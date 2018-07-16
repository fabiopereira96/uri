#include <stdio.h>
 
typedef struct Aluno {
    int posicao;
    int nota;
} Aluno;

void ordenaFila(Aluno *alunos, int n){
    int i, k;
    for (k = n/2; k > 0; k /= 2){
        for (i = k; i < n; i += 1) {
            Aluno temp = alunos[i];
            int j;            
            for (j = i; j >= k && alunos[j - k].nota < temp.nota; j -= k)
                alunos[j] = alunos[j - k];
            alunos[j] = temp;
        }
    }
}

int posicoesMantidas(Aluno alunos[], int m){
    int i, c = 0;
    ordenaFila(alunos, m);
    for(i=0; i<m; i++) 
        if(alunos[i].posicao == i) c++;
    return c;
}

int main() {
    int i, n, m, p, k;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &m);
        Aluno alunos[m];
        for(k=0; k<m; k++){
            scanf("%d", &alunos[k].nota);
            //Salva posição para não perder a referência ao aluno após ordernar
            alunos[k].posicao = k;
        }
        printf("%d\n", posicoesMantidas(alunos, m));
    }
    return 0;
}