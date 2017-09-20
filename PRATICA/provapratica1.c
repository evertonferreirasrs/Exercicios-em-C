#include <stdio.h>

typedef struct NO *ponteiro;

struct NO
{
    char contato[30];
    int smart;
    ponteiro link;
};

ponteiro cadastrar (ponteiro);
void listar(ponteiro);
void consultar_nome(ponteiro);


int main()
{
    ponteiro pont;
    int opcao;
    pont = NULL;

    do
    {
        system("cls");
        printf("\n 1 - Cadastrar Contato");
        printf("\n 2 - Listar Contato");
        printf("\n 3 - Consultar por Nome");
        printf("\n 4 - Remover Contato");
        printf("\n 5 - Sair");
        printf("\n Escolha uma opcao: ");
        scanf("%i", &opcao);

        switch(opcao)
        {
            case 1:
                system("cls");
                pont = cadastrar(pont);
            break;
            case 2:
                system("cls");
                listar(pont);
                getch();
            break;
            case 3:
                system("cls");
                consultar_nome(pont);
                getch();
            break;
            case 4:
                system("cls");

                getch();
            break;
            case 5:
                system("cls");
                printf("Fim do programa.");
            break;
            default:
                printf("\nOpcao Invalida\n\n");
                system("pause");
            break;
        }

    }while(opcao != 5);

    return 0;
}

ponteiro cadastrar(ponteiro pont)
{
    ponteiro aux;
    int numero, i;
    char nome[30];

    printf("Entre com o nome: ");
    scanf("%s",&nome);

    while(strcmp(nome,"fim") != 0)
    {
        printf("Entre com o Contato: ");
        scanf("%i",&numero);
        aux = pont;
        pont = (ponteiro) malloc(sizeof(struct NO));
        pont -> smart = numero;

        i = 0;
        while(nome[i] != '\0')
        {
            pont -> contato[i] = nome[i];
            i++;
        }
        pont -> contato[i] = '\0';
        pont -> link = aux;

        printf("Entre com o nome: ");
        scanf("%s",&nome);
    }

    return pont;
}

void listar(ponteiro pont)
{
    ponteiro aux;

    if(pont == NULL)
    {
        printf("\nNenhum Nome cadastrado.");
    }
    else
    {
        aux = pont;
        while(aux != NULL)
        {
            printf("\nNome: %s",aux -> contato);
            printf("\nContato: %i",aux -> smart);
            aux = aux -> link;
        }
    }
}

void consultar_nome(ponteiro pont)
{
    ponteiro aux;

    char nome[30];

    printf("Entre com o nome: ");
    scanf("%s",&nome);

    if(pont == NULL)
    {
        printf("\nNenhum Nome cadastrado.");
    }
    else
    {
        while(strcmp(nome, aux -> contato) == 0)
        {
            printf("\nNome: %s",aux -> contato);
            printf("\nContato: %i",aux -> smart);
        }
    }
}
