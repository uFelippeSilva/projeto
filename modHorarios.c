#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "modHorarios.h"
#include "modAnimal.h"
#include "modServico.h"
#include "validacaoProjeto.h"
void modulo_horarios(void){
char opcao;
do
{
    opcao = menu_horarios();
    switch(opcao)
    {
    case '1': 	cadastrar_horario();
    break;
    case '2': 	busca_consulta();
    break;
    case '3': 	atualizar_horario();
    break;
    case '4':   deletar_consulta();
    break;
    }
}
while (opcao != '0');}
char menu_horarios(void){
char op;
system("clear||cls");
printf("\n");
printf("///////////////////////////////////////////////////////////////////////////////////\n");
printf("///                                                                             ///\n");
printf("///         SIG-Pet um sistema de agendamento de consultas para pets            ///\n");
printf("///                                                                             ///\n");
printf("///////////////////////////////////////////////////////////////////////////////////\n");
printf("///                                                                             ///\n");
printf("///            = = = = sistema de agendamento de Horarios para pets = = = =     ///\n");
printf("///           |                                                             |   ///\n");
printf("///           |           1. Cadastrar Consulta                             |   ///\n");
printf("///           |           2. Procurar Consulta                              |   ///\n");
printf("///           |           3. Atualizar Consulta                             |   ///\n");
printf("///           |           4. Deletar Consulta Marcada                       !   ///\n");
printf("///           |           0. Voltar Menu Principal                          |   ///\n");
printf("///           |                                                             |   ///\n");
printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =    ///\n");
printf("///                                                                             ///\n");
printf("///////////////////////////////////////////////////////////////////////////////////\n");
printf("\n");
printf("escolha oque deseja:\n");
scanf("%c",&op);
getchar();
printf("\t\t\t<<< ... Loading ... >>>\n");
sleep(1);

return op;

}

void cadastrar_horario(void){
system("clear||cls");
Horario* hora;
hora = (Horario*) malloc(sizeof(Horario)); 
int a;
int b;
do
{
  printf(" | Informe o cpf do usuario: ");
  scanf(" %19[^\n]", hora->cpf_busca);
  getchar();
  printf(" | Informe o id do animal: ");
  scanf(" %9[^\n]", hora->id_animal);
  a = busca_petfile(hora->cpf_busca,hora->id_animal );
} 
while (a == 0);
do
{
  printf(" | Informe o ID do Servico: ");
  scanf(" %4[^\n]", hora->id_servico);
  getchar();
  b = buscaservico_file(hora->id_servico);
} 
while (b ==0);
do
{
  printf(" Digite o dia da Consulta: ");
  scanf("%d", &hora->dd);
  getchar();
  printf(" Digite o Mês da Consulta: ");
  scanf("%d", &hora->mm);
  getchar();
  printf(" digite o Ano da Consulta: ");
  scanf("%d", &hora->aa);
  getchar();  
}
while(!validaData(hora->dd, hora->mm, hora->aa));
do
{
  printf(" Digite a Hora da Consulta: ");
  scanf("%d", &hora->hora);
  getchar();
  printf(" Digite o Minuto da Consulta: ");
  scanf("%d", &hora->min);
  getchar();
}
while(!validaHora(hora->hora, hora->min));
printf("Informe id da consulta 6 Digitos: ");
scanf(" %6[^\n]", hora->id_consulta);
getchar();
hora->status='a';

printf("Consulta Cadastrado com Sucesso.!");
printf("Pressione qualquer tecla para sair...");
getchar();
gravaConsulta(hora);
free(hora);
}
void atualizar_horario(void){
system ( " clear||cls " );
FILE* fp;
Horario* hora;
int achou;
char resp;
char id_busca[7];
hora = (Horario*) malloc(sizeof(Horario));
achou =0;
fp = fopen("consultas.dat", "r+b");
if(fp == NULL)
{
  printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
  printf("Nao e possivel continuar o programa...\n");
  exit(1);
}
printf(" | ========================================================= | \n");
printf(" | --------------------------------------------------------- | \n");
printf(" | ------------------- Atualizar Consulta -------------------| \n");
printf(" | --------------------------------------------------------- | \n");
printf(" | ========================================================= | \n");
printf("Digite o ID da Consulta cadastrado: ");
scanf("%s", id_busca);
getchar();
while((!achou) && (fread(hora, sizeof(Horario), 1, fp)))
{
    if((strcmp(hora->id_consulta, id_busca) == 0) && (hora->status == 'a'))
    {
      achou = 1;
    }
}
if(achou)
{
exibeconsulta(hora);
printf(" Deseja realmente editar esta consulta? [s/n] ");
scanf("%c", &resp);
getchar();
  if (resp == 's' || resp == 'S')
  {
    do 
    {
      printf("Digite o novo dia do servico: ");
      scanf("%d", &hora->dd);
      getchar();
      printf("Digite o novo mes do servico: ");
      scanf("%d", &hora->mm);
      getchar();
      printf("Digite o novo ano do servico: ");
      scanf("%d", &hora->aa);
      getchar();   
    }
    while(!validaData(hora->dd, hora->mm, hora->aa));
    do 
    {
      printf(" Digite a nova hora do servico: ");
      scanf("%d", &hora->hora);
      getchar();
      printf(" Digite o novo Minuto do servico: ");
      scanf("%d", &hora->min);
      getchar();   
    }
    while(!validaHora(hora->hora, hora->min));
    hora->status = 'a'; // a = Ativo. x = Inativo
    fseek(fp, (-1)*sizeof(Horario), SEEK_CUR);
    fwrite(hora, sizeof(Horario), 1, fp);
    printf("\n Consulta editada com sucesso!!!\n");
    gravaConsulta(hora);
    printf("Pressione qualquer tecla para sair... ");
    getchar();
  }
  else
  {
    printf("Os dados da consulta nao foram alterados!");
  }
}
free(hora);
fclose(fp);
}

