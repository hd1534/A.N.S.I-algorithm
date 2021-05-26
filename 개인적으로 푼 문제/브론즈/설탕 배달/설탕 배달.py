# https://www.acmicpc.net/problem/2839

def sol(n):
    result = 0

    while n > 2:
        if n % 5 == 0:
            print(result + n // 5)
            return
        n -= 3
        result += 1

    if n:
        print(-1)
    else:
        print(result)


if __name__ == "__main__":
    sol(int(input()))
