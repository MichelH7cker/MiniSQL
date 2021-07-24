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

void completaConteudoFrom(char **conteudoFrom){
    for (int i = 0; i < 3; i++){
        strcpy(conteudoFrom[i], "none");
    }  
}

void armazenaArquivosFrom(char **conteudoFrom, char **entradaSeparada){
    int passouPeloFrom = 0;
    int posicaoFrom = 0;
    int posicaoEntrada = 0;
    while ((strcmp(entradaSeparada[posicaoEntrada], "where") != 0) /*|| (entradaSeparada[posicaoEntrada] != "\0")*/ ){
        if (passouPeloFrom){
            strcpy(conteudoFrom[posicaoFrom], entradaSeparada[posicaoEntrada]);
            posicaoFrom++;
        }
        if (strcmp(entradaSeparada[posicaoEntrada], "from") == 0){
            passouPeloFrom = 1;
        }
        posicaoEntrada++;
    }
}

void selecionaArquivo(char **conteudoFrom){
    char arquivo;
    for (int i = 0; i < 3; i++){
        if (strcmp(conteudoFrom[i], "Progs") == 0){
            int coluna = 0;
            arquivo = "Progs";
            imprimeColuna(coluna, arquivo);
        }
        else if(strcmp(conteudoFrom[i], "Docentes") == 0){
            int coluna = 0;
            arquivo = "Docentes";
            imprimeColuna(coluna, arquivo);
        }
        else if(strcmp(conteudoFrom[i], "Trabalhos") == 0){
            int coluna = 0;
            arquivo = "Trabalhos";
            imprimeColuna(coluna, arquivo);
        }
        /*else { //conteudoFrom não tem nada
            printf("entrei em nada \n");
            break;
        }*/
    }
}

void retiraVirgula(char *entrada, char *entradaSemVirgula){    
    int j = 0;
    for (int i = 0; entrada[i] != '\0'; i++){
        if (entrada[i] != ','){ 
            entradaSemVirgula[j] = entrada[i];
            j++;
        }
    }
    entradaSemVirgula[j] = '\0';
}

void mostraEntradaSeparada(char **entradaSeparada, int quantidadePalavras){
    for (int i = 0; i < quantidadePalavras; i++){
        printf("%s \n", entradaSeparada[i]);
    }
}

int verificaQuantidadePalavras(char *entrada){
    int quantidade = 1;
    int i = 0;
    while (entrada[i] != '\0'){
        if (entrada[i] == ' '){
            quantidade++;
        } 
        i++;
    }
    return quantidade;
}

void liberaMemoria(char **entradaSeparada, int quantidadePalavras) {
    for (int i = 0; i < quantidadePalavras; i++) {
        free(entradaSeparada[i]);
    }
    free(entradaSeparada);
}

int main(void){
    char entrada[130];
    fgets(entrada, 130, stdin);

    char entradaSemVirgula[130];
    retiraVirgula(entrada, entradaSemVirgula);

    int quantidadePalavras = verificaQuantidadePalavras(entradaSemVirgula);

    // MALLOC
    char **entradaSeparada;
    entradaSeparada = malloc(sizeof(char*) * quantidadePalavras); //malloc
    for (int i = 0; i < quantidadePalavras; i++) {
        entradaSeparada[i] = malloc(sizeof(char) * 50);
    }

    char *t;
    t = strtok(entradaSemVirgula, " "); //pega string até chegar em um espaço
    int i = 0;
    while(t != NULL){
        strcpy(entradaSeparada[i], t);
        t = strtok(NULL," ");
        i++;
    }

    mostraEntradaSeparada(entradaSeparada, quantidadePalavras); 

    // MALLOC
    char **conteudoFrom;
    conteudoFrom = malloc(sizeof(char*) * 3); //malloc
    for (int i = 0; i < 3; i++) {
        conteudoFrom[i] = malloc(sizeof(char) * 50);
    }

    completaConteudoFrom(conteudoFrom);
    armazenaArquivosFrom(conteudoFrom, entradaSeparada);
    printf("%s\n", conteudoFrom[0]);
    selecionaArquivo(conteudoFrom);
    liberaMemoria(entradaSeparada, quantidadePalavras);
}
