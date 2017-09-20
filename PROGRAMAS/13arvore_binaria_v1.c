#include <stdio.h>

typedef struct NO * ponteiro;
struct NO {
           int info;
           ponteiro esq;
           ponteiro dir;
        };

ponteiro instala(ponteiro , int);
ponteiro pesquisa(ponteiro, int);
void pre_ordem(ponteiro);
void em_ordem(ponteiro);
void pos_ordem(ponteiro);
void visita(ponteiro);
int conta_nos(ponteiro);
int altura(ponteiro);
int conta_folha(ponteiro);

int main()
{
  ponteiro raiz = NULL;
  ponteiro ender;
  int dado, opcao;
  
  system("cls");
  do
  {
   printf("\n1 - Incluir NO");
   printf("\n2 - Pesquisa");   
   printf("\n3 - Caminhamentos");
   printf("\n4 - Altura");
   printf("\n5 - Qtde Nos");
   printf("\n6 - Qtde Nos Folha");
   printf("\n7 - Sair");
   printf("\n\nOpcao: ");
   fflush(stdin);
   scanf("%i",&opcao);
   
   switch (opcao)
   {
    case 1: 
         printf("\n\nvalor: ");
         fflush(stdin);
         scanf("%i", &dado);
         raiz = instala (raiz, dado);       
         break;
    case 2: 
         printf("\n\nvalor: ");
         fflush(stdin);
         scanf("%i", &dado);
         ender = pesquisa (raiz, dado);
         if (ender != NULL)
         {
          printf("\n\nSucesso!\n\n");
         }
         else
         {
          printf("\n\nInsucesso!\n\n");   
         }       
         system("pause");
         break;
    case 3:
         printf("\n\nCaminhamento Pre-Ordem\n\n");
         pre_ordem(raiz);
         printf("\n");
         printf("\n\nCaminhamento Em-Ordem\n\n");
         em_ordem(raiz);
         printf("\n");
         printf("\n\nCaminhamento Pos-Ordem\n\n");
         pos_ordem(raiz);
         printf("\n\n");         
         system("pause");
         break;
    case 4:
         printf("\n\nAltura da Arvore: %i\n\n", altura(raiz));
         system("pause");
         break;
    case 5:
         //printf("\n\nQtde de Nos da Arvore: %i\n\n", conta_nos(raiz));
         //system("pause");
         break;
    case 6:
         //printf("\n\nQtde de Nos Folha: %i\n\n", conta_folha(raiz));
         //system("pause");
         break;
    case 7:
         break;
    default:
         printf("\n\nOpcao Invalida !\n");
         system("pause");
   }
   system("cls");
  }while (opcao != 7);
    
 return (0);   
}

/* Funcao PESQUISA */

ponteiro pesquisa(ponteiro raiz, int dado)
{
 if (raiz != NULL && dado != raiz->info)
 {        
   if (dado < raiz->info)
   {
    raiz = pesquisa(raiz->esq, dado);
   }
   else
   {
    raiz = pesquisa(raiz->dir, dado);
   }
 }       
 return (raiz);
}

ponteiro instala(ponteiro raiz, int dado)
{
 if (raiz != NULL)
 {
  if (dado < raiz->info)
  {
   raiz->esq = instala(raiz->esq, dado);
  }
  else
  {
   raiz->dir = instala(raiz->dir, dado);
  }
 }
 else
 {
  raiz = (ponteiro) malloc(sizeof(struct NO));
  raiz->info = dado;
  raiz->esq = NULL;
  raiz->dir = NULL;
 }
         
 return (raiz);
}

/* Funcao PRE-ORDEM */

void pre_ordem(ponteiro raiz)
{
 if (raiz != NULL)
 {
  visita(raiz);            
  pre_ordem(raiz->esq);
  pre_ordem(raiz->dir);         
 }   
}

/* Funcao EM-ORDEM */

void em_ordem(ponteiro raiz)
{
 if (raiz != NULL)
 {
  em_ordem(raiz->esq);
  visita(raiz);  
  em_ordem(raiz->dir);         
 }   
}

/* Funcao POS-ORDEM */

void pos_ordem(ponteiro raiz)
{
 if (raiz != NULL)
 {
  pos_ordem(raiz->esq);
  pos_ordem(raiz->dir);         
  visita(raiz);  
 }   
}

/* Funcao ALTURA da Árvore */

int altura(ponteiro raiz)
{
 int retorno, he, hd;
 if (raiz == NULL) 
      retorno = -1; // altura de árvore vazia é -1
 else 
 {
  he = altura (raiz->esq);
  hd = altura (raiz->dir);
  if (he < hd)
  {
   retorno = hd + 1;
  } 
  else 
  {
   retorno = he + 1;   
  }
 }  
 return retorno;   
}

/* Funcao VISITA */

void visita(ponteiro raiz)
{
 printf("%i ", raiz->info);    
}
