#include <stdio.h>
#include <stdlib.h>

#define TAM 6 //define o tamanho da lista

int lista[TAM], cont = 1; //declara a lista e a variável do contador

void adicionar(int valor, int posicao){//declara a funcao adicionar que tem as variaveis 'valor' e 'posição' como parametros

    if (posicao < 1 || posicao > 7){//verifica se a posição informada é valida
        printf("\nPosicao invalida!\n");
    
    }else if(cont == TAM){
        printf("\nA lista esta cheia!\n");
    }
    else{
    
        while (lista[posicao] != 0){
            
            posicao = (posicao + 1) % TAM;
        }
        lista[posicao] = valor;
        printf("Valor adicionado na posicao %d\n", posicao);
        cont++;
    }
}

int remover(int posicao){
    for (int i = 1; i < TAM; i++)
    {
        if (lista[i] == lista[posicao]){
            lista[i] = 0;
            return;
        }
    }
}


int mostrar_lista(){
    int vazio = 0;
    for (int i = 1; i < TAM; i++){
        if (lista[i] == 0) {
            printf("0 ");
            vazio++;
        }
        else{
            printf("%d ", lista[i]);
        }
    }
    
    if (vazio == 5){
        printf("\nLista vazia!\n");
    }
    
    printf("\n");
}

int main(){
   
    while(1){

        mostrar_lista();
        int opcao, valor, posicao;
        printf("== LISTA ==\n[1]Adicionar\n[2]Remover\n[0]Sair\n");
        scanf("%d", &opcao);

        if (opcao == 1){
            
            printf("Digite um valor para adicionar: ");
            scanf("%d", &valor);

            printf("Digite a posicao: ");
            scanf("%d", &posicao);

            adicionar(valor, posicao);

        }else if (opcao == 2)
        {
            mostrar_lista();
        
            printf("Qual a posicao que o valor esta? ");
            scanf("%d", &posicao);
        
            remover(posicao);
            printf("\nValor removido!\n");

        }else{
            break;
        }
    }
}