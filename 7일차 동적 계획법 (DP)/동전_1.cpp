// https://www.acmicpc.net/problem/11047

#include<bits/stdc++.h>

using namespace std;


int main() {
    int coins[105] = {0, };
    int dp[10005] = {0, };
    int n, i, j, k;

    scanf(" %d %d", &n, &k);

    for (i = 0; i < n; i++) 
        scanf(" %d", &coins[i]);
    
    // coins[0]만 있을때를 한번 해보고, coins[0]과 coins[1]이 있을때, coins[0]과 coins[1]과 coins[2]가 있을때 ... 이렇게 나아가면서 계산한다. 
    for (i = 0; i < n; i++) {
        for (j = 1; j <= k; j++) {
            if (j == coins[i]) {
                dp[j]++;
            }
            else if (j > coins[i]) { 
                dp[j] += dp[j-coins[i]];
            }
        }
    }

    printf("%d", dp[k]);

    return 0;
}