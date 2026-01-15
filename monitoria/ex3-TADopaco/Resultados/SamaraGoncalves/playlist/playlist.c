#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "musica.h"
#include "playlist.h"

struct playlist
{
    char nomePlay[MAX_TAM_STRING];
    Musica *musicas[TAM_MAX_MUSICAS];
    int qtdMusicas;
};

/**
 * @brief cria uma playlist vazia com todas as posicoes do array de musicas como NULL
 */
Playlist *criaPlaylist(char *name)
{
    Playlist *play;
    play = (Playlist *)calloc(1, sizeof(Playlist));

    // boas práticas
    if (!play)
    {
        printf("Falha na criação da playlist.\n");
        exit(1);
    }

    if (name)
    {
        strncpy(play->nomePlay, name, MAX_TAM_STRING - 1);
    }

    return play;
}

/**
 * @brief adiciona uma musica em uma playlist
 * @param playlist playlist onde a musica sera adiconada
 */
void adicionaMusica(Playlist *playlist)
{
    Musica *mus;

    if (playlist->qtdMusicas < TAM_MAX_MUSICAS)
    {
        mus = criaMusica();
        if (!mus)
        {
            printf("Erro na função criaMusica.\n");
            exit(1);
        }
        leMusica(mus);
        playlist->musicas[playlist->qtdMusicas] = mus;
        playlist->qtdMusicas++;
    }
    else
    {
        printf("PLAYLIST CHEIA!\n");
    }
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
    int i, j, flag = 0;

    // programação defensiva
    if (!playlist || !comparador)
    {
        printf("Playlist ou comparador inválido.\n");
        return 0;
    }

    for (i = 0; i < playlist->qtdMusicas; i++)
    {
        // se o ponteiro nessa posição não é NULL e for a música correta
        if (playlist->musicas[i] && comparador(playlist->musicas[i], music))
        {
            if (impMus)
            {
                printf("MUSICA REMOVIDA: ");
                impMus(playlist->musicas[i]);
            }
            else
            {
                printf("Função impMus não definida.\n");
            }

            apagaMusica(playlist->musicas[i]);
            flag = 1;
            break;
        }
    }

    if (!flag)
    {
        return 0;
    }

    for (j = i; j < playlist->qtdMusicas - 1; j++)
    {
        playlist->musicas[j] = playlist->musicas[j + 1];
    }

    playlist->musicas[playlist->qtdMusicas - 1] = NULL;
    playlist->qtdMusicas--;

    return 1;
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
    printf("---------------------------------------\n");

    if (key)
    {
        printf("%s\n\n", key);
    }
    else
    {
        printf("%s\n\n", playlist->nomePlay);
    }

    for (i = 0; i < playlist->qtdMusicas; i++)
    {
        if ((!comparador || comparador(playlist->musicas[i], key)) && impMus)
        {
            impMus(playlist->musicas[i]);
        }
    }
    printf("---------------------------------------\n");
}

/**
 * @brief desaloca uma playlist da memoria
 * @param playlist playlist a ser deslocada
 */
void apagaPlaylist(Playlist *playlist)
{
    int i;

    if (!playlist)
    {
        printf("Deu ruim aqui.\n");
    }

    for (i = 0; i < playlist->qtdMusicas; i++)
    {
        if (playlist->musicas[i])
        {
            apagaMusica(playlist->musicas[i]);
        }
    }

    free(playlist);
}