// https://www.acmicpc.net/problem/1992

#include<bits/stdc++.h>

using namespace std;


int arr[65][65] = {0, };

bool check(int n, int start_i, int start_j) {
    int i, j, check = arr[start_i][start_j];

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (arr[start_i + i][start_j + j] != check)
                return false;
        }
    }

    return true;
}


string dnc(int n, int start_i, int start_j) {
    int i, j, sum = 0;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            sum += arr[start_i + i][start_j + j];

    if (sum == 0) 
        return "0";
    if (sum == n*n)
        return "1";

    n >>= 1;
    return "(" + dnc(n, start_i, start_j) + dnc(n, start_i, start_j + n) + dnc(n, start_i + n, start_j) + dnc(n, start_i + n, start_j + n) + ")";
}


int main() {
    int n, i, j;

    scanf(" %d", &n);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf(" %1d", &arr[i][j]);
        }
    }

    cout << dnc(n, 0, 0);
    
    return 0;
}