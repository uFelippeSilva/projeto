#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "modServico.h"
#include "validacaoProjeto.h"
void modulo_servico(void) {
    char opcao;
    do {
        opcao = menu_servico();
        switch(opcao) {
            case '1': 	cadastraservico(); //Cadastrar Serviço!.
                        break;
            case '2': 	buscaservico(); //Pesquisar Por um Serviço Cadastrado!.
                        break;
            case '3': 	atualizarservico();//Parte de Atualizar um Serviço desejado.
                        break;
            case '4': 	deletarservico();//Deletando Serviço de Maneira Logica.
                        break;
            case '5': 	listaServicos();//Ira Listar Os Serviços Cadastrado no Sistema.!
                        break;            
        } 		
    }
while (opcao != '0');
}


char menu_servico(void) {
char op;
system ( " clear||cls " );
printf("\n");
printf("///////////////////////////////////////////////////////////////////////////////////\n");
printf("///                                                                             ///\n");
printf("///         SIG-Pet um sistema de agendamento de consultas para pets            ///\n");
printf("///                                                                             ///\n");
printf("///////////////////////////////////////////////////////////////////////////////////\n");
printf("///                                                                             ///\n");
printf("///            = = = = sistema de agendamento de consulta para pets = = = =     ///\n");
printf("///           |                                                             |   ///\n");
printf("///           |           1. Cadastrar Servico                              |   ///\n");
printf("///           |           2. Pesquisar Servico                              |   ///\n");
printf("///           |           3. Editar Servico                                 |   ///\n");
printf("///           |           4. Deletar Servico                                |   ///\n");
printf("///           |           5. Servicos Prestados                             |   ///\n");
printf("///           |           0. Voltar Menu Princpal                           |   ///\n");
printf("///           |                                                             |   ///\n");
printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =    ///\n");
printf("///                                                                             ///\n");
printf("///////////////////////////////////////////////////////////////////////////////////\n");
printf("escolha oque deseja:\n");
scanf("%c",&op);
getchar();
printf("\n");
printf("\t\t\t<<< ... Loading ... >>>\n");
sleep(1);

return op;
}
void cadastraservico(void)
{
system ( " clear||cls " );
Servicos* ser;
ser = (Servicos*) malloc(sizeof(Servicos));

printf(" | ========================================================= | \n");
printf(" | --------------------------------------------------------- | \n");
printf(" |                   Cadastrar Servico                       | \n");
printf(" | --------------------------------------------------------- | \n");
printf(" | ========================================================= | \n");
do
{
  printf("Informe o nome do Servico: ");
  scanf(" %19[^\n]", ser->nome);
  getchar();     
}
while (!validaPalavra(ser->nome));
do
{
  printf("Informe o ID do Servico: ");
  scanf(" %3[^\n]", ser->id_servico);
  getchar();   
} 
while (!(ser->id_servico));

printf("Informe o Valor do Servico: ");
scanf(" %9[^\n]", ser->valor);
getchar();

printf("Informe o Tempo Gasto do Servico: ");
scanf(" %9[^\n]", ser->tempo);
getchar();

ser->status = 'a';
gravaServico(ser);
free(ser);

printf("Servico Cadastrado com Sucesso.!");
printf("Pressione qualquer tecla para sair.... ");
getchar();
}

void buscaservico(void)
{
system ( " clear||cls " );
FILE* fp;
Servicos* ser;
int achou;
char id_busca[10];
fp = fopen("servicos.dat", "rb");

if (fp == NULL) 
  {
    printf("Ops! Erro na abertura do arquivo!\n");
    exit(1);
  }
printf(" | ========================================================= | \n");
printf(" | --------------------------------------------------------- | \n");
printf(" |                   Buscar Servico                          | \n");
printf(" | --------------------------------------------------------- | \n");
printf(" | ========================================================= | \n");
  
printf("\n = Buscar Servico  = \n"); 
printf("Informe ID do Servico: "); 
scanf(" %9[^\n]", id_busca);
ser = (Servicos*) malloc(sizeof(Servicos));
achou = 0;
while((!achou) && (fread(ser,sizeof(Servicos), 1, fp))) 
  {
    if ((strcmp(ser->id_servico, id_busca) == 0) && (ser->status != 'x'))
      {
      achou =1;
      }
  }
if (achou)
  {
  exibeservico(ser);
  }
else 
  {
    printf("Os dados do usuario nao foram encontrados\n");
  }
fclose(fp);
free(ser);
printf("Pressione qualquer tecla para sair.... ");
getchar();
getchar();
}

void atualizarservico(void)
{
system ( " clear||cls " );
FILE* fp;
Servicos* ser;
int achou;
char resp;
char id_busca[10];
ser = (Servicos*) malloc(sizeof(Servicos));
achou = 0;
fp = fopen("servicos.dat", "r+b");
if (fp == NULL)
{
  printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
  printf("Não é Póssivel Continuar o Programa...\n");
  exit(1);
}
  printf(" | ========================================================= | \n");
  printf(" |                                                           | \n");
  printf(" |                     Atualizar Serviço                     | \n");
  printf(" |                                                           | \n");
  printf(" | ========================================================= | \n");
  printf("Digite o ID do Serviço Cadastrado:");
  scanf("%s", id_busca);
  getchar();
while((!achou) && (fread(ser, sizeof(Servicos), 1, fp))){
  if ((strcmp(ser->id_servico, id_busca) == 0) && (ser->status == 'a')){
    achou = 1;
  }
}
if (achou) 
{
exibeservico(ser);
printf(" Deseja realmente editar este Serviço? [s/n] ");
scanf("%c", &resp);
getchar();
if (resp == 's' || resp == 'S')
  { 
    printf("Informe o Novo Valor Do Serviço: ");
    scanf(" %9[^\n]", ser->valor);
    getchar();    
    printf("Informe o Tempo Que Estima-se Gastar neste Serviço:");
    scanf(" %9[^\n]", ser->tempo);
    getchar();
    ser->status = 'a';
    fseek(fp, (-1)*sizeof(Servicos), SEEK_CUR);
    fwrite(ser, sizeof(Servicos), 1, fp);
    printf("\n Serviço Editado com Sucesso!!!\n");
    gravaServico(ser);
    printf("Pressione qualquer tecla para sair... ");
    getchar();
  }
  else
    {
      printf("Os Dados Não Foram Alterados!\n");
      printf("Pressione qualquer tecla para sair...");
      getchar();
    }
    } else {
    printf("Serviço Não encontrado!\n");
    printf("Pressione qualquer tecla para sair...");
    getchar();
  }
free(ser);
fclose(fp);
}     

