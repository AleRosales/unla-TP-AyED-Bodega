#ifndef RANKINGBODEGAS_H_INCLUDED
#define RANKINGBODEGAS_H_INCLUDED
#include "lista.h"


typedef struct BodegaStruct{
    char nombreBodega[50];
    int cant;
}*Bodega;

void lstBodegas(Lista catalogo, Lista info);

Bodega buscarBodega(Lista lista,char nombre[50]);

void ordenarListaAuxBodega(Lista lista, Lista ordenada);
#endif // RANKINGBODEGAS_H_INCLUDED
