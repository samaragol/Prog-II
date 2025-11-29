#include <stdio.h>
#include "vetor.h"

int soma(int num1, int num2)
{
    return num1 + num2;
}

int produto(int num1, int num2)
{
    return num1 * num2;
}

int main()
{
    Vetor vetor;

    LeVetor(&vetor);

    printf("Soma: %d\n", AplicarOperacaoVetor(&vetor, soma));
    printf("Produto: %d\n", AplicarOperacaoVetor(&vetor, produto));

    return 0;
}