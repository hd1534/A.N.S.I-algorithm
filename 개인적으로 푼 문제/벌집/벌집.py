# https://www.acmicpc.net/problem/2292

def sol(n):
    n -= 1  # 시작 자리는 세지 않는다.
    m = 6
    count = 1

    while n > 0:
        n -= m
        m += 6
        count += 1
    
    return count


if __name__ == "__main__":
    print(sol(int(input())))