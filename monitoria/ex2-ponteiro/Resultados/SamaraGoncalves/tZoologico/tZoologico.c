#include <stdio.h>
#include <string.h>
#include "tRecinto.h"
#include "tZoologico.h"

/**
 * @brief Cria e retorna um zoológico inicializado com os parâmetros fornecidos.
 *
 * Cada recinto é criado chamando CriaRecinto(capacidade).
 * O contador de dias começa em 0.
 *
 * @param nome Nome do zoológico.
 * @param nRecintos Número de recintos do zoológico (máx. 10).
 * @param capacidade Capacidade máxima de animais em cada recinto.
 * @return Estrutura tZoologico inicializada.
 */
tZoologico CriaZoologico(char *nome, int nRecintos, int capacidade)
{
    tZoologico zoo;
    int i;

    strcpy(zoo.nome, nome);
    for (i = 0; i < nRecintos; i++)
    {
        zoo.recintos[i] = CriaRecinto(capacidade);
    }
    zoo.nRecintos = nRecintos;
    zoo.capacidade = capacidade;
    zoo.dia = 0;

    return zoo;
}

/**
 * @brief Tenta adicionar um animal em um dos recintos do zoológico.
 *
 * O animal é adicionado no primeiro recinto disponível (não lotado).
 * Caso todos os recintos estejam cheios, retorna 0.
 *
 * @param z Ponteiro para o zoológico.
 * @param a Animal a ser adicionado (passado por valor).
 * @return 1 se o animal foi adicionado com sucesso, 0 se o zoológico estiver lotado.
 */
int AdicionaAnimalZoologico(tZoologico *z, tAnimal a)
{
    int i;

    for (i = 0; i < z->nRecintos; i++)
    {
        if (!EstaLotadoRecinto(&z->recintos[i]))
        {
            AdicionaAnimalRecinto(&z->recintos[i], a);
            printf("Animal %s foi adicionado ao recinto %d\n", NomeAnimal(&a), i);
            return 1;
        }
    }

    return 0;
}

/**
 * @brief Avança o dia em todos os recintos do zoológico.
 *
 * Todos os animais aumentam seu nível de fome e, se morrerem,
 * suas mortes são registradas. O contador de dias é incrementado.
 *
 * @param z Ponteiro para o zoológico.
 */
void PassaDiaZoologico(tZoologico *z)
{
    int i;

    for (i = 0; i < z->nRecintos; i++)
    {
        PassaDiaRecinto(&z->recintos[i]);
    }

    z->dia++;
}

/**
 * @brief Registra uma fuga em um recinto específico.
 *
 * Caso o índice informado seja inválido, imprime "Valor invalido".
 *
 * @param z Ponteiro para o zoológico.
 * @param idx Índice do recinto onde ocorreu a fuga.
 */
void FugaRecintoZoologico(tZoologico *z, int idx)
{
    if (idx >= z->nRecintos)
    {
        printf("Valor invalido\n");
    }
    else
    {
        FugaRecinto(&z->recintos[idx]);
    }
}

/**
 * @brief Encerra o zoológico.
 *
 * Se ainda houver animais, imprime:
 * "Animais liberados para a finalizacao do programa!!!"
 * Caso contrário, imprime:
 * "Programa finalizado com sucesso."
 *
 * @param z Ponteiro para o zoológico.
 */
void EncerraZoologico(tZoologico *z)
{
    int i, animal = 0;

    for (i = 0; i < z->nRecintos; i++)
    {
        if (!EstaVazioRecinto(&z->recintos[i]))
        {
            animal = 1;
        }
    }

    if (animal)
    {
        printf("Animais liberados para a finalizacao do programa!!!\n");
    }
    else
    {
        printf("Programa finalizado com sucesso.\n");
    }
}

/**
 * @brief Verifica se todos os recintos do zoológico estão lotados.
 *
 * @param z Ponteiro para o zoológico.
 * @return 1 se todos estiverem lotados, 0 caso contrário.
 */
int ZoologicoLotado(tZoologico *z)
{
    int i, lotado = 1;

    for (i = 0; i < z->nRecintos; i++)
    {
        if (!EstaLotadoRecinto(&z->recintos[i]))
        {
            lotado = 0;
        }
    }

    if (lotado)
    {
        return 1;
    }

    return 0;
}

/**
 * @brief Retorna o nome do zoológico.
 *
 * @param z Ponteiro para o zoológico.
 * @return Ponteiro para string com o nome do zoológico.
 */
char *GetNome(tZoologico *z)
{
    return z->nome;
}

int GetDia(tZoologico *z)
{
    return z->dia;
}
