#ifndef __COMPARACAO_H__          // entre arquivos
#define __COMPARACAO_H__          // impede loop

/**
 * 
 * @param comandoWhere comando passado pela entrada na parte where
 * @param tamanhoComandoWhere quantidade de palavra contidas no comandoWhere
 * @param whereFiltrado contém apenas as colunas a serem comparadas
 */
void filtraComandoWhere(char **comandoWhere, int tamanhoComandoWhere, char **whereFiltrado);

/**
 * @param conteudoWhere quais são as colunas a serem comparadas no where
 * @param tamanhoConteudoWhere quantas palavras há no where
 * @return quantidade de iguais, ou seja, comparacoes que há no where
 */

int numdeIguais(char **conteudoWhere, int tamanhoConteudoWhere);

/**
 * 
 * @param conteudoWhere quais são as colunas a serem comparadas no where
 * @param tamanhoConteudoWhere quantas palavras há no where
 */
void comparaDados(int *linhasIguaisRes, char **conteudoWhere, int tamanhoConteudoWhere);

/**
 * verifica quais linhas podem ser imprimidas
 * @param linhasIguaisRes lista de linhas que podem ser imprimidas
 * @param comandoWhere comando passado pela entrada na parte where
 * @param tamanhoComandoWhere quantidade de palavra contidas no comandoWhere
 */
void verificaLinhasPermitidas(int *linhasIguaisRes, char **comandoWhere, int tamanhoComandoWhere);

#endif
