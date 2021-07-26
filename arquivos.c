#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#include "saida.h"

#define COLUNASPROGS 7       //
#define COLUNASDOCENTES 6    // QUANTIDADE DE COLUNAS DE CADA ARQUIVO
#define COLUNASTRABALHOS 5   //

int encontraArquivo(char **arquivo) {
    if (strcmp(arquivo[0], "Docentes") == 0){
        return COLUNASDOCENTES;
    }
    if (strcmp(arquivo[0], "Progs") == 0) {
        return COLUNASPROGS;
    }
    return COLUNASTRABALHOS;
}

void imprimeSaida(int *colunaEntrada, char **arquivo){
    FILE *pArquivo;
    char cursor;
    int tamanhoArquivo = encontraArquivo(arquivo);

    if (tamanhoArquivo == COLUNASPROGS) {
        pArquivo = fopen("Progs.tsv","r");
    }
    else if (tamanhoArquivo == COLUNASTRABALHOS) {
        pArquivo = fopen("Trabalhos.tsv","r");
    }
    else {
        pArquivo = fopen("Docentes.tsv","r");
    }
    
    if (pArquivo == NULL){
        printf("Erro ao tentar abrir o arquivo!");
        exit(1);
    }

    int acumuladorTabs   = 0;
    int acumuladorLinhas = 0;
    int idColunaInicial  = *colunaEntrada;  //numero de qual coluna é
    int coluna = idColunaInicial;
    do{  
        cursor = fgetc(pArquivo);        
        if (acumuladorTabs == coluna && acumuladorTabs >= tamanhoArquivo){
            printf("%c", cursor);
        }
        if (cursor == '\t'){
            acumuladorTabs++;
        }
        
        if (cursor == '\n'){
            acumuladorTabs++;
            coluna += tamanhoArquivo;
            if (idColunaInicial < tamanhoArquivo - 1 && acumuladorTabs > tamanhoArquivo) {
                printf("\n"); 
            }          //serve pra quase todas as colunas, menos a ultima (da um enter a mais do que precisa)
        }
        
    } while (cursor != EOF); //enquanto não for final de arquivo 

    fclose(pArquivo);
}

void percorreCabecalho(char cabecalho[][100], char **conteudoSelect, int tamanhoConteudoSelect, int **colunaSelecionada, int **selectAtual){
    for (int indiceCabecalho = 0; indiceCabecalho < COLUNASDOCENTES; indiceCabecalho++){
        if (strcmp(conteudoSelect[**selectAtual], cabecalho[indiceCabecalho]) == 0){
            **colunaSelecionada = indiceCabecalho;
        }
    }
}

void escolheColunas(char **conteudoSelect, int tamanhoConteudoSelect, char **arquivo, int *colunaSelecionada, int *selectAtual){
    char cabecalhoProgs[COLUNASPROGS][100] = {{"Progs.Instituicao"}, {"Progs.Programa"}, {"Progs.Nivel"}, {"Progs.Sigla"}, {"Progs.TemDoutorado"}, {"Progs.Nome"}, {"Progs.AreadeAvaliacao"}};
    char cabecalhoDocentes[COLUNASDOCENTES][100] = {{"Docentes.AnodaTitulacao"}, {"Docentes.CodigoPPG"}, {"Docentes.Nacionalidade"}, {"Docentes.Nome"}, {"Docentes.PaisdaInstituicao"}, {"Docentes.Sexo"}};
    char cabecalhoTrabalhos[COLUNASTRABALHOS][100] = {{"Trabalhos.Ano"}, {"Trabalhos.Autor"}, {"Trabalhos.CodigoPPG"}, {"Trabalhos.Idioma"}, {"Trabalhos.Orientador"}};    

    if ((strcmp(arquivo[0], "Docentes")) == 0){
        percorreCabecalho(cabecalhoDocentes, conteudoSelect, tamanhoConteudoSelect, &colunaSelecionada, &selectAtual); 
    
    } else if (strcmp(arquivo[0], "Progs") == 0){
        percorreCabecalho(cabecalhoProgs, conteudoSelect, tamanhoConteudoSelect, &colunaSelecionada, &selectAtual);

    } else {
        percorreCabecalho(cabecalhoTrabalhos, conteudoSelect, tamanhoConteudoSelect, &colunaSelecionada, &selectAtual);
    }
    
}

void selecionaArquivos(char **conteudoFrom, int tamanhoConteudoFrom, char **arquivo, int posicaoFrom){
    printf("\n");
    if(strcmp(conteudoFrom[posicaoFrom], "Docentes") == 0){
        strcpy(arquivo[0], "Docentes");

    } else if (strcmp(conteudoFrom[posicaoFrom], "Progs") == 0){
        strcpy(arquivo[0], "Progs");

    } else if (strcmp(conteudoFrom[posicaoFrom], "Trabalhos") == 0){
        strcpy(arquivo[0], "Trabalhos");

    } else { //quando não tem mais arquivos
        strcpy(arquivo[0], "none");
    } 
}

