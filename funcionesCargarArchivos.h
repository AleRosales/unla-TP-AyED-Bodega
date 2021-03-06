#ifndef FUNCIONESCARGARARCHIVOS_H_INCLUDED
#define FUNCIONESCARGARARCHIVOS_H_INCLUDED

#include "infoMensual.h"
#include "vino.h"
#include "cliente.h"
#include "lista.h"
#include <string.h>


using namespace std;

void leerYpasarAusuarios(Lista clien);
void leerYpasarAseleccion(Lista selec);
void leerYpasaraVinos(Lista vin);


Cliente  pasarCharAStructConStringUsuario(string texto);
Vino  pasarCharAStructConStringVino(string texto);
infoMesual  pasarCharAstructSeleccion(string texto);


#endif // FUNCIONESCARGARARCHIVOS_H_INCLUDED
