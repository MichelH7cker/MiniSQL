#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#include "saida.h"

#define COLUNASPROGS 7       //
#define COLUNASDOCENTES 6    // QUANTIDADE DE COLUNAS DE CADA ARQUIVO
#define COLUNASTRABALHOS 5   //

#define DOCENTES 1           //        
#define PROGS 2              // ID PARA CADA ARQUIVO
#define TRABALHOS 3          //

#define LINHASAIDA 101       // LINHAS TOTAIS DA MATRIZ DE SAÍDA

int percorreCabecalho(char **conteudoSelect, int tamanhoConteudoSelect, char **arquivo, int selectAtual, int **colunaSelecionada){
    char cabecalhoProgs[COLUNASPROGS][100] = {{"Progs.Instituicao"}, {"Progs.Programa"}, {"Progs.Nivel"}, {"Progs.Sigla"}, {"Progs.TemDoutorado"}, {"Progs.Nome"}, {"Progs.AreadeAvaliacao"}};
    char cabecalhoDocentes[COLUNASDOCENTES][100] = {{"Docentes.AnodaTitulacao"}, {"Docentes.CodigoPPG"}, {"Docentes.Nacionalidade"}, {"Docentes.Nome"}, {"Docentes.PaisdaInstituicao"}, {"Docentes.Sexo"}};
    char cabecalhoTrabalhos[COLUNASTRABALHOS][100] = {{"Trabalhos.Ano"}, {"Trabalhos.Autor"}, {"Trabalhos.CodigoPPG"}, {"Trabalhos.Idioma"}, {"Trabalhos.Orientador"}};
    
    for (int i = 0; i < COLUNASDOCENTES; i++){
        if (strcmp(conteudoSelect[selectAtual], cabecalhoDocentes[i]) == 0){
            **colunaSelecionada = i;
            return DOCENTES;
        }
    }
    for (int j = 0; j < COLUNASPROGS; j++){
        if (strcmp(conteudoSelect[selectAtual], cabecalhoProgs[j]) == 0){
            **colunaSelecionada = j;
            return PROGS;
        }
    }
    for (int k = 0; k < COLUNASTRABALHOS; k++){
        if (strcmp(conteudoSelect[selectAtual], cabecalhoTrabalhos[k]) == 0){
            **colunaSelecionada = k;
            return TRABALHOS;
        }
    }
}

void selecionaArquivoColuna(char **conteudoSelect, int tamanhoConteudoSelect, char **arquivo, int posicaoSelect, int *colunaSelecionada){
    int arquivoSelecionado = percorreCabecalho(conteudoSelect , tamanhoConteudoSelect, arquivo, posicaoSelect, &colunaSelecionada);
    
    if (arquivoSelecionado == DOCENTES){
        strcpy(arquivo[0], "Docentes");
    } else if(arquivoSelecionado == PROGS){
        strcpy(arquivo[0], "Progs");
    } else {
        strcpy(arquivo[0], "Trabalhos");
    }
    
}

//select Trabalhos.CodigoPPG, Docentes.PaisdaInstituicao, Progs.AreadeAvaliacao from Trabalhos, Docentes, Progs