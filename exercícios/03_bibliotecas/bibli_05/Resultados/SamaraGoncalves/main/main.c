#include "string_utils.h"
#include <stdio.h>

/*
1 - Tamanho da string
2 - Copiar string
3 - Converter string para letras maiusculas
4 - Converter string para letras minusculas
5 - Imprimir string ao contrario
6 - Encerrar o programa
Opcao escolhida:
*/
void imprimeMenu()
{
    printf("1 - Tamanho da string\n2 - Copiar string\n3 - Converter string para letras maiusculas\n4 - Converter string para letras minusculas\n5 - Imprimir string ao contrario\n6 - Encerrar o programa\nOpcao escolhida: \n");
}

int main()
{
    char str[100], str_cpy[100];
    int opc;

    scanf("%[^\n]\n", str);

    imprimeMenu();

    while (scanf("%d", &opc) == 1 && opc != 6)
    {
        if (opc == 1)
        {
            printf("Tamanho da string: %d\n", string_length(str));
        }
        else if (opc == 2)
        {
            string_copy(str, str_cpy);
            printf("String copiada: %s\n", str_cpy);
        }
        else if (opc == 3)
        {
            string_upper(str);
            printf("String convertida para maiusculas: %s\n", str);
        }
        else if (opc == 4)
        {
            string_lower(str);
            printf("String convertida para minusculas: %s\n", str);
        }
        else if (opc == 5)
        {
            string_reverse(str);
            printf("String invertida: %s\n", str);
        }

        printf("\n");
        imprimeMenu();
    }

    return 0;
}