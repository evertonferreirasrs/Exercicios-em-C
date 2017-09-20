#include <stdio.h>
#include <stdlib.h>
#define N 5
typedef struct
{
    int topo;
    int elementos[N];
} pilha;
//-----------------------------------------------
void PUSH(pilha *, int);
int POP(pilha *);
void listar(pilha *);
//-----------------------------------------------
int main()
{
    int valor;
    int opcao;
    pilha P;
    P.topo = -1;

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
            PUSH(&P,valor);
            break;
        case 2:
            system("cls");
            valor = POP(&P);
            printf("Removido!!");
            getch();
            break;
        case 3:
            system("cls");
            listar(&P);
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

void PUSH(pilha * P, int valor)
{
    if(P->topo == N)
    {
        printf("Pilha cheia");
        getch();
    }
    else
    {
        P->topo = P->topo + 1;
        P->elementos[P->topo] = valor;
    }
}

int POP(pilha * P)
{
    int j;

    if(P->topo == -1){
        printf("Pilha vazia");
        getch();
    }else{
        j = P->elementos[P->topo];
        P->topo = P->topo -1;
    }
    return j;
}

void listar(pilha * P)
{
    pilha pilhaaux;
    pilhaaux.topo = -1;

    int Valor;

    if(P->topo == -1)
   {
       printf("Pilha vazia");
   }else
   {
       printf("Valor: ");
        while (P->topo != -1)
      {
          Valor = POP(P);
          PUSH(&pilhaaux, Valor);
          printf("\n%i", Valor);
      }
      while (pilhaaux.topo != -1)
      {
          Valor = POP(&pilhaaux);
          PUSH(P, Valor);
      }
   }getch();
}

