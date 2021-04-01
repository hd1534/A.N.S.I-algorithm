// https://www.acmicpc.net/problem/2178

#include <bits/stdc++.h>

using namespace std;


int arr[110][110] = {0, };

int bfs(pair<int, int> cur, int n, int m) {
    int di[] = {1, -1, 0,  0};
    int dj[] = {0,  0, 1, -1};
    int k, ni, nj;
    queue<pair<int, int>> q;

    q.push(cur);
    arr[cur.first][cur.second] = 1;

    while(!q.empty()) {
        cur = q.front();
        q.pop();
        for (k = 0; k < 4; k++) {
            ni = cur.first + di[k];
            nj = cur.second + dj[k];

            if (arr[ni][nj] != -1)
                continue;

            if (ni == n && nj == m)
                return arr[cur.first][cur.second] + 1;

            arr[ni][nj] = arr[cur.first][cur.second] + 1;
            
            q.push(pair<int, int>(ni, nj));
        }

    }

    return -1;
}

int main() {
    int i, j, k;
    int n, m;

    scanf(" %d %d", &n, &m);

    // 주위를 0으로 감쌀려고 1부터 시작
    for (i = 1; i <= n; i++) { 
        for (j = 1; j <= m; j++) {
            scanf(" %1d", &k);
            arr[i][j] = -k;
        }
    }

    printf("%d", bfs(pair<int, int>(1, 1), n, m));

    return 0;
}