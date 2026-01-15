#include "ticket.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct tic_str
{
    char nome[MAXNOMETICKET];
    int codigo;
    char descricao[MAXDESCRICAOTICKET];
    char situacao[MAXSITUACAOTICKET];
};

/** @brief aloca a memória de um tipo tTicket e o inicializa com
 * os parametros passados, retornando o ponteiro alocado.
 * @param nome titulo do ticket
 * @param codigo codigo de identificacao do ticket
 * @param descricao descricao do ticket
 * A situação do ticket deve ser iniciada como "PENDENTE"
 */

tTicket *criaTicket(char *nome, int codigo, char *descricao)
{
    tTicket *tic;

    tic = (tTicket *)calloc(1, sizeof(tTicket));

    if (!tic)
    {
        printf("Falha na alocação do ticket.\n");
        return NULL;
    }

    strncpy(tic->nome, nome, MAXNOMETICKET);
    tic->codigo = codigo;
    strncpy(tic->descricao, descricao, MAXDESCRICAOTICKET);
    strcpy(tic->situacao, "PENDENTE");

    return tic;
}

/** @brief lê as informacoes do ticket e retorna seu ponteiro alocado
 * Lembre-se de cria-lo utilizando a funcao criaTicket e utilize a seguinte formatacao
 * nome
 * codigo
 * descricao
 */
tTicket *leTicket()
{
    char nome[MAXNOMETICKET];
    int codigo;
    char descricao[MAXDESCRICAOTICKET];

    scanf("%[^\n]\n", nome);
    scanf("%d\n", &codigo);
    scanf("%[^\n]\n", descricao);

    return criaTicket(nome, codigo, descricao);
}

/** @brief altera a situacao do ticket para "CONCLUIDO"
 */
void alteraSituacaoTicket(tTicket *t)
{
    strcpy(t->situacao, "CONCLUIDO");
}

/** @brief compara se o código passado por parâmetro corresponde ao
 * código de identificação de um ticket
 * Retorna 1 se verdadeiro e 0 se falso.
 *
 */
int comparaTicket(tTicket *t, int codigo)
{
    if (t->codigo == codigo)
    {
        return 1;
    }

    return 0;
}

/** @brief função get que retonar o nome do ticket
 */
char *retornaNomeTicket(tTicket *t)
{
    return t->nome;
}

/** @brief retorna 1 se o ticket ainda esta pendente, 0 caso contrario */
int estaPendenteTicket(tTicket *t)
{
    if (!strcmp(t->situacao, "PENDENTE"))
    {
        return 1;
    }

    return 0;
}

/** @brief imprime as informações de um ticket a partir da seguinte formatação:
 * ======================
 * Nome: Resistor queimado
 * Codigo: 1225
 * Situacao: PENDENTE
 * Descricao: Resistor de 190 Ohms de um circuito impresso está queimado e precisa de substituicao
 */

void imprimeTicket(tTicket *t)
{
    printf("======================\n");
    printf("Nome: %s\n", t->nome);
    printf("Codigo: %d\n", t->codigo);
    printf("Situacao: %s\n", t->situacao);
    printf("Descricao: %s\n", t->descricao);
}

/** @brief libera a memória alocada para o ticket
 */
void destroiTicket(tTicket *t)
{
    free(t);
}