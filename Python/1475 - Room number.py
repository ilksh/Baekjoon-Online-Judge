check = [0 for i in range(10)]
room = input()

six_nine = 0

for char in room:
    num = int(char)
    
    # 6 and 9 can be turned upside down
    if num == 6 or num == 9: 
        six_nine += 1
        # 6 and 9 both used
        if six_nine == 2:
            check[6] += 1
            six_nine = 0
    else:
        check[num] += 1

# 6 and 9 were used odd times
if six_nine == 1:
    check[6] += 1

print(max(check))