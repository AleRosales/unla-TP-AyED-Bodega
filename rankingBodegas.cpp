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
using namespace std;

void lstBodegas(Lista catalogo, Lista infoSeleccionados)
{
    Lista lista =  crearLista();
    //Guarda los datos de los regiustros catalogo.txt primero en nodos(infoVinos)
    //Y luego en struct Vino
    for(int i = 1; i < catalogo->tamanio; i++)
    {
        Nodo infoVinos = nodoSeleccionado(catalogo,i);
        Vino vino = (Vino) infoVinos->dato;
        for(int j = 1; j < infoSeleccionados->tamanio; j++)
        {
            Nodo infoMen = nodoSeleccionado(infoSeleccionados,j);
            infoMesual infoMensualDat = (infoMesual) infoMen->dato;
            if(infoMensualDat->idVino1==vino->idVino || infoMensualDat->idVino2==vino->idVino ||
                    infoMensualDat->idVino3==vino->idVino || infoMensualDat->idVino4==vino->idVino ||
                    infoMensualDat->idVino5==vino->idVino || infoMensualDat->idVino6==vino->idVino)
            {
                Bodega bod = buscarBodega(lista,getNombre(vino));
                if(bod!=NULL)
                {
                    bod->cant++;
                }
                else
                {
                    bod = new BodegaStruct;
                    bod->cant=1;
                    strcpy(bod->nombreBodega, vino->bodega);
                    agregarNodo(lista,bod);
                }
            }
        }
    }
    cout <<endl<<"Ranking de bodegas:"<<endl;
    for(int b=1; b< lista->tamanio+1 ; b++)
    {
        Nodo nodoRanking=nodoSeleccionado(lista,b);
        Bodega bod=(Bodega)nodoRanking->dato;
        bod->nombreBodega;
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
