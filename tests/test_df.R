remotes::install_github("NOAA-FIMS/FIMS@feat-dimension-folding")
library(TMB)
library(Rcpp)
library(FIMS)

fims<-Rcpp::Module(module = "fims",PACKAGE = "FIMS")

abundace.data <- data.frame(
  ages = c (1:5), 
  years = c(2001,2002,2003,2004,2005),
  salary = c(623.3,515.2,611.0,729.0,843.25), 
  units = "mt"
)

fims$addData(abundace.data)


