#include <iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<fstream>
#include "funcionesCargarArchivos.h"
#include "infoMensual.h"
#include "vino.h"
#include "cliente.h"
#include "lista.h"


using namespace std;

void leerYpasarAusuarios(Lista clien){
    ifstream archivo;
    string texto;
    archivo.open("usuarios_test.txt",ios::in);//abrimos el archivo en modo lectura


    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }

    while(!archivo.eof()){//mientras no sea el final del archivo

        getline(archivo,texto);
        Cliente c;
        c= pasarCharAStructConStringUsuario(texto);

        agregarNodo(clien,c);
    }

    archivo.close();
}

void leerYpasarAseleccion(Lista selec){
     fstream archivo;
     string texto;
    archivo.open("elecion.txt",ios::in);//abrimos el archivo en modo lectura


    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }

    while(!archivo.eof()){//mientras no sea el final del archivo
        getline(archivo,texto);
        infoMesual c;
       c= pasarCharAstructSeleccion(texto);
       agregarNodo(selec,c);
    }

    archivo.close();

}

void leerYpasaraVinos(Lista vin){
 fstream archivo;
     string texto;
    archivo.open("catalogos.txt",ios::in);//abrimos el archivo en modo lectura


    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }

    while(!archivo.eof()){//mientras no sea el final del archivo
        getline(archivo,texto);
        Vino v;
        v= pasarCharAStructConStringVino(texto);
        agregarNodo(vin,v);

    }

    archivo.close();

}



Cliente  pasarCharAStructConStringUsuario(string texto){
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
    Cliente cli=crearCiente();

    setsNombre(cli,auxNombre);
    setsDireccion(cli,auxDireccion);
    setsIdusuario(cli,atoi(idUsuario));
    setsEdad(cli,atoi(auxEdad));

    return cli;
}

Vino  pasarCharAStructConStringVino(string texto){

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
    Vino vi=crearVino();

    setsAnioCosecha(vi,atoi(anioCosecha));
    setsIdVino(vi,atoi(idVino));
    setsBodega(vi,bodega);
    setsEtiqueta(vi,etiqueta);
    setsSegmentoVino(vi,segmento_del_vino);
    setsTerroir(vi,terroir);
    setsVarietal(vi,varietal);


    return vi;

};


infoMesual  pasarCharAstructSeleccion(string texto){

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
    infoMesual selec=crearInfoMensual();

    setsIdusuario(selec,atoi(idUsuario));
    setsMesSeleccion(selec,atoi(mesSeleccion));
    setsAnioSeleccion(selec,atoi(anioSeleccion));
    setsIdVino1(selec,atoi(idVino1));
    setsIdVino2(selec,atoi(idVino2));
    setsIdVino3(selec,atoi(idVino3));
    setsIdVino4(selec,atoi(idVino4));
    setsIdVino5(selec,atoi(idVino5));
    setsIdVino6(selec,atoi(idVino6));


    return selec;

};
