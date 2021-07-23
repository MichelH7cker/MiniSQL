#include <stdio.h> 
#include <stdlib.h>
#include<string.h>

#define INSTITUICAO 0;                      //
#define PROGRAMA 1;                         //
#define NIVEL 2;                            //
#define SIGLA 3;                            //  Progs
#define TEMDOUTORADO 4;                     //
#define NOME 5;                             //
#define AREADEAVALIACAO 6;                  //

#define ANOTITULACAO 0;                     //
#define CODIGOPPG 1;                        //
#define NACIONALIDADE 2;                    //  Docentes
#define NOME 3;                             //
#define PAISDAINSTITUICAO 4;                //
#define SEXO 5;                             //        

#define ANO 0;                              //
#define AUTOR 1;                            //
#define CODIGOPPG 2;                        //  Trabalhos
#define IDIOMA 3;                           //
#define ORIENTADOR 4;                       //

int encontraArq (char *arquivo) {
    if (arquivo == "Docentes") {
        return 6;
    }
    if (arquivo == "Progs") {
        return 7;
    }
    return 5;
}

void impColuna(int colunaEntrada, char *arquivo){
    FILE *pont_arq;
    char cursor;
    int tamanhoArq = encontraArq(arquivo);
    if (tamanhoArq == 7) {
        pont_arq = fopen("Progs.tsv","r");
    }
    else if (tamanhoArq == 5) {
        pont_arq = fopen("Trabalhos.tsv","r");
    }
    else {
        pont_arq = fopen("Docentes.tsv","r");
    }
    
    if (pont_arq == NULL){
        printf("Erro ao tentar abrir o arquivo!");
        exit(1);
    }

    int acumuladorTabs     = 0;
    int acumuladorLinhas   = 0;
    int idColunaInicial = colunaEntrada;            //numero de qual coluna é
    int coluna = idColunaInicial;
    do{  
        cursor = fgetc(pont_arq);
        //printf("%c", cursor);
        
        if (acumuladorTabs == coluna && acumuladorTabs >= tamanhoArq){
            printf("%c", cursor);
        }
        if (cursor == '\t'){
            acumuladorTabs++;
        }
        
        if (cursor == '\n'){
            acumuladorTabs++;
            coluna += tamanhoArq;
            if (idColunaInicial < tamanhoArq - 1 && acumuladorTabs > tamanhoArq) {
                printf("\n"); 
            }          //serve pra quase todas as colunas, menos a ultima (da um enter a mais do que precisa)
        }

        //printf("%c" , cursor);        
    } while (cursor != EOF);//enquanto não for final de arquivo 


    fclose(pont_arq);//fechando o arquivo
}

int main(void) {
    int coluna = 0;
    char *arquivo = "Trabalhos";
    impColuna(coluna, arquivo);
}
