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
    char texto[100];
    printf("coluna selecionada dentro da preenche saída: %d\n", *colunaSelecionada);
    do{
        cursor = fgetc(pArquivo); 
        if (cursor == '\t'){ 
            acumuladorTabs++;
        } else if (cursor == '\n'){
            acumuladorTabs = 0;
            acumuladorLinhas++;
        }
        //fscanf(pArquivo, "%[^\n]", linha);
        if (acumuladorTabs == *colunaSelecionada && acumuladorLinhas != 0){
            fscanf(pArquivo, "%[^\t^\n]", texto);
            strcpy(saida[acumuladorLinhas][colunaAtualMatriz], texto);
            printf("captamos o texto: %s\n", texto);
            printf("a matriz acabou de armazenar: %s\n", saida[acumuladorLinhas][colunaAtualMatriz]);
            printf("linha da matrz: %d --- coluna da matriz: %d\n", acumuladorLinhas, colunaAtualMatriz);
        }
    } while (cursor != EOF);

    printf("saindo da função preenche saída \n");
}

// select Progs.Sigla, Docentes.Nome from Progs, Docentes
void abreArquivo(int colunaSelecionada, char **arquivo, char ***saida, const int colunaAtualMatriz){
    FILE *pArquivo;
    //int tamanhoColuna = encontraArquivo(arquivo);
    printf("A coluna selecionada e: %d\n", colunaSelecionada);
    printf("A coluna atual da saida e: %d\n", colunaAtualMatriz);
    if ((strcmp(arquivo[0], "Progs")) == 0){
        pArquivo = fopen("Progs.tsv", "r");
        preencheSaida(saida, &colunaSelecionada, pArquivo, colunaAtualMatriz);
        printf("vou fechar o arquivo!\n");
        fclose(pArquivo);
        printf("arquivo fechado e saindo da função abre arquivo!\n");
    } else if ((strcmp(arquivo[0], "Trabalhos")) == 0) {
        pArquivo = fopen("Trabalhos.tsv", "r");
        preencheSaida(saida, &colunaSelecionada, pArquivo, colunaAtualMatriz);
        printf("vou fechar o arquivo!\n");
        fclose(pArquivo);
        printf("arquivo fechado e saindo da função abre arquivo!\n");
    }
    else {
        pArquivo = fopen("Docentes.tsv", "r");
        preencheSaida(saida, &colunaSelecionada, pArquivo, colunaAtualMatriz);
        printf("vou fechar o arquivo!\n");
        fclose(pArquivo);
        printf("arquivo fechado e saindo da função abre arquivo!\n");
    }
    if (pArquivo == NULL){
        printf("Erro ao tentar abrir o arquivo!");
        exit(-1);
    }   

    
}

void preencheComNone(char ***saida, int tamanhoConteudoSelect){
    for (int i = 0; i < 102; i++){
        for (int j = 0; j < tamanhoConteudoSelect; j++){
            strcpy(saida[i][j], "-");   
        }  
    }
}

void mostraMatriz(char ***saida, int tamanhoConteudoSelect){
    for (int i = 0; i < 102; i++){
        for (int j = 0; j < tamanhoConteudoSelect; j++){
            printf("%s ", saida[i][j]);   
        }  
        printf("\n");
    }
    
}

void liberaMemoriaRobusta(char ***saida, int tamanhoSelect){
    for (int i = 0; i < 102; i++) {
        for (int j = 0; j < tamanhoSelect; j++) {
            free(saida[i][j]);
        }
        free(saida[i]);
    }
    free(saida);
}