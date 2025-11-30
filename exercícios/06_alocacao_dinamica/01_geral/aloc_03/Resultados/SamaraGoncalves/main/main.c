#include <stdio.h>
#include <stdlib.h>
#include "utils_char.h"

int main()
{
    char *vetor;
    int tamanho;

    scanf("%d\n", &tamanho);
    vetor = CriaVetor(tamanho);
    ImprimeString(vetor, tamanho);
    LeVetor(vetor, tamanho);
    ImprimeString(vetor, tamanho);
    LiberaVetor(vetor);

    return 0;
}