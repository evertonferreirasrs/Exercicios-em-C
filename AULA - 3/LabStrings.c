#include <stdio.h>
#define N 30

void LerString(char[]);
int Obtertamanho(char[]);
int ObterLocalizacao(char[], char[]);
void ObterSubcadeia(char[], int, int);

int main()
{
    char cadeia[N], subCadeia[N], string[N];
    int i, opcao, posicao_inicial, comprimento, posicao_subcadeia;

    do
    {
        system("cls");
        printf("\n\n1 - Ler String.");
        printf("\n\n2 - Obter tamanho.");
        printf("\n\n3 - Obter Localizacao.");
        printf("\n\n4 - Obter Subcadeia.");
        printf("\n\n5 - Sair.");
        printf("\n\nOpcao: ");
        scanf("%i", &opcao);

        switch(opcao)
        {
        case 1: printf("Digite uma String: ");
                scanf("%s", &string);
                LerString(string);
                getch();
                break;
        case 2:
            printf("Digite a string: ");
            scanf("%s", &string);
            //Obtertamanho(string);

            printf("O tamanho desta string e de %i caracteres.", Obtertamanho(string));
            getch();
            break;

        case 3:
            printf("Digite a cadeia: ");
            scanf("%s", &cadeia);
            printf("Digite a Subcadeia: ");
            scanf("%s", &subCadeia);
            posicao_subcadeia = ObterLocalizacao(cadeia,subCadeia);
            printf("Subcadeia encontrada na posicao %i", posicao_subcadeia+1);
            getch();
            break;

        case 4:
            printf("Digite a cadeia: ");
            scanf("%s", &cadeia);
            printf("Digite a posicao inicial: ");
            scanf("%i", &posicao_inicial);
            printf("Digite o comprimento da subCadeia: ");
            scanf("%i", &comprimento);
            ObterSubcadeia(cadeia, posicao_inicial, comprimento);
            getch();
            break;

        default:
            break;
        }

    }
    while(opcao != 5);

    return 0;
}

void LerString(char string[])
{

}
int Obtertamanho(char string[])
{
    int i=0;

    while(string[i] != '\0')
    {
        i++;
    }
    return i;

}

int ObterLocalizacao(char cadeia[], char subCadeia[])
{
    int i, j , inicio, tamc, tams, achou, local;

    achou = 0;

    tamc = Obtertamanho(cadeia);
    tams = Obtertamanho(subCadeia);

    /*printf("TAMC: %i", tamc);
    printf("\nTAMS: %i", tams);
    getch();*/
    if(tamc >= tams)
    {
        inicio = 0;
        while((tamc >= tams) && (achou == 0))
        {
            i = 0;
            j = inicio;
            if(subCadeia[i] == cadeia[j])
            {
                local = j;
                i = i + 1;
                j = j + 1;
                while((i < tams) && (subCadeia[i] == cadeia[j]))
                {
                    i = i + 1;
                    j = j + 1;
                }
                if(i < tams)
                {
                    inicio = inicio + 1;
                    tamc = tamc - 1;
                }
                else
                {
                    achou = 1;
                }
            }
            else
            {
                inicio = inicio + 1;
                tamc = tamc - 1;
            }
        }
    }
    else
    {
        printf("A subcadeia  tem tamanho maior que a cadeia!");
    }
    /*printf("Local = %", local);
    getch();*/
    if(achou == 0)
    {
        local = -1;
    }

    return(local);
}

void ObterSubcadeia(char cadeia[], int posicao_inicial, int comprimento)
{
    int i, x=0;
    char cadeia_interna[N];

    posicao_inicial = posicao_inicial-1;
    for(i=0; i<comprimento; i++)
    {
        cadeia_interna[i] = cadeia[posicao_inicial];
        posicao_inicial++;
    }
    cadeia_interna[i+1] = '\0';
    printf("SubCadeia: %s", cadeia_interna);
}
