#ifndef INFOMENSUAL_H_INCLUDED
#define INFOMENSUAL_H_INCLUDED

/*
Definicion de tipo de dato InfoMensual para representar los datos de las selecciones de los Clientes
    Atributos:
        idUsuario
        mesSeleccion
        anioSeleccion
        idVino1
        idVino2
        idVino3
        idVino4
        idVino5
        idVino6
    Axiomas
        idUsuario: mayor a 0
        mesSeleccion: entre 1 y 12
        anioSeleccion: entre 0 y 2147483647
        idVino1: entre 0 y 2147483647
        idVino2: entre 0 y 2147483647
        idVino3: entre 0 y 2147483647
        idVino4: entre 0 y 2147483647
        idVino5: entre 0 y 2147483647
        idVino6: entre 0 y 2147483647
*/

/*Tipo de estructura*/

struct infoMesualEstructura{
        int idUsuario;
        int mesSeleccion;
        int anioSeleccion;
        int idVino1;
        int idVino2;
        int idVino3;
        int idVino4;
        int idVino5;
        int idVino6;
};
typedef struct infoMesualEstructura * infoMesual;

/**********************************/


/*getters y setters*/

int getsIdUsuarioInfo(infoMesual a);
int getsAnioSeleccion(infoMesual a);
int getsVino1(infoMesual a);
int getsVino2(infoMesual a);
int getsVino3(infoMesual a);
int getsVino4(infoMesual a);
int getsVino5(infoMesual a);
int getsVino6(infoMesual a);

void setsIdusuario(infoMesual a, int nuevoId);
void setsMesSeleccion(infoMesual a, int nuevoMesSeleccion);
void setsAnioSeleccion(infoMesual a, int nuevoAnioSeleccion);
void setsIdVino1(infoMesual a, int nuevoIdVino1);
void setsIdVino2(infoMesual a, int nuevoIdVino2);
void setsIdVino3(infoMesual a, int nuevoIdVino3);
void setsIdVino4(infoMesual a, int nuevoIdVino4);
void setsIdVino5(infoMesual a, int nuevoIdVino5);
void setsIdVino6(infoMesual a, int nuevoIdVino6);

/**********************************/

/*
    precondicion: ninguna
    postcondicion: crea la InfoMensual
*/

infoMesual crearInfoMensual();

#endif // INFOMENSUAL_H_INCLUDED
