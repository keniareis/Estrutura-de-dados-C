#include <stdio.h>
#include <stdlib.h>

typedef struct SStack{
    int info;
    struct SStack * next;
}TStack;

typedef struct {
    TStack * top;
    int quantidade;
}TDescritor;

TDescritor descritor;

void push(int dado){
    TStack * novo = malloc(sizeof(TStack));
    novo->info = dado;
    if (descritor.top == NULL){
        novo->next = novo;
    } else{
        novo->next = descritor.top->next; 
        descritor.top->next = novo;
    }
    descritor.top = novo;
}

void listar(){
    TStack * temp = descritor.top;
    printf("\n\nListando\n\n");
    if (temp != NULL){
        do {
            temp = temp->next;
            printf("%d ", temp->info);
        } while (temp != descritor.top);
    }
}

TStack * buscar(int key){
    TStack * temp = descritor.top;
    if (temp != NULL){
        do {
            temp = temp->next;
            if (temp->info == key)
                return temp;
        } while (temp != descritor.top);
    }
    return NULL;
}

void pop(){
    if (descritor.top != NULL){
        TStack * destroyer = descritor.top->next;
        if (destroyer == descritor.top){
            descritor.top = NULL;
        } else {
            descritor.top->next = destroyer->next;
        }
        free(destroyer);
    }
}

int main(int argc, char** argv) {
    int leitura;
    while (1){
        printf("Informe o valor: ");
        scanf("%d",&leitura);
        if (leitura == 0)
            break;
        push(leitura);
    }

    listar();
    pop();
    pop();
    listar();

    int chave;
    printf("\n\nInforme o valor da chave: ");
    scanf("%d",&chave);
    TStack * posicao = buscar(chave);
    if (posicao != NULL)
        printf("Chave encontrada na posição %p", posicao);
    else{
        printf("Chave não encontrada na pilha");
    }
  
    return (EXIT_SUCCESS);
}
