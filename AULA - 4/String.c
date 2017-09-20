/* Aula 04/03
 * Everton
 * Implementacao das Funcoes String
 */

#include <stdio.h>
#define N 30

int tamanho(char[N]);
int pos(char[N], char[N]);
void sub(char[N], int, int, char[N]);
int cmp(char[N], char[N]);
void cpy(char[N], char[N]);
void cat(char[N], char[N]);

int main(){

    char cadeia[N];
    char subcadeia[N];
    int pos_ini;
    int comp;
    int op;

    int res;
    do{
    printf("O que deseja fazer?\n\n");
    printf("1 - Tamanho de uma String\n");
    printf("2 - Tirar uma string de uma String\n");
    printf("3 - Localizar a posicao em uma String\n");
    printf("4 - Comparar Strings\n");
    printf("5 - Copiar Strings\n");
    printf("6 - Concatenar Strings\n");
    printf("7 - Sair\n");

    scanf("%i",&op);

    switch (op){
    case 1:
        printf("Digite uma string para ver seu tamanho: ");
        scanf("%s",&cadeia);
        res = tamanho(cadeia);
        printf("A String %s tem %i caracteres", cadeia, res);
        break;
    case 2:
        printf("Digite uma string reduzir: ");
        scanf("%s",&cadeia);
        printf("Digite a posicao de inicio da substring: ");
        scanf("%i",&pos_ini);
        printf("Digite o comprimento da substring: ");
        scanf("%i",&comp);
        sub(cadeia, pos_ini, comp, subcadeia);
        if(subcadeia != NULL){
            printf("A substring e %s", subcadeia);
        }
        break;
    case 3:
        printf("Digite uma string principal: ");
        scanf("%s",&cadeia);
        printf("Digite uma string que estara dentro da principal: ");
        scanf("%s",&subcadeia);
        res = pos(cadeia, subcadeia);
        if(res != -1){
            printf("A string esta na posicao: %i", res);
        }
        break;
    case 4:
        printf("Digite uma string principal: ");
        scanf("%s",&cadeia);
        printf("Digite uma string a ser comparada com a principal: ");
        scanf("%s",&subcadeia);
        res = cmp(cadeia,subcadeia);
        if(res != -1){
            printf("%s e %s sao iguais", cadeia, subcadeia);
        }
        break;
    case 5:
        printf("Digite uma string para copiar: ");
        scanf("%s",&cadeia);
        cpy(cadeia,subcadeia);
        if(subcadeia != '\0'){
            printf("%s foi copiado para %s", cadeia, subcadeia);
        }
        break;
    case 6:
        printf("Digite uma string para ser concatenada: ");
        scanf("%s", &cadeia);
        printf("Digite uma string para ser concatenar: ");
        scanf("%s", &subcadeia);
        cat(cadeia,subcadeia);
        if(subcadeia != '\0'){
            printf("A String concatenada e %s", cadeia);
        }
        break;
    }

    system("pause");
    system("cls");
    }while(op <= 6);

	return 0;
}

int tamanho(char cadeia[N]){
    int i;

	i = 0;

	while(cadeia[i] != '\0'){
		i++;
    }

	return i;
}

int pos(char cadeia[N], char subcadeia[N]){
    int local,i,j,inicio,tamc,tams,achou;

    achou = 0;

    tamc = tamanho(cadeia);
    tams = tamanho(subcadeia);

    if(tamc >= tams){
        inicio = 0;
        while(tamc >= tams && achou == 0){
            i = 0;
            j = inicio;
            if(subcadeia[i]=cadeia[j]){
                local = j;
                i++;
                j++;
                while(i<tams && subcadeia[i]==cadeia[j]){
                    i++;
                    j++;
                }
                if(i<tams){
                    inicio++;
                    tamc--;
                }else{
                    achou = 1;
                }
            }else{
                inicio++;
                tamc--;
            }
        }
    }else{
        printf("A subcadeia tem tamanho Maior que a cadeia!");
    }

    if(achou=0){
        local=-1;
    }
    return local;
}


void sub(char cadeia[N],int pos_ini, int comp, char subcadeia[N]){
    int i, tam, cont;

    tam = tamanho(cadeia);

    if(pos_ini > tam-1 || pos_ini < 0){
        printf("Posicao inicial invalida!");
        subcadeia[0] = '\0';
    }else{
        if(comp > tam || comp < 0){
            printf("Comprimento invalido!");
            subcadeia[0] = '\0';
        }else{
            i = pos_ini;
            cont = 0;
            while(i < tam && cont < comp){
                subcadeia[cont] = cadeia[i];
                cont++;
                i++;
            }
            subcadeia[cont] = '\0';
        }
    }
}

int cmp(char cadeia[N], char cadeia2[N]){

    int i = 0;
    while(cadeia[i] != '\0'){
        if(cadeia[i] != cadeia2[i]){
            printf("%s e %s nao sao iguais", cadeia, cadeia2);
            return -1;
        }
        i++;
    }

    return 0;
}

void cpy(char cadeia[N], char cadeia2[N]){
    int tam = tamanho(cadeia);

    int i;
    for(i=0;i<tam;i++){
        cadeia2[i] = cadeia[i];
    }
    if(cmp(cadeia,cadeia2) == 0){
        cadeia2[i] = '\0';
    }
}

void cat(char concated[N], char cadeia2[N]){
    int tam1 = tamanho(concated);
    int tam2 = tamanho(cadeia2);

    if(tam1 + tam2 > N-1){
        printf("O tamanho das Strings excedem o maximo");
        concated[0] = '\0';
        return;
    }else{
        int i = 0;
        while(i < (tam1 + tam2 + 1) && cadeia2[i] != '\0'){
            concated[tam1+i] = cadeia2[i];
            i++;
        }
        concated[tam1+i] = '\0';
    }
}
