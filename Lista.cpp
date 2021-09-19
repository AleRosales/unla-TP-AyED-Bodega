#include <iostream>
#include "Lista.h"
using namespace std;

Lista crearLista(){
    Lista lista=new listaStruct();
    setTamanio(lista,0);
    return lista;
}


void agregar(Lista lista,void* dato){
    Nodo newNodo=new nodo();
    setDato(newNodo,dato);
    if(getTamanio(lista)>0){
        int i=1;
        Nodo aux=getInicio(lista);
        while(getSiguiente(aux)!=NULL){
            i++;
            aux=aux->siguiente;
        }
        setNro(newNodo,(i+1));
        setSiguiente(newNodo,NULL);
        setSiguiente(aux,newNodo);
    }else{
        setNro(newNodo,1);
        setSiguiente(newNodo,NULL);
        setInicio(lista,newNodo);
    }
    setTamanio(lista,(getTamanio(lista)+1));
}


void eliminar(Lista lista,int nro){
    if(getTamanio(lista)>0){
        Nodo ant=NULL;
        Nodo aux=getInicio(lista);
        int encontrado=0;
        while(aux!=NULL && encontrado==0){
            if(getNro(aux)==(nro-1)){
                ant=aux;
            }
            if(getNro(aux)==nro){
                encontrado=1;
            }else{
                aux=getSiguiente(aux);
            }
        }
        if(encontrado==1){
            if(ant!=NULL){
                setSiguiente(ant,getSiguiente(aux));
            }else{
                //elimina el 1ro de la lista
                setInicio(lista,getSiguiente(aux));
            }
            Nodo sig=getSiguiente(aux);
            while(sig!=NULL){
                setNro(sig,getNro(sig)-1);
                sig=getSiguiente(sig);
            }
            delete getDato(aux);
            delete aux;
            setTamanio(lista,(getTamanio(lista)-1));
        }else{
            cout << "No se encontro el elemento "<<nro<<" en la lista"<< endl;
        }
    }else{
        cout << "La lista esta vacia"<< endl;
    }
}


void eliminarLista(Lista lista){
    Nodo aux=getInicio(lista);
    while(aux!=NULL){
        delete getDato(aux);
        delete aux;
        aux=getSiguiente(aux);
    }
    delete lista;
}


void setNro(Nodo nodo,int nro){
    nodo->nro=nro;
}
void setDato(Nodo nodo,void* dato){
    nodo->dato=dato;
}
void setSiguiente(Nodo nodo,Nodo sig){
    nodo->siguiente=sig;
}
int getNro(Nodo nodo){
    return nodo->nro;
}
void* getDato(Nodo nodo){
    return nodo->dato;
}
Nodo getSiguiente(Nodo nodo){
    return nodo->siguiente;
}

int getTamanio(Lista lista){
    return lista->tamanio;
}


Nodo getInicio(Lista lista){
    return lista->inicio;
}


void setTamanio(Lista lista,int tamanio){
    lista->tamanio=tamanio;
}


void setInicio(Lista lista,Nodo nodo){
    lista->inicio=nodo;
}
