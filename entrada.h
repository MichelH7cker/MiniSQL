#ifndef __ENTRADA_H__     // entre arquivos
#define __ENTRADA_H__     // impede loop

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
 * @param tamanhoComandoSelect quantidade de palavras do conteúdo referente ao select
 */
void armazenaComandoSelect(char **conteudoSelect, char **entradaSeparada, int tamanhoComandoSelect);

/**
 * separa os arquivos a serem abertos pedidos na entrada
 * por meio do array: "conteudoFrom"  
 * @param conteudoFrom array com conteúdo referente ao from
 * @param entradaSeparada array onde cada posição é uma palavra do input
 * @param tamanhoComandoFrom quantidade de palavras referente ao conteúdo do from
 * @param quantidadePalavras quantidade de palavras totais da entrada
 */
void armazenaComandoFrom(char **conteudoFrom, char **entradaSeparada, int tamanhoComandoFrom, int quantidadePalavras);


/**
 * mesmo que o anterior, porém com Where
 * @param conteudoWhere array com conteúdo referente ao where
 * @param entradaSeparada array onde cada posição é uma palavra do input
 * @param tamanhoComandoWhere
 * @param quantidadePalavras
 */
void armazenaComandoWhere(char **conteudoWhere, char **entradaSeparada, int tamanhoComandoWhere, int quantidadePalavras);


#endif