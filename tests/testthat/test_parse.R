context("Test address component accessors")

test_that("The parser works with single values", {
  address <- "92 avenue des champs-elysees"
  result <- poster::parse_addr(address)
  testthat::expect_true(is.na(result$house[1]))
  testthat::expect_equal(as.numeric(result$house_number[1]), 92)
  testthat::expect_equal(result$road[1], "avenue des champs-elysees")
  testthat::expect_true(is.na(result$suburb[1]))
  testthat::expect_true(is.na(result$city_district[1]))
  testthat::expect_true(is.na(result$city[1]))
  testthat::expect_true(is.na(result$state_district[1]))
  testthat::expect_true(is.na(result$state[1]))
  testthat::expect_true(is.na(result$postal_code[1]))
  testthat::expect_true(is.na(result$country[1]))
})
