# Description -----
# Creates a dataframe containing data to pass to FIMS. We want
# to be able to pass these in so they can contribute correctly to the
# likelihood. Note we still want to convert this so it has testthat
# expectations.

# Input data for trend ------
# creating a data frame for both trend and catch so that we could pass in two
# data types

input_data_trend <- data.frame(
  # Trend is a type of data, where it can include CPUE, surveys, or
  # environmental covariate
  type = "trend",
  # Name would be the "pretty" name printed on figures and in tables, where name
  # refers to the fleet or survey
  name = "Index_1",
  ages = c(1:5),
  years = c(rep(2001, length.out = 5), rep(2002, length.out =  5),
            rep(2003, length.out = 5), rep(2004, length.out =  5),
            rep(2005, length.out = 5)),
  value = c(623.3, 515.2, 611.0, 729.0, 843.25,
          623.3, 515.2, NA, 729.0, 843.25,
          623.3, 515.2, 611.0, 729.0, 843.25,
          623.3, 515.2, 611.0, NA, 843.25,
          623.3, 515.2, 611.0, 729.0, 843.25),
  units = "numbers",
  SE = 0.01
)

input_data_catch <- data.frame(
  # Trend is a type of data, where it can include CPUE, surveys, or
  # environmental covariate
  type = "catch",
  # Name would be the "pretty" name printed on figures and in tables, where name
  # refers to the fleet or survey
  name = "Index_1",
  ages = c(1:5),
  years = c(rep(2001, length.out = 5), rep(2002, length.out =  5),
            rep(2003, length.out = 5), rep(2004, length.out =  5),
            rep(2005, length.out = 5)),
  value = c(623.3, 515.2, 611.0, 729.0, 843.25,
          623.3, 515.2, 611.0, 729.0, 843.25,
          623.3, 515.2, 611.0, 729.0, 843.25,
          623.3, 515.2, 611.0, 729.0, 843.25,
          623.3, 515.2, 611.0, 729.0, 843.25),
  units = "numbers",
  SE = 0.01
)

# combine the dataframes because we just want one input dataframe
input_data <- rbind(input_data_trend, input_data_catch)

# Code snippets we may or may not need ------
# May want to make things into factors, but not sure yet
# input_data$type = factor(input_data$type,
# levels = c("catch", "trend"," age_comp", "length_comp"))

# in case we want to write a function to make the data frame, we could make a
# fxn like this (but would move it to the R sub directory)
# make.model.data <- function(data)
# {
#     data$
# }

# fims$addData(input.data)

#fims <- Rcpp::Module(module = "fims", PACKAGE = "FIMS")

# how to  run the TMB model in src/test_dim_folding.cpp
library(TMB)
TMB::compile("src/test_dim_folding.cpp")
dyn.load(dynlib("src/test_dim_folding"))

# Check that it is loaded using
names(base::getLoadedDLLs())

dim_folding_mod <- TMB::MakeADFun(
  data = list(
    obs = input_data$value,
    years = unique(input_data$years),
    n_ages = length(unique(input_data$ages))
  ),
  parameters = list(
    mu_age_comp = rep(0, max(input_data$ages) - 1)
  ),
  DLL = "test_dim_folding"
)

summary(dim_folding_mod)
