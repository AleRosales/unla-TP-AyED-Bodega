#include <iostream>
#include "RankingVinos.h"
#include "Lista.h"
#include "infoMensual.h"
#include "vino.h"
#include "cliente.h"
#include "RankingVarietales.h"
#include "string.h"
#include <iomanip>

using namespace std;

void rankingDeVarietales(Lista seleccionados, Lista clientes, Lista vinos){
    Lista rankingRango1 = rankingPorRangoEtario(seleccionados, clientes, vinos, 0, 30);
    Lista ordenada=crearLista();
    ordenarListaAuxVarietales(rankingRango1,ordenada);
    cout<<"Ranking de varietales de menores de 30:"<<endl;
    mostrarRanking(ordenada);
    Lista rankingRango2 = rankingPorRangoEtario(seleccionados, clientes, vinos, 30, 50);
    Lista ordenada1=crearLista();
    ordenarListaAuxVarietales(rankingRango2,ordenada1);
    cout<<"Ranking de varietales de entre 30 y 50:"<<endl;
    mostrarRanking(ordenada1);


    Lista rankingRango3 = rankingPorRangoEtario(seleccionados, clientes, vinos, 50, 1000);
    Lista ordenada2=crearLista();
    ordenarListaAuxVarietales(rankingRango3,ordenada2);
    cout<<"Ranking de varietales de mayores de 50:"<<endl;
    mostrarRanking(ordenada2);

}
//rankingPorRangoEtario ?
Lista rankingPorRangoEtario(Lista seleccionados, Lista clientes,Lista vinos, int valorEtarioInf, int valorEtarioSup) {
    Lista listaResultante = crearLista();
    Nodo nodoActual = seleccionados->inicio;

    while (nodoActual != NULL){
        infoMesual seleccionActual = (infoMesual) nodoActual->dato;
        int edadClienteActual = traerEdadCliente(clientes, getsIdUsuarioInfo(seleccionActual));

        if (edadClienteActual > valorEtarioInf && edadClienteActual < valorEtarioSup){



            Vino vino1 = traerVino(vinos, getsVino1(seleccionActual));
            Vino vino2 =traerVino(vinos, getsVino2(seleccionActual));
            Vino vino3 =traerVino(vinos, getsVino3(seleccionActual));
            Vino vino4 =traerVino(vinos, getsVino4(seleccionActual));
            Vino vino5 =traerVino(vinos, getsVino5(seleccionActual));
            Vino vino6 =traerVino(vinos, getsVino6(seleccionActual));


            agregarVarietal(listaResultante,getsVarietal(vino1));
            agregarVarietal(listaResultante, getsVarietal(vino2));
            agregarVarietal(listaResultante,getsVarietal(vino3));
            agregarVarietal(listaResultante, getsVarietal(vino4));
            agregarVarietal(listaResultante, getsVarietal(vino5));
            agregarVarietal(listaResultante, getsVarietal(vino6));


        }
        nodoActual = nodoActual->siguiente;
    }

    return listaResultante;
}

void agregarVarietal(Lista lista,char varietalSeleccionado[]){
    Nodo nodoActual = lista->inicio;
    bool encontrado = false;

    while(nodoActual != NULL && !encontrado){
        RankingVarietales ranking = (RankingVarietales) nodoActual->dato;

        if(strcmp(ranking -> varietal, varietalSeleccionado )== 0 ){
            encontrado = true;
            ranking->cantidadSelecciones +=1;
        }else{
            nodoActual = nodoActual->siguiente;
        }
    }
    if(!encontrado){
        RankingVarietales nuevoVarietal = new RankingVarietalesStruct();
        nuevoVarietal->cantidadSelecciones = 1;
        strcpy(nuevoVarietal->varietal,varietalSeleccionado);
        agregarNodo(lista, nuevoVarietal);
    }
}

int traerEdadCliente(Lista clientes,int idBuscado){
    Nodo nodoActual = clientes->inicio;
    Cliente encontrado = NULL;
    while(nodoActual != NULL && encontrado == NULL){
        Cliente clienteActual = (Cliente) nodoActual->dato;
        if(getsIdUsuario(clienteActual) == idBuscado){
            encontrado = clienteActual;
        }
        nodoActual = nodoActual->siguiente;
    }
    return getsEdad(encontrado);
}

Vino traerVino(Lista vinos,int idBuscado){
    Nodo nodoActual = vinos->inicio;
    Vino encontrado = NULL;
    while(nodoActual != NULL && encontrado == NULL){
        Vino vinoActual = (Vino) nodoActual->dato;
        if(getsVino(vinoActual)== idBuscado){
            encontrado = vinoActual;
        }
        nodoActual = nodoActual->siguiente;
    }
    return encontrado;
}

//void ordenarRanking(Lista lista){
//
//}

void mostrarRanking(Lista ranking){

    Nodo nodoActual = ranking->inicio;
     cout << setw( 70 ) << setfill( '-' ) << '\n' << setfill( ' ' );
    cout << "| "<< left << setw( 14 ) << "Posicion"<< "|" << right << setw( 1) << " Varietal"  << right << setw( 21 )<< "|"<< "Cantidad Selecionado" << " |"<<endl;
    cout << setw( 70 ) << setfill( '-' ) << '\n' << setfill( ' ' ) << '\n';
    while(nodoActual != NULL){
            RankingVarietales puestoActual = (RankingVarietales) nodoActual->dato;
            int resultado=strlen(puestoActual->varietal);
            cout<<"Nro en lista: "<<nodoActual->nro<<"  varietal: "<<puestoActual->varietal<<right << setw(38-resultado)<<" Cant.selecciones: "<<puestoActual->cantidadSelecciones<<std::endl;

            nodoActual = nodoActual->siguiente;
    }
    cout<<"\n"<<endl;

}

void ordenarListaAuxVarietales(Lista lista, Lista ordenada){
    Nodo actual;
    Nodo siguiente;
    actual=lista->inicio;
    Nodo auxNodo;
    int nro;

    while (actual!=NULL )
    {
        nro=actual->nro;
        siguiente=actual->siguiente;
        RankingVarietales auxMaximo=(RankingVarietales)actual->dato;
        while( siguiente !=NULL )
        {
            RankingVarietales rankig13=(RankingVarietales)siguiente->dato;
          if(auxMaximo->cantidadSelecciones<rankig13->cantidadSelecciones)
            {
            auxMaximo=rankig13;
            nro=siguiente->nro;
            }
            siguiente=siguiente->siguiente;

        }
        RankingVarietales nuevo = new RankingVarietalesStruct;
        auxNodo=nodoSeleccionado(lista,nro);
        RankingVarietales varietalesAnt=(RankingVarietales)auxNodo->dato;
        nuevo->cantidadSelecciones=varietalesAnt->cantidadSelecciones;
        strcpy(nuevo->varietal,varietalesAnt->varietal);

        agregarNodo(ordenada,nuevo);
        eliminarNodo(lista,nro);

        actual=lista->inicio;


    }
}
