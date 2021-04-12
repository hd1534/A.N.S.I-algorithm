# https: // www.acmicpc.net/problem/11653


def sol(n):
    if n == 1:
        return

    # 2의 배수일때  2로 나눔
    while n & 1 != 1:
        print(2)
        n >>= 1

    # 만약 i로 나누어지면 출력하고 한번더 나눠본다.
    i = 3
    while i*i <= n:
        if n % i:
            i += 2
        else:
            print(i)
            n /= i

    # 1이 아니면 출력한다 (1이 아닌 경우는 i*i == n일때)
    if n != 1:
        print(int(n))


if __name__ == "__main__":
    sol(int(input()))
