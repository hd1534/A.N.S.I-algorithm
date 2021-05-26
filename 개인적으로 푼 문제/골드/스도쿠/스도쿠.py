# https://www.acmicpc.net/problem/2580


def rollback(arr, blank, removed, row, column, block):
    for (i, j) in removed:
        blank.append((i, j))
        row[i].add(arr[i][j])
        column[j].add(arr[i][j])
        block[(i//3)*3 + j//3].add(arr[i][j])


def dfs(arr, blank, row, column, block):
    flag = True  # 변화가 있는지 확인용
    removed = []  # 복구를 위한 기록

    while flag:
        flag = False

        for n, (i, j) in enumerate(blank):
            tmp = row[i] & column[j] & block[(i//3)*3 + j//3]
            if len(tmp) == 1:
                flag = True
                removed.append(blank.pop(n))
                row[i] -= tmp
                column[j] -= tmp
                block[(i//3)*3 + j//3] -= tmp
                arr[i][j] = tmp.pop()

            elif len(tmp) == 0:
                rollback(arr, blank, removed, row, column, block)
                return False  # 빈칸이지만 채울 수 있는게 없을때

    if len(blank) == 0:
        return True  # arr을 다 채웠으면 True

    # 남은 갯수가 가장 적은거 찾기
    m = 999  # 최솟값
    p = 0  # 최솟값 위치
    for n, (i, j) in enumerate(blank):
        tmp = len(row[i] & column[j] & block[(i//3)*3 + j//3])
        if m > tmp:
            p = n
            m = tmp

    i, j = blank.pop(p)
    for num in row[i] & column[j] & block[(i//3)*3 + j//3]:
        arr[i][j] = num
        row[i].remove(num)
        column[j].remove(num)
        block[(i//3)*3 + j//3].remove(num)

        if dfs(arr, blank, row, column, block):
            return True

        row[i].add(num)
        column[j].add(num)
        block[(i//3)*3 + j//3].add(num)

    blank.append((i, j))
    rollback(arr, blank, removed, row, column, block)

    return False


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

    dfs(arr, blank, row, column, block)

    for a in arr:
        print(*a)


if __name__ == "__main__":
    sol()
