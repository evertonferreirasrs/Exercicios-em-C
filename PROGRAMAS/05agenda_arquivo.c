//Aplicativo Agenda
//Agenda - Estrutura de Dados Arquivo

#include <stdio.h>

//typedef - Utilizado para definir tipos
typedef struct {
                char contato[30];
                char tel_fixo[12];
                char celular[12];
                char email[20];
                char cidade[20];
                char estado[15];
               } Treg_agenda;
typedef FILE * Tagenda;

//Protótipos - Definição de funções (módulos)
void cadastro_contato();
Treg_agenda pesquisa_contato(char []);
void pesquisa_cidade(char []);
void pesquisa_estado(char []);
void rel_geral();

int main()
{
 Treg_agenda reg_agenda;
 int opcao;
 char contato[30];
 char cidade[20];
 char estado[15];

 do
 {
  system("cls");
  printf("\n1- Cadastro de Contatos");
  printf("\n2- Pesquisa por Nome");
  printf("\n3- Pesquisa por Cidade");
  printf("\n4- Pesquisa por Estado");
  printf("\n5- Relatorio Geral");
  printf("\n6- Finaliza");
  printf("\n\nOpcao: ");
  scanf("%i", &opcao);
  switch (opcao)
  {
   case 1: cadastro_contato();
           break;
   case 2: printf("\nDigite o nome do Contato: ");
           scanf("%s", &contato);
           reg_agenda = pesquisa_contato(contato);
           if (reg_agenda.contato != "")
           {
            printf("\n\nTelefone: %s", reg_agenda.tel_fixo);
            printf("\nCelular: %s", reg_agenda.celular);
            printf("\nEmail: %s", reg_agenda.email);
            printf("\nCidade: %s", reg_agenda.cidade);
            printf("\nEstado: %s", reg_agenda.estado);
           }
           else
           {
            printf("\n\nContato inexistente!!!");   
           }
           getch();
           break;
   case 3: printf("\nDigite a Cidade: ");
           scanf("%s", &cidade);
           pesquisa_cidade(cidade);
           getch();
           break;
   case 4: printf("\nDigite o Estado: ");
           scanf("%s", &estado);
           pesquisa_estado(estado);
           getch();
           break;
   case 5: rel_geral();
           getch();
           break;
   case 6: break;
   default:printf("\nOpcao Invalida!!!");
           getch();                  
  }
 }while (opcao != 6);

 return 0;
}

//Módulo Cadastro
void cadastro_contato()
{
 char contato[30];
 Tagenda agenda;
 Treg_agenda reg_agenda;
  
 agenda = fopen("agenda.dat","ab"); 
 printf("\n\nContato: ");
 scanf("%s", &contato);
 while (strcmp(contato, "fim") != 0)
 {
  strcpy(reg_agenda.contato, contato);
  printf("\nTelefone Fixo: ");
  scanf("%s", &reg_agenda.tel_fixo);       
  printf("\nCelular: ");
  scanf("%s", &reg_agenda.celular);
  printf("\nEmail: ");
  scanf("%s", &reg_agenda.email);
  printf("\nCidade: ");
  scanf("%s", &reg_agenda.cidade);       
  printf("\nEstado: ");
  scanf("%s", &reg_agenda.estado);       
  fwrite(&reg_agenda,sizeof(Treg_agenda), 1, agenda);
  printf("\nContato: ");
  scanf("%s", &contato);       
 }
 fclose(agenda); 
}

void rel_geral()
{
 Tagenda agenda;
 Treg_agenda reg_agenda;
 
 agenda = fopen("agenda.dat", "rb");
 if (agenda == NULL)
 {
  printf("\n\nArquivo nao aberto - Fale com a equipe de TI");
 }
 else
 {
  fread(&reg_agenda, sizeof(Treg_agenda), 1, agenda);   
  while (! feof(agenda))
  {
   printf("\n\n");
   printf("\nContato : %s", reg_agenda.contato);      
   printf("\nTelefone: %s", reg_agenda.tel_fixo);
   printf("\nCelular : %s", reg_agenda.celular);      
   printf("\nEmail   : %s", reg_agenda.email);      
   printf("\nCidade  : %s", reg_agenda.cidade);
   printf("\nEstado  : %s", reg_agenda.estado);      
   fread(&reg_agenda, sizeof(Treg_agenda), 1, agenda);     
  }   
  fclose(agenda);
 } 
 getch();
}

Treg_agenda pesquisa_contato(char contato[])
{
 Tagenda agenda;
 Treg_agenda reg_agenda;
 
 return reg_agenda;
}

void pesquisa_cidade(char cidade[])
{
 Tagenda agenda;
 Treg_agenda reg_agenda;
     
}

void pesquisa_estado(char estado[])
{
 Tagenda agenda;
 Treg_agenda reg_agenda;
     
}
