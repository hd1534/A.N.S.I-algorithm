# https://www.acmicpc.net/problem/9020


def sol():
    arr = [False, False] + [True] * 9999

    for i in range(2, 101):
        if arr[i]:
            for j in range(i * 2, len(arr), i):
                arr[j] = False

    for i in range(int(input())):
        n = int(input())

        tmp = n // 2
        while True:
            if arr[tmp] and arr[n - tmp]:
                print("%d %d" % (tmp, n - tmp))
                break
            tmp -= 1


if __name__ == "__main__":
    sol()
