# https://www.acmicpc.net/problem/2579


def sol():
    n = int(input())
    arr = [int(input()) for _ in range(n)] + [0, 0, 0]
    # [["연달아 가능할때", "건너뛰어야 할때"], ]
    # 시작점은 계단에 포함되지 않아서 초기값으로 이렇게 넣어줘야됨
    dp = [[arr[0], arr[0]], [arr[1], 0]] + [[0, 0] for _ in range(n+4)]

    for i in range(n):
        # 한칸 갔을 경우 다음번에는 한칸 건너뛰어야 한다.
        dp[i+1][1] = max(dp[i+1][1], arr[i+1] + dp[i][0])

        # 두칸 갔을 경우 다음번에는 연달아 가능하다.
        dp[i+2][0] = max(dp[i+2][0], arr[i+2] + dp[i][0], arr[i+2] + dp[i][1])

    print(max(dp[n-1]))


if __name__ == "__main__":
    sol()
