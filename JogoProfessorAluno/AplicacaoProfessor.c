/*
===========================================================================
Programa: AplicacaoProfessor.c
Objetivo: Cadastrar questoes para serem aplicadas.
Desenvolvedores: Roberto de Souza Porto Júnior
                 Everton Aparecido Ferreira
===========================================================================
*/
# include <stdio.h>
# include <stdlib.h>
# include "conio.h"
# include "conio.c"

typedef struct
{
    char pergunta[200];
    char esporte[20];
    char opcao1[50];
    char opcao2[50];
    char opcao3[50];
    char opcao4[50];
    int opcao_certa;
} Treg_aplicacao;
typedef FILE * Taplicacao;

void cadastro_questoes();
void rel_por_esporte();
void rel_geral();

int main()
{
    int opcao;
    char esporte[20];

        textbackground(0); // PRETO
        textcolor(15); // BRANCO
        system ("cls");
        printf("\n\n\n");
        textcolor(10); // VERDE
        printf ("\t    *------------------------------------------------------*\n\n");
        printf ("\t    |          Seja Bem Vindo ao TEC EDU SPORTS !          |\n\n");
        printf ("\t    *------------------------------------------------------*\n\n");
        textcolor(15); // BRANCO
        printf("\n\n");
        printf ("\tEste programa foi desenvolvido pelos alunos do primeiro ano de\n\n");
        printf ("\tSistemas de Informacao - FAI, para ser apresentado na disciplina\n\n");
        printf ("\tde Tecnicas de Programacao para o professor Roberto Porto.\n\n\n");
        printf ("\t\t\t\t   Conteudo :\n\n\n");
        printf ("\t* Usuario (Professor) podera casdastrar as questoes para\n\n");
        printf ("\tserem aplicadas a seus alunos.\n\n");
        printf ("\t* Podera ver o relatorio completo das questoes.\n\n");
        printf ("\t* Podera ver o relatorio apenas do Esporte a sua escolha.\n\n");

        textcolor(10); // VERDE
        printf("\n\n\tPRESSIONE ENTER PARA COMECAR !");
        getchar();
        system ("cls");
    do
    {



        textbackground(0); // PRETO
        textcolor(15); // BRANCO
        printf("\n\n\n\n");
        textcolor(10); // VERDE
        printf("\t XXXXXX  XXXXXX  XXXXXX     XXXXXX  XXXXXXX    XX    XX \n");
        printf("\t   XX    XX      XX         XX      XX    XX   XX    XX \n");
        printf("\t   XX    XX      XX         XX      XX     XX  XX    XX \n");
        printf("\t   XX    XXXXXX  XX         XXXXXX  XX     XX  XX    XX \n");
        printf("\t   XX    XX      XX         XX      XX    XX   XX    XX \n");
        printf("\t   XX    XX      XX         XX      XX   XX    XX    XX \n");
        printf("\t   XX    XXXXXX  XXXXXX     XXXXXX  XXXXXX     XXXXXXXX \n");
        printf("\n\n");
        printf("\t\t   XXXXXX  XXXXXX   XXXXXXXX  XXXXXXX  XXXXXXXX XXXXXX \n");
        printf("\t\t   XX      XX   XX  XX    XX  XX    XX    XX    XX     \n");
        printf("\t\t   XXX     XX   XX  XX    XX  XX    XX    XX    XXX    \n");
        printf("\t\t    XXX    XXXXXXX  XX    XX  XXXXXXX     XX     XXX   \n");
        printf("\t\t      XX   XX       XX    XX  XX  XX      XX       XX  \n");
        printf("\t\t       XX  XX       XX    XX  XX   XX     XX        XX \n");
        printf("\t\t   XXXXXX  XX       XXXXXXXX  XX    XX    XX    XXXXXX \n\n");

        printf("\n\n");
        textcolor(15); // BRANCO
        printf ("\t    *------------------------------------------------------*\n\n");
        printf ("\t    |            TEC EDU SPORTS - MENU DE OPCOES           |\n\n");
        printf ("\t    *------------------------------------------------------*\n\n");
        printf ("\t    | 1 - CADASTRO DE QUESTOES                             |\n\n");
        printf ("\t    | 2 - RELATORIO GERAL                                  |\n\n");
        printf ("\t    | 3 - RELATORIO POR ESPORTE                            |\n\n");
        printf ("\t    | 4 - VER OS DESENVOLVEDORES                           |\n\n");
        printf ("\t    | 5 - SAIR                                             |\n\n");
        printf ("\t    *------------------------------------------------------*\n\n");
        textcolor(10); // VERDE
        printf ("\t\t\n            O QUE DESEJA FAZER ? ");
        textcolor(15); // BRANCO
        scanf("%i", &opcao);

        switch (opcao)
        {
        case 1:
            system("cls");
            textbackground(0); // PRETO
            textcolor(15); // BRANCO
            cadastro_questoes();
            break;

        case 2:
            system("cls");
            textcolor(10); // VERDE
            printf("\n\t\t\t  RELATORIO DE TODOS OS ESPORTES");
            textcolor(15); // BRANCO
            rel_geral();
            getch();
            system("cls");
            break;

        case 3:
            system("cls");
            textcolor(10); // VERDE
            printf("\n\t\t\t  RELATORIO POR ESPORTE");
            textcolor(15); // BRANCO
            printf("\n\n\n\tDigite o Esporte: ");
            fflush(stdin);
            gets(esporte);

            rel_por_esporte(esporte);
            break;

        case 4:
            system("cls");
            textcolor(10); // VERDE
            printf ("\n\n\n\n\n\t\t                PROGRAMADORES: \n\n");
            textcolor(15); // BRANCO
            printf ("\n\t    *----------------------------------------------------*\n\n");
            printf ("\n\t    |            Roberto de Souza Porto Junior           |\n\n");
            printf ("\n\t    |              Everton Aparecido Ferreira            |\n\n");
            printf ("\n\t    *----------------------------------------------------*\n\n");

            getchar();
            textcolor(10); // VERDE
            printf ("\n\n\t    ENTER para retornar ao menu.");
            getchar();
            system("cls");

        case 5:
            break;
        default:
            printf("\nOpcao Invalida!!!");
            getch();
        }
    }
    while (opcao != 5);

    return 0;
}

