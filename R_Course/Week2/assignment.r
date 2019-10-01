# mean() used to get mean of a vector
# paste(x,y) will append y to x
# list.files(dir) used to read all files in a dir 

pollutantmean <- function(directory="./specdata", pollutant, id=1:332){
  allFiles <- list.files(directory)
  allFilePaths <- paste(directory,allFiles, sep="/")
  meanVectors <- c()
  for (i in id){
    currentFile <- read.csv(allFilePaths[i], header=T, sep=",")
    naRemoved <- currentFile[!is.na(currentFile[, pollutant]), pollutant]
    meanVectors <- c(meanVectors, naRemoved)
  }
  res <- mean(meanVectors)
  return(res)
}

# sample tests
pollutantmean("specdata", "sulfate", 1:10)
# 4.064128

pollutantmean("specdata", "nitrate", 70:72)
# 1.706047

pollutantmean("specdata", "nitrate", 23)
# 1.280833


complete <- function(directory, id=1:332){
  allFiles <- list.files(directory)
  allFilePaths <- paste(directory,allFiles, sep="/")
  files <- c()
  counts <- c()
  for (i in id){
    currentFile <- read.csv(allFilePaths[i], header=T, sep=",")
    naRemoved <- currentFile[!is.na(currentFile$Date) & !is.na(currentFile$sulfate) & !is.na(currentFile$nitrate) & !is.na(currentFile$ID),]
    files <- c(files,i)
    counts <- c(counts,nrow(naRemoved))
  }
  res <- data.frame(id=files,nobs=counts)
  return(res)
}

complete("specdata", 1)
#   id nobs
# 1  1  117

complete("specdata", c(2, 4, 8, 10, 12))
#   id nobs
# 1  2 1041
# 2  4  474
# 3  8  192
# 4 10  148
# 5 12   96

complete("specdata", 30:25)
#   id nobs
# 1 30  932
# 2 29  711
# 3 28  475
# 4 27  338
# 5 26  586
# 6 25  463

complete("specdata", 3)
#   id nobs
# 1  3  243

