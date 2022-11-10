## Postal address parsing in R

__Author:__ Oliver Keyes, Al Barrentine <br/>
__License:__ [MIT](http://opensource.org/licenses/MIT)<br/>
__Status:__ Stable

### Description

[libpostal](https://github.com/openvenues/libpostal) is a postal address parser written in C - and `poster` is a wrapper around it, allowing you to parse and normalise addresses from R.

It contains, amongst other things:

* An address normaliser;
* An address parser;
* Extractors for individual elements of addresses, from house numbers to countries.

Please note that this project is released with a [Contributor Code of Conduct](https://github.com/Ironholds/poster/blob/master/CONDUCT.md).
By participating in this project you agree to abide by its terms.

### Installation

Poster isn't on CRAN (they don't like dependencies they don't have) but it is stable. To get it:

    devtools::install_github("ironholds/poster")

or

    devtools::install_github("ironholds/poster", build_vignettes=TRUE)

to create the vignette

Note, of course, the dependencies, and make sure you have [libpostal](https://github.com/openvenues/libpostal)
installed first.

###Dependencies
* R. Doy.
* [Rcpp](https://cran.r-project.org/package=Rcpp)
* [libpostal](https://github.com/openvenues/libpostal)
