#include <stdio.h>
#include <math.h>

int main (void){

    int maior, menor, op, fat, cont, valor;
    int num[4];

    printf("Para maior menor                 - 1\n");
    printf("Para fatorial                    - 2\n");
    printf("Para notas acima/abaixo da media - 3\n");
    printf("Opcao: ");
    scanf("%d", &op);

    if (op == 1){
        cont = 0;
        for(cont = 0; cont<4; cont++){
            printf("Entre com o 1º numero: ");
            scanf("%d", &num[cont]);
        }
        cont = 0;
        maior = num[cont];
        menor = num[cont];
        cont++;

        do{
            if(num[cont] > maior ){
                maior = num[cont];
            }
            else if (num[cont] < menor){
                menor = num[cont];
            }
            cont++;
        }while(cont < 4);

        printf("O menor valor eh: %d \n", menor);
        printf("O maior valor eh: %d", maior);
    }
    else if (op == 2){
        cont = 1;
        valor = 0;
        printf("Entre com o numero para ser fatorado: ");
        scanf("%d", &fat);
        valor = 1 + valor;
        do {
            valor = valor * cont;
            cont++;
        }while(cont <= fat);

        printf("O fatorial de %d eh %d",fat, valor);
    }
    else if (op == 3){
        int notas[10];
        int media = 0;
        maior = 0;
        menor = 0;

        for(cont=0; cont<10; cont++){
            printf("Entre com a nota do aluno %d: ", cont);
            scanf("%d", &notas[cont]);
        }
        for(cont = 0; cont<10; cont++){
            media = media + notas[cont];
        }
        media = media / 10;
        cont = 0;
        do {
            if(notas[cont] >= media){
                maior = maior + 1;
            }
            else {
                menor = menor + 1;
            }
            cont++;
        }while (cont < 10);
        maior = maior/10 * 100;
        menor = menor/10 * 100;
        printf("%d \% alunos estao acima da media!\n",maior);
        printf("%d \% alunos estao abaixo da media!",menor);


    }
    else {
        printf("ERRO!");
    }
}