/*
================================================================================
Função Cadastro de questões
================================================================================
*/

void cadastro_questoes()
{
    char pergunta[200];
    char esporte[20];
    Taplicacao aplicacao;
    Treg_aplicacao reg_aplicacao;

    int questoes;

    aplicacao = fopen("aplicacao.dat","ab");

    textcolor(15); // BRANCO
    printf("\n\tDigite");
    textcolor(10); // VERDE
    printf("   FIM");
    textcolor(15); // BRANCO
    printf("   na opcao ");
    textcolor(10); // VERDE
    printf("( Digite o Esporte: )");
    textcolor(15); // BRANCO
    printf(" quando quiser sair.\n\n");
    printf("\n\n\tDigite o Esporte: ");
    fflush(stdin);
    gets(reg_aplicacao.esporte);
    if(strcmp(reg_aplicacao.esporte, "fim") == 0)
    {
        system("cls");
    }

    while (strcmp(reg_aplicacao.esporte, "fim") != 0)
    {
        questoes = 0;

        printf("\n\n\tDigite a pergunta: ");
        fflush(stdin);
        gets(reg_aplicacao.pergunta);

        printf("\n\n\tAlternativa 1: ");
        fflush(stdin);
        gets(reg_aplicacao.opcao1);

        printf("\n\n\tAlternativa 2: ");
        fflush(stdin);
        gets(reg_aplicacao.opcao2);

        printf("\n\n\tAlternativa 3: ");
        fflush(stdin);
        gets(reg_aplicacao.opcao3);

        printf("\n\n\tAlternativa 4: ");
        fflush(stdin);
        gets(reg_aplicacao.opcao4);

        do
        {
         printf("\n\n\tResposta Certa: ");
         fflush(stdin);
         scanf("%i", &reg_aplicacao.opcao_certa);
        }while (reg_aplicacao.opcao_certa < 1 || reg_aplicacao.opcao_certa > 4);

        questoes = questoes + 1;

        fwrite(&reg_aplicacao,sizeof(Treg_aplicacao), 1, aplicacao);

        system("cls");
        textcolor(15); // BRANCO
        printf("\n\tDigite");
        textcolor(10); // VERDE
        printf("   FIM");
        textcolor(15); // BRANCO
        printf("   na opcao ");
        textcolor(10); // VERDE
        printf("( Digite o Esporte: )");
        textcolor(15); // BRANCO
        printf(" quando quiser sair.\n\n");
        printf("\n\n\tDigite o Esporte: ");
        fflush(stdin);
        gets(reg_aplicacao.esporte);

        if(strcmp(reg_aplicacao.esporte, "fim") == 0)
    {
        system("cls");
    }
    }
    fclose(aplicacao);
}

