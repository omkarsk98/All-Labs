# apply a function on margins of an array
# x: array
# margin: which margins to retain
# func: function to be applied
x <- matrix(rnorm(200), 20, 10)
apply(x, 2, mean)
# retain 2nd dimension. ie. get mean over each column

apply(x, 1, mean)
# retain 1st dimension. ie. get mean over each row
# we have 20 rows, so we should get 20 rows

# some applications
rowSums = apply(x, 1, sum)
rowMeans = apply(x, 1, mean)
colSums = apply(x, 2, sum)
colMeans = apply(x, 2, mean)