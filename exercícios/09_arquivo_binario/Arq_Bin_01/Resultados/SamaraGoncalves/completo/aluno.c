#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

struct aluno
{
    char nome[100];
    char dtNasc[100];
    char curso[100];
    char periodo[50];
    int conclusao;
    float cra;
};

Aluno **CriaVetorAlunos(int numeroAlunos)
{
    Aluno **vetorAlunos;
    vetorAlunos = (Aluno **)calloc(numeroAlunos, sizeof(Aluno *));
    return vetorAlunos;
}

Aluno *CriaAluno(char *nome, char *dtNasc, char *cursoUfes, char *periodoIngresso, int percConclusao, float CRA)
{
    Aluno *aluno;
    aluno = (Aluno *)calloc(1, sizeof(Aluno));

    strcpy(aluno->nome, nome);
    strcpy(aluno->dtNasc, dtNasc);
    strcpy(aluno->curso, cursoUfes);
    strcpy(aluno->periodo, periodoIngresso);
    aluno->conclusao = percConclusao;
    aluno->cra = CRA;

    return aluno;
}

void LeAlunos(Aluno **vetorAlunos, int numeroAlunos)
{
    int i;
    char nome[100];
    char dtNasc[100];
    char cursoUfes[100];
    char periodoIngresso[50];
    int percConclusao;
    float CRA;
    Aluno *aluno;

    for (i = 0; i < numeroAlunos; i++)
    {
        scanf(" %[^\n]\n", nome);
        scanf("%[^\n]\n", dtNasc);
        scanf("%[^\n]\n", cursoUfes);
        scanf("%[^\n]\n", periodoIngresso);
        scanf("%d\n", &percConclusao);
        scanf("%f\n", &CRA);

        vetorAlunos[i] = CriaAluno(nome, dtNasc, cursoUfes, periodoIngresso, percConclusao, CRA);
    }
}

void LiberaAlunos(Aluno **alunos, int numeroAlunos)
{
    int i;

    for (i = 0; i < numeroAlunos; i++)
    {
        if (alunos[i] != NULL)
        {
            free(alunos[i]);
        }
    }
    if (alunos != NULL)
    {
        free(alunos);
    }
}

void SalvaAlunosBinario(Aluno **alunos, char *fileName, int numeroAlunos)
{
    FILE *file = fopen(fileName, "wb");
    int bytes = 0;
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    // Salva a quantidade de alunos
    bytes += fwrite(&numeroAlunos, sizeof(int), 1, file);

    for (int i = 0; i < numeroAlunos; i++)
    {
        int tam;

        // nome
        tam = strlen(alunos[i]->nome) + 1;
        bytes += fwrite(&tam, sizeof(int), 1, file) * sizeof(int); 
        bytes += fwrite(alunos[i]->nome, sizeof(char), tam, file) * sizeof(char);

        // data de nascimento
        tam = strlen(alunos[i]->dtNasc) + 1;
        bytes += fwrite(&tam, sizeof(int), 1, file) * sizeof(int);
        bytes += fwrite(alunos[i]->dtNasc, sizeof(char), tam, file) * sizeof(char);

        // curso
        tam = strlen(alunos[i]->curso) + 1;
        bytes += fwrite(&tam, sizeof(int), 1, file) * sizeof(int);
        bytes += fwrite(alunos[i]->curso, sizeof(char), tam, file) * sizeof(char);

        // período de ingresso
        tam = strlen(alunos[i]->periodo) + 1;
        bytes += fwrite(&tam, sizeof(int), 1, file) * sizeof(int);
        bytes += fwrite(alunos[i]->periodo, sizeof(char), tam, file) * sizeof(char);

        // dados simples
        bytes += fwrite(&alunos[i]->conclusao, sizeof(int), 1, file) * sizeof(int);
        bytes += fwrite(&alunos[i]->cra, sizeof(float), 1, file)* sizeof(float);
    }

    printf("Numero de bytes salvos: %d\n", bytes);
    fclose(file);
}

void CarregaAlunosBinario(Aluno **alunos, char *fileName)
{
    FILE *file = fopen(fileName, "rb");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    int numeroAlunos;
    fread(&numeroAlunos, sizeof(int), 1, file);

    for (int i = 0; i < numeroAlunos; i++)
    {
        alunos[i] = (Aluno *)calloc(1, sizeof(Aluno));

        int tam;

        // nome
        fread(&tam, sizeof(int), 1, file);
        fread(alunos[i]->nome, sizeof(char), tam, file);

        // data de nascimento
        fread(&tam, sizeof(int), 1, file);
        fread(alunos[i]->dtNasc, sizeof(char), tam, file);

        // curso
        fread(&tam, sizeof(int), 1, file);
        fread(alunos[i]->curso, sizeof(char), tam, file);

        // período de ingresso
        fread(&tam, sizeof(int), 1, file);
        fread(alunos[i]->periodo, sizeof(char), tam, file);

        // dados simples
        fread(&alunos[i]->conclusao, sizeof(int), 1, file);
        fread(&alunos[i]->cra, sizeof(float), 1, file);
    }

    fclose(file);
}

void ImprimeAlunos(Aluno **alunos, int numeroAlunos)
{
    int i;

    for (i = 0; i < numeroAlunos; i++)
    {
        printf("Aluno %d:\n", i);
        printf("Nome: %s\n", alunos[i]->nome);
        printf("Data Nascimento: %s\n", alunos[i]->dtNasc);
        printf("Curso: %s\n", alunos[i]->curso);
        printf("Periodo Ingresso: %s\n", alunos[i]->periodo);
        printf("%% Conclusao do Curso: %d\n", alunos[i]->conclusao);
        printf("CRA: %.2f\n", alunos[i]->cra);
    }
}
