# https://www.acmicpc.net/problem/1181

def sol():
    arr = set()
    for i in range(int(input())):
        arr.add(input())

    print("\n".join(sorted(list(arr), key=lambda x: (len(x), x))))


def short():
    a = set()
    exec("a.add(input());"*int(input()))
    print("\n".join(sorted(list(a), key=lambda x: (len(x), x))))


if __name__ == "__main__":
    sol()
