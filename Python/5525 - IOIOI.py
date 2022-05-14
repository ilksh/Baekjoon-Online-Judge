n = int(input())    # number of character 'O'
m = int(input())    # length of the string s
s = input()         # string

pn_cnt = 0
O_cnt = 0
# Based on the index, explore both sides -> start index = 1
idx = 1

while idx < m-1:
    if s[idx-1] == 'I' and s[idx] == 'O' and s[idx+1] == 'I':
        O_cnt += 1
        if O_cnt == n:
            # decrease for the next round
            O_cnt -= 1
            pn_cnt += 1
        # O jumps one step at a time
        # ex) OOI (x), IOI (o)
        idx += 2
    else:
        # since we couldn't find the pattern 'IOI'
        # initialize the number of O
        O_cnt = 0
        # no jump
        idx += 1

print(pn_cnt)