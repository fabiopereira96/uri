#include <stdio.h>

int compareValues(int a, int b, int c){
        if (a > b && b <= c)  return 1;
        if (a < b && b >= c)  return 1;
        if (a == b && b != c) return 1;
        return 0;
}

int simileValues(int *samples, int n){
    int i, count = 0, first, second, prev, current;
    first = samples[0];
    second  = samples[1];
    prev = first;
    current = second;
    for (i = 0; i < n; i++) {
        if (i > 1) {
            count += compareValues(prev, current, samples[i]);
        }
        prev = current;
        current = samples[i];
    }

    count += compareValues(prev, current, first);
    count += compareValues(samples[n-1], first, second);
    return count;
}

int main (){
    int n, i;
    scanf("%d", &n);
    while(n && n>1){
        int samples[n];
        for(i = 0; i<n; i++)
            scanf("%d", &samples[i]);
        printf("%d\n", simileValues(samples, n));
        scanf("%d", &n);
    }
    return 0;   
}