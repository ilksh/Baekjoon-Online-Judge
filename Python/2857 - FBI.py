answer = []
for i in range(1,6):
    agent = input()
    cnt = agent.count("FBI")
    if(cnt):
        answer.append(i)

if len(answer) == 0:
    print("HE GOT AWAY!")
else:
    for num in answer:
        print(num, end= " ")

