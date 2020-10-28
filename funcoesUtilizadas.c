#include "funcoesUtilizadas.h"


int imprimeRegistroNaTela(FILE* arquivo){
    //variaveis do arquivo
    char status;
    int idPessoa;
    char nomePessoa[40];
    int idadePessoa;
    char twitterPessoa[15];
    fread(&status, sizeof(char), 1, arquivo);
    if(status == '0') //arquivo logicamente removido
        return 0;// registro logicamente removido = retorna false
    else {
        //leitura dos dados do registro existente
        fread(&idPessoa, sizeof(int), 1, arquivo);
        fread(nomePessoa, sizeof(char), 40, arquivo);
        fread(&idadePessoa, sizeof(int), 1, arquivo);
        fread(twitterPessoa, sizeof(char), 15, arquivo);
        printf("Dados da pessoa de código %d\n", idPessoa);
        if(nomePessoa[0] != '\0')
            printf("Nome: %s\n", nomePessoa);
        else
            printf("Nome: -\n");              
        if(idadePessoa != -1)
            printf("Idade: %d anos\n", idadePessoa);
        else
            printf("Idade: -\n");
        printf("Twitter: %s\n", twitterPessoa);
        printf("\n");
    }
    return 1; //registro ocorreu como esperado = true
}

void escreveCabcArqPessoa(FILE* arquivoPessoa, int quantReg, char status){
    int i;
    fseek(arquivoPessoa, 0, SEEK_SET); //posicionando a escrita para escrever o cabecalho
        
    //como o fwrite pede um ponteiro foi necessario criar vetores de uma posicao
    char cabStatus1 = status;
    char cablixo1[59];
    for(i = 0; i < 59; i++) //escre o vetor lixo inteiro
        cablixo1[i] = '$';
    int quantRegistros = quantReg;

    //escrevendo o cabecalho
    fwrite(&cabStatus1, sizeof(char), 1, arquivoPessoa);
    fwrite(&quantRegistros, sizeof(int), 1, arquivoPessoa);
    fwrite(cablixo1, sizeof(char), 59, arquivoPessoa);
}

void escreveCabcArqIndexa(FILE* arqIndex, char status){
    int i;
    
    //criacao do cabecalho
    char cabStatus2 = status;
    char cablixo2[7];
    
    for(i = 0; i < 7; i++)
        cablixo2[i] = '$';

    fseek(arqIndex, 0, SEEK_SET);
    fwrite(&cabStatus2, 1, 1, arqIndex); //status
    fwrite(cablixo2, 1, 7, arqIndex); //lixo
}

//insere no arquivo pessoas
void inserirArqPessoas(int idPessoa, char nomePessoa[60], int idadePessoa, char twitterPessoa[40], FILE* arquivoPessoa){
    int i;
    int strFinal = 0; // quando for o final da string ele fica um 
    for(i = 0; i < 60; i++){ //funcao para identificar e settar o lixo
        if(strFinal == 1)
            nomePessoa[i] = '$';
        else if(nomePessoa[i] == '\0')
            strFinal = 1;
        else if(i == 39){ //aqui ele ja prepara a variavel para ser salva no tamanho exato do necessario no arquivo
            nomePessoa[i] = '\0';
            strFinal = 1;
            break;
        }
    }

    strFinal = 0; //setando zero de novo para recomecar a verificacao da outra palavra
    for(i = 0; i < 40; i++){
        if(strFinal == 1)
            twitterPessoa[i] = '$';
        else if(twitterPessoa[i] == '\0')
            strFinal = 1;
        else if(i == 14){ //aqui ele ja prepara a variavel para ser salva no tamanho exato do necessario no arquivo
            twitterPessoa[i] = '\0';
            strFinal = 1;
            break;
        }
    }

    char removido = '1';

    //aqui escreve todos os dados no arquivoPessoa.bin 
    fwrite(&removido, sizeof(char), 1, arquivoPessoa);
    fwrite(&idPessoa, 4, 1, arquivoPessoa);
    fwrite(nomePessoa, sizeof(char), 40, arquivoPessoa);
    fwrite(&idadePessoa, 4, 1, arquivoPessoa);
    fwrite(twitterPessoa, sizeof(char), 15, arquivoPessoa);
}
