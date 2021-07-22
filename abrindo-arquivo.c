#include <stdio.h> 
#include <stdlib.h>

int main(void){
    FILE *pont_arq;
    char c;
          
    pont_arq = fopen("Docentes.tsv","r");
    if (pont_arq == NULL){
        printf("Erro ao tentar abrir o arquivo!");
        exit(1);
    }
    printf("Lendo e exibindo os dados do arquivo \n\n");

    //Faça 
    do{  
        //faz a leitura do caracter no arquivo apontado por pont_arq
        
        c = fgetc(pont_arq);
        if (c == 'Nacionalidade'){
            printf("oi");
        }
        /*
        if (c == '\t'){
            printf("vai mudar de coluna! ");
        }

        if (c == '\n'){
            printf("vai pular a linha! \n");
        }*/
        //exibe o caracter lido na tela
        printf("%c" , c);        
    }while (c != EOF);//enquanto não for final de arquivo 
      
    fclose(pont_arq);//fechando o arquivo
}