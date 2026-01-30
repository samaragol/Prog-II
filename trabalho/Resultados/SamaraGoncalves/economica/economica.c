#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "economica.h"

#define TAM_ASSENTO_ESPECIAL 4

struct Economica
{
    int qtdBag;
    char assento[TAM_ASSENTO_ESPECIAL];
};

/**
 * @brief Cria uma nova reserva do tipo Econômica
 * @param nBagagens Número de bagagens permitidas
 * @param assentoEspecial Assento especial solicitado
 * @return Ponteiro para a nova reserva criada
 */
Economica *criaEconomica(int nBagagens, char *assentoEspecial)
{
    Economica *eco;

    eco = (Economica *)calloc(1, sizeof(Economica));

    eco->qtdBag = nBagagens;
    strcpy(eco->assento, assentoEspecial);

    return eco;
}

/**
 * @brief Lê os dados de uma reserva do tipo Econômica a partir da entrada padrão de acordo com a especificação do trabalho
 * @return Ponteiro para a nova reserva criada
 */
Economica *leEconomica()
{
    int qtdBag;
    char assento[TAM_ASSENTO_ESPECIAL];

    scanf("%d\n", &qtdBag);
    scanf("%s\n", assento);

    return criaEconomica(qtdBag, assento);
}

/**
 * @brief Imprime os detalhes de uma reserva do tipo Econômica
 * @param dado Ponteiro genérico para a reserva do tipo Econômica
 */
void imprimeEconomica(void *dado)
{
    printf("- Tipo: ECONOMICA\n");
    printf("- Numero de Bagagens: %d\n", ((Economica *)dado)->qtdBag);
    printf("- Assento Especial: %s\n", ((Economica *)dado)->assento);
}

/**
 * @brief Desaloca a memória associada a uma reserva do tipo Econômica
 * @param dado Ponteiro genérico para a reserva do tipo Econômica
 */
void desalocaEconomica(void *dado)
{
    free(dado);
}

/**
 * @brief Obtém o número de bagagens permitidas em uma reserva do tipo Econômica
 * @param dado Ponteiro genérico para a reserva do tipo Econômica
 * @return Número de bagagens permitidas
 */
int getNumBagagensEconomica(void *dado)
{
    return ((Economica *)dado)->qtdBag;
}

/**
 * @brief Obtém o tipo da reserva do tipo Econômica
 * @return Caractere representando o tipo da reserva ('E' para Econômica)
 */
char getTipoEconomica()
{
    return 'E';
}