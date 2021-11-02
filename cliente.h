#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

/*
Definicion de tipo de dato Cliente para representar los clientes que seleccionaron los vinos
    Atributos:
        idUsuario
        nombre
        direccion
        edad
    Axiomas
        idUsuario: mayor a 0
        nombre: hasta 30 caracteres
        direccion: hasta 90 caracteres
        edad: mayor a 0
*/

/*Tipo de estructura*/

struct ClienteEstructura{
    int idUsuario;
    char nombre[30];
    char direccion[90];
    int edad;
};

typedef struct ClienteEstructura * Cliente;

/**********************************/


/*getters y setters*/

char * getsNombre(Cliente a);
char * getsApellido(Cliente a);
int getsIdUsuario(Cliente a);
int getsEdad(Cliente a);
char * getsDireccion(Cliente a);
char * getsLocalidad(Cliente a);
char * getsProvincia(Cliente a);

void setsNombre(Cliente a, char nuevoNombre[30]);
void setsApellido(Cliente a, char nuevoApellido[50]);
void setsDireccion(Cliente a, char nuevoDireccion[50]);
void setsLocalidad(Cliente a, char nuevoLocalidad[50]);
void setsProvicia(Cliente a, char nuevoProvincia[50]);
void setsIdusuario(Cliente a, int nuevoId);
void setsEdad(Cliente a, int nuevoEdad);

/**********************************/

/*
    precondicion: ninguna
    postcondicion: crea el cliente
*/

Cliente crearCiente();

#endif // CLIENTE_H_INCLUDED
