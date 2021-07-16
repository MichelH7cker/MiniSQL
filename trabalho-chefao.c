#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char Instituicao;
    char Programa;
    int Nivel;
    char Sigla;
    char TemDoutorado;
    char Nome;
    char AreadeAvaliacao;
} Progs;

typedef struct {
    int AnoTitulacao[4];
    char CodigoPPG[14];
    char Nacionalidade;
    char Nome;
    char PaisdaInstituicao;
    char Sexo;
    
    //acessar arquivo referentes ao docentes

} Docentes;

typedef struct {
    int Ano[4];
    char Autor;
    char CodigoPPG;
    char Idioma;
    char Orientador;
} Trabalhos;


void pegaSelect(){
    //armazena condições do select
    //Exemplo: Progs.Sigla, Docentes.Nome
    //camposSelecionados[0] = Progs.Sigla
    //camposSelecionados[1] = Docentes.Nome
    char camposSelecionados;
}

void pegaFrom(){
    //usaria 
} 

void pegaWhere(){
    
}

void separaString(char **entrada, char entradaSeparada){
    int contEnt = 0;
    int contSep = 0;
    while (entrada[contEnt] != '\0'){
        if (entrada[contEnt] == ' '){
            entradaSeparada[contEnt] = 
            contSep++;
        } else if (entrada[contEnt] == ','){
            entradaSeparada[contEnt] = contEnt;
            contEnt += 2;
        } else {

        }

        entradaSeparada[contSep] += entrada[contEnt];
        contEnt++;
    }
    
}

int main(int argc, char *argv[]) {
    //RECEBENDO ENTRADA
    char entrada[1024];
    fgets(entrada, 1024, stdin);
    printf("%s", entrada);

    char entradaSeparada;
    separaString(entrada, entradaSeparada);
}

/*

//SELECT _____, _____ FROM _____, _____ WHERE comparação

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

*/
