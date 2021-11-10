#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TREE_HT 100

struct node {
    char data;
    unsigned freq;
    struct node *left, *right;
};

struct huffman {
    unsigned size;
    unsigned capacity;
    struct node** array;
};

struct test{
    char* arr;
    int* freq;
};
