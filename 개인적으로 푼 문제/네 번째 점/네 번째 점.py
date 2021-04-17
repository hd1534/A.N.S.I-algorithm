# https://www.acmicpc.net/problem/3009

def sol():
    x = y = 0

    for i in range(3):
        a, b = map(int, input().split())
        x ^= a
        y ^= b

    print(x, y)


def short():
    x = y = 0
    exec("a,b=map(int,input().split());x^=a;y^=b;"*3)
    print(x, y)


if __name__ == "__main__":
    sol()
