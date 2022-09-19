#include <stdio.h>
#include <stdlib.h>

//Assinatura das Funções Criadas:
void tela_principal(void);
void tela_sobre(void);
void tela_dupla(void);
void menu_usuario(void);
void cadastrar_usuario(void);
void editar_horario(void);
void editar_usuario(void);
void delete_usuario(void);
void pesquisar_usuario(void);
void menu_horarios(void);
void cadastrar_horario(void);
void deletar_horario(void);


// Começo do Programa. 
int main() {

    tela_principal();
    tela_sobre();
    tela_dupla();
    menu_usuario();
    cadastrar_usuario();
    editar_usuario();
    delete_usuario();
    pesquisar_usuario();
    menu_horarios();
    cadastrar_horario();
    editar_horario();
    deletar_horario();
    

    return 0;
}

void tela_principal(void) {
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
    printf("///           |           2. Agendamentos horarios                          |   ///\n");
    printf("///           |           3. Relatorios                                     |   ///\n");
    printf("///           |           0. Sair                                           |   ///\n");
    printf("///           |                                                             |   ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =    ///\n");
    printf("///                                                                             ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    
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
    printf("///           |     Matricula:20220055255                               |       ///\n");
    printf("///           |    Felippe da Silva Guedes                              |       ///\n");
    printf("///           |     Matricula:20220068057                               |       ///\n");
    printf("///           |                                                         |       ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = = = = =        ///\n");
    printf("///                                                                             ///\n");
    printf("///                                                                             ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////////\n");
} 
void menu_usuario(void) {
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
    printf("\n");
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
    scanf("%[A-Z a-z.,0-9]",cpf);
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
    scanf("%[A-Z a-z.,0-9]",cpf);
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                     Pressione enter para continuar!                     ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    getchar();
    printf("\n");

}

void menu_horarios(void){
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
    getchar();
    printf("\n");


}