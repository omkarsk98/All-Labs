# used for tabular data
# mul lists with same length, list as column
# unlike matrices, dataframes can store diff classes of data
# special attribute as row.names
# created by read.table() or read.csv()
# converted to matrix by data.matrix()
x <- data.frame(foo=1:4, bar=c(T, T, F, F))
print(x)
nrow(x) # for number of rows
ncol(x) # for number of columns
