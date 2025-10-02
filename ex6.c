#include <stdio.h>

int main()
{
    int cota, i = 1, k, qtd = 1, impresso = 0;
    char codigos[1000], aux;

    scanf("%d\n", &cota);

    scanf("%c", &codigos[0]);
    while (scanf("%c", &codigos[i]) == 1 && codigos[i] != EOF)
    {
        for (k = i; k > 0; k--)
        {
            if (codigos[k] < codigos[k - 1])
            {
                aux = codigos[k];
                codigos[k] = codigos[k - 1];
                codigos[k - 1] = aux;
            }
        }
        i++;
    }

    for (k = 1; k < i; k++)
    {
        if (codigos[k - 1] == codigos[k])
        {
            qtd++;
        }
        else
        {
            if (qtd > cota)
            {
                printf("%c: %d\n", codigos[k - 1], qtd);
                impresso = 1;
            }
            qtd = 1;
        }
    }

    if (cota == 0 || qtd == 1000)
    {
        printf("%c: %d\n", codigos[k - 1], qtd);
        impresso = 1;
    }
    if (impresso == 0)
    {
        printf("NENHUM\n");
    }

    return 0;
}