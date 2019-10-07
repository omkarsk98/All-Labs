set.seed(1)
sample(1:10,4)
# selects 4 random numbers from 1 to 10
# first param is the vector
# second param is the number of random numbers to be generated
sample(letters, 5)

sample(1:10)
# gives a random permuatation of this vector without reps

sample(1:10, replace=TRUE)
# allows repetition