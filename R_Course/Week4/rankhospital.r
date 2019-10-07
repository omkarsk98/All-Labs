rankhospital <- function(state, outcome, num) {
    # Validate the outcome string
    outcomes = c("heart attack", "heart failure", "pneumonia")
    if( outcome %in% outcomes == FALSE ) 
      stop("invalid outcome")
    
    # Read data
    data <- read.csv("outcome-of-care-measures.csv", colClasses = "character")
    # arrange data
    data <- data[c(2, 7, 11, 17, 23)]
    names(data)[1] <- "name"
    names(data)[2] <- "state"
    names(data)[3] <- "heart attack"
    names(data)[4] <- "heart failure"
    names(data)[5] <- "pneumonia"


    # Validate the state string
    if( state %in% data[, 2] == FALSE ) 
      stop("invalid state")
    
    # Validate the num value
    if( num != "best" && num != "worst" && num%%1 != 0 ) 
      stop("invalid num")

    # Filter out values that are not available
    data <- data[data$state==state & data[outcome] != 'Not Available', ]

    # Order the data
    data[outcome] <- as.data.frame(sapply(data[outcome], as.numeric))
    data <- data[order(data$name, decreasing = FALSE), ]
    data <- data[order(data[outcome], decreasing = FALSE), ]

    # Process the num argument
    vals <- data[, outcome]
    if( num == "best" ) {
        rowNum <- which.min(vals)
    } else if( num == "worst" ) {
        rowNum <- which.max(vals)
    } else {
        rowNum <- num
    }

    # Return hospital name in that state with lowest 30-day death rate
    data[rowNum, ]$name
}

# examples
# rankhospital("TX", "heart failure", 4)
# rankhospital("MD", "heart attack", "worst")
# rankhospital("MN", "heart attack", 5000)

# quiz
rankhospital("NC", "heart attack", "worst")
rankhospital("WA", "heart attack", 7)
rankhospital("TX", "pneumonia", 10)
rankhospital("NY", "heart attack", 7)