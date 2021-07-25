#ifndef __RECEBENDOENTRADA_H__     // entre arquivos
#define __RECEBENDOENTRADA_H__     // impede loop

void filtraEntrada(char *entrada, char *entradaSemVirgula);
/*
 * Função que retira todas as vírgulas  
 * e quebras de linhas  
 * (surgem por causa do fgets)
 */

int verificaQuantidadePalavras(char *entradaSemVirgula);

void separaEntrada(char *entradaSemVirgula, char **entradaSeparada);
/*
 * Cria um novo array para armazenar 
 * uma palavra em uma posição
 * (todas as palavras estão sem vírgulas)
 */

void mostraEntradaSeparada(char **entradaSeparada, int quantidadePalavras);
/*
 * Função para visualização
 */ 

void completaConteudoArray(char **array, int tamanhoArray);
/*
 * Preenche todas as posições do array
 * com uma palavra aleatória
 * Nesse caso, a palavra: "none"
 */

void armazenaConteudoFrom(char **conteudoFrom, char **entradaSeparada, int tamanhoConteudoFrom, int quantidadePalavras);
/*
 * Separa os arquivos a serem abertos pedidos na entrada
 * por meio da matriz: "conteudoFrom"  
 */

void armazenaConteudoSelect(char **conteudoSelect, char **entradaSeparada, int tamanhoConteudoSelect);
/*
 * Mesmo que o anterior, porém com Select
 */

void armazenaConteudoWhere(char **conteudoWhere, char **entradaSeparada, int tamanhoConteudoWhere, int quantidadePalavras);
/*
 * Mesmo que o anterior, porém com Where
 */

void liberaMemoria(char **matriz, int tamanho); 
/*
 * Desalocação de memória
 */

#endif