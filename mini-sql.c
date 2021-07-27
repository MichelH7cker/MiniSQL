#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "entrada.h"
#include "arquivos.h"
#include "saida.h"
#include "comparacao.h"
#include "memoria.h"

#define COLUNASPROGS 7       //
#define COLUNASDOCENTES 6    // QUANTIDADE DE COLUNAS DE CADA ARQUIVO
#define COLUNASTRABALHOS 5   //

#define LINHASAIDA 102       // LINHAS TOTAIS DA MATRIZ DE SAÍDA

int main(){
    char entrada[100];
    fgets(entrada, 100, stdin);
    char entradaSemVirgula[100];
    filtraEntrada(entrada, entradaSemVirgula);

    int quantidadePalavras = verificaQuantidadePalavrasTotal(entradaSemVirgula);

    int charEntradaSeparada = 50;
    char **entradaSeparada;   
    alocaMemoria(entradaSeparada, quantidadePalavras, charEntradaSeparada);
    separaEntrada(entradaSemVirgula, entradaSeparada);

    int tamanhoComandoSelect = verificaQuantidadePalavrasSelect(entradaSeparada);
    int tamanhoComandoFrom   = verificaQuantidadePalavrasFrom(quantidadePalavras, entradaSeparada);
    int tamanhoComandoWhere  = verificaQuantidadePalavrasWhere(quantidadePalavras, tamanhoComandoSelect, tamanhoComandoFrom); 

    char **comandoWhere;                                                 
    int charComandoWhere = 50;
    alocaMemoria(comandoWhere, tamanhoComandoWhere, charComandoWhere);                                                      
    

    char **arquivo;                                                   
    int tamanhoArquivo = 1;     
    int charTamanhoArquivo = 10;
    alocaMemoria(arquivo, tamanhoArquivo, charTamanhoArquivo);                                                                                               

    char ***saida; 
    int linhasMatrizRobusta = LINHASAIDA;
    int charTamanhoMatrizRobusta = 100;
    alocaMemoriaRobusta(saida, linhasMatrizRobusta, charTamanhoMatrizRobusta);

    ocupaConteudoSaida(saida, tamanhoComandoSelect);
    
    //mostraEntradaSeparada(entradaSeparada, quantidadePalavras);
    
    completaConteudoArray(comandoWhere, tamanhoComandoWhere);                                        
    armazenaComandoWhere(comandoWhere, entradaSeparada, tamanhoComandoWhere, quantidadePalavras);  

    int linhasIguais[101];
    verificaLinhasPermitidas(comandoWhere, tamanhoComandoWhere, linhasIguais);

    liberaMemoria(comandoWhere, tamanhoComandoWhere);     
    
    int colunaEscolhida;
    int colunaAtualMatriz = 0;
    char ordemSaida[tamanhoComandoFrom][30];
    for (int selectAtual = 0; selectAtual < tamanhoComandoSelect; selectAtual++){
        char **comandoSelect;   
        int charTamanhoSelect = 30;                                                                                                                                                               
        alocaMemoria(comandoSelect, tamanhoComandoSelect, charTamanhoSelect);

        completaConteudoArray (comandoSelect, tamanhoComandoSelect);                                      
        armazenaComandoSelect(comandoSelect, entradaSeparada, tamanhoComandoSelect);

        selecionaArquivoColuna(comandoSelect, tamanhoComandoSelect, arquivo, selectAtual, &colunaEscolhida);
        liberaMemoria(comandoSelect, tamanhoComandoSelect);
        
        if (strcmp(arquivo[0], "none") == 0) break; 

        abreArquivo(colunaEscolhida, arquivo, saida, colunaAtualMatriz);

        colunaAtualMatriz++;
    }

    liberaMemoria(entradaSeparada, quantidadePalavras);    
    liberaMemoria(arquivo, tamanhoArquivo);                 

    imprimeMatriz(saida, tamanhoComandoSelect, linhasIguais);
                          
    //liberaMemoriaRobusta(saida, tamanhoComandoSelect);                           
}

/* 
##### O programa se divide em 5 partes principais: ######
 * main
 * recebe entrada
 * abrindo selcionando arquivos
 * comparando campos
 * saída / imprimindo
 
*/ 

    //char **comandoFrom;                                           
    //comandoFrom = malloc(sizeof(char*) * tamanhocomandoFrom);   
    //for (int i = 0; i < tamanhocomandoFrom; i++) { 
    //    comandoFrom[i] = malloc(sizeof(char) * 20);
    //}
    //completaConteudoArray(comandoFrom, tamanhocomandoFrom);                                                                
    //armazenacomandoFrom(comandoFrom, entradaSeparada, tamanhocomandoFrom, quantidadePalavras);
    //liberaMemoria(comandoFrom, tamanhocomandoFrom);