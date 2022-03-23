# #Maybe don't need this here if move to test that, in
 remotes::install_github("NOAA-FIMS/FIMS@feat-dimension-folding")
library(TMB)
 library(Rcpp)
 library(FIMS)

fims <- Rcpp::Module(module = "fims", PACKAGE = "FIMS")

input.data <- data.frame(
  # Trend is a type of data, where it can include CPUE, surveys, or environmental covariate
  type = "trend",
  # Name would be the "pretty" name printed on figures and in tables, where name refers to
  # the fleet or survey
  name = "Index 1",
  ages = c(1:25),
  years = c(2001, 2002, 2003, 2004, 2005),
  value = c(623.3, 515.2, 611.0, 729.0, 843.25,
          623.3, 515.2, NA, 729.0, 843.25,
          623.3, 515.2, 611.0, 729.0, 843.25,
          623.3, 515.2, 611.0, NA, 843.25,
          623.3, 515.2, 611.0, 729.0, 843.25),
  units = "numbers",
  SE = 0.01
)

input.data$name = factor(input.data$name, levels = c("trend","catch","age_comp","length_comp"))

# fims$hello_fims()
# print("hello")
fims$addData(input.data)


