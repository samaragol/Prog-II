#include <stdio.h>
#include <string.h>
#include "tAnimal.h"
#include "tRecinto.h"
#include "tZoologico.h"

void imprimeMenu(tZoologico *zoo)
{
    printf("Dia %d no zoológico %s\nMenu:\n A - Adicionar animal\n D - Passar o dia\n F - Registrar fuga em recinto\n E - Encerrar programa\n", zoo->dia, GetNome(zoo));
}

int main()
{
    char opc;
    char nome[50];
    int nRecintos, capacidade, fome, idx, rebeliao = 0;
    tAnimal animal;
    tZoologico zoo;

    scanf("%[^\n]\n", nome);
    scanf("%d %d\n", &nRecintos, &capacidade);

    zoo = CriaZoologico(nome, nRecintos, capacidade);

    imprimeMenu(&zoo);

    while (scanf("%c\n", &opc) == 1 && opc != 'E')
    {
        if (opc == 'A')
        {
            printf("Informe o nível de fome e o nome do animal:\n");
            scanf("%d %[^\n]\n", &fome, nome);
            animal = CriaAnimal(nome, fome);
            if (!AdicionaAnimalZoologico(&zoo, animal))
            {
                printf("FUGA GERAL NO ZOOLÓGICO!!!\nTodos os animais fugiram.\n");
                return 0;
            }
        }
        else if (opc == 'D')
        {
            PassaDiaZoologico(&zoo);
        }
        else if (opc == 'F')
        {
            printf("Informe o recinto em que ocorreu a fuga:\n");
            scanf("%d\n", &idx);
            FugaRecintoZoologico(&zoo, idx);
        }

        imprimeMenu(&zoo);
    }

    EncerraZoologico(&zoo);

    return 0;
}