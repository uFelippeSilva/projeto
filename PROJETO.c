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
    printf("///                       4. Pesquisar Usuario                              |   ///\n");
    printf("///           |           0. Sair                                           |   ///\n");
    printf("///           |                                                             |   ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =    ///\n");
    printf("///                                                                             ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}
void cadastrar_usuario(void){
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                            Cadastro de Usuario.                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("/// Informe seu nome:                                                       ///\n");
    printf("/// Sua data de nascimento(dd/mm/ano):                                      ///\n");
    printf("/// Email:                                                                  ///\n");
    printf("/// Telefone para Contato:                                                  ///\n");
    printf("/// Cadastro Realizado Com Sucesso                                          ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}
void editar_usuario(void){
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                            Editar usuario.                              ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("/// Informe Seu Email Antigo:                                               ///\n");
    printf("/// Digite Sua Nova data de nascimento(dd/mm/ano):                          ///\n");
    printf("/// Digite Seu novo Email:                                                  ///\n");
    printf("/// Digite Seu Novo Telefone para Contato:                                  ///\n");
    printf("/// Seus Dados Foram Atualizados.                                           ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}
void delete_usuario(void){
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                            Deletar usuario.                             ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("/// Informe  Email Que Deseja Excluir::                                     ///\n");
    printf("/// Realmente deseja deletar seu cadastro?:                                 ///\n");
    printf("/// Usuario Deletando Com Sucesso.                                          ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

}
void pesquisar_usuario(void){
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                            Pesquisar usuario.                           ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("/// Informe  Email Que Deseja Pesquisar::                                   ///\n");
    printf("/// Realmente deseja deletar seu cadastro?:                                 ///\n");
    printf("/// Este Sao os dados do Usuario pesquisado:                                ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
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
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                            Cadastro de Horario Para consulta.           ///\n");
    printf("/// Informe dd/mm/ano da consulta:                                          ///\n");
    printf("/// Informe Horario da consulta:                                            ///\n");
    printf("/// Informe seu animal(gato,cachorro,etc.):                                 ///\n");
    printf("/// Informe o peso do animal:                                               ///\n");
    printf("/// Informe Qual serviço deseja:                                            ///\n");
    printf("/// Consulta Marcada Com Sucesso.                                           ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}
void editar_horario(void){
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                          Editar Horario  da Consulta.                   ///\n");
    printf("///                                                                         ///\n");
    printf("/// Informe dd/mm/ano consulta antiga:                                      ///\n");
    printf("/// Informe Horario consulta antiga:                                        ///\n");
    printf("/// Pra Quando deseja Altera consulta dd/mm/ano:                            ///\n");
    printf("/// Qual novo Horario deseja:                                               ///\n");
    printf("/// Consulta Remarcada com Sucesso.                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}
void deletar_horario(void){
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                            Deletar Consulta.                            ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("/// Informe dd/mm/ano da Consulta Que Deseja Excluir::                      ///\n");
    printf("/// Informe Horario da consulta:                                            ///\n");
    printf("/// Realmente deseja deletar sua consulta?:                                 ///\n");
    printf("/// Consulta Deletada Com Sucesso.                                          ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");


}