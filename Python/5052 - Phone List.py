class Trie:
    def __init__(self):
        self.child = {}
        self.finished = False

    def insert(self, phone):
        node = self
        for digit in phone:
            if digit not in node.child:
                node.child[digit] = Trie()

            node = node.child[digit]

        node.finished = True

    def search(self):
        rst = True
        for cur_node in self.child.values():
            if cur_node.finished:
                if len(cur_node.child):
                    return False
                else:
                    return True

            temp = cur_node.search()
            if temp is False:
                rst = False

        return rst


tc = int(input())

for _ in range(tc):
    trie = Trie()

    n = int(input())

    for _ in range(n):
        phone_number = input()
        trie.insert(phone_number)

    if trie.search():
        print("YES")
    else:
        print("NO")
