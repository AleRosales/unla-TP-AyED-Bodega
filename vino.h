#ifndef VINO_H_INCLUDED
#define VINO_H_INCLUDED

/*
Definicion de tipo de dato Vino para representar los datos de los Vinos
    Atributos:
        idVino
        etiqueta
        bodega
        segmento_del_vino
        varietal
        anioCosecha
        terroir
    Axiomas
        idVino: mayor a 0
        etiqueta: maximo 50 caracteres
        bodega: maximo 50 caracteres
        segmento_del_vino: maximo 50 caracteres
        varietal: maximo 50 caracteres
        anioCosecha: entre 0 y 2147483647
        terroir: maximo 50 caracteres
*/

/*Tipo de estructura*/

struct VinoEstructura{
        int idVino;
        char etiqueta[50];
        char bodega[50];
        char segmento_del_vino[50];
        char varietal[50];
        int anioCosecha;
        char terroir[50];
};

typedef struct VinoEstructura * Vino;

/**********************************/


/*getters y setters*/

int getsVino(Vino a);
int getsAnioCosecha(Vino a);
char * getsetiqueta(Vino a);
char * getsNombreBodega(Vino a);
char * getsVarietal(Vino a);

void setsIdVino(Vino a, int nuevoIdvino);
void setsEtiqueta(Vino a, char nuevaEtiqueta[50]);
void setsBodega(Vino a, char nuevoBodega[50]);
void setsSegmentoVino(Vino a, char nuevoSegmentoVino[50]);
void setsVarietal(Vino a, char nuevoVarietal[50]);
void setsAnioCosecha(Vino a, int nuevoAnioCosecha);
void setsTerroir(Vino a, char nuevoTerroir[50]);

/**********************************/

/*
    precondicion: ninguna
    postcondicion: crea el Vino
*/

Vino crearVino();

#endif // VINO_H_INCLUDED
