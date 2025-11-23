#include <stdio.h>
#include <string.h>
#include "evento.h"

/**
 * Cadastra um novo evento no calendário e o insere na próxima posição do array.
 *
 * @param eventos Array de eventos onde o novo evento será cadastrado.
 * @param numEventos Ponteiro para o número atual de eventos cadastrados.
 */
void cadastrarEvento(Evento *eventos, int *numEventos)
{
    int dia, mes, ano;
    char nome[50];

    scanf("%*c");
    if (*numEventos < 10)
    {
        scanf("%s\n", nome);
        scanf("%d %d %d\n", &dia, &mes, &ano);
        strcpy(eventos[*numEventos].nome, nome);
        eventos[*numEventos].dia = dia;
        eventos[*numEventos].mes = mes;
        eventos[*numEventos].ano = ano;
        *numEventos = *numEventos + 1;
        printf("Evento cadastrado com sucesso!\n");
    }
    else
    {
        printf("Limite de eventos atingido!\n");
    }
}

/**
 * Exibe todos os eventos cadastrados no calendário.
 *
 * @param eventos Array de eventos a serem exibidos.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void exibirEventos(Evento *eventos, int *numEventos)
{
    int i;
    scanf("%*c");

    if (*numEventos == 0)
    {
        printf("Nenhum evento cadastrado.\n");
    }
    else
    {
        printf("Eventos cadastrados:\n");
        for (i = 0; i < *numEventos; i++)
        {
            printf("%d - %s - %d/%d/%d\n", i, eventos[i].nome, eventos[i].dia, eventos[i].mes, eventos[i].ano);
        }
    }
}

/**
 * Troca a data de um evento específico no calendário.
 *
 * @param eventos Array de eventos onde o evento será modificado.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void trocarDataEvento(Evento *eventos, int *numEventos)
{
    int idx, dia, mes, ano;
    scanf("%*c");
    scanf("%d\n", &idx);
    if (idx < *numEventos)
    {
        scanf("%d %d %d\n", &dia, &mes, &ano);
        eventos[idx].dia = dia;
        eventos[idx].mes = mes;
        eventos[idx].ano = ano;
        printf("Data modificada com sucesso!\n");
    }
    else
    {
        printf("Indice invalido!\n");
    }
}

/**
 * Troca a posição de dois eventos, a partir do índice, dentro do array de eventos.
 *
 * @param eventos Array de eventos onde a troca será realizada.
 * @param indiceA Ponteiro para o primeiro índice.
 * @param indiceB Ponteiro para o segundo índice.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void trocarIndicesEventos(Evento *eventos, int *indiceA, int *indiceB, int *numEventos)
{
    Evento aux_event;
    scanf("%*c");
    if (*indiceA < *numEventos && *indiceB < *numEventos)
    {
        aux_event = eventos[*indiceA];
        eventos[*indiceA] = eventos[*indiceB];
        eventos[*indiceB] = aux_event;
        printf("Eventos trocados com sucesso!\n");
    }
    else
    {
        printf("Indices invalidos!\n");
    }
}
