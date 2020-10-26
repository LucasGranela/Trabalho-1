#ifndef ARQINDICEPESSOA_H
#define ARQINDICEPESSOA_H

typedef int Tipo_Dado;

struct elemento{
    struct elemento *ant;
    Tipo_Dado dado;
    struct elemento *prox;
};

typedef struct elemento Elem;
typedef struct elemento* Lista;


#endif