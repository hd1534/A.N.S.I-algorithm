# https://www.acmicpc.net/problem/10844

def sol():
    n = int(input())
    dp = [[0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0]] + [[0] * 12 for _ in range(n)]

    for i in range(n):
        for j in range(1, 11):
            dp[i+1][j+1] += dp[i][j]
            dp[i+1][j-1] += dp[i][j]

    print(sum(dp[n-1][1:-1]) % 1000000000)


if __name__ == "__main__":
    sol()
