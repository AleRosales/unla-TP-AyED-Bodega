#ifndef FUNCIONCARGARARCHIVOS_HPP_INCLUDED
#define FUNCIONCARGARARCHIVOS_HPP_INCLUDED
#include "infoMensual.hpp"
#include "vino.hpp"
#include "cliente.hpp"
#include "lista.hpp"

#include <string.h>


using namespace std;

void leerYpasarAstructConString(Lista clien);
void leerYpasarAseleccion(Lista selec);
void leerYpasaraVinos(Lista vin);


Cliente  pasarCharAStructConString(string texto);
Vino  pasarCharAStructConStringVino(string texto);
infoMesual  pasarCharAstructSeleccion(string texto);


#endif // FUNCIONCARGARARCHIVOS_HPP_INCLUDED
