#include "postal.h"

// Consistently set up and end usage.
//[[Rcpp::export]]
void setup() {
  if (!libpostal_setup() || !libpostal_setup_language_classifier() || !libpostal_setup_parser()) {
    throw std::runtime_error("Libbpostal setup failed");
  }
}
//[[Rcpp::export]]
void end() {
  libpostal_teardown();
  libpostal_teardown_language_classifier();
  libpostal_teardown_parser();
}

//'@title Normalise postal addresses
//'@description \code{normalise_addr} takes street
//'addresses and normalises them within the context of a specific
//'country or language. It currently recognises 60 different locales.
//'
//'@param addresses a character vector of addresses to normalise
//'
//'@return a character vector of normalised addresses.
//'
//'@examples
//'# Normalise an English address!
//'\dontrun{
//'normalise_addr("fourty seven love lane pinner")
//'# [1] "47 love lane pinner"
//'}
//'# Normalise a French one
//'\dontrun{
//'normalise_addr("Quatre-vignt-douze Ave des Champs-Élysées")
//'# "92 avenue des champs-elysees"
//'}
//'@seealso \code{\link{parse_addr}} for parsing addresses.
//'@export
// [[Rcpp::export]]
CharacterVector normalise_addr(CharacterVector addresses){
  poster_internal pinst;
  return pinst.address_normalise(addresses);
}

//'@title Expand postal addresses
//'@description \code{expand_addr} takes street
//'addresses and expands them to one or more normalised strings
//'within the context of a specific
//'country or language. It currently recognises 60 different locales.
//'
//'@param addresses a character vector of addresses to normalise
//'
//'@return a list of character vectors of expanded addresses.
//'
//'@examples
//'# expand an English address!
//'\dontrun{
//'expand_addr("fourty seven love lane pinner")
//'# [1] "47 love lane pinner"
//'}
//'# Normalise a French one
//'\dontrun{
//'expand_addr("Quatre-vignt-douze Ave des Champs-Élysées")
//'# "92 avenue des champs-elysees"
//'}
//'@seealso \code{\link{parse_addr}} for parsing addresses.
//'@export
// [[Rcpp::export]]
List expand_addr(CharacterVector addresses){
  poster_internal pinst;
  return pinst.expand_addr(addresses);
}


//'@title Parse street addresses
//'@description \code{parse_addr} parses street addresses into
//'their component parts, producing the addresses' house name,
//'number, road and suburb, city district and city, state district
//'and state, postal code, and country.
//'
//'@param addresses a character vector of addresses to parse.
//'
//'@return a data.frame of 20 columns; \code{house}, \code{category},
//'\code{near}, \code{house_number}, \code{road}, \code{unit},
//'\code{level}, \code{staircase}, \code{entrance}, \code{po_box},
//'\code{suburb}, \code{city_district}, \code{city},
//'\code{state_district}, \code{state}, \code{postal_code},
//'\code{country_region}, \code{country}, \code{world_region}. 
//'Values not found in the address are represented
//'with \code{NA}s
//'
//'@examples
//'\dontrun{
//'str(parse_addr("781 Franklin Ave Crown Heights Brooklyn NYC NY 11216 USA"))
//'}
//'# 'data.frame':	1 obs. of  10 variables:
//'#   $ house          : chr NA
//'#   $ category       : chr NA
//'#   $ near           : chr NA
//'#   $ house_number   : chr "781"
//'#   $ road           : chr "franklin ave"
//'#   $ unit           : chr NA
//'#   $ level          : chr NA
//'#   $ staircase      : chr NA
//'#   $ entrance       : chr NA
//'#   $ po_box         : chr NA
//'#   $ suburb         : chr "crown heights"
//'#   $ city_district  : chr "brooklyn"
//'#   $ city           : chr "nyc"
//'#   $ state_district : chr NA
//'#   $ state          : chr "ny"
//'#   $ postal_code    : chr NA
//'#   $ country_region : chr NA
//'#   $ country        : chr "usa"
//'#   $ world_region   : chr NA
//'
//'@seealso \code{\link{normalise_addr}} for normalising addresses.
//'
//'@export
//[[Rcpp::export]]
DataFrame parse_addr(CharacterVector addresses){
  poster_internal pinst;
  return pinst.parse_addr(addresses);
}

//[[Rcpp::export]]
CharacterVector get_elements_(CharacterVector addresses, int element){
  poster_internal pinst;
  return pinst.get_elements(addresses, element);
}

//[[Rcpp::export]]
CharacterVector set_elements_(CharacterVector addresses, CharacterVector replacement, int element){
  poster_internal pinst;
  return pinst.set_elements(addresses, replacement, element);
}
