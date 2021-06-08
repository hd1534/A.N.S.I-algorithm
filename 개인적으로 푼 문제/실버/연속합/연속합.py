# https://www.acmicpc.net/problem/1912


n = int(input())
arr = list(map(int, input().split()))
m = -9999
cur = 0

for i in arr:
    if i < 0:
        m = max(cur, m)
        if i + cur < 0:
            cur = 0
        else:
            cur += i
    else:
        cur += i

print(max(cur, m) if max(cur, m) != 0 else max(arr))
