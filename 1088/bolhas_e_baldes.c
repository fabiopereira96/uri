#include <stdio.h>
#include <stdlib.h>

int main (){
    int n;
    scanf("%d", &n);
    while(n != 0){
        int i, j, c = 0;
        int vet[n+1];
        for(i=1; i<=n; i++)
            scanf(" %d", &vet[i]);
        i = 1;
        while(i<=n){
            j = vet[i];
            if (j != i){
                c += 2 * (j - i) - 1;
                vet[i] = vet[j];
                vet[j] = j;
            } else i++;
        }
        if(c%2 == 0) printf("Carlos\n");
        else printf("Marcelo\n");
        scanf("\n%d", &n);
    }
    return 0;
}