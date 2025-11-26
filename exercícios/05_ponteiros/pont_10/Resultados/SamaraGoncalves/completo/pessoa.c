#include <stdio.h>
#include <string.h>
#include "pessoa.h"
/**
 * @brief Cria uma nova pessoa com nome vazio (primeiro caractere igual a '\0') e inicializa os ponteiros para pai, mae e irmao com NULL.
 *
 * @return Uma nova pessoa e sem pais e irmao.
 */
tPessoa CriaPessoa()
{
    tPessoa pess;

    pess.nome[0] = '\0';
    pess.pai = NULL;
    pess.mae = NULL;
    pess.irmao = NULL;

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
            printf("NOME COMPLETO: %s\nPAI: NAO INFORMADO\nMAE: %s\nIRMAO: NAO INFORMADO\n", pessoa->nome, pessoa->mae->nome);
        }
        else if (pessoa->mae == NULL && pessoa->pai != NULL)
        {
            printf("NOME COMPLETO: %s\nPAI: %s\nMAE: NAO INFORMADO\nIRMAO: NAO INFORMADO\n", pessoa->nome, pessoa->pai->nome);
        }
        else
        {
            printf("NOME COMPLETO: %s\nPAI: %s\nMAE: %s\nIRMAO: %s\n", pessoa->nome, pessoa->pai->nome, pessoa->mae->nome, pessoa->irmao->nome);
        }

        printf("\n");
    }
}

/**
 * @brief Verifica se duas pessoas são irmãos, ou seja, se os ponteiros pai e mae são iguais.
 *
 * @param pessoa1 Ponteiro para a primeira pessoa.
 * @param pessoa2 Ponteiro para a segunda pessoa.
 *
 * @return 1 se as pessoas forem irmãos e 0 caso contrário.
 */
int VerificaIrmaoPessoa(tPessoa *pessoa1, tPessoa *pessoa2)
{
    if ((pessoa1->pai == pessoa2->pai) && (pessoa1->mae == pessoa2->mae))
    {
        return 1;
    }

    return 0;
}

/**
 * @brief Le as associciacoes da entrada padrao e altera as pessoas de forma a representar as associacoes lidas
 *
 * Apos a associado dos pais, voce deve verificar se ha irmaos e associar os irmaos.
 *
 * @param pessoas Ponteiro para a lista de pessoas a serem associadas.
 * @param numPessoas Numero de pessoas a serem associadas (tamanho do vetor).
 */
void AssociaFamiliasGruposPessoas(tPessoa *pessoas, int numPessoas)
{
    int mae = 0, pai = 0, filho = 0, qtd = 0, i, j;

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

    for (i = 0; i < numPessoas; i++)
    {
        for (j = i + 1; j < numPessoas; j++)
        {
            if (VerificaIrmaoPessoa(&pessoas[i], &pessoas[j]))
            {
                pessoas[i].irmao = &pessoas[j];
                pessoas[j].irmao = &pessoas[i];
            }
        }
    }
}
