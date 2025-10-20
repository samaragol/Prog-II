#include <stdio.h>
#include <stdlib.h>
int main()
{
    int lin, col, i, j, k, x_jog, y_jog, x_fim, y_fim, block = 0;
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
        for (i = 0; i < lin; i++)
        {
            if (i == y_jog)
            {
                for (j = 0; j < col; j++)
                {
                    if (j == x_jog)
                    {
                        printf("(%d,%d) ", y_jog + 1, x_jog + 1);
                        if (k == 4)
                        {
                            k = 0;
                        }
                        matriz[y_jog][x_jog] = 1;
                        if (ordem[k] == 'C') // aCima
                        {
                            if (matriz[i - 1][j] == 0 && i != 0)
                            {
                                y_jog = y_jog - 1;
                            }
                            else
                            {
                                block++;
                            }
                        }
                        else if (ordem[k] == 'B') // aBaixo
                        {
                            if (matriz[i + 1][j] == 0 && i != lin - 1)
                            {
                                y_jog = y_jog + 1;
                            }
                            else
                            {
                                block++;
                            }
                        }
                        else if (ordem[k] == 'D') // Direita
                        {
                            if (matriz[i][j + 1] == 0 && j != col - 1)
                            {
                                x_jog = x_jog + 1;
                            }
                            else
                            {
                                block++;
                            }
                        }
                        else if (ordem[k] == 'E') // Esquerda
                        {
                            if (matriz[i][j - 1] == 0 && j != 0)
                            {
                                x_jog = x_jog - 1;
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
                        // block = 0;
                        k++;
                    }
                }
            }
        }
    }

    return 0;
}