#ifndef ARQINDICEPESSOA_H
#define ARQINDICEPESSOA_H

#define FALSO      0
#define VERDADEIRO 1

#define OK         1
#define ERRO       0


typedef int Tipo_Dado;

struct elemento{
    struct elemento *ant;
    Tipo_Dado dado;
    struct elemento *prox;
};

typedef struct elemento Elem;
typedef struct elemento* Lista;

Lista* cria_lista();
void libera_lista(Lista* li);
int consulta_lista_pos(Lista* li, int pos, Tipo_Dado *dt);
int consulta_lista_dado(Lista* li, Tipo_Dado dt, Elem **el);
int insere_lista_final(Lista* li, Tipo_Dado dt);
int remove_lista(Lista* li, Tipo_Dado dt);
int tamanho_lista(Lista* li);
void imprime_lista(Lista* li);

#endif