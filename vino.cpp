#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "vino.h"

using namespace std;



struct VinoEstructura{
        int idVino;
        char etiqueta[50];
        char bodega[50];
        char segmento_del_vino[50];
        char varietal[50];
        int anioCosecha;
        char terroir[50];
        };

Vino crearVino(){

    Vino e = new VinoEstructura;

    return e;

}


int getsVino(Vino a){

return a->idVino;

}
char * getsetiqueta(Vino a){
   return a->etiqueta;
}

char * getsNombreBodega(Vino a){
    return a->bodega;
}

int getsAnioCosecha(Vino a){
   return a->anioCosecha;
}

void setsIdVino(Vino a, int nuevoIdvino){
    a->idVino=nuevoIdvino;
}
void setsEtiqueta(Vino a, char nuevaEtiqueta[50]){
    strcpy(a->etiqueta,nuevaEtiqueta);
}
void setsBodega(Vino a, char nuevoBodega[50]){
    strcpy(a->bodega,nuevoBodega);
}
void setsSegmentoVino(Vino a, char nuevoSegmentoVino[50]){
    strcpy(a->segmento_del_vino,nuevoSegmentoVino);
}
void setsVarietal(Vino a, char nuevoVarietal[50]){
    strcpy(a->varietal,nuevoVarietal);
}
void setsAnioCosecha(Vino a, int nuevoAnioCosecha){
    a->anioCosecha=nuevoAnioCosecha;
}
void setsTerroir(Vino a, char nuevoTerroir[50]){
   strcpy(a->terroir,nuevoTerroir);
}
