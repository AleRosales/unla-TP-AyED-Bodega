#ifndef VINO_H_INCLUDED
#define VINO_H_INCLUDED

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

Vino crearVino();
void setsIdVino(Vino a, int nuevoIdvino);

void setsEtiqueta(Vino a, char nuevaEtiqueta[50]);

void setsBodega(Vino a, char nuevoBodega[50]);

void setsSegmentoVino(Vino a, char nuevoSegmentoVino[50]);

void setsVarietal(Vino a, char nuevoVarietal[50]);

void setsAnioCosecha(Vino a, int nuevoAnioCosecha);

void setsTerroir(Vino a, char nuevoTerroir[50]);



#endif // VINO_H_INCLUDED
