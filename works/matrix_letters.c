#include <stdio.h>

//   *
//  ***
// *****
//*******
// *****
//  ***
//   *
int main() {
    int n = 7;
    int mid = n / 2;
    for (int i = 0; i < n; ++i) {
        int len = i < mid ? i + 1 : n - i;
        for (int j = 0; j < mid - len + 1; ++j) {
            printf(" ");
        }
        for (int j = 0; j < len * 2 - 1; ++j) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
