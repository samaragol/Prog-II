#include <stdio.h>
#include "restaurante.h"

int main()
{
    tRestaurante restaurante;
    tAlimento alimento;
    char opcao, nome[32];
    float qtd;

    restaurante = leRestaurante();

    while (scanf("%c\n", &opcao) == 1 && opcao != 'E')
    {
        if (opcao == 'A')
        {
            alimento = leAlimento();
            restaurante = cadastraAlimento(restaurante, alimento);
        }
        else if (opcao == 'C')
        {
            scanf("%[^\n]\n", nome);
            scanf("%f", &qtd);
            restaurante = consumirAlimentoRestaurante(restaurante, nome, qtd);
        }
        else if (opcao == 'I')
        {
            imprimeRestaurante(restaurante);
        }
    }

    return 0;
}