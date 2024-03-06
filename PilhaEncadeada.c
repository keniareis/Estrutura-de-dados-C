    #include <stdio.h>
    #include <stdlib.h>

    typedef struct SPilha{
        int info;
        struct SPilha * next;
    }TPilha;

    //sentinela
    TPilha * pilha = NULL;

    void enqueue(int dado){
        TPilha * ultimo;
        TPilha * novo = malloc(sizeof(TPilha));
        
        novo->info = dado; //atribui o dado ao novo nó
        novo->next = NULL; //o proximo nó do novo nó é NULL
        
        if (pilha == NULL){
            pilha = novo;

        }else{
            ultimo = pilha;
            while (ultimo->next != NULL){
                ultimo = ultimo->next;
            }
            ultimo->next = novo;
        }
    }

    void listar(){
        TPilha * ultimo = pilha;
        printf("\n\nListando:\n");

        while (ultimo != NULL){
            printf("%d ", ultimo->info);
            ultimo = ultimo->next;
        }
    }

    TPilha * buscar(int key){
        TPilha * ultimo = pilha;

        while (ultimo != NULL){
            if (ultimo->info == key){
                return ultimo;
            }
            ultimo = ultimo->next;
        }
        return NULL;
    }

    void dequeue(){
        if (pilha != NULL){ // Verifica se a pilha não está vazia
            TPilha * penultimo = NULL; // Cria um ponteiro para o penúltimo elemento e inicializa como NULL
            TPilha * ultimo = pilha; // Cria um ponteiro para o último elemento e inicializa como o primeiro elemento da pilha

            while (ultimo->next != NULL){ // Enquanto o próximo elemento existir
                penultimo = ultimo; // Atualiza o penúltimo elemento para ser o atual
                ultimo = ultimo->next; // Atualiza o último elemento para ser o próximo
            }

            if (penultimo != NULL){ // Se o penúltimo elemento existir (ou seja, a pilha tem mais de um elemento)
                penultimo->next = NULL; // Define o próximo elemento do penúltimo como NULL, removendo a referência ao último elemento
            } else { // Se o penúltimo elemento não existir (ou seja, a pilha tem apenas um elemento)
                pilha = NULL; // Define a pilha como NULL, indicando que está vazia
            }

            free(ultimo); // Libera a memória do último elemento
        }
    }


    int main(){

        int leitura; // Variável para a leitura do dado
        while (1){ // Loop infinito
            printf("Informe o valor: "); // Pede ao usuário para informar um valor
            scanf("%d",&leitura); // Lê o valor
            if (leitura == 0) // Se o valor for 0
                break; // Sai do loop
            enqueue(leitura); // Adiciona um novo nó à fila
        }

        listar(); // Lista todos os nós da fila
        dequeue(); // Remove o primeiro nó da fila
        dequeue(); // Remove o primeiro nó da fila
        listar(); // Lista todos os nós da fila

        int chave; // Variável para a chave
        printf("\n\nInforme o valor da chave: "); // Pede ao usuário para informar uma chave
        scanf("%d",&chave); // Lê a chave
        TPilha * posicao = buscar(chave); // Busca um nó com a chave
        if (posicao != NULL) // Se a chave foi encontrada
            printf("Chave encontrada na posição %p", posicao); // Imprime a posição do nó
        else // Se a chave não foi encontrada
            printf("Chave não encontrada na fila"); // Imprime uma mensagem

        return (EXIT_SUCCESS); // Retorna sucesso

        
    }