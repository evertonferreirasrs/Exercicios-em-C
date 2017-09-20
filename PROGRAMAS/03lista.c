#include <stdio.h>

typedef struct NO * ponteiro; //Define o tipo ponteiro 
                              //(ponteiro para a estrutura NO)
                              
struct NO {                   //Estrutura (NÓ) da lista
          int info;
          ponteiro link;
          };

//Protótipos (descrição de funções)

ponteiro criar_lista(ponteiro); //retorna o ponteiro atualizado 
void listar_lista(ponteiro);       

int main()
{
 ponteiro pont = NULL;
 int opcao;

 do
 {
  system("CLS");
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
   case  1: pont = criar_lista(pont);
            break;
   case  2: 
            break;
   case  3: 
            break;
   case  4: listar_lista(pont);;  
            break;
   case  5: 
            break;
   case  6: 
            break;
   case  7: 
            break;
   case  8: 
            break;
   case  9: 
            break;
   case 10: 
            break;
   case 11: 
            break;
   case 12: 
            break;
   case 13: 
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
