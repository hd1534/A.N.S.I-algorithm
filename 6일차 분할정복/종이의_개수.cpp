// https://www.acmicpc.net/problem/1780

#include<bits/stdc++.h>

using namespace std;


int m = 0, z = 0, p = 0;
int arr[2500][2500] = {0,};


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


void dnc(int n, int start_i, int start_j) {
    int i, j;

    if (n == 0) {
        return;
    }


    if (check(n, start_i, start_j)) {
        switch (arr[start_i][start_j]) {
        case -1:
            m ++;
            break;
        case 0:
            z ++;
            break;
        case 1:
            p ++;
            break;
        }
        return;
    }
    
    n /= 3;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            dnc(n, start_i + i*n, start_j + j*n);
        }
    }

    return;
}


int main() {
    int n, i, j;

    scanf(" %d", &n);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) 
            scanf(" %d", &arr[i][j]);

    dnc(n, 0, 0);

    printf("%d\n%d\n%d", m, z, p);

    return 0;
}