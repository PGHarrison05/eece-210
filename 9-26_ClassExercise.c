#include <stdio.h>

void print_big(int number);

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d",&num);


    print_big(num);

    return 0;
}

void print_big(int number) {
 if (number > 10) {
    printf ("%d is big\n", number);
    }
 }
