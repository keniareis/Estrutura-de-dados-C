#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0

typedef struct SVertice {
    int dado;
    struct SConexao *conexao;
    struct SVertice *next;
    _Bool visitado;
    int distancia; 
    struct SVertice *anterior; 
} TVertice;

typedef struct SConexao {
    struct SVertice *vertice;
    struct SConexao *next;
    int peso; // Campo de peso
} TConexao;

TVertice *inicio = NULL, *ultimo = NULL;

TVertice *buscarVertice(int key) {
    TVertice *temp = inicio;
    while (temp != NULL) {
        if (temp->dado == key)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

TVertice *adicionarVertice(int info) {
    TVertice *novo;

    novo = buscarVertice(info);
    if (novo != NULL)
        return novo;

    novo = (TVertice *)malloc(sizeof(TVertice));
    novo->dado = info;
    novo->conexao = NULL;
    novo->next = NULL;
    novo->visitado = FALSE;
    novo->distancia = INT_MAX; 
    novo->anterior = NULL; 

    if (inicio == NULL) {
        inicio = novo;
    } else {
        ultimo->next = novo;
    }

    ultimo = novo;
    return novo;
}

void listar() {
    TVertice *temp = inicio;
    while (temp != NULL) {
        printf("%d ", temp->dado);
        temp = temp->next;
    }
    printf("\n");
}

void conectarVertices(int info1, int info2, int peso) {
    TVertice *verticeOrigem, *verticeDestino;
    TConexao *ultimaConexao;

    verticeOrigem = adicionarVertice(info1);
    verticeDestino = adicionarVertice(info2);

    TConexao *novaConexao = (TConexao *)malloc(sizeof(TConexao));
    novaConexao->vertice = verticeDestino;
    novaConexao->next = NULL;
    novaConexao->peso = peso;

    if (verticeOrigem->conexao == NULL)
        verticeOrigem->conexao = novaConexao;
    else {
        ultimaConexao = verticeOrigem->conexao;
        while (ultimaConexao->next != NULL) {
            ultimaConexao = ultimaConexao->next;
        }
        ultimaConexao->next = novaConexao;
    }
}

TVertice *minDistancia() {
    TVertice *min = NULL;
    TVertice *v = inicio;
    while (v != NULL) {
        if (!v->visitado && (min == NULL || v->distancia < min->distancia)) {
            min = v;
        }
        v = v->next;
    }
    return min;
}

void dijkstra(TVertice *origem) {
    origem->distancia = 0;
    TVertice *vAtual;

    while ((vAtual = minDistancia()) != NULL) {
        vAtual->visitado = TRUE;

        TConexao *conexao = vAtual->conexao;
        while (conexao != NULL) {
            if (!conexao->vertice->visitado && vAtual->distancia + conexao->peso < conexao->vertice->distancia) {
                conexao->vertice->distancia = vAtual->distancia + conexao->peso;
                conexao->vertice->anterior = vAtual;
            }
            conexao = conexao->next;
        }
    }
}

void imprimirCaminho(TVertice *destino) {
    if (destino->anterior != NULL) {
        imprimirCaminho(destino->anterior);
    }
    printf("%d ", destino->dado);
}

int main(int argc, char** argv) {
    int leitura, leitura2, peso;

    while (1) {
        printf("Informe os valores dos vertices e o peso da aresta (ou 0 0 0 para terminar): ");
        scanf("%d %d %d", &leitura, &leitura2, &peso);
        if (leitura == 0 && leitura2 == 0 && peso == 0)
            break;

        conectarVertices(leitura, leitura2, peso);
    }

    printf("Informe o vertice de origem: ");
    scanf("%d", &leitura);
    TVertice *origem = buscarVertice(leitura);

    printf("Informe o vertice de destino: ");
    scanf("%d", &leitura2);
    TVertice *destino = buscarVertice(leitura2);

    if (origem != NULL && destino != NULL) {
        dijkstra(origem);
        printf("Distancia do vertice %d ate a origem: %d\n", destino->dado, destino->distancia);
        printf("Caminho mais curto do vertice %d ate o vertice %d: ", origem->dado, destino->dado);
        imprimirCaminho(destino);
        printf("\n");
    } else {
        if (origem == NULL) {
            printf("Vertice de origem nao encontrado.\n");
        }
        if (destino == NULL) {
            printf("Vertice de destino nao encontrado.\n");
        }
    }

    return 0;
}
