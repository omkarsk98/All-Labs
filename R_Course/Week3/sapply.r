# lapply returns a list.. sapply will return a vector
x <- list(a = 1:5, b = rnorm(10))
sapply(x, mean)

# sapply
#          a          b 
# 3.00000000 0.05934921 

# lapply
# $a
# [1] 3

# $b
# [1] 0.05290194

