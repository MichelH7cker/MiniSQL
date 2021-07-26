#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int verificaQuantidadePalavrasTotal(char *entradaSemVirgula){
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

int verificaQuantidadePalavrasSelect(char **entradaSeparada){
    int quantidadePalavrasSelect = 0;
    //select a b from
    for (int i = 1; 1; i++){
        if ((strcmp(entradaSeparada[i], "from")) == 0){
            return quantidadePalavrasSelect;
        }
        quantidadePalavrasSelect++;
    }
}

int verificaQuantidadePalavrasFrom(int quantidadePalavras, char **entradaSeparada){
    int posicaoFrom;
    //select a b c from a b c
    for (int i = 0; ; i++){
        if (strcmp(entradaSeparada[i], "from") == 0){
            posicaoFrom = i;
            break;
        }
    }

    for (int i = posicaoFrom; i < quantidadePalavras; i++){
        if ((strcmp(entradaSeparada[i], "where")) == 0){
            return i - posicaoFrom - 1;

        } else if (i == quantidadePalavras - 1){
            return quantidadePalavras - posicaoFrom - 1;
        }
    }

}

int verificaQuantidadePalavrasWhere(int quantidadePalavras, int quantidadePalavrasSelect, int quantidadePalavrasFrom){
    int quantidadePalavrasWhere = quantidadePalavras - quantidadePalavrasFrom - quantidadePalavrasSelect - 2;

    if (quantidadePalavrasWhere != 0){
        return quantidadePalavrasWhere - 1;
    } else {
        return quantidadePalavrasWhere;
    }
    
    
    return quantidadePalavras - quantidadePalavrasFrom - quantidadePalavrasSelect - 2;
}

void separaEntrada(char *entradaSemVirgula, char **entradaSeparada){
    char *t;
    t = strtok(entradaSemVirgula, " "); // SELCIONA STRING ATÉ ESPAÇO
    int i = 0;
    while(t != NULL){
        strcpy(entradaSeparada[i], t);
        t = strtok(NULL," ");
        i++;
    }
}

void mostraEntradaSeparada(char **entradaSeparada, int quantidadePalavras){
    for (int i = 0; i < quantidadePalavras; i++){
        printf("%s ", entradaSeparada[i]);
    }
}

void completaConteudoArray(char **array, int tamanhoArray){
    for (int i = 0; i < tamanhoArray; i++){
        strcpy(array[i], "none");
    }  
}

void armazenaConteudoFrom(char **conteudoFrom, char **entradaSeparada, int tamanhoConteudoFrom, int quantidadePalavras){
    int passouPeloFrom = 0;
    int posicaoFrom = 0;
    
    for (int posicaoEntrada = 0; posicaoFrom < tamanhoConteudoFrom; posicaoEntrada++){
        if (posicaoEntrada == quantidadePalavras){
            break;
        }
        if ((strcmp(entradaSeparada[posicaoEntrada], "where") == 0)){
            break;
        } 
        if (passouPeloFrom){
            strcpy(conteudoFrom[posicaoFrom], entradaSeparada[posicaoEntrada]);
            posicaoFrom++;
        }

        if (strcmp(entradaSeparada[posicaoEntrada], "from") == 0){
            passouPeloFrom = 1;
        }
        
    } 
}

void armazenaConteudoSelect(char **conteudoSelect, char **entradaSeparada, int tamanhoConteudoSelect){
    int posicaoSelect = 0;
    for (int posicaoEntrada = 1; strcmp(entradaSeparada[posicaoEntrada], "from") != 0; posicaoEntrada++, posicaoSelect++){
        strcpy(conteudoSelect[posicaoSelect], entradaSeparada[posicaoEntrada]);
    } 
}

void armazenaConteudoWhere(char **conteudoWhere, char **entradaSeparada, int tamanhoConteudoWhere, int quantidadePalavras){
    int posicaoWhere = 0;
    int passouPeloWhere = 0;
    for (int posicaoEntrada = 0; posicaoEntrada < quantidadePalavras; posicaoEntrada++){
        if(passouPeloWhere){
            strcpy(conteudoWhere[posicaoWhere], entradaSeparada[posicaoEntrada]);
            printf("O conteudo where vale: %s\n", conteudoWhere[posicaoWhere]);
            posicaoWhere++;
        }
        if ((strcmp(entradaSeparada[posicaoEntrada], "where")) == 0){
            passouPeloWhere = 1;
        }
        
    }
}
//Aqui tinha a função "abreArquivos" que está no arquivo: "abrindo-e-selecionando-arqs.c"

void liberaMemoria(char **matriz, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

/*
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