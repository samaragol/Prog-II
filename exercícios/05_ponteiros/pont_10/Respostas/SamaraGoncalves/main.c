#include <stdio.h>
#include <string.h>
#include "pessoa.h"

int main()
{
    int qtd, i;

    scanf("%d\n", &qtd);
    tPessoa pessoas[qtd];

    for (i = 0; i < qtd; i++)
    {
        pessoas[i] = CriaPessoa();
        LePessoa(&pessoas[i]);
    }
    AssociaFamiliasGruposPessoas(pessoas, qtd);
    for (i = 0; i < qtd; i++)
    {
        ImprimePessoa(&pessoas[i]);
    }
    
    return 0;
}