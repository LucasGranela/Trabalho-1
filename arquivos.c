#include "arquivos.h"

FILE* abrirArquivo(char nomearquivo[50], char modo[3]){
    FILE *arquivo;

    arquivo = fopen(nomearquivo,modo);

    if(arquivo == NULL){
        printf("Falha no carregamento do arquivo.\n");
        return NULL;
    }

    return arquivo;
}

void fechaArquivo(FILE* arquivo){
    fclose(arquivo);    
}
