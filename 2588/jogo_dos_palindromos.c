#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){

    int ascii[255];
    int i;
    char c[1000];
    int rc, count;
    while ((rc = scanf("%[^\n]", c)) != EOF){
        count = -1;
        for (i = 0; i < 255; i++)
            ascii[i] = 0;
        scanf("%*c"); //desconsidera o \n
        if (rc == 1){
            for (i = 0; i < strlen(c); i++)
                ascii[c[i]]++;
        }
        for (i = 0; i < 255; i++){
            if(ascii[i] % 2 != 0)
                count++;
        }
        if(count == -1)
            count = 0;
        printf("%d\n", count);
    }
    return 0;
}