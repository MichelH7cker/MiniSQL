#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#include "arquivos.h"
#include "saida.h"
#include "comparacao.h"
#include "memoria.h"

#define LINHASAIDA 102    // LINHAS TOTAIS DA MATRIZ DE SAÍDA

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
    for (int i = 1; 1; i++){
        if ((strcmp(entradaSeparada[i], "from")) == 0){
            return quantidadePalavrasSelect;
        }
        quantidadePalavrasSelect++;
    }
}

int verificaQuantidadePalavrasFrom(int quantidadePalavras, char **entradaSeparada){
    int posicaoFrom;
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
        strcpy(array[i], "-");
    }  
}

void armazenaComandoFrom(char **comandoFrom, char **entradaSeparada, int tamanhoComandoFrom, int quantidadePalavras){
    int passouPeloFrom = 0;
    int posicaoFrom = 0;
    
    for (int posicaoEntrada = 0; posicaoFrom < tamanhoComandoFrom; posicaoEntrada++){
        if (posicaoEntrada == quantidadePalavras){
            break;
        }
        if ((strcmp(entradaSeparada[posicaoEntrada], "where") == 0)){
            break;
        } 
        if (passouPeloFrom){
            strcpy(comandoFrom[posicaoFrom], entradaSeparada[posicaoEntrada]);
            posicaoFrom++;
        }

        if (strcmp(entradaSeparada[posicaoEntrada], "from") == 0){
            passouPeloFrom = 1;
        }
        
    } 
}

void armazenaComandoSelect(char **comandoSelect, char **entradaSeparada, int tamanhoComandoSelect){
    int posicaoSelect = 0;
    for (int posicaoEntrada = 1; strcmp(entradaSeparada[posicaoEntrada], "from") != 0; posicaoEntrada++, posicaoSelect++){
        strcpy(comandoSelect[posicaoSelect], entradaSeparada[posicaoEntrada]);
    } 
}

void armazenaComandoWhere(char **comandoWhere, char **entradaSeparada, int tamanhoComandoWhere, int quantidadePalavras){
    int posicaoWhere = 0;
    int passouPeloWhere = 0;
    for (int posicaoEntrada = 0; posicaoEntrada < quantidadePalavras; posicaoEntrada++){
        if(passouPeloWhere){
            strcpy(comandoWhere[posicaoWhere], entradaSeparada[posicaoEntrada]);
            printf("O conteudo where vale: %s\n", comandoWhere[posicaoWhere]);
            posicaoWhere++;
        }
        if ((strcmp(entradaSeparada[posicaoEntrada], "where")) == 0){
            passouPeloWhere = 1;
        }
        
    }
}