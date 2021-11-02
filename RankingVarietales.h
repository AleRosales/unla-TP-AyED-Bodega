#ifndef RANKINGVARIETALES_H_INCLUDED
#define RANKINGVARIETALES_H_INCLUDED

struct RankingVarietalesStruct{
    int posicion;
    int cantidadSelecciones;
    char varietal [50];
};

typedef struct RankingVarietalesStruct* RankingVarietales;

int traerEdadCliente(Lista clientes,int idBuscado);

Vino traerVino(Lista vinos,int idBuscado);

void agregarVarietal(Lista lista,char varietalSeleccionado [50]);

void rankingDeVarietales(Lista seleccionados, Lista clientes, Lista vinos);

Lista rankingPorRangoEtario(Lista seleccionados, Lista clientes,Lista vinos, int valorEtarioInf, int valorEtarioSup);

void mostrarRanking(Lista ranking);

void ordenarListaAuxVarietales(Lista lista, Lista ordenada);

#endif // RANKINGVARIETALES_H_INCLUDED
