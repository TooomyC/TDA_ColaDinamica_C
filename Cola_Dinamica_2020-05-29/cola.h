#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include "Nodo.h"

void crearCola(Cola* cola);
int encolar(Cola* cola, const void* d, unsigned tamElem);
int desencolar(Cola* cola, void* d, unsigned tamElem);
int frenteDeCola(const Cola* cola, void* d, unsigned tamElem);
int colaVacia(const Cola* cola);
int colaLlena(const Cola* cola, unsigned tamElem);
void vaciarCola(Cola* cola);


#endif // COLA_H_INCLUDED
