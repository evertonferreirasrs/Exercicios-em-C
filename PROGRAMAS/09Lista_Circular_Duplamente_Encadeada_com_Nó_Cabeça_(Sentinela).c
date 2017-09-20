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
        printf("1 - Cadastro de Contatos"); // JÁ COLOCAR EM ORDEM ALFABETICA
        printf("\n2 - Listagem de Contatos em ordem crescente");
        printf("\n3 - Listagem de Contatos em ordem decrescente)");
        printf("\n4 - Consulta por nome");
        printf("\n5 - Remoção de Contatos");
        printf("\n6 - SAIR ");
        printf("\nO que deseja fazer? ");
        scanf("%i", &opcao);

        switch(opcao)
        {
        case 1:
            system("cls");
            cadastro_contatos(pont);
            break;

        case 2:

            break;

        case 3:

            break;

        case 4:
            system("cls");
            printf("\n\nNome a ser procurado: ");
            scanf("%s", &nome);
            consulta_nome(pont, nome);
            getch();
            break;

        case 5:
            system("cls");
            printf("\n\nDigite o nome a ser removido: ");
            scanf("%s", &nome);
            remocao_contatos(pont, nome);
            getch();
            break;

        case 6:
            break;

        default:
            printf("Opcao Invalida !");
            break;
        }
    }
    while(opcao != 6);

    return 0;
}

//-----------------------------------------------------
void remover_NO(ponteiro p)
{
    p->llink->rlink = p->rlink;
    p->rlink->llink = p->llink;
    free(p);
}
// -----------------------------------------------------------------------------
void inserir_NO(ponteiro p, int numero, char nome[])
{
    char nome1[30];
    ponteiro aux;
    aux = (ponteiro) malloc(sizeof(struct NO));
    aux->smart = numero;
    strcpy(aux->contato, nome);
    aux->llink = p;
    aux->rlink = p->rlink;
    p->rlink->llink = aux;
    p->rlink = aux;
}

//1----------------------------------------------------
void cadastro_contatos(ponteiro pont)
{
    ponteiro aux;
    aux = pont->rlink;

    char nome[30], nome1[30];
    int numero;


    printf("Digite o nome do contato: ");
    scanf("%s", &nome);

    nome1[30] = nome[30];

    while(strcmp(nome, "fim") != 0)
    {
        printf("Digite o numero: ");
        scanf("%i", &numero);

        while ((aux -> rlink != pont) && (strcmp (nome1[30], nome[30]) = -1))
        {
            aux = aux->rlink;
        }



        inserir_NO(pont->llink, numero, nome);

        printf("Digite o nome do contato: ");
        scanf("%s", &nome);

    }
}

//4---------------------------------------------------------------------
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

//5-----------------------------------------------------------------------
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
