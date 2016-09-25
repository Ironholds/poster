#include "postal.h"

String poster_internal::isna(std::string x){
  if(x == ""){
    return NA_STRING;
  }
  return x;
}

CharacterVector poster_internal::parse_single(String x, address_parser_options_t& opts){
  
  CharacterVector output(10, NA_STRING);
  address_parser_response_t *parsed = parse_address((char*) x.get_cstring(), opts);
  std::string holding;
  for (unsigned int n = 0; n < parsed->num_components; n++) {
    holding = parsed->labels[n];
    // Optimise this by using an enum
    if(holding == "house"){
      output[0] = isna(parsed->components[n]);
    }
    
    if(holding == "house_number"){
      output[1] = isna(parsed->components[n]);
    }
    
    if(holding == "road"){
      output[2] = isna(parsed->components[n]);
    }
    
    if(holding == "suburb"){
      output[3] = isna(parsed->components[n]);
    }
    
    if(holding == "city_district"){
      output[4] = isna(parsed->components[n]);
    }
    
    if(holding == "city"){
      output[5] = isna(parsed->components[n]);
    }
    
    if(holding == "state_district"){
      output[6] = isna(parsed->components[n]);
    }
    
    if(holding == "state"){
      output[7] = isna(parsed->components[n]);
    }
    
    if(holding == "postcode"){
      output[8] = isna(parsed->components[n]);
    }
    
    if(holding == "country"){
      output[9] = isna(parsed->components[n]);
    }
  }

  address_parser_response_destroy(parsed);
  return output;
}

CharacterVector poster_internal::address_normalise(CharacterVector addresses){
  
  unsigned int input_size = addresses.size();
  CharacterVector output(input_size);
  normalize_options_t options = get_libpostal_default_options();
  size_t num_expansions;
  char **expansions;
  
  for(unsigned int i = 0; i < input_size; i++){
    
    if((i % 10000) == 0){
      Rcpp::checkUserInterrupt();
    }
    
    if(addresses[i] == NA_STRING){
      
      output[i] = NA_STRING;
      
    } else {
      
      expansions = expand_address(addresses[i], options, &num_expansions);
      if(num_expansions == 0){
        output[i] = addresses[i];
      } else {
        output[i] = std::string(expansions[0]);
      }
      
      expansion_array_destroy(expansions, num_expansions);
      
    }
  }
  
  return output;
}

DataFrame poster_internal::parse_addr(CharacterVector addresses){
  
  unsigned int input_size = addresses.size();
  CharacterVector house(input_size, NA_STRING);
  CharacterVector house_number(input_size, NA_STRING);
  CharacterVector road(input_size, NA_STRING);
  CharacterVector suburb(input_size, NA_STRING);
  CharacterVector city_district(input_size, NA_STRING);
  CharacterVector city(input_size, NA_STRING);
  CharacterVector state_district(input_size, NA_STRING);
  CharacterVector state(input_size, NA_STRING);
  CharacterVector postal_code(input_size, NA_STRING);
  CharacterVector country(input_size, NA_STRING);
  CharacterVector holding;
  address_parser_options_t options = get_libpostal_address_parser_default_options();

  for(unsigned int i = 0; i < input_size; i++){
    if((i % 10000) == 0){
      Rcpp::checkUserInterrupt();
    }
    if(addresses[i] != NA_STRING){
      address_parser_response_t *parsed = parse_address((char*) addresses[i],
                                                        options);
      std::string holding;
      for (unsigned int n = 0; n < parsed->num_components; n++) {
        holding = parsed->labels[n];
        // Optimise this by using an enum
        if(holding == "house"){
          house[i] = isna(parsed->components[n]);
        }
        
        if(holding == "house_number"){
          house_number[i] = isna(parsed->components[n]);
        }
        
        if(holding == "road"){
          road[i] = isna(parsed->components[n]);
        }
        
        if(holding == "suburb"){
          suburb[i] = isna(parsed->components[n]);
        }
        
        if(holding == "city_district"){
          city_district[i] = isna(parsed->components[n]);
        }
        
        if(holding == "city"){
          city[i] = isna(parsed->components[n]);
        }
        
        if(holding == "state_district"){
          state_district[i] = isna(parsed->components[n]);
        }
        
        if(holding == "state"){
          state[i] = isna(parsed->components[n]);
        }
        
        if(holding == "postcode"){
          postal_code[i] = isna(parsed->components[n]);
        }
        
        if(holding == "country"){
          country[i] = isna(parsed->components[n]);
        }
      }
      address_parser_response_destroy(parsed);
    }
  }
  
  return DataFrame::create(_["house"] = house,
                           _["house_number"] = house_number,
                           _["road"] = road,
                           _["suburb"] = suburb,
                           _["city_district"] = city_district,
                           _["city"] = city,
                           _["state_district"] = state_district,
                           _["state"] = state,
                           _["postal_code"] = postal_code,
                           _["country"] = country,
                           _["stringsAsFactors"] = false);
}

CharacterVector poster_internal::get_elements(CharacterVector addresses, int element){
  
  unsigned int input_size = addresses.size();
  CharacterVector output(input_size);
  
  address_parser_options_t options = get_libpostal_address_parser_default_options();
  address_parser_options_t& opt_ref = options;
  
  for(unsigned int i = 0; i < input_size; i++){
    if((i % 10000) == 0){
      Rcpp::checkUserInterrupt();
    }
    
    if(addresses[i] == NA_STRING){
      output[i] = NA_STRING;
    } else {
      output[i] = parse_single(addresses[i], opt_ref)[element];
    }
  
  }
  
  return output;
    
}

CharacterVector poster_internal::set_elements(CharacterVector addresses, CharacterVector new_value, int element){
  
  unsigned int input_size = addresses.size();
  CharacterVector output(input_size);
  CharacterVector holding;
  address_parser_options_t options = get_libpostal_address_parser_default_options();
  address_parser_options_t& opt_ref = options;
  
  if(new_value.size() == 1){
    if(new_value[0] == NA_STRING){
      return addresses;
    }
    for(unsigned int i = 0; i < input_size; i++){
      if((i % 10000) == 0){
        Rcpp::checkUserInterrupt();
      }
      
      if(addresses[i] == NA_STRING){
        output[i] = NA_STRING;
      } else {
        holding = parse_single(addresses[i], opt_ref);
        std::string addr_cp = Rcpp::as<std::string>(addresses[i]);
        if(holding[element] == NA_STRING){
          output[i] = addresses[i];
        } else {
          addr_cp.replace(addr_cp.find(Rcpp::as<std::string>(holding[element])),
                          Rcpp::as<std::string>(holding[element]).size(), new_value[0]);
          output[i] = addr_cp;
        }
      }
    }
  } else if(new_value.size() == input_size){
    for(unsigned int i = 0; i < input_size; i++){
      if((i % 10000) == 0){
        Rcpp::checkUserInterrupt();
      }
      
      if(addresses[i] == NA_STRING){
        output[i] = NA_STRING;
      } else if(new_value[i] == NA_STRING){
        output[i] = addresses[i];
      } else {
        holding = parse_single(addresses[i], opt_ref);
        std::string addr_cp = Rcpp::as<std::string>(addresses[i]);
        if(holding[element] == NA_STRING){
          output[i] = addresses[i];
        } else {
          addr_cp.replace(addr_cp.find(Rcpp::as<std::string>(holding[element])),
                          Rcpp::as<std::string>(holding[element]).size(), new_value[i]);
          output[i] = addr_cp;
        }
      }
    }
  } else {
    Rcpp::stop("The set of new values must be the same length as the addresses, or of length 1");
  }
  
  return output;
}
