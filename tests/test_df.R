
#fims <- Rcpp::Module(module = "fims", PACKAGE = "FIMS")

input.data <- data.frame(
  # Trend is a type of data, where it can include CPUE, surveys, or environmental covariate
  type = "trend",
  # Name would be the "pretty" name printed on figures and in tables, where name refers to
  # the fleet or survey
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

input.data$type = factor(input.data$type, levels = c("catch","trend","age_comp","length_comp"))

make.model.data <- function(data)
{
    
}

# fims$hello_fims()
 print(input.data)
fims$addData(input.data)


