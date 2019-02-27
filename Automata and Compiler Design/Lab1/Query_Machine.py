entry = input("Enter Input:")
current_state = 0
for i in entry:
    """ reject if input contains values other then 0 or 1 """
    if i != '0' and i != '1':
        print("Input should contain only 0 or 1")
        exit(-1)  # error
    """ if current state is 0
    remain at state 0 if next input value is 1
    go to state 1 if next input value is 0 """
    if current_state == 0:
        if i == '1':
            current_state = 0
        else:
            current_state = 1
        """ if current state is 1
        remain at state 1 if next input value is 1
        go to state 0 if next input value is 0 """
    else:
        if i == '1':
            current_state = 1
        else:
            current_state = 0

if current_state == 0:
    print("Input Accepted")
else:
    print("Input Not Accepted")
