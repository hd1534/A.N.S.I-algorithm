# https://www.acmicpc.net/problem/11054

def sol():
    n = int(input())
    arr = list(map(int, input().split()))
    dpUp = [1 for _ in range(n)]  # 점점 커지는
    dpDown = [1 for _ in range(n)]  # 점점 작아지는

    for start in range(n):
        cur = arr[start]
        for i in range(start+1, n):
            if arr[i] > cur and dpUp[i] <= dpUp[start]:
                dpUp[i] = dpUp[start] + 1

    arr.reverse()
    for start in range(n):
        cur = arr[start]
        for i in range(start+1, n):
            if arr[i] > cur and dpDown[i] <= dpDown[start]:
                dpDown[i] = dpDown[start] + 1
    dpDown.reverse()

    print(max([dpUp[i] + dpDown[i] for i in range(n)])-1)


if __name__ == "__main__":
    sol()
