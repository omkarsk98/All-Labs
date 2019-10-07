best <- function(state, outcome){
  outcomes = c("heart attack", "heart failure", "pneumonia")
  if( outcome %in% outcomes == FALSE ) 
    stop("invalid outcome")

  # read data
  data <- read.csv("outcome-of-care-measures.csv", colClasses = "character")
  
  # arrange data to readable form and keep only required fields
  data <- data[c(2, 7, 11, 17, 23)]
  names(data)[1] <- "name"
	names(data)[2] <- "state"
	names(data)[3] <- "heart attack"
	names(data)[4] <- "heart failure"
	names(data)[5] <- "pneumonia"

  # validate state
  if( state %in% data[,2] == FALSE ) 
    stop("invalid state")

  # remove data that is not available
  data <- data[data$state==state & data[outcome] != 'Not Available', ]
	
  # get min
  rowNum <- which.min(data[, outcome])
	# Return hospital name 
	data[rowNum, ]$name
}

# examples
# best("TX", "heart attack")
# best("TX", "heart failure")
# best("MD", "heart attack")
# best("MD", "pneumonia")
# best("BB", "heart attack")
# best("NY", "hert attack")

# quiz questions
best("SC", "heart attack")
best("NY", "pneumonia")
best("AK", "pneumonia")