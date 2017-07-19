#include "postal.h"

String poster_internal::isna(std::string x){
  if(x == ""){
    return NA_STRING;
  }
  return x;
}

enum {
    PARSER_LABEL_HOUSE,
    PARSER_LABEL_CATEGORY,
    PARSER_LABEL_NEAR,
    PARSER_LABEL_HOUSE_NUMBER,
    PARSER_LABEL_ROAD,
    PARSER_LABEL_UNIT,
    PARSER_LABEL_LEVEL,
    PARSER_LABEL_STAIRCASE,
    PARSER_LABEL_ENTRANCE,
    PARSER_LABEL_PO_BOX,
    PARSER_LABEL_POSTCODE,
    PARSER_LABEL_SUBURB,
    PARSER_LABEL_CITY_DISTRICT,
    PARSER_LABEL_CITY,
    PARSER_LABEL_ISLAND,
    PARSER_LABEL_STATE_DISTRICT,
    PARSER_LABEL_STATE,
    PARSER_LABEL_COUNTRY_REGION,
    PARSER_LABEL_COUNTRY,
    PARSER_LABEL_WORLD_REGION
};

// What if we..
// For each address, parse it, throw the parsed results into a vector
// 

CharacterVector poster_internal::parse_single(String x, libpostal_address_parser_options_t& opts){
  CharacterVector output(20, NA_STRING);
  libpostal_address_parser_response_t *parsed = libpostal_parse_address((char*) x.get_cstring(), opts);
  std::string holding;
  for (unsigned int n = 0; n < parsed->num_components; n++) {
    holding = parsed->labels[n];

    // Optimise this by using an enum
    if (holding == "house") {
      output[PARSER_LABEL_HOUSE] = isna(parsed->components[n]);
    }
    if (holding == "category") {
      output[PARSER_LABEL_CATEGORY] = isna(parsed->components[n]);
    }
    if (holding == "near") {
      output[PARSER_LABEL_NEAR] = isna(parsed->components[n]);
    }
    if (holding == "house_number") {
      output[PARSER_LABEL_HOUSE_NUMBER] = isna(parsed->components[n]);
    }
    if (holding == "road") {
      output[PARSER_LABEL_ROAD] = isna(parsed->components[n]);
    }
    if (holding == "unit") {
      output[PARSER_LABEL_UNIT] = isna(parsed->components[n]);
    }
    if (holding == "level") {
      output[PARSER_LABEL_LEVEL] = isna(parsed->components[n]);
    }
    if (holding == "staircase") {
      output[PARSER_LABEL_STAIRCASE] = isna(parsed->components[n]);
    }
    if (holding == "entrance") {
      output[PARSER_LABEL_ENTRANCE] = isna(parsed->components[n]);
    }
    if (holding == "po_box") {
      output[PARSER_LABEL_PO_BOX] = isna(parsed->components[n]);
    }
    if (holding == "postcode") {
      output[PARSER_LABEL_POSTCODE] = isna(parsed->components[n]);
    }
    if (holding == "suburb") {
      output[PARSER_LABEL_SUBURB] = isna(parsed->components[n]);
    }
    if (holding == "city_district") {
      output[PARSER_LABEL_CITY_DISTRICT] = isna(parsed->components[n]);
    }
    if (holding == "city") {
      output[PARSER_LABEL_CITY] = isna(parsed->components[n]);
    }
    if (holding == "island") {
      output[PARSER_LABEL_ISLAND] = isna(parsed->components[n]);
    }
    if (holding == "state_district") {
      output[PARSER_LABEL_STATE_DISTRICT] = isna(parsed->components[n]);
    }
    if (holding == "state") {
      output[PARSER_LABEL_STATE] = isna(parsed->components[n]);
    }
    if (holding == "country_region") {
      output[PARSER_LABEL_COUNTRY_REGION] = isna(parsed->components[n]);
    }
    if (holding == "country") {
      output[PARSER_LABEL_COUNTRY] = isna(parsed->components[n]);
    }
    if (holding == "world_region") {
      output[PARSER_LABEL_WORLD_REGION] = isna(parsed->components[n]);
    }
  }

  libpostal_address_parser_response_destroy(parsed);
  return output;
}

CharacterVector poster_internal::address_normalise(CharacterVector addresses){
  
  unsigned int input_size = addresses.size();
  CharacterVector output(input_size);
  libpostal_normalize_options_t options = libpostal_get_default_options();
  size_t num_expansions;
  char **expansions;
  
  for(unsigned int i = 0; i < input_size; i++){
    
    if((i % 10000) == 0){
      Rcpp::checkUserInterrupt();
    }
    
    if(addresses[i] == NA_STRING){
      
      output[i] = NA_STRING;
      
    } else {
      
      expansions = libpostal_expand_address(addresses[i], options, &num_expansions);
      if(num_expansions == 0){
        output[i] = addresses[i];
      } else {
        output[i] = std::string(expansions[0]);
      }
      
      libpostal_expansion_array_destroy(expansions, num_expansions);
      
    }
  }
  
  return output;
}

