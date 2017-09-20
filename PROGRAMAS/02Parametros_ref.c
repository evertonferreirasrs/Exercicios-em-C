#include <stdio.h>

void Leitura_Coeficientes (float *, float *, float *);
int Raizes_Equacao (float, float, float, float *, float *);

int main()
{
  float A, B, C, Raiz1, Raiz2;
  int Estado;

  Leitura_Coeficientes (&A, &B, &C);
  if ( A == 0)
  {
   printf("Não é uma Equação do 2º. Grau");
  }
  else
  {
   Estado = Raizes_Equacao (A, B, C, &Raiz1, &Raiz2);
   if (Estado == 0)
   {
     printf("Não existem raizes reais");
   }
   else
   {
    printf("Raiz 1: %.2f, Raiz 2: %.2f", Raiz1, Raiz2);
   }
  }
  printf("\n\n\n");
  system("pause");
  return 0;
}

void Leitura_Coeficientes (float * X, float * Y, float * Z)
{
 printf("Valor de A: ");
 scanf("%f", X);
 printf("Valor de B: ");
 scanf("%f", Y);
 printf("Valor de C: ");
 scanf("%f", Z);
}

int Raizes_Equacao (float X, float Y, float Z, float * raiz1, float * raiz2)
{
 float Delta;
 int estado = 0;

 Delta = Y * Y - 4 * X * Z;
 if ( Delta >= 0 )
 {
  estado = 1;
  *raiz1 = (-Y + sqrt(Delta))/(2 * X);
  *raiz2 = (-Y - sqrt(Delta))/(2 * X);
 }
 return estado;
}
