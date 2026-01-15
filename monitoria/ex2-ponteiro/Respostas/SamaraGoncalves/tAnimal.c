#include <stdio.h>
#include <string.h>
#include "tAnimal.h"


/**
 * @brief Inicializa e retorna um novo animal.
 *
 * Cria um animal a partir dos parâmetros fornecidos.
 * Caso o valor de fome seja menor ou igual a 0, o programa imprime "VALOR INVALIDO",
 * define o nome do animal como "Desconhecido" e a fome como 0.
 *
 * @param nome Nome do animal.
 * @param fome Nível inicial de fome (deve ser maior que 0).
 * @return tAnimal inicializado com os valores válidos (ou padrão, em caso de erro).
 */
tAnimal CriaAnimal(char *nome, int fome)
{
    tAnimal animal;

    if (fome <= 0)
    {
        printf("VALOR INVALIDO\n");
        animal.fome = 0;
        strcpy(animal.nome, "Desconhecido");
    }

    animal.fome = fome;
    strcpy(animal.nome, nome);

    return animal;
}

/**
 * @brief Incrementa em 1 o nível de fome do animal.
 *
 * Essa função simula a passagem de um dia no zoológico.
 *
 * @param a Ponteiro para o animal que terá o nível de fome incrementado.
 */
void PassaDiaAnimal(tAnimal *a)
{
    a->fome++;
}

/**
 * @brief Verifica se o animal morreu de fome.
 *
 * Um animal é considerado morto se sua fome for maior ou igual a 10.
 *
 * @param a Ponteiro para o animal a ser verificado.
 * @return 1 se o animal morreu de fome, 0 caso contrário.
 */
int AnimalEstaMorto(tAnimal *a)
{
    if (a->fome >= 10)
    {
        return 1;
    }

    return 0;
}

/**
 * @brief Exibe a mensagem de fuga do animal.
 *
 * O formato da mensagem é: "Animal <nome> fugiu!"
 *
 * @param a Ponteiro para o animal que fugiu.
 */
void ImprimeFugaAnimal(tAnimal *a)
{
    printf("Animal %s fugiu!\n", a->nome);
}

/**
 * @brief Exibe a mensagem de morte do animal.
 *
 * O formato da mensagem é: "Animal <nome> morreu de fome."
 *
 * @param a Ponteiro para o animal que morreu.
 */
void ImprimeMorteAnimal(tAnimal *a)
{
    printf("Animal %s morreu de fome.\n", a->nome);
}

/**
 * @brief Retorna o nome do animal.
 *
 * @param a Ponteiro para o animal cujo nome será retornado.
 * @return Ponteiro para a string com o nome do animal.
 */
char *NomeAnimal(tAnimal *a)
{
    return a->nome;
}
