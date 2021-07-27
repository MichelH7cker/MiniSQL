#ifndef __COMPARACAO_H__          // entre arquivos
#define __COMPARACAO_H__          // impede loop

/**
 * @param comandoWhere quais são as colunas a serem comparadas no where
 * @param tamanhocomandoWhere quantas palavras há no where
 * @param linhaIguais quantidade de iguais, ou seja, comparacoes que há no where
 */
int verificaQuantidadeDeIguais(char **comandoWhere, int tamanhoComandoWhere);

/**
 * Verifica quais linhas passam pela comparacação booleana.
 * As linhas que passarem serão impressas na matriz de saída
 * @param comandoWhere array com conteúdo referente ao where
 * @param tamanhoComandoWhere quantidade de palavras do conteúdo referente ao where
 * @param linhasIguais linhas que são verdadeiras na comparação
 */
void verificaLinhasPermitidas(char **comandoWhere, int tamanhoComandoWhere, int *linhasIguais);

/**
 * 
 * 
 * @param comandoWhere quais são as colunas a serem comparadas no where
 * @param tamanhocomandoWhere quantas palavras há no whsere
 */
void comparaDados(int **linhasIguais, char ***comandoWhere, int tamanhoComandoWhere);

#endif