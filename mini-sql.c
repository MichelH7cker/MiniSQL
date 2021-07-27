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

#define LINHASAIDA 102       // LINHAS TOTAIS DA MATRIZ DE SAÍDA

int main(int argc, char *argv[]){
    char entrada[100];
    fgets(entrada, 100, stdin);
    char entradaSemVirgula[100];
    filtraEntrada(entrada, entradaSemVirgula);

    int quantidadePalavras = verificaQuantidadePalavrasTotal(entradaSemVirgula);

    char **entradaSeparada;        
    alocaMemoria(entradaSeparada, quantidadePalavras, 50);            
    
    separaEntrada(entradaSemVirgula, entradaSeparada);

    int tamanhoConteudoSelect = verificaQuantidadePalavrasSelect(entradaSeparada);
    int tamanhoConteudoFrom   = verificaQuantidadePalavrasFrom(quantidadePalavras, entradaSeparada);
    int tamanhoConteudoWhere  = verificaQuantidadePalavrasWhere(quantidadePalavras, tamanhoConteudoSelect, tamanhoConteudoFrom); 
                                                   
    
    char **comandoWhere;       
    alocaMemoria(comandoWhere, tamanhoConteudoWhere, 50);       

    completaConteudoArray (comandoWhere, tamanhoConteudoWhere);                                        
    armazenaConteudoWhere (comandoWhere, entradaSeparada, tamanhoConteudoWhere, quantidadePalavras);  
    int linhasIguaisRes[101];
    verificaLinhasPermitidas(linhasIguaisRes, comandoWhere, tamanhoConteudoWhere);

    liberaMemoria(comandoWhere, tamanhoConteudoWhere);    
    
    char **arquivo;  
    int tamanhoArquivo = 1;                                                  
    alocaMemoria(arquivo, tamanhoArquivo, 10);                                                                

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
    
    int colunaEscolhida;
    int colunaAtualMatriz = 0;
    char ordemSaida[tamanhoConteudoFrom][30];
    for (int selectAtual = 0; selectAtual < tamanhoConteudoSelect; selectAtual++){
        char **conteudoSelect;
        alocaMemoria(conteudoSelect, tamanhoConteudoSelect, 30);                                                                                                        
        conteudoSelect = malloc(sizeof(char*) * tamanhoConteudoSelect);     //
                                                                      
        completaConteudoArray (conteudoSelect, tamanhoConteudoSelect);                                      
        armazenaConteudoSelect(conteudoSelect, entradaSeparada, tamanhoConteudoSelect);

        selecionaArquivoColuna(conteudoSelect, tamanhoConteudoSelect, arquivo, selectAtual, &colunaEscolhida);
        liberaMemoria(conteudoSelect, tamanhoConteudoSelect);

        
        
        if (strcmp(arquivo[0], "none") == 0) break; 

        abreArquivo(colunaEscolhida, arquivo, saida, colunaAtualMatriz);

        colunaAtualMatriz++;
    }

    liberaMemoria(entradaSeparada, quantidadePalavras);     //  DESALOCACAO
    liberaMemoria(arquivo, tamanhoArquivo);                 //  DE MEMORIA

    imprimeMatriz(saida, tamanhoConteudoSelect, linhasIguaisRes);
                          
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
     
