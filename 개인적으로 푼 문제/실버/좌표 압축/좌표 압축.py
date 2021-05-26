# https://www.acmicpc.net/problem/18870

def sol():
    input()
    arr = list(map(int, input().split()))
    dic = {s: i for i, s in enumerate(sorted(list(set(arr))))}

    print(*map(lambda x: dic[x], arr))


def short():
    input()
    a = [*map(int, input().split())]
    d = {s: i for i, s in enumerate(sorted(list(set(a))))}
    print(*map(lambda x: d[x], a))


if __name__ == "__main__":
    sol()
