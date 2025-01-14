#include <stdio.h>

int main() {
    int a[11][11];


    for (int i = 0; i <= 10; i++) {
        for (int j = 0; j <= 10; j++) {
            a[i][j] = i * j;
        }
    }


    printf("Multiplication Table from 0 to 10:\n");
    for (int i = 0; i <= 10; i++) {
        for (int j = 0; j <= 10; j++) {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
