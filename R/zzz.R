.onLoad <- function(libname, pkgname){
  poster:::setup()
  return(invisible())
}

.onUnload <- function(libpath){
  poster:::end()
  return(invisible())
}
