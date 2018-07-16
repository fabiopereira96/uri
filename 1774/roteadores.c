#include <stdio.h>
#include <stdlib.h>

typedef int TipoChaveVertice;
typedef int TipoChaveAresta;

typedef struct TipoAresta{
    int origem,
        destino,
        preco;
} Aresta;

typedef struct TipoGrafo{
    TipoChaveVertice v;
    TipoChaveAresta a;
    Aresta *arestas;
} Grafo;

typedef struct sconjunto{
    int parent;
    int rank;
}Conjunto;

Grafo *criaGrafo(TipoChaveVertice, TipoChaveAresta);
int find(Conjunto [], int);
void Union(Conjunto [], int, int);
int comp(const void*, const void*);
void KruskalMST(Grafo*);

int main(){
    int i, v, w, p;
    TipoChaveAresta c;
    TipoChaveVertice r;
    scanf("%d %d", &r, &c);
    Grafo *g = criaGrafo(r, c);

    for (i = 0; i < c; i++){
        scanf("%d %d %d", &v, &w, &p);
        g->arestas[i].origem = v - 1;
        g->arestas[i].destino = w - 1;
        g->arestas[i].preco = p;
    }

    KruskalMST(g);
    return 0;
}

Grafo *criaGrafo(TipoChaveVertice v, TipoChaveAresta a){
    Grafo *g = (Grafo *)calloc(1, sizeof(Grafo));
    g->v = v;
    g->a = a;

    g->arestas = (Aresta *)calloc(g->a, sizeof(Aresta));

    return g;
}

int find(Conjunto sconjuntos[], int i){

    if (sconjuntos[i].parent != i)
        sconjuntos[i].parent = find(sconjuntos, sconjuntos[i].parent);

    return sconjuntos[i].parent;
}

void Union(Conjunto sconjuntos[], int x, int y){
    int xroot = find(sconjuntos, x);
    int yroot = find(sconjuntos, y);

    if (sconjuntos[xroot].rank < sconjuntos[yroot].rank){
        sconjuntos[xroot].parent = yroot;
    } else if (sconjuntos[xroot].rank > sconjuntos[yroot].rank){
        sconjuntos[yroot].parent = xroot;
    } else {
        sconjuntos[yroot].parent = xroot;
        sconjuntos[xroot].rank++;
    }
}

//Comparação pro qsort
int comp(const void *a, const void *b){
    Aresta *a1 = (Aresta *)a;
    Aresta *b1 = (Aresta *)b;
    return a1->preco > b1->preco;
}

void KruskalMST(Grafo *g){
    int v = g->v;
    Aresta result[v];
    int a = 0;
    int i = 0;

    qsort(g->arestas, g->a, sizeof(g->arestas[0]), comp);

    struct sconjunto *sconjuntos =
        (struct sconjunto *)calloc(v, sizeof(struct sconjunto));

    int k;
    for (k = 0; k < v; ++k){
        sconjuntos[k].parent = k;
        sconjuntos[k].rank = 0;
    }

    while (a < v - 1){

        Aresta prox_aresta = g->arestas[i++];

        int x = find(sconjuntos, prox_aresta.origem);
        int y = find(sconjuntos, prox_aresta.destino);

        if (x != y){
            result[a++] = prox_aresta;
            Union(sconjuntos, x, y);
        }
    }

    int sum = 0;
    for (i = 0; i < a; ++i){
        sum += result[i].preco;
    }
    printf("%d\n", sum);
    return;
}
