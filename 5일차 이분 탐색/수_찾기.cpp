// https://www.acmicpc.net/problem/1920

#include<bits/stdc++.h>

using namespace std;

vector<int> arr;
int n, m;


int search(int target) {
    int s = 0, e = n, mid;

    while (s <= e) {
        mid = (s + e) / 2;
        
        if (arr[mid] == target)
            return 1;
        
        if (arr[mid] > target)
            e = mid - 1;
        else
            s = mid + 1;
    }
    return 0;
}


int main() {
    int tmp;

    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %d", &tmp);
        arr.push_back(tmp);
    }

    sort(arr.begin(), arr.end());

    scanf(" %d", &m);
    while (m--) {
        scanf(" %d", &tmp);
        printf("%d\n", search(tmp));
    }

    return 0;
}