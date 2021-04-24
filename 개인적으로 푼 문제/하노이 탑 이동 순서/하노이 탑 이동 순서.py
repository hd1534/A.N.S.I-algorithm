# https://www.acmicpc.net/problem/11729


def hanoi(n, FROM, TO, TEMP):
    if n == 0:
        return

    hanoi(n-1, FROM, TEMP, TO)
    print(FROM, TO)
    hanoi(n-1, TEMP, TO, FROM)


def sol():
    n = int(input())

    print(2**n - 1)
    hanoi(n, 1, 3, 2)


def short():
    def h(n, f, t): n and (h(n-1, f, f ^ t), print(f, t), h(n-1, f ^ t, t))
    n = int(input())
    print(2**n-1)
    h(n, 1, 3)


if __name__ == "__main__":
    sol()