/*
================================================================================
Função Relatório Geral:
================================================================================
*/

void rel_geral()
{
    Taplicacao aplicacao;
    Treg_aplicacao reg_aplicacao;

    aplicacao = fopen("aplicacao.dat", "rb");
    if (aplicacao == NULL)
    {
        printf("\n\nArquivo nao aberto !");
    }
    else
    {
        fread(&reg_aplicacao, sizeof(Treg_aplicacao), 1, aplicacao);
        while (! feof(aplicacao))
        {
            textcolor(10); // VERDE
            printf("\n\n\n\tESPORTE : %s\n", reg_aplicacao.esporte);
            textcolor(15); // BRANCO
            printf("\n\n\tPergunta: %s\n", reg_aplicacao.pergunta);
            printf("\n\n\tAlternativa 1: %s", reg_aplicacao.opcao1);
            printf("\n\n\tAlternativa 2: %s", reg_aplicacao.opcao2);
            printf("\n\n\tAlternativa 3: %s", reg_aplicacao.opcao3);
            printf("\n\n\tAlternativa 4: %s\n", reg_aplicacao.opcao4);
            printf("\n\tResposta Certa: %i", reg_aplicacao.opcao_certa);
            fread(&reg_aplicacao, sizeof(Treg_aplicacao), 1, aplicacao);
            textcolor(10); // VERDE
            printf ("\n\n\n*----------------------------------------------------------------------------*\n");
        }
        fclose(aplicacao);
    }
}

/*
================================================================================
Função Relatório por Esporte:
================================================================================
*/

void rel_por_esporte(char esporte[])
{
    Taplicacao aplicacao;
    Treg_aplicacao reg_aplicacao;

    aplicacao = fopen("aplicacao.dat", "rb");
    if (aplicacao == NULL)
    {
        printf("\n\nFalha na Abertura do Arquivo: aplicacao.dat");
    }
    else
    {
        fread(&reg_aplicacao, sizeof(Treg_aplicacao), 1, aplicacao);
        while (! feof(aplicacao))
        {
            if (strcmp(reg_aplicacao.esporte, esporte) == 0)
            {
                printf("\n\tESPORTE: %s\n", reg_aplicacao.esporte);
                printf("\n\tPergunta: %s\n", reg_aplicacao.pergunta);
                printf("\n\tAlternativa 1: %s", reg_aplicacao.opcao1);
                printf("\n\tAlternativa 2: %s", reg_aplicacao.opcao2);
                printf("\n\tAlternativa 3: %s", reg_aplicacao.opcao3);
                printf("\n\tAlternativa 4: %s\n", reg_aplicacao.opcao4);
                printf("\n\tAlternativa Certa: %i", reg_aplicacao.opcao_certa);
                textcolor(10); // VERDE
                printf ("\n\n*----------------------------------------------------------------------------*\n");
                textcolor(15); // BRANCO
            }
            fread(&reg_aplicacao, sizeof(Treg_aplicacao), 1, aplicacao);
        }
        fclose(aplicacao);
    }
    printf("\n\n");
    system("pause");
    system("cls");
}
