#ifndef FUNCOESUTILIZADAS_H
#define FUNCOESUTILIZADAS_H

#include <stdio.h>
#include <stdlib.h>

    int imprimeRegistroNaTela(FILE* arquivo); //recebe um arquivo e imprime no modo desejado pelos casos 2 e 3
    void escreveCabcArqPessoa(FILE* arquivo, int quantReg, char status);
    void escreveCabcArqIndexa(FILE* arquivo, char status);


#endif