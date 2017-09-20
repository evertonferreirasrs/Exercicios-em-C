#include <stdio.h>

#define tam 5

typedef struct {
          int comeco, termino, tamanho;
          int elementos[tam];
        } Fila;
        
void enfileire(Fila *, int);
int desenfileire(Fila *);

int main()
{
 int valor, i;
 Fila f;
 
 f.comeco = 0;
 f.termino = -1;
 f.tamanho = 0;

 printf("Enfileiramento\n");    
 for (i = 0; i < tam; i++)
 {
   printf("%i\n", i);  
   enfileire(&f, i);    
 }   

 printf("\n\n");
 printf("Desenfileiramento\n"); 
 for (i = 0; i < tam; i++)
 {
   valor = desenfileire(&f);
   printf("%i\n", valor); 
 }   
 
 getch();
    
 return 0;   
} 

void enfileire(Fila * f, int valor)
{
 if (f->tamanho == tam)
 {
   printf("Fila Cheia!");
   getch();           
 }     
 else
 {
  f->termino = f->termino % tam + 1;
  f->elementos[f->termino] = valor;
  f->tamanho = f->tamanho + 1;    
 }
}

int desenfileire(Fila * f)
{
 int valor = -1;
    
 if (f->tamanho == 0)
 {
   printf("Fila Vazia!");
   getch();           
 }     
 else
 {
  valor = f->elementos[f->comeco];    
  f->comeco = f->comeco % tam + 1;
  f->tamanho = f->tamanho - 1;
 }
 return valor;
}
