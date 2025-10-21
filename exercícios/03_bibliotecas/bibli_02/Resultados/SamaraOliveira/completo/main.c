#include <stdio.h>
#include "matrix_utils.h"

void imprimeMenu()
{
    printf("1 - Somar matrizes\n2 - Subtrair matrizes\n3 - Multiplicar matrizes\n4 - Multiplicacao de uma matriz por escalar\n5 - Transposta de uma matriz\n6 - Encerrar o programa\nOpcao escolhida: \n");
}

void inicializaMatrix(int rows, int cols, int matrix[rows][cols])
{
    int i, j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            matrix[i][j] = 0;
        }
    }
}
int main()
{
    int input = -1, rows1, rows2, cols1, cols2, scalar = 1, option = 1;

    // Matriz 1
    scanf("%d %d", &rows1, &cols1);
    int matrix1[rows1][cols1];
    matrix_read(rows1, cols1, matrix1);

    // Matriz 2
    scanf("%d %d", &rows2, &cols2);
    int matrix2[rows2][cols2];
    matrix_read(rows2, cols2, matrix2);

    // Inicializa matrizes
    inicializaMatrix(rows1, cols1, matrix1);
    inicializaMatrix(rows2, cols2, matrix2);

    imprimeMenu();

    while (scanf("%d", &input) == 1 && input != 6)
    {
        if (input == 1)
        {
            if (possible_matrix_sum(rows1, cols1, rows2, cols2))
            {
                int result[rows1][cols1];
                inicializaMatrix(rows1, cols1, result);

                matrix_add(rows1, cols1, matrix1, rows2, cols2, matrix2, result);
                matrix_print(rows1, cols1, result);
            }
            else
            {
                printf("Erro: as dimensoes da matriz nao correspondem\n");
            }
        }
        else if (input == 2)
        {
            if (possible_matrix_sub(rows1, cols1, rows2, cols2))
            {
                int result[rows1][cols1];
                inicializaMatrix(rows1, cols1, result);

                matrix_sub(rows1, cols1, matrix1, rows2, cols2, matrix2, result);
                matrix_print(rows1, cols1, result);
            }
            else
            {
                printf("Erro: as dimensoes da matriz nao correspondem\n");
            }
        }
        else if (input == 3)
        {
            if (possible_matrix_multiply(cols1, rows2))
            {
                int result[rows1][cols1];
                inicializaMatrix(rows1, cols1, result);

                matrix_multiply(rows1, cols1, matrix1, rows2, cols2, matrix2, result);
                matrix_print(rows1, cols2, result);
            }
            else
            {
                printf("Erro: as dimensoes da matriz nao correspondem\n");
            }
        }
        else if (input == 4)
        {
            scanf("%d %d", &scalar, &option);

            if (option == 1)
            {
                scalar_multiply(rows1, cols1, matrix1, scalar);
                matrix_print(rows1, cols1, matrix1);
            }
            else
            {
                scalar_multiply(rows2, cols2, matrix2, scalar);
                matrix_print(rows2, cols2, matrix2);
            }
        }
        else if (input == 5)
        {
            int result1[rows1][cols1];
            inicializaMatrix(rows1, cols1, result1);
            transpose_matrix(rows1, cols1, matrix1, result1);
            matrix_print(rows1, cols1, result1);
            int result2[rows2][cols2];
            inicializaMatrix(rows2, cols2, result2);
            transpose_matrix(rows2, cols2, matrix2, result2);
            matrix_print(rows2, cols2, result2);
        }

        imprimeMenu();
    }

    return 0;
}