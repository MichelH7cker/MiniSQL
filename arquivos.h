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

void selecionaArquivos(char **conteudoFrom, int tamanhoConteudoFrom, char **arquivo);

int escolheColunas(char **conteudoArray, int tamanhoArray, char **arquivo);

void imprimeColuna(int colunaEntrada, char **arquivo);

#endif