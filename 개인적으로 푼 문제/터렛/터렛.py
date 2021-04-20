# https://www.acmicpc.net/problem/1002


def sol():
    for i in range(int(input())):
        x1, y1, r1, x2, y2, r2 = map(int, input().split())

        if (x1 == x2 and y1 == y2):
            print(-(r1 == r2))
            continue

        distance = ((x1 - x2)**2 + (y1 - y2)**2)**0.5

        if distance > r1 + r2 or max(r1, r2) > distance + min(r1, r2):
            print(0)
        elif distance == r1 + r2 or max(r1, r2) == distance + min(r1, r2):
            print(1)
        else:
            print(2)


def short():
    exec("X,Y,Z,x,y,z=map(int,input().split());d=((X-x)**2+(Y-y)**2)**0.5;l=max(Z,z);m=min(Z,z);print(-(Z==z) if X==x and Y==y else(0 if d>Z+z or l>d+m else(1 if d==Z+z or l==d+m else 2)));"*int(input()))


if __name__ == "__main__":
    short()
