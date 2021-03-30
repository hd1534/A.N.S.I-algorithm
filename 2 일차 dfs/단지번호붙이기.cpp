// https://www.acmicpc.net/problem/2667

#include <bits/stdc++.h>

using namespace std;


int arr[30][30] = {0, };
int di[] = {1, -1, 0, 0};
int dj[] = {0, 0, 1, -1};

// -1인 부분을 num으로 바꾸고, num의 개수를 리턴
int dfs(int i, int j, int num) {
    int count = 1;

    if (arr[i][j] != -1)
        return 0;

    arr[i][j] = num;

    for (int k = 0; k < 4; k++)
        count += dfs(i + di[k], j + dj[k], num);

    return count;
}

int main() {
    int n, tmp;
    int i, j, k;
    int num = 0;
    vector<int> vec;

    scanf(" %d", &n);

    // %1d 씩 값을 받아서 저장 (1부터 시작하는 이유는 겉에 0으로 패딩하려고)
    for (i = 1; i <= n; i++) 
        for (j = 1; j <= n; j++) {
                scanf(" %1d", &tmp);
                arr[i][j] = -tmp;
        }

    // 하나씩 확인해 보면서 -1인 영역을 num 영역으로 바꾸는 함수 실행
    for (i = 1; i <= n; i++) 
        for (j = 1; j <= n; j++) 
            if (arr[i][j] == -1) 
                vec.push_back(dfs(i, j, ++num));
    
    // 정렬
    sort(vec.begin(), vec.end());
    
    // 정답 출력
    printf("%d\n", num);
    for (int i : vec)
        printf("%d\n", i);

    return 0;
}