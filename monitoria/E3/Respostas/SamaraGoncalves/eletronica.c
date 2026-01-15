#include "ticket.h"
#include "tecnico.h"
#include "eletronica.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct str_ele
{
    char nome[QTDMAXNOMEELETRONICA];
    tTecnico *tecnicos[QTDMAXTECNICO];
    int qtdTec;
};

/** @brief cria, alocando na memoria, um tipo tEletronica, a partir dos parametros
 * Uma eletronica tem um nome (char *), um vetor de ponteiros para tecnicos (Tecnicos **)
 * e um qtdTecnicos, que se inicia com 0;
 * aloque 10 espacos para o vetor tTecnico e inicie qtdTecnicos como 0
 * @return um tipo tEletronica inicializado e alocado
 */
tEletronica *criaEletronica(char *nome)
{
    tEletronica *ele;

    ele = (tEletronica *)calloc(1, sizeof(tEletronica));

    if (!ele) // ele não!
    {
        printf("Falha na alocação da eletrônica.\n");
        return NULL;
    }

    strncpy(ele->nome, nome, QTDMAXNOMEELETRONICA);

    return ele;
}

/** @brief adiciona um tipo tTecnico na lista de tecnicos de uma eletronica
 * @param e eletronica a ter um tecnico adicionado
 * @param t tecnico a ser adicionado
 */
void cadastraTecnico(tEletronica *e, tTecnico *t)
{
    if (e->qtdTec == QTDMAXTECNICO)
    {
        printf("Quantidade máxima atingida!\n");
        // nem tem caso assim mas é por via das dúvidas
    }
    else
    {
        e->tecnicos[e->qtdTec] = t;
        e->qtdTec++;
    }
}

/** @brief adiciona um ticket a um tecnico pertencente a uma eletronica
 * utilize o id para pesquisar e encontrar o tecnico com codigo de identificao igual
 * caso nao encontre, imprima a mensagem de erro "TECNICO NAO ENCONTRADO" e não faça nada
 * @param e eletronica a ter a lista de tecnicos pesquisada
 * @param id codigo de identificacao do tecnico a ter o ticket atribuido
 * @param t ticket a ser atribuido
 */
void atribuiTicketEletronica(tEletronica *e, char *id, tTicket *t)
{
    int i, encontrou = 0;

    for (i = 0; i < e->qtdTec; i++)
    {
        if (comparaTecnico(e->tecnicos[i], id))
        {
            atribuiTicket(e->tecnicos[i], t);
            encontrou = 1;
        }
    }

    if (!encontrou)
    {
        printf("TECNICO NAO ENCONTRADO\n");
        destroiTicket(t);
    }
}

/** @brief dobra a qtdMaxTickets de um tecnico, utilizando o id como parametro de pesquisa
 * caso nao encontre, imprima a mensagem de erro "TECNICO NAO ENCONTRADO" e não faça nada
 * @param e eletronica a ter a lista de tecnicos pesquisada
 * @param id codigo de identificacao do tecnico a ter a carga aumentada
 */
void aumentaCargaTecnicoEletronica(tEletronica *e, char *id)
{
    int i, encontrou = 0;

    for (i = 0; i < e->qtdTec; i++)
    {
        if (comparaTecnico(e->tecnicos[i], id))
        {
            aumentaCargaTecnico(e->tecnicos[i]);
            encontrou = 1;
        }
    }

    if (!encontrou)
    {
        printf("TECNICO NAO ENCONTRADO\n");
    }
}

/** @brief encontra um ticket na lista de ticket de todos os tecnicos de uma eletronica,
 * utilizando o codigo para pesquisa, e altera sua situacao para "CONCLUIDO"
 * @param e eletronica a ser pesquisada
 * @param codigo codigo a ser utilizado para pesquisar o ticket
 */

void alteraSituacaoTicketEletronica(tEletronica *e, int codigo)
{
    int i;

    for (i = 0; i < e->qtdTec; i++)
    {
        alteraSituacaoTicketTecnico(e->tecnicos[i], codigo);
    }
}

/** @brief imprime as informacoes de uma eletronica a partir da seguinte formatacao
 * Nome: WS Eletronica
 * Tecnicos empregados:
 * Ficha do Tecnico #####
 * Nome: Ronaldo
 * Id: SUP0024
 * Tickets atribuidos:
 * ======================
 * Nome: Resistor queimado
 * Codigo: 1225
 * Situacao: PENDENTE
 * Descricao: Resistor de 190 Ohms de um circuito impresso está queimado e precisa de substituicao
 * ======================
 * Tecnico com maior numero de pendencias: Ronaldo, 1 pendencia(s)
 */
void imprimeEletronica(tEletronica *e)
{
    int i, tec = 0, maior = 0;

    printf("Nome: %s\n", e->nome);
    printf("Tecnicos empregados:\n");

    for (i = 0; i < e->qtdTec; i++)
    {
        imprimeTecnico(e->tecnicos[i]);

        if (i == 0)
        {
            maior = quantidadeTicketsPendentes(e->tecnicos[i]);
        }

        if (quantidadeTicketsPendentes(e->tecnicos[i]) > maior)
        {
            maior = quantidadeTicketsPendentes(e->tecnicos[i]);
            tec = i;
        }
    }
    printf("======================\n");
    printf("Tecnico com maior numero de pendencias: %s\n", retornaNomeTecnico(e->tecnicos[tec]));
}

/** @brief desaloca toda a memoria alocada para um tipo tEletronica
 *
 */
void destroiEletronica(tEletronica *e)
{
    int i;

    for (i = 0; i < e->qtdTec; i++)
    {
        destroiTecnico(e->tecnicos[i]);
    }
    free(e);
}
