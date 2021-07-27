#ifndef __ARQUIVOS_H__          // entre arquivos
#define __ARQUIVOS_H__          // impede loop



/**
 * Responsável por armazenar, tanto a coluna 
 * quanto o arquivo referente a essa coluna
 * @param comandoSelect são todas as informações contidas no select
 * @param tamanhocomandoSelect quantidade de palavras do comandoSelect
 * @param arquivo carrega a informação e qual arquivo será aberto
 * @param posicaoSelect palavra (análoga a coluna do arquivo) atual do comandoSelect
 * @param colunaEscolhida coluna que será armazenada na matriz de saída
 */
void selecionaArquivoColuna(char **comandoSelect, int tamanhocomandoSelect, char **arquivo, int posicaoSelect, int *colunaEscolhida);

/**
 * Função para visualização e saída
 * @param colunaEntrada array que guarda todas as informações do Select
 * @param tamanhoSelect quantidade de palavras que existe no comandoSelect
 */
void imprimeSaida(int *colunaEntrada, char **arquivo);

#endif