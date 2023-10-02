#include <stdio.h>

#define TAM 5

int fila[TAM]; //Implementa que a fila tem no maximo 5 elementos
int inicio = 0;//indica o indice do primeiro elemento da fila
int fim = 0;// indica o indice do ultimo elemento da fila

void enqueue(int valor) {
  if (fim == (inicio + TAM - 1) % TAM) {
    printf("Fila cheia. Deseja retirar um valor para adicionar outro? ([1] SIM, [0] NAO): ");
    int resposta;
    scanf("%d", &resposta);

    if (resposta == 1) {
      int valor_removido = denqueue();
      printf("Valor removido: %d\n", valor_removido);
    } else {
      return;
    }
  }

  fila[fim] = valor;
  fim = (fim + 1) % TAM;
}

int denqueue() {
  if (inicio == fim) {
    printf("Fila vazia.\n");
    return -1;
  }

  int valor = fila[inicio];
  inicio = (inicio + 1) % TAM;
  return valor;
}

void mostrar_fila() {
  if (inicio == fim) {
    printf("Fila vazia.\n");
    return;
  }

  printf("Fila: ");
  for (int i = inicio; i != fim; i = (i + 1) % TAM) {
    if (fila[i] == 0) {
      printf("0 ");
    } else {
      printf("%d ", fila[i]);
    }
  }
  printf("\n");
}

int main() {
  mostrar_fila();

  while (1) {
    int opcao;
    printf("O que deseja fazer? ([1] ADICIONAR, [2] REMOVER, [0] SAIR): ");
    scanf("%d", &opcao);

    if (opcao == 1) {
      int valor;
      printf("Digite um valor para adicionar à fila: ");
      scanf("%d", &valor);
      enqueue(valor);
    } else if (opcao == 2) {
      int valor = denqueue();
      printf("Valor desenfileirado: %d\n", valor);
    } else {
      break;
    }

    mostrar_fila();
  }

  return 0;
}