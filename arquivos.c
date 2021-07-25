#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

int encontraArquivo(char **arquivo) {
    if (strcmp(arquivo[0], "Docentes") == 0){
        return 6;
    }
    if (strcmp(arquivo[0], "Progs") == 0) {
        return 7;
    }
    return 5;
}

void imprimeColuna(int colunaEntrada, char **arquivo){
    FILE *pAarquivo;
    char cursor;
    int tamanhoArquivo = encontraArquivo(arquivo);
    if (tamanhoArquivo == 7) {
        pAarquivo = fopen("Progs.tsv","r");
    }
    else if (tamanhoArquivo == 5) {
        pAarquivo = fopen("Trabalhos.tsv","r");
    }
    else {
        pAarquivo = fopen("Docentes.tsv","r");
    }
    
    if (pAarquivo == NULL){
        printf("Erro ao tentar abrir o arquivo!");
        exit(1);
    }

    int acumuladorTabs   = 0;
    int acumuladorLinhas = 0;
    int idColunaInicial  = colunaEntrada;  //numero de qual coluna é
    int coluna = idColunaInicial;
    do{  
        cursor = fgetc(pAarquivo);        
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
        
    } while (cursor != EOF);//enquanto não for final de arquivo 

    fclose(pAarquivo);
}

int escolheColunas(char **conteudoSelect, int tamanhoConteudoSelect, char **arquivo){
    char cabecalhoProgs[7][100] = {{"Progs.Instituicao"}, {"Progs.Programa"}, {"Progs.Nivel"}, {"Progs.Sigla"}, {"Progs.TemDoutorado"}, {"Progs.Nome"}, {"Progs.AreadeAvaliacao"}};
    char cabecalhoDocentes[6][100] = {{"Docentes.AnodaTitulacao"}, {"Docentes.CodigoPPG"}, {"Docentes.Nacionalidade"}, {"Docentes.Nome"}, {"Docentes.PaisdaInstituicao"}, {"Docentes.Sexo"}};
    char cabecalhoTrabalhos[5][100] = {{"Trabalhos.Ano"}, {"Trabalhos.Autor"}, {"Trabalhos.CodigoPPG"}, {"Trabalhos.Idioma"}, {"Trabalhos.Orientador"}};
        
    for (int posicaoConteudoSelect = 0; posicaoConteudoSelect < tamanhoConteudoSelect; posicaoConteudoSelect++){
        if (strcmp(arquivo[0], "Docentes") == 0){
            for (int indice = 0; indice < 5; indice++){ //FOR DO DICIONÁRIO
                if ((strcmp(conteudoSelect[posicaoConteudoSelect], cabecalhoDocentes[indice])) == 0){
                    return indice;
                    
                } 
            }
            
        } else if ((strcmp(arquivo[0], "Progs") == 0)){
            for (int indice = 0; indice < 7; indice++){
                if ((strcmp(conteudoSelect[posicaoConteudoSelect], cabecalhoProgs[indice])) == 0){
                    return indice;
                } 
            }
            
        } else {
            for (int indice = 0; indice < 6; indice++){
                if ((strcmp(conteudoSelect[posicaoConteudoSelect], cabecalhoTrabalhos[indice])) == 0){
                    return indice;
                } 
            }
        }
        
    }
    
}

void selecionaArquivos(char **conteudoFrom, int tamanhoConteudoFrom, char **arquivo){
    for (int i = 0; i < tamanhoConteudoFrom; i++){
        printf("\n");
        if(strcmp(conteudoFrom[i], "Docentes") == 0){
            strcpy(arquivo[0], "Docentes");

        } else if (strcmp(conteudoFrom[i], "Progs") == 0){
            strcpy(arquivo[0], "Progs");

        } else if (strcmp(conteudoFrom[i], "Trabalhos") == 0){
            strcpy(arquivo[0], "Trabalhos");

        } else { //quando não tem mais arquivos
            break;
        }
    }
}
