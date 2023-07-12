// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

// setup
void setup();
RcppExport SEXP _poster_setup() {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    setup();
    return R_NilValue;
END_RCPP
}
// end
void end();
RcppExport SEXP _poster_end() {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    end();
    return R_NilValue;
END_RCPP
}
// normalise_addr
CharacterVector normalise_addr(CharacterVector addresses);
RcppExport SEXP _poster_normalise_addr(SEXP addressesSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< CharacterVector >::type addresses(addressesSEXP);
    rcpp_result_gen = Rcpp::wrap(normalise_addr(addresses));
    return rcpp_result_gen;
END_RCPP
}
// expand_addr
List expand_addr(CharacterVector addresses);
RcppExport SEXP _poster_expand_addr(SEXP addressesSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< CharacterVector >::type addresses(addressesSEXP);
    rcpp_result_gen = Rcpp::wrap(expand_addr(addresses));
    return rcpp_result_gen;
END_RCPP
}
// parse_addr
DataFrame parse_addr(CharacterVector addresses);
RcppExport SEXP _poster_parse_addr(SEXP addressesSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< CharacterVector >::type addresses(addressesSEXP);
    rcpp_result_gen = Rcpp::wrap(parse_addr(addresses));
    return rcpp_result_gen;
END_RCPP
}
// get_elements_
CharacterVector get_elements_(CharacterVector addresses, int element);
RcppExport SEXP _poster_get_elements_(SEXP addressesSEXP, SEXP elementSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< CharacterVector >::type addresses(addressesSEXP);
    Rcpp::traits::input_parameter< int >::type element(elementSEXP);
    rcpp_result_gen = Rcpp::wrap(get_elements_(addresses, element));
    return rcpp_result_gen;
END_RCPP
}
// set_elements_
CharacterVector set_elements_(CharacterVector addresses, CharacterVector replacement, int element);
RcppExport SEXP _poster_set_elements_(SEXP addressesSEXP, SEXP replacementSEXP, SEXP elementSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< CharacterVector >::type addresses(addressesSEXP);
    Rcpp::traits::input_parameter< CharacterVector >::type replacement(replacementSEXP);
    Rcpp::traits::input_parameter< int >::type element(elementSEXP);
    rcpp_result_gen = Rcpp::wrap(set_elements_(addresses, replacement, element));
    return rcpp_result_gen;
END_RCPP
}
