#ifndef __LIB_USER_EXTRAS_H
#define __LIB_USER_EXTRAS_H

char* readline(int len);
bool compare_wakeat(const struct list_elem* a, const struct list_elem* b, void* aux);

#endif //__LIB_USER_EXTRAS_H