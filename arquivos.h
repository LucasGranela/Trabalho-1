#ifndef ARQUIVOS_H_
#define ARQUIVOS_H_

#include <stdlib.h>
#include <stdio.h>

    FILE* abrirArquivo(char nomearquivo[50], char modo[50]);
    void fechaArquivo(FILE* arquivo);

#endif