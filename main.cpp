#include <iostream>
#include "lista.h"
#include "funcionesCargarArchivos.h"
#include "infoMensual.h"
#include "vino.h"
#include "cliente.h"
#include "RankingVinos.h"
#include "rankingBodegas.h"

using namespace std;

int main()
{
    //Lista es un puntero a estructura listaStruct
    //listaStruct tiene como atributos:
    // un int tamanio-->tamaño de la lista
    // un Nodo puntero a la struct nodo
    //(la struct nodo tiene como atibutos:
    //un int nro-->número del nodo en la lista
    //un *void--->dato
    //un Nodo que es el puntero al siguiente)
    //crearLista reserva espacio en memoria de tamaño listaStruct
    Lista miListaCliente=crearLista();
    Lista miListaVinos=crearLista();
    Lista miListaSeleccion=crearLista();

    leerYpasarAstructConString(miListaCliente);
    leerYpasarAseleccion(miListaSeleccion);
    leerYpasaraVinos(miListaVinos);

    /*cout <<"Lista de vinos:"<<endl;
    mostrarLista(miListaVinos);
    cout <<"Lista de clientes:"<<endl;
    mostrarLista(miListaCliente);
    cout <<"Lista de seleccion vinos:"<<endl;
    mostrarLista(miListaSeleccion);*/

    //Dan ambos 233(Y)
    rankingPorVinos(miListaSeleccion,miListaVinos);
    lstBodegas(miListaVinos,miListaSeleccion);
    return 0;
}
