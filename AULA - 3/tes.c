#include <stdlib.h>
#include <stdio.h>

typedef char palavra[18];

//definição dos módulos

int tam(palavra);
int pos(palavra);
int sub(palavra);

int main (){
    int tamanho = 0;
    palavra pala;
    pala[0] = '\0';
    printf("Entre com a palavra desejada: ");
    gets(pala);
    tamanho = tam(pala);
    printf("A palavra contem %d letras!", tamanho);
    printf("Entre com parte a ser pesquisada: ");
    pos(pala);
    sub(pala);




    printf("");
    printf("");
    getch();
}

int tam(palavra pala){
    int i, cont = 0;
    for(i=0; i < 18; i++){
        if(pala[i] != '\0'){
            cont = cont + 1;
        }
        else {
            i = 18;
            return cont;
        }
    }
}
