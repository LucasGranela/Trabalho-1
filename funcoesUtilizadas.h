#ifndef FUNCOESUTILIZADAS_H
#define FUNCOESUTILIZADAS_H

#include <stdio.h>
#include <stdlib.h>

    int imprimeRegistroNaTela(FILE* arquivo); //recebe um arquivo e imprime no modo desejado pelos casos 2 e 3
    void escreveCabcArqPessoa(FILE* arquivo, int quantReg, char status);
    void escreveCabcArqIndexa(FILE* arquivo, char status);
    void inserirArqPessoas(int idPessoa, char nomePessoa[60], int idadePessoa, char twitterPessoa[40], FILE* arquivoPessoa);
    int verificaConsistencia(FILE* arquivo);
    int retornaRRN(FILE* arquivo);

#endif