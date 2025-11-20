#include <stdio.h>
#include <string.h>
#include "tAnimal.h"
#include "tRecinto.h"

/**
 * @brief Cria e retorna um novo recinto com capacidade definida.
 *
 * Inicializa a quantidade de animais como 0.
 *
 * @param capacidade Capacidade máxima de animais que o recinto comporta.
 * @return Estrutura tRecinto inicializada.
 */
tRecinto CriaRecinto(int capacidade)
{
    tRecinto recinto;
    recinto.qtd = 0;
    recinto.capacidade = capacidade;

    return recinto;
}

/**
 * @brief Adiciona um animal ao recinto, se houver espaço disponível.
 *
 * A função adiciona o animal na primeira posição livre.
 *
 * @param r Ponteiro para o recinto onde o animal será adicionado.
 * @param a Animal a ser adicionado (passado por valor).
 * @return 1 se o animal foi adicionado com sucesso, 0 caso o recinto esteja lotado.
 */
int AdicionaAnimalRecinto(tRecinto *r, tAnimal a)
{
    if (r->qtd == r->capacidade)
    {
        return 0;
    }

    r->animais[r->qtd] = a;
    r->qtd++;
    return 1;
}

/**
 * @brief Simula a passagem de um dia para todos os animais do recinto.
 *
 * Todos os animais têm seu nível de fome incrementado.
 * Caso algum morra (fome >= 10), é removido e sua morte é impressa.
 *
 * @param r Ponteiro para o recinto.
 */
void PassaDiaRecinto(tRecinto *r)
{
    int i, j = 1, qtd;

    qtd = r->qtd;

    for (i = 0; i < r->qtd; i++)
    {
        PassaDiaAnimal(&r->animais[i]);
    }
    for (i = 0; i < qtd; i++)
    {
        if (AnimalEstaMorto(&r->animais[i]))
        {
            ImprimeMorteAnimal(&r->animais[i]);
            while (AnimalEstaMorto(&r->animais[i + j]))
            {
                j++;
                if (i + j >= qtd)
                {
                    j = 0;
                    break;
                }
            }
            r->animais[i] = r->animais[i + j];
            r->qtd--;
        }
    }
}

/**
 * @brief Registra uma fuga de todos os animais do recinto.
 *
 * Todos os animais são "liberados" e a contagem do recinto é zerada.
 *
 * @param r Ponteiro para o recinto.
 */
void FugaRecinto(tRecinto *r)
{
    int i;

    for (i = 0; i < r->qtd; i++)
    {
        ImprimeFugaAnimal(&r->animais[i]);
    }

    r->qtd = 0;
}

/**
 * @brief Verifica se o recinto está lotado.
 *
 * @param r Ponteiro para o recinto.
 * @return 1 se o recinto estiver cheio, 0 caso contrário.
 */
int EstaLotadoRecinto(tRecinto *r)
{
    if (r->qtd == r->capacidade)
    {
        return 1;
    }

    return 0;
}

/**
 * @brief Verifica se o recinto está vazio.
 *
 * @param r Ponteiro para o recinto.
 * @return 1 se o recinto estiver vazio, 0 caso contrário.
 */
int EstaVazioRecinto(tRecinto *r)
{
    if (r->qtd == 0)
    {
        return 1;
    }

    return 0;
}
