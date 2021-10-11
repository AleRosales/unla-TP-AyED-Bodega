#include <iostream>
#include "RankingVinos.h"
#include "Lista.h"
#include "infoMensual.h"
#include "vino.h"
#include "cliente.h"
#include "RankingVarietales.h"
#include "string.h"

void rankingDeVarietales(Lista seleccionados, Lista clientes, Lista vinos){
    Lista rankingRango1 = rankingPorRangoEtario(seleccionados, clientes, vinos, 0, 30);
//    ordenarRanking(rankingRango3);
    mostrarRanking(rankingRango1);
    Lista rankingRango2 = rankingPorRangoEtario(seleccionados, clientes, vinos, 30, 50);
//    ordenarRanking(rankingRango3);
    mostrarRanking(rankingRango2);
    Lista rankingRango3 = rankingPorRangoEtario(seleccionados, clientes, vinos, 50, 1000);
//    ordenarRanking(rankingRango3);
    mostrarRanking(rankingRango3);

}
//rankingPorRangoEtario ?
Lista rankingPorRangoEtario(Lista seleccionados, Lista clientes,Lista vinos, int valorEtarioInf, int valorEtarioSup) {
    Lista listaResultante = crearLista();
    Nodo nodoActual = seleccionados->inicio;

    while (nodoActual != NULL){
        infoMesual seleccionActual = (infoMesual) nodoActual->dato;
        int edadClienteActual = traerEdadCliente(clientes, seleccionActual->idUsuario);

        if (edadClienteActual > valorEtarioInf && edadClienteActual < valorEtarioSup){

            agregarNodo(listaResultante, nodoActual);

            Vino vino1 = traerVino(vinos, seleccionActual->idVino1);
            Vino vino2 =traerVino(vinos, seleccionActual->idVino2);
            Vino vino3 =traerVino(vinos, seleccionActual->idVino3);
            Vino vino4 =traerVino(vinos, seleccionActual->idVino4);
            Vino vino5 =traerVino(vinos, seleccionActual->idVino5);
            Vino vino6 =traerVino(vinos, seleccionActual->idVino6);


            agregarVarietal(listaResultante, vino1->varietal);
            agregarVarietal(listaResultante, vino2->varietal);
            agregarVarietal(listaResultante, vino3->varietal);
            agregarVarietal(listaResultante, vino4->varietal);
            agregarVarietal(listaResultante, vino5->varietal);
            agregarVarietal(listaResultante, vino6->varietal);


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
        if(vinoActual->idVino == idBuscado){
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
     std::cout<<"Ranking de varietales:"<<std::endl;
    while(nodoActual != NULL){
            RankingVarietales puestoActual = (RankingVarietales) nodoActual->dato;
            char etiquetaVarietal [50];
             strcpy(puestoActual->varietal,etiquetaVarietal);
            std::cout<<"puesto "<<puestoActual->posicion<<"/t varietal: "<<etiquetaVarietal<<"/t Cant.selecciones: "<<puestoActual->cantidadSelecciones<<std::endl;

            nodoActual = nodoActual->siguiente;
    }

}
