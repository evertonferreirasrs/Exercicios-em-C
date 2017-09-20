#include <stdio.h>
#include <stdlib.h>
#define n 10

int main()
{
    int acima, abaixo, i;
    float notas[i];
    float media, per_acima, per_abaixo;

    for (i=0; i < n; i++)
    {
        printf("Digite a nota do aluno[%i]: ", i+1);
        scanf("%f", &notas[i]);
    }
    media = 0;

    for (i=0; i < n; i++)
    {
        media = media + notas[i];
    }
    media = media / n;

    acima = 0;
    abaixo = 0;

    for (i = 0; i < n; i++)
    {
        if(notas[i] >= media)
        {
            acima++;
        }else
        {
            abaixo++;
        }
    }
    per_acima = ((float)acima / n )* 100;
    per_abaixo = ((float)abaixo / n )* 100;

    printf("\nMedia da turma = %.2f", media);
    printf("\nAcima ou igual a media = %i", acima);
    printf("\nAbaixo da media = %i", abaixo);
    printf("\n\nPercentual acima da media = %.2f", per_acima);
    printf("\nPercentual abaixo da media = %.2f\n\n", per_abaixo);

    getch();
}
