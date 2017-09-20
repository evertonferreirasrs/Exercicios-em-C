#include <stdio.h>
#include <stdlib.h>

typedef int *Ponteiro;

int main()
{
 Ponteiro Pont;
 int aux;
 
 // Usando ponteiro SEM alocar memória.

 aux = 10;
 Pont = &aux;  // Operador unário & (endereço de).
 printf("\n\n\n");
 printf("Uso de Ponteiro SEM Alocacao Dinamica");
 printf("\n\n\naux = 10; Pont = &aux;\n"); 
 printf("\nValor do conteudo de AUX: %i", aux);
 printf("\nValor do endereco de AUX: %p", &aux);
 printf("\n\n");
 printf("\nValor do conteudo de PONT: %p", Pont);
 printf("\nValor do endereco de PONT: %p", &Pont);
 
 *Pont = 20;  // Operador unário * (conteúdo de).

 printf("\n\n\n======================================"); 
 printf("\n\n\n*Pont = 20;\n"); 
 printf("\nValor do conteudo de AUX: %i", aux);
 printf("\nValor do endereco de AUX: %p", &aux);
 printf("\n\n");
 printf("\nValor do conteudo de PONT: %p", Pont);
 printf("\nValor do endereco de PONT: %p", &Pont);

 printf("\n\n");
 system("PAUSE");

 // Usando ponteiro COM alocação de memória.

 aux = 10;
 Pont = (Ponteiro) malloc(sizeof(int));
 printf("\n\n\n"); 
 printf("\nUso de Ponteiro COM Alocacao Dinamica");
 printf("\n\n\naux = 10;\n"); 
 printf("\nValor do conteudo de AUX: %i", aux);
 printf("\nValor do endereco de AUX: %p", &aux);
 printf("\n\n");
 printf("\nValor do conteudo de PONT: %p", Pont);
 printf("\nValor do endereco de PONT: %p", &Pont);

 *Pont = 20;
 printf("\n\n\n======================================"); 
 printf("\n\n\n*Pont = 20;\n"); 
 printf("\nValor do conteudo de AUX: %i", aux);
 printf("\nValor do endereco de AUX: %p", &aux);
 printf("\n\n");
 printf("\nValor da area apontada por PONT: %i", *Pont);
 printf("\nValor do endereco de PONT: %p", &Pont);

 printf("\n\n");
 
 system("PAUSE");
 
 return (0);   
}
