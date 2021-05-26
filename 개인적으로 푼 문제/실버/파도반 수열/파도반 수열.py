# https://www.acmicpc.net/problem/9461
# ㅋㅋㅋㅋ 이걸 지하철에서 핸드폰으로 풀줄이야 ㅋㅋㅋㅋㅋㅋㅋㅋ


dp = [1,1,1,2,2]
for i in range(99):
    dp.append(dp[i]+dp[i+4])

for i in range(int(input())):
    print(dp[int(input())-1])
