# read.table(), read.csv()
# readLines() to read txt files
# source for reading in r code
# load for reading in saved work space
# unserialize for reading single R objects in binary form


# for writing data
# write.table()
# writeLines()
# dump
# save()
# serialize()


# for readtable 
# file: name of the file
# header: logical for file containing header line
# sep: how the cols are seperated
# colClasses: vector for classes of columns
# nrows: no. of rows in dataset
# comment.char: string indicating the comment characters
# skip: no. of lines to skip from the beginning
# stringAsFactors: should char variable be added as factor

data <- read.table("foo.txt", nrows=12, header=False)
names(data) <- c("open", "high","low", "close")
data