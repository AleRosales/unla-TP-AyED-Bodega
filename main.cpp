#include <iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<fstream>
#include "lista.hpp"


using namespace std;

struct cliente{
    int idUsuario;
    char nombre[50];
    char direccion[55];
    int edad;

};

struct vino{
    int idVino;
    char etiqueta[50];
    char bodega [50];
    char segmento_del_vino[50];
    char varietal[50];
    int anioCosecha;
    char terroir[50];

};

struct seleccion{
    int idUsuario;
    int mesSeleccion;
    int anioSeleccion;
    int idVino1;
    int idVino2;
    int idVino3;
    int idVino4;
    int idVino5;
    int idVino6;
};
void leerYpasarAstructConString(Lista clien);
void leerYpasarAseleccion(Lista selec);
void leerYpasaraVinos(Lista vin);


struct cliente pasarCharAStructConString(string texto);
struct vino pasarCharAStructConStringVino(string texto);
struct seleccion pasarCharAstructSeleccion(string texto);

void mostrarClientes(struct cliente);
void mostrarVinos(struct vino v[]);
void mostrarSeleccion(struct seleccion v[]);


int main()
{

    Lista miListaCliente=crearLista();
    Lista miListaVinos=crearLista();
    Lista miListaSeleccion=crearLista();

    leerYpasarAstructConString(miListaCliente);
    leerYpasarAseleccion(miListaSeleccion);
    leerYpasaraVinos(miListaVinos);




    cout << "Hello world!" << endl;
    return 0;
}

void leerYpasarAstructConString(Lista clien){
    ifstream archivo;
    string texto;
    archivo.open("usuarios_test.txt",ios::in);//abrimos el archivo en modo lectura
    int contador=0;

    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }

    while(!archivo.eof()){//mientras no sea el final del archivo
        getline(archivo,texto);
         struct cliente c;
        c= pasarCharAStructConString(texto);
        agregar(clien,&c);
        cout<<"TAmanio clientes"<<getTamanio(clien)<<endl;


    }

    archivo.close();
}

void leerYpasarAseleccion(Lista selec){
     fstream archivo;
     string texto;
    archivo.open("elecion.txt",ios::in);//abrimos el archivo en modo lectura
    int contador=0;

    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }

    while(!archivo.eof()){//mientras no sea el final del archivo
        getline(archivo,texto);
        struct seleccion c;
       c= pasarCharAstructSeleccion(texto);
       agregar(selec,&c);
       cout<<"TAmanio seleccion"<<getTamanio(selec)<<endl;




    }

    archivo.close();

}

void leerYpasaraVinos(Lista vin){
 fstream archivo;
     string texto;
    archivo.open("catalogos.txt",ios::in);//abrimos el archivo en modo lectura
    int contador=0;

    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }

    while(!archivo.eof()){//mientras no sea el final del archivo
        getline(archivo,texto);
        struct vino v;
        v= pasarCharAStructConStringVino(texto);
        agregar(vin,&v);
       cout<<"TAmanio vinos"<<getTamanio(vin)<<endl;


    }

    archivo.close();

}

struct cliente pasarCharAStructConString(string texto){

    int pos=-1;
    int pos2=-1;
    int pos3=-1;


    char auxNombre[30]= " ";
    char auxEdad [50]=" ";
    char idUsuario[30];
    char auxDireccion[90]=" ";

    int longitud= texto.size();

    fflush (stdin);
    for (int i=0;i<longitud;i++)
    {
        if(texto[i]=='-')
        {
            pos=i;

            i=longitud;//termina el for
        }
    }
    for (int i=pos+1;i<longitud;i++)
    {
        if(texto[i]=='-')
        {
            pos2=i;

            i=longitud;//termina el for
        }
    }
    for (int i=pos2+1;i<longitud;i++)
    {
        if(texto[i]=='-')
        {
            pos3=i;

            i=longitud;//termina el for
        }
    }



     for (int i=0;i<pos;i++)
    {
      idUsuario[i]=texto[i];

    }


    for (int i=pos+1;i<pos2;i++)
    {

      auxNombre[i-pos-1]=texto[i];
    }

     for (int i=pos2+1;i<pos3;i++)
    {

      auxDireccion[i-pos2-1]=texto[i];

    }
     for (int i=pos3+1;i<longitud;i++)
    {

      auxEdad[i-pos3-1]=texto[i];
    }


