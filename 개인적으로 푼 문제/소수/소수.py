# https://www.acmicpc.net/problem/2581

def sol(n, m):
    arr = [2] + list(range(3, m+1, 2))
    _min = float("inf")
    _sum = i = 0

    while i < len(arr):
        if arr[i] != 0:
            j = i + 1
            while j < len(arr):
                if arr[j] % arr[i] == 0:
                    arr[j] = 0
                j += 1
        i += 1

    if n == 2:
        _min = 2
        _sum = 2

    if m == 1:
        print(-1)
        return

    for i in arr[n//2:]:
        if i != 0:
            _min = min(_min, i)
        _sum += i

    if _min == float("inf"):
        print(-1)
    else:
        print(_sum)
        print(_min)


if __name__ == "__main__":
    sol(int(input()), int(input()))
