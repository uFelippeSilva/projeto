#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "modSobre.h"

void modulo_sobre(void) {
char opcao;
do
{
    opcao = menu_sobre();
    switch(opcao)
    {
        case '1': 	tela_sobre();
                    break;
        case '2': 	tela_dupla();
                    break;
    } 		
}
while (opcao != '0');
}

char menu_sobre(void) {
system("clear||cls");
char op;
printf("\n");
printf("///////////////////////////////////////////////////////////////////////////////////\n");
printf("///                                                                             ///\n");
printf("///         SIG-Pet um sistema de agendamento de consultas para pets            ///\n");
printf("///                                                                             ///\n");
printf("///////////////////////////////////////////////////////////////////////////////////\n");
printf("///                                                                             ///\n");
printf("///            = = = = sistema de agendamento de consulta para pets = = = =     ///\n");
printf("///           |                                                             |   ///\n");
printf("///           |           1. Sobre o Projeto                                |   ///\n");
printf("///           |           2. Dupla Do Projeto                               |   ///\n");
printf("///           |           0. Voltar Menu Principal                          |   ///\n");
printf("///           |                                                             |   ///\n");
printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =    ///\n");
printf("///                                                                             ///\n");
printf("///////////////////////////////////////////////////////////////////////////////////\n");
printf("escolha oque deseja:\n");
scanf("%c",&op);
getchar();
printf("\n");
return op;
}

void tela_sobre(void) {
printf("\n");
printf("///////////////////////////////////////////////////////////////////////////////////\n");
printf("///                                                                             ///\n");
printf("///             As clinicas para atendimento a pequenos animais                 ///\n");
printf("///              sao cada vez mais populares.                                   ///\n");
printf("///             O presente projeto tem como objetivo propor um progama          ///\n");
printf("///              de computaodr que implemente funcionalidades basicas           ///\n");
printf("///              relacionas ao agendamento de consultas de pequenos animais,    ///\n");
printf("///              armazenando tanto informacoes do pet quanto do seu dono.       ///\n");
printf("///                                                                             ///\n");
printf("///////////////////////////////////////////////////////////////////////////////////\n");
}
void tela_dupla(void) {
printf("\n");
printf("///////////////////////////////////////////////////////////////////////////////////\n");
printf("///                                                                             ///\n");
printf("///            = = = Sistema de agendamento de consultas para pet = = =         ///\n");
printf("///           |                                                         |       ///\n");
printf("///           |   Este projeto exemplo foi desenvolvido por:            |       ///\n");
printf("///           |                                                         |       ///\n");
printf("///           |    Davi Natan Vieira de oliveira                        |       ///\n");
printf("///           |    Matricula:20220055255                                |       ///\n");
printf("///           |    Felippe da Silva Guedes                              |       ///\n");
printf("///           |    Matricula:20220068057                                |       ///\n");
printf("///           |                                                         |       ///\n");
printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = = = = =        ///\n");
printf("///                                                                             ///\n");
printf("///                                                                             ///\n");
printf("///////////////////////////////////////////////////////////////////////////////////\n");
} 
