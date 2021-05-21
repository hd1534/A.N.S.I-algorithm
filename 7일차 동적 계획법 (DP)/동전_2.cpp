// https://www.acmicpc.net/problem/11047

#include<bits/stdc++.h>

#define MAX 99999

using namespace std;


int main() {
    int coins[105] = {0, };
    int dp[10005];
    int n, i, j, k;

    scanf(" %d %d", &n, &k);

    fill(dp, dp + k + 5, MAX);  // 여유롭게 큰 값으로 초기화

    for (i = 0; i < n; i++) 
        scanf(" %d", &coins[i]);
    
    // 최소 동전 개수를 기록한다.
    for (i = 1; i <= k; i++) {
        for (j = 0; j < n; j++) {
            if (i == coins[j]) {
                dp[i] = 1;
            }
            else if (i > coins[j] && dp[i] > dp[i-coins[j]] + 1) { 
                dp[i] = dp[i-coins[j]] + 1;
            }
        }
    }

    if (dp[k] == MAX) {
        printf("-1");
    }
    else {
        printf("%d", dp[k]);
    }

    return 0;
}