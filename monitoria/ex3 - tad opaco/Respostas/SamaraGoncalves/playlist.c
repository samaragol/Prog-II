#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "musica.h"
#include "playlist.h"

struct playlist
{
    char nomePlay[MAX_TAM_STRING];
    char **musicas;
    int qtdMusicas;
};

/**
 * @brief cria uma playlist vazia com todas as posicoes do array de musicas como NULL
 */
Playlist *criaPlaylist(char *name)
{
    Playlist *play;
    play = (Playlist *)calloc(1, sizeof(play));
    play->musicas = (Musica **)calloc(TAM_MAX_MUSICAS, sizeof(Musica *));
    strcpy(play->nomePlay, name);
    play->qtdMusicas = 0;
    return play;
}

/**
 * @brief adiciona uma musica em uma playlist
 * @param playlist playlist onde a musica sera adiconada
 */
void adicionaMusica(Playlist *playlist)
{
    Musica *mus;

    mus = criaMusica();
    leMusica(mus);
    playlist->musicas[playlist->qtdMusicas] = mus;
    playlist->qtdMusicas++;
}

/**
 * @brief remove uma musica de uma playlist
 * @param playlist playlist a ter a musica removida
 * @param music nome da musica a ser removida
 * @param impMus ponteiro para funcao de impressao de musica
 * @return 1 caso a musica seja removida com sucesso e 0 caso o contrario
 */
int removeMusica(Playlist *playlist, char *music, compara comparador, tipoImpressaoMusica impMus)
{
    int i;

    for (i = 0; i < playlist->qtdMusicas; i++)
    {
        if (comparador(playlist->musicas[i], music))
        {
            printf("MUSICA REMOVIDA: ");
            impMus(music);
            free(playlist->musicas[i]);
            playlist->qtdMusicas--;
            return 1;
        }
    }
    return 0;
}

/**
 * @brief Função genérica que realiza impressões filtradas na playlist (todas as impressoes sao feitas por essa funcao)
 * @param playlist playlist a ser percorrida
 * @param key chave de busca (por exemplo: nome do artista)
 * @param modo função que implementa o modo de impressão/filtragem
 *             (ex.: `imprimePorArtista`).
 * @param impMus ponteiro para funcao de impressao de musica.
 *
 * Dica: ponteiros para função também podem ser NULL
 */
void impressFunction(Playlist *playlist, char *key, compara comparador, tipoImpressaoMusica impMus)
{
    int i;

    for (i = 0; i < playlist->qtdMusicas; i++)
    {
        if (comparador(playlist->musicas[i], key))
        {
            impMus(playlist->musicas[i]);
        }
    }
}

/**
 * @brief desaloca uma playlist da memoria
 * @param playlist playlist a ser deslocada
 */
void apagaPlaylist(Playlist *playlist)
{
    int i;

    for (i = 0; i < playlist->qtdMusicas; i++)
    {
        free(playlist->musicas[i]);
    }

    free(playlist);
}