#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct SArvore{
    int info;
    struct SArvore * filho;
    struct SArvore * irmao;
} TArvore;

void preencherArvoreConvencional(TArvore * no){
    if (no == NULL)
        return;

    TArvore * novo;
    TArvore * brother;
    int leitura;

    while (TRUE) {
        printf("Informe o valor do filho de %d: ",no->info);
        scanf("%d",&leitura);
        if (leitura  == 0)
            break;

        novo = malloc(sizeof(TArvore));
        novo->info = leitura;
        novo->filho = novo->irmao = NULL;

        if (no->filho == NULL){
            no->filho = novo;
        }else{
            brother->irmao = novo;
        }

        brother = novo;
    }

    preencherArvoreConvencional(no->filho);
    preencherArvoreConvencional(no->irmao);
}

void profundidade(TArvore * no){
    if (no == NULL)
        return;
    
    printf("%d ",no->info);
    profundidade(no->filho);
    profundidade(no->irmao);
}

void largura(TArvore * no){
    if (no == NULL)
        return;
    
    printf("%d ",no->info);
    largura(no->irmao);
    largura(no->filho);
}

TArvore* removerNo(TArvore *no, int valor) {
    if (no == NULL)
        return NULL;

    if (no->info == valor) {
        if (no->filho != NULL) {
            TArvore *temp = no->filho;
            while (temp->irmao != NULL) {
                temp = temp->irmao;
            }
            temp->irmao = no->irmao;
            TArvore *returnNode = no->filho;
            free(no);
            return returnNode;
        } else {
            TArvore *returnNode = no->irmao;
            free(no);
            return returnNode;
        }
    } else {
        no->filho = removerNo(no->filho, valor);
        no->irmao = removerNo(no->irmao, valor);
    }
    return no;
}


int main() {

    TArvore * raiz = malloc(sizeof(TArvore));
    printf("Informe o valor da raiz: ");
    scanf("%d", &raiz->info);
    raiz->filho = raiz->irmao = NULL;

    preencherArvoreConvencional(raiz);
    profundidade(raiz);

    int valorRemover;
    printf("\nInforme o valor do no a ser removido: ");
    scanf("%d", &valorRemover);
    raiz = removerNo(raiz, valorRemover);


    profundidade(raiz); 

   
    return (EXIT_SUCCESS);
}
