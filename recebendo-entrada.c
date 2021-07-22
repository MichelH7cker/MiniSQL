#include <stdio.h>
#include <string.h>
/*
typedef struct{
    char siglas;
    char idade;
} Progs;

*/
int verificaQuantidadePalavras(char *entrada, int tamanhoStr){
    int quantidade = 1;
    int i = 0;
    while (i < tamanhoStr){
        if (entrada[i] == ' '){
            quantidade++;
        } 
        i++;
    }
    return quantidade;
}

int main(void){
    char entrada[100];
    fgets(entrada, 100, stdin);

    int tamanhoStr = strlen(entrada);
    int quantidadePalavras = verificaQuantidadePalavras(entrada, tamanhoStr);

   
    char *t;
    char entradaSeparada[quantidadePalavras][30];

    t = strtok(entrada, " ");

    int i = 0;
    while(i < quantidadePalavras){ 
        strcpy(entradaSeparada[i], t);
        t = strtok(NULL, " ");
        i++;
    }

    for (int i = 0; i < quantidadePalavras; i++){
        printf("%s \n", entradaSeparada[i]);
    }

    //printf("%s", entradaSeparada[2]);
    if (strcmp(entradaSeparada[0], "select") == 0){
        printf("oi");
    }
    // se posicao == nome
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