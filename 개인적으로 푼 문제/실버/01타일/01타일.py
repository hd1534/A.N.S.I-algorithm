# https://www.acmicpc.net/problem/1904


def sol():
    dp = [1, 1]
    n = int(input())

    for i in range(2, n+1):
        dp.append((dp[i-1] + dp[i-2]) % 15746)

    print(dp[n])


if __name__ == "__main__":
    sol()
