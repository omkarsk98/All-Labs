# c function is used to create vectors of objects
num <- c(0.5, 0.6) # numeric
log <- c(TRUE, FALSE)		# logical or simply T or F
chars <- c("a", "b", "c")			# chars
int <- 9:29 # creates a list from 9 to 29
com <- c(1+0i, 2+4i)
#print(int)

# using vector function of type and length
vec <- vector("numeric", length=10)
#print(vec)

# mixing objects
mix <- c(1.7, T, "a")
#print(mix)

x <- 1:15
dim(x) <- c(3,5)
print(x)
