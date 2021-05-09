// https://www.acmicpc.net/problem/2869

#include<bits/stdc++.h>

using namespace std;

int main() {
    long long int a, b, v;

    scanf(" %ld %ld %ld", &a, &b, &v);

    v -= a; // 마지막날 올라가는 거리
    a -= b; // 올라갔따 미끄러진 거리 (하루동안 움직인 거리)
    printf("%ld", 1 + v/a + (v%a != 0));

    return 0;
}