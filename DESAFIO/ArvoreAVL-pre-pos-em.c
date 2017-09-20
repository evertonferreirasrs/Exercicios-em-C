#include <stdio.h>
#include <stdlib.h>
//-------------------------------------------------------
//
typedef struct NO* ArvAVL;
//Prototipos
ArvAVL* cria_ArvAVL();
void libera_ArvAVL(ArvAVL *raiz);
int insere_ArvAVL(ArvAVL *raiz, int data);
int remove_ArvAVL(ArvAVL *raiz, int valor);
int estaVazia_ArvAVL(ArvAVL *raiz);
int altura_ArvAVL(ArvAVL *raiz);
int totalNO_ArvAVL(ArvAVL *raiz);
int consulta_ArvAVL(ArvAVL *raiz, int valor);
void preOrdem_ArvAVL(ArvAVL *raiz);
void emOrdem_ArvAVL(ArvAVL *raiz);
void posOrdem_ArvAVL(ArvAVL *raiz);

//--------------------------------------------------------
int main()
{
    ArvAVL* avl;
    int res,i, valor, opcao, N;

    avl = cria_ArvAVL();
    do
    {
        printf("\t\tARVORES AVL\n");
        printf("1 - criar arvores avl\n");
        printf("2 - remover valores da arvore\n");
        printf("3 - caminhamento pre-ordem\n");
        printf("4 - caminhamento pos-ordem\n");
        printf("5 - Sair\n");
        printf("Opcao: ");
        scanf("%i",&opcao);
        switch(opcao)
        {
        case 1:
            printf("Digite a quantidade de valores a ser inseridas: ");
            scanf("%i",&N);
            for(i=0; i<N; i++)
            {
                printf("Digite o %io. valor: ",i + 1);
                scanf("%i",&valor);
                res = insere_ArvAVL(avl,valor);
            }
            printf("\nAVL Caminhamento em ordem:\n");
            emOrdem_ArvAVL(avl);
            printf("\n\n");
            break;
        case 2:
            printf("Digite o Valor a ser removido: ");
            scanf("%i", &valor);
            remove_ArvAVL(avl,valor);
            printf("\nAVL tree:\n");
            emOrdem_ArvAVL(avl);
            printf("\n\n");
            break;
            case 3:
                preOrdem_ArvAVL(avl);
                break;
            case 4:
                posOrdem_ArvAVL(avl);
                break;
        default:
            break;
        }
    }
    while(opcao<5);

    libera_ArvAVL(avl);

    return 0;
}
//-----------------------------------------------------------
struct NO
{
    int info;
    int altura;         //altura da sub arvore usada para calcular o fator de balanceamento
    struct NO *esq;
    struct NO *dir;
};
//-----------------------------------------------------------
//Criar arvore
ArvAVL* cria_ArvAVL()
{
    ArvAVL* raiz = (ArvAVL*) malloc(sizeof(ArvAVL));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}
