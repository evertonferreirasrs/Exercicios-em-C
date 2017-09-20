#include <stdio.h>
#include <stdlib.h>
#define N 10

//-----------------------------------------------
void BUSCA_SERIAL(int[], int);
void BUSCA_SEQUENCIAL(int[], int);
void BUSCA_BINARIA(int[], int);
void BUSCA_DIRETA_TRANSFORMADA(int[], int);

//-----------------------------------------------
int main()
{
    int valor;
    int opcao;
    int I;
    int VETOR[N];
    int CHAVE;

    for(I = 0; I < N; I++)
    {
        VETOR[I] = I + 1;
    }

    do
    {
        system("cls");
        printf("\n=============================");
        printf("\n1 - Busca Serial");
        printf("\n2 - Busca Sequencial");
        printf("\n3 - Busca Binaria");
        printf("\n4 - Busca Direta Transformada");
        printf("\n5 - Sair");
        printf("\n==============================");
        printf("\n\nOpcao: ");
        scanf("%i",&opcao);

        switch (opcao)
        {
        case 1:
            system("cls");
            printf("Entre com o numero a ser procurado: ");
            scanf("%i", &CHAVE);
            BUSCA_SERIAL(VETOR, CHAVE);
            printf("\n\n");
            system("pause");
            break;

        case 2:
            system("cls");
            printf("Entre com o numero a ser procurado: ");
            scanf("%i", &CHAVE);
            BUSCA_SEQUENCIAL(VETOR, CHAVE);
            printf("\n\n");
            system("pause");
            break;

        case 3:
            system("cls");
            printf("Entre com o numero a ser procurado: ");
            scanf("%i", &CHAVE);
            BUSCA_BINARIA(VETOR, CHAVE);
            printf("\n\n");
            system("pause");
            break;

        case 4:
            system("cls");
            printf("Entre com o numero a ser procurado: ");
            scanf("%i", &CHAVE);
            BUSCA_DIRETA_TRANSFORMADA(VETOR, CHAVE);
            printf("\n\n");
            system("pause");
            break;

        case 5:
            printf("Obrigado!!");
            break;

        default:
            printf("Opcao Invalida!!");
            getch();
            break;
        }
    }
    while (opcao != 5);

    return 0;
}
//-------------------------------------------
void BUSCA_SERIAL(int VETOR[N], int CHAVE)
{
    int I = 0;

    while ((I < N) && (CHAVE != VETOR[I]))
    {
        I = I + 1;
    }
    if (I < N)
    {
        printf("SUCESSO");
    }
    else
    {
        printf("INSUCESSO");
    }
}

//-------------------------------------------
void BUSCA_SEQUENCIAL(int VETOR[], int CHAVE)
{
    int I = 0;

    while ((I < N) && (CHAVE > VETOR[I]))
    {
        I = I + 1;
    }

    if ((I < N) && (CHAVE = VETOR[I]))
    {
        printf("SUCESSO");
    }
    else
    {
        printf("INSUCESSO");
    }
}

//-------------------------------------------
void BUSCA_BINARIA(int VETOR[], int CHAVE)
{
    int LINF = 1;
    int LSUP = N;
    int I = 0;
    I = (LINF + LSUP) / 2;

    while ((LSUP >= LINF) && (CHAVE != VETOR[I]))
    {
        if (CHAVE < VETOR[I])
        {
            LSUP = I - 1;
        }
        else
        {
            if (CHAVE > VETOR[I])
            {
                LINF = I + 1;
            }
        }
        I = (LINF + LSUP) / 2;
    }
    if (LSUP >= LINF)
    {
        printf("SUCESSO");
    }
    else
    {
        printf("INSUCESSO");
    }
}

//-------------------------------------------
void BUSCA_DIRETA_TRANSFORMADA(int VETOR[], int CHAVE)
{
    int KMENOR = VETOR[1];
    int KMAIOR = VETOR[N];
    int DEN = KMAIOR - KMENOR;
    int CTE1 = (KMAIOR - N * KMENOR) / DEN;
    int CTE2 = (N - 1) / DEN;

    int END = CTE1 + CHAVE * CTE2;
    if (CHAVE != VETOR[END])
    {
        if (CHAVE < VETOR[END])
        {
            while ((END > 1) && (CHAVE < VETOR[END]))
            {
                END = END - 1;
            }
        }
        else
        {
            while ((END < N) && (CHAVE > VETOR[END]))
            {
                END = END + 1;
            }
        }
    }

    if ((END >= 1) && (END <= N) && (CHAVE = VETOR[END]))
    {
        printf("SUCESSO");
    }
    else
    {
        printf("INSUCESSO");
    }
}
