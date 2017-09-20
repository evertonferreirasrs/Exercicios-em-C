/* ==================================================================== */
/* Implementação da Lista de Exercícios sobre LISTAS ENCADEADAS SIMPLES */
/* ==================================================================== */

#include <stdio.h>
#include <stdlib.h>

typedef struct NO * ponteiro;

struct NO {
          int info;
          ponteiro link;
          };

ponteiro cria_lista(ponteiro);
ponteiro consulta_lista(ponteiro, int);
int contar_nos(ponteiro);
void imprime_lista(ponteiro);       
ponteiro insere_no_final(ponteiro, int);
ponteiro insere_no_inicio(ponteiro, int);
ponteiro insere_no_meio(ponteiro, int);
void insere_no_apos_no(ponteiro, ponteiro, int);
ponteiro insero_no_ordem(ponteiro, int);

int main()
{
 ponteiro pont, pos;
 int opcao, valor, qtde_nos;
  
 pont = NULL;
 opcao = 0;
 while (opcao != 14)   
 {
  system("CLS");
  printf("\n 1 - Criar Lista");
  printf("\n 2 - Consulta Lista");
  printf("\n 3 - Contar Nos da Lista");
  printf("\n 4 - Imprimir a Lista");
  printf("\n 5 - Inserir No no Final da Lista");
  printf("\n 6 - Inserir No no Inicio da Lista");
  printf("\n 7 - Inserir No no Meio da Lista");
  printf("\n 8 - Inserir No Apos um No Conhecido");
  printf("\n 9 - Inserir No em uma Lista Ordenada");
  printf("\n10 - Remover o Primeiro No da Lista");
  printf("\n11 - Remover o Ultimo No da Lista");
  printf("\n12 - Remover o No do Meio da Lista");
  printf("\n13 - Remover o No Qualquer da Lista");
  printf("\n14 - Finalizar");
  printf("\n\nOpcao: ");
  fflush(stdin);
  scanf("%i", &opcao);
  system("CLS");
   
  switch (opcao)
  {
   case 1: pont = cria_lista(pont);
           break;
   case 2: printf("\n\nValor: ");
           scanf("%i", &valor);
           pos = consulta_lista(pont, valor);
           if (pos != NULL)
           {
            printf("\n\nEndereço: %i, Valor: %i \n\n", pos, pos->info);
           }
           else
           {
            printf("\n\nValor nao Encontrado!!!\n\n");
           }
           system("pause");  
           break;
   case 3: qtde_nos = conta_nos(pont);
           printf("\n\nQuantidade de Nos: %i\n\n", qtde_nos);
           system("pause");  
           break;
   case 4: imprime_lista(pont);
           printf("\n\n");
           system("PAUSE");
           break;
   case 5: printf("\n\nValor: ");
           scanf("%i", &valor); // Falta consistir o valor p/ que seja > que 0.
           pont = insere_no_final(pont,valor);
           break;
   case 6: printf("\n\nValor: ");
           scanf("%i", &valor); // Falta consistir o valor p/ que seja > que 0.
           pont = insere_no_inicio(pont,valor);
           break;
   case 7: printf("\n\nValor: ");
           scanf("%i", &valor); // Falta consistir o valor p/ que seja > que 0.
           pont = insere_no_meio(pont,valor);
           break;
   case 8: printf("\n\nInserir apos qual Valor : ");
           scanf("%i", &valor); 
           pos = consulta_lista(pont, valor);
           if (pos != NULL)
           {
           printf("\n\nValor a ser Inserido : ");
           scanf("%i", &valor); // Falta consistir o valor p/ que seja > que 0.                   
           insere_no_apos_no(pont, pos, valor);
           }
           else
           {
            printf("\n\nValor nao encontrado!!!");
            system("PAUSE");
           }
           break;
   case 9: printf("\n\n\nNao Implementado\n\n");
           system("pause");  
           break;
   case 10: printf("\n\n\nNao Implementado\n\n");
           system("pause");  
           break;
   case 11: printf("\n\n\nNao Implementado\n\n");
           system("pause");  
           break;
   case 12: printf("\n\n\nNao Implementado\n\n");
           system("pause");  
           break;
   case 13: printf("\n\n\nNao Implementado\n\n");
           system("pause");  
           break;
   case 14: break;
   default: printf("\n\nOpcao Invalida!!!\n\n");
            system("PAUSE");
            break;
  }
 }
 system("CLS");
  
 return 0;   
}

// CRIA LISTA ENCADEADA
//=============================================================================

