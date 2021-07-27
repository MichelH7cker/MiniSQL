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
 * Responsável por armazenar, tanto a coluna 
 * quanto o arquivo referente a essa coluna
 * @param conteudoSelect são todas as informações contidas no select
 * @param tamanhoConteudoSelect quantidade de palavras do conteudoSelect
 * @param arquivo carrega a informação e qual arquivo será aberto
 * @param posicaoSelect palavra (análoga a coluna do arquivo) atual do conteudoSelect
 * @param colunaEscolhida coluna que será armazenada na matriz de saída
 */
void selecionaArquivoColuna(char **conteudoSelect, int tamanhoConteudoSelect, char **arquivo, int posicaoSelect, int *colunaEscolhida);

/**
 * Função para visualização e saída
 * @param colunaEntrada array que guarda todas as informações do Select
 * @param tamanhoSelect quantidade de palavras que existe no conteudoSelect
 */
void imprimeSaida(int *colunaEntrada, char **arquivo);

#endif