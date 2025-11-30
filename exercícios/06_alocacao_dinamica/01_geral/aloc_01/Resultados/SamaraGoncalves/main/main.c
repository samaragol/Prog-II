#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main()
{
    int *vetor, tam;
    float media;

    scanf("%d\n", &tam);

    vetor = CriaVetor(tam);
    if (vetor == NULL)
    {
        printf("Problema na alocação\n");
        return 1;
    }
    LeVetor(vetor, tam);
    media = CalculaMedia(vetor, tam);

    printf("%.2f", media);

    LiberaVetor(vetor);
    return 0;
}