//-----------------------------------------------------------
void libera_NO(struct NO* no)
{
    if(no == NULL)
        return;
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}
//-----------------------------------------------------------
void libera_ArvAVL(ArvAVL* raiz)
{
    if(raiz == NULL)
        return;
    libera_NO(*raiz);           //libera cada nó
    free(raiz);                 //libera a raiz
}
//-----------------------------------------------------------
//função que calcula a altura de um no
int altura_NO(struct NO* no)
{
    int aux;
    if(no == NULL)          //se nao existe um no
        aux = -1;
    else
        aux = no->altura;
    return aux;
}
//-----------------------------------------------------------
int fatorBalanceamento_NO(struct NO* no)
{
    int aux;
    aux = labs(altura_NO(no->esq) - altura_NO(no->dir));// altura q define qual rotacao devo usar em modulo
    return aux;
}
//-----------------------------------------------------------
//calcula o maior valor
int maior(int x, int y)
{
    int aux;
    if(x > y)
        aux = x;
    else
        aux = y;
    return aux;
}
//------------------------------------------------------------
int estaVazia_ArvAVL(ArvAVL *raiz)
{
    int aux;
    if((raiz == NULL) || (*raiz == NULL))
        aux = 1;
    else
    {
        aux = 0;
    }
    return aux;
}
//---------------------------------------------------------------
int totalNO_ArvAVL(ArvAVL *raiz)
{
    int aux, alt_esq, alt_dir;
    if (raiz == NULL || *raiz == NULL)
        aux = 0;
    else
    {
        alt_esq = totalNO_ArvAVL(&((*raiz)->esq));
        alt_dir = totalNO_ArvAVL(&((*raiz)->dir));
        aux = (alt_esq + alt_dir + 1);
    }

    return aux;
}
//----------------------------------------------------------------
int altura_ArvAVL(ArvAVL *raiz)
{
    int aux;
    if (raiz == NULL || *raiz == NULL)
        aux = 0;
    else
    {
        int alt_esq = altura_ArvAVL(&((*raiz)->esq));
        int alt_dir = altura_ArvAVL(&((*raiz)->dir));
        if (alt_esq > alt_dir)
            aux = alt_esq + 1;
        else
            aux = alt_dir + 1;
    }
    return aux;
}
//--------------------------------------------------------------
void preOrdem_ArvAVL(ArvAVL *raiz)
{
    if(raiz == NULL)
        return;
    if(*raiz != NULL)
    {
        printf("No %d: H(%d) fb(%d)\n",(*raiz)->info,altura_NO(*raiz),fatorBalanceamento_NO(*raiz));
        preOrdem_ArvAVL(&((*raiz)->esq));
        preOrdem_ArvAVL(&((*raiz)->dir));
    }
}
//--------------------------------------------------------------
void emOrdem_ArvAVL(ArvAVL *raiz)
{
    if(raiz == NULL)
        return;
    if(*raiz != NULL)
    {
        emOrdem_ArvAVL(&((*raiz)->esq));
        printf("No %d: H(%d) fb(%d)\n",(*raiz)->info,altura_NO(*raiz),fatorBalanceamento_NO(*raiz));
        emOrdem_ArvAVL(&((*raiz)->dir));
    }
}
//---------------------------------------------------------------------
void posOrdem_ArvAVL(ArvAVL *raiz)
{
    if(raiz == NULL)
        return;
    if(*raiz != NULL)
    {
        posOrdem_ArvAVL(&((*raiz)->esq));
        posOrdem_ArvAVL(&((*raiz)->dir));
        printf("No %d: H(%d) fb(%d)\n",(*raiz)->info,altura_NO(*raiz),fatorBalanceamento_NO(*raiz));
    }
}
//--------------------------------------------------------
int consulta_ArvAVL(ArvAVL *raiz, int valor)
{
    int aux;
    if(raiz == NULL)
        aux = 0;
    else
    {
        struct NO* atual = *raiz;
        while(atual != NULL)
        {
            if(valor == atual->info)
            {
                aux = 1;
            }
            else{
                if(valor > atual->info)
                    atual = atual->dir;
                else
                    atual = atual->esq;
            }

        }
    }

    return aux;
}

