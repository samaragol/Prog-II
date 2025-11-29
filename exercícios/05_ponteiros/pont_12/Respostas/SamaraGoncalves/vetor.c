#include <stdio.h>
#include "vetor.h"

/**
 * Lê um vetor da entrada padrão.
 *
 * @param vetor Ponteiro para o vetor que será lido.
 */
void LeVetor(Vetor *vetor)
{
    int tam, i;

    scanf("%d\n", &tam);

    for (i = 0; i < tam; i++)
    {
        scanf("%d", &vetor->elementos[i]);
    }
    vetor->tamanhoUtilizado = tam;
}

/**
 * Aplica uma operação em um vetor.
 *
 * @param vetor Ponteiro para o vetor que será utilizado.
 * @param op Ponteiro para a função que será aplicada.
 * @return O resultado da operação.
 */
int AplicarOperacaoVetor(Vetor *vetor, Operation op)
{
    int i, result = 0;

    result = vetor->elementos[0];
    for (i = 1; i < vetor->tamanhoUtilizado; i++)
    {
        result = op(result, vetor->elementos[i]);
    }

    return result;
}
