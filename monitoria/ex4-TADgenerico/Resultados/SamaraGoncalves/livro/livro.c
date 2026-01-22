#include "livro.h"
#include <stdio.h>
#include <stdlib.h>

/** @brief Estrutura do Livro, contendo:
 *
 * - Título
 *
 * - Autor
 *
 * - Gênero
 *
 * - Editora
 *
 * - Ano
 */
struct Livro
{
    char titulo[MAXTAM_STRINGS];
    char autor[MAXTAM_STRINGS];
    char genero[MAXTAM_STRINGS];
    char editora[MAXTAM_STRINGS];
    int ano;
};

/**
 * @brief Lê as informações de um livro, conforme as especificações, e o constrói.
 * Não é necessário alocar as strings dinamicamente, apenas o livro em si.
 * @return Um objeto do tipo livro lido da entrada padrão e devidamente alocado.
 */
Livro *livro_read_and_construct()
{
    Livro *liv;

    liv = (Livro *)calloc(1, sizeof(Livro));

    scanf("%s", liv->titulo);
    scanf(" %s", liv->autor);
    scanf(" %s", liv->genero);
    scanf(" %s", liv->editora);
    scanf("%d\n", &liv->ano);

    return liv;
}

/**
 * @brief Imprime todas as informações de um livro na tela, conforme as especificações.
 * @param l Livro a ser impresso (passado como void*, é preciso fazer typecast dentro da função).
 *
 *  Titulo: 1984
    Autor: George_Orwell
    Genero: Distopia
    Editora: Companhia_das_Letras
    Ano: 1949
 */
void livro_print(void *l)
{
    printf("LIVRO\n");
    printf("Titulo: %s\n", ((Livro *)l)->titulo);
    printf("Autor: %s\n", ((Livro *)l)->autor);
    printf("Genero: %s\n", ((Livro *)l)->genero);
    printf("Editora: %s\n", ((Livro *)l)->editora);
    printf("Ano: %d\n", ((Livro *)l)->ano);
}

/**
 * @brief Destrói um livro, liberando toda a memória alocada para ele.
 * @param l Livro a ser liberado (passado como void*, é preciso fazer typecast dentro da função).
 */
void livro_destroy(void *l)
{
    free(l);
}
