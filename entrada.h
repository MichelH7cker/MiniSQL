#ifndef __RECEBENDOENTRADA_H__     // entre arquivos
#define __RECEBENDOENTRADA_H__     // impede loop

/**
 * função que retira todas as vírgulas  
 * e quebras de linhas (surgem por causa do fgets)
 * @param entrada variável que captura o texto de entrada
 * @param entradaSemVirgula input formatado: sem vírgulas e quebra de linhas
 */
void filtraEntrada(char *entrada, char *entradaSemVirgula);

/**
 * nome intuitivo
 * @param entradaSemVirgula input formatado: sem vírgulas e quebra de linhas
 */
int verificaQuantidadePalavrasTotal(char *entradaSemVirgula);

/**
 * cria um novo array para armazenar uma palavra em uma posição
 * @param entradaSemVirgula input formatado: sem vírgulas e quebra de linhas
 * @param entradaSeparada array onde cada posição é uma palavra do input
 */
void separaEntrada(char *entradaSemVirgula, char **entradaSeparada);

/**
 * nome intuitivo
 * @param entradaSeparada array onde cada posição é uma palavra do input
 */
int verificaQuantidadePalavrasSelect(char **entradaSeparada);

/**
 * nome intuitivo
 * @param quantidadePalavras quantidade de palavras totais da entrada
 * @param entradaSeparada array onde cada posição é uma palavra do input
 */
int verificaQuantidadePalavrasFrom(int quantidadePalavras, char **entradaSeparada);

/**
 * nome intuitivo
 * @param quantidadePalavras quantidade de palavras totais da entrada
 * @param quantidadePalavrasSelect quantidade de palavras do conteúdo referente ao select
 * @param quantidadePalavrasFrom quantidade de palavras do conteúdo referente ao from
 */
int verificaQuantidadePalavrasWhere(int quantidadePalavras, int quantidadePalavrasSelect, int quantidadePalavrasFrom);

/**
 * função para visualização
 * @param entradaSeparada array onde cada posição é uma palavra do input
 * @param quantidadePalavras quantidade de palavras totais da entrada
 */
void mostraEntradaSeparada(char **entradaSeparada, int quantidadePalavras);

/**
 * preenche todas as posições de um array genérico
 * com coisas aleatórias. Nesse caso, apenas com ""
 * @param array genérico
 * @param tamanhoArray quantidade de posições
 */
void completaConteudoArray(char **array, int tamanhoArray);

/**
 * separa os arquivos a serem abertos pedidos na entrada
 * por meio do array: "conteudoFrom" 
 * @param conteudoSelect array com conteúdo referente ao select
 * @param entradaSeparada array onde cada posição é uma palavra do input
 * @param tamanhoConteudoSelect quantidade de palavras do conteúdo referente ao select
 */
void armazenaConteudoSelect(char **conteudoSelect, char **entradaSeparada, int tamanhoConteudoSelect);

/**
 * separa os arquivos a serem abertos pedidos na entrada
 * por meio do array: "conteudoFrom"  
 * @param conteudoFrom array com conteúdo referente ao from
 * @param entradaSeparada array onde cada posição é uma palavra do input
 * @param tamanhoConteudoFrom quantidade de palavras referente ao conteúdo do from
 * @param quantidadePalavras quantidade de palavras totais da entrada
 */
void armazenaConteudoFrom(char **conteudoFrom, char **entradaSeparada, int tamanhoConteudoFrom, int quantidadePalavras);


/**
 * mesmo que o anterior, porém com Where
 * @param conteudoWhere array com conteúdo referente ao where
 * @param entradaSeparada array onde cada posição é uma palavra do input
 * @param tamanhoConteudoWhere
 * @param quantidadePalavras
 */
void armazenaConteudoWhere(char **conteudoWhere, char **entradaSeparada, int tamanhoConteudoWhere, int quantidadePalavras);

/**
 * desalocação de memória
 * @param matriz genérica
 * @param tamanho quantidade de linhas
 */
void liberaMemoria(char **matriz, int tamanho); 

#endif