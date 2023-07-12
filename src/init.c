#include <R.h>
#include <Rinternals.h>
#include <stdlib.h> // for NULL
#include <R_ext/Rdynload.h>

/* FIXME: 
Check these declarations against the C/Fortran source code.
*/

/* .Call calls */
extern SEXP _poster_end();
extern SEXP _poster_get_elements_(SEXP, SEXP);
extern SEXP _poster_normalise_addr(SEXP);
extern SEXP _poster_expand_addr(SEXP);
extern SEXP _poster_parse_addr(SEXP);
extern SEXP _poster_set_elements_(SEXP, SEXP, SEXP);
extern SEXP _poster_setup();

static const R_CallMethodDef CallEntries[] = {
  {"_poster_end",            (DL_FUNC) &_poster_end,            0},
  {"_poster_get_elements_",  (DL_FUNC) &_poster_get_elements_,  2},
  {"_poster_normalise_addr", (DL_FUNC) &_poster_normalise_addr, 1},
  {"_poster_expand_addr",    (DL_FUNC) &_poster_expand_addr,    1},
  {"_poster_parse_addr",     (DL_FUNC) &_poster_parse_addr,     1},
  {"_poster_set_elements_",  (DL_FUNC) &_poster_set_elements_,  3},
  {"_poster_setup",          (DL_FUNC) &_poster_setup,          0},
  {NULL, NULL, 0}
};

void R_init_poster(DllInfo *dll)
{
  R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
}
