// https://www.acmicpc.net/problem/10845

#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

int main() {
    queue<int> q;
    char input[10];
    int n, tmp;

    scanf(" %d", &n);
    while(n--) {
        scanf("%s", input);

        if (!strcmp(input, "push")) {
            scanf(" %d", &tmp);
            q.push(tmp);
        }
        else if (!strcmp(input, "pop")) {
            if (q.size()) {
                printf("%d\n", q.front());
                q.pop();
            }
            else
                printf("-1\n");
        }
        else if (!strcmp(input, "size")) {
            printf("%d\n", (int)q.size());
        }
        else if (!strcmp(input, "empty")) {
            printf("%d", q.empty());
        }
        else if (!strcmp(input, "front")) {
            if (q.size()) 
                printf("%d", q.front());
            else
                printf("-1\n");
        }
        else {
            if (q.size()) 
                printf("%d", q.back());
            else
                printf("-1\n");
        }
    }

    return 0;
}