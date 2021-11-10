#include "header.c"

int main() {
    /*
    int size = 1000;
    char* str = (char*)malloc(size * sizeof(char));
    strcpy(str, "Hello world!");
    
    struct node* tab = getRedundancy(str, size);
    int size = sizeof(tab) / sizeof(tab[0]);
    */
    char arr[] = { 'g', 'y', 'k', 'm', 'n', 'f' };
    int freq[] = { 5, 9, 11, 13, 14, 20 };

    HuffmanCodes(arr, freq, size);

    free(tab);
    free(str);
    return 0;
}
