#include <stdio.h>
#include <stdlib.h>

typedef struct SArvore{
    int info;
    struct SArvore * esq;
    struct SArvore * dir;
} TArvore;


void preOrdem(TArvore * no){
    if (no == NULL)
        return;
    printf("%d ",no->info);
    preOrdem(no->esq);
    preOrdem(no->dir);
}

void ordem(TArvore * no){
    if (no == NULL)
        return;
    ordem(no->esq);
    printf("%d ",no->info);
    ordem(no->dir);
}

void posOrdem(TArvore * no){
    if (no == NULL)
        return;
    posOrdem(no->esq);
    posOrdem(no->dir);
    printf("%d ",no->info);
}

void preencherArvore(TArvore * no){
    if (no == NULL)
        return;

    int cont = 1;
    int leitura;
    TArvore * novo;

    while (cont <= 2){
        printf("Informe o valor do filho do nó %d: ", no->info);
        scanf("%d",&leitura);
        if (leitura == 0){
            cont++;
            continue;
        }

        novo = malloc(sizeof(TArvore));
        novo->info = leitura;
        novo->esq = novo->dir = NULL;
        
        if (cont == 1)
            no->esq = novo;
        else
            no->dir = novo; 

        cont++;    
    }

    preencherArvore(no->esq);
    preencherArvore(no->dir);
}

TArvore* remover(TArvore * raiz, int key){
    if(raiz == NULL){
        return raiz;
    }     

    if (key < raiz->info){
        raiz->esq = remover(raiz->esq, key);
    }
    else if (key > raiz->info){
        raiz->dir = remover(raiz->dir, key);
    }
    else{
        if (raiz->esq == NULL){
            TArvore* temp = raiz->dir;
            free(raiz);
            return temp;
        }else if (raiz->dir == NULL){
            TArvore* temp = raiz->esq;
            free(raiz);
            return temp;
        }

        TArvore* temp = raiz->dir;
        TArvore* pai = raiz;
        while (temp->esq != NULL){
            pai = temp;
            temp = temp->esq;
        }
        
        raiz->info = temp->info;

        if (pai != raiz)
            pai->esq = remover(pai->esq, temp->info);
        else
            pai->dir = remover(pai->dir, temp->info);
    }
    return raiz;
}

        
int main(int argc, char** argv) {

    TArvore * raiz = malloc(sizeof(TArvore));
    printf("Informe o valor da raiz: ");
    scanf("%d",&raiz->info);

    preencherArvore(raiz);
    ordem(raiz);

    printf("Qual voce quer remover? ");
    int key;
    scanf("%d", &key);
    remover(raiz, key);
    ordem(raiz);

/*
    TArvore * no = malloc(sizeof(TArvore));
    no->info = 2;
    raiz->esq = no;
    no = malloc(sizeof(TArvore));
    no->info = 10;
    raiz->dir = no;

    no = malloc(sizeof(TArvore));
    no->info = 3;
    raiz->esq->dir = no;

    no = malloc(sizeof(TArvore));
    no->info = 6;
    raiz->dir->esq = no;

    no = malloc(sizeof(TArvore));
    no->info = 4;
    raiz->esq->dir->dir = no;

    no = malloc(sizeof(TArvore));
    no->info = 8;
    raiz->dir->esq->dir = no;

    no = malloc(sizeof(TArvore));
    no->info = 9;
    raiz->dir->esq->dir->dir = no;
*/



;

    return (EXIT_SUCCESS);
}
