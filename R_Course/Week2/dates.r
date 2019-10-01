# dates are represented by date class
# times are represneted by POSIXct and POSIXlt class
# dates are stored as no. of days since 01-01-1970
# times are stored as no. of seconds since 01-01-1970

x <- as.Date("1970-01-01")
x
unclass(x)


# for times
# POSIXct is very arge integer vector
# POSIXlt stores list and stores day of the year, day of the week, etc
x <- Sys.time() # already in POSIXct format
x
p <- as.POSIXlt(x)
names(unclass(p))
p$mday


dateString <- c("January 10, 2012 10:40","December 9, 2011 9:10")
x <- strptime(dateString,"%B %d, %Y %H:%M")
x
class(x)


t1 <- as.Date("2012-03-01")
t2 <- as.Date("2012-03-05")

# difference in between the 2 dates
t1-t2