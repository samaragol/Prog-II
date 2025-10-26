#include "data.h"
#include <stdio.h>

/**
 * @brief Verifica se uma data é válida.
 *
 * @param dia Dia da data.
 * @param mes Mês da data.
 * @param ano Ano da data.
 * @return Retorna 1 se a data é válida e 0 caso contrário.
 */
int verificaDataValida(int dia, int mes, int ano)
{
    if (dia <= numeroDiasMes(mes, ano) && mes <= 12 && ano >= 0)
    {
        return 1;
    }

    return 0;
}

/**
 * @brief Imprime uma data no formato DD/MM/AAAA.
 *
 * @param dia Dia da data.
 * @param mes Mês da data.
 * @param ano Ano da data.
 */
void imprimeData(int dia, int mes, int ano)
{
    printf("%02d/%02d/%04d\n", dia, mes, ano);
}

/**
 * @brief Imprime o nome do mês por extenso.
 *
 * @param mes Mês da data.
 */
void imprimeMesExtenso(int mes)
{
    if (mes == 1)
    {
        printf("Janeiro");
    }
    else if (mes == 2)
    {
        printf("Fevereiro");
    }
    else if (mes == 3)
    {
        printf("Março");
    }
    else if (mes == 4)
    {
        printf("Abril");
    }
    else if (mes == 5)
    {
        printf("Maio");
    }
    else if (mes == 6)
    {
        printf("Junho");
    }
    else if (mes == 7)
    {
        printf("Julho");
    }
    else if (mes == 8)
    {
        printf("Agosto");
    }
    else if (mes == 9)
    {
        printf("Setembro");
    }
    else if (mes == 10)
    {
        printf("Outubro");
    }
    else if (mes == 11)
    {
        printf("Novembro");
    }
    else if (mes == 12)
    {
        printf("Dezembro");
    }
}

/**
 * @brief Imprime uma data por extenso no formato "DD de NOME_DO_MES de AAAA".
 *
 * @param dia Dia da data.
 * @param mes Mês da data.
 * @param ano Ano da data.
 */
void imprimeDataExtenso(int dia, int mes, int ano)
{
    printf("%02d de ", dia);
    imprimeMesExtenso(mes);
    printf(" de %04d\n", ano);
}

/**
 * @brief Verifica se um ano é bissexto.
 *
 * @param ano Ano a ser verificado.
 * @return Retorna 1 se o ano é bissexto e 0 caso contrário.
 */
int verificaBissexto(int ano)
{
    if (ano % 4 == 0 || (ano % 100 == 00 && ano % 400 == 0))
    {
        return 1;
    }

    return 0;
}

/**
 * @brief Retorna o número de dias de um determinado mês.
 *
 * @param mes Mês a ser verificado.
 * @param ano Ano da data.
 * @return Retorna o número de dias do mês.
 */
int numeroDiasMes(int mes, int ano)
{
    if (mes == 1)
    {
        return 31;
    }
    else if (mes == 2)
    {
        if (verificaBissexto(ano))
        {
            return 29;
        }
        return 28;
    }
    else if (mes == 3)
    {
        return 31;
    }
    else if (mes == 4)
    {
        return 30;
    }
    else if (mes == 5)
    {
        return 31;
    }
    else if (mes == 6)
    {
        return 30;
    }
    else if (mes == 7)
    {
        return 31;
    }
    else if (mes == 8)
    {
        return 31;
    }
    else if (mes == 9)
    {
        return 30;
    }
    else if (mes == 10)
    {
        return 31;
    }
    else if (mes == 11)
    {
        return 30;
    }
    else if (mes == 12)
    {
        return 31;
    }
}

/**
 * @brief Compara duas datas.
 *
 * @param dia1 Dia da primeira data.
 * @param mes1 Mês da primeira data.
 * @param ano1 Ano da primeira data.
 * @param dia2 Dia da segunda data.
 * @param mes2 Mês da segunda data.
 * @param ano2 Ano da segunda data.
 * @return Retorna 1 se a primeira data é maior que a segunda, -1 se a primeira data é menor que a segunda e 0 se as datas são iguais.
 */
int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2)
{
    if (ano1 > ano2)
    {
        return 1;
    }
    else if (ano1 == ano2)
    {
        if (mes1 > mes2)
        {
            return 1;
        }
        else if (mes1 == mes2)
        {
            if (dia1 > dia2)
            {
                return 1;
            }
            else if (dia1 == dia2)
            {
                return 0;
            }
        }
    }

    return -1;
}

/**
 * @brief Calcula o número de dias até o início de um determinado mês.
 *
 * @param mes Mês a ser verificado.
 * @param ano Ano da data.
 * @return Retorna o número de dias até o início do mês.
 */
int calculaDiasAteMes(int mes, int ano)
{
    int dias = 0, i;

    for (i = 1; i <= mes; i++)
    {
        dias += numeroDiasMes(i, ano);
    }

    return dias;
}

/**
 * @brief Calcula a diferença em dias entre duas datas.
 *
 * @param dia1 Dia da primeira data.
 * @param mes1 Mês da primeira data.
 * @param ano1 Ano da primeira data.
 * @param dia2 Dia da segunda data.
 * @param mes2 Mês da segunda data.
 * @param ano2 Ano da segunda data.
 * @return Retorna o número de dias de diferença entre as datas.
 */
int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2)
{
    int i, total_dias = 0;

    if (comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == -1)
    {
        for (i = ano1; i < ano2; i++)
        {
            if (verificaBissexto(i))
            {
                total_dias += 366;
            }
            else
            {
                total_dias += 365;
            }
        }

        total_dias += (calculaDiasAteMes(mes2, ano2) - numeroDiasMes(mes2, ano2) + dia2) - (calculaDiasAteMes(mes1, ano1) - numeroDiasMes(mes1, ano1) + dia1);
    }
    else if (comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == 1)
    {
        for (i = ano2; i < ano1; i++)
        {
            if (verificaBissexto(i))
            {
                total_dias += 366;
            }
            else
            {
                total_dias += 365;
            }
        }

        total_dias += (calculaDiasAteMes(mes1, ano1) - numeroDiasMes(mes1, ano1) + dia1) - (calculaDiasAteMes(mes2, ano2) - numeroDiasMes(mes2, ano2) + dia2);
    }

    return total_dias;
}

/**
 * @brief Imprime a próxima data no formato DD/MM/AAAA.
 *
 * @param dia Dia da data.
 * @param mes Mês da data.
 * @param ano Ano da data.
 */
void imprimeProximaData(int dia, int mes, int ano)
{
    dia++;
    if (dia > numeroDiasMes(mes, ano))
    {
        dia = 1;
        mes++;
        if (mes > 12)
        {
            mes = 1;
            ano++;
        }
    }

    printf("%02d/%02d/%04d\n", dia, mes, ano);
}
