#include <stdio.h>
#include <stdlib.h>

typedef struct NO * ponteiro; //Define o tipo ponteiro
                              //(ponteiro para a estrutura NO)

struct NO {                   //Estrutura (NÓ) da lista
          int info;
          ponteiro link;
          };

//Protótipos (descrição de funções)

ponteiro criar_lista(ponteiro); //retorna o ponteiro atualizado
void listar_lista(ponteiro); // 4
ponteiro consultar_lista(ponteiro, int); // 2
int contar_no(ponteiro); // 3
ponteiro inserir_no_final(ponteiro, int); // 5
ponteiro inserir_no_inicio(ponteiro, int); // 6
ponteiro inserir_no_meio(ponteiro, int); // 7
void inserir_no_apos_no_conhecido(ponteiro, ponteiro , int); // 8
ponteiro inserir_no_ordenado(ponteiro, int); // 9
ponteiro remover_primeiro_no(ponteiro); // 10
ponteiro remover_ultimo_no(ponteiro); // 11
ponteiro remover_meio_no(ponteiro); // 12
ponteiro remover_escolher_no(ponteiro, int); // 13
ponteiro remover_todos(ponteiro); // 0 BONUS

int main()
{
 ponteiro resultado;
 ponteiro pont = NULL;
 int valor;
 int opcao;

 do
 {
  system("CLS");
  printf("\n =============================================================");
  printf("\nO (0) eh o especial desenvolvido por Marcelo e Roberto JR");
  printf("\n =============================================================");
  printf("\n 0 - Apagar todos NOs");
  printf("\n 1 - Criar Lista");
  printf("\n 2 - Consultar Lista");
  printf("\n 3 - Contar NOs da Lista");
  printf("\n 4 - Listar a Lista");
  printf("\n 5 - Inserir NO no Final da Lista");
  printf("\n 6 - Inserir NO no Inicio da Lista");
  printf("\n 7 - Inserir NO no Meio da Lista");
  printf("\n 8 - Inserir NO Apos um NO Conhecido");
  printf("\n 9 - Inserir NO em uma Lista Ordenada");
  printf("\n10 - Remover o Primeiro NO da Lista");
  printf("\n11 - Remover o Ultimo NO da Lista");
  printf("\n12 - Remover o NO do Meio da Lista");
  printf("\n13 - Remover um NO Qualquer da Lista");
  printf("\n14 - Finalizar");
  printf("\n\nOpcao: ");
  scanf("%i", &opcao);

  switch (opcao)
  {
   
   case  0: pont = remover_todos(pont);
   			break;
   
   case  1: pont = criar_lista(pont);
            break;
   
   case  2: do
            {
            printf("Digite o valor: ");
            scanf("%i", &valor);
            }while(valor == 0);

            resultado = consultar_lista(pont, valor);

            if(resultado != NULL)
            {
                printf("O endereco encontrado eh: %p", resultado);
            }
            else
            {
                printf("Endereco nao encontrado");
            }
            getch();

            break;

   case  3: valor = contar_no(pont);
            printf("Quantidade de NOs eh: %i", valor);
            getch();

            break;

   case  4: listar_lista(pont);
            break;

   case  5: do
            {
            printf("Digite o valor a ser inserido: ");
            scanf("%i", &valor);
            }while(valor == 0);

            pont = inserir_no_final(pont, valor);

            break;

   case  6: do
            {
            printf("Digite o valor a ser inserido: ");
            scanf("%i", &valor);
            }while(valor == 0);

            pont = inserir_no_inicio(pont, valor);
            break;

   case  7: do
            {
            printf("Digite o valor a ser inserido: ");
            scanf("%i", &valor);
            }while(valor == 0);

            pont = inserir_no_meio(pont, valor);
            break;

   case  8: do
            {
            printf("Entre com o valor do NO conhecido: ");
            scanf("%i", &valor);
            }while(valor == 0);
            resultado = consultar_lista(pont, valor);
            if (resultado == NULL)
            {
                printf("O NO nao existe !");
            }
            else
            {
            do
            {
            printf("Digite o valor a ser inserido: ");
            scanf("%i", &valor);
            }while(valor == 0);

            inserir_no_apos_no_conhecido(pont, resultado, valor);

            }

            break;

   case  9: do
            {
            printf("Digite o valor a ser inserido: ");
            scanf("%i", &valor);
            }while(valor == 0);

            pont = inserir_no_ordenado(pont, valor);
            break;
   
   case 10: pont = remover_primeiro_no(pont);
            break;
   
   case 11: pont = remover_ultimo_no(pont);
            break;
   
   case 12: pont = remover_meio_no(pont);
            break;
   
   case 13: do
            {
            printf("Digite o valor a ser excluido: ");
            scanf("%i", &valor);
            }while(valor == 0);
            
            pont = remover_escolher_no(pont,valor);
            
			break;
   
   case 14: break;
   
   default: printf("\n\nOpcao Invalida!!!\n\n");
            system("PAUSE");
            break;
  }
 }while (opcao != 14);
 system("CLS");

 return 0;
}

