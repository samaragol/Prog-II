#include <stdio.h>
#include <stdlib.h>
#include "midia.h"
#include "roteiro.h"
#include "livro.h"
#include "pintura.h"
#include "musica.h"

int main()
{
    int i, qtd;
    char opc;
    Roteiro *rot;

    rot = roteiro_construct();

    scanf("%d\n", &qtd);

    for (i = 0; i < qtd; i++)
    {
        scanf("%c", &opc);

        if (opc == 'L')
        {
            Livro *liv = livro_read_and_construct();
            roteiro_inserir_midia(rot, liv, livro_print, livro_destroy);
        }
        else if (opc == 'M')
        {
            Musica *mus = musica_read_and_construct();
            roteiro_inserir_midia(rot, mus, musica_print, musica_destroy);
        }
        else if (opc == 'P')
        {
            Pintura *pin = pintura_read_and_construct();
            roteiro_inserir_midia(rot, pin, pintura_print, pintura_destroy);
        }
        else
        {
            printf("Nao e uma midia valida!!!\n");
        }
    }

    roteiro_imprimir_midias(rot);
    roteiro_destroy(rot);

    return 0;
}