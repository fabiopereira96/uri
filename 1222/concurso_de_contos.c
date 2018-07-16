#include <stdio.h>
#include <string.h>

int main() {
    int n, l, c, i;
    while (scanf("%d", &n) == 1 && scanf("%d", &l) == 1 && scanf("%d\n", &c) == 1) {
        char words[n][c];
        int strLength = 0, line = 0, pages = 0;
        for (i = 0; i < n; i++) {
            scanf("%s", words[i]);
            if (strLength + strlen(words[i]) > c) {
                strLength = strlen(words[i]) + 1;
                line++;  
            } else if(strLength + strlen(words[i]) == c) {
                strLength = 0;
                line++;
            } else {
                strLength += strlen(words[i]) + 1;
            }
            if (line == l) {
                line = 0;
                pages++;
            }
        }
        if(strLength > 0 || line > 0) pages++;
        printf("%d\n", pages);
    }
    return 0;
}