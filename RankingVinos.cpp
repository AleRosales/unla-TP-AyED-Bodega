#include <iostream>
#include "RankingVinos.h"
#include "Lista.h"
#include "infoMensual.h"
#include "vino.h"

using namespace std;

void rankingPorVinos (Lista  seleccionados,Lista vinos){
    Lista ranking = crearLista();

    for(int b=1; b< vinos->tamanio ; b++){
        Nodo nodoVino=nodoSeleccionado(vinos,b);
        Vino vino=(Vino)nodoVino->dato;
        for(int i=1; i< seleccionados->tamanio ; i++){
            Nodo nodoInforMensual=nodoSeleccionado(seleccionados,i);
            infoMesual info = (infoMesual) nodoInforMensual->dato;
            if(info->idVino1==vino->idVino || info->idVino2==vino->idVino || info->idVino3==vino->idVino ||
               info->idVino4==vino->idVino || info->idVino5==vino->idVino || info->idVino6==vino->idVino ){
                RankingVinos rankingDato=buscarVino(ranking,vino->idVino);
                if (rankingDato!=NULL){
                    rankingDato->cantidadSelecciones+=1;
                }else{
                    rankingDato=new RankingVinosStruct();
                    rankingDato->cantidadSelecciones=1;
                    rankingDato->vino=vino;
                    agregarNodo(ranking,rankingDato);
                }
            }
        }
    }
    cout <<endl<<"Ranking de vinos:"<<endl;
    //mostrar resultado
    for(int b=1; b< ranking->tamanio+1 ; b++){
        Nodo nodoRanking=nodoSeleccionado(ranking,b);
        RankingVinos rankingDato=(RankingVinos)nodoRanking->dato;
        Vino vino=rankingDato->vino;
        cout <<"Nro en lista:"<<nodoRanking->nro<<" -Vino "<<vino->idVino<<":"<<vino->etiqueta<<" "<<vino->anioCosecha<<" -Cant seleccionada: "<<rankingDato->cantidadSelecciones<<endl;
    }
}

RankingVinos buscarVino(Lista lista,int idVino){
    Nodo aux=lista->inicio;
    int encontrado=0;
    while(aux!=NULL && encontrado==0){
        RankingVinos rankig=(RankingVinos) aux->dato;
        Vino vino=rankig->vino;
        if(vino->idVino==idVino){
            encontrado=1;
        }else{
            aux=aux->siguiente;
        }
    }
    if(encontrado==1){
        return (RankingVinos)aux->dato;
    }else{
        return NULL;
    }
}
