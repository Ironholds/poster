context("Test address component accessors")

test_that("Accessors work with single values", {
  address <- "92 avenue des champs-elysees"
  testthat::expect_true(is.na(house(address)))
  testthat::expect_equal(as.numeric(house_number(address)), 92)
  testthat::expect_equal(road(address), "avenue des champs-elysees")
  testthat::expect_true(is.na(suburb(address)))
  testthat::expect_true(is.na(city_district(address)))
  testthat::expect_true(is.na(city(address)))
  testthat::expect_true(is.na(state_district(address)))
  testthat::expect_true(is.na(state(address)))
  testthat::expect_true(is.na(postal_code(address)))
  testthat::expect_true(is.na(country(address)))
})

test_that("Accessors work with multiple values", {
  address <- c("92 avenue des champs-elysees", "92 avenue des champs-elysees")
  testthat::expect_true(is.na(house(address)[2]))
  testthat::expect_equal(as.numeric(house_number(address)[2]), 92)
  testthat::expect_equal(road(address)[2], "avenue des champs-elysees")
  testthat::expect_true(is.na(suburb(address)[2]))
  testthat::expect_true(is.na(city_district(address)[2]))
  testthat::expect_true(is.na(city(address)[2]))
  testthat::expect_true(is.na(state_district(address)[2]))
  testthat::expect_true(is.na(state(address)[2]))
  testthat::expect_true(is.na(postal_code(address)[2]))
  testthat::expect_true(is.na(country(address)[2]))
})

test_that("NAs are handled", {
  address <- NA_character_
  testthat::expect_true(is.na(house(address)))
  testthat::expect_true(is.na(house_number(address)))
  testthat::expect_true(is.na(road(address)))
  testthat::expect_true(is.na(suburb(address)))
  testthat::expect_true(is.na(city_district(address)))
  testthat::expect_true(is.na(city(address)))
  testthat::expect_true(is.na(state_district(address)))
  testthat::expect_true(is.na(state(address)))
  testthat::expect_true(is.na(postal_code(address)))
  testthat::expect_true(is.na(country(address)))
})
