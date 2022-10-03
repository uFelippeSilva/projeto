#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "modUsuario.h"
void modulo_usuario(void) {
    char opcao;
    do {
        opcao = menu_usuario();
        switch(opcao) {
            case '1': 	cadastrar_usuario();
                        break;
            case '2': 	editar_usuario();
                        break;
            case '3': 	delete_usuario();
                        break;
            case '4': 	pesquisar_usuario();
                        break;
        } 		
    } while (opcao != '0');
}
char menu_usuario(void) {
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
    printf("///           |           1. cadastro Usuario                               |   ///\n");
    printf("///           |           2. Editar Usuario                                 |   ///\n");
    printf("///           |           3. Deletar Usuario                                |   ///\n");
    printf("///           |           4. Pesquisar Usuario                              |   ///\n");
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

void cadastrar_usuario(void){
    char nome[50];
    char cpf [20];
    char telefone[20];
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                            Cadastro de Usuario.                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("/// Informe seu nome:                                                       ///\n");
    printf("/// Informe Seu CPF:                                                        ///\n");
    printf("/// Telefone para Contato:                                                  ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    scanf("%[A-Z a-z]",nome);getchar();
    scanf("%[0-9]",cpf);getchar();
    scanf("%[0-9]",telefone);getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                     Pressione enter para continuar!                     ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    getchar();
}
void editar_usuario(void){
    char cpf[20];
    char nome[50];
    char telefone[20];
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                            Editar usuario.                              ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("/// Informe Seu CPF:                                                        ///\n");
    printf("/// Informe Seu nome:                                                       ///\n");
    printf("/// Digite Seu Novo Telefone para Contato:                                  ///\n");  
    printf("/// Seus Dados Foram Atualizados!                                           ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    scanf("%[A-Z a-z.,0-9]",cpf);getchar();
    scanf("%[A-Z a-z]",nome);getchar();
    scanf("%[0-9]",telefone);getchar(); 
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                     Pressione enter para continuar!                     ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    getchar();
    printf("\n");
}
void delete_usuario(void){
    char cpf[20];
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                            Deletar usuario.                             ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("/// Informe CPF:                                                            ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    scanf("%[A-Z a-z.,0-9]",cpf);getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                     Pressione enter para continuar!                     ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    getchar();
    printf("\n");

}
void pesquisar_usuario(void){
    char cpf[20];
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                            Pesquisar usuario.                           ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("/// Informe  CPF Que Deseja Pesquisar::                                     ///\n");
    printf("/// Este Sao os dados do Usuario pesquisado:                                ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    scanf("%[A-Z a-z.,0-9]",cpf);getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                     Pressione enter para continuar!                     ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    getchar();
    printf("\n");
}