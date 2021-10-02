#ifndef RANKINGVINOS_H_INCLUDED
#define RANKINGVINOS_H_INCLUDED
#include "vino.h"
#include "Lista.h"

struct RankingVinosStruct{
    int posicion;
    int cantidadSelecciones;
    Vino vino;
};
typedef struct RankingVinosStruct* RankingVinos;

void rankingPorVinos (Lista  seleccionados,Lista vinos);

RankingVinos buscarVino(Lista lista,int idVino);
#endif // RANKINGVINOS_H_INCLUDED
