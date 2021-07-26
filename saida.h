#ifndef __SAIDA_H__          // impede loop
#define __SAIDA_H__          // entre arquivos

/**
 * Abre arquivos para começar a armazenar os dados
 * @param colunaSelecionada mostra qual a coluna da matriz do arquivo que será armazenada
 * @param arquivo carrega arquivo a ser aberto
 * @param saida
 * @param colunaMatriz coluna da matriz que deve ser preenchida
 */
void abreArquivo(int colunaSelecionada, char **arquivo, char ***saida, const int colunaAtualMatriz);

void preencheSaida(char ***saida, const int colunaSelecionada, const FILE *pArquivo, const int colunaAtualMatriz);

void preencheComNone(char ***saida, int tamanhoConteudoSelect);

void mostraMatriz(char ***saida, int tamanhoConteudoSelect);

/*
 * Libera a memória de uma matriz
 * de três dimensões, por isso o nome
 */
void liberaMemoriaRobusta(char ***saida, int tamanhoConteudoSelect);

#endif