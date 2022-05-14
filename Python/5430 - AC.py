from collections import deque

tc = int(input())

for i in range(tc):

    e_check = False  # verify array is empty
    r_check = False  # check command includes reverse operation

    command = input()  # function p
    num = int(input())  # number of data
    temp = input()

    # parsing and slicing
    temp = temp[1:len(temp) - 1]  # delete square bracket on both sides
    temp = temp.split(',')  # delete ',' btw numbers

    if num == 0:
        dq = deque()
    else:
        dq = deque(temp)

    for char in command:
        if char == 'R':
            r_check = not r_check
            
        elif char == 'D':
            if len(dq) == 0:
                e_check = True
                break

            # front of the reversed array = end of original array
            if r_check:
                dq.pop()

            # front of original array = popleft()
            else:
                dq.popleft()

    # if R order was issued odd times -> reverse the array
    if r_check:
        dq.reverse()

    if e_check:
        print("error")
    else:
        print('[' + ",".join(dq) + ']')x