    struct cliente a;

    strcpy(a.nombre,auxNombre);
    strcpy(a.direccion ,auxDireccion);
    a.idUsuario=atoi(idUsuario);

    a.edad = atoi(auxEdad);

    return a;


};
struct vino pasarCharAStructConStringVino(string texto){

    int pos=-1;
    int pos2=-1;
    int pos3=-1;
    int pos4=-1;
    int pos5=-1;
    int pos6=-1;

    char idVino[50]=" ";
    char etiqueta[50]=" ";
    char bodega [50]=" ";
    char segmento_del_vino[50]=" ";
    char varietal[50]=" ";
    char anioCosecha[50]=" ";
    char terroir[50]=" ";


     int longitud= texto.size();

    fflush (stdin);
    for (int i=0;i<longitud;i++)
    {
        if(texto[i]=='-')
        {
            pos=i;

            i=longitud;//termina el for
        }
    }
    for (int i=pos+1;i<longitud;i++)
    {
        if(texto[i]=='-')
        {
            pos2=i;

            i=longitud;//termina el for
        }
    }
    for (int i=pos2+1;i<longitud;i++)
    {
        if(texto[i]=='-')
        {
            pos3=i;

            i=longitud;//termina el for
        }
    }
      for (int i=pos3+1;i<longitud;i++)
    {
        if(texto[i]=='-')
        {
            pos4=i;

            i=longitud;//termina el for
        }
    }
        for (int i=pos4+1;i<longitud;i++)
    {
        if(texto[i]=='-')
        {
            pos5=i;

            i=longitud;//termina el for
        }
    }
    for (int i=pos5+1;i<longitud;i++)
    {
        if(texto[i]=='-')
        {
            pos6=i;

            i=longitud;//termina el for
        }
    }



      for (int i=0;i<pos;i++)
    {
      idVino[i]=texto[i];

    }


    for (int i=pos+1;i<pos2;i++)
    {

      etiqueta[i-pos-1]=texto[i];
    }

     for (int i=pos2+1;i<pos3;i++)
    {

      bodega[i-pos2-1]=texto[i];

    }
     for (int i=pos3+1;i<pos4;i++)
    {

      segmento_del_vino[i-pos3-1]=texto[i];
    }
     for (int i=pos4+1;i<pos5;i++)
    {

      varietal[i-pos4-1]=texto[i];
    }
      for (int i=pos5+1;i<pos6;i++)
    {

      anioCosecha[i-pos5-1]=texto[i];
    }
        for (int i=pos6+1;i<longitud;i++)
    {

      terroir[i-pos6-1]=texto[i];
    }
    struct vino a;

    a.anioCosecha=atoi(anioCosecha);
    a.idVino=atoi(idVino);
    strcpy(a.bodega,bodega);
    strcpy(a.etiqueta,etiqueta);
    strcpy(a.segmento_del_vino,segmento_del_vino);
    strcpy(a.terroir,terroir);
    strcpy(a.varietal,varietal);

    return a;

};
struct seleccion pasarCharAstructSeleccion(string texto){
  int pos=-1;
    int pos2=-1;
    int pos3=-1;
    int pos4=-1;
    int pos5=-1;
    int pos6=-1;
    int pos7=-1;
    int pos8=-1;

    char idUsuario[50]=" ";
    char mesSeleccion[50]=" ";
    char anioSeleccion [50]=" ";
    char idVino1[50]=" ";
    char idVino2[50]=" ";
    char idVino3[50]=" ";
    char idVino4[50]=" ";
    char idVino5[50]=" ";
    char idVino6[50]=" ";

     int longitud= texto.size();

