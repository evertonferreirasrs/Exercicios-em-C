#include <stdio.h>
#include <stdlib.h>

typedef struct NO * ponteiro;

struct NO
{
    char contato[30];
    int smart;
    ponteiro Rlink, Llink;
};

// ------------------------------------------------------------------------------------
ponteiro cadastro_contatos(ponteiro);
void listagem_contatos(ponteiro);
void consulta_nome(ponteiro);
ponteiro remocao_contatos(ponteiro);

// ------------------------------------------------------------------------------------
int main()
{
    ponteiro pont;
    int opcao;

    pont = NULL;

    do
    {
      system("cls");
      printf("1 - Cadastrar novo contatos");
      printf("\n2 - Listar contatos");
      printf("\n3 - Consultar contatos por nome.(Listar todos os dados)");
      printf("\n4 - Remover contatos por nome");
      printf("\nO que deseja fazer? ");
      scanf("%i", &opcao);

      switch(opcao)
      {
        case 1:system("cls");
            pont = cadastro_contatos(pont);
            break;

        case 2:system("cls");
            listagem_contatos(pont);
            getch();
            break;

        case 3:system("cls");
            consulta_nome(pont);
            getch();
            break;

        case 4:system("cls");
            pont = remocao_contatos(pont);
            getch();
            break;

        default: printf("Opcao Invalida !");
             break;
      }
    }while(opcao != 5);

return 0;
}

// -----------------------------------------------------------------------------
ponteiro cadastro_contatos(ponteiro pont)
{
    char nome[30];
    int numero;
    ponteiro aux;
    int i;

    printf("Digite o nome do contato: ");
    scanf("%s", &nome);


    while(strcmp(nome, "fim") != 0)
    {
        printf("Digite o numero: ");
    	scanf("%i", &numero);

		aux = pont;
		pont = (ponteiro) malloc(sizeof(struct NO));
        pont->smart = numero;

        i = 0;
        while(nome[i] != '\0')
        {
            pont->contato[i] = nome[i];
            i++;
        }
        pont->contato[i] = '\0';
        pont->link = aux;

        printf("Digite o nome do contato: ");
        scanf("%s", &nome);

    }

    return pont;
}

//-----------------------------------------------------------------------------------
void listagem_contatos(ponteiro pont)
{
    ponteiro aux;

    if(pont == NULL)
    {
        printf("Nao há contatos !");
    }
    else
    {
        aux = pont;
        while(aux != NULL)
        {
            printf("Contato: %s Numero: %i", aux->contato, aux->smart);
            aux = aux->link;
        }
    }
}

//----------------------------------------------------------------------------------------
void consulta_nome(ponteiro pont)
{
    ponteiro aux;
    char nome[30];

    if(pont == NULL)
    {
        printf("Nao há contatos !");
    }
    else
    {
        printf("Entre com o nome a ser PROCURADO: ");
        scanf("%s", &nome);

        aux = pont;
        while(aux != NULL && strcmp(nome , aux->contato)!= 0 )
    	{
            aux = aux->link;
        }
        if(aux == NULL)
        {
        	printf("Contato nao encontrado");
		}
		else
		{
			printf("Contato: %s Numero: %i", aux->contato, aux->smart);
		}

    }
}

//------------------------------------------------------------------------------------
ponteiro remocao_contatos(ponteiro pont)
{
    ponteiro aux,apagar;
    char nome[30];
	printf("Entre com o nome a ser DELETADO: ");
    scanf("%s", &nome);
    if(pont == NULL)
    {
        printf("Nao há contatos !");
    }
    else if(strcmp(pont -> contato,nome) == 0)
    {
    	aux = pont;
		pont = pont -> link;
		free(aux);
		printf("Contato apagado");
	}else
	{

        aux = pont;
        while(aux -> link != NULL && strcmp(aux -> link -> contato , nome) != 0)
        {
            aux = aux -> link;
        }
        if(aux -> link == NULL)
        {
        	printf("Contato nao encontrado.");
    	}
    	else
    	{
    		apagar = aux -> link;
    		aux = apagar -> link;
    		free(apagar);
    		printf("Contato apagado");
    	}
    }
    return pont;
}



