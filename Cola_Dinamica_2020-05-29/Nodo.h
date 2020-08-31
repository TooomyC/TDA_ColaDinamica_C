#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

typedef struct SNodo
{
    void* dato;
    unsigned tamElem; //Tamanio del dato
    struct SNodo* sig; //Puntero nodo

} Nodo;

#endif // NODO_H_INCLUDED
