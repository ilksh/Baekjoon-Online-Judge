n = int(input())

file1 = list(input())

for i in range(n-1):
    file2 = list(input())
    for j in range(len(file1)):
        if file1[j] != file2[j]:
            file1[j] = '?'
            
print("".join(file1))
