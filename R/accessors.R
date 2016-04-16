#'@title Get an address's elements
#'@description as in the lubridate package, individual components of an address
#'can be extracted using the relevant function call - see the
#'examples.
#'@aliases house
#'@rdname accessors
#'
#'@param x an address, or vector of addresses
#'
#'@examples
#'#Get a component
#'\dontrun{
#'example_address <- "The Deaconage, 781 Franklin Ave Crown Heights Brooklyn NYC NY 11216 USA"
#'house(example_address)
#'}
#'@export
house <- function(x){
  return(get_elements_(x, 0))
}

#'@rdname accessors
#'@export
house_number <- function(x){
  return(get_elements_(x, 1))
}

#'@rdname accessors
#'@export
road <- function(x){
  return(get_elements_(x, 2))
}

#'@rdname accessors
#'@export
suburb <- function(x){
  return(get_elements_(x, 3))
}
#'@rdname accessors
#'@export
city_district <- function(x){
  return(get_elements_(x, 4))
}

#'@rdname accessors
#'@export
city <- function(x){
  return(get_elements_(x, 5))
}

#'@rdname accessors
#'@export
state_district <- function(x){
  return(get_elements_(x, 6))
}

#'@rdname accessors
#'@export
state <- function(x){
  return(get_elements_(x, 7))
}

#'@rdname accessors
#'@export
postal_code <- function(x){
  return(get_elements_(x, 8))
}


#'@rdname accessors
#'@export
country <- function(x){
  return(get_elements_(x, 9))
}
