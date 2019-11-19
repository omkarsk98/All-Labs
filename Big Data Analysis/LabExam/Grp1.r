setwd("/home/programmer/Chang/BTech/BTech Labs/Big Data Analysis/LabExam")
data <- read.csv("./Cars93.csv")
# colnames(data)
# drops <- c("RPM","Rev.per.mile","Weight")
# boxplot(data[,!(names(data) %in% drops)])

# cmeans = colMeans(data)
# mapply('/', data, cmeans)
boxplot(data)
