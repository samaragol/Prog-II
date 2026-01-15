#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pacote.h"
#include "gerenciadorpacotes.h"

#define MAX_QTD_PCTS 10

struct gerenciadorpacotes
{
    tPacote **pacotes;
    int qtdPacotes;
    int qtdMax;
};

/**
 * @brief Cria uma TAD que gerencia pacotes. O pacote é um TAD genérico.
 *
 *
 * @return O gerenciador de pacotes
 */
tGerenciador *CriaGerenciador()
{
    tGerenciador *geren;

    geren = (tGerenciador *)calloc(1, sizeof(tGerenciador));

    if (!geren)
    {
        printf("Falha na alocação do gerenciador.\n");
        return NULL;
    }

    geren->qtdMax = MAX_QTD_PCTS;
    geren->pacotes = (tPacote **)calloc(geren->qtdMax, sizeof(tPacote *));

    return geren;
}

/**
 * @brief Adiciona um pacote ao gerenciador de pacotes.
 *
 * @param geren O gerenciador de pacotes que armazenará o pacote
 * @param pac O pacote que queremos adicionar no gerenciador.
 *
 */
void AdicionaPacoteNoGerenciador(tGerenciador *geren, tPacote *pac)
{
    if (geren->qtdPacotes == geren->qtdMax)
    {
        geren->qtdMax += 10;
        geren->pacotes = (tPacote **)realloc(geren->pacotes, sizeof(tPacote *) * geren->qtdMax);
    }

    geren->pacotes[geren->qtdPacotes] = pac;
    geren->qtdPacotes++;
}

/**
 * @brief Destrói um gerenciador de pacotes
 *
 * @param geren O gerenciador de pacotes que será destruído (memória liberada)
 *
 */
void DestroiGerenciador(tGerenciador *geren)
{
    int i;

    for (i = 0; i < geren->qtdPacotes; i++)
    {
        DestroiPacote(geren->pacotes[i]);
    }

    free(geren->pacotes);
    free(geren);
}

/**
 * @brief Imprime um pacote específico do gerenciador de pacotes.
 *
 * @param geren - O gerenciador de pacotes que terá um pacote impresso
 * @param idx - O índice do pacote a ser impresso (começa em zero!)
 *
 */
void ImprimirPacoteNoIndice(tGerenciador *geren, int idx)
{
    if (idx >= geren->qtdPacotes)
    {
        printf("Índice inválido.\n");
    }
    else
    {
        ImprimePacote(geren->pacotes[idx]);
    }
}

/**
 * @brief Imprime todos os pacotes de um gerenciador de pacotes
 *
 * @param geren O gerenciador de pacotes que terá seus pacotes impressos
 *
 */
void ImprimirTodosPacotes(tGerenciador *geren)
{
    int i;

    for (i = 0; i < geren->qtdPacotes; i++)
    {
        ImprimePacote(geren->pacotes[i]);
    }
}
