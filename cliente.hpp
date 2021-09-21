#ifndef CLIENTE_HPP_INCLUDED
#define CLIENTE_HPP_INCLUDED

struct ClienteEstructura;
typedef struct ClienteEstructura * Cliente;


char * getsNombre(Cliente a);
char * getsApellido(Cliente a);
int getsIdUsuario(Cliente a);
int getsEdad(Cliente a);
char * getsDireccion(Cliente a);
char * getsLocalidad(Cliente a);
char * getsProvincia(Cliente a);

Cliente crearCiente();
void setsNombre(Cliente a, char nuevoNombre[30]);

void setsApellido(Cliente a, char nuevoApellido[50]);


void setsDireccion(Cliente a, char nuevoDireccion[50]);


void setsLocalidad(Cliente a, char nuevoLocalidad[50]);

void setsProvicia(Cliente a, char nuevoProvincia[50]);


void setsIdusuario(Cliente a, int nuevoId);

void setsEdad(Cliente a, int nuevoEdad);

#endif // CLIENTE_HPP_INCLUDED
