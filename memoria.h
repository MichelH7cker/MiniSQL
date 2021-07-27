#ifndef __MEMORIA_H__          // entre arquivos
#define __MEMORIA_H__ 

/**
 * 
 * @param matriz matriz que vai ser alocada a memoria
 * @param tamanho quantidade de linhas da matriz
 * @param conteudo quantidade de colunas da matriz, ou seja, quantidade de letras de cada linha
 */
void alocaMemoria(char **matriz, int tamanho, int conteudo);

void alocaMemoriaRobusta(char ***matrizRobusta, int tamanho, int charTamanhoMatriz);

/**
 * desalocação de memória
 * @param matriz genérica
 * @param tamanho quantidade de linhas
 */
void liberaMemoria(char **matriz, int tamanho); 

/**
 * Libera a memória de uma matriz
 * de três dimensões, por isso o nome
 */
void liberaMemoriaRobusta(char ***matrizRobusta, int tamanhoArray);

#endif