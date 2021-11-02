#ifndef RANKINGVINOS_H_INCLUDED
#define RANKINGVINOS_H_INCLUDED
#include "vino.h"
#include "lista.h"

struct RankingVinosStruct{
    int cantidadSelecciones;
    Vino vino;
};
typedef struct RankingVinosStruct* RankingVinos;


void rankingPorVinos (Lista  seleccionados,Lista vinos);
void ordenarListaAux(Lista lista, Lista ordenada);
void agregarVinos(Lista ranking, Vino vino);
RankingVinos buscarVino(Lista lista,int idVino);
void mostrarListaRankigVino(Lista lista);
#endif // RANKINGVINOS_H_INCLUDED
