#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <colaDinamica.h> ///En este orden!
#include <cola.h>

#define CANT_CADS 8
#define TAM_CAD 7

int main()
{
    char vCad [CANT_CADS][TAM_CAD] = {"Algo","Para","Decir","No","Se", "Me", "Ocurre", "Nada"};

    Cola cola;

    crearCola(&cola);

    for(int i = 0; i < CANT_CADS; i++)
        encolar(&cola, vCad[i], strlen(vCad[i]) + 1);

    char cad[TAM_CAD];

    while(!colaVacia(&cola))
    {
       desencolar(&cola, cad, TAM_CAD);
       puts(cad);
    }

    return 0;
}
