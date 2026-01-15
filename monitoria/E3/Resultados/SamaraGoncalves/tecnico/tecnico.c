#include "ticket.h"
#include "tecnico.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct str_tec
{
    char nome[MAXNOMETECNICO];
    char id[MAXIDTECNICO];
    tTicket **tickets;
    int qtdTickets;
    int qtdMax;
};

/** @brief cria, alocando memoria, e inicializa um tipo tTecnico a partir
 * dos parametros
 * Um tecnico possui um nome, um codigo de identificacao (char *id),
 * uma lista de tickets (tTickets **tickets), qtdMaxTickets e qtdTickets
 * A lista de tickets inicia vazia e a quantidade maxima de tickets
 * (qtdMaxTickets) comeca com 1 e quantidade de tickets (qtdTickets) começa com 0
 * @param nome nome a ser atribuido ao tecnico
 * @param id codigo de identificacao a ser atribuido ao tecnico
 * @return tTecnico alocado e inicializado
 */
tTecnico *criaTecnico(char *nome, char *id)
{
    tTecnico *tec;

    tec = (tTecnico *)calloc(1, sizeof(tTecnico));
    if (!tec)
    {
        printf("Falha na alocação do técnico.\n");
        return NULL;
    }

    strncpy(tec->nome, nome, MAXNOMETECNICO);
    strncpy(tec->id, id, MAXIDTECNICO);
    tec->qtdMax = 1;
    tec->tickets = (tTicket **)calloc(tec->qtdMax, sizeof(tTicket *));
    if (!tec->tickets)
    {
        printf("Falha na alocação de tickets.\n");
        return NULL;
    }

    return tec;
}

/** @brief le as informações de um tecnico seguindo a ordem de formatação:
 * nome
 * codigo de identificacao
 * criando, alocando memoria, de um tipo tTecnico a partir dos parametros lidos
 * @return tTecnico alocado e inicializado
 */
tTecnico *leTecnico()
{
    char nome[MAXNOMETECNICO];
    char id[MAXIDTECNICO];

    scanf("%[^\n]\n", nome);
    scanf("%[^\n]\n", id);

    return criaTecnico(nome, id);
}

/** @brief adiciona um ticket na lista de tickets de um tecnico
 * caso a lista esteja cheia, ou seja, com o a quantidade de tickets
 * igual a quantidade de maxima, imprima a mensagem "TECNICO SOBRECARREGADO",
 * não adicione o ticket e destrua-o (libere a memoria)
 * Incremente a quantidade de tickets
 * @param tec ponteiro do tecnico a ter o ticket adicionado
 * @param tic ponteiro do ticket a ser adicionado
 */
void atribuiTicket(tTecnico *tec, tTicket *tic)
{
    if (tec->qtdTickets >= tec->qtdMax)
    {
        printf("TECNICO SOBRECARREGADO\n");
        destroiTicket(tic);
    }
    else
    {
        tec->tickets[tec->qtdTickets] = tic;
        tec->qtdTickets++;
    }
}

/** @brief dobra a qtdMaxTickets de um tecnico, fazendo uma realocação (realloc) no
 * vetor tTickets correspondente a nova quantidade máxima de tickets
 * @param tec tecnico a ter a carga aumentada
 */
void aumentaCargaTecnico(tTecnico *tec)
{
    tec->qtdMax *= 2;
    tec->tickets = realloc(tec->tickets, sizeof(tTicket *) * tec->qtdMax);
}

/** @brief altera a situacao de um ticket na lista de tickets de
 * um tecnico para "CONCLUIDO", utilizando o codigo de identificacao para
 * pesquisar o ticket
 * Caso nao exista um ticket com o codigo fornecido,  não altere nada
 * @param tec tecnico a ter a lista de tickets pesquisada
 * @param codigo codigo do ticket a ser alterado
 */
void alteraSituacaoTicketTecnico(tTecnico *tec, int codigo)
{
    int i;

    for (i = 0; i < tec->qtdTickets; i++)
    {
        if (comparaTicket(tec->tickets[i], codigo))
        {
            alteraSituacaoTicket(tec->tickets[i]);
        }
    }
}

/** @brief retorna a quantidade de tickets com a situacao "PENDENTE" da
 * lista de tickets de um tecnico
 * @param tec tecnico a ter a lista de tickets percorrida
 * @return quantidade de tickets pendentes
 */
int quantidadeTicketsPendentes(tTecnico *t)
{
    int i, qtd = 0;

    for (i = 0; i < t->qtdTickets; i++)
    {
        if (estaPendenteTicket(t->tickets[i]))
        {
            qtd++;
        }
    }

    return qtd;
}

/** @brief compara se o id fornecido é igual ao de um tecnico
 * atencao: o id aqui é um char*, nao um int como em tTicket
 * @return 1 caso o id seja igual ao do tecnico, 0 caso contrario
 */
int comparaTecnico(tTecnico *t, char *id)
{
    if (!strcmp(t->id, id))
    {
        return 1;
    }

    return 0;
}

/** @brief get nome de um tTecnico
 *  @return nome do tecnico
 */
char *retornaNomeTecnico(tTecnico *t)
{
    return t->nome;
}

/** @brief imprime as informacoes de um tecnico seguindo a formatação:
 * Ficha do Tecnico #####
 * Nome: Ronaldo
 * Id: SUP0024
 * Tickets atribuidos:
 * ======================
 * Nome: Resistor queimado
 * Codigo: 1225
 * Situacao: PENDENTE
 * Descricao: Resistor de 190 Ohms de um circuito impresso está queimado e precisa de substituicao
 */
void imprimeTecnico(tTecnico *t)
{
    int i;

    printf("Ficha do Tecnico #####\n");
    printf("Nome: %s\n", t->nome);
    printf("Id: %s\n", t->id);
    printf("Tickets atribuidos:\n");
    for (i = 0; i < t->qtdTickets; i++)
    {
        imprimeTicket(t->tickets[i]);
    }
}

/** @brief desaloca todo o espaco de memoria alocado para um tecnico
 *
 */
void destroiTecnico(tTecnico *t)
{
    int i;

    for (i = 0; i < t->qtdTickets; i++)
    {
        destroiTicket(t->tickets[i]);
    }

    free(t->tickets);
    free(t);
}