void busca_consulta(void){
system("clear||cls");
FILE* fp;
Horario* hora;
int achou;
char id_busca[7];
fp = fopen("consultas.dat", "rb");
if (fp == NULL)
  {
    printf("Ops! Erro na abertura do arquivo!\n");
    exit(1);
  }
printf("\n = Buscar Consulta = \n"); 
printf("Informe ID da consulta: "); 
scanf(" %6[^\n]", id_busca);
hora = (Horario*) malloc(sizeof(Horario));
achou = 0;
while((!achou) && (fread(hora,sizeof(Horario), 1, fp))) 
{
  if ((strcmp(hora->id_consulta, id_busca) == 0) && (hora->status != 'x'))
  {
    achou =1;
  }
}
if (achou)
{
  exibeconsulta(hora);
}
else
{
  printf("Os dados da consulta nao foram encontrados\n");
}
fclose(fp);
free(hora);
printf("Pressione qualquer tecla para sair.... ");
getchar();
}

void deletar_consulta(void){
system ( " clear||cls " );
FILE* fp;
Horario* hora;
int achou;
char resp;
char id_busca[7];
fp = fopen("consultas.dat", "r+b");
if (fp == NULL)
{
  printf("Ops! Erro na abertura do arquivo!\n");
  exit(1);
}
hora = (Horario*) malloc(sizeof(Horario));
printf(" | ============================================================== | \n");
printf(" | -------------------------------------------------------------- | \n");
printf(" | ---------------------- Excluir usuario ----------------------- | \n");
printf(" | -------------------------------------------------------------- | \n");
printf(" | ============================================================== | \n");
printf("Informe o ID da consulta: ");
scanf("%s", id_busca);
getchar();
achou=0;
while ((!achou) && (fread(hora, sizeof(Horario), 1, fp)))
{
  if ((strcmp(hora->id_consulta, id_busca) == 0) && (hora->status == 'a'))
  {
    achou = 1;
  }
}
if (achou)
{
  exibeconsulta(hora);
  printf("Deseja realmente excluir esta consulta? (s/n)");
  scanf("%c", &resp);
  if (resp == 's' || resp == 'S')
  {
    hora->status = 'x';
    fseek(fp, (-1)*sizeof(Horario), SEEK_CUR);
    fwrite(hora, sizeof(Horario), 1, fp);
    printf("\n Consulta excluido com sucesso!");
    gravaConsulta(hora);
    printf("Pressione qualquer tecla para sair... ");
    getchar();
  }
  else
  {
    printf("\n Tudo bem, a consulta nao foi alterada.");
  }
  }
  else
  {
    printf("Consulta nao foi encontrada!");
  }
free(hora);
fclose(fp);
printf("Pressione qualquer tecla para sair.... ");
getchar();
}

void gravaConsulta(Horario* hora){
FILE* fp;
fp = fopen("consultas.dat", "ab");
if (fp == NULL)
{
  printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
  printf("Não é possível continuar este programa...\n");
  exit(1);
}
fwrite(hora, sizeof(Horario), 1, fp);
fclose(fp);
}

void exibeconsulta(Horario* hora){
system("clear||cls");
  {
  printf("\n= = = Consulta Cadastrada = = =\n");
  printf("CPF dono do animal: %s\n", hora->cpf_busca);
  printf("id do animal: %s\n", hora->id_animal);
  printf("Dia da  consulta: %d\n", hora->dd);
  printf("Mes da consulta: %d\n", hora->mm);
  printf("Ano da consulta : %d\n", hora->aa);
  printf("Hora da consulta: %d\n", hora->hora);
  printf("Minuto da consulta: %d\n", hora->min);
  }
}