    fflush (stdin);
    for (int i=0;i<longitud;i++)
    {
        if(texto[i]=='-')
        {
            pos=i;

            i=longitud;//termina el for
        }
    }
    for (int i=pos+1;i<longitud;i++)
    {
        if(texto[i]=='-')
        {
            pos2=i;

            i=longitud;//termina el for
        }
    }
    for (int i=pos2+1;i<longitud;i++)
    {
        if(texto[i]=='-')
        {
            pos3=i;

            i=longitud;//termina el for
        }
    }
      for (int i=pos3+1;i<longitud;i++)
    {
        if(texto[i]=='-')
        {
            pos4=i;

            i=longitud;//termina el for
        }
    }
        for (int i=pos4+1;i<longitud;i++)
    {
        if(texto[i]=='-')
        {
            pos5=i;

            i=longitud;//termina el for
        }
    }
    for (int i=pos5+1;i<longitud;i++)
    {
        if(texto[i]=='-')
        {
            pos6=i;

            i=longitud;//termina el for
        }
    }
       for (int i=pos6+1;i<longitud;i++)
    {
        if(texto[i]=='-')
        {
            pos7=i;

            i=longitud;//termina el for
        }
    }
    for (int i=pos7+1;i<longitud;i++)
    {
        if(texto[i]=='-')
        {
            pos8=i;

            i=longitud;//termina el for
        }
    }



      for (int i=0;i<pos;i++)
    {
      idUsuario[i]=texto[i];

    }


    for (int i=pos+1;i<pos2;i++)
    {

      mesSeleccion[i-pos-1]=texto[i];
    }

     for (int i=pos2+1;i<pos3;i++)
    {

      anioSeleccion[i-pos2-1]=texto[i];

    }
     for (int i=pos3+1;i<pos4;i++)
    {

     idVino1[i-pos3-1]=texto[i];
    }
     for (int i=pos4+1;i<pos5;i++)
    {

      idVino2[i-pos4-1]=texto[i];
    }

      for (int i=pos5+1;i<pos6;i++)
    {

      idVino3[i-pos5-1]=texto[i];
    }
        for (int i=pos6+1;i<pos7;i++)
    {

      idVino4[i-pos6-1]=texto[i];
    }
    for (int i=pos7+1;i<pos8;i++)
    {

      idVino5[i-pos7-1]=texto[i];
    }
    for (int i=pos8+1;i<longitud;i++)
    {

      idVino6[i-pos8-1]=texto[i];
    }
    struct seleccion a;

    a.idUsuario=atoi(idUsuario);
    a.mesSeleccion=atoi(mesSeleccion);
    a.anioSeleccion=atoi(anioSeleccion);
    a.idVino1=atoi(idVino1);
    a.idVino2=atoi(idVino2);
    a.idVino3=atoi(idVino3);
    a.idVino4=atoi(idVino4);
    a.idVino5=atoi(idVino5);
    a.idVino6=atoi(idVino6);
    return a;

};

/*
void mostrarClientes(struct cliente){


    {
    cout<<"\n--------DATOS-----------"<<endl;
    cout<<"\nNombre: "<<cliente.nombre<<endl;
    cout<<"\nEdad : "<<cliente.edad<<endl;
    cout<<"\nDireccion : "<<cliente.direccion<<endl;
    cout<<"\nIdusuario : "<<cliente.idUsuario<<endl;

        }
    }
*/


void mostrarVinos(struct vino v[]){
    for(int i=0;i<14;i++)
    {
    cout<<"\n--------DATOS-----------"<<endl;
    cout<<"\nIdVino: "<<v[i].idVino<<endl;
    cout<<"\nEtiqueta : "<<v[i].etiqueta<<endl;
    cout<<"\nBodega: "<<v[i].bodega<<endl;
    cout<<"\nSegmento del vino: "<<v[i].segmento_del_vino<<endl;
    cout<<"\nVarietal: "<<v[i].varietal<<endl;
    cout<<"\nAnio de cosecha: "<<v[i].anioCosecha<<endl;
    cout<<"\nTerroir: "<<v[i].terroir<<endl;
        }

}
void mostrarSeleccion(struct seleccion v[]){
       for(int i=0;i<50;i++){
     cout<<"\n--------DATOS-----------"<<endl;
    cout<<"\nIdUsuario: "<<v[i].idUsuario<<endl;
    cout<<"\nmes: "<<v[i].mesSeleccion<<endl;
    cout<<"\nAnio "<<v[i].anioSeleccion<<endl;
    cout<<"\nVinos "<<v[i].idVino1<<"+"<<v[i].idVino2<<"+"<<v[i].idVino3<<"+"<<v[i].idVino4<<"+"<<v[i].idVino5<<"+"<<v[i].idVino6<<endl;
    }


}
