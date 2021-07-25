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
    int tamanhoConteudoSelect = verificaQuantidadePalavras(quantidadePalavras, entradaSeparada, "select");
    int tamanhoConteudoFrom = verificaQuantidadePalavras(quantidadePalavras, entradaSeparada, "from");
    int tamanhoConteudoWhere = verificaQuantidadePalavras(quantidadePalavras, entradaSeparada, "where");                                                          //

    char **conteudoFrom;                                                //
    int tamanhoConteudoFrom = 4;                                        //
    conteudoFrom = malloc(sizeof(char*) * tamanhoConteudoFrom);         // ALOCA MEMÓRIA PARA
    for (int i = 0; i < tamanhoConteudoFrom; i++) {                     // conteudoFrom
        conteudoFrom[i] = malloc(sizeof(char) * 50);                    //
    }                                                                   //

    char **conteudoSelect;                                              //
    int tamanhoConteudoSelect = 4;                                      //
    conteudoSelect = malloc(sizeof(char*) * tamanhoConteudoSelect);     // ALOCA MEMÓRIA PARA   
    for (int i = 0; i < tamanhoConteudoSelect; i++) {                   // conteudoSelect
        conteudoSelect[i] = malloc(sizeof(char) * 50);                  //
    }                                                                   //

    char **conteudoWhere;                                               //
    int tamanhoConteudoWhere = 4;                                       //
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

    char **saida;                                                       //
    int tamanhoSaida = 50;                                              //
    saida = malloc(sizeof(char*) * tamanhoSaida);                       // ALOCA MEMÓRIA PARA
    for (int i = 0; i < tamanhoSaida; i++) {                            // saida
        saida[i] = malloc(sizeof(char) * 50);                           //
    }                                                                   //

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
    for (int selectAtual = 0; selectAtual < tamanhoConteudoSelect; selectAtual++){
        selecionaArquivos(conteudoFrom, tamanhoConteudoFrom, arquivo);  //retorna qual arquivo abrir
        escolheColunas(conteudoSelect, tamanhoConteudoSelect, arquivo, &colunaSelecionada, &selectAtual);
        //abreArquivo(colunaSelecionada, arquivo);
        imprimeColuna(&colunaSelecionada, arquivo);
    }

    // SEMPRE VERIFICAR SE O DICIONÁRIO ESTÁ CERTO
    liberaMemoria(entradaSeparada, quantidadePalavras);     //                          //
    liberaMemoria(conteudoFrom, tamanhoConteudoFrom);       //                          //
    liberaMemoria(conteudoSelect, tamanhoConteudoSelect);   //      LIBERA MEMÓRIA      //
    liberaMemoria(arquivo, tamanhoArquivo);                 //                          //
    liberaMemoria(saida, tamanhoSaida);                     //                          //
    liberaMemoria(conteudoWhere, tamanhoConteudoWhere);     //                          //
}


//select Progs.Sigla, Progs.Nome from Progs where Progs.Nivel = "7"

/* ## O programa se divide em 5 partes principais: ##
 * main
 * recebe entrada
 * abrindo selcionando arquivos
 * comparando campos
 * saída / imprimindo
 */ 
     