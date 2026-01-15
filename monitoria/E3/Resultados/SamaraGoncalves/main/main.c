#include "ticket.h"
#include "tecnico.h"
#include "eletronica.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char nome[QTDMAXNOMEELETRONICA];
    char opcao[20];
    char id[MAXIDTECNICO];
    int cod;
    tEletronica *ele;
    tTecnico *tec;
    tTicket *tic;

    scanf("%[^\n]\n", nome);

    ele = criaEletronica(nome);

    while (1)
    {
        scanf("%s\n", opcao);

        if (!strcmp(opcao, "CADASTRA"))
        {
            tec = leTecnico();
            cadastraTecnico(ele, tec);
        }
        else if (!strcmp(opcao, "TICKET"))
        {
            tic = leTicket();
            scanf("%[^\n]\n", id);
            atribuiTicketEletronica(ele, id, tic);
        }
        else if (!strcmp(opcao, "AUMENTA"))
        {
            scanf("%[^\n]\n", id);
            aumentaCargaTecnicoEletronica(ele, id);
        }
        else if (!strcmp(opcao, "CONCLUI"))
        {
            scanf("%d\n", &cod);
            alteraSituacaoTicketEletronica(ele, cod);
        }
        else if (!strcmp(opcao, "IMPRIME"))
        {
            imprimeEletronica(ele);
        }
        else if (!strcmp(opcao, "FIM"))
        {
            destroiEletronica(ele);
            break;
        }
    }

    return 0;
}