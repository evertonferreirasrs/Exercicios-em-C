#include <stdio.h>

int main()
{
 char cadeia[2];
 int  codigo[2];
 
 printf("\n\n");
 printf("TIPOS    X    BYTES\n");
 printf("___________________\n\n");
 
 printf("CHAR        %i bytes\n\n", sizeof(char));
 printf("LONG INT    %i bytes\n\n", sizeof(long int));
 printf("INT         %i bytes\n\n", sizeof(int));
 printf("SHORT INT   %i bytes\n\n", sizeof(short int));
 printf("FLOAT       %i bytes\n\n", sizeof(float));
 printf("DOUBLE      %i bytes\n\n", sizeof(double));
 printf("CHAR [2]    %i bytes\n\n", sizeof(cadeia));  
 printf("INT [2]     %i bytes\n\n", sizeof(codigo));
 
 printf("___________________\n\n");
 
 getch();
 
 
 return 0;   
}

