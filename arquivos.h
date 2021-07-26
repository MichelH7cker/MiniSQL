#ifndef __ARQUIVOS_H__          // entre arquivos
#define __ARQUIVOS_H__          // impede loop

struct {
    int Instituicao;            //
    int Programa;               //
    int Nivel;                  //
    int Sigla;                  //  Arquivo Progs.tsv
    int TemDoutorado;           //
    int Nome;                   //
    int AreadeAvaliacao;        //
} Progs;

struct {
    int AnodaTitulacao;         //
    int CodigoPPG;              //
    int Nacionalidade;          //  Arquivo Docentes.tsv
    int Nome;                   //
    int PaisdaInstituicao;      //
    int Sexo;                   //
} Docentes;

struct {
    int Ano;                    //
    int Autor;                  //
    int CodigoPPG;              //  Arquivo Trabalhos.tsv
    int Idioma;                 //
    int Orientador;             //
} Trabalhos;

/**
 * Função para visualização e saída
 * @param conteudoFrom array que guarda todas as informações do Select
 * @param tamanhoConteudoFrom quantidade de palavras que existe no conteudoSelect
 * @param arquivo carrega o arquivo a ser aberto
 * @param posicaoFrom
 */
void selecionaArquivos(char **conteudoFrom, int tamanhoConteudoFrom, char **arquivo, int posicaoFrom);

/**
 * @param conteudoSelect array que guarda todas as informações do Select
 * @param tamanhoSelect quantidade de palavras que existe no conteudoSelect
 * @param arquivo arquivo a ser aberto
 * @param colunaSelecionada coluna a ser armazenada
 * @param selectAtual qual palavra atual do conteudoSelect
 */
int escolheColunas(char **conteudoSelect, int tamanhoSelect, char **arquivo, int *colunaSelecionada, int *selectAtual); 

/**
 * Função para visualização e saída
 * @param colunaEntrada array que guarda todas as informações do Select
 * @param tamanhoSelect quantidade de palavras que existe no conteudoSelect
 */
void imprimeSaida(int *colunaEntrada, char **arquivo);

#endif