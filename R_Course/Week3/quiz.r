# execute the code for answer. sab kuch copy karoge kya?
library(datasets)
data(iris)
virgins <- subset(iris, Species=="virginica")
mean(virgins$Sepal.Length) # q1 
apply(iris[,1:4], 2, mean) # q2

library(datasets)
data(mtcars)
mtcars[1:5,]

print("tapply")
tapply(mtcars$mpg, mtcars$cyl, mean)
with(mtcars, tapply(mpg, cyl, mean))
sapply(split(mtcars$mpg, mtcars$cyl),mean)
# q3

fours <- subset(mtcars, cyl == 4)
eights <- subset(mtcars, cyl == 8)
abs(mean(fours$hp) - mean(eights$hp)) # q4 
