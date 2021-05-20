// https://www.acmicpc.net/problem/11047

#include<bits/stdc++.h>

using namespace std;


int main() {
    int arr[] = {100000000,100000000,100000000,100000000,100000000,100000000,100000000,100000000,100000000,100000000};
    int n, k, result = 0;

    scanf(" %d %d", &n, &k);

    while (n) 
        scanf(" %d", &arr[--n]);
    
    for (n = 0; n < 10; n++) {
        if (arr[n] < k) {
            result += k / arr[n];
            k %= arr[n];
        }
        else if (arr[n] == k) {
            result += k / arr[n];
            break;
        }
    }

    printf("%d", result);

    return 0;
}