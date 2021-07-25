#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "entrada.h"
#include "arquivos.h"

int main(){
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

    char **conteudoSelect;
    int tamanhoConteudoSelect = 4;
    conteudoSelect = malloc(sizeof(char*) * tamanhoConteudoSelect); 
    for (int i = 0; i < tamanhoConteudoSelect; i++) {
        conteudoSelect[i] = malloc(sizeof(char) * 50);
    }

    char **conteudoWhere;
    int tamanhoConteudoWhere = 4;
    conteudoWhere = malloc(sizeof(char*) * tamanhoConteudoWhere); 
    for (int i = 0; i < tamanhoConteudoWhere; i++) {
        conteudoWhere[i] = malloc(sizeof(char) * 50);
    }

    char **arquivo;
    int tamanhoArquivo = 1;
    arquivo = malloc(sizeof(char*) * tamanhoArquivo); 
    for (int i = 0; i < tamanhoArquivo; i++) {
        arquivo[i] = malloc(sizeof(char) * 50);
    }

    char **saida;
    int tamanhoSaida = 50;
    saida = malloc(sizeof(char*) * tamanhoSaida); 
    for (int i = 0; i < tamanhoSaida; i++) {
        saida[i] = malloc(sizeof(char) * 50);
    }

    int coluna;  
    // transformar num array e fazer um contandor na entrada no select

    separaEntrada(entradaSemVirgula, entradaSeparada);
    mostraEntradaSeparada(entradaSeparada, quantidadePalavras);

    completaConteudoArray(conteudoFrom, tamanhoConteudoFrom);                                          //                     
    armazenaConteudoFrom(conteudoFrom, entradaSeparada, tamanhoConteudoFrom, quantidadePalavras);      //
    completaConteudoArray(conteudoSelect, tamanhoConteudoSelect);                                      //
    armazenaConteudoSelect(conteudoSelect, entradaSeparada, tamanhoConteudoSelect);                    //
    completaConteudoArray(conteudoWhere, tamanhoConteudoWhere);                                        //
    armazenaConteudoWhere(conteudoWhere, entradaSeparada, tamanhoConteudoWhere, quantidadePalavras);  //                                                                 

    selecionaArquivos(conteudoFrom, tamanhoConteudoFrom, arquivo); 
    coluna = escolheColunas(conteudoSelect, tamanhoConteudoSelect, arquivo);
    printf("a coluna é: %d \n", coluna);
    // SEMPRE VERIFICAR SE O DICIONÁRIO ESTÁ CERTO
    imprimeColuna(coluna, arquivo);

    liberaMemoria(entradaSeparada, quantidadePalavras);     //                          //
    liberaMemoria(conteudoFrom, tamanhoConteudoFrom);       //                          //
    liberaMemoria(conteudoSelect, tamanhoConteudoSelect);   //      libera memória      //
    liberaMemoria(arquivo, tamanhoArquivo);                 //                          //
    liberaMemoria(saida, tamanhoSaida);                     //                          //
    liberaMemoria(conteudoWhere, tamanhoConteudoWhere);     //                          //
}

/*
select Progs.Sigla, Progs.Nome from Progs where Progs.Nivel = "7"

O programa se divide em 5 partes principais:
    - main
    - recebe entrada
    - abrindo selcionando arquivos
    - comparando campos
    - saída / imprimindo*/
