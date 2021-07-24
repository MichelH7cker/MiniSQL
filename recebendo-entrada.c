#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void separadaEntrada(char *entradaSemVirgula, char **entradaSeparada){
    char *t;
    t = strtok(entradaSemVirgula, " "); // SELCIONA STRING ATÉ ESPAÇO
    int i = 0;
    while(t != NULL){
        strcpy(entradaSeparada[i], t);
        t = strtok(NULL," ");
        i++;
    }
}

void completaConteudoFrom(char **conteudoFrom, int tamanhoConteudoFrom){
    for (int i = 0; i < tamanhoConteudoFrom; i++){
        strcpy(conteudoFrom[i], "none");
    }  
}

void armazenaArquivosFrom(char **conteudoFrom, char **entradaSeparada, int tamanhoConteudoFrom){
    int passouPeloFrom = 0;
    int posicaoFrom = 0;

    for (int posicaoEntrada = 0; posicaoFrom < tamanhoConteudoFrom; posicaoEntrada++){
        if (strcmp(entradaSeparada[posicaoEntrada], "where") == 0){
            printf("entrou no where\n");
            break;
        }

        if (passouPeloFrom){
            strcpy(conteudoFrom[posicaoFrom], entradaSeparada[posicaoEntrada]);
            printf("O conteudoFrom acabou de armazenar: %s\n", conteudoFrom[posicaoFrom]);
            posicaoFrom++;
        }

        if (strcmp(entradaSeparada[posicaoEntrada], "from") == 0){
            passouPeloFrom = 1;
        }
        
    } 
}

void selecionaArquivo(char **conteudoFrom, int tamanhoConteudoFrom){
    for (int i = 0; i < tamanhoConteudoFrom; i++){
        printf("O conteudo from em selciona arquivo e: %s\n", conteudoFrom[i]);
        if (strcmp(conteudoFrom[i], "Progs") == 0){
            printf("entrei Progs\n");
        } else if(strcmp(conteudoFrom[i], "Docentes") == 0){
            printf("entrei em docentes\n");
        } else if (strcmp(conteudoFrom[i], "Trabalhos") == 0){
            printf("entrei em trabalhos \n");
        } else { //quando não tem mais arquivos
            break;
        }
    }
}

// TIRA VIRGULA E \n
void filtraEntrada(char *entrada, char *entradaSemVirgula){ 
    int j = 0;
    for (int i = 0; entrada[i] != '\0'; i++){
        if (entrada[i] == '\n'){
            break;
        }
        
        if (entrada[i] != ','){ 
            entradaSemVirgula[j] = entrada[i];
            j++;
        }
    }
    entradaSemVirgula[j] = '\0';
}

void mostraEntradaSeparada(char **entradaSeparada, int quantidadePalavras){
    for (int i = 0; i < quantidadePalavras; i++){
        printf("%s\n", entradaSeparada[i]);
    }
}

int verificaQuantidadePalavras(char *entradaSemVirgula){
    int quantidadePalavras = 1;
    int i = 0;
    while (entradaSemVirgula[i] != '\0'){
        if (entradaSemVirgula[i] == ' '){
            quantidadePalavras++;
        } 
        i++;
    }
    return quantidadePalavras;
}

void liberaMemoria(char **matriz, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

int main(void){
    char entrada[100];
    fgets(entrada, 100, stdin);
    char entradaSemVirgula[100];
    filtraEntrada(entrada, entradaSemVirgula);
    int quantidadePalavras = verificaQuantidadePalavras(entradaSemVirgula);
    
    // MALLOC
    char **entradaSeparada;
    entradaSeparada = malloc(sizeof(char*) * (quantidadePalavras));
    for (int i = 0; i < quantidadePalavras; i++) {
        entradaSeparada[i] = malloc(sizeof(char) * 50);
    }
    
    // MALLOC
    char **conteudoFrom;
    int tamanhoConteudoFrom = 4;
    conteudoFrom = malloc(sizeof(char*) * tamanhoConteudoFrom); 
    for (int i = 0; i < tamanhoConteudoFrom; i++) {
        conteudoFrom[i] = malloc(sizeof(char) * 50);
    }

    separadaEntrada(entradaSemVirgula, entradaSeparada);
    mostraEntradaSeparada(entradaSeparada, quantidadePalavras);
    completaConteudoFrom(conteudoFrom, tamanhoConteudoFrom);
    armazenaArquivosFrom(conteudoFrom, entradaSeparada, tamanhoConteudoFrom);
    selecionaArquivo(conteudoFrom, tamanhoConteudoFrom);
    liberaMemoria(entradaSeparada, quantidadePalavras);
    liberaMemoria(conteudoFrom, tamanhoConteudoFrom);
}

/*

- Alteramos a retira virgula, colcoamos strcpy
- modificiamos o tamanho do conteudo from
- Aumentamos uma condição no while do armzena arquivos from
- Mudamos a posição dos ifs no armzena arquivos

pegar cada palavra da entrada e adicionar em uma matriz
cada possição corresponde a uma palavra.



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