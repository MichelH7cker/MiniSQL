#ifndef __ARQUIVOS_H__          // entre arquivos
#define __ARQUIVOS_H__          // impede loop

/**
 * @param conteudoWhere quais são as colunas a serem comparadas no where
 * @param tamanhoConteudoWhere quantas palavras há no where
 * @return quantidade de iguais, ou seja, comparacoes que há no where
 */

int numdeIguais(char **conteudoWhere, int tamanhoConteudoWhere);

/**
 * 
 * 
 * @param conteudoWhere quais são as colunas a serem comparadas no where
 * @param tamanhoConteudoWhere quantas palavras há no where
 */
void comparacao(char **conteudoWhere, int tamanhoConteudoWhere);

#endif
