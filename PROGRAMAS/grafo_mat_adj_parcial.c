
#include <stdio.h>

#define vertices 5


typedef int Tmat_adj[vertices][vertices];
typedef struct fila Tfila;
typedef struct pilha Tpilha;

struct fila
{
 int comeco, termino, tamanho;
 int elementos[vertices];
};

struct pilha
{
 int topo;
 int elementos[vertices];
};

//Protótipos de Funções.
void inicia_grafo(Tmat_adj);//Inicializa o matriz de adjacencias.
void armazena_grafo(Tmat_adj);//Armazena as adjacências.
void mostra_grafo(Tmat_adj);//Escreve a matriz de adj.
void amplitude(int, Tmat_adj);//Caminhamento em amplitude.
void profundidade(int, Tmat_adj);//Caminhamento em profundidade.
void visite(int);//Escreve o vértice na tela.
void inicia_marca(int []);//Zera o vetor de visitas.
void marque(int, int []);//Marca o vértice visitado.
void inicia_fila(Tfila *);//Inicializa a fila sequencial.
void enfileire(int, Tfila *);//Insere na fila.
int desenfileire(Tfila *);//Retira da fila.
void inicia_pilha(Tpilha *);//Inicializa a pilha sequencial.
void empilhe(int, Tpilha *);//Insere na pilha.
int desempilhe(Tpilha *);//Retira da pilha.

int main()
{
 char opcao;
 int vertice;
 Tmat_adj grafo;

 inicia_grafo(grafo);

 do
 {
   system("cls");
   printf("\n\n\nGRAFO - MATRIZ DE ADJACENCIAS\n");
   printf("\n1 - Armazena GRAFO");
   printf("\n2 - Mostra MATRIZ de Adjacencias");
   printf("\n3 - Caminhamento AMPLITUDE");
   printf("\n4 - Caminhamento PROFUNDIDADE");
   printf("\n5 - Fim\n");
   printf("\nOpcao: ");
   fflush(stdin);
   scanf("%c",&opcao);

   switch (opcao)
   {
     case '1': armazena_grafo(grafo);
               break;
     case '2': mostra_grafo(grafo);
               printf("\n\n");
               system("pause");
               break;
     case '3': do
               {
                 printf("\n\nVertice Inicial: ");
                 scanf("%i", &vertice);
               }while ((vertice < 1) || (vertice > vertices));
               amplitude(vertice, grafo);
               printf("\n\n");
               system("pause");
               break;
     case '4': do
               {
                 printf("\n\nVertice Inicial: ");
                 scanf("%i", &vertice);
               }while ((vertice < 1) || (vertice > vertices));
               profundidade(vertice, grafo);
               printf("\n\n");
               system("pause");
               break;
     case '5': printf("\n\nFinalizando");
               break;
     default:  printf("\n\nOpcao Invalida!\n\n");
               system("pause");
   }

 }while (opcao != '5');

 return (0);
}


void inicia_grafo(Tmat_adj grafo)
{
  int i, j;

  for (i=0; i < vertices; i++)
  {
    for (j=0; j < vertices; j++)
    {
      grafo[i][j] = 0;
    }
  }

}

void armazena_grafo(Tmat_adj grafo)
{
  int i,j;
  char resp;

  do
  {
   do
   {
    printf("\nVertice Origem: ");
    scanf("%i", &i);
   }while (i < 1 || i > vertices);
   do
   {
    printf("\nVertice Destino: ");
    scanf("%i", &j);
   }while (j < 1 || j > vertices);
   grafo[i-1][j-1] = 1;
   grafo[j-1][i-1] = 1;
   printf("\nContinuar(s/n): ");
   fflush(stdin);
   scanf("%c", &resp);
  }while (resp == 's');
}

void mostra_grafo(Tmat_adj grafo)
{
  int i,j;
  for (i=0; i < vertices; i++)
  {
    printf("\n");
    for (j=0; j < vertices; j++)
    {
      printf("%3i", grafo[i][j]);
    }
  }
}

void visite(int vertice)
{
  printf("\n%i", vertice);
}

void inicia_marca(int marca[])
{
  int i;
  for (i=0; i < vertices; i++)
  {
    marca[i] = 0;
  }
}

void marque(int vertice, int marca[])
{
  marca[vertice] = 1;
}

void inicia_fila(Tfila * f)
{
  f->tamanho = 0;
  f->comeco = 0;
  f->termino = -1;
}

void enfileire(int n, Tfila * f)
{
  if (f->tamanho == vertices)
  {
    printf("\n\nFila Cheia!\n\n");
    system("pause");
  }
  else
  {
    f->termino = (f->termino + 1) % vertices;
    f->elementos[f->termino] = n;
    f->tamanho++;
  }
}

int desenfileire(Tfila * f)
{
  int n;

  if (f->tamanho == 0)
  {
    n = -1;
  }
  else
  {
    n = f->elementos[f->comeco];
    f->comeco = (f->comeco + 1) % vertices;
    f->tamanho--;
  }
  return n;
}

void inicia_pilha(Tpilha * p)
{
 p->topo = -1;
}

void empilhe(int n, Tpilha * p)
{
  if (p->topo == vertices)
  {
    printf("\n\nPilha Cheia!\n\n");
    system("pause");
  }
  else
  {
    p->topo++;
    p->elementos[p->topo] = n;
  }
}

int desempilhe(Tpilha * p)
{
  int n;

  if (p->topo == -1)
  {
    n = -1;
  }
  else
  {
    n = p->elementos[p->topo];
    p->topo--;
  }
  return n;
}

void amplitude(int n, Tmat_adj grafo)
{
 Tfila f;
 int marca[vertices];
 int t, w;

 inicia_fila(&f);
 inicia_marca(marca);

 visite(n);
 marque(n-1,marca);
 enfileire(n,&f);
 while(f.tamanho > 0)
 {
     t = desenfileire(&f);
     for(w = 0;w < vertices; w++)
     {
         if(grafo[t-1][w] == 1 && marca[w] != 1)
         {
             visite(w+1);
             marque(w,marca);
             enfileire(w+1,&f);
         }
     }
 }


}

void profundidade(int n, Tmat_adj grafo)
{
 Tpilha p;
 int marca[vertices];
 int t, w;

 inicia_pilha(&p);
 inicia_marca(marca);

 visite(n);
 marque(n-1,marca);
 empilhe(n,&p);

 while(p.topo >= 0)
 {
     t = desempilhe(&p);
     t--;
     w = 0;
     while(w < 5)
     {
         if(grafo[t][w] == 1 && marca[w] != 1)
         {
             visite(w+1);
             marque(w,marca);
             empilhe(t+1,&p);
             t = w;
             w = 0;
         }
         else
         {
             w++;
         }
     }

 }

}
