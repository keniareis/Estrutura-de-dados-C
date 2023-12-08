#include <stdio.h>
#include <stdlib.h>

#define TAM 5

int vetor[5] = {1,4,3,2,5};//define o vetor

//Particiona o vetor
int partition(int v[], int inicio, int fim){
    int pivo = v[inicio];//inicia o vetor no ultimo elemento da fila
    int maiores = fim + 1; // elementos maiores que o pivo
    int i,temp;//variaveis auxiliares

    //percorre o vetor fim ao inicio
    for (i = fim; i > inicio; i--){
        if (v[i] > pivo){//se o elemento atual é maior que o pivo 
            maiores--;//decrementa o indice dos elementos maiores
            
            //troca o elemento atual com o elemento no indice dos maiores
            temp = v[i];
            v[i] = v[maiores];
            v[maiores] = temp;
        }
    }
    //coloca o pivo na posição certa no vetor
    int meio = maiores - 1;//decrementar o maior valor
    temp = v[inicio];
    v[inicio] = v[meio];
    v[meio] = temp;
    return meio;//retorna a posição do pivo
}

//Função para ordenar
void quickSort(int v[], int inicio, int fim){
    if (inicio >= fim)//se o inicio é maior ou igual ao fim retorna 
        return;
    int meio = partition(v,inicio,fim);//particiona o vetor
    quickSort(v,inicio,meio - 1);//ordena a primeira parte
    quickSort(v,meio + 1,fim);//ordena
}

void listar(int v[], int tamanho){
    int i;
    printf("\n\nListando\n");
    for (i = 0; i < tamanho;i++){
        printf("%d ",v[i]);
    }
}

int main(int argc, char** argv) {
    
    listar(vetor,TAM);
    quickSort(vetor, 0,4);
    listar(vetor,TAM);
  
    return (EXIT_SUCCESS);
}
