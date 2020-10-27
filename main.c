#include <stdio.h>
#include <stdlib.h>

#include "arqIndicePessoa.h"
#include "funcoes-fornecidas/fornecido.h"


int main (){
    /*
    * O programa possui 5 tipos de entrada: 
    *   caso 1: ler arquivos em formato csv e gravar em arquivos de dados de saida 
    *   
    *   caso 2: recuperar os dados do arquivo pessoa e mostrar de forma organizada
    * 
    *   caso 3: busca por determinado usuario
    *   
    *   caso 4: insercao de registro adicionais
    * 
    *   caso 5: atualizacao dos campos 
    */

    int caso;
    
    scanf("%d ", &caso);
    
    //TENTEI FAZER COM SWITCH CASE, MAS DEU 
    //"a label can only be part of a statement and a declaration is not a statement"
    //entao fiz com if else mesmo, depois se vc conseguir arrumar eu agradeco

    if(caso == 1){
        char nomeArquivolido[50];
        char arqPessoa[50];
        char arqIndPessoa[50];
        
        int i;

        //leitura dos arquivos a serem lidos
        scanf("%[^ ]%*c", nomeArquivolido);
        scanf("%[^ ]%*c", arqPessoa);
        scanf("%s", arqIndPessoa);

        //pelo arquivo csv poder ser muito grande, sera necessario ler um por um e salvando no arquivo Pessoas
        
        FILE* arquivoEntrada = fopen(nomeArquivolido, "r"); //abrindo arquivo de entrada de dados
        FILE* arquivoPessoa = fopen(arqPessoa, "wb");   //abrindo o arquivo que serao salvados os dados

        if(arquivoPessoa == NULL || arquivoEntrada == NULL){ //verificando se os arquivos foram corretamente abertos
            printf("Falha no carregamento do arquivo.\n");
            return 0;
        }

        fseek(arquivoEntrada, 45, SEEK_SET); //posicionando a leitura para depois do cabecalho 

        fseek(arquivoPessoa, 0, SEEK_SET); //posicionando a escrita para escrever o cabecalho
        
        //como o fwrite pede um ponteiro foi necessario criar vetores de uma posicao
        char cabStatus1[1] = {'0'};
        char cablixo1[59];
        for(i = 0; i < 59; i++)
            cablixo1[i] = '$';
        int cab[1] = {0};

        //escrevendo o cabecalho
        fwrite(cabStatus1, sizeof(char), 1, arquivoPessoa);
        fwrite(cab, sizeof(int), 1, arquivoPessoa);
        fwrite(cablixo1, sizeof(char), 59, arquivoPessoa);

        //variaveis para leitura e escrita das variaveis
        char nomePessoa[60];
        char twitterPessoa[40];
        char removido[1] = {'1'};
        int idPessoa[1], idadePessoa[1];
        int quantPessoas[1];

        quantPessoas[0] = 0;

        

        //lista dinamica para criar o arquivo .index
        Lista* li = cria_lista();
        int RRN;
        int id;

        while(fscanf(arquivoEntrada, "%d%*c", idPessoa) == 1){  //enquanto existir id pessoa, podera continuar a leitura
            if(fscanf(arquivoEntrada, "%[^,]", nomePessoa) < 1)  //verifica se o nome e' nulo
                nomePessoa[0] = '\0'; //se for nulo setta como tal 
                
            fscanf(arquivoEntrada, "%*c%d%*c%[^\r]", idadePessoa, twitterPessoa); //leitura do resto dos dados
            quantPessoas[0] ++; //incrementacao da quantidade de pessoas total para atualizar o cabecalho no final do codigo

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

            //aqui escreve todos os dados no arquivoPessoa.bin 
            fwrite(removido, sizeof(char), 1, arquivoPessoa);
            fwrite(idPessoa, 4, 1, arquivoPessoa);
            fwrite(nomePessoa, sizeof(char), 40, arquivoPessoa);
            fwrite(idadePessoa, 4, 1, arquivoPessoa);
            fwrite(twitterPessoa, sizeof(char), 15, arquivoPessoa);

            //cria a lista dinamicamente ordenada dos index
            RRN = quantPessoas[0] - 1;
            id = idPessoa[0];
            insere_lista_ordenada(li, RRN, id);
        }

        //Abertura do arquivo para gravacao do index
        FILE* arqIndex = fopen(arqIndPessoa, "wb");
        if(arqIndex == NULL){
            printf("Falha no carregamento do arquivo.\n");
            return 0;
        }

        //criacao do cabecalho
        char cabStatus2[1] = {'0'};
        char cablixo2[7];
        for(i = 0; i < 7; i++)
            cablixo2[i] = '$';

        fseek(arqIndex, 0, SEEK_SET);
        fwrite(cabStatus2, 1, 1, arqIndex); //status
        fwrite(cablixo2, 1, 7, arqIndex); //lixo

        for(i = 1; i <= quantPessoas[0]; i++){
            consulta_lista_pos(li, i, &id, &RRN); //id e RRN vao ficar com os valores corretos
            fwrite(&id, sizeof(int), 1, arqIndex);
            fwrite(&RRN, sizeof(int), 1, arqIndex);
        }

        //setta no cabecalho a quantidade de pessoas total do arquivo
        fseek(arquivoPessoa, 1, SEEK_SET);
        fwrite(quantPessoas, 4, 1, arquivoPessoa);

        //apos modificado todo o arquivo setta o status do cabecalho para 1 novamente para dizer que ele esta finalizado e consistente
        cabStatus1[0] = '1';
        fseek(arquivoPessoa, 0, SEEK_SET); //cabecalho do arquivo Pessoa
        fwrite(cabStatus1, 1, 1, arquivoPessoa);
        fseek(arqIndex, 0, SEEK_SET); //cabecalho do arquivo IndexaPessoa
        fwrite(cabStatus1, 1, 1, arqIndex);


        //lebera todos os ponteiros criados dinamicamente
        fclose(arqIndex);
        fclose(arquivoEntrada);
        fclose(arquivoPessoa);
        libera_lista(li);
        
        //funcao de coleta para verificacao do codigo
        binarioNaTela1(arqPessoa,arqIndPessoa);
    } else if (caso == 2) {
        
    } else if (caso == 3) {

    } else if (caso == 4) {
        
    } else if (caso == 5) {

    } else {

    }

    return 0;
}