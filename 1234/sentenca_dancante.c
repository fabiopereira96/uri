#include <stdio.h>
#include <string.h>
 
#define ASCII_INVERTE 32 

int main() {
    int i, flag;
    char c[50];
    int rc;
    while ((rc = scanf("%[^\n]", c)) != EOF) {
        flag = 1;
        scanf("%*c");
        if(rc == 1){
            for (i = 0; i < strlen(c); i++){
                if (flag == -1 && (c[i] > 64 && c[i] < 91))
                    c[i] += ASCII_INVERTE;
                else if (flag == 1 && (c[i] > 96 && c[i] < 123))
                    c[i] -= ASCII_INVERTE;
                if (c[i] != 32)
                    flag *= -1;
            }
            printf("%s", c);
            printf("\n");
        }
    }
    return 0;
}