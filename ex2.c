#include <stdio.h>

int main()
{
    int loop, linhas, num = 1, k;

    scanf("%d", &linhas);

    for (loop = 0; loop < linhas; loop++)
    {
        for (k = 0; k < loop; k++, num++)
        {
            printf("%d ", num);
        }
        printf("\n");
    }

    return 0;
}