# https://www.acmicpc.net/problem/11053

def sol():
    n = int(input())
    arr = list(map(int, input().split()))
    dp = [1 for _ in range(n)]

    for start in range(n):
        cur = arr[start]
        for i in range(start+1, n):
            if arr[i] > cur and dp[i] <= dp[start]:
                dp[i] = dp[start] + 1

    print(max(dp))


if __name__ == "__main__":
    sol()
