#include <stdio.h>
#include <stdlib.h>
int main()
{
    int lin, col, i, j, k = 0, x_jog, y_jog, x_fim, y_fim, block = 0;
    char ordem[4];

    scanf("%d %d", &lin, &col);

    int matriz[lin][col];

    for (i = 0; i < lin; i++)
    {
        for (j = 0; j < col; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }

    scanf("%d %d %d %d\n", &y_jog, &x_jog, &y_fim, &x_fim);

    x_jog--;
    y_jog--;
    x_fim--;
    y_fim--;

    for (i = 0; i < 4; i++)
    {
        scanf("%c", &ordem[i]);
    }

    while (1)
    {
        printf("(%d,%d) ", y_jog + 1, x_jog + 1);

        if (k == 4)
        {
            k = 0;
        }

        if (ordem[k] == 'C') // aCima
        {
            if (matriz[y_jog - 1][x_jog] == 0 && y_jog != 0)
            {
                matriz[y_jog][x_jog] = 1;
                y_jog--;
            }
            else
            {
                block++;
            }
        }
        else if (ordem[k] == 'B') // aBaixo
        {
            if (matriz[y_jog + 1][x_jog] == 0 && y_jog != lin - 1)
            {
                matriz[y_jog][x_jog] = 1;
                y_jog++;
            }
            else
            {
                block++;
            }
        }
        else if (ordem[k] == 'D') // Direita
        {
            if (matriz[y_jog][x_jog + 1] == 0 && x_jog != col - 1)
            {
                matriz[y_jog][x_jog] = 1;
                x_jog++;
            }
            else
            {
                block++;
            }
        }
        else if (ordem[k] == 'E') // Esquerda
        {
            if (matriz[y_jog][x_jog - 1] == 0 && x_jog != 0)
            {
                matriz[y_jog][x_jog] = 1;
                x_jog--;
            }
            else
            {
                block++;
            }
        }

        if (x_jog == x_fim && y_jog == y_fim)
        {
            printf("Chegou na posião final");
            exit(0);
        }

        if (block == 4)
        {
            printf("block = %d", block);
            exit(0);
        }
        block = 0;
        k++;
    }

    return 0;
}