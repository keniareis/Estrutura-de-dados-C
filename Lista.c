#include <stdio.h>
#include <stdlib.h>

#define TAM 5

int lista[TAM], inicio = 0, fim = 0;

void adicionar(int valor){
    int resposta, valor_removido, escolha;

    if(fim  == (inicio + (TAM -1) % TAM)) {
        printf("Lista cheia!\nDeseja remover um valor? [1]SIM  [2]NAO");
        scanf("%d", &resposta);
        
        if(resposta == 1){
            mostrar_lista();
    
            printf("Qual valor voce quer remover? ");
            scanf("%d", &escolha);
    
            valor_removido = remover(escolha);
            printf("O valor %d foi removido!", valor_removido);
    
        }else{
            return;
        }
    }

    lista[TAM] = valor;

}
void remover(){

}

int mostrar_lista(){

}

int main(){
    mostrar_lista();
   
    while(1){

        int opcao, valor;
        printf("== LISTA ==\n[1]Adicionar\n[2]Remover\n[0]Sair");
        scanf("%d", &opcao);

        if (opcao == 1){
            
            printf("Digite um valor para adicionar: ");
            scanf("%d", &valor);
        
            adicionar(valor);

        }else if (opcao == 2)
        {
            mostrar_lista();
        
            printf("Digite um valor para remover: ");
            scanf("%d", &valor);
        
            remover(valor);
            printf("Valor removido!");

        }else{
            break;
        }
        
        
    }
        
    }
    