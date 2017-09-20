#include <stdio.h>
#include <stdlib.h>
#define N 5

typedef struct
{
    int comeco, termino, tamanho;
    int elementos[N];
} Fila;
//-----------------------------------------------
void Inserir(Fila *, int);
int Remover(Fila *);
void listar(Fila *);
//-----------------------------------------------
int main()
{
    int valor;
    int opcao;
    Fila F;
    F.comeco = 0;
    F.termino = -1;
    F.tamanho = 0;

    do
    {
        system("cls");
        printf("1 - Inserir pilha");
        printf("\n2 - Remover pilha");
        printf("\n3 - Listar pilha");
        printf("\n4 - SAIR");
        printf("\n\nOpcao: ");
        scanf("%i",&opcao);

        switch (opcao)
        {
        case 1:
            system("cls");
            printf("Entre com o valor: ");
            scanf("%i",&valor);
            Inserir(&F,valor);
            break;
        case 2:
            system("cls");
            valor = Remover(&F);
            printf("Removido!!");
            getch();
            break;
        case 3:
            system("cls");
            listar(&F);
            break;
        case 4:
            printf("Obrigado!!");
            break;
        default:
            printf("Opcao Invalida!!");
            getch();
            break;
        }
    }
    while (opcao != 4);

    return 0;
}
//-------------------------------------------

void Inserir(Fila * F, int valor)
{
    if(F->tamanho == N)
    {
        printf("Fila cheia");
        getch();
    }
    else
    {
        F->tamanho = F->tamanho +1;
        F->termino = (F->termino + 1) %N;
        F->elementos[F->termino] = valor;
    }
}
//----------------------------------------------------
int Remover(Fila * F)
{
    int j;

    if(F->tamanho == 0){
        printf("Fila vazia");
        getch();
    }else{
        F->tamanho = F->tamanho -1;
        j = F->elementos[F->comeco];
        F->comeco = (F->comeco + 1) %N;
    }
    return j;
}

void listar(Fila * F)
{
    Fila Filaaux;
    Filaaux.comeco = 0;
    Filaaux.termino = -1;
    Filaaux.tamanho = 0;
   int Valor;

   if(F->tamanho == 0)
   {
       printf("Fila vazia");
   }else
   {
       printf("Valor: ");
      while (F->tamanho != 0)
      {
          Valor = Remover(F);
          Inserir(&Filaaux, Valor);
          printf("\n%i", Valor);
      }
      while (Filaaux.tamanho != 0)
      {
          Valor = Remover(&Filaaux);
          Inserir(F, Valor);
      }
   }getch();
}

