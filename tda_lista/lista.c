#include "lista.h"
#include <stdlib.h>

lista_t* lista_crear(){
    lista_t* lista_nueva = calloc(1, sizeof(lista_t));
    if(!lista_nueva)
        return NULL;
    return lista_nueva;
}

int lista_insertar(lista_t* lista, void* elemento){
    if(!lista)
        return -1;
    if(!lista->nodo_inicio){
        nodo_t* nuevo_nodo = calloc(1, sizeof(nodo_t));
        if(!nuevo_nodo)
            return -1;
        nuevo_nodo->elemento = elemento;
        lista->nodo_inicio = nuevo_nodo;
        lista->nodo_fin = nuevo_nodo;
        lista->nodo_inicio->siguiente = lista->nodo_fin;
    }
    else{
        nodo_t* nuevo_nodo = calloc(1, sizeof(nodo_t));
        if(!nuevo_nodo)
            return -1;
        nuevo_nodo->elemento = elemento;
        lista->nodo_fin->siguiente = nuevo_nodo;
        lista->nodo_fin = nuevo_nodo;
    }
    lista->cantidad++;
    return 0;
}

int lista_insertar_en_posicion(lista_t* lista, void* elemento, size_t posicion){
    return 0;
}

int lista_borrar(lista_t* lista){
    return 0;
}

int lista_borrar_de_posicion(lista_t* lista, size_t posicion){
    return 0;
}

void* lista_elemento_en_posicion(lista_t* lista, size_t posicion){
    return NULL;
}

void* lista_ultimo(lista_t* lista){
    return NULL;
}

bool lista_vacia(lista_t* lista){
    return false;
}

size_t lista_elementos(lista_t* lista){
    if(!lista)
        return 0;
    return lista->cantidad;
}

int lista_apilar(lista_t* lista, void* elemento){
    return 0;
}

int lista_desapilar(lista_t* lista){
    return 0;
}

void* lista_tope(lista_t* lista){
    return NULL;
}

int lista_encolar(lista_t* lista, void* elemento){
    return 0;
}

int lista_desencolar(lista_t* lista){
    return 0;
}

void* lista_primero(lista_t* lista){
    return NULL;
}

void lista_destruir(lista_t* lista){
    //Hay que terminar de implementarla
    free(lista);
}

lista_iterador_t* lista_iterador_crear(lista_t* lista){
        return NULL;
}

bool lista_iterador_tiene_siguiente(lista_iterador_t* iterador){
    return false;
}

bool lista_iterador_avanzar(lista_iterador_t* iterador){
    return false;
}

void* lista_iterador_elemento_actual(lista_iterador_t* iterador){
    return NULL;
}

void lista_iterador_destruir(lista_iterador_t* iterador){

}

size_t lista_con_cada_elemento(lista_t* lista, bool (*funcion)(void*, void*), void *contexto){
    return 0;
}
