def harmony_check(compare):
    i =0
    while(True):
        i+=1
        cur_series = 1 + 3 * i * (i - 1)
        #print("cur: ", cur_series, "i: ", i)
        if(cur_series >= compare):
            print(i)
            return;

num = int(input())
harmony_check(num)



