#include <stdio.h>
#include <math.h>
#define pi 3.14159

double area (double r){
    return pow(r,2)*pi;
}

int main (){
    double r;
    scanf("%lf", &r);
    printf("A=%.4lf\n", area(r));
    return 0;
}