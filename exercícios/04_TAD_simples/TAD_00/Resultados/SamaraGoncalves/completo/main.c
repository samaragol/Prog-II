#include "ponto.h"
#include <stdio.h>

int main()
{
    Ponto ponto1, ponto2;
    float x1, y1, x2, y2, dist = 0;

    scanf("%f %f %f %f", &x1, &y1, &x2, &y2);
    ponto1 = pto_cria(x1, y1);
    ponto2 = pto_cria(x2, y2);

    dist = pto_distancia(ponto1, ponto2);
    printf("%g", dist);

    return 0;
}