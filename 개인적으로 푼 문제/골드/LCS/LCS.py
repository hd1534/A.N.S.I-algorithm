# https://www.acmicpc.net/problem/9251


def faild():
    str1 = input()
    str2 = input()
    arr = []
    dic = {chr(i): [j for j, data in enumerate(str2) if data == chr(i)]
           for i in range(ord('A'), ord('Z')+1)}

    for index, data in enumerate(str1):
        # 연결 할 수 있는게 있는 모든 노드들을 일단 만들어서 넣어둔다.
        for targetIdx in dic[data]:
            arr.append(targetIdx)

    # 가장긴 증가하는 수열
    n = len(arr)
    dp = [1 for _ in range(n)]
    for start in range(n):
        cur = arr[start]
        for i in range(start+1, n):
            if arr[i] > cur and dp[i] <= dp[start]:
                dp[i] = dp[start] + 1

    print(max(dp))


if __name__ == "__main__":
    sol()
