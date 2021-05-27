#include "lista.h"
#include "pa2mm.h"

void dadoQueNecesitoUnaLista_siCreoUnaListaNueva_devuelvoUnaListaVacia(){
  lista_t* nueva_lista = lista_crear();

  pa2m_afirmar(nueva_lista->nodo_inicio == NULL, "Se obtuvo una lista con un nodo inicio igual a NULL");
  pa2m_afirmar(nueva_lista->nodo_fin == NULL, "Se obtuvo una lista con un nodo fin igual a NULL");
  pa2m_afirmar(nueva_lista->cantidad == 0, "Se obtuvo una lista con cantidad igual a 0");

  lista_destruir(nueva_lista);
}

void dadaUnaListaVacia_siLeAgregoUnElemento_resultaEnUnaListaConUnElemento(){
  lista_t* lista_null = NULL;
  lista_t* nueva_lista = lista_crear();
  void* elemento = malloc(sizeof(int));

  pa2m_afirmar(lista_insertar(lista_null, elemento) == -1, "Dada una lista nula, devuelvo -1");
  pa2m_afirmar(lista_insertar(nueva_lista, elemento) == 0, "Se pudo agregar un elemento a la lista");
  pa2m_afirmar(nueva_lista->nodo_inicio->elemento == elemento && elemento == nueva_lista->nodo_fin->elemento ,"El primer y ultimo elemento de la lista es el elemento que agregué");

  free(elemento);
  lista_destruir(nueva_lista);
}

void dadaUnaLista_siAgregoElementos_laListaSeAgranda(){
  lista_t* lista = lista_crear();
  void* elemento = malloc(sizeof(char));
  lista_insertar(lista, elemento);

  pa2m_afirmar(lista_insertar(lista, elemento) == 0, "Se pudo agregar un elemento nuevo a la lista");
  pa2m_afirmar(lista_elementos(lista) == 2, "Se obtuvo una lista con dos elementos");
  pa2m_afirmar(lista_insertar(lista, elemento) == 0, "Se pudo agregar un elemento nuevo a la lista");
  pa2m_afirmar(lista_elementos(lista) == 3, "Se obtuvo una lista con tres elementos");

  free(elemento);
  lista_destruir(lista);
}

void dadaUnaLista_siPidoElElementoDeUnaPosicion_reciboEseElemento(){
  lista_t* lista = lista_crear();
  void* elemento = malloc(sizeof(char));
  void* elemento1 = malloc(sizeof(int));
  void* elemento2 = malloc(sizeof(float));
  lista_insertar(lista, elemento);
  lista_insertar(lista, elemento1);
  lista_insertar(lista, elemento2);

  pa2m_afirmar(lista_elemento_en_posicion(lista, 0) == elemento, "El primer elemento de la lista es el primer agregado");
  pa2m_afirmar(lista_elemento_en_posicion(lista, 1) == elemento1, "El segundo elemento de la lista es el segundo agregado");
  pa2m_afirmar(lista_elemento_en_posicion(lista, 2) == elemento2, "El tercer elemento de la lista es el tercer agregado");

  free(elemento);
  free(elemento1);
  free(elemento2);
  lista_destruir(lista);
}

void dadaUnaLista_siLeAgregoElementos_puedoSaberConCuantosElementosCuenta(){
  lista_t* lista = lista_crear();
  void* elemento = malloc(sizeof(char));

  pa2m_afirmar(lista_elementos(lista) == 0, "La lista no tiene elementos o no existe");
  lista_insertar(lista, elemento);
  pa2m_afirmar(lista_elementos(lista) == 1, "La lista tiene un elemento");
  lista_insertar(lista, elemento);
  pa2m_afirmar(lista_elementos(lista) == 2, "La lista tiene dos elementos");
  lista_insertar(lista, elemento);
  pa2m_afirmar(lista_elementos(lista) == 3, "La lista tiene tres elementos");

  free(elemento);
  lista_destruir(lista);
}

int main(){
  pa2m_nuevo_grupo("Pruebas de crear lista");
  dadoQueNecesitoUnaLista_siCreoUnaListaNueva_devuelvoUnaListaVacia();
  
  pa2m_nuevo_grupo("Pruebas de lista insertar");
  dadaUnaListaVacia_siLeAgregoUnElemento_resultaEnUnaListaConUnElemento();
  dadaUnaLista_siAgregoElementos_laListaSeAgranda();

  pa2m_nuevo_grupo("Pruebas de lista cantidad de elementos");
  dadaUnaLista_siLeAgregoElementos_puedoSaberConCuantosElementosCuenta();

  pa2m_nuevo_grupo("Pruebas de lista elemento en posición");
  dadaUnaLista_siPidoElElementoDeUnaPosicion_reciboEseElemento();

  return pa2m_mostrar_reporte();
}
