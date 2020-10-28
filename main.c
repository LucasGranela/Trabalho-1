#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arqIndicePessoa.h"
#include "funcoes-fornecidas/fornecido.h"
#include "funcoesUtilizadas.h"


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
    
    scanf("%d%*c", &caso);
    
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

        //variaveis para leitura e escrita das variaveis
        char nomePessoa[60];
        char twitterPessoa[40];
        char removido = '1';
        int idPessoa, idadePessoa;
        int quantPessoas;

        quantPessoas = 0;

        //lista dinamica para criar o arquivo .index
        Lista* li = cria_lista();
        int RRN;
        int id;

        escreveCabcArqPessoa(arquivoPessoa, 0, '0'); //escreve o cabecalho do arquivoPessoa
        fseek(arquivoEntrada, 45, SEEK_SET); //posicionando a leitura para depois do cabecalho 
        
        while(fscanf(arquivoEntrada, "%d%*c", &idPessoa) == 1){  //enquanto existir id pessoa, podera continuar a leitura
            if(fscanf(arquivoEntrada, "%[^,]", nomePessoa) < 1)  //verifica se o nome e' nulo
                nomePessoa[0] = '\0'; //se for nulo setta como tal 
                
            fscanf(arquivoEntrada, "%*c%d%*c%[^\r]", &idadePessoa, twitterPessoa); //leitura do resto dos dados
            quantPessoas++; //incrementacao da quantidade de pessoas total para atualizar o cabecalho no final do codigo

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
            fwrite(&removido, sizeof(char), 1, arquivoPessoa);
            fwrite(&idPessoa, 4, 1, arquivoPessoa);
            fwrite(nomePessoa, sizeof(char), 40, arquivoPessoa);
            fwrite(&idadePessoa, 4, 1, arquivoPessoa);
            fwrite(twitterPessoa, sizeof(char), 15, arquivoPessoa);

            //cria a lista dinamicamente ordenada dos index
            RRN = quantPessoas - 1;
            id = idPessoa;
            insere_lista_ordenada(li, RRN, id);
        }

        //Abertura do arquivo para gravacao do index
        FILE* arqIndex = fopen(arqIndPessoa, "wb");
        if(arqIndex == NULL){
            printf("Falha no carregamento do arquivo.\n");
            return 0;
        }
        
        escreveCabcArqIndexa(arqIndex, '0'); //escreve cabecalho do arquivo

        for(i = 1; i <= quantPessoas; i++){
            consulta_lista_pos(li, i, &id, &RRN); //id e RRN vao ficar com os valores corretos
            fwrite(&id, sizeof(int), 1, arqIndex);
            fwrite(&RRN, sizeof(int), 1, arqIndex);
        }

        //setta no cabecalho a quantidade de pessoas total do arquivo e reescreve o cabecalho
        escreveCabcArqPessoa(arquivoPessoa, quantPessoas, '1');
        escreveCabcArqIndexa(arqIndex, '1');

        //lebera todos os ponteiros criados dinamicamente
        fclose(arqIndex);
        fclose(arquivoEntrada);
        fclose(arquivoPessoa);
        libera_lista(li);
        
        //funcao de coleta para verificacao do codigo
        binarioNaTela1(arqPessoa,arqIndPessoa);
        
    } else if (caso == 2) {
        //leitura do arq binario que sera usado 
        char nomeArqlido[50];
        scanf("%s", nomeArqlido);
        int i; //utilizacao em for

        FILE* arqBin = fopen(nomeArqlido, "rb");
        if(arqBin == NULL){ //verifica se o programa conseguiu abrir
            printf("Falha no carregamento do arquivo.\n");
            return 0;
        }

        //leitura do status para verificar se o arquivo esta consistente para continuar o codigo
        char status;
        fseek(arqBin, 0, SEEK_SET);
        fread(&status, sizeof(char), 1, arqBin);

        if(status == '0'){
            printf("Falha no carregamento do arquivo.\n");
            fclose(arqBin);
            return 0;
        }

        //leitura e armazenamento da quantidade de dados que o arquivo possui
        int quant_dados;
        fread(&quant_dados, sizeof(int), 1, arqBin);

        //posiciona a leitura para depois do cabecalho
        fseek(arqBin, 64, SEEK_SET);

        //variavel para saber se o arquivo possui algum dado
        int quantEscritos = 0; 

        //for para percorrer todos os dados
        for(i = 0; i <= quant_dados; i++){
            if(imprimeRegistroNaTela(arqBin)) //escreve o dado na tela
                quantEscritos++;
            else
                fseek(arqBin, 63, SEEK_CUR); //pula ponteiro para proximo dado
        }
        
        if(quantEscritos == 0)
            printf("Registro inexistente.\n");

        fclose(arqBin);

    } else if (caso == 3) {
        //variaveis dos arquivos e o campo a ser utilizado
        char nomeArqPessoa[50];
        char nomeArqIndex[50];
        char campo[15]; //idPessoa,nomePessoa,idadePessoa ou twitterPessoa

        //leitura das variaveis 
        scanf("%[^ ]%*c", nomeArqPessoa);
        scanf("%[^ ]%*c", nomeArqIndex);
        scanf("%[^ ]%*c", campo);

        //vai abrir os dois arquivos necessarios e verificar se eles estao de acordo com o necessario
        FILE* arquivoPessoa = fopen(nomeArqPessoa, "rb");
        FILE* arquivoIndexaPessoa = fopen(nomeArqIndex, "rb");

        //verifica se existe um arquivo e se ele abre corretamente
        if(arquivoPessoa == NULL || arquivoIndexaPessoa == NULL){
            printf("Falha no carregamento do arquivo.\n");
            return 0;
        }

        //verifica se o arquivo esta consistente para ser lido
        char statusPessoa;
        char statusIndexaPessoa;
        fseek(arquivoPessoa, 0, SEEK_SET);
        fread(&statusPessoa, sizeof(char), 1, arquivoPessoa);
        fseek(arquivoIndexaPessoa, 0, SEEK_SET);
        fread(&statusIndexaPessoa, sizeof(char), 1, arquivoIndexaPessoa);

        //fecha os arquivos antes do encerramento do programa
        if(statusPessoa == '0' || statusIndexaPessoa == '0'){
            printf("Falha no carregamento do arquivo.\n");
            fclose(arquivoIndexaPessoa);
            fclose(arquivoPessoa);
            return 0;
        }

        //de novo, queria usar o switch case, mas parece que o compilador nao compila direito entao fiz com if else
        if(strcmp(campo, "idPessoa") == 0) {//verifica se o campo escolhido e' o do idPessoa
            int valor; //verifica o id requerido para encontrar o campo 
            scanf("%d", &valor);

            int RRN;
            int id = 0;
            //posiciona o ponteiro do arquivo no id requerido para buscar o RRN certo
            fseek(arquivoIndexaPessoa, 4, SEEK_SET); //primeiro id
            //apesar do primeiro id ser com 8 bytes, se somar esse fseek com o do while da os 8 bytes necessarios 

            while(id < valor){ //passa por todos os id para verificar se ele nao foi excluido
                fseek(arquivoIndexaPessoa, 4, SEEK_CUR); //pula proximo id - pula o campo do RRN
                fread(&id, sizeof(int), 1, arquivoIndexaPessoa); //le id
            } 

            if(id == valor){
                //apos verificar a existencia do dado, procura-se o RRN e faz a busca no arquivoPessoa
                fread(&RRN, sizeof(int), 1, arquivoIndexaPessoa);
                fseek(arquivoPessoa, ((RRN+1)*64), SEEK_SET);
                imprimeRegistroNaTela(arquivoPessoa); //imprime o dado na tela
            } 
            else
                printf("Registro inexistente.\n");
            
            fclose(arquivoIndexaPessoa);
            fclose(arquivoPessoa);

        } else if (strcmp(campo, "idadePessoa") == 0) {
            int valor; //verifica a idade requerida para encontrar o campo 
            scanf("%d", &valor);

            fclose(arquivoIndexaPessoa); //nao sera necessario para esse modo

            int quantRegistros;
            int i;

            fread(&quantRegistros, 4, 1, arquivoPessoa); //Le a quantidade de Registros do arquvo para o loop
            
            fseek(arquivoPessoa, 64, SEEK_SET); //posiciona o ponteiro para dps do cabecalho para comecar o loop
            
            int idade;
            char status;
            int QuantImprimida = 0;

            for(i = 0; i < quantRegistros; i++){
                fread(&status, sizeof(char), 1, arquivoPessoa);
                if(status == '1'){
                    fseek(arquivoPessoa, 44, SEEK_CUR); //posiciona o ponteiro para ler a idade
                    fread(&idade, sizeof(int), 1, arquivoPessoa);
                    
                    if(idade == valor){ //compara a idade
                        fseek(arquivoPessoa, -49, SEEK_CUR); //se a idade for igual ele volta para o comeco do registro para imprimir na tela
                        imprimeRegistroNaTela(arquivoPessoa);
                        QuantImprimida++;
                    }
                    else
                        fseek(arquivoPessoa, 15, SEEK_CUR); //pula para o proximo registro

                }
                else {
                    fseek(arquivoPessoa, 63, SEEK_CUR); //pula para proximo registro
                    quantRegistros++;                   //aumenta na quantidade o resgistro que nao foi contabilizado
                }
            }
            if(QuantImprimida == 0) //NAO possui nenhum arquivo
                printf("Registro inexistente.\n");

            fclose(arquivoPessoa);
        }
        

    } else if (caso == 4) {
        
    } else if (caso == 5) {

    } else {

    }

    return 0;
}