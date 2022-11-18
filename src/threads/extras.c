#include "lib/stdio.h"
#include "devices/input.h"
#include "threads/malloc.h"
#include "list.h"
#include "thread.h"


char*
readline(int len) {
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

bool
compare_wakeat(const struct list_elem* a, const struct list_elem* b, void* aux)
{
    int64_t wakeat_a = list_entry(a, struct thread, elem)->wakeat;
    int64_t wakeat_b = list_entry(b, struct thread, elem)->wakeat;
    return wakeat_a < wakeat_b;
}