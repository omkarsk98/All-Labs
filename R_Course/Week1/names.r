# for readable codes
x <- 1:3

print(names(x))
# outputs to NULL

names(x) <- c("foo","bar", "norf")
# run script for output

cat("x:",x,"\n")
cat("names of x",names(x),"\n")

y <- list(a=1, b=2, c=3)
print(y)

m <- matrix(1:4, nrow=2, ncol=2)
dimnames(m) <- list(c("a","b"),c("c","d"))
print(m)
#print(m[c][a])