ponteiro cria_lista(ponteiro pont)
{
 ponteiro aux1, aux2;
 int valor;

  printf("\nValor: ");
  scanf("%i", &valor);
  if (valor > 0)
  {
   // Cria Primeiro NÓ:
   pont = (ponteiro) malloc(sizeof(struct NO));
   pont->info = valor;
   pont->link = NULL;
 
   // Inserção de Novos NÓS:
   aux1 = pont;
   printf("\nValor: ");
   scanf("%i", &valor);
   while (valor > 0)
   {
    aux2 = (ponteiro) malloc(sizeof(struct NO));
    aux2->link = NULL;
    aux2->info = valor;
    aux1->link = aux2;
    aux1 = aux2;
    printf("\nValor: ");
    scanf("%i", &valor);  
   }
  }
 aux1 = NULL;
 aux2 = NULL;       
 
 return pont;
}

// CONSULTA A LISTA ENCADEADA
//=============================================================================

ponteiro consulta_lista(ponteiro pont, int valor)
{
 ponteiro aux;
 
 aux = pont;
 while ((aux != NULL) && (aux->info != valor))
 {
  aux = aux->link;      
 }
 
 return aux;
}

// CONTA NÓS DA LISTA ENCADEADA
//=============================================================================

int conta_nos(ponteiro pont)
{
 ponteiro aux;
 int contador = 0;
 
 aux = pont;
 while (aux != NULL)
 {
  contador++;
  aux = aux->link;
 }
 
 return contador;   
}

// IMPRIME A LISTA ENCADEADA
//=============================================================================

void imprime_lista(ponteiro pont)
{
 ponteiro lista;
 
 lista = pont;
 
 while (lista != NULL)
 {
  printf("\n%i", lista->info);
  lista = lista->link;
 }     
}

// INSERE NOVO NÓ NO FINAL DA LISTA ENCADEADA
//=============================================================================

ponteiro insere_no_final(ponteiro pont, int valor)
{
 ponteiro aux1, aux2;
 
 if (pont == NULL)
 {
  pont = (ponteiro) malloc(sizeof(struct NO));
  pont->info = valor;
  pont->link = NULL;
 }
 else
 {
  aux1 = pont;
  while (aux1->link != NULL)
  {
   aux1 = aux1->link;     
  }    
  aux2 = (ponteiro) malloc(sizeof(struct NO));
  aux2->info = valor;
  aux2->link = NULL;
  aux1->link = aux2;
  aux1 = NULL;
  aux2 = NULL;
 }
 
 return pont;        
}

// INSERE NOVO NÓ NO INICIO DA LISTA ENCADEADA
//=============================================================================

ponteiro insere_no_inicio(ponteiro pont, int valor)
{
 ponteiro aux;
 
 if (pont == NULL)
 {
  pont = (ponteiro) malloc(sizeof(struct NO));
  pont->info = valor;
  pont->link = NULL;
 }
 else
 {          
  aux = (ponteiro) malloc(sizeof(struct NO));
  aux->info = valor;
  aux->link = NULL;
  aux->link = pont;
  pont = aux;
  aux = NULL;
 }         
         
 return pont;         
}

// INSERE NOVO NÓ NO MEIO DA LISTA ENCADEADA
//=============================================================================

ponteiro insere_no_meio(ponteiro pont, int valor)
{
 ponteiro aux1, aux2;
 int qtde_nos, meio, i;
 
 if (pont == NULL)
 {
  pont = (ponteiro) malloc(sizeof(struct NO));
  pont->info = valor;
  pont->link = NULL;
 }
 else
 {          
  qtde_nos = conta_nos(pont);
  meio = (int) qtde_nos / 2;
  
  aux1 = pont;
  for (i=2; i <= meio; i++)
  {
   aux1 = aux1->link;
  }
  
  aux2 = (ponteiro) malloc(sizeof(struct NO));
  aux2->info = valor;
  aux2->link = aux1->link;
  aux1->link = aux2;

  aux1 = NULL;
  aux2 = NULL;
 }           

 return pont;         
}

// INSERE NOVO NÓ APÓS UM NÓ CONHECIDO NA LISTA ENCADEADA
//=============================================================================

void insere_no_apos_no(ponteiro pont, ponteiro no, int valor)
{
 ponteiro aux;
 
 aux = (ponteiro) malloc(sizeof(struct NO));
 aux->info = valor;
 aux->link = no->link;
 no->link = aux;    
}

// INSERE NOVO NÓ EM UMA LISTA ENCADEADA ORDENADA
//=============================================================================

ponteiro insero_no_ordem(ponteiro pont, int valor)
{
 ponteiro aux;
 
 if (pont == NULL)
 {
  pont = (ponteiro) malloc(sizeof(struct NO));
  pont->info = valor;
  pont->link = NULL;
 }
 else
 {          
  aux = pont;
  //while (aux
 
 
  aux = (ponteiro) malloc(sizeof(struct NO));
  aux->info = valor;
 }         
         
         
 return pont;         
}
