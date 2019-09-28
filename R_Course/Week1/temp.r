data <- read.csv("quiz.csv")
# ozone <- data["Ozone"]
# final <- ozone[!is.na(ozone)]
# mean(final)

# ozone <- subset(data, Ozone>31)

# temp <- subset(ozone, Temp>90)
# # ozone <- ozone[data["Temp"]>90]

# mean(temp$Solar)
# # solar <- ozone["Solar"]
# # solar

month <- subset(data, Month==5)
max(month$Ozone[!is.na(month$Ozone)])

# max(month[!is.na(month$Ozone)])
# month