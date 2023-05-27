n = int(input()) # input the number
 
mul_of_two = 0   # number of nums who is multiple of two
mul_of_five = 0  # # number of nums who is multiple of five

for i in range(1, n + 1):
    # current number is neither multiple of two or five
    if i % 2 and i % 5 : continue
 
    # current number is multiple of two
    if not i % 2:
        while i % 2 == 0:
            i //= 2
            mul_of_two += 1
    # current number is multiple of five
    if not i % 5:
        while i % 5 == 0:
            i //= 5
            mul_of_five += 1
 
 
rst  = 0
if (mul_of_two + mul_of_five != 0): rst = min(mul_of_two, mul_of_five)
print(rst)

    