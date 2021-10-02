#include <iostream>
#include "Lista.h"
using namespace std;

Lista crearLista(){
    Lista lista=new listaStruct();
    lista->tamanio=0;
    return lista;
}


void agregarNodo(Lista lista,void* dato){
    Nodo newNodo=new nodo();
    newNodo->dato=dato;
    if(lista->tamanio>0){
        int i=1;
        Nodo aux=lista->inicio;
        while(aux->siguiente!=NULL){
            i++;
            aux=aux->siguiente;
        }
        newNodo->nro=(i+1);
        newNodo->siguiente=NULL;
        aux->siguiente=newNodo;
    }else{
        newNodo->nro=1;
        newNodo->siguiente=NULL;
        lista->inicio=newNodo;
    }
    lista->tamanio=(lista->tamanio+1);
}


void eliminarNodo(Lista lista,int nro){
    if(lista->tamanio>0){
        Nodo ant=NULL;
        Nodo aux=lista->inicio;
        int encontrado=0;
        while(aux!=NULL && encontrado==0){
            if(aux->nro==(nro-1)){
                ant=aux;
            }
            if(aux->nro==nro){
                encontrado=1;
            }else{
                aux=aux->siguiente;
            }
        }
        if(encontrado==1){
            if(ant!=NULL){
                ant->siguiente=aux->siguiente;
            }else{
                //elimina el 1ro de la lista
                lista->inicio=aux->siguiente;
            }
            Nodo sig=aux->siguiente;
            while(sig!=NULL){
                sig->nro=(sig->nro-1);
                sig=sig->siguiente;
            }
            delete aux->dato;
            delete aux;
            lista->tamanio=(lista->tamanio-1);
        }else{
            cout << "No se encontro el elemento "<<nro<<" en la lista"<< endl;
        }
    }else{
        cout << "La lista esta vacia"<< endl;
    }
}


void eliminarLista(Lista lista){
    Nodo aux=lista->inicio;
    while(aux!=NULL){
        delete aux->dato;
        delete aux;
        aux=aux->siguiente;
    }
    delete lista;
}

Nodo nodoSeleccionado(Lista lista,int nro){
    Nodo aux=lista->inicio;
    if(aux->nro==nro){
        return aux;
    }
    while(aux!=NULL){
        if(aux->nro==nro){
            return aux;
        }else{
            aux=aux->siguiente;
        }
    }
    cout << "No se encontro el elemento "<<nro<<" en la lista"<< endl;
    return NULL;
}

bool listaVacia(Lista lista){
    if(lista==NULL || lista->tamanio==0 || lista->inicio==NULL){
        return true;
    }else{
        return false;
    }
}

Nodo ultimoNodo(Lista lista){
    Nodo aux=lista->inicio;
    while(aux->siguiente!=NULL){
        aux=aux->siguiente;
    }
    return aux;
}

Nodo anteriorNodo(Lista lista,Nodo nodo){
    Nodo anterior=lista->inicio;
    while(anterior->siguiente!=nodo && anterior->siguiente!=NULL){
        anterior=anterior->siguiente;
    }
    if(anterior->siguiente==nodo){
        return anterior;
    }else{
        cout << "No se encontro el nodo anterior al nodo "<<nodo->nro<<" en la lista"<< endl;
        return NULL;
    }
}

void mostrarLista(Lista lista){
    Nodo nodo=lista->inicio;
    cout << "Nodo nro:"<<nodo->nro<<"  Dato:"<<(nodo->dato)<< endl;
    while(nodo!=NULL){
        cout << "Nodo nro:"<<nodo->nro<<"  Dato:"<<(nodo->dato)<< endl;
        nodo=nodo->siguiente;
    }
}
