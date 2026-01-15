#include "midia.h"
#include "roteiro.h"
#include "pintura.h"
#include "musica.h"
#include "livro.h"
#include <stdio.h>

int main(){
    int n;

    Roteiro* r = roteiro_construct();

    scanf("%d%*c", &n);

    for(int i = 0; i < n; i++){
        char op;

        scanf("%c", &op);

        if(op == 'P'){  //pintura
            Pintura* p = pintura_read_and_construct();
            roteiro_inserir_midia(r, p, pintura_print, pintura_destroy);
        }

        else if(op == 'M'){ //musica
            Musica* m = musica_read_and_construct();
            roteiro_inserir_midia(r, m, musica_print, musica_destroy);
        }

        else if(op=='L'){   //livro
            Livro* l = livro_read_and_construct();
            roteiro_inserir_midia(r, l, livro_print, livro_destroy);
        }

        else printf("Nao e uma midia valida!!!\n");
    }

    roteiro_imprimir_midias(r);

    roteiro_destroy(r);

    return 0;
}