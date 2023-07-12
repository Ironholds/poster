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

#### Nonstandard location for libpostal

Most of the libpostal documentation assumes that it is installed in a standard system spot and that
it is possible to use `ldconfig` to make it globally accessible. This isn't always possible or desirable.

Here is one way of dealing with a local installation by a user, without setting `LD_LIBRARY_PATH`

1. Install libpostal after configuring a nonstandard location:

    `./configure --prefix=${HOME}/local`

1. Set the PKG_CONFIG_PATH variable to ensure that `pkg-config` will find libpostal:

    `export PKG_CONFIG_PATH=${PKG_CONFIG_PATH}:${HOME}/local`
    
1. Test

    `pkg-config libpostal --cflags`
    
1. Start an R session (e.g. rstudio), and set an environment variable to indicate that the RPATH setting should be used:

    `Sys.setenv(SETRPATH="TRUE")`

1. Run the install from the poster folder:

    `devtools::install()`
    
These steps can be carried out in various ways. The key point is that pkg-config will
find libpostal when run from the R package installer and that SETRPATH exists so 
that the package installer will set it.


###Dependencies
* R. Doy.
* [Rcpp](https://cran.r-project.org/package=Rcpp)
* [libpostal](https://github.com/openvenues/libpostal)
