// https://www.acmicpc.net/problem/1074

#include <bits/stdc++.h>

using namespace std;


// 2**n 값을 위한 배열 [2**n for n in range(31)]
int square[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824};


// n: 현재 블럭이 2**n 인지 (2의 n제곱인지)
// start_val: 시작점, 즉 상대좌표(0,0)의 값
// start_row, start_column: 시작 지점의 행과 열
// target_row, target_column: 목표 지점의 행과 열
int dnc(int n, int start_val, int start_row, int start_column, int target_row, int target_column) {
    int relative_row,  relative_column; // 상대적인 행과 열

    do {
        // 상대 좌표
        relative_row = target_row - start_row;
        relative_column = target_column - start_column;

        // z모양의 큰덩이로 나눠서 봤을때 0,1,2,3 중 어디인지 알아내기 위한 작업
        // 이작업뒤에 relative_row + 2 * relative_column은 0,1,2,3 으로 나온다
        if (relative_row < square[n-1]) {
            relative_row = 0; // 상대좌표로 봤을때 왼쪽일때
        }
        else {
            relative_row = 1; // 상대좌표로 봤을때 오른쪽일때
        }
        if (relative_column < square[n-1]) {
            relative_column = 0; // 상대좌표로 봤을때 위쪽일때
        }
        else {
            relative_column = 1; // 상대좌표로 봤을때 아래쪽일때
        }

        // 4등분 했을때 값들
        start_val += (relative_row + 2 * relative_column) * square[(n-1)*2]; // square[(n-1)*2] == ((2**n)/2)**n 
        start_row += relative_row * square[n-1];
        start_column += relative_column * square[n-1];
    } while(--n > 0);

    return start_val;

}

int main() {
    int n, r, c;

    scanf(" %d %d %d", &n, &c, &r);

    printf("%d", dnc(n, 0, 0, 0, r, c));

    return 0;
}