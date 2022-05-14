m = int(input())
n =m
cnt =0

while(True):
    if(n <10):
        new_first = n
        new_second = n
    else:
        new_first = n%10
        new_first%= 10
        new_second = (n//10) + (n%10)
        new_second %=10
        
    new = int(new_first)*10 + int(new_second)
    #print("New: ", new)
    cnt +=1
    if(m == int(new)):
        break
    else:
        n = new
        

print(cnt)

    
