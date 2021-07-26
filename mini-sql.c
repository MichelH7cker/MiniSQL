#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "entrada.h"
#include "arquivos.h"
#include "comparacao.h"
#include "saida.h"

int main(){
    char entrada[100];
    fgets(entrada, 100, stdin);
    char entradaSemVirgula[100];
    filtraEntrada(entrada, entradaSemVirgula);

    int quantidadePalavras = verificaQuantidadePalavrasTotal(entradaSemVirgula);

    char **entradaSeparada;                                             //
    entradaSeparada = malloc(sizeof(char*) * (quantidadePalavras));     // ALOCA MEMÓRIA PARA
    for (int i = 0; i < quantidadePalavras; i++) {                      // entradaSeparada
        entradaSeparada[i] = malloc(sizeof(char) * 50);                 //
    }                                                                   //
    
    separaEntrada(entradaSemVirgula, entradaSeparada);

    int tamanhoConteudoSelect = verificaQuantidadePalavrasSelect(entradaSeparada);
    int tamanhoConteudoFrom = verificaQuantidadePalavrasFrom(quantidadePalavras, entradaSeparada);
    int tamanhoConteudoWhere = verificaQuantidadePalavrasWhere(quantidadePalavras, tamanhoConteudoSelect, tamanhoConteudoFrom); 

    char **conteudoSelect;                                              //
    conteudoSelect = malloc(sizeof(char*) * tamanhoConteudoSelect);     // ALOCA MEMÓRIA PARA   
    for (int i = 0; i < tamanhoConteudoSelect; i++) {                   // conteudoSelect
        conteudoSelect[i] = malloc(sizeof(char) * 50);                  //
    }                                                                   //

    char **conteudoFrom;                                                //
    conteudoFrom = malloc(sizeof(char*) * tamanhoConteudoFrom);         // ALOCA MEMÓRIA PARA
    for (int i = 0; i < tamanhoConteudoFrom; i++) {                     // conteudoFrom
        conteudoFrom[i] = malloc(sizeof(char) * 50);                    //
    }                                                                   //

    char **conteudoWhere;                                               //
    conteudoWhere = malloc(sizeof(char*) * tamanhoConteudoWhere);       // ALOCA MEMÓRIA PARA   
    for (int i = 0; i < tamanhoConteudoWhere; i++) {                    // conteudoWhere
        conteudoWhere[i] = malloc(sizeof(char) * 50);                   //
    }                                                                   //

    char **arquivo;                                                     //
    int tamanhoArquivo = 1;                                             //
    arquivo = malloc(sizeof(char*) * tamanhoArquivo);                   // ALOCA MEMÓRIA PARA
    for (int i = 0; i < tamanhoArquivo; i++) {                          // arquivo
        arquivo[i] = malloc(sizeof(char) * 50);                         //
    }                                                                   //

    char ***saida;
    saida = malloc(sizeof(char**) * tamanhoConteudoSelect);
    for (int i = 0; i < 2; i++) {
        saida[i] = malloc(sizeof(char*) * 100);
        for (int t = 0; t < 5; t++) {
            saida[i][t] = malloc(sizeof(char) * 100);
        }
    }

    int colunaSelecionada;  
    // transformar num array e fazer um contandor na entrada no select

    mostraEntradaSeparada(entradaSeparada, quantidadePalavras);

    completaConteudoArray (conteudoFrom, tamanhoConteudoFrom);                                           //                     
    armazenaConteudoFrom  (conteudoFrom, entradaSeparada, tamanhoConteudoFrom, quantidadePalavras);      //
    completaConteudoArray (conteudoSelect, tamanhoConteudoSelect);                                       //
    armazenaConteudoSelect(conteudoSelect, entradaSeparada, tamanhoConteudoSelect);                      //
    completaConteudoArray (conteudoWhere, tamanhoConteudoWhere);                                         //
    armazenaConteudoWhere (conteudoWhere, entradaSeparada, tamanhoConteudoWhere, quantidadePalavras);    //                                                                 

    //Select campo1, campo2, campo3
    int posicaoFrom = 0;
    saida[100][tamanhoConteudoSelect];
    int colunaAtualMatriz = 0;
    for (int selectAtual = 0; selectAtual < tamanhoConteudoSelect; selectAtual++){
        selecionaArquivos(conteudoFrom, tamanhoConteudoFrom, arquivo, posicaoFrom);  //retorna qual arquivo abrir
        if ((strcmp(arquivo[0], "none")) == 0){ break;}

        escolheColunas(conteudoSelect, tamanhoConteudoSelect, arquivo, &colunaSelecionada, &selectAtual);
        abreArquivo(colunaSelecionada, arquivo, saida, colunaAtualMatriz);
        
        colunaAtualMatriz++;
        posicaoFrom++;
    }
    
    preencheComNone(saida, tamanhoConteudoSelect);
    mostraMatriz(saida, tamanhoConteudoSelect);
    //imprimeSaida(&colunaSelecionada, arquivo);

    liberaMemoria(entradaSeparada, quantidadePalavras);     //                          //
    liberaMemoria(conteudoFrom, tamanhoConteudoFrom);       //                          //
    liberaMemoria(conteudoSelect, tamanhoConteudoSelect);   //      LIBERA MEMÓRIA      //
    liberaMemoria(arquivo, tamanhoArquivo);                 //                          //
    liberaMemoria(conteudoWhere, tamanhoConteudoWhere);     //                          //
    liberaMemoriaRobusta(saida, tamanhoConteudoSelect);     //                          //
}



/* 

##### O programa se divide em 5 partes principais: ######
 * main
 * recebe entrada
 * abrindo selcionando arquivos
 * comparando campos
 * saída / imprimindo
 
*/ 
     