#include <iostream>
#include "lista.h"
#include "funcionesCargarArchivos.h"
#include "infoMensual.h"
#include "vino.h"
#include "cliente.h"
#include "RankingVinos.h"


using namespace std;

int main()
{
    Lista miListaCliente=crearLista();
    Lista miListaVinos=crearLista();
    Lista miListaSeleccion=crearLista();

    leerYpasarAstructConString(miListaCliente);
    leerYpasarAseleccion(miListaSeleccion);
    leerYpasaraVinos(miListaVinos);

    /*cout <<"Lista de clientes:"<<endl;
    mostrarLista(miListaCliente);

    cout <<"Lista de vinos:"<<endl;
    mostrarLista(miListaVinos);

    cout <<"Lista de seleccion vinos:"<<endl;
    mostrarLista(miListaSeleccion);*/

    rankingPorVinos(miListaSeleccion,miListaVinos);

    return 0;
}