List poster_internal::parse_addr(CharacterVector addresses){
  
  unsigned int input_size = addresses.size();
  CharacterVector house(input_size, NA_STRING);
  CharacterVector category(input_size, NA_STRING);
  CharacterVector near(input_size, NA_STRING);
  CharacterVector house_number(input_size, NA_STRING);
  CharacterVector road(input_size, NA_STRING);
  CharacterVector unit(input_size, NA_STRING);
  CharacterVector level(input_size, NA_STRING);
  CharacterVector staircase(input_size, NA_STRING);
  CharacterVector entrance(input_size, NA_STRING);
  CharacterVector po_box(input_size, NA_STRING);
  CharacterVector suburb(input_size, NA_STRING);
  CharacterVector city_district(input_size, NA_STRING);
  CharacterVector city(input_size, NA_STRING);
  CharacterVector island(input_size, NA_STRING);
  CharacterVector state_district(input_size, NA_STRING);
  CharacterVector state(input_size, NA_STRING);
  CharacterVector postal_code(input_size, NA_STRING);
  CharacterVector country(input_size, NA_STRING);
  CharacterVector country_region(input_size, NA_STRING);
  CharacterVector world_region(input_size, NA_STRING);
  CharacterVector holding;

  libpostal_address_parser_options_t options = libpostal_get_address_parser_default_options();

  for(unsigned int i = 0; i < input_size; i++){
    if((i % 10000) == 0){
      Rcpp::checkUserInterrupt();
    }
    if(addresses[i] != NA_STRING){
      libpostal_address_parser_response_t *parsed = libpostal_parse_address((char*) addresses[i], options);
      std::string holding;
      for (unsigned int n = 0; n < parsed->num_components; n++) {
        holding = parsed->labels[n];
        // Optimise this by using an enum
        if (holding == "house") {
          house[i] = isna(parsed->components[n]);
        }
        if (holding == "category") {
          category[i] = isna(parsed->components[n]);
        }
        if (holding == "near") {
          near[i] = isna(parsed->components[n]);
        }
        if (holding == "house_number") {
          house_number[i] = isna(parsed->components[n]);
        }
        if (holding == "road") {
          road[i] = isna(parsed->components[n]);
        }
        if (holding == "unit") {
          unit[i] = isna(parsed->components[n]);
        }
        if (holding == "level") {
          level[i] = isna(parsed->components[n]);
        }
        if (holding == "staircase") {
          staircase[i] = isna(parsed->components[n]);
        }
        if (holding == "entrance") {
          entrance[i] = isna(parsed->components[n]);
        }
        if (holding == "po_box") {
          po_box[i] = isna(parsed->components[n]);
        }
        if (holding == "suburb") {
          suburb[i] = isna(parsed->components[n]);
        }
        if (holding == "city_district") {
          city_district[i] = isna(parsed->components[n]);
        }
        if (holding == "city") {
          city[i] = isna(parsed->components[n]);
        }
        if (holding == "island") {
          island[i] = isna(parsed->components[n]);
        }
        if (holding == "state_district") {
          state_district[i] = isna(parsed->components[n]);
        }
        if (holding == "state") {
          state[i] = isna(parsed->components[n]);
        }
        if (holding == "postcode") {
          postal_code[i] = isna(parsed->components[n]);
        }
        if (holding == "country_region") {
          country_region[i] = isna(parsed->components[n]);
        }
        if (holding == "country") {
          country[i] = isna(parsed->components[n]);
        }
        if (holding == "world_region") {
          world_region[i] = isna(parsed->components[n]);
        }

      }
      libpostal_address_parser_response_destroy(parsed);
    }
  }
  
  List out;
  out["house"] = house;
  out["category"] = category;
  out["near"] = near;
  out["house_number"] = house_number;
  out["road"] = road;
  out["unit"] = unit;
  out["level"] = level;
  out["staircase"] = staircase;
  out["entrance"] = entrance;
  out["po_box"] = po_box;
  out["suburb"] = suburb;
  out["city_district"] = city_district;
  out["city"] = city;
  out["island"] = island;
  out["state_district"] = state_district;
  out["state"] = state;
  out["postal_code"] = postal_code;
  out["country_region"] = country_region;
  out["country"] = country;
  out["world_region"] = world_region;
  out.attr("class") = "data.frame";
  IntegerVector rownames = Rcpp::seq(1,addresses.size());
  out.attr("row.names") = rownames;
  return out;
}

CharacterVector poster_internal::get_elements(CharacterVector addresses, int element){
  
  unsigned int input_size = addresses.size();
  CharacterVector output(input_size);
  
  libpostal_address_parser_options_t options = libpostal_get_address_parser_default_options();
  libpostal_address_parser_options_t& opt_ref = options;
  
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
  libpostal_address_parser_options_t options = libpostal_get_address_parser_default_options();
  libpostal_address_parser_options_t& opt_ref = options;
  
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
