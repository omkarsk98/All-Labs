corr <- function(directory, threshold=0){
  allFiles <- list.files(directory)
  allFilePaths <- paste(directory,allFiles, sep="/")
  corVectors <- c()
  for (i in 1:332){
    currentFile <- read.csv(allFilePaths[i], header=T, sep=",")
    naRemoved <- currentFile[!is.na(currentFile$Date) & !is.na(currentFile$sulfate) & !is.na(currentFile$nitrate) & !is.na(currentFile$ID),]
    if(nrow(naRemoved)>threshold){
      corVectors <- c(corVectors,cor(naRemoved$sulfate, naRemoved$nitrate))
    }
  }
  return(corVectors)
}

cr <- corr("specdata", 150)
head(cr)
# -0.01895754 -0.14051254 -0.04389737 -0.06815956 -0.12350667 -0.07588814

summary(cr)
#     Min.  1st Qu.   Median     Mean  3rd Qu.     Max. 
# -0.21057 -0.04999  0.09463  0.12525  0.26844  0.76313

cr <- corr("specdata", 400)
head(cr)
# -0.01895754 -0.04389737 -0.06815956 -0.07588814  0.76312884 -0.15782860

summary(cr)
#     Min.  1st Qu.   Median     Mean  3rd Qu.     Max. 
# -0.17623 -0.03109  0.10021  0.13969  0.26849  0.76313 

cr <- corr("specdata", 5000)
summary(cr)
# Length  Class   Mode 
#      0   NULL   NULL 

length(cr)
# 0

cr <- corr("specdata")
summary(cr)
#     Min.  1st Qu.   Median     Mean  3rd Qu.     Max. 
# -1.00000 -0.05282  0.10718  0.13684  0.27831  1.00000 

length(cr)
# 323

cr <- corr("specdata", 2000)                
n <- length(cr)                
cr <- corr("specdata", 1000)                
cr <- sort(cr)
print(c(n, round(cr, 4)))