#include <stdio.h>
#include <stdlib.h>
#include "pintura.h"
/**
 * @brief Estrutura de uma pintura, contendo:
 *
 * - Título
 *
 * - Artista
 *
 * - Movimento
 *
 * - Material
 *
 * - Ano
 */
struct Pintura
{
    char titulo[MAXTAM_STRINGS];
    char artista[MAXTAM_STRINGS];
    char movimento[MAXTAM_STRINGS];
    char material[MAXTAM_STRINGS];
    int ano;
};

/**
 * @brief Lê as informações de uma pintura, conforme as especificações, e a constrói.
 * Não é necessário alocar as strings dinamicamente, apenas a pintura em si.
 * @return Um objeto do tipo pintura lido da entrada padrão e devidamente alocado.
 */
Pintura *pintura_read_and_construct()
{
    Pintura *pin;

    pin = (Pintura *)calloc(1, sizeof(Pintura));
    scanf("%s", pin->titulo);
    scanf(" %s", pin->artista);
    scanf(" %s", pin->movimento);
    scanf(" %s", pin->material);
    scanf("%d\n", &pin->ano);

    return pin;
}

/**
 * @brief Imprime todas as informações de uma pintura na tela, conforme as especificações.
 * @param p pintura a ser impressa (passada como void*, é preciso fazer typecast dentro da função).
 */
void pintura_print(void *p)
{
    printf("PINTURA\n");
    printf("Titulo: %s\n", ((Pintura *)p)->titulo);
    printf("Artista: %s\n", ((Pintura *)p)->artista);
    printf("Movimento: %s\n", ((Pintura *)p)->movimento);
    printf("Material: %s\n", ((Pintura *)p)->material);
    printf("Ano: %d\n", ((Pintura *)p)->ano);
}

/**
 * @brief Destrói uma pintura, liberando toda a memória alocada para ela.
 * @param p pintura a ser liberada (passada como void*, é preciso fazer typecast dentro da função).
 */
void pintura_destroy(void *p)
{
    free(p);
}
