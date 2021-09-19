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
void agregar(Lista lista,void* dato);

/*
PRE : El Lista debe haber sido creada.
POST: Elimina el nodo de nro igual al que se envio por parametro
*/
void eliminar(Lista lista,int nro);

/*
PRE : El Lista debe haber sido creada.
POST: Elimina todos los nodos de la lista liberando la memoria
*/
void eliminarLista(Lista lista);


/*
PRE : El nodo debe haber sido creado.
POST: Asigna nro a nodo
*/
void setNro(Nodo nodo,int nro);

/*
PRE : El nodo debe haber sido creado.
POST: Asigna dato a nodo
*/
void setDato(Nodo nodo,void* dato);

/*
PRE : El nodo debe haber sido creado.
POST: Asigna siguiente a nodo
*/
void setSiguiente(Nodo nodo,Nodo sig);

/*
PRE : El nodo debe haber sido creado.
POST: Devuelve el nro del nodo
*/
int getNro(Nodo nodo);
/*
PRE : El nodo debe haber sido creado.
POST: Devuelve el dato del nodo
*/
void* getDato(Nodo nodo);
/*
PRE : La lista debe haber sido creado.
POST: Devuelve el siguiente del nodo
*/
Nodo getSiguiente(Nodo nodo);

/*
PRE : La lista debe haber sido creado.
POST: Devuelve el tamaño de la lista
*/
int getTamanio(Lista lista);

/*
PRE : La lista debe haber sido creado.
POST: Devuelve el primer nodo
*/
Nodo getInicio(Lista lista);

/*
PRE : La lista debe haber sido creado.
POST: Asigna el tamaño a la lista
*/
void setTamanio(Lista lista,int tamanio);

/*
PRE : La lista debe haber sido creado.
POST: Asigna el primer nodo a la lista
*/
void setInicio(Lista lista,Nodo nodo);
#endif
