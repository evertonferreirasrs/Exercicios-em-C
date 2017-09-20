#include <stdio.h>
#define N 10
void preencherVetor(int[N]);
void serial(int[N],int);
void sequencial(int[N],int);
void binaria(int[N],int);
void direta_transformada(int[N],int);

int main()
{
    int vetor[N];
    int opcao;
    int chave;
    do
    {
        system("cls");
        printf("1.Preencher Vetor");
        printf("\n2.Busca Serial");
        printf("\n3.Busca Sequencial");
        printf("\n4.Busca Binaria");
        printf("\n5.Busca Direta transformada");
        printf("\n0.Sair");
        printf("\nEntre com a opcao: ");
        scanf("%i",&opcao);
        switch(opcao)
        {
        case 0:
            break;
        case 1:
            system("cls");
            preencherVetor(vetor);
            break;
        case 2:
            system("cls");
            printf("entre com o numero a ser pesquisado: ");
            scanf("%i",&chave);
            serial(vetor,chave);
            break;
        case 3:
            system("cls");
            printf("entre com o numero a ser pesquisado: ");
            scanf("%i",&chave);
            sequencial(vetor,chave);
            break;
        case 4:
            system("cls");
            printf("entre com o numero a ser pesquisado: ");
            scanf("%i",&chave);
            binaria(vetor,chave);

            break;
        case 5:
            system("cls");
            printf("entre com o numero a ser pesquisado: ");
            scanf("%i",&chave);
            direta_transformada(vetor,chave);
            break;
        default:
            break;
        }

    }while(opcao != 0);

    return 0;
}

void preencherVetor(int vetor[N])
{
    int i;
    for(i=0;i<N;i++)
    {
        printf("Entre com o %i valor: ",i+1);
        scanf("%i",&vetor[i]);
    }
}

void serial(int vetor[N],int chave)
{
    int i = 0;
    while(i<N && chave != vetor[i])
    {
        i++;
    }
    if(i < N)
    {
        printf("SUCESSO!");
    }
    else
    {
        printf("INSUCESSO!");
    }
    system("pause");
}

void sequencial(int vetor[N],int chave)
{
    int i = 0;
    while(i<N && chave > vetor[i])
    {
        i++;
    }
    if(i<N && chave == vetor[i])
    {
        printf("SUCESSO!");
    }
    else
    {
        printf("INSUCESSO!");
    }
    system("pause");
}

void binaria(int vetor[N],int chave)
{
    int linferior = 0,lsuperior = N-1;
    int i;
    i = (linferior+lsuperior)/2;
    while(lsuperior >= linferior && chave != vetor[i])
    {
        if(chave < vetor[i])
        {
            lsuperior = i-1;
        }
        else if(chave > vetor[i])
        {
            linferior = i + 1;
        }
        i = (linferior+lsuperior)/2;
    }
    if(lsuperior >= linferior)
    {
        printf("SUCESSO!");
    }
    else
    {
        printf("INSUCESSO!");
    }
    system("pause");
}

void direta_transformada(int vetor[N],int chave)
{
    int i;
    int kmenor,kmaior,den,cte1,cte2,end;
    kmenor = vetor[0];
    kmaior = vetor[N-1];
    den = kmaior - kmenor;
    cte1 = (kmaior - N * kmenor) / den;
    cte2 = (N-1)/den;
    end = cte1 + chave * cte2;

    if(chave != vetor[end])
    {
        if(chave < vetor[end])
        {
            while((end > 0) && (chave < vetor[end]))
            {
                end--;
            }
        }
        else
        {
            while((end > N-1) && (chave > vetor[end]))
            {
                end++;
            }
        }
    }
    if((end >= 0) && (end <= N-1) && (chave == vetor[end]))
    {
        printf("SUCESSO!");
    }
    else
    {
        printf("INSUCESSO!");
    }
    system("pause");
}
