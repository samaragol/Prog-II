#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "candidato.h"
#include "eleitor.h"
#include "eleicao.h"

#define MAX_CANDIDATOS_POR_CARGO 3
#define MAX_ELEITORES 10

// typedef struct {
//     tCandidato** presidentes;
//     int totalPresidentes;

//     tCandidato** governadores;
//     int totalGovernadores;

//     int votosBrancosPresidente;
//     int votosNulosPresidente;

//     int votosBrancosGovernador;
//     int votosNulosGovernador;

//     tEleitor** eleitores;
//     int totalEleitores;

// } tEleicao;

/**
 * @brief Inicializa uma eleição com valores padrão (zerando as variáveis que armazenam votos).
 * Ainda nessa função, é lido a quantidade de candidatos e os candidatos são lidos e armazenados
 * A memória necessária para os vetores "presidentes", "governadores" deve ser alocada aqui.
 * Demais ponteiros devem ser inicializado com NULL.
 * @return Eleição inicializada.
 */
tEleicao *InicializaEleicao()
{
    tEleicao *eleicao;
    tCandidato *candidato;
    int qtdC, i;

    eleicao = (tEleicao *)calloc(1, sizeof(tEleicao));
    eleicao->presidentes = (tCandidato **)calloc(MAX_CANDIDATOS_POR_CARGO, sizeof(tCandidato *));
    eleicao->governadores = (tCandidato **)calloc(MAX_CANDIDATOS_POR_CARGO, sizeof(tCandidato *));

    scanf("%d\n", &qtdC);

    for (i = 0; i < qtdC; i++)
    {
        candidato = CriaCandidato();
        LeCandidato(candidato);
        if (ObtemCargo(candidato) == 'P')
        {
            eleicao->presidentes[eleicao->totalPresidentes] = candidato;
            eleicao->totalPresidentes++;
        }
        else if (ObtemCargo(candidato) == 'G')
        {
            eleicao->governadores[eleicao->totalGovernadores] = candidato;
            eleicao->totalPresidentes++;
        }
    }

    return eleicao;
}

void ApagaEleicao(tEleicao *eleicao)
{
    int i;

    for (i = 0; i < eleicao->totalEleitores; i++)
    {
        free(eleicao->eleitores[i]);
    }
    for (i = 0; i < eleicao->totalPresidentes; i++)
    {
        free(eleicao->presidentes[i]);
    }
    for (i = 0; i < eleicao->totalGovernadores; i++)
    {
        free(eleicao->governadores[i]);
    }

    free(eleicao);
}

/**
 * @brief Realiza uma eleição.
 * Nessa função, é lido a quantidade de eleitores e os eleitores são lidos e armazenados.
 * @param eleicao Eleição a ser realizada.
 */
void RealizaEleicao(tEleicao *eleicao)
{
    tEleitor *eleitor;
    int i, j, qtdE, igual = 0;

    eleicao->eleitores = (tEleitor **)calloc(MAX_ELEITORES, sizeof(tEleitor *));
    scanf("%d\n", &qtdE);

    for (i = 0; i < qtdE; i++)
    {
        eleitor = CriaEleitor();
        LeEleitor(eleitor);
        eleicao->eleitores[i] = eleitor;
        eleicao->totalEleitores++;
    }

    for (i = 0; i < qtdE; i++)
    {
        for (j = i + 1; j < qtdE; j++)
        {
            if (eleicao->eleitores[i] == eleicao->eleitores[j])
            {
                igual = 1;
            }
        }
    }

    if (igual)
    {
        printf("ELEICAO ANULADA\n");
        ApagaEleicao(eleicao);
        exit(1);
    }
}

/**
 * @brief Imprime o resultado da eleição na tela a partir da aparucao dos votos.
 * @param eleicao Eleição a ser impressa.
 */
void ImprimeResultadoEleicao(tEleicao *eleicao)
{
    int qtdNulos = 0, qtdVotosP = 0, qtdVotosG = 0, i, j, empateG = 0, empateP = 0;
    tCandidato presida, gov;

    for (j = 0; j < eleicao->totalEleitores; j++)
    {
        for (i = 0; i < eleicao->totalPresidentes; i++)
        {
            if (VerificaIdCandidato(eleicao->presidentes[i], ObtemVotoPresidente(eleicao->eleitores[j])))
            {
                IncrementaVotoCandidato(eleicao->presidentes[i]);
                qtdVotosP++;
            }
        }
        for (i = 0; i < eleicao->totalGovernadores; i++)
        {
            if (VerificaIdCandidato(eleicao->governadores[i], ObtemVotoGovernador(eleicao->eleitores[j])))
            {
                IncrementaVotoCandidato(eleicao->governadores[i]);
                qtdVotosG++;
            }
        }
    }

    for (i = 1; i < eleicao->presidentes; i++)
    {
        if (ObtemVotos(eleicao->presidentes[i - 1] > ObtemVotos(eleicao->presidentes[i])))
        {
            presida = *eleicao->presidentes[i - 1];
        }
        else if (ObtemVotos(eleicao->presidentes[i - 1] < ObtemVotos(eleicao->presidentes[i])))
        {
            presida = *eleicao->presidentes[i];
        }
        else if (ObtemVotos(eleicao->presidentes[i - 1] == ObtemVotos(eleicao->presidentes[i])))
        {
            empateP = 1;
        }
    }

    printf("- PRESIDENTE ELEITO: ");
    if (empateP)
    {
        printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
    }
    else
    {
        ImprimeCandidato(&presida, CalculaPercentualVotos(&presida, qtdVotosP));
    }
    printf("- GOVERNADOR ELEITO: ");
    if (empateG)
    {
        printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
    }
    else
    {
        ImprimeCandidato(&gov, CalculaPercentualVotos(&gov, qtdVotosG));
    }
}
