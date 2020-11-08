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



int consulta_lista_pos(Lista* li, int pos, int *id, int *rrn ) {
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
        *id = no->idPessoa;
        *rrn = no->RRN;
        return OK;
    }
}

int consulta_lista_id(Lista* li, int id, Elem **el) {
    if (li == NULL)
        return 0;

    Elem *no = *li;

    while (no != NULL && no->idPessoa != id){
        no = no->prox;
    }

    if (no == NULL)
        return ERRO;
    else {
        *el = no;
        return OK;
    }
}

int insere_lista_final(Lista* li, int dt) {
    Elem *no;
    
    if (li == NULL) return ERRO;

    no = (Elem*) malloc(sizeof(Elem));

    if (no == NULL)  return ERRO;

    no->idPessoa = dt;
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

int insere_lista_ordenada(Lista* li, int rrn, int id) {

    if (li == NULL)
        return ERRO;

    Elem *no = (Elem*) malloc(sizeof(Elem));

    if (no == NULL)
        return ERRO;

    no->idPessoa = id;
    no->RRN = rrn;

    if ((*li) == NULL) {  //lista vazia: insere in�cio
        no->prox = NULL;
        no->ant = NULL;
        *li = no;
        return OK;
    }

    else{
        Elem *ante, *atual = *li;

        while (atual != NULL && atual->idPessoa < id) {
            ante = atual;
            atual = atual->prox;
        }

        if (atual == *li) {   //insere in�cio
            no->ant = NULL;
            (*li)->ant = no;
            no->prox = (*li);
            *li = no;
        } else {
            no->prox = ante->prox;
            no->ant = ante;
            ante->prox = no;
            
            if (atual != NULL)
                atual->ant = no;
        }
        return OK;
    }
}


int remove_lista(Lista* li, int dt) {   //TERMINAR
    if (li == NULL)
        return ERRO;

    if ((*li) == NULL)//lista vazia
        return ERRO;

    Elem *no = *li;

    while (no != NULL && no->idPessoa != dt){
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
        printf("idPessoa: %5d # Ant: %p - idPessoa: %p - Prox: %p\n",no->idPessoa,no->ant,no,no->prox);
        no = no->prox;
    }
    printf("-------------- FIM LISTA -----------------\n");
}
