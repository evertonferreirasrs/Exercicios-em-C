#include <stdio.h>
#include <stdlib.h>

int main()
{
    int maior;

    int *a, *b, *c;

    a = (int*) malloc(sizeof(int));
    b = (int*) malloc(sizeof(int));
    c = (int*) malloc(sizeof(int));

    printf("Entre com o primeiro valor: ");
    scanf("%i", a);
    printf("Entre com o segundo valor: ");
    scanf("%i", b);
    printf("Entre com o terceiro valor: ");
    scanf("%i", c);

    maior = *a;

    if (*b > maior)
    {
        maior = *b;
    }
    if (*c > maior)
    {
        maior = *c;
    }

    printf("\nO maior valor eh : %i\n", maior);
}
