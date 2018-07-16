#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *str_replace(char *orig, char *rep, char *with){
    char *result;
    char *ins;
    char *tmp;
    int len_rep;
    int len_with;
    int len_front;
    int count;

    if (!orig || !rep)
        return NULL;

    len_rep = strlen(rep);

    if (len_rep == 0)
        return NULL;
    if (!with)
        with = "";

    len_with = strlen(with);

    ins = orig;
    for (count = 0; tmp = strcasestr(ins, rep); ++count)
        ins = tmp + len_rep;

    tmp = result = malloc(strlen(orig) + (len_with - len_rep) * count + 1);

    if (!result)
        return NULL;

    while (count--){
        ins = strcasestr(orig, rep);
        len_front = ins - orig;
        tmp = strncpy(tmp, orig, len_front) + len_front;
        tmp = strcpy(tmp, with) + len_with;
        orig += len_front + len_rep;
    }
    strcpy(tmp, orig);
    return result;
}

//Força bruta
int contaTag(char *T, char *P, int n, int m){
    int i, j, k, count = 0;
    for (i = 1; i <= (n - m + 1); i++){
        k = i;
        j = 1;
        while (T[k - 1] == P[j - 1] && j <= m){
            j++;
            k++;
        }
        if (j > m)
            count++;
    }
    return count;
}

int main(){
    char *tag = calloc(11, sizeof(char *));
    char *text = calloc(51, sizeof(char *));
    char *subs_tag = calloc(5, sizeof(char *));

    int len_tag, len_text, qtd_tag_in_text;
    int rc, i, x, k, j;
    int len_new_text;

    while ((rc = scanf("%s\n %s\n %[^\n]", tag, subs_tag, text)) != EOF){
        i = x = 0;
        len_tag = strlen(tag);
        len_text = strlen(text);
        qtd_tag_in_text = contaTag(text, tag, len_text, len_tag);
        len_new_text = 10000;

        char *new_text = calloc(len_new_text, sizeof(char *));
        char *aux = calloc(len_text, sizeof(char *));

        int valid = 0;
        x = 0;
            for (i = 0; i < strlen(text); i++){
                if (valid || text[i] == '<'){
                    valid = 1;
                    char ch[2] = {'\0'};
                    ch[0] = text[i];
                    strcat(aux, ch);
                    if (valid && text[i] == '>'){
                        valid = 0;
                        strcat(new_text,
                               str_replace(aux, tag, subs_tag));
                        for (j = 0; j < strlen(aux); j++){
                            aux[j] = '\0';
                        }
                    }
                }
                else{
                    char ch[2] = {'\0'};
                    ch[0] = text[i];
                    strcat(new_text, ch);
                }
            }
            printf("%s\n", new_text);

            for (j = 0; j < strlen(new_text); j++){
                new_text[j] = '\0';
            }
    }
    return 0;
}