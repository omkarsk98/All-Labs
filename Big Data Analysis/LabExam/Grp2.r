setwd("/home/programmer/Chang/BTech/BTech Labs/Big Data Analysis/LabExam")
cars <- read.csv("./Cars93.csv")
# head(data)
data.frame(table(cars$Cylinders))