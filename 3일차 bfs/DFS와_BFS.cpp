// https://www.acmicpc.net/problem/1260

#include <bits/stdc++.h>

using namespace std;

vector<int> vec[1010];
set<int> visited;

void dfs(int cur) {
    if (visited.find(cur) != visited.end())
        return;
    
    visited.insert(cur);
    printf("%d ", cur);
    
    for (int i : vec[cur]) {
        dfs(i);
    }
}

void bfs(int cur) {
    queue<int> q;

    visited.clear();
    q.push(cur);

    while (!q.empty()) {
        cur = q.front();
        q.pop();

        if (visited.find(cur) != visited.end())
            continue;

        visited.insert(cur);
        printf("%d ", cur);

        for (int i : vec[cur]) 
            q.push(i);
    }
    
}

int main() {
    int i, j, k;
    int n, m, v;

    scanf(" %d %d %d", &n, &m, &v);

    for (i = 0; i < m; i++) {
        scanf(" %d %d", &j, &k);
        vec[j].push_back(k);
        vec[k].push_back(j);
    }

    for (auto &s : vec) {
        sort(s.begin(), s.end());
    }

    dfs(v);
    printf("\n");
    bfs(v);

    return 0;
}