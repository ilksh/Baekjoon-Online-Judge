import sys
from collections import Counter

s = sys.stdin.readline()
s= s.upper()
if len(s) == 2:
    print(s)
    
else:
    new_s = sorted(Counter(s).items(), key=lambda x:(-x[1],x[0]))

    # print(new_s)
    if new_s[0][1] == new_s[1][1]:
        print("?")
    else:
        print(new_s[0][0])


