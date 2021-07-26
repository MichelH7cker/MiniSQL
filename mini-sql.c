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
    int tamanhoConteudoFrom   = verificaQuantidadePalavrasFrom(quantidadePalavras, entradaSeparada);
    int tamanhoConteudoWhere  = verificaQuantidadePalavrasWhere(quantidadePalavras, tamanhoConteudoSelect, tamanhoConteudoFrom); 
                                                   
    /*
    char **conteudoWhere;                                            
    conteudoWhere = malloc(sizeof(char*) * tamanhoConteudoWhere);        
    for (int i = 0; i < tamanhoConteudoWhere; i++) {                    
        conteudoWhere[i] = malloc(sizeof(char) * 50);                   
    }      */                                                           
    
    char **arquivo;                                                   
    int tamanhoArquivo = 1;                                        
    arquivo = malloc(sizeof(char*) * tamanhoArquivo);                   
    for (int i = 0; i < tamanhoArquivo; i++) {                          
        arquivo[i] = malloc(sizeof(char) * 10);                         
    }                                                                  

    char ***saida; //101
    saida = malloc(sizeof(char**) * 102); // Linhas
    for (int i = 0; i < 102; i++) {
        saida[i] = malloc(sizeof(char*) * tamanhoConteudoSelect); // Colunas
        for (int t = 0; t < tamanhoConteudoSelect; t++) {
            saida[i][t] = malloc(sizeof(char) * 100); //Chars
        }
    }
    preencheComNone(saida, tamanhoConteudoSelect);

    int colunaSelecionada;  
    // transformar num array e fazer um contandor na entrada no select
    
    mostraEntradaSeparada(entradaSeparada, quantidadePalavras);
    
    //completaConteudoArray (conteudoWhere, tamanhoConteudoWhere);                                        
    //armazenaConteudoWhere (conteudoWhere, entradaSeparada, tamanhoConteudoWhere, quantidadePalavras);                                                                    
    //iberaMemoria(conteudoWhere, tamanhoConteudoWhere);     
    
    int posicaoFrom = 0;
    int colunaAtualMatriz = 0;
    for (int selectAtual = 0; selectAtual < tamanhoConteudoSelect; selectAtual++){
        char **conteudoFrom;                                           
        conteudoFrom = malloc(sizeof(char*) * tamanhoConteudoFrom);   
        for (int i = 0; i < tamanhoConteudoFrom; i++) {conteudoFrom[i] = malloc(sizeof(char) * 20);}
        completaConteudoArray(conteudoFrom, tamanhoConteudoFrom);                                                                
        armazenaConteudoFrom(conteudoFrom, entradaSeparada, tamanhoConteudoFrom, quantidadePalavras);
        selecionaArquivos(conteudoFrom, tamanhoConteudoFrom, arquivo, posicaoFrom);  
        liberaMemoria(conteudoFrom, tamanhoConteudoFrom);

        if ((strcmp(arquivo[0], "none")) == 0){ break;}

        char **conteudoSelect;                                          
        conteudoSelect = malloc(sizeof(char*) * tamanhoConteudoSelect);       
        for (int i = 0; i < tamanhoConteudoSelect; i++) {conteudoSelect[i] = malloc(sizeof(char) * 30);}   
        completaConteudoArray (conteudoSelect, tamanhoConteudoSelect);                                      
        armazenaConteudoSelect(conteudoSelect, entradaSeparada, tamanhoConteudoSelect);
        escolheColunas(conteudoSelect, tamanhoConteudoSelect, arquivo, &colunaSelecionada, &selectAtual);
        liberaMemoria(conteudoSelect, tamanhoConteudoSelect);

        printf("A COLUNA SELECIONADA E: %d\n", colunaSelecionada);
        printf("A coluna atual da matriz é: %d\n", colunaAtualMatriz);

        abreArquivo(colunaSelecionada, arquivo, saida, colunaAtualMatriz);

        printf("voltei no for principal\n");
        printf("A coluna da matriz valia %d\n", colunaAtualMatriz);
        colunaAtualMatriz++;
        printf("A coluna passou a valer %d\n", colunaAtualMatriz);
        posicaoFrom++;

    }
    liberaMemoria(entradaSeparada, quantidadePalavras);
    mostraMatriz(saida, tamanhoConteudoSelect);
    //imprimeSaida(&colunaSelecionada, arquivo);                                                   
    liberaMemoria(arquivo, tamanhoArquivo);                      
    liberaMemoriaRobusta(saida, tamanhoConteudoSelect);                            
}

/* 

##### O programa se divide em 5 partes principais: ######
 * main
 * recebe entrada
 * abrindo selcionando arquivos
 * comparando campos
 * saída / imprimindo
 
*/ 
     