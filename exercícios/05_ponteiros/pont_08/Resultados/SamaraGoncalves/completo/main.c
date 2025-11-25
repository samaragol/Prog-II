#include <stdio.h>
#include "tDepartamento.h"

int main()
{
    char curso1[STRING_MAX];
    char curso2[STRING_MAX];
    char curso3[STRING_MAX];
    char diretor[STRING_MAX];
    char nome[STRING_MAX];
    int m1, m2, m3, qtd_deptos, i;

    scanf("%d\n", &qtd_deptos);
    tDepartamento vet_deptos[qtd_deptos];

    for (i = 0; i < qtd_deptos; i++)
    {
        scanf("%[^\n]\n", nome);
        scanf("%[^\n]\n", diretor);
        scanf("%[^\n]\n", curso1);
        scanf("%[^\n]\n", curso2);
        scanf("%[^\n]\n", curso3);
        scanf("%d %d %d\n", &m1, &m2, &m3);
        if (m1 < 0 || m2 < 0 || m3 < 0)
        {
            printf("\nDigite um departamento com médias válidas");
            i--;
        }
        else
        {
            vet_deptos[i] = CriaDepartamento(curso1, curso2, curso3, nome, m1, m2, m3, diretor);
        }
    }

    for (i = 0; i < qtd_deptos; i++)
    {
        ImprimeAtributosDepartamento(vet_deptos[i]);
        
    }
    printf("\n");
    

    return 0;
}