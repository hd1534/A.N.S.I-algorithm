// https://www.acmicpc.net/problem/4963

#include <bits/stdc++.h>

using namespace std;


int arr[60][60];
int di[] = {-1, 0, 1,   -1,  1,   -1,  0,  1};
int dj[] = { 1, 1, 1,    0,  0,   -1, -1, -1};

// 가로 세로 대각선을 확인하면서 -1인 영역을 count로 바꿈
void dfs(int i, int j, int count) {
    if (arr[i][j] != -1)
        return;

    arr[i][j] = count;

    for (int k = 0; k < 8; k++)
        dfs(i + di[k], j + dj[k], count);

}

int main() {
    int tmp;
    int w, h;
    int i, j, k;
    int count;

    while (true) {
        fill(begin(arr[0]), begin(arr[0]) + 60 * 60, 0);
        count = 0;

        scanf(" %d %d", &w, &h);

        if ( !(w || h) )
            return 0;

        // 입력 받음
        for (i = 1; i <= h; i++) 
            for (j = 1; j <= w; j++)  {
                scanf(" %d", &tmp);
                arr[i][j] = -tmp;
            }

        // 하나씩 확인해 보면서 dfs 호출
        for (i = 1; i <= h; i++) 
            for (j = 1; j <= w; j++) 
                if (arr[i][j] == -1) 
                    dfs(i, j, ++count);
        

        printf("%d\n", count);
    }

    return 0;
}