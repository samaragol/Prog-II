#include "reserva.h"
#include "data.h"
#include "morador.h"
#include "area.h"
#include <stdio.h>

int main()
{
    int qtd_areas, qtd_moradores, qtd_reser, qtd_convidados, num_reser = 0;
    int i, j;
    Area areas[10], area;
    Morador moradores[100], morador;
    Reserva reservas[100];
    Data data;
    char id_area[MAX_TAM_ID], cpf[MAX_TAM_CPF];

    scanf("%d\n", &qtd_areas);
    for (i = 0; i < qtd_areas; i++)
    {
        areas[i] = lerArea();
    }

    scanf("%d\n", &qtd_moradores);
    for (i = 0; i < qtd_moradores; i++)
    {
        moradores[i] = lerMorador();
    }

    scanf("%d\n", &qtd_reser);
    for (i = 0; i < qtd_reser; i++)
    {
        scanf("%[^\n]\n", id_area);
        scanf("%[^\n]\n", cpf);
        data = lerData();
        scanf("%d\n", &qtd_convidados);

        for (j = 0; j < qtd_areas; j++)
        {
            if (verificaIdArea(areas[j], id_area))
            {
                area = areas[j];
            }
        }

        for (j = 0; j < qtd_moradores; j++)
        {
            if (verificaCPFMorador(moradores[j], cpf))
            {
                if (verificaSolicitacaoReserva(reservas, num_reser, moradores[j], area, data, qtd_convidados))
                {
                    reservas[num_reser] = criaReserva(moradores[j], area, data, qtd_convidados);
                    num_reser++;
                }
            }
        }
    }

    for (i = 0; i < num_reser; i++)
    {
        imprimeReserva(reservas[i]);
    }

    return 0;
}