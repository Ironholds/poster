#' @title Tools for handling URLs
#' @name poster
#' @description Normalise street addresses, or parse them, extracting house
#'   number, street name, post code and various other elements of a street
#'   address. Requires (and is built around) the libpostal library
#'   ('https://github.com/openvenues/libpostal').
#' 
#' @seealso the package \code{vignette("Address Parsing with Poster", package = "poster")}.
#' @useDynLib poster, .registration = TRUE
#' @importFrom Rcpp sourceCpp
#' @docType package
#' @aliases poster poster-package
NULL
