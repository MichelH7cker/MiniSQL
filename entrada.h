#ifndef __RECEBENDOENTRADA_H__     // entre arquivos
#define __RECEBENDOENTRADA_H__     // impede loop

void filtraEntrada(char *entrada, char *entradaSemVirgula);

int verificaQuantidadePalavras(char *entradaSemVirgula);

void separaEntrada(char *entradaSemVirgula, char **entradaSeparada);

void mostraEntradaSeparada(char **entradaSeparada, int quantidadePalavras);

void completaConteudoArray(char **array, int tamanhoArray);

void armazenaConteudoFrom(char **conteudoFrom, char **entradaSeparada, int tamanhoConteudoFrom, int quantidadePalavras);

void armazenaConteudoSelect(char **conteudoSelect, char **entradaSeparada, int tamanhoConteudoSelect);

void armazenaConteudoWhere(char **conteudoWhere, char **entradaSeparada, int tamanhoConteudoWhere, int quantidadePalavras);

void liberaMemoria(char **matriz, int tamanho);

#endif