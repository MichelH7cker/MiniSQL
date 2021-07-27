#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#include "saida.h"

#define COLUNASPROGS     7   //
#define COLUNASDOCENTES  6   // QUANTIDADE DE COLUNAS DE CADA ARQUIVO
#define COLUNASTRABALHOS 5   //

#define LINHASAIDA 102       // LINHAS TOTAIS DA MATRIZ DE SAÍDA

void armazenaDadosSaida(char ***saida, const int *colunaEscolhida, FILE *pArquivo, const int colunaAtualMatriz){
    int acumuladorTabs   = 0;
    int acumuladorLinhas = 0;
    int cursor;
    char texto[100];

    do{
        cursor = fgetc(pArquivo); 
        if (cursor == '\t'){ 
            acumuladorTabs++;
        } else if (cursor == '\n'){
            acumuladorTabs = 0;
            acumuladorLinhas++;
        }

        if (acumuladorTabs == *colunaEscolhida && acumuladorLinhas != 0){
            fscanf(pArquivo, "%[^\t^\n]", texto);

            strcpy(saida[acumuladorLinhas][colunaAtualMatriz], texto);
        }
    } while (cursor != EOF);
}   

void abreArquivo(int colunaEscolhida, char **arquivo, char ***saida, const int colunaAtualMatriz){
    FILE *pArquivo;

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
    armazenaDadosSaida(saida, &colunaEscolhida, pArquivo, colunaAtualMatriz);
    fclose(pArquivo);
    
}

void ocupaConteudoSaida(char ***saida, int tamanhoConteudoSelect){
    for (int i = 1; i < LINHASAIDA; i++){
        for (int j = 0; j < tamanhoConteudoSelect; j++){
            strcpy(saida[i][j], "none");   
        }  
    }
}

//select Progs.Sigla, Docentes.Nome from Progs, Docentes
void imprimeMatriz(char ***saida, int colunaLimite){
    int mostra = 1;
    int contaNada;
    int comparacao;
    for (int linhaAtual = 1; linhaAtual < 101; linhaAtual++){
        contaNada = 0;
        for (int colunaAtual = 0; colunaAtual < colunaLimite; colunaAtual++){  
            comparacao = strcmp(saida[linhaAtual][colunaAtual], "none");
            if (comparacao == 0){
                contaNada++;
                if(contaNada == colunaLimite) {
                    liberaMemoriaRobusta(saida, colunaLimite);
                    exit(0);
                }
                continue;
            }
            for(int i = 0; i < contaNada; i++) {
                printf("\t");
            }
            if (colunaAtual == 0){
                printf("%s", saida[linhaAtual][colunaAtual]);
            } else {
                printf("\t%s", saida[linhaAtual][colunaAtual]);
            }
        }
        printf("\n");
    }
}

void liberaMemoriaRobusta(char ***saida, int tamanhoSelect){
    for (int i = 0; i < LINHASAIDA; i++) {
        for (int j = 0; j < tamanhoSelect; j++) {
            free(saida[i][j]);
        }
        free(saida[i]);
    }
    free(saida);
}