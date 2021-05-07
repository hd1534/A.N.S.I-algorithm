// https://www.acmicpc.net/problem/1005

#include<bits/stdc++.h>

using namespace std;

int delay[1005];
int cur[1005];  // 그래프 내에서 읽을 원소 개수
int graph[1005][1005];
int dfsMemo[1005];  // 메모이제이션 


int dfs(int w) {
    int max = 0;
    int b, tmp;

    for (int i = 0; i < cur[w]; i++) {
        b = graph[w][i];

        // 메모이제이션
        if (dfsMemo[b] == -1) {
            tmp = dfs(b);
            dfsMemo[b] = tmp; 
        }
        else {
            tmp = dfsMemo[b];
        }

        if (tmp > max) {
            max = tmp;
        }
    }

    return max + delay[w];
}

int main() {
    int t;
    int n, k, w;
    int x, y, tmp;

    scanf(" %d", &t);

    while (t--) {
        scanf(" %d %d", &n, &k);
        fill(cur, cur+n+2, 0);  // cur를 0으로 초기화 (처피 다른것들은 커서 기준으로 동작해서 딱히 안지워도 덮어 쓰기에 상관 x)
        fill(dfsMemo, dfsMemo+n+2, -1);
        
        // 번호가 1번부터 시작하니 편하게 i=1부터 시작
        for (int i = 1; i <= n; i++) {
            scanf(" %d", &tmp);
            delay[i] = tmp;
        }

        for (int i = 0; i < k; i++) {
            scanf(" %d %d", &x, &y);

            graph[y][cur[y]++] = x; // y를 만들기 위해선 x가 필요
        }

        scanf(" %d", &w);
        printf("%d\n", dfs(w));
    }

    return 0;
}