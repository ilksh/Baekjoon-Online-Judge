import sys
input = sys.stdin.readline
s = set()

def new_add(num):
    s.add(num)


def new_check(num):
    new_set = set([num])   # make a new set
    temp_set = s&new_set
    if len(temp_set) == 1:
        rst = True
    else:
        rst = False
    return rst


def new_remove(num):
    if len(s):
        s.discard(num)


def new_toggle(num):
    if new_check(num):
        new_remove(num)
    else:
        new_add(num)


def make_all():
    global s
    s = set(i for i in range(1, 21))


def make_empty():
    s = set([])


def ans_print(ans):
    for e in ans:
        print(int(e))


if __name__ == "__main__":
    ans = []
    n = int(input())
    for _ in range(n):
        order = input()
        order = order.split()
        if order[0] == "add":
            num = int(order[1])
            new_add(num)
        elif order[0] == "check":
            num = int(order[1])
            ans.append(new_check(num))
        elif order[0] == "toggle":
            num = int(order[1])
            new_toggle(num)
        elif order[0] == "all":
            make_all()
        elif order[0] == "empty":
            make_empty()
    ans_print(ans)