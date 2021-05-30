# https://www.acmicpc.net/problem/2565

# 처음에 이렇게 풀었는데 안됨.... 나중에 이게 왜 안되는지 확인해 봐야지...
def failed():
    n = int(input())
    arr = sorted([list(map(int, input().split())) for _ in range(n)])
    dp = [0 for _ in range(n)]

    # 겹치는 전깃줄 개수 기록
    for i, (start, end) in enumerate(arr):
        for j in range(i+1, n):
            s, e = arr[j]
            if (start <= s and e <= end) or (s <= start and end <= e):
                dp[j] += 1
                dp[i] += 1

    count = 0
    while True:
        i = m = 0  # m = 가장큰 값의 인덱스

        # 0인 값은 제거하고 최대값을 찾기
        while i < len(dp):
            if dp[i] <= 0:
                dp.pop(i)
                arr.pop(i)
                continue

            if dp[i] > dp[m]:
                m = i

            i += 1

        if len(dp) == 0:
            break

        start, end = arr[m]
        for i, (s, e) in enumerate(arr):
            if (start <= s and e <= end) or (s <= start and end <= e):
                dp[i] -= 1

        count += 1
        dp.pop(m)
        arr.pop(m)

    print(count)


def sol():
    n = int(input())
    arr = [a[1]
           for a in sorted([list(map(int, input().split())) for _ in range(n)])]
    dp = [1 for _ in range(n)]

    for start in range(n):
        cur = arr[start]
        for i in range(start+1, n):
            if arr[i] > cur and dp[i] <= dp[start]:
                dp[i] = dp[start] + 1

    print(n - max(dp))


if __name__ == "__main__":
    sol()
