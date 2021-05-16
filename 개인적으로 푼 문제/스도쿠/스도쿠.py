# https://www.acmicpc.net/problem/2580


def sol():
    arr = []
    row = [None, None, None, None, None, None, None, None, None]
    column = [set(), set(), set(), set(), set(), set(), set(), set(), set()]
    block = [set(), set(), set(), set(), set(), set(), set(), set(), set()]
    s = set([1, 2, 3, 4, 5, 6, 7, 8, 9])
    blank = []

    # 가로, 세로, 블럭으로 나눠서 입력 받기
    # 나중에 찾아야 되는 0은 blank에 넣어둠
    for i in range(9):
        arr.append([int(n) for n in input().split()])
        row[i] = set(arr[i])

        for j, data in enumerate(arr[i]):
            if data == 0:
                blank.append((i, j))
            column[j].add(data)
            block[(i//3)*3 + j//3].add(data)

    # 필요한것만 저장
    for i in range(9):
        row[i] = s - row[i]
        column[i] = s - column[i]
        block[i] = s - block[i]

    while len(blank) != 0:
        for n, (i, j) in enumerate(blank):
            tmp = row[i] & column[j] & block[(i//3)*3 + j//3]
            if len(tmp) == 1:
                blank.pop(n)
                row[i] -= tmp
                column[j] -= tmp
                block[(i//3)*3 + j//3] -= tmp
                arr[i][j] = tmp.pop()

    for str in arr:
        print(*str)


if __name__ == "__main__":
    sol()
