#include <stdio.h>
#include <stdlib.h>

#define TAM 6 //define o tamanho da lista

int lista[TAM], cont = 1; //declara a lista e a variável do contador

void adicionar(int valor, int posicao){//declara a funcao adicionar que tem as variaveis 'valor' e 'posição' como parametros

    if (posicao < 1 || posicao > 7){//verifica se a posição informada é valida
        printf("\nPosicao invalida!\n");
    
    }else if(cont == TAM){// verifica se a lista esta cheia
        printf("\nA lista esta cheia!\n");
    }
    else{
    
        while (lista[posicao] != 0){//verifica se a posicao esta ocupada
            posicao = (posicao + 1) % TAM;//se sim, a posição é incrementada ate achar uma posição vazia
        }
        lista[posicao] = valor;//o valor é inserido na posição vazia
        printf("\nValor adicionado na posicao %d\n", posicao);
        cont++;//o contador é incremetado para indicar que um novo elemento foi adicionado a lista
    }
}

int remover(int posicao){//declara a função responsável por remover os elementos da lista
    for (int i = 1; i < TAM; i++)//percorre a lista
    {
        if (lista[i] == lista[posicao]){//verifica se o indice da lista é o mesmo que o informado
            lista[i] = 0;//remove o elemento da lista
            return;//sai da função
        }
    }
}


int mostrar_lista(){//declara a funcao que exibi a lista na tela
    int vazio = 0;//declara o contador 
    for (int i = 1; i < TAM; i++){//percorre a lista
        if (lista[i] == 0) {//verifica se a posição esta vazia
            printf("0 ");
            vazio++;//incrementa 1 ao contador
        }
        else{
            printf("%d ", lista[i]);// se a posicao nao estiver vazia exibe o elemento encontrado
        }
    }
    
    if (vazio == 5){//verifica se o contador percorreu toda fila 
        printf("\nLista vazia!\n");//se sim, a fila esta vazia
    }
    
    printf("\n");
}

int main(){//declara a função principal que é a entrada do programa
   
    while(1){//inicia 

        mostrar_lista();// a função é chamada para exibir a lista na tela
        int opcao, valor, posicao;//declara as variaveis 
        printf("== LISTA ==\n[1]Adicionar\n[2]Remover\n[0]Sair\n");//mostra as opçoes para o usuario
        scanf("%d", &opcao);//le a opcao escolhida

        if (opcao == 1){//executa essa condição se a opcao escolhida for '1'
            
            printf("Digite um valor para adicionar: ");
            scanf("%d", &valor);

            printf("Digite a posicao: ");
            scanf("%d", &posicao);

            adicionar(valor, posicao);//chama a função adicionar

        }else if (opcao == 2)//executa essa condição se a opcao escolhida for '2'
        {
            mostrar_lista();//chama a função para exibir a lista
        
            printf("\nQual a posicao que o valor esta? ");
            scanf("%d", &posicao);
        
            remover(posicao);//chama a função para remover o elemento da posição escolhida
            printf("\nValor removido!\n");

        }else{
            break;//o loop continua ate o usuario escolher sair
        }
    }
}