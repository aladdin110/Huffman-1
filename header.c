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

void sort(struct huffman* huffman, int id){
    int smallest = id;
    int left = 2 * id + 1;
    int right = 2 * id + 2;

    if (left < huffman->size && huffman->array[left]->freq< huffman->array[smallest]->freq)
        smallest = left;

    if (right < huffman->size && huffman->array[right]->freq < huffman->array[smallest]->freq)
        smallest = right;

    if (smallest != id) {
        swapnode(&huffman->array[smallest], &huffman->array[id]);
        sort(huffman, smallest);
    }
}

int isSizeOne(struct huffman* huffman){
    return (huffman->size == 1);
}

struct node* extractMin(struct huffman* huffman){
    struct node* temp = huffman->array[0];
    huffman->array[0] = huffman->array[huffman->size - 1];
    --huffman->size;
    sort(huffman, 0);
    return temp;
}

void inserthuffman(struct huffman* huffman,struct node* node){
    ++huffman->size;
    int i = huffman->size - 1;
    while (i && node->freq < huffman->array[(i - 1) / 2]->freq) {
        huffman->array[i] = huffman->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    huffman->array[i] = node;
}


void buildhuffman(struct huffman* huffman){
    int n = huffman->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i)
        sort(huffman, i);
}

int isLeaf(struct node* root){
    return !(root->left) && !(root->right);
}


struct huffman* createAndBuildhuffman(char data[],int freq[], int size){
    struct huffman* huffman = createhuffmanTree(size);
    for (int i = 0; i < size; ++i)
        huffman->array[i] = newNode(data[i], freq[i]);
    huffman->size = size;
    buildhuffman(huffman);
    return huffman;
}
