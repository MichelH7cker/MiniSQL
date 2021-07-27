#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#include "entrada.h"
#include "arquivos.h"
#include "saida.h"
#include "comparacao.h"

#define LINHASAIDA 102       // LINHAS TOTAIS DA MATRIZ DE SAÍDA

void alocaMemoria(char **matriz, int tamanho, int conteudo) {
    matriz = malloc(sizeof(char*) * tamanho);        
    for (int i = 0; i < tamanho; i++) {                    
        matriz[i] = malloc(sizeof(char) * conteudo);                   
    }                                                           
}

void alocaMemoriaRobusta(char ***matrizRobusta, int linhasMatrizRobusta, int charTamanhoMatriz){
    matrizRobusta = malloc(sizeof(char**) * LINHASAIDA); // Linhas
    for (int i = 0; i < LINHASAIDA; i++) {
        matrizRobusta[i] = malloc(sizeof(char*) * linhasMatrizRobusta); // Colunas
        for (int t = 0; t < linhasMatrizRobusta; t++) {
            matrizRobusta[i][t] = malloc(sizeof(char) * charTamanhoMatriz); //Char
        }
    }

}

void liberaMemoria(char **matriz, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        free(matriz[i]);
    }
    free(matriz);
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