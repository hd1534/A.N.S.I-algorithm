
def sol():
    n = int(input())
    arr = [int(input()) for _ in range(n)] + [0, 0, 0]
    dp = [[arr[0], arr[0]], [arr[1], 0]] + [[0, 0] for _ in range(n+1)]
    # [[연달아 가도 될때 최댓값, 건너뛰어야만 하는 최댓값]]

    for i in range(n):
        # 연달아 갈때
        dp[i+1][1] = max(dp[i+1][1], arr[i+1] + dp[i][0])
        # 한칸 건너뛀때
        dp[i+2][0] = max(dp[i+2][0], arr[i+2] + dp[i][1], arr[i+2] + dp[i][0])
        # 두칸 건너뛸때
        dp[i+3][0] = max(dp[i+3][0], arr[i+3] + dp[i][1], arr[i+3] + dp[i][0])

        # 세칸 이상인경우 가운데 와인을 마시는게 무조건 더 효율적이므로 필요 없다.
        # ex)  OXXXO < OXOXO

    # 마지막을 포함하지 않는게 더 많을 수 도 있기에..
    print(max(dp[n-1]+dp[n-2]))


if __name__ == "__main__":
    sol()
