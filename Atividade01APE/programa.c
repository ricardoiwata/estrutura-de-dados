#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME_LEN 100
#define MAX_CURSO_LEN 50
#define MAX_LINE_LEN 512

typedef struct
{
    char nome[MAX_NOME_LEN];
    char telefone[15]; // (555) 123-4567
    char curso[MAX_CURSO_LEN];
    double nota1;
    double nota2;
} Aluno;

int main()
{
    FILE *entrada = fopen("C://Users/riwat/Desktop/estrutura-de-dados/Atividade01APE/DadosEntrada.csv", "r");
    FILE *saida = fopen("C://Users/riwat/Desktop/estrutura-de-dados/Atividade01APE/output/SituacaoFinal.csv", "w");

    if (entrada == NULL || saida == NULL)
    {
        perror("Erro ao abrir arquivos");
        exit(EXIT_FAILURE);
    }

    char linha[MAX_LINE_LEN];
    fprintf(saida, "Nome,Nota Media,Situacao\n");

    if (fgets(linha, sizeof(linha), entrada) == NULL)
    {
        perror("Erro ao ler a primeira linha");
        exit(EXIT_FAILURE);
    }

    while (fgets(linha, sizeof(linha), entrada) != NULL)
    {
        Aluno aluno;
        char *token;
        double somaNotas = 0.0;

        token = strtok(linha, ",");
        strncpy(aluno.nome, token, sizeof(aluno.nome));

        token = strtok(NULL, ",");
        strncpy(aluno.telefone, token, sizeof(aluno.telefone));

        token = strtok(NULL, ",");
        strncpy(aluno.curso, token, sizeof(aluno.curso));

        token = strtok(NULL, ",");
        sscanf(token, "%lf", &aluno.nota1);
        somaNotas += aluno.nota1;

        token = strtok(NULL, ",");
        sscanf(token, "%lf", &aluno.nota2);
        somaNotas += aluno.nota2;

        double media = somaNotas / 2.0;
        const char *situacao = (media >= 7.0) ? "APROVADO" : "REPROVADO";

        fprintf(saida, "%s,%.2lf,%s\n", aluno.nome, media, situacao);
    }

    fclose(entrada);
    fclose(saida);

    return 0;
}
