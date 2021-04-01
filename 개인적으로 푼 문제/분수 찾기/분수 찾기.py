# https://www.acmicpc.net/problem/1193

def sol(n):
    d = 1

    while n > d:
        n -= d
        d += 1

    # d는 대각선으로 몇번째 줄인지
    return [
        str(n) + "/" + str(d - n + 1),  # d가 짝수일때 오른쪽 위에서 왼쪽 아래로
        str(d - n + 1) + "/" + str(n)  # d가 홀수일때 왼쪽 아래서 오른쪽 위로
    ][d % 2]


if __name__ == "__main__":
    print(sol(int(input())))
