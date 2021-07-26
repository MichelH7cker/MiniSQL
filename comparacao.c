#include<string.h>

#include "arquivos.h"

int numdeIguais(char **conteudoWhere, int tamanhoConteudoWhere) {
    int numIguais = 0;
    for (int i = 0; i < tamanhoConteudoWhere; i++) {
        if(strcmp(conteudoWhere[i], '=') == 0) {
            numIguais++;
        }
    }
    return numIguais;
}

void comparacao(char **conteudoWhere, int tamanhoConteudoWhere) {
    int qtdComparacao = numdeIguais(conteudoWhere, tamanhoConteudoWhere);
    char colunasComparacoes[qtdComparacao][25];
    int colunasComparar = 0;
    for (int i = 0; i < tamanhoConteudoWhere; i++){
        if (strcmp(conteudoWhere[i],'=') == 0 || strcmp(conteudoWhere[i], "and") == 0) {
            strcpy(colunasComparacoes[colunasComparar], colunasComparacoes[colunasComparar]);
            colunasComparar++;
        }
    }
    
    int linhasCompativeis1[100];
    int linhasIguaisRes[100];
    for (int contadorComparacoes = 0; contadorComparacoes < qtdComparacao; contadorComparacoes++) {
        for (int i = 0; i < 100; i++) {
            int l1 = 0;
            for(int linha = 0; linha < 100; linha++) {
                if (linhaColuna1[linha] == linhaColuna2[linha]) {
                    linhasCompativeis1[l1] = linha;
                    l1++; 
                }
            }
            if(contadorComparacoes == 0) {
                for (int i = 0; i < 100; i++) {
                    linhasIguaisRes[i] == linhasCompativeis1[i];
                }
            }
            else {
                int contadorLinhasIguais = 0;
                for (int i = 0; i < 100; i++) {
                    if (linhasIguaisRes[i] == linhasCompativeis1[i]) {
                        linhasIguaisRes[contadorLinhasIguais] == linhasCompativeis1[i];
                        contadorLinhasIguais++;
                    }
                }
            }
        }
    }
}

    

/*
- comparar o conteudo de duas colunas, os conteudos que forem iguais serao salvos em 
uma terceira matriz junto com suas respectivas linha (não necessariamente na mesma matriz)

- caso tenha mais comparacoes, outras matrizes de comparacoes serao separadas com suas linhas,
quanto mais comparacoes tiver, mais matrizes de comparacoes vai ter

- com todos os vetores de linhas prontos, basta compará-los entre si e com o vetor de linhas resultante
compará-lo com sua coluna do select, vai retornar uma matriz de comparacao para printar junto a resposta
*/
