#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "executiva.h"

struct Executiva
{
    int nBagagens;
    char refEsp[TAM_PADRAO];
    char acess[TAM_PADRAO];
};

/**
 * @brief Cria uma nova reserva do tipo Executiva
 * @param nBagagens Número de bagagens permitidas
 * @param assentoEspecial Assento especial solicitado
 * @return Ponteiro para a nova reserva criada
 */
Executiva *criaExecutiva(int nBagagens, char *refEsp, char *acess)
{
}

/**
 * @brief Lê os dados de uma reserva do tipo Executiva a partir da entrada padrão de acordo com a especificação do trabalho
 * @return Ponteiro para a nova reserva criada
 */
Executiva *leExecutiva();

/**
 * @brief Imprime os detalhes de uma reserva do tipo Executiva
 * @param dado Ponteiro genérico para a reserva do tipo Executiva
 */
void imprimeExecutiva(void *dado);

/**
 * @brief Desaloca a memória associada a uma reserva do tipo Executiva
 * @param dado Ponteiro genérico para a reserva do tipo Executiva
 */
void desalocaExecutiva(void *dado);

/**
 * @brief Obtém o número de bagagens permitidas em uma reserva do tipo Executiva
 * @param dado Ponteiro genérico para a reserva do tipo Executiva
 * @return Número de bagagens permitidas
 */
int getNumBagagensExecutiva(void *dado);

/**
 * @brief Obtém o tipo da reserva do tipo Executiva
 * @return Caractere representando o tipo da reserva ('E' para Executiva)
 */
char getTipoExecutiva();

#endif // _EXECUTIVA_H_