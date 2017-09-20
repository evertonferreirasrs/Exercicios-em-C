#include <stdio.h>
#include <stdlib.h>
#define N 5
typedef struct
{
    int comeco, termino;
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
    F.comeco = -1;
    F.termino = -1;

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
    if(F->termino == N)
    {
        printf("Fila cheia");
        getch();
    }
    else
    {
        F->termino = F->termino + 1;
        F->elementos[F->termino] = valor;
    }
}
//--------------------------------------------------------------
int Remover(Fila * F)
{
    int j;

    if(F->termino < F->comeco){
        printf("Fila vazia");
        getch();
    }else{
        j = F->elementos[F->comeco];
        F->comeco = F->comeco +1;
        printf("Removido!!");
        getch();
    }
    return j;
}
//----------------------------------------------------------------------
void listar(Fila * F)
{
    F->comeco = -1;

   if(F->termino == F->comeco)
   {
       printf("Fila vazia");
   }else
   {
       printf("valor: ");
       while(F->comeco < F->termino)
       {
           printf("\n%i",F->elementos[F->comeco]);
           F->comeco = F->comeco + 1;
       }
   }getch();
}

