// https://www.acmicpc.net/problem/2606

#include <bits/stdc++.h>

using namespace std;

vector<int> vec[105];
set<int> visited;


// target에 연결되어 있는 모든 위치를 들르고, visited 에 기록
void dfs(int target) {
    // 만약 이미 방문했으면 다시 방문하지 않음
    if (visited.find(target) != visited.end())
        return;

    visited.insert(target);

    for (int i : vec[target])
        dfs(i);

    return;
}


int main() {
    int n, m;
    int i, j, k;

    scanf(" %d\n %d", &n, &m);

    for (i = 0; i < m; i++) {
        scanf(" %d %d", &j, &k);
        vec[j].push_back(k);
        vec[k].push_back(j);
    }

    dfs(1);
    printf("%d", visited.size() - 1);
}
