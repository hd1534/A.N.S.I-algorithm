# https://www.acmicpc.net/problem/9251


def sol():
    str1 = input()
    str2 = input()

    n, m = len(str1)+1, len(str2)+1
    arr = [[0 for _ in range(m)] for _ in range(n)]

    for i, c1 in enumerate(str1):
        for j, c2 in enumerate(str2):
            if c1 == c2:
                arr[i+1][j+1] = arr[i][j] + 1
            else:
                arr[i+1][j+1] = max(arr[i+1][j], arr[i][j+1])

    print(arr[-1][-1])


if __name__ == "__main__":
    sol()
