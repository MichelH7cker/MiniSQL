#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
typedef struct{
    char siglas;
    char idade;
} Progs;

*/

void selecionaArquivo(char **conteudoFrom){
    printf("entrou na selciona Arquivo\n");
    printf("%s\n", conteudoFrom);
    for (int i = 0; i < 5; i++){
        printf("entrou no for \n");
        if (strcmp(conteudoFrom[i], "Docentes") == 0){ //tabela 5
            //open Docentes
        } else if(strcmp(conteudoFrom[i], "Progs") == 0){ //tabela 4
            printf("conseguimos!");
        } else { // tabela 3
            // open Trabalhos
        }
        
    }
    
}

void retiraVirgula(char *entrada, char *entradaSemVirgula){    
    int j = 0;
    for (int i = 0; entrada[i] != '\0'; i++){
        if (entrada[i] != ','){ 
            entradaSemVirgula[j] = entrada[i];
            j++;
        }
    }
    entradaSemVirgula[j] = '\0';
}

void mostraEntradaSeparada(char **entradaSeparada, int quantidadePalavras){
    for (int i = 0; i < quantidadePalavras; i++){
        printf("%s \n", entradaSeparada[i]);
    }
}

int verificaQuantidadePalavras(char *entrada){
    int quantidade = 1;
    int i = 0;
    while (entrada[i] != '\0'){
        if (entrada[i] == ' '){
            quantidade++;
        } 
        i++;
    }
    return quantidade;
}

void liberaMemoria(char **entradaSeparada, int quantidadePalavras) {
    for (int i = 0; i < quantidadePalavras; i++) {
        free(entradaSeparada[i]);
    }
    free(entradaSeparada);
}

int main(void){
    char entrada[130];
    fgets(entrada, 130, stdin);

    char entradaSemVirgula[130];
    retiraVirgula(entrada, entradaSemVirgula);

    int quantidadePalavras = verificaQuantidadePalavras(entradaSemVirgula);

    char *t;
    char **entradaSeparada;
    entradaSeparada = malloc(sizeof(char*) * quantidadePalavras);
    for (int i = 0; i < quantidadePalavras; i++) {
        entradaSeparada[i] = malloc(sizeof(char) * 50);
    }

    t = strtok(entradaSemVirgula, " "); //pega string até chegar em um espaço
    
    int i = 0;
    while(t != NULL){
        strcpy(entradaSeparada[i], t);
        //printf("%s \n", t);
        t = strtok(NULL," ");
        i++;
    }

    mostraEntradaSeparada(entradaSeparada, quantidadePalavras); 
    
    int passouPeloFrom = 0;
    char conteudoFrom[5][20];
    int j = 0;
    int k = 0;
    while ( (strcmp(entradaSeparada[k], "where") != 0) || (entradaSeparada[k] == '\0') ){
        if (passouPeloFrom){
            strcpy(conteudoFrom[j], entradaSeparada[k]);
            j++;
        }
        if (strcmp(entradaSeparada[k], "from") == 0){
            passouPeloFrom = 1;
        }
        k++;
    }
    
    selecionaArquivo(conteudoFrom);
}

/*

pegar cada palavra da entrada e adicionar em uma matriz
cada possição corresponde a uma palavra.
*/

/*

SELECT _____, _____ FROM _____, _____ WHERE comparação
select Progs.Sigla, Progs.Nome from Progs where Progs.Nivel = "7"

===================== CASO 1 =====================

.in:    select Progs.Sigla, Progs.Nome from Progs where Progs.Nivel = "7"
.out:   UFPE-CC-7	    CIENCIAS DA COMPUTACAO
        UFRJ-ESC-7	    ENGENHARIA DE SISTEMAS E COMPUTACAO
        PUC-RIO-I-7	    INFORMATICA
        UFMG-CC-7	    CIENCIAS DA COMPUTACAO
        USP-SC-CCMC-7	CIENCIAS DA COMPUTACAO E MATEMATICA COMPUTACIONAL
        UNICAMP-CC-7	CIENCIA DA COMPUTACAO
        UFRGS-C-7	    COMPUTACAO

=================================================

arquivo[][] = {anoDatitulacap{{2002} {2003}}, codigo{1231afa},{} }

AnodaTitulacao	CodigodoPPG	Nacionalidade	Nome	PaisdaInstituicao	Sexo
2009	27001016029P4	BRASIL	EDILAYNE MENESES SALGUEIRO	BRASIL	FEMININO

*/