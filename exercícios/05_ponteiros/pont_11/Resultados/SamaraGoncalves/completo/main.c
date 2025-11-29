#include <stdio.h>
#include "calculadora.h"

float adicao(float num1, float num2)
{
    return num1 + num2;
}

float subtracao(float num1, float num2)
{
    return num1 - num2;
}

float multiplicacao(float num1, float num2)
{
    return num1 * num2;
}

float divisao(float num1, float num2)
{
    return num1 / num2;
}

int main()
{
    char opc;
    float num1, num2, result = 0;

        while (scanf(" %c\n", &opc) == 1 && opc != 'f')
    {
        scanf("%f %f\n", &num1, &num2);

        if (opc == 'a')
        {
            result = Calcular(num1, num2, adicao);
            printf("%.2f + %.2f =", num1, num2);
        }
        else if (opc == 's')
        {
            result = Calcular(num1, num2, subtracao);
            printf("%.2f - %.2f =", num1, num2);
        }
        else if (opc == 'm')
        {
            result = Calcular(num1, num2, multiplicacao);
            printf("%.2f x %.2f =", num1, num2);
        }
        else if (opc == 'd')
        {
            result = Calcular(num1, num2, divisao);
            printf("%.2f / %.2f =", num1, num2);
        }

        printf(" %.2f\n", result);
    }

    return 0;
}