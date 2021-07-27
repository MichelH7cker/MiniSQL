#include<string.h>
#include<stdlib.h>

#include "arquivos.h"
#include "saida.h"

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
    
    for (int contadorComparacoes = 0; contadorComparacoes < quantidadeComparacao; contadorComparacoes++) {
        for (int i = 0; i <= 100; i++) {
            int l1 = 0;
            int linhasCompativeis[101];

            int colunaEscolhida;
            int tamanhoArquivo = 1;   
            for(int i = 0; i < quantidadeComparacao; i++) {
                char **arquivo1;                                                 
                alocaMemoria(arquivo1, tamanhoArquivo, 10); 
                char ***linhaColuna1;
                linhaColuna1 = malloc(sizeof(char**) * 101); // Linhas
                for (int i = 0; i < 101; i++) {
                    linhaColuna1[i] = malloc(sizeof(char*) * 1); // Colunas
                    for (int t = 0; t < 1; t++) {
                        linhaColuna1[i][t] = malloc(sizeof(char) * 100); //Char
                    }
                }

                selecionaArquivoColuna(whereFiltrado, quantidadeComparacao, arquivo1, i, &colunaEscolhida);
                if (strcmp(arquivo1[0], "none") == 0) break;
                abreArquivo(colunaEscolhida, arquivo1, linhaColuna1, 0);


                i++;
                char **arquivo2;                                                
                alocaMemoria(arquivo2, tamanhoArquivo, 10); 
                char ***linhaColuna2;
                linhaColuna2 = malloc(sizeof(char**) * 101); // Linhas
                for (int i = 0; i < 101; i++) {
                    linhaColuna2[i] = malloc(sizeof(char*) * 1); // Colunas
                    for (int t = 0; t < 1; t++) {
                        linhaColuna2[i][t] = malloc(sizeof(char) * 100); //Char
                    }
            }
            
            selecionaArquivoColuna(whereFiltrado, quantidadeComparacao, arquivo1, i, &colunaEscolhida);
            if (strcmp(arquivo1[0], "none") == 0) break;
            abreArquivo(colunaEscolhida, arquivo1, linhaColuna1, 0);

            for(int linha = 0; linha < 101; linha++) {
                if (strcmp(linhaColuna1[linha][0], linhaColuna2[linha][0]) == 0) {
                    linhasCompativeis[l1] = linha;
                    l1++; 
                }
            }
            if(contadorComparacoes == 0) {
                for (int i = 0; i < 101; i++) {
                    linhasIguaisRes[i] == linhasCompativeis[i];
                }
            }
            else {
                int contadorLinhasIguais = 0;
                for (int i = 0; i < 101; i++) {
                    if (linhasIguaisRes[i] == linhasCompativeis[i]) {
                        linhasIguaisRes[contadorLinhasIguais] == linhasCompativeis[i];
                        contadorLinhasIguais++;
                    }
                }
            }
            liberaMemoriaRobusta(linhaColuna1, 1);
            liberaMemoriaRobusta(linhaColuna2, 1);
            }
        }
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
