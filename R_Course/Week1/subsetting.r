# [] for getting same class
# [[]] getting an element
# $ extract element by name

x <- c("a","b","c","d","d","a")
x[1]
x[1:2]

x[x>"a"] # returns everything greater than "a"

y <- x>"a"
y # get a logical vector

x[y] # used as logical index, returns indices with true

# subsetting lists
x <- list(foo=1:4, bar=0.6, baz="woo")
x[1] # returns 1st list, prints the name too
x[[1]] # does not print the name

# indexing with name
x$bar
x["bar"]
x[["bar"]]

# for multiple vectors from the list
print("Printing multiple values from the list")
x[c(1,3)] # returns 1st and 3rd vectors in it

# subsetting nested lists
x <- list(a=list(10,12,14),b=c(3.14, 2.81))
x[[c(1,3)]] # from 1st index, 3rd value
x[[c(2,1)]] # from 2nd index, 1st value


# subsetting a matrix
x <- matrix(1:6,2,3)
x[1,2] # 1st row, 2md value
x[1,] # everything from 1st row

x[1,, drop=FALSE]

# subsetting with names
x <- list(abs=10:15)
x$abs
x[["a"]] # not exactly found
x[["a", exact=FALSE]] # does not look for exact match


# removing missing values
x <- c(1,2,NA,4, NA, 5)
bad <- is.na(x) # gets vector of true and false
x[!bad] # prints only true or false values
