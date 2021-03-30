// https://www.acmicpc.net/problem/11724

#include <bits/stdc++.h>

using namespace std;

vector<int> vec[1010];
bool isVisited[1010] = {0, };


// target에서 방문할 수 있는 모든 지점을 isVisited에 기록함
void dfs(int target) {
    if (isVisited[target])
        return;
    
    isVisited[target] = true;

    for (int i : vec[target])
        dfs(i);
    
    return;
}

int main() {
    int n, m;
    int i, j, k;
    int count = 0;

    scanf(" %d %d", &n, &m);
    
    for (i = 0; i < m; i++) {
        scanf(" %d %d", &j, &k);
        vec[j].push_back(k);
        vec[k].push_back(j);
    }

    // 방문한적이 없는 곳만 dfs 호출
    for (i = 1; i <= n; i++) {
        if (isVisited[i])
            continue;

        dfs(i);
        count++;
    }

    printf("%d", count);

    return 0;
}