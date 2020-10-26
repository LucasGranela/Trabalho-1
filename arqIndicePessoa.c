#include "arqIndicePessoa.h"

#include <stdio.h>
#include <stdlib.h>

Lista* cria_lista() {
    Lista* li = (Lista*) malloc(sizeof(Lista));

    if (li != NULL)
        *li = NULL;

    return li;
}



void libera_lista(Lista* li) {
    if (li != NULL) {
        Elem* no;

        while ((*li) != NULL) {
            no = *li;
            *li = (*li)->prox;

            free(no);
        }

        free(li);
    }
}



int consulta_lista_pos(Lista* li, int pos, Tipo_Dado *dt) {
    if (li == NULL || pos <= 0)
        return ERRO;
    
    Elem *no = *li;

    int i = 1;

    while (no != NULL && i < pos){
        no = no->prox;
        i++;
    }

    if (no == NULL)
        return ERRO;
    else {
        *dt = no->dado;
        return OK;
    }
}

int consulta_lista_dado(Lista* li, Tipo_Dado dt, Elem **el) {
    if (li == NULL)
        return 0;

    Elem *no = *li;

    while (no != NULL && no->dado != dt){
        no = no->prox;
    }

    if (no == NULL)
        return ERRO;
    else {
        *el = no;
        return OK;
    }
}

int insere_lista_final(Lista* li, Tipo_Dado dt) {
    Elem *no;
    
    if (li == NULL) return ERRO;

    no = (Elem*) malloc(sizeof(Elem));

    if (no == NULL)  return ERRO;

    no->dado = dt;
    no->prox = NULL;

	if ((*li) == NULL) {   //lista vazia: insere in�cio
        no->ant = NULL;
        *li = no;
    } else {
        Elem *aux;
        aux = *li;
        
        while (aux->prox != NULL){
            aux = aux->prox;
        }

        aux->prox = no;
        no->ant = aux;
    }

    return OK;
}


int remove_lista(Lista* li, Tipo_Dado dt) {   //TERMINAR
    if (li == NULL)
        return ERRO;

    if ((*li) == NULL)//lista vazia
        return ERRO;

    Elem *no = *li;

    while (no != NULL && no->dado != dt){
        no = no->prox;
    }

    if (no == NULL)//n�o encontrado
        return ERRO;

    if (no->ant == NULL)//remover o primeiro?
        *li = no->prox;
    else
        no->ant->prox = no->prox;

    if (no->prox != NULL)//n�o � o �ltimo?
        no->prox->ant = no->ant;

    free(no);
    
    return OK;

}

int tamanho_lista(Lista* li) {
    if (li == NULL)
        return 0;

    int cont = 0;

    Elem* no = *li;

    while (no != NULL){
        cont++;
        no = no->prox;
    }

    return cont;
}

void imprime_lista(Lista* li) {
    Elem* no = *li;

    if (li == NULL)
        return;

    while (no != NULL) {
        printf("Dado: %5d # Ant: %p - Dado: %p - Prox: %p\n",no->dado,no->ant,no,no->prox);
        no = no->prox;
    }
    printf("-------------- FIM LISTA -----------------\n");
}
