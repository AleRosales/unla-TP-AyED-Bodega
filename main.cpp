#include <iostream>
#include "lista.hpp"
#include "funcionCargarArchivos.hpp"
#include "infoMensual.hpp"
#include "vino.hpp"
#include "cliente.hpp"



using namespace std;

int main()
{
    Lista miListaCliente=crearLista();
    Lista miListaVinos=crearLista();
    Lista miListaSeleccion=crearLista();

    leerYpasarAstructConString(miListaCliente);
    leerYpasarAseleccion(miListaSeleccion);
    leerYpasaraVinos(miListaVinos);


    cout << "Hello world!" << endl;
    return 0;
}
