#ifndef __SAIDA_H__          // impede loop
#define __SAIDA_H__          // entre arquivos

/**
 * Abre arquivos para começar a armazenar os dados
 * @param colunaSelecionada mostra qual a coluna da matriz do arquivo que será armazenada
 * @param arquivo carrega arquivo a ser aberto
 * @param saida
 * @param colunaMatriz coluna da matriz que deve ser preenchida
 */
void abreArquivo(int colunaEscolhida, char **arquivo, char ***saida, const int colunaAtualMatriz);

/**
 * Função para armazenar todas as informações
 * necessárias para o output e pedidas durante a entrada
 * @param saida matriz de saída
 * @param colunaEscolhida coluna a ser armazenada na matriz de saída 
 * @param pArquivo ponteiro do tipo FILE
 * @param colunaAtualMatriz coluna da matriz em que os dados serão armazenados 
 */
void armazenaDadosSaida(char ***saida, const int *colunaEscolhida, FILE *pArquivo, const int colunaAtualMatriz);

/**
 * Ocupa todas as posições da matriz de saída 
 * com espaços em brancos. 
 * Propósito: não causar segmentation fault
 * @param saida matriz de saída
 * @param tamanhoConteudoSelect quantidade de colunas da matriz de saída
 */
void ocupaConteudoSaida(char ***saida, int tamanhoConteudoSelect);


/**
 * Função de visualização e output 
 * @param saida matriz de sáida
 * @param tamanhoConteudoSelect quantidade de colunas da matriz de saída
 */
void imprimeMatriz(char ***saida, int tamanhoConteudoSelect);

/**
 * Libera a memória de uma matriz
 * de três dimensões, por isso o nome
 * @param saida matriz de saída
 * @param tamanhoConteudoSelect quantidade de colunas da matriz de saída
 */
void liberaMemoriaRobusta(char ***saida, int tamanhoConteudoSelect);

#endif