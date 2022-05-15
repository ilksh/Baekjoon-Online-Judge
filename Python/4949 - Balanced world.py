def check(string):
    stack = []
    for elem in string:
        if elem == '(':
            stack.append(elem)

        elif elem == '[':
            stack.append(elem)

        elif elem == ')':
            if not stack or stack[-1] != '(':
                return "no"
            else:
                stack.pop()

        elif elem == ']':
            if not stack or stack[-1] != '[':
                return "no"
            else:
                stack.pop()

    if stack:
        return "no"
    else:
        return "yes"


while True:
    s = input()
    if s == '.':
        break
    print(check(s))



