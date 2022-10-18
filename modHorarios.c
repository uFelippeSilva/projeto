#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "modHorarios.h"
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
    char data[32];
    char horario[24];
    char animal[20];
    char peso[100];
    char servico[50];
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                    Cadastro de Horario Para consulta.                   ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("/// Informe dd/mm/ano da consulta:                                          ///\n");
    printf("/// Informe Horario da consulta:                                            ///\n");
    printf("/// Informe seu animal(gato,cachorro,etc.):                                 ///\n");
    printf("/// Informe o peso do animal:                                               ///\n");
    printf("/// Informe Qual serviço deseja:                                            ///\n");
    printf("/// Consulta Marcada Com Sucesso.                                           ///\n");
    printf("/// Informe Qual servico deseja:                                            ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    scanf("%[0-9]",data);getchar();
    scanf("%[0-9]",horario);getchar();
    scanf("%[A-Z a-z]",animal);getchar();
    scanf("%[0-9]",peso);getchar();
    scanf("%[A-Z a-z]",servico);getchar();
    printf("Consulta Marcada Com Sucesso.");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                     Pressione enter para continuar!                     ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    getchar();
    printf("\n");

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