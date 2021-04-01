// https://www.acmicpc.net/problem/2644

#include <bits/stdc++.h>


using namespace std;

vector<int> vec[110];
set<int> visited;


int bfs(const int t1, const int t2) {
    pair<int, int> cur; // <위치, count>
    queue<pair<int, int>> q;

    q.push(pair<int, int>(t1, 0));

    while (!q.empty()) {
        cur = q.front();
        q.pop();

        if (visited.find(cur.first) != visited.end())
            continue;
        visited.insert(cur.first);

        for (auto i : vec[cur.first]) {
            if (i == cur.first)
                continue;

            if (i == t2)
                return cur.second + 1;

            q.push(pair<int, int>(i, cur.second + 1));
        }
    }
    
    return -1;
}


int main() {
    int n, m;
    int t1, t2;
    int i, j;

    scanf(" %d %d %d %d", &n, &t1, &t2, &m);

    while (m--) {
        scanf(" %d %d", &i, &j);
        vec[i].push_back(j);
        vec[j].push_back(i);
    }

    printf("%d", bfs(t1, t2));

    return 0;
}
