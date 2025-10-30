#include "data.h"
#include "morador.h"
#include <string.h>
#include <stdio.h>

/*
 *  Função que lê um morador de acordo com o formato de entrada descrito na
 *  especificação
 *  Retorna o Morador lido
 */
Morador lerMorador()
{
    Morador morador;

    
    scanf("%[^\n]\n", morador.nome);
    scanf("%[^\n]\n", morador.cpf);
    morador.dataNasc = lerData();
    scanf("%[^\n]\n", morador.idResidencia);

    return morador;
}

/**
 * Função que imprime todas as informações de uma Morador conforme o formato
 * descrito na especificação. Dica: veja o arquivo de saída nos casos de teste.
 *
 */
void imprimeMorador(Morador m)
{
    printf("Nome: %s\nCPF: %s\n", m.nome, m.cpf);
    printf("Data de Nascimento: ");
    imprimeData(m.dataNasc);
    printf("Residência: %s\n", m.idResidencia);
}

/**
 * Verifica se dois moradores são iguais. A comparação é feita usando apenas o CPF.
 * Se for exatamente o mesmo, retorna 1. Caso contrário, retorna 0.
 */
int comparaMorador(Morador m1, Morador m2)
{
    if (strcmp(m1.cpf, m2.cpf) == 0)
    {
        return 1;
    }

    return 0;
}

/**
 * Verifica se um dado CPF pertence ao morador.
 * Se for exatamente o mesmo, retorna 1. Caso contrário, retorna 0.
 */
int verificaCPFMorador(Morador m1, char *cpf)
{
    if (strcmp(m1.cpf, cpf) == 0)
    {
        return 1;
    }

    return 0;
}

/*
 *  Função que calcula a idade de um morador em relação a uma data de referência
 *  Retorna a idade do morador em anos
 */
int calculaIdadeMorador(Morador m, Data dataRef)
{
    return calcularDiffAnosData(m.dataNasc, dataRef);
}
