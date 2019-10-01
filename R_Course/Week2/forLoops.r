x <- c("a","b","c","d")

for( i in 1:4){
  # do something
  print(x[i])
}

for(i in seq_along(x)){ # takes vector
  print(x[i])
}

for (letter in x){
  print(letter)
}

x <- matrix(1:6,2,3)

for(i in seq_along(nows(x))){
  for(j in seq_along(ncols(x))){
    print(x[i, j])
  }
}