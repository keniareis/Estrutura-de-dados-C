#include <stdio.h>

#define TAM 5

int fila[TAM]; //Implementa que a fila como vetor e tem no maximo 5 elementos
int inicio = 0;//indica o indice do primeiro elemento da fila
int fim = 0;// indica o indice do ultimo elemento da fila

void enqueue(int valor) {// a função adiciona um elemento a fila 
  //o if verifica se a fila está cheia 
  if (fim == (inicio + TAM - 1) % TAM) {
    //se estiver cheia ela pergunta se ele deseja retirar um valor da fila
    printf("Fila cheia. Deseja retirar um valor para adicionar outro? ([1] SIM, [0] NAO): ");
    int resposta;
    scanf("%d", &resposta);
    // se houver confirmação a função if é ativada 
    if (resposta == 1) {
      int valor_removido = denqueue();//chama a função denqueue para remover o valor da fila
      printf("Valor removido: %d\n", valor_removido);//exibe o valor removido na tela
    } else {
      return;// retorna a funcao enqueue
    }
  }

  fila[fim] = valor;  // adiciona o valor passado como parametro ao vetor fila  na posição fim
  fim = (fim + 1) % TAM;//incrementa o valor de fim de acordo com o tamanho da fila
}

int denqueue() {// declara a função dequeue que remove um elemento da fila
  if (inicio == fim) {//verifica se a fila esta vazia
    printf("Fila vazia.\n");
    return -1;// se sim retorna o valor -1
  }

  int valor = fila[inicio];//remove o primeiro elemento da fila e armazena na variavel 'valor'
  inicio = (inicio + 1) % TAM;//incrementa o valor de inicio de acordo com o tamamho da fila
  return valor; //retorna o valor removido da fila
}

void mostrar_fila() {//declara a função 'mostrar_fila' q exibe os elementos da fila na tela
  if (inicio == fim) {//verifica se a fila esta vazia 
    printf("Fila vazia.\n");//se sim exibe a mensagem na tela
    return;// retorna/sai da condição
  }

  printf("Fila: ");// imprime a mensagem 
  for (int i = inicio; i != fim; i = (i + 1) % TAM) {//inicia o for para percorrer a fila
    if (fila[i] == 0) {//verifica se o indice é igual a 0 
      printf("0 ");//se sim imprime o 0 
    } else {
      printf("%d ", fila[i]);//senao, imprime o valor do elemento na tela  
    }
  }
  printf("\n");
}

int main() {//função principal
  mostrar_fila();// chama a função 'mostrar_fila' para mostrar a fila vazia

  while (1) {// inicia o loop q só irá parar quando o usuario escolher 0
    int opcao;//declara a variável 
    printf("O que deseja fazer? ([1] ADICIONAR, [2] REMOVER, [0] SAIR): ");//mostra as escolhas que o usuario pode fazer
    scanf("%d", &opcao);// lê a opção escolhida pelo usuário

    if (opcao == 1) {// verifica se a opcao escolhida pelo usuario é 1
      int valor;//essa varialvel armazana o valor adicionado a fila
      printf("Digite um valor para adicionar à fila: ");
      scanf("%d", &valor);//ler o valor q o usuário escolheu
      enqueue(valor);//chama a função enqueue para adicionar o valor a fila
    } else if (opcao == 2) {//verifica se a opção é igual a 2
      int valor = denqueue();// se sim, chama a função denqueue para remover um valor da fila
      printf("Valor desenfileirado: %d\n", valor);//mostra o valor que foi retirado
    } else {//se a opção for diferente de 1 ou 2 ele encerra o loop
      break;
    }

    mostrar_fila();//chama a função fila e a mostra atualizada
  }

  return 0;
}