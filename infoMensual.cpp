#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "infoMensual.hpp"

using namespace std;



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
infoMesual crearInfoMensual(){

    infoMesual e = new infoMesualEstructura;

    return e;
}

void setsIdusuario(infoMesual a, int nuevoId){
    a->idUsuario=nuevoId;
}
void setsMesSeleccion(infoMesual a, int nuevoMesSeleccion){
    a->mesSeleccion=nuevoMesSeleccion;
}
void setsAnioSeleccion(infoMesual a, int nuevoAnioSeleccion){
    a->anioSeleccion=nuevoAnioSeleccion;
}
void setsIdVino1(infoMesual a, int nuevoIdVino1){
    a->idVino1=nuevoIdVino1;
}
void setsIdVino2(infoMesual a, int nuevoIdVino2){
    a->idVino2=nuevoIdVino2;
}
void setsIdVino3(infoMesual a, int nuevoIdVino3){
    a->idVino3=nuevoIdVino3;
}
void setsIdVino4(infoMesual a, int nuevoIdVino4){
    a->idVino4=nuevoIdVino4;
}
void setsIdVino5(infoMesual a, int nuevoIdVino5){
    a->idVino5=nuevoIdVino5;
}
void setsIdVino6(infoMesual a, int nuevoIdVino6){
    a->idVino6=nuevoIdVino6;
}