#include <stdio.h>

typedef struct NO * ponteiro;

struct NO
{
 ponteiro llink; 
 int info;
 ponteiro rlink;
};

void insere_no(ponteiro, int);
void remove_no(ponteiro);
void cria_dupla(ponteiro);
ponteiro consulta_dupla(ponteiro, int);
int conta_no_dupla(ponteiro);
void lista_dupla(ponteiro);

int main()
{
 int opcao, info, cont;
 ponteiro pont, ender;
 
 //Cria Nó Cabeça.
 pont = (ponteiro) malloc(sizeof(struct NO));
 pont->info = -1;
 pont->llink = pont;
 pont->rlink = pont;
 
    
 opcao = 0;
 while (opcao != 6)
 {
  system("CLS");
  printf("\n 1 - Criar Lista");
  printf("\n 2 - Consultar");
  printf("\n 3 - Contar Nos");
  printf("\n 4 - Listar Nos");  
  printf("\n 5 - Remove No");
  printf("\n 6 - Finalizar");
  printf("\n\nOpcao: ");
  fflush(stdin);
  scanf("%i", &opcao);
 
  switch (opcao)
  {
   case 1: cria_dupla(pont);
           break;
   case 2: printf("\n\nInformacao: ");
           scanf("%i", &info);
           ender = consulta_dupla(pont, info);
           if (ender != NULL)
           {
            printf("\n\nInformacao Encontrada!!!\n\n");
           }
           else
           {
            printf("\n\nInformacao Nao Encontrada!!!\n\n");    
           }
           system("pause");
           break;
   case 3: cont = conta_no_dupla(pont);
           printf("\n\nQuantidade de Nos: %i\n\n", cont);
           system("pause");
           break;
   case 4: lista_dupla(pont);
           system("PAUSE");
           break;           
   case 5: printf("\n\nInformacao: ");
           scanf("%i", &info);
           ender = consulta_dupla(pont, info);
           if (ender != NULL)
           {
            remove_no(ender);
           }
           else
           {
            printf("\n\nInformacao Nao Encontrada!!!\n\n");    
            system("PAUSE");
           }        
           break;           
   case 6: break;
   default: printf("\n\nOpcao Invalida!!!\n\n");
            system("PAUSE");
            break;
  }
 }
 system("CLS");
  
 return 0;   
}

//Função INSERE_NO.

void insere_no(ponteiro p, int valor)

{
  ponteiro aux; 
 
  aux = (ponteiro) malloc (sizeof(struct NO));
  aux->info = valor;
  aux->llink = p;
  aux->rlink = p->rlink;
  p->rlink->llink = aux;
  p->rlink = aux;
}

//Função REMOVE_NO.

void remove_no(ponteiro p)

{
  p->llink->rlink = p->rlink;
  p->rlink->llink = p->llink;
  free(p);
}
//Função CRIA_DUPLA.

void cria_dupla(ponteiro pont)

{
 int valor;
 ponteiro aux; 

 printf("\n\nValor: ");
 scanf("%i", &valor);

 while (valor > 0)
 {
  insere_no(pont->llink, valor);
  printf("\n\nValor: ");
  scanf("%i", &valor);
 }
 
}

//Função CONSULTA_DUPLA.

ponteiro consulta_dupla(ponteiro pont, int info)
{
 ponteiro aux;
 
 aux = pont->rlink;

 while (aux != pont && aux->info != info)
 {
  aux = aux->rlink;
 }
 if (aux == pont)
 {
  aux = NULL;
 }
 
 return aux;   
}

//Função CONTA_NO_DUPLA.

int conta_no_dupla(ponteiro pont)
{
 int cont;
 ponteiro aux;

 cont = 0; 
 aux = pont->rlink;
 while (aux != pont)
 {
  cont++;
  aux = aux->rlink;      
 }

 return cont;     
}       

//Função LISTA_DUPLA.

void lista_dupla(ponteiro pont)
{
 ponteiro aux;
 
 if (pont != pont->rlink)
 {
   aux = pont->rlink;
   while (aux != pont)
   {
    printf("\n%i", aux->info);
    aux = aux->rlink;      
   }
 }
 else
 {
  printf("\n\nLista Vazia!!!\n\n"); 	
 }
 printf("\n");
}       
