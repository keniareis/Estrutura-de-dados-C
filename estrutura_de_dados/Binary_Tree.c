#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *right;
    struct Node *left;
} Node;



Node *insert(Node *root, int data){
    if(root == NULL){
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;

        return newNode;
    }

    if (data > (root)->data){
        root->right = insert(root->right, data);
    } else{
        root->left = insert(root->left, data);
    }

    return root;
}
    
int search(Node *root, int data){
    if(root == NULL){
        return 0;

    }else if (data == root->data){
        return 1;

    }else if (data > root->data){
        return search(root->right, data);

    }else{
        return search(root->left, data);
    }
    
}

void inOrder(Node *root){
    if (root == NULL) {
        return;
    }

    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
    
}

void preOrder(Node *root){
    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
    
}

void posOrder(Node *root){
    if (root == NULL) {
        return;
    }

    posOrder(root->left);
    posOrder(root->right);
    printf("%d ", root->data);
    
}

int main(){
    Node *root = NULL;


    int number = 1;
    printf("insira os valores na arvore (0 para sair):\n");
    while (number != 0) {
        scanf("%d", &number);
        if (number != 0) {
            root = insert(root, number);
        }
    }

    printf("arvore em ordem:\n");
    inOrder(root);

    printf("\n\narvore em pre ordem:\n");
    preOrder(root);

    printf("\narvore em pos ordem:\n");
    posOrder(root);

    return 0;
}