//Exemplo de uso de Pilha Encadeada
//Considerando que será armazendo na Pilha somente valores positivos e zero.

#include <stdio.h>

#define tam 5

typedef struct Pilha * ponteiro;
struct Pilha {
         int info;
         ponteiro link;
       };
        
ponteiro push(ponteiro topo, int);
ponteiro pop(ponteiro topo, int *);

int main()
{
 int valor, i;
 ponteiro topo;
 
 topo = NULL;

 printf("Empilhamento\n");    
 for (i = 1; i <= tam; i++)
 {
   printf("%i\n", i);  
   topo = push(topo, i);    
 }   

 printf("\n\n");
 printf("Desempilhamento\n"); 
 for (i = 1; i <= tam; i++)
 {
   topo = pop(topo, &valor);
   printf("%i\n", valor); 
 }   
 
 getch();
    
 return 0;   
} 

ponteiro push(ponteiro topo, int valor)
{
  ponteiro p;

  p = (ponteiro) malloc(sizeof(struct Pilha));
  p->info = valor;
  p->link = topo;
  topo = p;
  p = NULL;
  
  return topo;
}

ponteiro pop(ponteiro topo, int * valor)
{

 ponteiro p;
    
 if (topo == NULL)
 {
   printf("Pilha Vazia!");
   *valor = -1;
   getch();           
 }     
 else
 {
  *valor = topo->info;
  p = topo;
  topo = topo->link;
  free(p);
 }
 return topo;
}
