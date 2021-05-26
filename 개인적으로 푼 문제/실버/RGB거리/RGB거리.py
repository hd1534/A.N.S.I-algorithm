# https://www.acmicpc.net/problem/1149


def sol():
    n = int(input())
    arr = []

    for _ in range(n):
        arr.append(list(map(int, input().split())))

    dp = [arr[0]] + [[float('inf')]*3 for _ in range(n)]

    for i in range(1, n):
        for j in range(3):
            for k in range(3):
                if j != k:
                    dp[i][j] = min(dp[i][j], arr[i][j] + dp[i-1][k])

    print(min(dp[n-1]))


if __name__ == "__main__":
    sol()
