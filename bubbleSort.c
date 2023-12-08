#include <stdio.h>
#include <stdlib.h>
#define TAM 5

void bubbleSort(int vetor[]){
    int troca;
    for(int i = 0; i < TAM - 1;i++){
        for(int j = i + 1; j < TAM; j++){
            if (vetor[i] > vetor[j]){
                troca = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = troca;
            }
            
        }
        for(int k = 0; k < TAM; k++){
            printf("%d ", vetor[k]);
        }   
        printf("\n");
    }
}

int main(){
    int vetor[5] = {5, 4, 3, 2, 1};

    bubbleSort(vetor);
    return 0;
}