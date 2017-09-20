#include <stdio.h>

#define tam 5

typedef struct {
          int topo;
          int elementos[tam];
        } Pilha;
        
void push(Pilha *, int, int);
int pop(Pilha *);

int main()
{
 int valor, i;
 Pilha p;
 
 p.topo = -1;

 printf("Empilhamento\n");    
 for (i = 1; i <= tam; i++)
 {
   printf("%i\n", i);  
   push(&p, i, tam);    
 }   

 printf("\n\n");
 printf("Desempilhamento\n"); 
 for (i = 1; i <= tam; i++)
 {
   valor = pop(&p);
   printf("%i\n", valor); 
 }   
 
 getch();
    
 return 0;   
} 

void push(Pilha * p, int valor, int n)
{
 if (p->topo == n)
 {
   printf("Pilha Cheia!");
   getch();           
 }     
 else
 {
  p->topo = p->topo + 1;
  p->elementos[p->topo] = valor;    
 }
}

int pop(Pilha * p)
{
 int valor = -1;
    
 if (p->topo == -1)
 {
   printf("Pilha Vazia!");
   getch();           
 }     
 else
 {
  valor = p->elementos[p->topo];    
  p->topo = p->topo - 1;
 }
 return valor;
}
