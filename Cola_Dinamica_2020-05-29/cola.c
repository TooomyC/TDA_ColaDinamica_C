#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <colaDinamica.h>
#include "cola.h"

#define FALSO 0
#define VERDADERO 1

#define minimo(X, Y) ((X) < (Y) ? (X) : (Y))
#define maximo(X, Y) ((X) > (Y) ? (X) : (Y))

void crearCola(Cola* cola)
{
    cola->frente = cola->fondo = NULL;
}

int encolar(Cola* pcola, const void* d, unsigned tamElem)
{
    Nodo* nue = (Nodo*)malloc(sizeof(Nodo));

    if(!nue)
        return FALSO;

    nue->dato = malloc(tamElem);

    if(!nue->dato)
    {
        free(nue);
        return FALSO;
    }

    memcpy(nue->dato, d, tamElem);
    nue->tamElem = tamElem;
    nue->sig = NULL;

    if(pcola->fondo) ///no vacia
        pcola->fondo->sig = nue; ///(1)
    else
    pcola->frente = nue; ///(3)

    pcola->fondo = nue; ///(2)

    return VERDADERO;
}


int desencolar(Cola* pcola, void* d, unsigned tamElem)
{
    if(!pcola->frente)
        return FALSO;

    Nodo* nae = pcola->frente; ///(1)

    memcpy(d, nae->dato, minimo(nae->tamElem, tamElem));

    pcola->frente = nae->sig; ///(2)

    if(!pcola->frente)
        pcola->fondo = NULL;

    free(nae->dato);
    free(nae);

    return VERDADERO;
}


int frenteDeCola(const Cola* pcola, void* d, unsigned tamElem)
{
    if(!pcola->frente)
        return FALSO;

    Nodo* n = pcola->frente; ///(1)

    memcpy(d, n->dato, minimo(n->tamElem, tamElem));

    return VERDADERO;
}


int colaVacia(const Cola* pcola)
{
    return !pcola->frente; //pcola->frente == NULL;
}


int colaLlena(const Cola* pcola, unsigned tamElem)
{
    void* p = malloc(sizeof(Nodo));

    if(!p)
        return VERDADERO;

    p = malloc(tamElem);

    free(p);

    return !p; //p == NULL;
}

void vaciarCola(Cola* pcola)
{
    Nodo* nae;

    while(pcola->frente)
    {
        nae = pcola->frente; ///(1)
        pcola->frente = nae->sig; ///(2)

        free(nae->dato);
        free(nae);
    }

    pcola->fondo = NULL;
}
