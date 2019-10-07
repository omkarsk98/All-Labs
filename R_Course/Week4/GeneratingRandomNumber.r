# rnorm: generate random normal variates with a given mean and standard deviation
# dnorm: evaluate the normal probability density (with the given mean/SD) ata point
# pnorm: evaluate the cumulative distribution function for a normal distribution
# rpois: generate random poisson variates with a given rate

# 4 functions associated with probability distribution function
# d: density
# r: random number generation
# p: cumulative distribution
# q: quantile function

set.seed(1)
# reproduce same random numbers after setting set.seed(1)

x <- rnorm(10,20,2)
# 10: number of random numbers
# 20: mean
# 2: std deviation
