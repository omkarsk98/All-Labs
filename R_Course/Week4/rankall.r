rankall <- function(outcome, num = "best") {
  # Validate the outcome string
  outcomes = c("heart attack", "heart failure", "pneumonia")
  if( outcome %in% outcomes == FALSE ) stop("invalid outcome")
  
  # Validate the num value
  if( num != "best" && num != "worst" && num%%1 != 0 ) stop("invalid num")

  # Read data
  data <- read.csv("outcome-of-care-measures.csv", colClasses = "character")
  # Arrange
  data <- data[c(2, 7, 11, 17, 23)]
  names(data)[1] <- "name"
  names(data)[2] <- "state"
  names(data)[3] <- "heart attack"
  names(data)[4] <- "heart failure"
  names(data)[5] <- "pneumonia"

  # Filter out the rows that are not available
  data <- data[data[outcome] != 'Not Available', ]
  
  # Order the data
  data[outcome] <- as.data.frame(sapply(data[outcome], as.numeric))
  data <- data[order(data$name, decreasing = FALSE), ]
  data <- data[order(data[outcome], decreasing = FALSE), ]

  # Process num argument
  getHospByRank <- function(df, s, n) {
    df <- df[df$state==s, ]
    vals <- df[, outcome]
    if( n == "best" ) {
        rowNum <- which.min(vals)
    } else if( n == "worst" ) {
        rowNum <- which.max(vals)
    } else {
        rowNum <- n
    }
    df[rowNum, ]$name
  }
  
  # For each state, find the hospital of the given rank
  states <- data[, 2]
  states <- unique(states)
  newdata <- data.frame("hospital"=character(), "state"=character())
  for(st in states) {
    hosp <- getHospByRank(data, st, num)
    newdata <- rbind(newdata, data.frame(hospital=hosp, state=st))
  }

  # Return a data frame with the hospital names and the (abbreviated) state name
  newdata <- newdata[order(newdata['state'], decreasing = FALSE), ]
  newdata
}

# examples
# head(rankall("heart attack", 20), 10)
# tail(rankall("pneumonia", "worst"), 3)
# tail(rankall("heart failure"), 10)

# quiz
r <- rankall("heart attack", 4)
as.character(subset(r, state == "HI")$hospital)

r <- rankall("pneumonia", "worst")
as.character(subset(r, state == "NJ")$hospital)

r <- rankall("heart failure", 10)
as.character(subset(r, state == "NV")$hospital)
