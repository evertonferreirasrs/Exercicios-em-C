#include <stdio.h>
#include <stdlib.h>

typedef struct NO * ponteiro;

struct NO
{
    char contato[30];
    int smart;
    ponteiro llink, rlink;
};

// ------------------------------------------------------------------------------------
void remover_NO(ponteiro);
void inserir_NO(ponteiro, int, char[]);

void cadastro_contatos(ponteiro);
void listagem_contatos(ponteiro);
void consulta_nome(ponteiro, char[]);
void remocao_contatos(ponteiro, char[]);

// ------------------------------------------------------------------------------------
int main()
{
    ponteiro pont, ender;
    int opcao;
    int flag = -1;
    char nome[30];
    int numero;

    pont = (ponteiro) malloc(sizeof(struct NO));
    pont->smart = flag;
    pont->rlink = pont;
    pont->llink = pont;

    do
    {
        system("cls");
        printf("1 - Permitir a insercao de novo contatos");
        printf("\n2 - Listar os dados de todos os contatos");
        printf("\n3 - Permitir a consulta de contatos por nome.(Listar todos os dados)");
        printf("\n4 - Permitir a remocao de contatos por nome");
        printf("\n5 - SAIR ");
        printf("\nO que deseja fazer? ");
        scanf("%i", &opcao);

        switch(opcao)
        {
        case 1:
            system("cls");
            cadastro_contatos(pont);
            break;

        case 2:
            system("cls");
            listagem_contatos(pont);
            getch();
            break;

        case 3:
            system("cls");
            printf("\n\nNome a ser procurado: ");
            scanf("%s", &nome);
            consulta_nome(pont, nome);
            getch();
            break;

        case 4:
            system("cls");
            printf("\n\nDigite o nome a ser removido: ");
            scanf("%s", &nome);
            remocao_contatos(pont, nome);
            getch();
            break;

        case 5:
            break;

        default:
            printf("Opcao Invalida !");
            break;
        }
    }
    while(opcao != 5);

    return 0;
}

// -----------------------------------------------------------------------------
void remover_NO(ponteiro p)
{
    p->llink->rlink = p->rlink;
    p->rlink->llink = p->llink;
    free(p);
}

// -----------------------------------------------------------------------------
void inserir_NO(ponteiro p, int numero, char nome[])
{
    ponteiro aux;
    aux = (ponteiro) malloc(sizeof(struct NO));
    aux->smart = numero;
    strcpy(aux->contato, nome);
    aux->llink = p;
    aux->rlink = p->rlink;
    p->rlink->llink = aux;
    p->rlink = aux;
}

// -----------------------------------------------------------------------------
void cadastro_contatos(ponteiro pont)
{
    char nome[30];
    int numero;


    printf("Digite o nome do contato: ");
    scanf("%s", &nome);


    while(strcmp(nome, "fim") != 0)
    {
        printf("Digite o numero: ");
        scanf("%i", &numero);

        inserir_NO(pont->llink, numero, nome);

        printf("Digite o nome do contato: ");
        scanf("%s", &nome);

    }
}

//-----------------------------------------------------------------------------------
void listagem_contatos(ponteiro pont)
{
    ponteiro aux;

    if (pont != pont->rlink)
    {
        aux = pont->rlink;
        while (aux != pont)
        {
            printf("\n%s", aux->contato);
            printf("\n%i", aux->smart);
            aux = aux->rlink;
        }
    }
    else
    {
        printf("\n\nLista Vazia!!!\n\n");
    }
    printf("\n");
}

//----------------------------------------------------------------------------------------
void consulta_nome(ponteiro pont, char nome[])
{
    ponteiro aux;

    aux = pont->rlink;

    while (aux != pont && strcmp(nome, aux->contato) != 0)
    {
        aux = aux->rlink;
    }
    if (aux == pont)
    {
        printf("Contato nao encontrado!");
    }
    else
    {
        printf("Contato: %s Numero: %i", aux->contato, aux->smart);
    }

}

//------------------------------------------------------------------------------------
void remocao_contatos(ponteiro pont, char nome[])
{
    ponteiro aux;

    aux = pont->rlink;

    while (aux != pont && strcmp(nome, aux->contato) != 0)
    {
        aux = aux->rlink;
    }
    if (aux == pont)
    {
        printf("Contato nao encontrado!");
    }
    else
    {
        remover_NO(aux);
        printf("Contato Removido!!");
    }
}



