#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#include "saida.h"
#include "arquivos.h"

#define COLUNASPROGS     7   //
#define COLUNASDOCENTES  6   // QUANTIDADE DE COLUNAS DE CADA ARQUIVO
#define COLUNASTRABALHOS 5   //

void preencheSaida(char ***saida, const int *colunaSelecionada, FILE *pArquivo, const int colunaAtualMatriz){
    int acumuladorTabs   = 0;
    int acumuladorLinhas = 0;
    char cursor;

    char texto[20];
    do{

        cursor = fgetc(pArquivo); 
        if (cursor == '\t'){ 
            acumuladorTabs++;
        } else if (cursor == '\n'){
            acumuladorTabs = 0;
            acumuladorLinhas++;
        }

        if (acumuladorTabs == *colunaSelecionada && acumuladorLinhas != 0){
            fscanf(pArquivo, "%[^\t]", texto);
            strcpy(saida[acumuladorLinhas][colunaAtualMatriz], texto);
            printf("captamos o texto: %s\n", texto);
            printf("a matriz acabou de armazenar: %s\n", saida[acumuladorLinhas][colunaAtualMatriz]);
        }

    } while (cursor != EOF);
}

// select Progs.Sigla, Docentes.Nome from Progs, Docentes
void abreArquivo(int colunaSelecionada, char **arquivo, char ***saida, const int colunaAtualMatriz){
    FILE *pArquivo;
    char cursor;
    //int tamanhoColuna = encontraArquivo(arquivo);
    
    if ((strcmp(arquivo[0], "Progs")) == 0){
        pArquivo = fopen("Progs.tsv", "r");
    } else if ((strcmp(arquivo[0], "Trabalhos")) == 0) {
        pArquivo = fopen("Trabalhos.tsv", "r");
    }
    else {
        pArquivo = fopen("Docentes.tsv", "r");
    }
    if (pArquivo == NULL){
        printf("Erro ao tentar abrir o arquivo!");
        exit(-1);
    }   

    preencheSaida(saida, &colunaSelecionada, pArquivo, colunaAtualMatriz);
}

void preencheComNone(char ***saida, int tamanhoConteudoSelect){
    for (int i = 0; i < 130; i++){
        for (int j = 0; j < tamanhoConteudoSelect; j++){
            strcpy(saida[i][j], "none");   
        }  
    }
}

void mostraMatriz(char ***saida, int tamanhoConteudoSelect){
    for (int i = 0; i < 130; i++){
        for (int j = 0; j < tamanhoConteudoSelect; j++){
            printf("%s ", saida[i][j]);   
        }  
        printf("\n");
    }
    
}

void liberaMemoriaRobusta(char ***saida, int tamanhoSelect){
    for (int i = 0; i < 130; i++) {
        for (int j = 0; j < tamanhoSelect; j++) {
            free(saida[i][j]);
        }
        free(saida[i]);
    }
    free(saida);
}