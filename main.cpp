#include <iostream>
#include "lista.h"
#include "funcionesCargarArchivos.h"
#include "infoMensual.h"
#include "vino.h"
#include "cliente.h"



using namespace std;

int main()
{
    Lista miListaCliente=crearLista();
    Lista miListaVinos=crearLista();
    Lista miListaSeleccion=crearLista();

    leerYpasarAstructConString(miListaCliente);
    leerYpasarAseleccion(miListaSeleccion);
    leerYpasaraVinos(miListaVinos);
    return 0;
}
