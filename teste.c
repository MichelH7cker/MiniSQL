#include <stdio.h> 
#include <stdlib.h>
#include<string.h>
/*
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
*/
int encontraArq (char *arquivo) {
    if (arquivo == "Docentes") {
        return 6;
    }
    if (arquivo == "Progs") {
        return 7;
    }
    return 5;
}

void imprimeColuna(int colunaEntrada, char *arquivo){
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

void separadaEntrada(char *entradaSemVirgula, char **entradaSeparada){
    char *t;
    t = strtok(entradaSemVirgula, " "); // SELCIONA STRING ATÉ ESPAÇO
    int i = 0;
    while(t != NULL){
        strcpy(entradaSeparada[i], t);
        t = strtok(NULL," ");
        //printf("%s \n", t);
        i++;
    }
}

void completaConteudoFrom(char **conteudoFrom, int tamanhoConteudoFrom){
    for (int i = 0; i < tamanhoConteudoFrom; i++){
        strcpy(conteudoFrom[i], "none");
        //printf("O conteudoFrom acabou de amarzenar: %s\n", conteudoFrom[i]);
    }  
}

void armazenaArquivosFrom(char **conteudoFrom, char **entradaSeparada, int quantidadePalavras){
    int passouPeloFrom = 0;
    int posicaoFrom = 0;
    // entradaSeparada = select a b c from Progs
    // conteudoFrom = none none none
    for (int posicaoEntrada = 0; posicaoEntrada < quantidadePalavras; posicaoEntrada++){
        if (strcmp(entradaSeparada[posicaoEntrada], "Where") == 0){
            break;
        }

        if (passouPeloFrom){
            strcpy(conteudoFrom[posicaoFrom], entradaSeparada[posicaoEntrada]);
            printf("O conteudoFrom acabou de armazenar: %s", conteudoFrom[posicaoFrom]);
            posicaoFrom++;
        }

        if (strcmp(entradaSeparada[posicaoEntrada], "from") == 0){
            passouPeloFrom = 1;
        }
        
    } 
}

void selecionaArquivo(char **conteudoFrom, int tamanhoConteudoFrom){
    for (int i = 0; i < tamanhoConteudoFrom; i++){
        char *arquivo;
        printf("O conteudo from em seleciona arquivo e: %s\n", conteudoFrom[i]);
        if (strcmp(conteudoFrom[i], "Progs") == 0){
            printf("entrei Progs\n");
            int coluna = 2;
            printf("%s\n", conteudoFrom[i]);
            arquivo = "Progs";
            imprimeColuna(coluna, arquivo);
        } else if(strcmp(conteudoFrom[i], "Docentes") == 0){
            printf("entrei em Docentes\n");
            int coluna = 5;
            printf("%s\n", conteudoFrom[i]);
            arquivo = "Docentes";
            imprimeColuna(coluna, arquivo);
        } else if(strcmp(conteudoFrom[i], "Trabalhos") == 0){
            printf("entrei em Trabalhos \n");
            int coluna = 0;
            printf("%s\n", conteudoFrom[i]);
            arquivo = "Trabalhos";
            imprimeColuna(coluna, arquivo);
        } /*else { //conteudoFrom não tem nada
            //printf("entrei em nada \n");
            break;
        }*/
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
            //strcpy(entradaSemVirgula[j], entrada[i]);
            entradaSemVirgula[j] = entrada[i];
            j++;
        }
    }
    //strcpy(entradaSemVirgula[j], '\0');
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
    //gets(entrada);
    //scanf("%s", entrada);
    fgets(entrada, 100, stdin);
    //strcat(entrada, " none");
    char entradaSemVirgula[100];
    
    filtraEntrada(entrada, entradaSemVirgula);
    //retiraQuebraDeLinhas(entrada,entradaSemVirgula);

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
    // from Progs Docentes none where
    //strcpy(entradaSeparada[quantidadePalavras - 1], "none"); // ULTIMA POSIÇÃO COM
    separadaEntrada(entradaSemVirgula, entradaSeparada);
    mostraEntradaSeparada(entradaSeparada, quantidadePalavras);
    completaConteudoFrom(conteudoFrom, tamanhoConteudoFrom);
    armazenaArquivosFrom(conteudoFrom, entradaSeparada, quantidadePalavras);
    //printf("%s\n", conteudoFrom[0]);      DEBUGANDO AGAIN
    selecionaArquivo(conteudoFrom, tamanhoConteudoFrom);
    liberaMemoria(entradaSeparada, quantidadePalavras);
    liberaMemoria(conteudoFrom, tamanhoConteudoFrom);
}
