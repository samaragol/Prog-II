#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pacote.h"

struct pacote
{
    void *mensagem;
    int soma;
    Type type;
    int numElem;
};

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar um pacote a ser transmitido
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tPacote *CriaPacote(Type type, int numElem)
{
    tPacote *pac;

    pac = (tPacote *)calloc(1, sizeof(tPacote));

    if (!pac)
    {
        printf("Erro na alocação do pacote.\n");
        return NULL;
    }

    pac->type = type;
    pac->numElem = numElem;

    if (type == INT)
    {
        pac->mensagem = calloc(numElem, sizeof(int));
    }
    else if (type == CHAR)
    {
        pac->mensagem = calloc(numElem, sizeof(char));
    }

    return pac;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param pac - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiPacote(tPacote *pac)
{
    free(pac->mensagem);
    free(pac);
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param pac - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LePacote(tPacote *pac)
{
    int i;

    scanf("%*c");
    if (pac->type == INT)
    {
        for (i = 0; i < pac->numElem; i++)
        {
            scanf("%d", &((int *)pac->mensagem)[i]);
        }
        scanf("%*c"); // \n sobrando
    }
    else if (pac->type == CHAR)
    {
        for (i = 0; i < pac->numElem; i++)
        {
            scanf("%c", &((char *)pac->mensagem)[i]);
        }
        scanf("%*c"); // \n sobrando
    }

    CalculaSomaVerificacaoPacote(pac);
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param pac - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimePacote(tPacote *pac)
{
    int i;

    printf("%d ", pac->soma);
    if (pac->type == INT)
    {
        for (i = 0; i < pac->numElem; i++)
        {
            printf("%d", ((int *)pac->mensagem)[i]);
            if (i == pac->numElem - 1)
            {
                printf("\n");
            }
            else
            {
                printf(" ");
            }
        }
    }
    else if (pac->type == CHAR)
    {
        for (i = 0; i < pac->numElem; i++)
        {
            printf("%c", ((char *)pac->mensagem)[i]);
        }
        printf("\n");
    }
}

/**
 * @brief Calcula a soma de verificacao de um pacote e a armazena internamente
 *
 * @param pac - O vetor genérico que terá sua soma de verificacao calculada
 */
void CalculaSomaVerificacaoPacote(tPacote *pac)
{
    int i, soma = 0;

    if (pac->type == INT)
    {
        for (i = 0; i < pac->numElem; i++)
        {
            soma += ((int *)pac->mensagem)[i];
        }
    }
    else if (pac->type == CHAR)
    {
        for (i = 0; i < pac->numElem; i++)
        {
            soma += ((char *)pac->mensagem)[i];
        }
    }

    pac->soma = soma;
}
