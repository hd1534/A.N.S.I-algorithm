// https://www.acmicpc.net/problem/2805

#include<bits/stdc++.h>

using namespace std;

long long int n, m;
vector<long long int> arr;


long long int sum(long long height) {
    long long int s = 0;

    for (long long int i : arr) {
        if (i <= height) 
            break;
        
        s += i - height;
    }
    return s;
}


int main() {
    long long int tmp, prev, s, mid, e = 0;

    scanf(" %ld %ld", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf(" %ld", &tmp);
        arr.push_back(tmp);
    }

    sort(arr.rbegin(), arr.rend());

    tmp = 0, prev =  s = arr[0] - m / n;

    while (s > e) {
        mid = (s + e) / 2;
        
        if (sum(mid) < m) {
            prev = s;
            s = mid;
        }
        else {
            s = prev;
            e = mid + 1;
        }
    }
    // s == e 일때 탈출할건데, 탈출할때 쯤이면 s와 e는 1차이 정도에서 같아진것일텐데 같아졌을때 검증을 안하고 나왔으므로 검증하고 작으면 1만큼 조정
    if (sum(s) < m) {
        s--;
    }

    printf("%ld", s);

    return 0;
}