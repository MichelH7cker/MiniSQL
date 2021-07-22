#include <stdio.h> 
#include <stdlib.h>
#include<string.h>

int main(void){
    FILE *pont_arq;
    char cursor;
          
    pont_arq = fopen("Docentes.tsv","r");
    if (pont_arq == NULL){
        printf("Erro ao tentar abrir o arquivo!");
        exit(1);
    }

    int acumuladorTabs     = 0;
    int acumuladorLinhas   = 0;
    int coluna = 0;
    int i = 0;
    do{  
        cursor = fgetc(pont_arq);
        //printf("%c", cursor);
        
        if (cursor == '\t'){
            acumuladorTabs++;
        }
        if (cursor == '\n'){
            acumuladorTabs++;
            coluna += 6;
        }
        if (acumuladorTabs == coluna){
            printf("%c", cursor);
        }

        
        //printf("%c" , cursor);        
    } while (cursor != EOF);//enquanto não for final de arquivo 


    fclose(pont_arq);//fechando o arquivo
}