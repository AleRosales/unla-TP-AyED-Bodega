#include <iostream>
#include "rankingVinos.h"
#include "lista.h"
#include "infoMensual.h"
#include "vino.h"
#include "RankingVarietales.h"
#include <iomanip>
#include <string.h>


using namespace std;

void rankingPorVinos (Lista  seleccionados,Lista vinos)
{
    Lista ranking = crearLista();
    int ultimo = ultimoAnio();

    for(int i=1; i<= seleccionados->tamanio ; i++)
        {
            Nodo nodoInforMensual=nodoSeleccionado(seleccionados,i);
            infoMesual info = (infoMesual) nodoInforMensual->dato;
            if(getsAnioSeleccion(info) == ultimo){
            Vino vino1 = traerVino(vinos, getsVino1(info));
            Vino vino2 =traerVino(vinos, getsVino2(info));
            Vino vino3 =traerVino(vinos, getsVino3(info));
            Vino vino4 =traerVino(vinos, getsVino4(info));
            Vino vino5 =traerVino(vinos, getsVino5(info));
            Vino vino6 =traerVino(vinos, getsVino6(info));

            agregarVinos(ranking,vino1);
            agregarVinos(ranking,vino2);
            agregarVinos(ranking,vino3);
            agregarVinos(ranking,vino4);
            agregarVinos(ranking,vino5);
            agregarVinos(ranking,vino6);

            }
            }

    Lista ordenada=crearLista();
    ordenarListaAux(ranking,ordenada);

    mostrarListaRankigVino(ordenada);
}

RankingVinos buscarVino(Lista lista,int idVino)
{
    Nodo aux=lista->inicio;
    int encontrado=0;
    while(aux!=NULL && encontrado==0)
    {
        RankingVinos rankig=(RankingVinos) aux->dato;
        Vino vino=rankig->vino;
        if(getsVino(vino)==idVino)
        {
            encontrado=1;
        }
        else
        {
            aux=aux->siguiente;
        }
    }
    if(encontrado==1)
    {
        return (RankingVinos)aux->dato;
    }
    else
    {
        return NULL;
    }
}

void agregarVinos(Lista ranking, Vino vino){

   RankingVinos rankingDato=buscarVino(ranking,getsVino(vino));
                if (rankingDato!=NULL)
                {
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

void ordenarListaAux(Lista lista, Lista ordenada)
{
    Nodo actual;
    Nodo siguiente;
    actual=lista->inicio;

    Nodo auxNodo;

    int nro;
    int i=1;

    while (actual!=NULL )
    {
        nro=actual->nro;
        siguiente=actual->siguiente;
        RankingVinos rankig1=(RankingVinos)actual->dato;
        while( siguiente !=NULL )
        {

            RankingVinos rankig2=(RankingVinos)siguiente->dato;

          if(rankig1->cantidadSelecciones<rankig2->cantidadSelecciones)
            {
                rankig1=rankig2;
                nro=siguiente->nro;
            }
            siguiente=siguiente->siguiente;

        }
        RankingVinos nuevo=new RankingVinosStruct;
        auxNodo=nodoSeleccionado(lista,nro);
        RankingVinos vinoAnt=(RankingVinos)auxNodo->dato;
        nuevo->cantidadSelecciones=vinoAnt->cantidadSelecciones;
        nuevo->vino=vinoAnt->vino;

        agregarNodo(ordenada,nuevo);
        eliminarNodo(lista,nro);

        actual=lista->inicio;
        i++;

    }

}




void mostrarListaRankigVino(Lista lista){
    int j=1;
     cout << setw( 80 ) << setfill( '-' ) << '\n' << setfill( ' ' );
    cout << "| "<< left << setw( 14 ) << "Posicion"<< "|" << right << setw( 1) << " Vino"  << right << setw( 9 )
    << " | " << "Etiqueta"<<right << setw(7)<< "|" << "Anio"<<right << setw(7) << "|"<< "Cantidad Selecionado" << " |"<<endl;
    cout << setw( 80 ) << setfill( '-' ) << '\n' << setfill( ' ' ) << '\n';
    while(j<=lista->tamanio){

        Nodo nodoRanking=nodoSeleccionado(lista,j);
       RankingVinos rankingDato=(RankingVinos)nodoRanking->dato;
       Vino vino1=rankingDato->vino;
        int resultado=strlen(getsetiqueta(vino1)); //cuento El tamaño de la cadena para despues poder restar

        cout <<"Nro en lista: "<<nodoRanking->nro<<" -Vino "<<getsVino(vino1)<< " : "<<getsetiqueta(vino1)<<right << setw(16-resultado)<< ""<<getsAnioCosecha(vino1)<<right << setw(7) << ""<<" Cant seleccionada: "<<rankingDato->cantidadSelecciones<<endl;
        j++;
    }

      cout<<"\n"<<endl;

}
