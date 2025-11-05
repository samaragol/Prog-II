#include "jogador.h"
#include "jogada.h"
#include "tabuleiro.h"
#include <stdio.h>

/**
 * Cria um jogador com o id passado como parâmetro e retorna o jogador criado.
 *
 * @param idJogador o id do jogador (1 ou 2).
 *
 * @return tJogador o jogador criado.
 */
tJogador CriaJogador(int idJogador)
{
    tJogador jogador;

    jogador.id = idJogador;

    return jogador;
}

/**
 * Recebe um jogador e um tabuleiro e retorna o tabuleiro com a jogada do jogador.
 *
 * @param jogador o jogador que fará a jogada.
 * @param tabuleiro o tabuleiro atual.
 *
 * @return o tabuleiro atualizado com a jogada do jogador.
 */
tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro)
{
    tJogada jogada;

    while (1)
    {
        printf("Jogador %d\n", jogador.id);

        jogada = LeJogada();

        if (!EhPosicaoValidaTabuleiro(ObtemJogadaX(jogada), ObtemJogadaY(jogada)))
        {
            printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
        }
        else if (!EstaLivrePosicaoTabuleiro(tabuleiro, ObtemJogadaX(jogada), ObtemJogadaY(jogada)))
        {
            printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
        }
        else
        {

            tabuleiro = MarcaPosicaoTabuleiro(tabuleiro, jogador.id, ObtemJogadaX(jogada), ObtemJogadaY(jogada));
            return tabuleiro;
        }
    }
}

/**
 * Recebe um jogador e um tabuleiro e retorna 1 se o jogador venceu e 0 caso contrário.
 *
 * @param jogador o jogador a ser verificado.
 * @param tabuleiro o tabuleiro atual.
 *
 * @return 1 se o jogador venceu, 0 caso contrário.
 */
int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro)
{
    // int i, j, contador = 0, linha[] = {-1, -1, -1, -1, -1}, coluna[] = {-1, -1, -1, -1, -1}, ig_lin = 1, ig_col = 1, ig_dia_e = 1, ig_dia_d = 1;

    // for (i = 0; i < TAM_TABULEIRO; i++)
    // {
    //     for (j = 0; j < TAM_TABULEIRO; j++)
    //     {
    //         if (EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, i, j, jogador.id))
    //         {
    //             linha[contador] = i;
    //             coluna[contador] = j;
    //             contador++;
    //         }
    //     }
    // }

    // if (contador >= 3)
    // {
    //     for (i = 1; i < contador; i++)
    //     {
    //         if (linha[i - 1] != linha[i])
    //         {
    //             ig_lin = 0;
    //         }
    //         if (coluna[i - 1] != coluna[i])
    //         {
    //             ig_col = 0;
    //         }
    //     }

    //     for (i = 0, j = contador - 1; i < contador; i++, j--)
    //     {
    //         if (linha[i] != coluna[i])
    //         {
    //             ig_dia_e = 0;
    //         }
    //         if (linha[i] != i || coluna[j] != j)
    //         {
    //             ig_dia_d = 0;
    //         }
    //     }

    //     if (ig_lin || ig_col || ig_dia_e || ig_dia_d)
    //     {
    //         return 1;
    //     }
    // }

    // return 0;
}