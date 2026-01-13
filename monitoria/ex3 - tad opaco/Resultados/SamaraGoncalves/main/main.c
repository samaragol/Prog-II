#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "musica.h"
#include "playlist.h"

int main()
{
    char nome[MAX_TAM_STRING];
    int qtdAcoes = 0, i, acao;
    Playlist *play;
    char key[MAX_TAM_STRING];

    scanf("%[^\r]\r\n", nome);
    scanf("%d\r\n", &qtdAcoes);

    play = criaPlaylist(nome);

    for (i = 0; i < qtdAcoes; i++)
    {
        scanf("%d\r\n", &acao);

        if (acao == 1)
        {
            adicionaMusica(play);
        }
        else if (acao == 2)
        {
            scanf("%[^\r]\r\n", key);
            if (!(removeMusica(play, key, comparaNomeMus, imprimeMusica_Album)))
            {
                printf("A MUSICA NAO ESTA NA PLAYLIST\n");
            }
        }
        else if (acao == 3)
        {
            impressFunction(play, NULL, NULL, imprimeMusica);
        }
        else if (acao == 4)
        {
            scanf("%[^\r]\r\n", key);
            impressFunction(play, key, comparaArtistaMus, imprimeMusica_Artista);
        }
        else if (acao == 5)
        {
            scanf("%[^\r]\r\n", key);
            impressFunction(play, key, comparaAlbumMus, imprimeMusica_Album);
        }
        else if (acao == 6)
        {
            scanf("%[^\r]\r\n", key);
            impressFunction(play, key, comparaGeneroMus, imprimeMusica_Genero);
        }
    }
    apagaPlaylist(play);

    return 0;
}