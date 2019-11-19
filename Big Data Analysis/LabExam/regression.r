setwd("/home/programmer/Chang/BTech/BTech Labs/Big Data Analysis/LabExam")
data <- read.csv("./Cars93.csv")
fit<-lm(Price~.,data=data)
summary(fit)

# doing it on only numeric data
Cars_new = data[,c(4,5,6,7,8,13,14)]
fit<-lm(Price~.,data=Cars_new)
summary(fit)

predicted_price <- predict(fit,Cars_new)
comp = cbind(predicted_price, Cars_new$Price)
View(comp)
summary(comp)
cor(comp)