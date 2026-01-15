#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pacote.h"
#include "gerenciadorpacotes.h"

void imprimeMenu()
{
    printf("\nEscolha uma opcao:\n");
    printf("\t(1) Cadastrar um novo pacote\n");
    printf("\t(2) Imprimir um pacote especifico\n");
    printf("\t(3) Imprimir todos os pacotes e sair\n");
}

int main()
{
    int opc = 0, type, numElem, idx;
    tPacote *pac;
    tGerenciador *geren;

    geren = CriaGerenciador();

    while (1)
    {
        imprimeMenu();

        scanf("%d\n", &opc);

        if (opc == 1)
        {
            printf("Digite o tipo (0-char, 1-int) e o numero de elementos do pacote/mensagem: ");
            scanf("%d %d", &type, &numElem);

            if (type != 1 && type != 0)
            {
                printf("\nDigite um tipo valido!");
            }
            else
            {
                pac = CriaPacote(type, numElem);
                LePacote(pac);
                AdicionaPacoteNoGerenciador(geren, pac);
            }
        }
        else if (opc == 2)
        {
            scanf("%d\n", &idx);
            ImprimirPacoteNoIndice(geren, idx);
        }
        else if (opc == 3)
        {
            ImprimirTodosPacotes(geren);
            DestroiGerenciador(geren);
            break;
        }
        else
        {
            printf("Escolha uma opcao valida para o menu!");
        }
    }

    return 0;
}