# https://www.acmicpc.net/problem/1932


def sol():
    n = int(input())
    arr = [list(map(int, input().split())) for _ in range(n)]
    dp = [[arr[0][0]]] + [[0]*i for i in range(2, n+1)]

    for i in range(n-1):
        for j in range(i+1):
            dp[i+1][j] = max(dp[i+1][j], arr[i+1][j] + dp[i][j])  # 좌
            dp[i+1][j+1] = max(dp[i+1][j+1], arr[i+1][j+1] + dp[i][j])  # 우

    print(max(dp[n-1]))


if __name__ == "__main__":
    sol()
