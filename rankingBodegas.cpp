#include <iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<fstream>
#include "lista.h"
#include "vino.h"
#include "infoMensual.h"
#include "funcionesCargarArchivos.h"
#include "rankingBodegas.h"
#include "RankingVarietales.h"
using namespace std;

void lstBodegas(Lista vinos, Lista infoSeleccionados)
{
    Lista lista =  crearLista();
    //Guarda los datos de los regiustros catalogo.txt primero en nodos(infoVinos)
    //Y luego en struct Vino
    int ultimo = ultimoAnio();
    for(int j = 1; j <= infoSeleccionados->tamanio; j++)
        {
            Nodo infoMen = nodoSeleccionado(infoSeleccionados,j);
            infoMesual info = (infoMesual) infoMen->dato;
            if(getsAnioSeleccion(info) == ultimo){
            Vino vino1 = traerVino(vinos, getsVino1(info));
            Vino vino2 =traerVino(vinos, getsVino2(info));
            Vino vino3 =traerVino(vinos, getsVino3(info));
            Vino vino4 =traerVino(vinos, getsVino4(info));
            Vino vino5 =traerVino(vinos, getsVino5(info));
            Vino vino6 =traerVino(vinos, getsVino6(info));

            agregarBodega(lista,vino1);
            agregarBodega(lista,vino2);
            agregarBodega(lista,vino3);
            agregarBodega(lista,vino4);
            agregarBodega(lista,vino5);
            agregarBodega(lista,vino6);
            }
        }

     Lista ordenada=crearLista();

    ordenarListaAuxBodega(lista,ordenada);

    cout <<endl<<"Ranking de bodegas:"<<endl;
    for(int b=1; b< ordenada->tamanio+1 ; b++)
    {
        Nodo nodoRanking=nodoSeleccionado(ordenada,b);
        Bodega bod=(Bodega)nodoRanking->dato;
        cout <<"Nro en lista:"<<nodoRanking->nro<<" -Bodega "<<bod->nombreBodega<<" -Cant seleccionada: "<<bod->cant<<endl;
    }
}


Bodega buscarBodega(Lista lista,char nombre[50])
{
    Nodo aux=lista->inicio;
    int encontrado=0;
    while(aux!=NULL && encontrado==0)
    {
        Bodega bodega=(Bodega) aux->dato;
        if(strcmp(bodega->nombreBodega,nombre)==0)
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
        return (Bodega)aux->dato;
    }
    else
    {
        return NULL;
    }
}

void agregarBodega(Lista bodega, Vino vino){

                Bodega bod = buscarBodega(bodega,getsNombreBodega(vino));
                if(bod!=NULL)
                {
                    bod->cant++;
                }
                else
                {
                    bod = new BodegaStruct;
                    bod->cant=1;
                    strcpy(bod->nombreBodega, getsNombreBodega(vino));
                    agregarNodo(bodega,bod);
                }


}

void ordenarListaAuxBodega(Lista lista, Lista ordenada){
    Nodo actual;
    Nodo siguiente;
    actual=lista->inicio;
    Nodo auxNodo;
    int nro;

    while (actual!=NULL )
    {
        nro=actual->nro;
        siguiente=actual->siguiente;
        Bodega auxMaximo=(Bodega)actual->dato;
        while( siguiente !=NULL )
        {
            Bodega rankig13=(Bodega)siguiente->dato;
          if(auxMaximo->cant<rankig13->cant)
            {
            auxMaximo=rankig13;
            nro=siguiente->nro;
            }
            siguiente=siguiente->siguiente;

        }

        Bodega nuevo=new BodegaStruct;
        auxNodo=nodoSeleccionado(lista,nro);
        Bodega bodegaAnt=(Bodega)auxNodo->dato;
        nuevo->cant=bodegaAnt->cant;
        strcpy(nuevo->nombreBodega,bodegaAnt->nombreBodega);

        agregarNodo(ordenada,nuevo);
        eliminarNodo(lista,nro);

        actual=lista->inicio;


    }




}