// 0 BONUS =============================================================
ponteiro remover_todos(ponteiro pont)
{
	ponteiro aux;
	
	if(pont == NULL)
	{
		printf("Esta vazia !");
		getch();
	}
	else
	{
		aux = pont;
		while(aux != NULL)
		{
			aux = aux->link;
			free(pont);
			pont = aux;
		}
	}
	
	return pont;
}

// 1 ===================================================================
ponteiro criar_lista(ponteiro pont)
{
 ponteiro aux;
 int valor;

 printf("\n\n");
 printf("Entre com o Valor: ");
 scanf("%i", &valor);
 while (valor > 0)
 {
  aux = (ponteiro) malloc(sizeof(struct NO));
  aux->info = valor;
  aux->link = pont;
  pont = aux;

  printf("\nEntre com o Valor: ");
  scanf("%i", &valor);
 }
 aux = NULL;

 return pont;
}

// 2 ===========================================================================
ponteiro consultar_lista(ponteiro pont, int valor)
{
ponteiro aux;
aux = pont;

if(pont != NULL)
{
    while((aux != NULL) && (valor != aux->info))
    aux = aux->link;
}
else
{
    printf("Lista esta vazia !");
    aux = NULL;
}
    return aux;
}

// 3 ==========================================================================
int contar_no(ponteiro pont)
{
ponteiro aux;
aux = pont;
int cont = 0;

while(aux != NULL)
{
    aux = aux->link;
    cont++;
}
return cont;
}

// 4 ==========================================================================
void listar_lista(ponteiro pont)
{
 ponteiro aux;

 aux = pont;

 if (aux == NULL)
 {
  printf("\n\nA Lista esta Vazia!!!\n\n");
 }
 else
 {
  while (aux != NULL)
  {
   printf("\n%i", aux->info);
   aux = aux->link;
  }
 }
 getch();
}

// 5 ====================================================================
ponteiro inserir_no_final(ponteiro pont, int valor)
{
ponteiro aux;
aux = pont;

if(aux == NULL)
{
    pont = (ponteiro) malloc(sizeof(struct NO));
    pont->info = valor;
    pont->link = NULL;
}
else
{
    while(aux->link != NULL)
    {
        aux = aux->link;
    }
    aux->link = (ponteiro) malloc(sizeof(struct NO));

    aux->link->info = valor;
    aux->link->link = NULL;
}
    return pont;
}

// 6 ===============================================================
ponteiro inserir_no_inicio(ponteiro pont, int valor)
{
ponteiro aux;
aux = pont;

if(pont == NULL)
{
    pont = (ponteiro) malloc(sizeof(struct NO));
    pont->info = valor;
    pont->link = NULL;
}
else
{
    aux = (ponteiro) malloc(sizeof(struct NO));
    aux->info = valor;
    aux->link = pont;
    pont = aux;
}
return pont;
}

