// https://www.acmicpc.net/problem/7576

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> arr;
vector<pair<int, int>> toCheck;
queue<pair<int, int>> q;

int bfs() {
    int k, max = 1;
    int ni, nj;
    pair<int, int> cur;
    int di[] = {1, -1, 0,  0};
    int dj[] = {0,  0, 1, -1};

    // bfs로 기록하면서 탐색
    while (!q.empty()) {
        cur = q.front();
        q.pop();

        for (k = 0; k < 4; k++) {
            ni = cur.first + di[k];
            nj = cur.second + dj[k];

            if (arr[ni][nj] != 0)
                continue;
            
            arr[ni][nj] = arr[cur.first][cur.second] + 1;
            max = arr[ni][nj] > max ? arr[ni][nj] : max;
            q.push(pair<int, int> (ni, nj));            
        }
    }

    // 비어있는 곳 기준으로 확인해보면 익지 않은 토마토가 있는지 확인 가능
    for (auto cur : toCheck) {
        for (k = 0; k < 4; k++) {
            if (arr [cur.first + di[k]][cur.second + dj[k]] == 0)
                return -1;
        }
    }

    return max - 1;
}


int main() {
    int n, m;
    int i, j, k;

    scanf(" %d %d", &m, &n);

    // 맵 만들기
    arr.push_back(vector<int>(m + 2, -2));
    for (i = 1; i <= n; i++) {
        arr.push_back(vector<int> (1, -2));
        
        for (j = 1; j <= m; j++) {
            scanf(" %d", &k);
            arr[i].push_back(k);
            if (k == 1)
                q.push(pair<int, int>(i, j));
            if (k == -1)
                toCheck.push_back(pair<int, int>(i, j));
        }

        arr[i].push_back(-2);
    }
    arr.push_back(vector<int>(m + 2, -2));

    if (q.empty()) {
        printf("-1");
        return 0;
    }

    printf("%d", bfs());
    // for (auto i : arr) {
    //     printf("\n");
    //     for (auto j : i) {
    //         printf("%2d ", j);
    //     }
    // }

    return 0;
}