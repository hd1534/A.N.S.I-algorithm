# https://www.acmicpc.net/problem/9663


count = n = 0


class Node:
    def __init__(self, data, prev=None):
        self.data = data
        self.prev = prev
        self.next = None

    def __repr__(self):
        return self.data

    def __str__(self):
        return str(self.data)

    def __add__(self, num):
        return self.data + num


class LinkedList:
    def __init__(self, nodes=None):
        self.head = None
        if nodes is not None:
            node = Node(data=nodes.pop(0))
            self.head = node
            for elem in nodes:
                node.next = Node(data=elem, prev=node)
                node = node.next

    def __iter__(self):
        node = self.head
        while node is not None:
            yield node
            node = node.next

    def __repr__(self):
        node = self.head
        nodes = []
        while node is not None:
            nodes.append(node.data)
            node = node.next
        nodes.append("None")
        return " -> ".join(map(str, nodes))

    def pop(self, node):
        if self.head == node:
            self.head = node.next
            if node.next is not None:
                node.next.prev = None
        else:
            node.prev.next = node.next
            if node.next is not None:
                node.next.prev = node.prev

    def unpop(self, node):
        if node.prev is None:
            self.head = node
            if node.next is not None:
                node.next.prev = node
        else:
            node.prev.next = node
            if node.next is not None:
                node.next.prev = node


def dfs(i, row, diagonal1, diagonal2):
    global n, count

    if i == 0:
        count += 1
        return

    i -= 1

    for j in row:
        if diagonal1[i+j.data] == 0 and diagonal2[i+n-1-j.data] == 0:
            diagonal1[i+j.data] = diagonal2[i+n-1-j.data] = 1
            row.pop(j)

            dfs(i, row, diagonal1, diagonal2)

            row.unpop(j)
            diagonal1[i+j.data] = diagonal2[i+n-1-j.data] = 0


def sol():
    global n, count

    n = int(input())

    row = LinkedList([i for i in range(n)])
    diagonal1 = [0 for _ in range(2*n)]
    diagonal2 = [0 for _ in range(2*n)]

    dfs(n, row, diagonal1, diagonal2)
    print(count)


if __name__ == "__main__":
    sol()
