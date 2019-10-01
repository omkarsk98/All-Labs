add2 <- function(x,y){
  x+y
}

add2(3,5)

above10 <- function(x){
  use <- x>10
  x[use]
}

above <- function(x,n=10){ # default value for n as 10
  use <- x>n
  x[use]
}

columnMean <- function(y){
  nc <- ncol(y) # number of cols
  means <- numeric(nc)
  for( i in 1:nc){
    means[i] <- mean(y[,i])
  }
  means
}

