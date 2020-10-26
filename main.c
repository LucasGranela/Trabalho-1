#include <stdio.h>
#include <stdlib.h>

#include "arquivos.h"
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
    
    scanf("%d", &caso);

    switch (caso)
    {
    case 1:
        printarTeste();
        break;
    case 2:
        /* code */
        break;
    case 3:
        /* code */
        break;
    case 4:
        /* code */
        break;
    case 5:
        /* code */
        break;    
    default:
        break;
    }


    binarioNaTela1("teste1","teste2");

    return 0;
}