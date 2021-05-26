# https://www.acmicpc.net/problem/11651


def sol():
    coordinates = []
    for i in range(int(input())):
        coordinates.append(list(map(int, input().split())))

    for cordinate in sorted(coordinates, key=lambda x: list(reversed(x))):
        print(cordinate[0], cordinate[1])


if __name__ == "__main__":
    sol()
