#include <string.h>
#include <stdlib.h>

#include "arquivos.h"
#include "saida.h"
#include "memoria.h"

int verificaQuantidadeDeIguais(char **comandoWhere, int tamanhoComandoWhere) {
    int numIguais = 0;
    for (int i = 0; i < tamanhoComandoWhere; i++) {
        if(strcmp(comandoWhere[i], "=") == 0) {
            numIguais++;
        }
    }
    return numIguais;
}

void filtraComandoWhere(char **comandoWhere, int tamanhoComandoWhere, char **whereFiltrado){
    int colunaParaComparacao = 0;
    for (int posicaoComandoWhere = 0; posicaoComandoWhere < tamanhoComandoWhere; posicaoComandoWhere++){
        if (strcmp(comandoWhere[posicaoComandoWhere], "=") == 0 || strcmp(comandoWhere[posicaoComandoWhere], "and") == 0) {

            strcpy(whereFiltrado[colunaParaComparacao], comandoWhere[posicaoComandoWhere]);
            colunaParaComparacao++;
        }
    }
}

void comparaDados(int *linhasIguaisRes, char **comandoWhere, int tamanhoComandoWhere) {
    int quantidadeComparacao = verificaQuantidadeDeIguais(comandoWhere, tamanhoComandoWhere);
    char *whereFiltrado[quantidadeComparacao];

    filtraComandoWhere(comandoWhere, tamanhoComandoWhere, whereFiltrado);
    
    int linhasCompativeis[101];
    int guardaLinhas[101];

    for (int contadorComparacoes = 0; contadorComparacoes < quantidadeComparacao; contadorComparacoes++) { // percorre todo o comando where
        for (int i = 0; i < 2; i++) {
            int colunaEscolhida;
            int tamanhoArquivo = 1;  
            
            char **arquivo;
            alocaMemoria(arquivo, tamanhoArquivo, 10);

            char ***linhaColuna1;
            alocaMemoriaRobusta(linhaColuna1, 101, 100);
            linhaColuna1 = malloc(sizeof(char**) * 101);

            char ***linhaColuna2;
            alocaMemoriaRobusta(linhaColuna2, 101, 100);
            linhaColuna2 = malloc(sizeof(char**) * 101);
 

            for(int i = 0; i < quantidadeComparacao; i += 2) {
                selecionaArquivoColuna(whereFiltrado, quantidadeComparacao, arquivo, i, &colunaEscolhida);
                if (strcmp(arquivo[0], "none") == 0) break;
                abreArquivo(colunaEscolhida, arquivo, linhaColuna1, 0);
            }
            
            selecionaArquivoColuna(whereFiltrado, quantidadeComparacao, arquivo, i, &colunaEscolhida);

            if (strcmp(arquivo[0], "none") == 0) break;
            abreArquivo(colunaEscolhida, arquivo, linhaColuna1, 0);

            for(int linha = 0; linha < 101; linha++) {
                if (strcmp(linhaColuna1[linha][0], linhaColuna2[linha][0]) == 0) {
                    linhasCompativeis[linha] = 1; 
                }
                else {
                    linhasCompativeis[linha] = 0;
                }
            }

            if(contadorComparacoes == 0) {
                for (int i = 0; i < 101; i++) {
                    guardaLinhas[i] == linhasCompativeis[i];
                }
            }
            else {
                for (int contadorLinhas = 0; contadorLinhas < 101; contadorLinhas++) {
                    if (linhasCompativeis[i] == guardaLinhas[i]) {

                    }
                    else {
                        guardaLinhas[contadorLinhas] == 0;
                    }
                }
            }
            liberaMemoriaRobusta(linhaColuna1, 1);
            liberaMemoriaRobusta(linhaColuna2, 1);
            }
        }
    }

    for (int linha = 0; linha < 101; linha++) {
        if(linhasIguaisRes[linha] != guardaLinhas[linha]) {
            linhasIguaisRes[linha] = 0;
        }
        printf("%d ", linhasIguaisRes[linha]);
    }

}

void verificaLinhasPermitidas(int *linhasIguaisRes, char **comandoWhere, int tamanhoComandoWhere) {
    if(tamanhoComandoWhere > 0) {
        comparaDados(linhasIguaisRes, comandoWhere, tamanhoComandoWhere);
    }
    else {
        for(int i = 0; i <= 100; i++) {
            linhasIguaisRes[i] = i;
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