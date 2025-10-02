#include <stdio.h>
#include <math.h>

int main()
{
    int num_dec, num_oct = 0, i = 0, pot;

    scanf("%d", &num_dec);

    while (num_dec > 0)
    {
        pot = pow(10, i);
        num_oct += (num_dec % 8) * pot;
        num_dec = num_dec / 8;
        i++;
    }

    printf("%d", num_oct);

    return 0;
}