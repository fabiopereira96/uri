#include <stdio.h>
#include <string.h>

#define NUMBER_RENAS  9

int main (){
    char renas[NUMBER_RENAS][20] = {"Dasher",
                                    "Dancer",
                                    "Prancer",
                                    "Vixen",
                                    "Comet",
                                    "Cupid",
                                    "Donner",
                                    "Blitzen",
                                    "Rudolph"};
    int i, total = 0, bolas;
    for (i = 0; i < NUMBER_RENAS; i++){
        scanf("%d", &bolas);
        total += bolas;
    }
    int rena;
    rena = total % NUMBER_RENAS;
    if(rena == 0){
        rena = NUMBER_RENAS;
    }
    printf("%s\n", renas[rena-1]);
    return 0;
}