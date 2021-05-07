// https://www.acmicpc.net/problem/2252

#include<bits/stdc++.h>

using namespace std;


int main() {
    int n,  m;
    int a, b, tmp;
    queue<int> q;
    vector<int> indegree;
    vector<vector<int>> graph;

    scanf(" %d %d", &n, &m);
    graph = vector<vector<int>>(n+1, vector<int>());
    indegree = vector<int> (n+1, 0);

    for (int i = 0; i < m; i++) {
        scanf(" %d %d", &a, &b);
        graph[a].push_back(b);
        indegree[b]++;
    }


    for (int i = 1; i <= n; i++) {
        if (!indegree[i]) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        tmp = q.front(); q.pop();
        printf("%d ", tmp);

        for (int i : graph[tmp]) {
            if (!--indegree[i]) {
                q.push(i);
            }
        }
    }

    return 0;
}