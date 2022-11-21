#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "modHorarios.h"
#include "modAnimal.h"
#include "modServico.h"
#include "validacaoProjeto.h"
void modulo_horarios(void) {
    char opcao;
    do {
        opcao = menu_horarios();
        switch(opcao) {
            case '1': 	cadastrar_horario();
                        break;
            case '2': 	editar_horario();
                        break;
            case '3': 	deletar_horario();
                        break;
        } 		
    } while (opcao != '0');
}
char menu_horarios(void){
    char op;
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                             ///\n");
    printf("///         SIG-Pet um sistema de agendamento de consultas para pets            ///\n");
    printf("///                                                                             ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                             ///\n");
    printf("///            = = = = sistema de agendamento de Horarios para pets = = = =     ///\n");
    printf("///           |                                                             |   ///\n");
    printf("///           |           1. Cadastrar Horario                              |   ///\n");
    printf("///           |           2. Editar Horario                                 |   ///\n");
    printf("///           |           3. Deletar Horario                                |   ///\n");
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
    } while (a == 0);
do
    {
      printf(" | Informe o ID do Serviço: ");
        scanf(" %4[^\n]", hora->id_servico);
      getchar();
      b = buscaservico_file(hora->id_servico);
    } while (b ==0);

do {
        printf(" Digite o dia do Serviço: ");
        scanf("%d", &hora->dd);
        getchar();
        printf(" Digite o Mês do Serviço: ");
        scanf("%d", &hora->mm);
        getchar();
        printf(" digite o Ano do Serviço: ");
        scanf("%d", &hora->aa);
        getchar();
        
    } while(!validaData(hora->dd, hora->mm, hora->aa));
do {
        printf(" Digite a Hora do Serviço: ");
        scanf("%d", &hora->hora);
        getchar();
        printf(" Digite o Minuto do Serviço: ");
        scanf("%d", &hora->min);
        getchar();
        
    } while(!validaHora(hora->hora, hora->min));
    printf("Informe id da consulta 6 Digitos: ");
    scanf(" %s",&hora->id_consulta);
    hora->status='a';
printf("Consulta Cadastrado com Sucesso.!");
printf("Pressione qualquer tecla para sair.... ");
getchar();

}
void editar_horario(void){
    char data[32];
    char horario[24];
    char data2[32];
    char horario2[24];
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                          Editar Horario  da Consulta.                   ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("/// Informe dd/mm/ano consulta antiga:                                      ///\n");
    printf("/// Informe Horario consulta antiga:                                        ///\n");
    printf("/// Pra Quando deseja Altera consulta dd/mm/ano:                            ///\n");
    printf("/// Qual novo Horario deseja:                                               ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    scanf("%[0-9]",data);getchar();
    scanf("%[0-9]",horario);getchar();
    scanf("%[0-9]",data2);getchar();
    scanf("%[0-9]",horario2);getchar();
    printf("Consulta Remarcada com Sucesso.");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                     Pressione enter para continuar!                     ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    getchar();
    printf("\n");

}

void deletar_horario(void){
    char data[32];
    char horario[24];
    char deletar[10];
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                            Deletar Consulta.                            ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("/// Informe dd/mm/ano da Consulta Que Deseja Excluir::                      ///\n");
    printf("/// Informe Horario da consulta:                                            ///\n");
    printf("/// Realmente deseja deletar sua consulta?:                                 ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    scanf("%[0-9]",data);getchar();
    scanf("%[0-9]",horario);getchar();
    scanf("%[A-Z a-z]",deletar);getchar();
    printf("Consulta Deletada Com Sucesso.");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                     Pressione enter para continuar!                     ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}



void gravaConsulta(Horario* hora) {
  FILE* fp;
  fp = fopen("consultas.dat", "ab");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar este programa...\n");
    exit(1);
  }
  fwrite(hora, sizeof(Horario), 1, fp);
  fclose(fp);
}

void exibeconsulta(Horario* hora) {
    
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