// 7 ==================================================================
ponteiro inserir_no_meio(ponteiro pont, int valor)
{
ponteiro novo;
ponteiro aux;
aux = pont;
int qtd;
int i;

if(pont == NULL)
{
    pont = (ponteiro) malloc(sizeof(struct NO));
    pont->info = valor;
    pont->link = NULL;
}
else
{
    qtd = contar_no(pont);
    qtd = qtd / 2;
    novo = (ponteiro) malloc(sizeof(struct NO));
    novo->info = valor;
    i = 1;
    while(i < qtd)
    {
        aux = aux->link;
        i++;
    }
    novo->link = aux->link;
    aux->link = novo;
}
    return pont;
}

// 8 ========================================================================
void inserir_no_apos_no_conhecido(ponteiro pont, ponteiro aux, int valor)
{
ponteiro novo;

novo = (ponteiro) malloc(sizeof(struct NO));
novo->info = valor;
novo->link = aux->link;
aux->link = novo;

}

// 9 ========================================================================
ponteiro inserir_no_ordenado(ponteiro pont, int valor)
{
ponteiro aux;
ponteiro novo;

if (pont == NULL)
{
    pont = (ponteiro) malloc(sizeof(struct NO));
    pont->info = valor;
    pont->link = NULL;
}
else
{
    if (valor < pont->info)
    {
       aux = (ponteiro) malloc(sizeof(struct NO));
       aux->info = valor;
       aux->link = pont;
       pont = aux;
    }
    else
    {
        aux = pont;
        while((aux->link != NULL) && (valor > aux->link->info))
        {
            aux = aux->link;
        }
        novo = (ponteiro) malloc(sizeof(struct NO));
        novo->info = valor;
        novo->link = aux->link;
        aux->link = novo;
    }
}
    return pont;
}

// 10 ==========================================================================================
ponteiro remover_primeiro_no(ponteiro pont)
{
	ponteiro aux;
	
	if(pont == NULL)
	{
		printf("A lista esta vazia !");
		getch();
	}
	else
	{
		aux = pont;
		pont = pont->link;
		free(aux);
	}
	
	return pont;
}

// 11 ==========================================================================================
ponteiro remover_ultimo_no(ponteiro pont)
{
	ponteiro aux;
	
	if(pont == NULL)
	{
		printf("Lista esta vazia !");
	}
	else
	{
		if(pont->link == NULL)
		{
			free(pont);
			pont = NULL;
		}
		else
		{
			aux = pont;
			while(aux->link->link != NULL)
			{
				aux = aux->link;
			}
			free(aux->link);
			aux->link = NULL;
		}
	}
	
	return pont;
}

// 12 ==========================================================================================
ponteiro remover_meio_no(ponteiro pont)
{
	ponteiro aux;
	ponteiro novo;
	int qtd;
	int i;
	
	if(pont == NULL)
	{
		printf("Lista esta vazia !");	
	}
	else
	{
		if(pont->link == NULL)
		{
			free(pont->link);
			pont = NULL;
		}
		else
		{
			qtd = contar_no(pont);
			qtd = qtd / 2;
			aux = pont;
			i = 1;
			while((aux->link->link != NULL) && (i < qtd))
			{
				i++;
				aux = aux->link;
				novo = aux->link;
				aux->link = novo->link;
				free(novo);
			}
		}
	}	
	
	return pont;
}

// 13 ==========================================================================================
ponteiro remover_escolher_no(ponteiro pont, int valor)
{
	
	ponteiro aux;
	ponteiro novo;
	
	if(pont == NULL)
	{
		printf("A lista esta vazia !");
		getch();
	}
	else
	{
		if(pont->link == NULL)
		{
			if(pont->info == valor)
			{
				free(pont);
				pont = NULL;
			}
			else
			{
				printf("O valor nao foi encontrado !");
				getch();
			}
		}
		else
		{
			aux = pont;
			if(pont->info == valor)
			{
				pont = pont->link;
				free(aux);
			}
			else
			{
				while((aux->link != NULL) && (valor != aux->link->info))
				{
					aux = aux->link;
				}
				if(aux->link == NULL)
				{
					printf("O valor nao foi encontrado !");
					getch();
				}
				else
				{
					novo = aux->link;
					aux->link = novo->link;
					free(novo);
				}
			}
		}
	}
	
	return pont;
}
