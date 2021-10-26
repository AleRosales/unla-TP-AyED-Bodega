#ifndef VINO_H_INCLUDED
#define VINO_H_INCLUDED


typedef struct VinoEstructura * Vino;

Vino crearVino();

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

#endif // VINO_H_INCLUDED
