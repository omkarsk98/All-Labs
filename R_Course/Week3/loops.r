# lapply: loop over a list and run a function on each element.
# sapply: same as lapply, but simplify the result
# apply: apply a function over margins of a result
# tapply: apply a function over subsets of vector
# mapply: multivariate version of lapply


x <- list(a = 1:5, b = rnorm(10))
x
lapply(x, mean)
# returns list with the same names

x <- list(a=1:4, b=rnorm(10), c = rnorm(20,1), d = rnorm(100,5))
lapply(x, mean)

x <- 1:4
lapply(x, runif, min = 0, max = 10)
# runif: generates random value

print("on a list of matrices")
x <- list(a=matrix(1:4, 2, 2), b = matrix(1:6, 3, 2))
x
# to get first column of the martix
lapply(x, function(elt) elt[,1])