.onLoad <- function(libname, pkgname){
  setup()
  return(invisible())
}

.onUnload <- function(libpath){
  end()
  return(invisible())
}
