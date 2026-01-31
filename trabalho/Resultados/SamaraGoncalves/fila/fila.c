#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "reserva.h"

#define TAM_FILA 10
#define TAM_ID 10

struct Fila
{
    Reserva **reservas;
    int qtdRes;
    int qtdResCon;
    int tamAtual;
};

/**
 * @brief Cria uma fila de reservas vazia
 * @return Ponteiro para a fila criada
 */
Fila *criaFila()
{
    Fila *fila;

    fila = (Fila *)calloc(1, sizeof(Fila));
    fila->reservas = (Reserva **)calloc(TAM_FILA, sizeof(Reserva *));
    fila->tamAtual = TAM_FILA;

    return fila;
}

/**
 * @brief Insere uma nova reserva na fila e realiza todas as operações de memória necessárias
 * @param f Fila de reservas
 * @param cpfPassageiro CPF do passageiro que está solicitando a reserva
 * @param codigoVoo Código do voo associado à reserva
 * @param dado   Uma reserva genérica  (considerando que existe mais de um tipo de reserva)
 * @param getTipo   Função de callback que retorna o tipo da reserva
 * @param notifica  Função de callback que irá imprimir uma reserva quando for solicitada uma consulta
 * @param desaloca  Função de callback que irá desalocar  uma reserva da memória
 * @param processa  Função de callback que irá processar uma reserva
 */
void insereReservaNaFila(Fila *f, char *cpfPassageiro, char *codigoVoo, void *dado,
                         func_ptr_tipo getTipo,
                         func_ptr_imprime notifica,
                         func_ptr_desaloca desaloca,
                         func_ptr_processa processa)
{
    if (f->qtdRes == f->tamAtual - 1)
    {
        f->tamAtual = f->tamAtual + 10;
        f->reservas = (Reserva **)realloc(f->reservas, f->tamAtual * sizeof(Reserva *));
    }

    f->reservas[f->qtdRes] = criaReserva(cpfPassageiro, codigoVoo, dado, getTipo, notifica, desaloca, processa);
    f->qtdRes++;
}

/** * @brief Desaloca toda a memória associada à fila de reservas
 * @param f Fila de reservas a ser desalocada
 */
void desalocaFila(Fila *f)
{
    int i;

    for (i = 0; i < f->qtdRes; i++)
    {
        desalocaReserva(f->reservas[i]);
    }
    free(f->reservas);
    free(f);
}

/**
 * @brief Processa todas as reservas na fila, atualizando todas as informações necessárias que a fila mantém
 * @param f Fila de reservas a ser processada
 * @param listaPassageiros Ponteiro para a lista de passageiros cadastrados
 * @param listaVoos Ponteiro para a lista de voos cadastrados
 */
void processaReservasNaFila(Fila *f, void *listaPassageiros, void *listaVoos)
{
    int i;

    for (i = 0; i < f->qtdRes; i++)
    {
        processaReserva(listaPassageiros, listaVoos, f->reservas[i]);
        if (!strcmp(getStatusReserva(f->reservas[i]), "CONFIRMADA"))
        {
            f->qtdResCon++;
        }
    }
}

/**
 * @brief Imprime todas as reservas na fila quando solicitado uma consulta
 * @param f Fila de reservas a ser impressa
 */
void imprimeFila(Fila *f)
{
    int i;
    char id[TAM_ID];

    for (i = 0; i < f->qtdRes; i++)
    {
        sprintf(id, "RES-%d", i + 1);
        setIDReserva(f->reservas[i], id);
        imprimeReserva(f->reservas[i]);
    }
}

/**
 * @brief Obtém a quantidade de total de reservas na fila
 * @param f Fila de reservas
 * @return Quantidade de reservas na fila
 */
int getQntdReservaFila(Fila *f)
{
    return f->qtdRes;
}

/**
 * @brief Obtém a quantidade de reservas confirmadas na fila
 * @param f Fila de reservas
 * @return Quantidade de reservas confirmadas na fila
 */
int getQntdReservasConfirmadasFila(Fila *f)
{
    return f->qtdResCon;
}

/**
 * @brief Obtém uma reserva na posição especificada da fila
 * @param f Fila de reservas
 * @param posicao Posição da reserva desejada
 * @return Ponteiro para a reserva na posição especificada, ou NULL se a posição for inválida
 */
Reserva *getReservaNaPosicaoFila(Fila *f, int posicao)
{
    return f->reservas[posicao];
}