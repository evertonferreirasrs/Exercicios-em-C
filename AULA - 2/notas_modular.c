#include <stdio.h>
#define N 10

typedef float Tnotas[N];

//Protótipos
void Leitura (Tnotas);
float Calcula_media_turma(Tnotas);
void Conta_acima_abaixo(Tnotas,float,int *, int *);

int main()
{
    Tnotas notas;
    int acima, abaixo;
    float media, per_acima, per_abaixo;

    Leitura(notas);
    media = Calcula_media_turma(notas);
    Conta_acima_abaixo(notas, media, &acima, &abaixo);
    per_acima = ((float)acima / N) * 100;
    per_abaixo = ((float)abaixo / N) * 100;

    printf("\nTotal Acima = %i (%.2f)", acima, per_acima);
    printf("\nTotal Abaixo = %i (%.2f)", abaixo, per_abaixo);
    getch();

}

void Leitura (Tnotas notas)
{
    int i;

    for(i = 0; i < N; i++)
    {
        printf("Nota do Aluno [%i]: ", i+1);
        scanf("%f", &notas[i]);
    }
}
float Calcula_media_turma(Tnotas notas)
{
    int i;
    float media = 0.0;

    for(i = 0; i < N; i++)
    {
        media = media + notas[i];
    }
    media = media / N;

    return media;
}
void Conta_acima_abaixo(Tnotas notas,float media,int * Pacima, int * Pabaixo)
{
    int i;
    *Pacima = 0.0;
    *Pabaixo = 0.0;

    for(i = 0; i < N; i++)
    {
        if (notas[i] >= media)
        {
            *Pacima = *Pacima + 1;
        }else
        {
            *Pabaixo = *Pabaixo + 1;
        }
    }
}
