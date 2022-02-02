#include <stdio.h>
#include <stdlib.h>

int main(){
    int a[5] = {0,0,0,0,0};
    int l = sizeof(a) / sizeof(int);
    printf("%lu", sizeof(a));
    putchar('?');
}