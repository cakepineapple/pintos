#include "lib/stdio.h"
#include "devices/input.h"
#include "threads/malloc.h"


char* readline(int len) {
    input_init();
    char key = '\0';
    char* word = malloc(sizeof(char) * len);
    int i;
    for (i = 0; i < len - 1; i++) {
        key = input_getc();
        if (key == 13) {
            word[i] = '\0';
            break;
        }
        word[i] = key;
        printf("%c", key);
    }
    return word;
}