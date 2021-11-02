#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"


using namespace std;

Cliente crearCiente(){

    Cliente e = new ClienteEstructura;

    return e;

}

char * getsNombre(Cliente a)
{
    return a->nombre;
}

int getsIdUsuario(Cliente a)
{
    return a->idUsuario;
}
int getsEdad(Cliente a)
{
    return a->edad;
}

char * getsDireccion(Cliente a)
{
    return a->direccion;
}

void setsNombre(Cliente a, char nuevoNombre[30]){
    strcpy(a->nombre,nuevoNombre);
}

void setsDireccion(Cliente a, char nuevoDireccion[50]){

    strcpy(a->direccion,nuevoDireccion);
}

void setsIdusuario(Cliente a, int nuevoId){
    a->idUsuario=nuevoId;
}

void setsEdad(Cliente a, int nuevoEdad){
    a->edad=nuevoEdad;
}
