#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "entrada.h"
#include "arquivos.h"
#include "comparacao.h"
#include "saida.h"

#define COLUNASPROGS 7       //
#define COLUNASDOCENTES 6    // QUANTIDADE DE COLUNAS DE CADA ARQUIVO
#define COLUNASTRABALHOS 5   //

#define LINHASAIDA 101       // LINHAS TOTAIS DA MATRIZ DE SAÍDA


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
    int tamanhoConteudoFrom   = verificaQuantidadePalavrasFrom(quantidadePalavras, entradaSeparada);
    int tamanhoConteudoWhere  = verificaQuantidadePalavrasWhere(quantidadePalavras, tamanhoConteudoSelect, tamanhoConteudoFrom); 
                                                   
    
    /*char **conteudoWhere;                                            
    conteudoWhere = malloc(sizeof(char*) * tamanhoConteudoWhere);        
    for (int i = 0; i < tamanhoConteudoWhere; i++) {                    
        conteudoWhere[i] = malloc(sizeof(char) * 50);                   
    }*/                                                           
    
    char **arquivo;                                                   
    int tamanhoArquivo = 1;                                        
    arquivo = malloc(sizeof(char*) * tamanhoArquivo);                   
    for (int i = 0; i < tamanhoArquivo; i++) {                          
        arquivo[i] = malloc(sizeof(char) * 10);                         
    }                                                                  

    char ***saida; //101
    saida = malloc(sizeof(char**) * LINHASAIDA); // Linhas
    for (int i = 0; i < LINHASAIDA; i++) {
        saida[i] = malloc(sizeof(char*) * tamanhoConteudoSelect); // Colunas
        for (int t = 0; t < tamanhoConteudoSelect; t++) {
            saida[i][t] = malloc(sizeof(char) * 100); //Char
        }
    }

    ocupaConteudoSaida(saida, tamanhoConteudoSelect);
    
    //mostraEntradaSeparada(entradaSeparada, quantidadePalavras);
    
    //completaConteudoArray (conteudoWhere, tamanhoConteudoWhere);                                        
    //armazenaConteudoWhere (conteudoWhere, entradaSeparada, tamanhoConteudoWhere, quantidadePalavras);                                                                    
    //iberaMemoria(conteudoWhere, tamanhoConteudoWhere);     
    
    int colunaEscolhida;
    int posicaoFrom = 0;
    int colunaAtualMatriz = 0;
    char ordemSaida[tamanhoConteudoFrom][30];
    for (int selectAtual = 0; selectAtual < tamanhoConteudoSelect; selectAtual++){
        char **conteudoSelect;                                              //                                                             
        conteudoSelect = malloc(sizeof(char*) * tamanhoConteudoSelect);     //  
        for (int i = 0; i < tamanhoConteudoSelect; i++) {                   // MALLOC
            conteudoSelect[i] = malloc(sizeof(char) * 30);                  //
        }                                                                   //
                                                                      
        completaConteudoArray (conteudoSelect, tamanhoConteudoSelect);                                      
        armazenaConteudoSelect(conteudoSelect, entradaSeparada, tamanhoConteudoSelect);

        selecionaArquivoColuna(conteudoSelect, tamanhoConteudoSelect, arquivo, selectAtual, &colunaEscolhida);
        liberaMemoria(conteudoSelect, tamanhoConteudoSelect);

        char **conteudoFrom;                                           
        conteudoFrom = malloc(sizeof(char*) * tamanhoConteudoFrom);   
        for (int i = 0; i < tamanhoConteudoFrom; i++) { 
            conteudoFrom[i] = malloc(sizeof(char) * 20);
        }
        completaConteudoArray(conteudoFrom, tamanhoConteudoFrom);                                                                
        armazenaConteudoFrom(conteudoFrom, entradaSeparada, tamanhoConteudoFrom, quantidadePalavras);
        liberaMemoria(conteudoFrom, tamanhoConteudoFrom);
        
        if (strcmp(arquivo[0], "none") == 0) break; 

        abreArquivo(colunaEscolhida, arquivo, saida, colunaAtualMatriz);

        colunaAtualMatriz++;
        posicaoFrom++;
    }

    imprimeMatriz(saida, tamanhoConteudoSelect);

    liberaMemoria(entradaSeparada, quantidadePalavras);    //
    liberaMemoria(arquivo, tamanhoArquivo);                // DESALOCAÇÃO      
    liberaMemoriaRobusta(saida, tamanhoConteudoSelect);    //                        
}

/* 

##### O programa se divide em 5 partes principais: ######
 * main
 * recebe entrada
 * abrindo selcionando arquivos
 * comparando campos
 * saída / imprimindo
 
*/ 
     