#include "util.h"
#include <string.h>

size_t vtrlen(void* ptr){
    if (ptr == NULL)
        return 0;
    size_t contador = 0;
    while (((void**) ptr)[contador] != NULL){
        contador++;
    }
    return contador;
}

void* vtradd(void* ptr, void* item){
    size_t tamanio_anterior = vtrlen(ptr);
    ptr = realloc(ptr, sizeof(void*) * (tamanio_anterior + 2));
    ((void**) ptr)[tamanio_anterior] = item;
    ((void**) ptr)[tamanio_anterior + 1] = NULL;
    return ptr;
}

void vtrfree(void* ptr){

}

char** split(const char* str, char separador){
    char** ptr = NULL;
    size_t i;
    char* palabra;
    for(i = 0; i < strlen(str); i++){
        while(str[i] != separador){
            palabra += str[i];
            i++;
        }
        ptr = vtradd(ptr, palabra);
        palabra = NULL;
    }
    return ptr;
}

char* fgets_alloc(FILE* archivo){
    return NULL;
}

void fclosen(FILE* archivo){

}
