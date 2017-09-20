#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n1, n2, n3, n4, maior, menor;

    printf("Digite o N1: ");
    scanf("%i", &n1);
    printf("Digite o N2: ");
    scanf("%i", &n2);
    printf("Digite o N3: ");
    scanf("%i", &n3);
    printf("Digite o N4: ");
    scanf("%i", &n4);

    maior = n1;
    menor = n1;

    if (n2 > maior)
    {
        maior = n2;
    }
    if (n3 > maior)
    {
        maior = n3;
    }
    if (n4 > maior)
    {
        maior = n4;
    }


     if (n2 < menor)
    {
        menor = n2;
    }
    if (n3 < menor)
    {
        menor = n3;
    }
    if (n4 < menor)
    {
        menor = n4;
    }

    printf("\nO maior valor eh: %i", maior);
    printf("\nO menor valor eh: %i\n", menor);


}

