/*
===========================================================================
Programa: JogarAluno.c
Objetivo: Responder questoes relacionadas a esportes.
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
    char nome_aluno[30];
    char esporte[20];
    int pontuacao;
    int questoes;
} Treg_jogo;
typedef FILE * Tjogo;

typedef struct
{
    char pergunta[200];
    char esporte[20];
    char opcao1[50];
    char opcao2[50];
    char opcao3[50];
    char opcao4[50];
    int  opcao_certa;
} Treg_aplicacao;

void jogar();
void pontuacao_geral();
void guardarPontuacao(Treg_jogo);
void pontuacao_por_jogador();

int main()
{
    Treg_jogo regJogador;
    char nome_aluno[30];
    int opcao;


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
    printf ("\t* Usuario (Aluno) podera responder as questoes.\n\n");
    printf ("\t* Podera ver a pontuacao geral dos jogadores.\n\n");
    printf ("\t* Podera ver a pontuacao apenas do jogador a sua escolha.\n\n");

    textcolor(10); // VERDE
    printf("\n\tPRESSIONE ENTER PARA COMECAR...");
    getchar();


    do
    {
        system ("cls");
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
        printf ("\t    |  1 - JOGAR                                           |\n\n");
        printf ("\t    |  2 - PONTUCAO GERAL                                  |\n\n");
        printf ("\t    |  3 - PONTUACAO POR JOGADOR                           |\n\n");
        printf ("\t    |  4 - VER OS DESENVOLVEDORES                          |\n\n");
        printf ("\t    |  5 - SAIR                                            |\n\n");
        printf ("\t    *------------------------------------------------------*\n\n");
        textcolor(10); // VERDE
        printf ("\t\t\n        O QUE DESEJA FAZER ? ");
        textcolor(15); // BRANCO
        scanf("%i", &opcao);

        switch (opcao)
        {
        case 1:
            jogar();
            break;

        case 2:
            pontuacao_geral();
            getch();
            break;

        case 3:
            system("cls");
            textcolor(10); // VERDE
            printf("\n\n\t\t\t\tPONTUACAO POR JOGADOR");
            textcolor(15); // BRANCO
            printf("\n\n\n\n\tDigite o Nome do Jogador: ");
            fflush(stdin);
            gets(nome_aluno);
            system("cls");

            pontuacao_por_jogador(nome_aluno);
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


void guardarPontuacao(Treg_jogo dados)
{
    Tjogo arq = fopen("DadosJogador.dat","ab");

    fwrite(&dados, sizeof(Treg_jogo), 1, arq);

    fclose(arq);
}

void jogar()
{
    Treg_jogo jogador;
    Tjogo arq = fopen("aplicacao.dat", "rb");
    Treg_aplicacao pergunta;
    int resposta;

    system("cls");
    textbackground(0); // PRETO
    textcolor(10); // VERDE
    printf("\n\n\n\t\t\t\t\t JOGO");
    textcolor(15); // BRANCO

    printf("\n\n\n\tDigite seu nome: ");
    fflush(stdin);
    gets(jogador.nome_aluno);
    printf("\n\tDigite um esporte: ");
    scanf("%s", &jogador.esporte);
    jogador.pontuacao = 0;
    jogador.questoes = 0;

    fread(&pergunta, sizeof(Treg_aplicacao), 1, arq);
    while (! feof(arq))
    {
        if (strcmp(pergunta.esporte, jogador.esporte) == 0)
        {
            textcolor(15); // BRANCO
            printf("\n\n\tEsporte: %s", pergunta.esporte);
            printf("\n\n\tPergunta: %s", pergunta.pergunta);
            printf("\n\n\tAlternativa 1: %s", pergunta.opcao1);
            printf("\n\tAlternativa 2: %s", pergunta.opcao2);
            printf("\n\tAlternativa 3: %s", pergunta.opcao3);
            printf("\n\tAlternativa 4: %s", pergunta.opcao4);
            textcolor(10); // VERDE
            printf("\n\n\tResposta: ");
            textcolor(15); // BRANCO
            scanf("%i", &resposta);
            jogador.questoes++;


            if(resposta == pergunta.opcao_certa)
            {
                jogador.pontuacao++;
                textcolor(14); // AMARELO
                printf("\n\tPARABENS, CERTA RESPOSTA !\n\n");
                textcolor(10); // VERDE
                system("pause");
                system("cls");
            }
            else
            {
                textcolor(14); // AMARELO
                printf("\n\tVoce ERROU !\n\n");
                textcolor(10); // VERDE
                system("pause");
                system("cls");
            }

        }
        fread(&pergunta, sizeof(Treg_aplicacao), 1, arq);
    }
    fclose(arq);
    guardarPontuacao(jogador);
}

void pontuacao_geral()
{
    Tjogo arq;
    Treg_jogo reg_resultado;

    system("cls");
    arq = fopen("DadosJogador.dat", "rb");
    if (arq == NULL)
    {
        printf("\n\nArquivo nao aberto !");
    }
    else
    {
        fread(&reg_resultado, sizeof(Treg_jogo), 1, arq);
        while (! feof(arq))
        {

            textcolor(10); // VERDE
            printf("\n\t\t\t\t PONTUACAO GERAL");

            textcolor(15); // BRANCO
            printf("\n\n\tNome : %s\n", reg_resultado.nome_aluno);
            printf("\n\tEsporte : %s\n", reg_resultado.esporte);
            textcolor(10); // VERDE
            printf("\n\tPontuacao :");
            textcolor(15); // BRANCO
            printf("\n\n\tAcertou ");
            textcolor(14); // AMARELO
            printf("%i", reg_resultado.pontuacao);
            textcolor(15); // BRANCO
            printf(" de um total de %i questoes !", reg_resultado.questoes);
            fread(&reg_resultado, sizeof(Treg_jogo), 1, arq);
            textcolor(10); // VERDE
            printf ("\n\n*-----------------------------------------------------------------------------*\n");
            textcolor(15); // BRANCO
        }
        fclose(arq);
    }
    getch();
}

void pontuacao_por_jogador(char nome_aluno[])
{
    Tjogo arq;
    Treg_jogo reg_resultado;
    int cont = 0;

    arq = fopen("DadosJogador.dat", "rb");
    if (arq == NULL)
    {
        printf("\n\nFalha na Abertura do Arquivo: aplicacao.dat");
    }
    else
    {
        fread(&reg_resultado, sizeof(Treg_jogo), 1, arq);
        while (! feof(arq))
        {
            if (strcmp(reg_resultado.nome_aluno, nome_aluno) == 0)
            {

                textcolor(10); // VERDE
                printf("\n\n\t\t\t\t      RESULTADO");
                textcolor(15); // BRANCO

                printf("\n\n\tNome: %s\n", reg_resultado.nome_aluno);
                printf("\n\tEsporte: %s\n", reg_resultado.esporte);
                textcolor(10); // VERDE
                printf("\n\tPontuacao: ");
                textcolor(15); // BRANCO
                printf("\n\n\tAcertou ");
                textcolor(14); // AMARELO
                printf("%i", reg_resultado.pontuacao);
                textcolor(15); // BRANCO
                printf(" de um total de %i questoes !", reg_resultado.questoes);
                textcolor(10); // VERDE
                printf ("\n\n*----------------------------------------------------------------------------*\n");
                cont = 1;
            }
            fread(&reg_resultado, sizeof(Treg_jogo), 1, arq);
        }
        if (cont == 0)
        {
          textcolor(10); // VERDE
          printf("\n\n\t\t\t\t      RESULTADO");
          textcolor(15); // BRANCO
          textcolor(10); // VERDE
          printf("\n\n\tJogador nao encontrado !");
        }
        fclose(arq);
    }
    printf("\n\n");
    system("pause");
    system("cls");
}
