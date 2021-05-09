# https://www.acmicpc.net/problem/15649


def permutations(arr, m, li):
    if (m == 0):
        print(li)
        return

    for i in arr:
        permutations([x for x in arr if x != i], m-1, li + str(i) + " ")


def sol():
    n, m = map(int, input().split())

    permutations(range(1, n+1), m, "")


if __name__ == "__main__":
    sol()
