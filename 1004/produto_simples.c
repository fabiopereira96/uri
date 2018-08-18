#include <stdio.h>

int prod(int a, int b){
    return a * b;
}

int main(int argc, char *argv[]){
    int a, b, PROD;
    scanf("%d", &a);
    scanf("%d", &b);
    PROD = prod(a,b);
    printf("PROD = %d\n", PROD);
    return 0;
}