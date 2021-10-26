#ifndef LISTA_H_
#define LISTA_H_

/**
    Definición del Tipo de Dato para manejo de Listas.
    Atributos:
    * nro,
    * dato,
    * nodoSiguiente,

*/

/******************************************************************************/


typedef struct nodo* Nodo;

typedef struct listaStruct* Lista;

struct nodo {
    int nro;
    void* dato;
    Nodo siguiente;
};

struct listaStruct {
    int tamanio;
    Nodo inicio;
};

/******************************************************************************/
/* Definicion de Primitivas */
/*--------------------------*/

/*
  PRE : El Lista no debe haber sido creado.
  POST: El Lista queda creado y preparado para ser usado.
*/
Lista crearLista();

/*
PRE : El Lista debe haber sido creada.
POST: Crea nuevo nodo en la lista con el dato enviado por parametro.
*/
void agregarNodo(Lista lista,void* dato);

/*
PRE : El Lista debe haber sido creada.
POST: Elimina el nodo de nro igual al que se envio por parametro
*/
void eliminarNodo(Lista lista,int nro);

/*
PRE : El Lista debe haber sido creada.
POST: Elimina todos los nodos de la lista liberando la memoria
*/
void eliminarLista(Lista lista);

bool listaVacia(Lista lista);

Nodo nodoSeleccionado(Lista lista,int nro);

Nodo ultimoNodo(Lista lista);

Nodo anteriorNodo(Lista lista,Nodo nodo);

void mostrarLista(Lista lista);

int ultimoAnio();
#endif
