# https://www.acmicpc.net/problem/1003

def fibonacci(n):
    arr = [[1, 0], [0, 1]]  # [0의 갯수, 1의 갯수],

    for i in range(2, n+2):
        arr.append([arr[i-1][0] + arr[i-2][0], arr[i-1][1] + arr[i-2][1]])

    return arr


def sol():

    arr = fibonacci(40)

    for _ in range(int(input())):
        print(*arr[int(input())])


def short():
    exec("a,b=1,0;exec('a,b=b,a+b;'*int(input()));print(a,b);"*int(input()))


if __name__ == "__main__":
    sol()