//--------------------------------------------------------------
//ratacao simples a direita qndo inserida duas vezes a esquerda
void RotacaoLL(ArvAVL *A)           //LL
{
    printf("RotacaoLL\n");
    struct NO *B;
    //no recebe o filho a esquerda
    B = (*A)->esq;
    //filho a esq da raiz recebe o da direita
    (*A)->esq = B->dir;
    //filho a direita do no passa a ser a raiz
    B->dir = *A;
    //calcula o nova altura
    (*A)->altura = maior(altura_NO((*A)->esq),altura_NO((*A)->dir)) + 1;
    B->altura = maior(altura_NO(B->esq),(*A)->altura) + 1;
    *A = B;
}
//---------------------------------------------------------------
//rotacao simples a esquerda
void RotacaoRR(ArvAVL *A) //RR
{
    printf("RotacaoRR\n");
    struct NO *B;
    //no recebe o filho da direita da raiz
    B = (*A)->dir;
    //filho a dir da raiz recebe o da esq
    (*A)->dir = B->esq;
    //filho a esq do no passa a ser a raiz
    B->esq = (*A);
    //calcula o nova altura
    (*A)->altura = maior(altura_NO((*A)->esq),altura_NO((*A)->dir)) + 1;
    B->altura = maior(altura_NO(B->dir),(*A)->altura) + 1;
    //coloca o no na raiz;
    (*A) = B;
}
//-----------------------------------------------------------------------
//rotacao dupla a direira inserido aa direitaa da sub-arvore a esquerda
void RotacaoLR(ArvAVL *A) //LR
{
    printf("RotacaoLR\n");
    RotacaoRR(&(*A)->esq);
    RotacaoLL(A);
}
//rotacao dupla a esquerda inserido a esquerda da sub arvore a direita
void RotacaoRL(ArvAVL *A) //RL
{
    printf("RotacaoRL\n");
    RotacaoLL(&(*A)->dir);
    RotacaoRR(A);
}
//-------------------------------------------------------------
int insere_ArvAVL(ArvAVL *raiz, int valor)
{
    int res;
    if(*raiz == NULL) //árvore vazia ou nó folha
    {
        struct NO *novo;
        novo = (struct NO*)malloc(sizeof(struct NO));
        if(novo == NULL)
            return 0;

        novo->info = valor;
        novo->altura = 0;
        novo->esq = NULL;
        novo->dir = NULL;
        *raiz = novo;
        return 1;
    }

    struct NO *atual = *raiz;
    //se valor for menor q raiz, vai para sub arvore da esquerda
    if(valor < atual->info)
    {
        if((res = insere_ArvAVL(&(atual->esq), valor)) == 1)
        {
            //depois da insercao se o fator for maior q 2, precisa balancear
            if(fatorBalanceamento_NO(atual) >= 2)
            {
                if(valor < (*raiz)->esq->info )
                {
                    RotacaoLL(raiz);
                }
                else
                {
                    //se for maior caso de joelho
                    RotacaoLR(raiz);
                }
            }
        }
    }
    else
    {
        //se o valor for maior q raiz, vai para a sub arvore da dir
        if(valor > atual->info)
        {
            if((res = insere_ArvAVL(&(atual->dir), valor)) == 1)
            {
                if(fatorBalanceamento_NO(atual) >= 2)
                {
                    if((*raiz)->dir->info < valor)
                    {
                        RotacaoRR(raiz);
                    }
                    else
                    {
                        RotacaoRL(raiz);
                    }
                }
            }
        }
        else
        {
            printf("Valor duplicado!!\n");
            return 0;
        }
    }

    atual->altura = maior(altura_NO(atual->esq),altura_NO(atual->dir)) + 1;

    return res;
}
//---------------------------------------------------------------------------
struct NO* procuraMenor(struct NO* atual)
{
    struct NO *no1 = atual;
    struct NO *no2 = atual->esq;
    while(no2 != NULL)
    {
        no1 = no2;
        no2 = no2->esq;
    }
    return no1;
}
//-------------------------------------------------------------
int remove_ArvAVL(ArvAVL *raiz, int valor)
{
    if(*raiz == NULL) // valor não existe
    {
        printf("valor não existe!!\n");
        return 0;
    }

    int res;
    if(valor < (*raiz)->info)
    {
        if((res = remove_ArvAVL(&(*raiz)->esq,valor)) == 1)
        {
            if(fatorBalanceamento_NO(*raiz) >= 2)
            {
                if(altura_NO((*raiz)->dir->esq) <= altura_NO((*raiz)->dir->dir))
                    RotacaoRR(raiz);
                else
                    RotacaoRL(raiz);
            }
        }
    }

    if((*raiz)->info < valor)
    {
        if((res = remove_ArvAVL(&(*raiz)->dir, valor)) == 1)
        {
            if(fatorBalanceamento_NO(*raiz) >= 2)
            {
                if(altura_NO((*raiz)->esq->dir) <= altura_NO((*raiz)->esq->esq) )
                    RotacaoLL(raiz);
                else
                    RotacaoLR(raiz);
            }
        }
    }

    if((*raiz)->info == valor)
    {
        if(((*raiz)->esq == NULL || (*raiz)->dir == NULL)) // nó tem 1 filho ou nenhum
        {
            struct NO *oldNode = (*raiz);
            if((*raiz)->esq != NULL)
                *raiz = (*raiz)->esq;
            else
                *raiz = (*raiz)->dir;
            free(oldNode);
        }
        else    // nó tem 2 filhos
        {
            struct NO* temp = procuraMenor((*raiz)->dir);
            (*raiz)->info = temp->info;
            remove_ArvAVL(&(*raiz)->dir, (*raiz)->info);
            if(fatorBalanceamento_NO(*raiz) >= 2)
            {
                if(altura_NO((*raiz)->esq->dir) <= altura_NO((*raiz)->esq->esq))
                    RotacaoLL(raiz);
                else
                    RotacaoLR(raiz);
            }
        }
        if (*raiz != NULL)
            (*raiz)->altura = maior(altura_NO((*raiz)->esq),altura_NO((*raiz)->dir)) + 1;
        return 1;
    }

    (*raiz)->altura = maior(altura_NO((*raiz)->esq),altura_NO((*raiz)->dir)) + 1;

    return res;
}
