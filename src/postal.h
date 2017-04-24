#include <Rcpp.h>
#include <libpostal/libpostal.h>
using namespace Rcpp;


#ifndef __POSTER_INTERNAL__
#define __POSTER_INTERNAL__

class poster_internal {
  
private:
  
  String isna(std::string x);

  CharacterVector parse_single(String x, libpostal_address_parser_options_t& opts);
  
public:
  
  CharacterVector address_normalise(CharacterVector addresses);
  
  List parse_addr(CharacterVector addresses);
  
  CharacterVector get_elements(CharacterVector addresses, int element);
  
  CharacterVector set_elements(CharacterVector addresses, CharacterVector new_value, int element);
  
};

#endif
