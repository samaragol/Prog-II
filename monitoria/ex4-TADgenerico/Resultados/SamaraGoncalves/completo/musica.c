#include <stdio.h>
#include <stdlib.h>
#include "musica.h"

/**
 * @brief Estrutura da Música, contendo:
 *
 * - Título
 *
 * - Artista
 *
 * - Número de participantes
 *
 * - Participantes (vetor)
 *
 * - Álbum
 *
 * - Gênero
 */
struct Musica
{
    char titulo[MAXTAM_STRINGS];
    char artista[MAXTAM_STRINGS];
    int qtdPar;
    char **part;
    char album[MAXTAM_STRINGS];
    char genero[MAXTAM_STRINGS];
};

/**
 * @brief Lê as informações de uma música, conforme as especificações, e a constrói.
 * Não é necessário alocar as strings dinamicamente, apenas a música em si.
 * @return Um objeto do tipo música lido da entrada padrão e devidamente alocado.
 */
Musica *musica_read_and_construct()
{
    Musica *mus;
    int i;

    mus = (Musica *)calloc(1, sizeof(Musica));
    scanf("%s", mus->titulo);
    scanf(" %s", mus->artista);
    scanf("%d", &mus->qtdPar);
    mus->part = (char **)calloc(mus->qtdPar, sizeof(char *));
    for (i = 0; i < mus->qtdPar; i++)
    {
        mus->part[i] = (char *)calloc(MAXTAM_STRINGS, sizeof(char));
        scanf(" %s", mus->part[i]);
    }
    scanf(" %s", mus->album);
    scanf(" %s\n", mus->genero);

    return mus;
}

/**
 * @brief Imprime todas as informações de uma música na tela, conforme as especificações.
 * @param m música a ser impressa (passada como void*, é preciso fazer typecast dentro da função).
 *
 *  MIDIA 2: MUSICA
    Queen - Bohemian_Rhapsody (feat. Freddie_Mercury, Brian_May, Roger_Taylor)
    Album: A_Night_at_the_Opera
    Genero: Rock
 */
void musica_print(void *m)
{
    int i;

    printf("MUSICA\n");
    printf("%s - %s (feat. ", ((Musica *)m)->artista, ((Musica *)m)->titulo);
    for (i = 0; i < ((Musica *)m)->qtdPar; i++)
    {
        if (i < ((Musica *)m)->qtdPar - 1)
        {
            printf("%s, ", ((Musica *)m)->part[i]);
        }
        else
        {
            printf("%s)\n", ((Musica *)m)->part[i]);
        }
    }
    printf("Album: %s\n", ((Musica *)m)->album);
    printf("Genero: %s\n", ((Musica *)m)->genero);
}

/**
 * @brief Destrói uma música, liberando toda a memória alocada para ela.
 * @param m música a ser liberada (passada como void*, é preciso fazer typecast dentro da função).
 */
void musica_destroy(void *m)
{
    int i;

    for (i = 0; i < ((Musica *)m)->qtdPar; i++)
    {
        free(((Musica *)m)->part[i]);
    }

    free(((Musica *)m)->part);
    free(m);
}