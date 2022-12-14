#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "modRelatorios.h"
#include "modUsuario.h"
#include"modAnimal.h"

void modulo_relatorio(void){
char opcao;
do
{
    opcao = menu_relatorio();
    switch(opcao)
    {
        case '1': 	relatorios_usu();
        break;
        case '2': 	relatorios_pet();
        break;
    } 		
}
while (opcao != '0');
}

char menu_relatorio(void) {
char op;
system("clear||cls");
printf("\n");
printf("///////////////////////////////////////////////////////////////////////////////////\n");
printf("///                                                                             ///\n");
printf("///         SIG-Pet um sistema de agendamento de consultas para pets            ///\n");
printf("///                                                                             ///\n");
printf("///////////////////////////////////////////////////////////////////////////////////\n");
printf("///                                                                             ///\n");
printf("///            = = = = sistema de agendamento de consulta para pets = = = =     ///\n");
printf("///           |                                                             |   ///\n");
printf("///           |           1. Relatorios de Usuarios                         |   ///\n");
printf("///           |           2. Relatorio do Animal                            |   ///\n");
printf("///           |           0. Voltar ao Menu Principal                       |   ///\n");
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


void relatorios_usu(void){
    char opcao;
    do
    {
        opcao = relatorio_usuario();
        switch(opcao)
        {
            case '1': 	relatorio_ordenado();
            break;
            case '2':   listaUsuarios();
            break;

        } 		
    }
    while (opcao != '0');
}
void relatorios_pet(void){
    char opcao;
    do
    {
        opcao = relatorio_animal();
        switch(opcao)
        {
            case '1': 	relatorio_ordenado();
            break;
            case '2':   listaPets();
            break;
            case '3':   listaPetsMacho();
            break;
            case '4':   listaPetsFemea();
            break;

        } 		
    }
    while (opcao != '0');
}

char relatorio_usuario(void) {
char op;
system("clear||cls");
printf("\n");
printf("///////////////////////////////////////////////////////////////////////////////////\n");
printf("///                                                                             ///\n");
printf("///            = = = Sistema de agendamento de consultas para pet = = =         ///\n");
printf("///           |                                                         |       ///\n");
printf("///           |     1. Alfabetico Dinamico                              |       ///\n");
printf("///           |     2. Listar Todos                                     |       ///\n");
printf("///           |     0. Voltar.                                          |       ///\n");
printf("///           |                                                         |       ///\n");
printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = = = = =        ///\n");
printf("///                                                                             ///\n");
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
char relatorio_animal(void) {
char op;
system("clear||cls");
printf("\n");
printf("///////////////////////////////////////////////////////////////////////////////////\n");
printf("///                                                                             ///\n");
printf("///            = = = Sistema de agendamento de consultas para pet = = =         ///\n");
printf("///           |     1. Alfabetico Dinamico                              |       ///\n");
printf("///           |     2. Listar Todos Animais                             |       ///\n");
printf("///           |     3. Animais Sexo Masculino                           |       ///\n");
printf("///           |     4. Animais Sexo Feminino                            |       ///\n");
printf("///           |     0. Voltar                                           |       ///\n");
printf("///           |                                                         |       ///\n");
printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = = = = =        ///\n");
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