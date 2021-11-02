#include <iostream>
#include "lista.h"
#include "funcionesCargarArchivos.h"
#include "RankingVinos.h"
#include "RankingBodegas.h"
#include "RankingVarietales.h"

using namespace std;

int main(){
    Lista miListaCliente=crearLista();
    Lista miListaVinos=crearLista();
    Lista miListaSeleccion=crearLista();

    leerYpasarAusuarios(miListaCliente);
    leerYpasarAseleccion(miListaSeleccion);
    leerYpasaraVinos(miListaVinos);
    int opcion;
    bool repetir=true;
    do
    {
        system("cls");
        cout<<"\n-----------------------------Menu principal-----------------------------\n"<<endl;
        cout<<"1-Ranking de vinos"<<endl;
        cout<<"2-Ranking de bodegas"<<endl;
        cout<<"3-Ranking de varietales"<<endl;
        cout<<"4- Salir"<<endl;
        cin>>opcion;
        switch(opcion)
        {
        case 1:
            rankingPorVinos(miListaSeleccion,miListaVinos);
            system("pause");
            break;
        case 2:
            lstBodegas(miListaVinos,miListaSeleccion);
            system("pause");
            break;
        case 3:
            rankingDeVarietales(miListaSeleccion,miListaCliente,miListaVinos);
            system("pause");
            break;
        case 4:
            cout<<"Adios!!"<<endl;
            repetir=false;
            break;
        }
    }
    while(repetir);
    return 0;
}
