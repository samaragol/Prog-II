#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "musica.h"

struct musica
{
    char nome[MAX_TAM_STRING];
    char artista[MAX_TAM_STRING];
    char album[MAX_TAM_STRING];
    char genero[MAX_TAM_STRING];
};

/**
 * @brief cria um dado do tipo musica, ponteiros devem receber NULL e atributos numericos 0
 * @return retorna a musica criada
 */
Musica *criaMusica()
{
    Musica *musica;

    musica = (Musica *)calloc(1, sizeof(*musica));

    return musica;
}

/**
 * @brief le os atributos de uma musica
 * @param music ponteiro para a musica
 */
void leMusica(Musica *music)
{
    char nome[MAX_TAM_STRING];
    char artista[MAX_TAM_STRING];
    char album[MAX_TAM_STRING];
    char genero[MAX_TAM_STRING];

    scanf("%[^\r]\r", nome);
    scanf("%[^\r]\r", artista);
    scanf("%[^\r]\r", album);
    scanf("%[^\r]\r", genero);

    strcpy(music->nome, nome);
    strcpy(music->artista, artista);
    strcpy(music->album, album);
    strcpy(music->genero, genero);
}

/**
 * @brief compara duas musicas
 * @param music_1 primeira musica
 * @param music_2 segunda musica
 * @return 1 se forem iguais e qualquer outro valor caso contrario
 */
int comparaMusicas(Musica *music_1, Musica *music_2)
{
    if (comparaNomeMus(music_1, music_2->nome) && comparaArtistaMus(music_1, music_2->artista))
    {
        return 1;
    }

    return 0;
}

/**
 * @brief compara o nome de uma musica com a string fornecida
 * @return 1 se forem iguais, 0 caso contrario
 */
int comparaNomeMus(Musica *music, char *name)
{
    if (!strcmp(music->nome, name))
    {
        return 1;
    }

    return 0;
}

/**
 * @brief compara o artista de uma musica com a string fornecida
 * @return 1 se forem iguais, 0 caso contrario
 */
int comparaArtistaMus(Musica *music, char *artist)
{
    if (!strcmp(music->artista, artist))
    {
        return 1;
    }

    return 0;
}

/**
 * @brief compara o album de uma musica com a string fornecida
 * @return 1 se forem iguais, 0 caso contrario
 */
int comparaAlbumMus(Musica *music, char *album)
{
    if (!strcmp(music->album, album))
    {
        return 1;
    }

    return 0;
}

/**
 * @brief compara o genero de uma musica com a string fornecida
 * @return 1 se forem iguais, 0 caso contrario
 */
int comparaGeneroMus(Musica *music, char *genre)
{
    if (!strcmp(music->genero, genre))
    {
        return 1;
    }

    return 0;
}

/**
 * @brief imprime uma musica no formato [nome] - [artista] ............ [album]
 * @param music musica a ser impressa
 */
void imprimeMusica(Musica *music)
{
    printf("%s - %s ............ %s\n", music->nome, music->artista, music->album);
}

/**
 * @brief imprime uma musica no formato [nome]
 * @param musica a ser impressa
 */
void imprimeMusica_Album(Musica *music)
{
    printf("%s\n", music->nome);
}

/**
 * @brief imprime uma musica no formato [nome] - [album]
 * @param musica a ser impressa
 */
void imprimeMusica_Artista(Musica *music)
{
    printf("%s - %s\n", music->nome, music->album);
}

/**
 * @brief imprime uma musica no formato [nome] - [artista]
 * @param music musica a ser impressa
 */
void imprimeMusica_Genero(Musica *music)
{
    printf("%s - %s\n", music->nome, music->artista);
}

/**
 * @brief desaloca uma musica da memoria
 * @param music musica a ser desalocada
 */
void apagaMusica(Musica *music)
{
    free(music);
}