#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_VERTICE 27
#define VERDE 0
#define AMARELO 1 
#define VERMELHO 2 

int cor[MAX_VERTICE];
int componente[MAX_VERTICE];
int g[MAX_VERTICE][MAX_VERTICE];

void iniciaFila(int []);
void insereFila(int [], int, int *, int);
int removeFila (int [], int *, int);
int filaVazia  (int [], int, int);
int compara(const void *, const void *);
void ordena(int []);
void BFS(int, int);

int main(){

    char v1, v2;
    int V, E, C, i, j, k, x, y;
    int cont = 0;

    scanf("%d", &C);

    for (k = 0; k < C; k++){
        scanf("%d %d", &V, &E);

        for (i = 0; i < V; i++)
            for (j = 0; j < V; j++)
                g[i][j] = 0;

        for (i = 0; i < E; i++){
            scanf(" %c", &v1);
            scanf(" %c", &v2);
            x = v1 - 'a';
            y = v2 - 'a';
            g[x][y] = g[y][x] = 1;
        }
        //Disponivel
        for (i = 0; i < V; i++)
            cor[i] = VERDE;

        cont = 0;
        printf("Case #%d:\n", k + 1);
        for (i = 0; i < V; i++){
            if (cor[i] == VERDE){
                cont++;

                BFS(i, V);
                ordena(componente);
                
                for (j = 0; j < V && componente[j] != -1; j++)
                    printf("%c,", componente[j] + 'a');

                printf("\n");
            }
        }
        printf("%d connected components\n\n", cont);
    }
}

void iniciaFila(int q[]){
    int i;
    for (i = 0; i < MAX_VERTICE; i++)
        q[i] = -1;
}

void insereFila(int fila[], int inicio, int *fim, int vertice){
    fila[++(*fim)] = vertice;
}

int removeFila(int fila[], int *inicio, int fim){
    int retorno = fila[*inicio];
    (*inicio)++;
    return retorno;
}

int filaVazia(int fila[], int inicio, int fim){
    if (fim < inicio)
        return 1;
    return 0;
}

int compara(const void *a, const void *b){
    return (*(int *)a - *(int *)b);
}

void ordena(int vetor[]){
    int i, j;
    int tamanho = 0;
    for (i = 0; i < MAX_VERTICE && vetor[i] != -1; i++)
        tamanho++;
    qsort(vetor, tamanho, sizeof(int), compara);
}

void BFS(int raiz, int V){
    int fila[MAX_VERTICE];
    int iniFila = 0,
        fimFila = -1;
    int iniComp = 0,
        fimComp = -1;
    int atual, i;

    cor[raiz] = AMARELO;

    iniciaFila(fila);
    iniciaFila(componente);

    insereFila(fila, iniFila, &fimFila, raiz);
    insereFila(componente, iniComp, &fimComp, raiz);

    while (!filaVazia(fila, iniFila, fimFila)){
        atual = removeFila(fila, &iniFila, fimFila);
        for (i = 0; i < V; i++){
            if (i != atual){
                if (g[atual][i] > 0){
                    if (cor[i] == VERDE){
                        cor[i] = AMARELO;
                        insereFila(fila, iniFila, &fimFila, i);
                        insereFila(componente, iniComp, &fimComp, i);
                    }
                }
            }
        }
        cor[atual] = VERMELHO;
    }
}