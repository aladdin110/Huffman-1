#include "header.h"

struct node* newNode(char data, unsigned freq){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

struct huffman* createhuffmanTree(unsigned capacity){
    struct huffman* huffman = (struct huffman*)malloc(sizeof(struct huffman));
    huffman->size = 0;
    huffman->capacity = capacity;
    huffman->array = (struct node**)malloc(huffman->capacity * sizeof(struct node*));
    return huffman;
}

void swapnode(struct node** a, struct node** b){
    struct node* t = *a;
    *a = *b;
    *b = t;
}
