#include <stdio.h>
#include <math.h>

int main()
{
    float x_alvo, y_alvo, r_alvo, x_tiro, y_tiro, r_tiro, soma_raios, distancia;

    scanf("%f%f%f%f%f%f", &x_alvo, &y_alvo, &r_alvo, &x_tiro, &y_tiro, &r_tiro);

    soma_raios = r_alvo + r_tiro;

    distancia = sqrt(pow(x_alvo - x_tiro, 2) + pow(y_alvo - y_tiro, 2));

    if (distancia <= soma_raios)
    {
        printf("ACERTOU");
    }
    else
    {
        printf("ERROU");
    }

    return 0;
}