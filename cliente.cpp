#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"


using namespace std;

struct ClienteEstructura{
    int idUsuario;
    char nombre[30];
    char direccion[90];
    int edad;
};

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
/*
void setsApellido(Cliente a, char nuevoApellido[50]){
    strcpy(a->apellido,nuevoApellido);
}
*/
void setsDireccion(Cliente a, char nuevoDireccion[50]){

    strcpy(a->direccion,nuevoDireccion);
}

void setsIdusuario(Cliente a, int nuevoId){
    a->idUsuario=nuevoId;
}

void setsEdad(Cliente a, int nuevoEdad){
    a->edad=nuevoEdad;
}