void deletarservico(void){
system ( " clear||cls " );
FILE* fp;
Servicos* ser;
int achou;
char resp;
char id_busca[10];
fp = fopen("servicos.dat", "r+b");

  if (fp == NULL)
    {
      printf("Ops! Erro na abertura do arquivo!\n");
      exit(1);
    }
  ser = (Servicos*) malloc(sizeof(Servicos));
  printf(" | ============================================================== | \n");
  printf(" |                                                                | \n");
  printf(" |                        Excluir Serviço                         | \n");
  printf(" |                                                                | \n");
  printf(" | ============================================================== | \n");
  printf("Informe o ID do Servico que Você quer Excluir:");
  scanf("%s", id_busca);
  getchar();
  achou=0;
  while ((!achou) && (fread(ser, sizeof(Servicos), 1, fp))){
  if ((strcmp(ser->id_servico, id_busca) == 0) && (ser->status == 'a'))
    {
      achou = 1;
    }
  }
  if (achou)
  {
  exibeservico(ser);
  printf("Deseja Realmente Excluir os Dados Deste Serviço? (s/n)");
  scanf("%c", &resp);
  getchar();
    if (resp == 's' || resp == 'S')
      {
      ser->status = 'x';
      fseek(fp, (-1)*sizeof(Servicos), SEEK_CUR);
      fwrite(ser, sizeof(Servicos), 1, fp);
      printf("\n Serviço Excluido com Sucesso!");
      gravaServico(ser);
      printf("Pressione qualquer tecla para sair... ");
      getchar();
      }
    else
      {
        printf("\nTudo Bem, os Dados Não Foram Alterados!");
      }
  }
  else
    {
      printf("O Usuário Não foi Encontrado!");
    }
  free(ser);
  fclose(fp);
  printf("Pressione qualquer tecla para sair.... ");
  getchar();  
}

void gravaServico(Servicos* ser) {
system("clear||cls");
FILE* fp;
fp = fopen("servicos.dat", "ab");
if (fp == NULL)
{
printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
printf("Não é possível continuar este programa...\n");
}
fwrite(ser, sizeof(Servicos), 1, fp);
fclose(fp);
}

void exibeservico(Servicos* ser){
  system("clear||cls");
  {
    printf("\n= = = Serviço Cadastrado = = =\n");
    printf("Nome do Serviço: %s\n", ser->nome);
    printf("ID do Serviço: %s\n", ser->id_servico);
    printf("Valor do Serviço: %s\n", ser->valor);
    printf("Tempo Estimado Para Realização do Serviço: %s\n", ser->tempo);
    printf("Status:%c\n", ser->status);  
  }
}

void listaServicos(void) {
system ( " clear||cls " );
FILE* fp;
Servicos* ser;
printf("\n = Lista de Serviços Prestados. = \n"); 
ser = (Servicos*) malloc(sizeof(Servicos));
fp = fopen("servicos.dat", "rb");
if (fp == NULL)
{
printf("Ops! Ocorreu um Erro na Abertura do Arquivo!\n");
printf("Não é Póssivel Continuar este Programa...\n");
exit(1);
printf("\n\n");
printf(" | ---------------------- Exibe Serviços Cadastrado -------------------- | \n");
printf(" |                                                                       | \n");
printf(" | --------------------------------------------------------------------- | \n");
}
while(fread(ser, sizeof(Servicos), 1, fp))
{
if (ser->status != 'x')
{
exibeservico(ser);
}
}
fclose(fp);
free(ser);
printf("Pressione qualquer tecla para sair.... ");
getchar();
getchar();
}
int buscaservico_file(char*id_busca){
system ( " clear||cls " );
FILE* fp;
Servicos* ser;
int achou;
  fp = fopen("servicos.dat", "rb");

    if (fp == NULL) {
        printf("Ops! Erro na Abertura do Arquivo!\n");
        exit(1);
    }

    printf(" | ========================================================= | \n");
    printf(" |                                                           | \n");
    printf(" |                   Buscar Serviço                          | \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");

  ser = (Servicos*) malloc(sizeof(Servicos));
  achou = 0;
  while((!achou) && (fread(ser,sizeof(Servicos), 1, fp))) {
    if ((strcmp(ser->id_servico, id_busca) == 0) && (ser->status != 'x'))
    {
      achou =1;
    }
}
if (achou) {
    exibeservico(ser);
    fclose(fp);
    free(ser);
    return 1;
}else {
    printf("Os Dados do Usuário Não Foram Encontrados\n");
    fclose(fp);
    free(ser);
    return 0;
}
}
