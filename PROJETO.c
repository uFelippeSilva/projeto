#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//Assinatura das Funções Criadas:
char tela_principal(void);
void tela_sobre(void);
void tela_dupla(void);

//Funçoes Mod Usuario
void modulo_usuario(void);
char menu_usuario(void);
void cadastrar_usuario(void);
void editar_usuario(void);
void delete_usuario(void);
void pesquisar_usuario(void);

//Funçoes Mod Horarios
void modulo_horarios(void);
char menu_horarios(void);
void cadastrar_horario(void);
void editar_horario(void);
void deletar_horario(void);

//Funçoes Mod Animal
void modulo_animal(void);
char menu_animal(void);
void cadastrar_animal(void);
void editar_animal(void);
void pesquisar_animal(void);
void delete_animal(void);
// Começo do Programa.
int main(void) {
    char opcao;
    do {
        opcao = tela_principal();
        switch(opcao) {
            case '1':     modulo_usuario();
                          break;
            case '2':     modulo_horarios();
                          break;
            case '3':     modulo_animal();
                          break;
            
        } 	
    } while (opcao != '0');
    return 0;
}



char tela_principal(void) {
    int op;
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                             ///\n");
    printf("///         SIG-Pet um sistema de agendamento de consultas para pets            ///\n");
    printf("///                                                                             ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                             ///\n");
    printf("///            = = = = sistema de agendamento de consulta para pets = = = =     ///\n");
    printf("///           |                                                             |   ///\n");
    printf("///           |           1. menu usuario                                   |   ///\n");
    printf("///           |           2. menu consultas                                 |   ///\n");
    printf("///           |           3. menu animal                                    |   ///\n");
    printf("///           |           4. menu relatiorios                               |   ///\n");
    printf("///           |           0. Finalizar Programa                             |   ///\n");
    printf("///           |                                                             |   ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =    ///\n");
    printf("///                                                                             ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////////\n");
    printf("escolha oque deseja:\n");
    scanf("%[0-9]",&op);
    getchar();
    printf("\t\t\t<<<  Loading  >>>\n");
    sleep(1);
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
    printf("///           |           0. Sair                                           |   ///\n");
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
    printf("///           |           0. Sair                                           |   ///\n");
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
void modulo_animal(void) {
    char op;
    do {
        op = menu_animal();
        switch(op) {
            case '1': 	cadastrar_animal();
                        break;
            case '2': 	editar_animal();
                        break;
            case '3': 	delete_animal();
                        break;
            case '4': 	pesquisar_animal();
                        break;
        } 		
    } while (op != '0');
}

char menu_animal(void) {
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
    printf("///           |           1. cadastrar Animal                               |   ///\n");
    printf("///           |           2. Editar    Animal                               |   ///\n");
    printf("///           |           3. Deletar   Animal                               |   ///\n");
    printf("///           |           4. Pesquisar Animal                               |   ///\n");
    printf("///           |           0. Sair                                           |   ///\n");
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
void cadastrar_animal(void){
    char cpf [20];
    char id[20];
    char animal[20];
    char cor[20];
    char peso[20];
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                            Cadastro de Animal.                          ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("/// Informe CPF do Dono do Animal:                                          ///\n");
    printf("/// Informe ID unico Que Deseja pro Animal:                                 ///\n");
    printf("/// Informe Especie do Animal:                                              ///\n");
    printf("/// Informe Cor do Animal:                                                  ///\n");
    printf("/// Informe Peso do Animal:                                                 ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    scanf("%[0-9]",cpf);getchar();
    scanf("%[0-9]",id);getchar();
    scanf("%[A-Z a-z]",animal);getchar();
    scanf("%[A-Z a-z]",cor);getchar();
    scanf("%[0-9]",peso);getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                     Pressione enter para continuar!                     ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    getchar();
}

void editar_animal(void){
    char cpf[20];
    char id[20];
    char novo_peso[20];
    char nova_cor[20];
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                            Editar Animal.                              ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("/// Informe CPF Do Dono Do Animal:                                          ///\n");
    printf("/// Informe ID Unico do Animal:                                             ///\n");
    printf("/// Informe Novo Peso do animal:                                            ///\n");  
    printf("/// Informe Nova Cor do Animal:                                             ///\n");
    printf("/// Seus Dados Foram Atualizados!                                           ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    scanf("%[0-9]",cpf);getchar();
    scanf("%[0-9]",id);getchar();
    scanf("%[0-9]",novo_peso);getchar();
    scanf("%[A-Z a-z]",nova_cor);getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                     Pressione enter para continuar!                     ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    getchar();
    printf("\n");
}
void pesquisar_animal(void){
    printf("\n");
    char cpf[20];
    char id[20];
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                            Pesquisar Animal.                           ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("/// Informe  CPF Do Dono do Animal:                                         ///\n");
    printf("/// Informe  ID Unico Do Animal:                                            ///\n");
    printf("/// Este Sao os dados do Animal pesquisado:                                 ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    scanf("%[0-9]",cpf);getchar();
    scanf("%[0-9]",id);getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                     Pressione enter para continuar!                     ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    getchar();
    printf("\n");

}
void delete_animal(void){
    char cpf[20];
    char id[20];
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                            Deletar Animal.                              ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("/// Informe CPF Do Dono do Animal:                                          ///\n");
    printf("/// Informe ID Do Animal:                                                   ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    scanf("%[0-9]",cpf);getchar();
    scanf("%[0-9]",id);getchar();
    printf("/// Animal Deletado Com Sucesso.\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                     Pressione enter para continuar!                     ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    getchar();
    printf("\n");

}