// https://www.acmicpc.net/problem/2748

#include<bits/stdc++.h>

using namespace std;

int main() {
    unsigned long long int a = 0, b = 1, tmp;
    int n;

    scanf(" %d", &n);

    while(n--) {
        tmp = a + b;
        a = b;
        b = tmp;
    }

    printf("%llu", a);

    return 0;
}