# Factors are used for categorial data
x <- factor(c("yes","no","yes","no","no"),levels=c("yes","no"))
print(x)
table(x) # leveled alphabetically
unclass(x)
