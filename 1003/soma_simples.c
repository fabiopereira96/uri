#include <stdio.h>

int soma(int a, int b){
    return a + b;
}

int main(int argc, char *argv[]){
    int a, b, SOMA;
    scanf("%d", &a);
    scanf("%d", &b);
    SOMA = soma(a,b);
    printf("SOMA = %d\n", SOMA);
    return 0;
}