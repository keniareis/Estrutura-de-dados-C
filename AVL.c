#include <stdio.h>
#include <stdlib.h>

typedef struct SArvore{
    int info;
    struct SArvore *esq, *dir;
    int altura;
} TArvore;

TArvore* novoNo(int x){
    TArvore *novo = malloc(sizeof(TArvore));

    if (novo)
    {
        novo->info = x;
        novo->esq = NULL;
        novo->dir = NULL;
        novo->altura = 0;
    }else
        printf("\nErro ao alocar no novo");
    return novo;
    
}

int maior(int a, int b){
    return (a > b) ? a : b;
}

int alturaNo(TArvore *no){
    if (no == NULL)
        return -1;
    else
        return no->altura;
}

int calculoBalanceamento(TArvore *no){
    if (no)
        return(alturaNo(no->esq) - alturaNo(no->dir));
    else
        return 0;
    
}

TArvore * rotEsq(TArvore *pai){
    TArvore *a, *b;

    a = pai->dir;
    b = a->esq;

    a->esq = pai;
    pai->dir = b;

    pai->altura = maior(alturaNo(pai->esq), alturaNo(pai->dir)) + 1;
    a->altura = maior(alturaNo(a->esq), alturaNo(a->dir)) + 1;
    return a;
}


TArvore * rotDir(TArvore *pai){
    TArvore *a, *b;

    a = pai->esq;
    b = a->dir;

    a->dir = pai;
    pai->esq = b;

    pai->altura = maior(alturaNo(pai->esq), alturaNo(pai->dir)) + 1;
    a->altura = maior(alturaNo(a->esq), alturaNo(a->dir)) + 1;
    return a;
}

TArvore* rotDirEsq(TArvore *pai){
    pai->dir = rotDir(pai->dir);
    return rotEsq(pai);
}

TArvore* rotEsqDir(TArvore *pai){
    pai->esq = rotEsq(pai->esq);
    return rotDir(pai);
}

TArvore* balancear(TArvore *pai){
    int fatorPai = calculoBalanceamento(pai);

    if (fatorPai < -1 && calculoBalanceamento(pai->dir) <= 0){
        pai = rotEsq(pai);
    }else if (fatorPai > 1 && calculoBalanceamento(pai->esq) >= 0){
        pai = rotDir(pai);
    }else if (fatorPai > 1 && calculoBalanceamento(pai->esq) < 0){
        pai = rotEsqDir(pai);
    }else if (fatorPai < -1 && calculoBalanceamento(pai->dir) > 0){
        pai = rotDirEsq(pai);
    }

    return pai;
    
}


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

TArvore* preencherArvore(TArvore * pai, int x){
    if (pai == NULL)
        return novoNo(x);
    else{
        if (x < pai->info){
            pai->esq = preencherArvore(pai->esq, x);
        }else if (x > pai->info){
            pai->dir = preencherArvore(pai->dir, x);
        }else{
            printf("\n o no %d ja existe!", x);
        }
    }
    
    pai->altura = maior(alturaNo(pai->esq), alturaNo(pai->dir)) + 1;

    pai = balancear(pai);

    return pai;
}

TArvore* remover(TArvore *pai, int key){
    if (pai == NULL){
        printf("Valor nao encontrado\n");
        return NULL;
    }else{
        if (pai->info == key)
        {
            if (pai->esq == NULL && pai->dir == NULL){
                free(pai);
                printf("folha %d removida!\n", key);
                return NULL;
            }else{
                if (pai->esq != NULL && pai->dir != NULL){
                    TArvore *temp = pai->esq;

                    while (temp->dir != NULL){
                        temp = temp->dir;
                    }
                    
                    pai->info = temp->info;
                    temp->info = key;
                    printf("trocou %d\n", key);
                    pai->esq = remover(pai->esq, key);
                    return pai;
                }else{
                    TArvore *temp;
                    if (pai->esq != NULL){
                        temp = pai->esq;
                    }else{
                        temp = pai->dir;
                    }
                    free(pai);
                    printf("no com um filho removido %d\n", key);
                    return temp;
                }
            }
        }else{
            if (key < pai->info){
                pai->esq = remover(pai->esq, key);
            }else
                pai->dir = remover(pai->dir, key);
        }

        pai->altura = maior(alturaNo(pai->esq), alturaNo(pai->dir)) + 1;

        pai = balancear(pai);

        return pai;
        
    }
    
    
}

void imprimir(TArvore *pai, int nivel){
    if (pai){
        imprimir(pai->dir, nivel + 1);
        printf("\n\n");

        for (int i = 0; i < nivel; i++){
            printf("\t");
        }
        
        printf("%d", pai->info);
        imprimir(pai->esq, nivel + 1);
    }
    
}

int main() {

    TArvore * raiz = malloc(sizeof(TArvore));
    int opcao, valor;

    do
    {
        printf("\n\n\t0 - Sair\n\t1 - Inserir\n\t2 - Remover\n\t3 - Imprimir\n\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 0:
            printf("Finalizado");
            break;
        case 1:
            printf("\tDigite o valor para ser inserido: ");
            scanf("%d", &valor);
            raiz = preencherArvore(raiz, valor);
            break;
        case 2:
            printf("\tDigite o valor para ser removido: ");
            scanf("%d", &valor);
            raiz = remover(raiz, valor);
            break;
        case 3:
            //A arvore esta sendo imprimida na horizontal
            imprimir(raiz, 1);
            break;

        default:
            printf("\nOpcao invalida\n");
        }

    } while (opcao != 0);
    

    return 0;
}
