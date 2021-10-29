#ifndef RANKINGBODEGAS_H_INCLUDED
#define RANKINGBODEGAS_H_INCLUDED
#include "lista.h"

//Estructura que guarda el nombre de una bodega y la lista de vinos que contiene
typedef struct BodegaStruct{
    char nombreBodega[50];
    int cant;
}*Bodega;
//Función que crea una lista de bodegas.
//Abre el archivo catalogos.txt y toma el nombre de la bodega del primer registro.
//Luego, agrega el vino a la Lista vinos de la bodega recién creada.
//Pasa al segundo registro. Si el nombre de la bodega ya existe en la lista,
//agrega otro vino a la Lista vinos de la bodega ya creada; sino, crea una nueva,
//la agrega a la lstBodegas y hace lo mismo con el vino
void lstBodegas(Lista catalogo, Lista info);

Bodega buscarBodega(Lista lista,char nombre[50]);
void agregarBodega(Lista bodega, Vino vino);
void ordenarListaAuxBodega(Lista lista, Lista ordenada);
#endif // RANKINGBODEGAS_H_INCLUDED
