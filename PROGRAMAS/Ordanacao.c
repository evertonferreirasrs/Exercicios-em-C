#include <stdio.h>
#include <stdlib.h>
#define N 100
//-----------------------------------------------
void CRIAR_VETOR (int []);
void SELEC_DIRETA (int []);
void INS_DIRETA (int []);
void SHELL_SORT (int []);
void BOLHA (int []);
void QUICK_SORT (int [], int, int);
void MERGE (int [], int, int [], int [], int);
//-----------------------------------------------
int main()
{
    int opcao;
    int VET[N];

    do
    {
        system("cls");
        printf("\n=============================");
        printf("\n1 - Criar Vetor");
        printf("\n2 - Seleção Direta");
        printf("\n3 - Inserção Direta");
        printf("\n4 - Shell Sort");
        printf("\n5 - Buble Sort");
        printf("\n6 - Quick Sort");
        printf("\n7 - Listar Vetor");
        printf("\n8 - SAIR");
        printf("\n==============================");
        printf("\n\nOpcao: ");
        scanf("%i",&opcao);

        switch (opcao)
        {
        case 1:
            system("cls");
            CRIAR_VETOR (VET);
            break;

        case 2:
            system("cls");

            break;

        case 3:
            system("cls");

            break;

        case 4:
            system("cls");

            break;
        case 5:
            system("cls");

            break;
        case 6:
            system("cls");

            break;
        case 7:
            system("cls");

            break;

        case 8:
            printf("Obrigado!!");
            break;

        default:
            printf("Opcao Invalida!!");
            getch();
            break;
        }
    }
    while (opcao != 8);

    return 0;
}
//--------------------------------------------------------
void CRIAR_VETOR (int VET[N])
{
    int I;
    srand(time(NULL));

    for (I = 0; I < N; I++)
    {
        VET[I] = rand() % 1000;
    }
}
//--------------------------------------------------------
void SELEC_DIRETA (int VET[N])
{
    int I, J, MENOR, AUX;

    for ( I = 1; I (N - l); I++)
    {
        MENOR = I;
        for (J = (I + 1); J < N; J++)
        {
            if (VET [J] < VET [MENOR])
            {
                MENOR = J
            }
        }

        AUX = VET [I];
        VET [I] = VET [MENOR];
        VET [MENOR] = AUX;
    }

}
//--------------------------------------------------------
void INS_DIRETA (int VET[N])
{
    int I, X, K, J;

    for (I = 2; I < N; I++)
    {
        X = VET[ I ];
        K = 1;
        J = I – 1;
        while ((J >= 1) && (K = 1))
        {
            if (X < VET[J]);
            {
                VET[J + 1] = VET[J];
                J = J – 1;
            }
            else
                K = J + 1;
        }
        VET[K] = X;
    }
}
//--------------------------------------------------------
void SHELL_SORT (int VET[N],)
{
    int I, K;
    bool CHAVE;

    I = N DIV 2;
    while ( I != 0 )
    {
        do
        {
            CHAVE = true;
            for (K = 1; k <  (N - I); k++)
            {
                if (VET [K] > VET [K + I])
                {
                    AUX = VET [K];
                    VET [K] = VET [K+I];
                    VET [K + I] = AUX;
                    CHAVE = false;
                }
            }
        }
        while (CHAVE != true);
        I = I DIV 2;
    }
}
//---------------------------------------------------------
void BOLHA (int VET[N])
{
    int I, AUX;
    bool CHAVE;

    do
    {
        CHAVE = true;
        for ( I =1; I < ( N – 1 ); I++)
        {
            if (VET [I] > VET [I + l])
            {
                AUX = VET[I];
                VET [I] = VET [I + 1];
                VET [I + 1] = AUX;
                CHAVE = false;
            }
        }
    }
    while (CHAVE != true);
}
//-----------------------------------------------------------
void QUICK_SORT (int VET[N}, int INICIO, int FIM)
{
    int I, J, MEIO;

    I = INICIO;
    J = FIM;
    MEIO = VET[(INICIO + FIM) DIV 2];
    do
    {
        while (VET[I] < MEIO)
        {
            I = I + 1;
        }
        while (VET[J] > MEIO)
        {
            J = J - 1;
        }
        if (I <= J)
        {
            AUX = VET[I];
            VET[I] = VET[J];
            VET [J] = AUX;
            I = I + 1;
            J = J - 1;
        }
    }
    while (I > J);
    if (INICIO < J)
    {
        QUICK_SORT (INICIO, J);
    }
    if (I < FIM)
    {
        QUICK_SQRT (I, FIM);
    }
}
//---------------------------------------------------
void MERGE (inr VET1[N], int M, int VET2[N], int VET3 [N], int K)
{
    int I1, I2, I3, K;
    bool CHAVE;

    I1 = 1;
    I2 = 1;
    K = M + N;
    for (I3 = 1; I3 < K; I++)
    {
        CHAVE = true;
        if (I1 > M)
        {
            CHAVE = false;
        }
        else if (I2 <= N)
        {
            if (VET1[I1] > VET2[I2])
            {
                CHAVE = false;
            }
        }
        if (CHAVE)
        {
            VET3 [I3] = VET1 [I1];
            I1 = I1 + 1;
        }
        else
        {
            VET3 [I3] = VET2 [I2];
            I2 = I2 + 1;
        }
    }
}
