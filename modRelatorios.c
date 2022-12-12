#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "modRelatorios.h"
#include "modUsuario.h"

void modulo_relatorio(void){
char opcao;
do
{
    opcao = menu_relatorio();
    switch(opcao)
    {
        case '1': 	relatorios_usu();
        break;
        case '2': 	relatorio_animal();
        break;
    } 		
}
while (opcao != '0');
}

char menu_relatorio(void) {
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

char relatorio_usuario(void) {
    char op;
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                             ///\n");
    printf("///            = = = Sistema de agendamento de consultas para pet = = =         ///\n");
    printf("///           |                                                         |       ///\n");
    printf("///           |     1. Alfabetico dinamico                              |       ///\n");
    printf("///           |     2. Listar Todos                                     |       ///\n");
    printf("///           |     3.                                                  |       ///\n");
    printf("///           |     Flavius Gorgonio                                    |       ///\n");
    printf("///           |     Ensinar Nos Meros Humanos                           |       ///\n");
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

void relatorio_animal(void) {
printf("\n");
printf("///////////////////////////////////////////////////////////////////////////////////\n");
printf("///                                                                             ///\n");
printf("///            = = = Sistema de agendamento de consultas para pet = = =         ///\n");
printf("///           |     Relatorio de Animal                                 |       ///\n");
printf("///           |     Estara Disponivel em Breve                          |       ///\n");
printf("///           |     Quando Nosso Professor                              |       ///\n");
printf("///           |     Flavius Gorgonio                                    |       ///\n");
printf("///           |     Ensinar Nos Meros Humanos                           |       ///\n");
printf("///           |     Armazenar Dados.                                    |       ///\n");
printf("///           |                                                         |       ///\n");
printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = = = = =        ///\n");
printf("///                                                                             ///\n");
printf("///                                                                             ///\n");
printf("///////////////////////////////////////////////////////////////////////////////////\n");
} 