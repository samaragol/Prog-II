#include <stdio.h>
#include <string.h>
#include "pessoa.h"

/**
 * @brief Cria uma nova pessoa com nome vazio (primeiro caractere igual a '\0') e inicializa os ponteiros para pai e mae com NULL.
 *
 * @return Uma nova pessoa e sem pais.
 */
tPessoa CriaPessoa()
{
    tPessoa pess;

    pess.nome[0] = '\0';
    pess.pai = NULL;
    pess.mae = NULL;

    return pess;
}

/**
 * @brief Lê os dados de uma pessoa.
 *
 * @param pessoa Ponteiro para a pessoa a ser lida.
 */
void LePessoa(tPessoa *pessoa)
{
    char nome[100];

    scanf(" %[^\n]\n", nome);
    strcpy(pessoa->nome, nome);
}

/**
 * @brief Verifica se uma pessoa tem pai e/ou mae associado(s).
 * Ou seja, verifica pelo menos um dos ponteiros pai e mae é diferente de NULL.
 *
 * @param pessoa Ponteiro para a pessoa a ser verificada.
 *
 * @return 1 se a pessoa tiver pai e/ou mae associado(s) e 0 caso contrário.
 */
int VerificaSeTemPaisPessoa(tPessoa *pessoa)
{
    if (pessoa->pai != NULL || pessoa->mae != NULL)
    {
        return 1;
    }

    return 0;
}

/**
 * @brief Imprime os dados de uma pessoa caso tenha pai e/ou mae associado(s).
 * Dica: use a função VerificaSeTemPaisPessoa para verificar se a pessoa tem pai e/ou mae associado(s).
 * Alem disso, imprimir o nome do irmao caso exista.
 *
 * @param pessoa Ponteiro para a pessoa a ser impressa.
 */
void ImprimePessoa(tPessoa *pessoa)
{
    if (VerificaSeTemPaisPessoa(pessoa))
    {
        if (pessoa->pai == NULL && pessoa->mae != NULL)
        {
            printf("NOME COMPLETO: %s\nPAI: NAO INFORMADO\nMAE: %s\n", pessoa->nome, pessoa->mae->nome);
        }
        else if (pessoa->mae == NULL && pessoa->pai != NULL)
        {
            printf("NOME COMPLETO: %s\nPAI: %s\nMAE: NAO INFORMADO\n", pessoa->nome, pessoa->pai->nome);
        }
        else
        {
            printf("NOME COMPLETO: %s\nPAI: %s\nMAE: %s\n", pessoa->nome, pessoa->pai->nome, pessoa->mae->nome);
        }

        printf("\n");
    }
}

/**
 * @brief Le as associciacoes da entrada padrao e altera as pessoas de forma a representar as associacoes lidas
 *
 * @param pessoas Ponteiro para a lista de pessoas a serem associadas.
 */
void AssociaFamiliasGruposPessoas(tPessoa *pessoas)
{
    int mae = 0, pai = 0, filho = 0, qtd = 0, i;

    scanf("%d\n", &qtd);

    for (i = 0; i < qtd; i++)
    {
        scanf("mae: %d, pai: %d, filho: %d\n", &mae, &pai, &filho);
        if (mae != -1)
        {
            pessoas[filho].mae = &pessoas[mae];
        }

        if (pai != -1)
        {
            pessoas[filho].pai = &pessoas[pai];
        }
    }
}
