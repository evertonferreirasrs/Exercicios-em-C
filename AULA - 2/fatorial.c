#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, fat, i;
    fat = 1;

    printf("Digite um numero para ser calculado o seu Fatorial: ");
    scanf("%i", &num);

    if(num > 1)
        {
            for (i = 1; i <= num; i++)
            {
                fat = fat * i;
            }
        }else
        {
            fat = 1;
        }

    printf("\nO Fatorial eh: %i\n", fat);

}
