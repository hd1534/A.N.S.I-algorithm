# https://www.acmicpc.net/problem/1011


def sol():

    for i in range(int(input())):
        x, y = map(int, input().split())
        count = 1
        distance = y - x

        distance /= 2  # 시작과 끝의 속도? 는 1 이므로 가운데를 기준으로 대칭된다고 생각

        # 절반만 보는중.. count = 이번에 움직이는 거리
        while distance > count:
            distance -= count
            count += 1

        # count보다 작게 한번만 더 가면 되는 경우 (세세한 값은 이전단계들 에서 조절해 맞출 수 있다.)
        if distance * 2 <= count:
            count = count * 2 - 1
        # count만큼 두번 가야 하는 경우 (세세한 값은 이전단계들 에서 조절해 맞출 수 있다.)
        else:
            count = count * 2

        print(count)


if __name__ == "__main__":
    sol()
