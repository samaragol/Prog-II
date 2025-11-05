#include <stdio.h>
#include <string.h>
#include "eleicao.h"

/**
 * @brief Inicializa uma eleição com valores padrão (zerando os votos invalidos).
 * Ainda nessa função, é lido a quantidade de candidatos e os candidatos são lidos e armazenados.
 * @return Eleição inicializada.
 */
tEleicao InicializaEleicao()
{
    tEleicao e;
    tCandidato c;
    int qtdCandidatos, i;

    e.totalPresidentes = 0;
    e.totalGovernadores = 0;
    e.totalEleitores = 0;
    e.votosBrancosGovernador = 0;
    e.votosBrancosPresidente = 0;
    e.votosNulosGovernador = 0;
    e.votosNulosPresidente = 0;

    scanf("%d\n", &qtdCandidatos);

    for (i = 0; i < qtdCandidatos; i++)
    {
        c = LeCandidato();
        if (ObtemCargo(c) == 'P')
        {
            e.presidentes[e.totalPresidentes] = c;
            e.totalPresidentes++;
        }
        else if (ObtemCargo(c) == 'G')
        {
            e.governadores[e.totalGovernadores] = c;
            e.totalGovernadores++;
        }
    }

    return e;
}

/**
 * @brief Realiza uma eleição.
 * Nessa função, é lido a quantidade de eleitores e os eleitores são lidos e armazenados.
 * @param eleicao Eleição a ser realizada.
 * @return Eleição com os resultados da votação.
 */
tEleicao RealizaEleicao(tEleicao eleicao)
{
    int i, qtdEleitores;

    scanf("%d\n", &qtdEleitores);

    for (i = 0; i < qtdEleitores; i++)
    {
        eleicao.eleitores[eleicao.totalEleitores] = LeEleitor();
        eleicao.totalEleitores++;
    }

    return eleicao;
}

/**
 *

    - PRESIDENTE ELEITO: Edsger Dijkstra (Partido do Melhor Caminho (PMC)), 3 voto(s), 100.00%
    - GOVERNADOR ELEITO: Ada Lovelace (Gamers Unidos (GU)), 2 voto(s), 66.67%
    - NULOS E BRANCOS: 0, 0

 * @brief Imprime o resultado da eleição na tela a partir da aparucao dos votos.
 * @param eleicao Eleição a ser impressa.
 */
void ImprimeResultadoEleicao(tEleicao eleicao)
{
    tCandidato candEleito;
    int i;

    for (i = 1; i < eleicao.totalPresidentes; i++)
    {
        if (ObtemVotos(eleicao.presidentes[i - 1]) > ObtemVotos(eleicao.presidentes[i]))
        {
            candEleito = eleicao.presidentes[i - 1];
        }
        else
        {
            candEleito = eleicao.presidentes[i];
        }
    }

    printf("- PRESIDENTE ELEITO: ");
    ImprimeCandidato(candEleito, CalculaPercentualVotos(candEleito, eleicao.totalEleitores));

    for (i = 1; i < eleicao.totalGovernadores; i++)
    {
        if (ObtemVotos(eleicao.governadores[i - 1]) > ObtemVotos(eleicao.governadores[i]))
        {
            candEleito = eleicao.governadores[i - 1];
        }
        else
        {
            candEleito = eleicao.governadores[i];
        }
    }

    printf("- GOVERNADOR ELEITO: ");
    ImprimeCandidato(candEleito, CalculaPercentualVotos(candEleito, eleicao.totalEleitores));

    printf("- NULOS E BRANCOS: %d, %d");
}
