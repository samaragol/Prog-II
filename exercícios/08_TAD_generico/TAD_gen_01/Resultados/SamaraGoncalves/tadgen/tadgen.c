#include "tadgen.h"
#include <stdio.h>
#include <stdlib.h>

struct generic
{
    Type type;
    void *dados;
    int numElem;
};

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar tanto inteiros quanto floats
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tGeneric *CriaGenerico(Type type, int numElem)
{
    tGeneric *gen;

    gen = (tGeneric *)calloc(1, sizeof(tGeneric));

    gen->type = type;
    gen->numElem = numElem;

    if (type == INT)
    {
        gen->dados = calloc(numElem, sizeof(int));
    }
    else if (type == FLOAT)
    {
        gen->dados = calloc(numElem, sizeof(float));
    }

    return gen;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param gen - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiGenerico(tGeneric *gen)
{
    free(gen->dados);
    free(gen);
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param gen - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LeGenerico(tGeneric *gen)
{
    int i;

    printf("\nDigite o vetor:\n");

    if (gen->type == INT)
    {
        for (i = 0; i < gen->numElem; i++)
        {
            scanf("%d", &((int *)gen->dados)[i]);
        }
    }
    else if (gen->type == FLOAT)
    {
        for (i = 0; i < gen->numElem; i++)
        {
            scanf("%f", &((float *)gen->dados)[i]);
        }
    }
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param gen - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimeGenerico(tGeneric *gen)
{
    int i;

    if (gen->type == INT)
    {
        for (i = 0; i < gen->numElem; i++)
        {
            printf("%d", ((int *)gen->dados)[i]);
            if (i == gen->numElem - 1)
            {
                printf("\n");
            }
            else
            {
                printf(" ");
            }
        }
    }
    else if (gen->type == FLOAT)
    {
        for (i = 0; i < gen->numElem; i++)
        {
            printf("%.2f", ((float *)gen->dados)[i]);
            if (i == gen->numElem - 1)
            {
                printf("\n");
            }
            else
            {
                printf(" ");
            }
        }
    }
}
