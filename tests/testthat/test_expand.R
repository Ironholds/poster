context("Test address expansion")

exp1 <- c("92 avenue des champs-elysees", "92 avenue des champs elysees", "92 avenue des champselysees")
test_that("simple addresses can be normalised", {
  result <- expand_addr("Quatre-vingt-douze Ave des Champs-Élysées")
  testthat::expect_equal(result[[1]], exp1)
})

test_that("Multiple addresses can be normalised", {
  result <- expand_addr(rep("Quatre-vingt-douze Ave des Champs-Élysées", 2))
  testthat::expect_equal(length(result), 2)
  testthat::expect_equal(result[[1]], exp1)
  testthat::expect_equal(result[[2]], exp1)
})

test_that("NAs are handled", {
  result <- expand_addr(c("Quatre-vingt-douze Ave des Champs-Élysées", NA))
  testthat::expect_equal(length(result), 2)
  testthat::expect_equal(result[[1]], exp1)
  testthat::expect_true(is.na(result[[2]]))
})
