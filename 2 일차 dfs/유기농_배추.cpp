// https://www.acmicpc.net/problem/1012

#include <bits/stdc++.h>

using namespace std;


int arr[60][60];
int di[] = {1, -1, 0, 0};
int dj[] = {0, 0, 1, -1};


// 주위 영역 묶기
void dfs(int i, int j, int count) {
    if (arr[i][j] != -1)
        return;

    arr[i][j] = count;

    for (int k = 0; k < 4; k++)
        dfs(i + di[k], j + dj[k], count);

}

int main() {
    int t;
    int n, m, l;
    int i, j, k;
    int count;

    scanf(" %d", &t);

    while (t--) {
        fill(begin(arr[0]), begin(arr[0]) + 60 * 60, 0);
        count = 0;

        scanf(" %d %d %d", &m, &n, &l);

        while  (l--) {
            scanf(" %d %d", &j, &i);
            arr[i+1][j+1] = -1;
        }

        for (i = 1; i <= n; i++) 
            for (j = 1; j <= m; j++) 
                if (arr[i][j] == -1) 
                    dfs(i, j, ++count);
        

        printf("%d\n", count);
    }

    return 0;
}