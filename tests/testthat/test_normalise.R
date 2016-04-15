context("Test address normalisation")

test_that("simple addresses can be normalised", {
  result <- normalise_addr("Quatre-vingt-douze Ave des Champs-Élysées")
  testthat::expect_equal(result, "92 avenue des champs-elysees")
})

test_that("Multiple addresses can be normalised", {
  result <- normalise_addr(rep("Quatre-vingt-douze Ave des Champs-Élysées", 2))
  testthat::expect_equal(length(result), 2)
  testthat::expect_equal(result, rep("92 avenue des champs-elysees", 2))
})

test_that("NAs are handled", {
  result <- normalise_addr(c("Quatre-vingt-douze Ave des Champs-Élysées", NA))
  testthat::expect_equal(length(result), 2)
  testthat::expect_equal(result[1], "92 avenue des champs-elysees")
  testthat::expect_true(is.na(result[2]))
})
