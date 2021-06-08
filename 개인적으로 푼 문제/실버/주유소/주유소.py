# https://www.acmicpc.net/problem/13305

def sol():
    n = int(input())
    distance = list(map(int, input().split()))
    price = list(map(int, input().split()))

    result = 0
    cur = 1000000000  # 현재 기름값
    for i, d in enumerate(distance):
        cur = min(cur, price[i])
        result += cur * distance[i]

    print(result)


if __name__ == "__main__":
    sol()
