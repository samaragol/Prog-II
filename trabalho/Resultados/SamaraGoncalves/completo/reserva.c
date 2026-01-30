#include <stdio.h>
#include <stdlib.h>
#include "reserva.h"

#define TAM_CPF 15
#define TAM_COD 10
#define TAM_STATUS 15
/**
 * Estrutura de uma Reserva contendo os parametros comuns entre todos os tipos de Reservas e um tipo genérico.
 */
struct Reserva
{
    char cpf[TAM_CPF];
    char codigo[TAM_COD];
    char status[TAM_STATUS];
    char id[TAM_COD];
    float preco;
    void *dado;
    func_ptr_tipo getTipo;
    func_ptr_imprime imprime;
    func_ptr_desaloca desaloca;
    func_ptr_processa processa;
};

/**
 * @brief Aloca uma estrutura Reserva na memória e inicializa os parâmetro necessários
 * @param cpfPassageiro CPF do passageiro que está solicitando a reserva
 * @param codigoVoo Código do voo associado à reserva
 * @param dado   Uma reserva genérica  (considerando que existe mais de um tipo de reserva)
 * @param getTipo   Função de callback que retorna o tipo da reserva
 * @param imprime  Função de callback que irá imprimir uma reserva quando for solicitada uma consulta
 * @param desaloca  Função de callback que irá desalocar  uma reserva da memória
 * @param processa  Função de callback que irá processar uma reserva
 * @return  Uma estrutura Reserva inicializada.
 */
Reserva *criaReserva(char *cpfPassageiro, char *codigoVoo, void *dado, func_ptr_tipo getTipo,
                     func_ptr_imprime imprime, func_ptr_desaloca desaloca, func_ptr_processa processa)
{
    Reserva *res;

    res = (Reserva *)calloc(1, sizeof(Reserva));

    strcpy(res->cpf, cpfPassageiro);
    strcpy(res->codigo, codigoVoo);
    res->dado = dado;
    res->getTipo = getTipo;
    res->imprime = imprime;
    res->desaloca = desaloca;
    res->processa = processa;
    setStatusReserva(res, "SOLICITADA");

    return res;
}

/**
 * @brief Compara o CPF de quem solicitou a abertura da reserva com um CPF informado
 * @param r Reserva inicializada
 * @param cpf CPF a ser comparado
 * @return 1 se os CPFs forem iguais, 0 caso contrário
 */
int comparaCPFSolicitanteReserva(Reserva *r, char *cpf)
{
    if (!strcmp(r->cpf, cpf))
    {
        return 1;
    }

    return 0;
}

/**
 * @brief Processa uma reserva, verificando se os requisitos são atendidos e atualizando o status da reserva para CONFIRMADA ou CANCELADA
 * @param listaPassageiros Ponteiro para a lista de passageiros cadastrados
 * @param listaVoos Ponteiro para a lista de voos cadastrados
 * @param res Reserva a ser processada
 * @return 1 se a reserva for confirmada, 0 se for cancelada
 */
int processaReserva(void *listaPassageiros, void *listaVoos, Reserva *res)
{
    if (res->processa(listaPassageiros, listaVoos, res))
    {
        setStatusReserva(res, "CONFIRMADA");
        return 1;
    }

    setStatusReserva(res, "CANCELADA");
    return 0;
}

/**
 * @brief  Desaloca uma reserva da memória
 * @param doc estrutura do tipo Reserva que deve ser liberada da memória
 */
void desalocaReserva(Reserva *r)
{
    r->desaloca(r->dado);
    free(r);
}

/**
 * @brief  Imprime uma reserva
 * @param doc Reserva a ser notificada
 */
void imprimeReserva(Reserva *r)
{
    printf("- ID: %s\n", r->id);
    printf("- Passageiro: %s\n", r->cpf);
    printf("- Status: %s\n", r->status);
    printf("- Codigo do Voo: %s\n", r->codigo);
    printf("- Preco: %.2f\n", r->preco);
    r->imprime(r->dado);
    printf("===============================\n");
}

/**
 * @brief Atribui um preço a uma reserva
 * @param d Reserva inicializada
 * @param preco Preço a ser atribuido à reserva
 */
void setPrecoReserva(Reserva *d, float preco)
{
    d->preco = preco;
}

/**
 * @brief Atribui um status a uma reserva (CONFIRMADA, CANCELADA ou SOLICITADA)
 * @param d Reserva inicializada
 * @param status Status a ser atribuido à reserva
 */
void setStatusReserva(Reserva *d, char *status)
{
    strcpy(d->status, status);
}

/**
 * @brief Atribui um ID a uma reserva
 * @param d Reserva inicializada
 * @param id ID a ser atribuido à reserva
 */
void setIDReserva(Reserva *d, char *id)
{
    strcpy(d->id, id);
}

/**
 * @brief Obtem o código do voo associado a uma reserva
 * @param r Reserva inicializada
 * @return código do voo da Reserva
 */
char *getCodigoVooReserva(Reserva *r)
{
    return r->codigo;
}

/**
 * @brief Obtem o tipo de uma reserva
 * @param r Reserva inicializada
 * @return tipo da Reserva
 */
char getTipoReserva(Reserva *r)
{
    char tipo;

    tipo = r->getTipo();

    return tipo;
}

/**
 * @brief Obtem o CPF de quem solicitou a abertura da reserva
 * @param r Reserva inicializada
 * @return CPF de quem solicitou a abertura da reserva
 */
char *getCPFSolicitanteReserva(Reserva *r)
{
    return r->cpf;
}

/**
 * @brief Obtem o status de uma reserva
 * @param r Reserva inicializada
 * @return status da Reserva
 */
char *getStatusReserva(Reserva *r)
{
    return r->status;
}

/**
 * @brief Obtem o dado genérico de uma reserva
 * @param r Reserva inicializada
 * @return dado genérico da Reserva
 */
void *getDadoReserva(Reserva *r)
{
    return r->dado;
}