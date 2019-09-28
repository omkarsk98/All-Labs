# file: opens  a connection to a file
# gzfile: opens a connection to a file compressed with gzip
# bzfile: opens a connection to a file compressed with bzip2
# url: opens a connection to a webpage


# str(file)

# description is for name fo the file
# open is access having r:read, w:write, a:append, rb, wb, ab is for binary files

con <- file("foo.txt","r")
data <- read.csv(con)
# names(data) <- c("open","high", "low", "close")
data
close(con)

# this is same as data <- read.csv("foo.txt")