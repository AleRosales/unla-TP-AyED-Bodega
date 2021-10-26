#include <iostream>
#include "rankingVinos.h"
#include "lista.h"
#include "infoMensual.h"
#include "vino.h"

using namespace std;

void rankingPorVinos (Lista  seleccionados,Lista vinos){
    Lista ranking = crearLista();
    int cont = 0;
    int ultimo = ultimoAnio();

    for(int b=1; b<= vinos->tamanio ; b++){

        Nodo nodoVino=nodoSeleccionado(vinos,b);
        Vino vino=(Vino)nodoVino->dato;

        for(int i=1; i<= seleccionados->tamanio ; i++){
            Nodo nodoInforMensual=nodoSeleccionado(seleccionados,i);
            infoMesual info = (infoMesual) nodoInforMensual->dato;

            if(getsAnioSeleccion(info) == ultimo){
                if(getsVino1(info)==getsVino(vino) ||getsVino2(info)==getsVino(vino)|| getsVino3(info)==getsVino(vino) ||
                        getsVino4(info)==getsVino(vino) || getsVino5(info)==getsVino(vino) || getsVino6(info)==getsVino(vino)){

                    RankingVinos rankingDato=buscarVino(ranking,getsVino(vino));

                    if (rankingDato!=NULL){
                        rankingDato->cantidadSelecciones+=1;
                    }
                    else
                    {
                        rankingDato=new RankingVinosStruct();
                        rankingDato->cantidadSelecciones=1;
                        rankingDato->vino=vino;
                        agregarNodo(ranking,rankingDato);
                    }
                }
            }
        }
    }

    Lista ordenada=crearLista();
    ordenarListaAux(ranking,ordenada);

    mostrarListaRankigVino(ordenada);

}

RankingVinos buscarVino(Lista lista,int idVino){

    Nodo aux=lista->inicio;
    int encontrado=0;
    while(aux!=NULL && encontrado==0){

        RankingVinos rankig=(RankingVinos) aux->dato;
        Vino vino=rankig->vino;

        if(getsVino(vino)==idVino){
            encontrado=1;
        }
        else
        {
            aux=aux->siguiente;
        }
    }
    if(encontrado==1){
        return (RankingVinos)aux->dato;
    }
    else
    {
        return NULL;
    }
}


void ordenarListaAux(Lista lista, Lista ordenada){
    Nodo actual;
    Nodo siguiente;
    actual=lista->inicio;
    Nodo aux=actual;
    Nodo auxNodo;
    Nodo mostrar;
    int nro;
    int i=1;

    while (actual!=NULL ){
        nro=actual->nro;
        siguiente=actual->siguiente;
        RankingVinos rankig1=(RankingVinos)actual->dato;

        while(siguiente !=NULL ){

        RankingVinos rankig2=(RankingVinos)siguiente->dato;
          if(rankig1->cantidadSelecciones<rankig2->cantidadSelecciones){
                rankig1=rankig2;
                nro=siguiente->nro;
            }
            siguiente=siguiente->siguiente;
        }

        RankingVinos nuevo=new RankingVinosStruct;
        auxNodo=nodoSeleccionado(lista,nro);
        RankingVinos vinoAnt=(RankingVinos)auxNodo->dato;
        nuevo->cantidadSelecciones=vinoAnt->cantidadSelecciones;
        nuevo->posicion=vinoAnt->posicion;
        nuevo->vino=vinoAnt->vino;

        agregarNodo(ordenada,nuevo);
        eliminarNodo(lista,nro);

        actual=lista->inicio;
        i++;

    }

}

void mostrarListaRankigVino(Lista lista){
    int j=1;

    while(j<=lista->tamanio){

    Nodo nodoRanking=nodoSeleccionado(lista,j);
       RankingVinos rankingDato=(RankingVinos)nodoRanking->dato;
       Vino vino1=rankingDato->vino;

        cout <<"Nro en lista:"<<nodoRanking->nro<<" -Vino "<<getsVino(vino1)<<":"<<getsetiqueta(vino1)<<" "<<getsAnioCosecha(vino1)<<" -Cant seleccionada: "<<rankingDato->cantidadSelecciones<<endl;
        j++;
    }
}

void ordenarLista(Lista lista){
    Nodo actual;
    Nodo siguiente;
    Nodo averQueHay;
    actual=lista->inicio;

    Vino aux;
    while (actual!=NULL){
        siguiente=actual->siguiente;
        while( siguiente !=NULL){

            RankingVinos rankig1=(RankingVinos)actual->dato;
            RankingVinos rankig2=(RankingVinos)siguiente->dato;

            if(rankig1->cantidadSelecciones<rankig2->cantidadSelecciones){
                aux=rankig2->vino;
                rankig2->vino=rankig1->vino;
                rankig1->vino=aux;
                int aux =rankig2->cantidadSelecciones;
                rankig2->cantidadSelecciones=rankig1->cantidadSelecciones;
                rankig1->cantidadSelecciones=aux;

            }
            siguiente=siguiente->siguiente;
        }
        actual=actual->siguiente;
    }

}
