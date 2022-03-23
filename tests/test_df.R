# #Maybe don't need this here if move to test that, in
 remotes::install_github("NOAA-FIMS/FIMS@feat-dimension-folding")
library(TMB)
 library(Rcpp)
 library(FIMS)

fims <- Rcpp::Module(module = "fims", PACKAGE = "FIMS")

input.data <- data.frame(
  name = "trend", # or something else? I vote for "trend" b/c then you can use environmental data
  nages = c(25),
  ages = c(1:25), 
  nyears = c(5),
  years = c(2001, 2002, 2003, 2004, 2005),
  value = c(623.3, 515.2, 611.0, 729.0, 843.25,
          623.3, 515.2, NA, 729.0, 843.25,
          623.3, 515.2, 611.0, 729.0, 843.25,
          623.3, 515.2, 611.0, NA, 843.25,
          623.3, 515.2, 611.0, 729.0, 843.25), 
  units = "numbers",
  SE = NA,
  Neff = NA
)
fims$hello_fims()
print("hello")
#fims$addData(input.data)


