#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "modAnimal.h"
#include "modSobre.h"
#include "modUsuario.h"
#include "modHorarios.h"
#include "modServico.h"
#include "modRelatorios.h"
#include "validacaoProjeto.h"

//Compile os .h -> gcc -c -Wall *.h
//Compile os .c -> gcc -c -Wall *.c
//                 gcc -o test *.o
//                  ./test

//Assinatura das Funções Criadas:
char tela_principal(void);





// Começo do Programa.
int main(void) {
char opcao;
do
{
    opcao = tela_principal();
    switch(opcao)
    {
        case '1':     modulo_usuario();
        break;
        case '2':     modulo_servico();
        break;
        case '3':     modulo_animal();
        break;
        case '4':     modulo_horarios();
        break;      
        case '5':     modulo_sobre();   
        break;
        case '6':     modulo_relatorio();
        break;                        
    } 	
}
while (opcao != '0');
return 0;
}



char tela_principal(void) {
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
printf("///           |           1. Menu Usuario                                   |   ///\n");
printf("///           |           2. Menu Servicos                                  |   ///\n");
printf("///           |           3. Menu Animal                                    |   ///\n");
printf("///           |           4. Menu Consultas                                 |   ///\n");
printf("///           |           5. menu sobre Projeto Criadores                   |   ///\n");
printf("///           |           6. Menu Relatorios                                |   ///\n");
printf("///           |           0. Finalizar Programa                             |   ///\n");
printf("///           |                                                             |   ///\n");
printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =    ///\n");
printf("///                                                                             ///\n");
printf("///////////////////////////////////////////////////////////////////////////////////\n");
printf("escolha oque deseja:\n");
scanf("%c", &op);
getchar();
printf("\t\t\t<<<  Loading  >>>\n");
sleep(1);
printf("\n");

return op;

}