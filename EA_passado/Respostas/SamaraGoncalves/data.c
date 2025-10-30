#include "data.h"
#include <stdio.h>


/*
 * Função que lê uma data no formato dd/mm/aaaa
 * e retorna a Data lida
 */
Data lerData()
{
    Data data;
    scanf("%d/%d/%d\n", &data.dia, &data.mes, &data.ano);
    return data;
}

/*
 * Função que imprime uma data no formato dd/mm/aaaa
 * Com \n no final.
 */
void imprimeData(Data d)
{
    printf("%d/%d/%d\n", d.dia, d.mes, d.ano);
}

/*
 *   Função que compara se as duas datas são exatamente iguais
 *   Retorna 1 se verdadeiro e 0 caso contrário
 */
int comparaData(Data d1, Data d2)
{
    if (d1.dia == d2.dia && d1.mes == d2.mes && d1.ano == d2.ano)
    {
        return 1;
    }

    return 0;
}

/*
 *  Função que calcula a diferença de anos entre duas datas da mesma
 *  forma que calculamos aniversários.
 *  Exemplo: 25/12/1990 e 10/12/2025 = 34 anos
 *  Retorna a diferença de anos entre as duas datas
 */
int calcularDiffAnosData(Data inicio, Data fim)
{
    int diff;

    diff = fim.ano - inicio.ano;
    if (fim.mes <= inicio.mes)
    {
        if (fim.dia < inicio.dia)
        {
            diff--;
        }
    }

    return diff;
}
