# https://www.acmicpc.net/problem/9663


count = n = 0


def dfs(i, row, diagonal1, diagonal2):
    global n, count

    if i == 0:
        count += 1
        return

    i -= 1

    for j in row:
        if diagonal1[i+j] == 0 and diagonal2[i+n-1-j] == 0:
            diagonal1[i+j] = diagonal2[i+n-1-j] = 1

            dfs(i, [r for r in row if r != j], diagonal1, diagonal2)

            diagonal1[i+j] = diagonal2[i+n-1-j] = 0


def sol():
    global n, count

    n = int(input())

    row = [i for i in range(n)]
    diagonal1 = [0 for _ in range(2*n)]
    diagonal2 = [0 for _ in range(2*n)]

    dfs(n, row, diagonal1, diagonal2)
    print(count)


if __name__ == "__main__":
    sol()
