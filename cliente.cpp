#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.hpp"
#include <cstring>

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
/*
char * getsApellido(Cliente a)
{
    return a->apellido;
}
*/

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
/*
char * getsLocalidad(Cliente a)
{
    return a->localidad;
}
char * getsProvincia(Cliente a)
{
    return a->provincia;
}

*/

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
/*
void setsLocalidad(Cliente a, char nuevoLocalidad[50]){

    strcpy(a->localidad,nuevoLocalidad);
}
void setsProvicia(Cliente a, char nuevoProvincia[50]){

    strcpy(a->provincia,nuevoProvincia);
}
*/
void setsIdusuario(Cliente a, int nuevoId){
    a->idUsuario=nuevoId;
}

void setsEdad(Cliente a, int nuevoEdad){
    a->edad=nuevoEdad;
}

