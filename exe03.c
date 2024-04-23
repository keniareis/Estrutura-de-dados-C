#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó da árvore
struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

// Função para criar um novo nó
struct Node* newNode(char data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Função para imprimir a fórmula em ordem (in-order traversal)
void printInOrder(struct Node* node) {
    if (node == NULL) return;
    if (node->data == '+' || node->data == '-' || node->data == '*' || node->data == '/') {
        printf("(");
        printInOrder(node->left);
        printf(" %c ", node->data);
        printInOrder(node->right);
        printf(")");
    } else {
        printf("%c", node->data);
    }
}

int main() {
    // Construindo a árvore para a fórmula: (A + B) * (C - D)
    struct Node* root = newNode('*');
    root->left = newNode('+');
    root->right = newNode('-');
    root->left->left = newNode('A');
    root->left->right = newNode('B');
    root->right->left = newNode('C');
    root->right->right = newNode('D');

    printf("Formula em ordem: ");
    printInOrder(root);
    printf("\n");
     
    return 0;
}