// https://www.acmicpc.net/problem/2630

#include<bits/stdc++.h>

using namespace std;


int white = 0, blue = 0;
int arr[130][130] = {0,};

void dnc(int n, int start_i, int start_j) {
    int i, j, sum = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            sum += arr[start_i + i][start_j + j];
        }
    }

    if (sum == 0) {
        white ++;
        return;
    }
    if (sum == n*n) {
        blue ++;
        return;
    }

    n >>= 1;
    dnc(n, start_i, start_j);
    dnc(n, start_i + n, start_j);
    dnc(n, start_i, start_j + n);
    dnc(n, start_i + n, start_j + n);

    return;
}


int main() {
    int n, i, j;

    scanf(" %d", &n);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) 
            scanf(" %d", &arr[i][j]);

    dnc(n, 0, 0);

    printf("%d\n%d", white, blue);

    return 0;
}