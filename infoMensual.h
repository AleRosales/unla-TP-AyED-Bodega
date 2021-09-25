#ifndef INFOMENSUAL_H_INCLUDED
#define INFOMENSUAL_H_INCLUDED

struct infoMesualEstructura;
typedef struct infoMesualEstructura * infoMesual;

infoMesual crearInfoMensual();

void setsIdusuario(infoMesual a, int nuevoId);

void setsMesSeleccion(infoMesual a, int nuevoMesSeleccion);

void setsAnioSeleccion(infoMesual a, int nuevoAnioSeleccion);

void setsIdVino1(infoMesual a, int nuevoIdVino1);

void setsIdVino2(infoMesual a, int nuevoIdVino2);

void setsIdVino3(infoMesual a, int nuevoIdVino3);

void setsIdVino4(infoMesual a, int nuevoIdVino4);

void setsIdVino5(infoMesual a, int nuevoIdVino5);

void setsIdVino6(infoMesual a, int nuevoIdVino6);

#endif // INFOMENSUAL_H_INCLUDED
