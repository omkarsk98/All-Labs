entry = input("Enter Input:")
current_state = 0
for i in entry:
    """ reject if input contains values other then 0 or 1 """
    if i != '0' and i != '1':
        print("Input should contain only 0 or 1")
        exit(-1)  # error
    """ if current state is 0
    go to state 3 if next input value is 1
    go to state 1 if next input value is 0 """
    if current_state == 0:
        if i == '1':
            current_state = 3
        else:
            current_state = 1
        """ if current state is 1
        remain at state 1 if next input value is 0
        go to state 2 if next input value is 1 """
    elif current_state == 1:
        if i == '1':
            current_state = 2
        else:
            current_state = 1
        """ if current state is 2
        remain at state 2 if next input value is 1
        go to state 1 if next input value is 0 """
    elif current_state == 2:
        if i == '1':
            current_state = 2
        else:
            current_state = 1
        """ if current state is 3
            go to state 2 if next input value is 1
            go to state 1 if next input value is 0 """
    elif current_state == 3:
        if i == '1':
            current_state = 2
        else:
            current_state = 1
""" if the ending state is 2, input is Accepted
else it is rejected """
if current_state == 2:
    print("Input Accepted")
else:
    print("Input Not Accepted")
