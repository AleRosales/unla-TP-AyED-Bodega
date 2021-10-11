#include <iostream>
#include "lista.h"
#include "funcionesCargarArchivos.h"
#include "infoMensual.h"
#include "vino.h"
#include "cliente.h"
#include "RankingVinos.h"
#include "RankingBodegas.h"
#include "RankingVarietales.h"


using namespace std;

int main()
{
    //Lista es un puntero a estructura listaStruct
    //listaStruct tiene como atributos:
    // un int tamanio-->tama�o de la lista
    // un Nodo puntero a la struct nodo
    //(la struct nodo tiene como atibutos:
    //un int nro-->n�mero del nodo en la lista
    //un *void--->dato
    //un Nodo que es el puntero al siguiente)
    //crearLista reserva espacio en memoria de tama�o listaStruct
    Lista miListaCliente=crearLista();
    Lista miListaVinos=crearLista();
    Lista miListaSeleccion=crearLista();

    leerYpasarAstructConString(miListaCliente);
    leerYpasarAseleccion(miListaSeleccion);
    leerYpasaraVinos(miListaVinos);

    cout <<"Lista de clientes:"<<endl;
    mostrarLista(miListaCliente);

    cout <<"Lista de vinos:"<<endl;
    mostrarLista(miListaVinos);
    cout <<"Lista de clientes:"<<endl;
    mostrarLista(miListaCliente);
    cout <<"Lista de seleccion vinos:"<<endl;
    mostrarLista(miListaSeleccion);

    //Dan ambos 233(Y)
    rankingPorVinos(miListaSeleccion,miListaVinos);

    lstBodegas(miListaVinos,miListaSeleccion);

    rankingDeVarietales(miListaSeleccion,miListaCliente,miListaVinos);


    return 0;
}
