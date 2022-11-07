#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "modUsuario.h"
#include "validacaoProjeto.h"
void modulo_usuario(void) {
    Usuario* fulano;
    char opcao;
    do {
        opcao = menu_usuario();
        switch(opcao) {
            case '1': 	fulano = cadastroUsuario();
                        gravaUsuario(fulano);
                        free(fulano);
                        break;
            case '2': 	editar_usuario();
                        break;
            case '3': 	delete_usuario();
                        break;
            case '4': 	pesquisar_usuario();
                        break;
            case '5': 	exibeUsuario(fulano);
                        break;            
        } 		
    } while (opcao != '0');
    free(fulano);
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
    printf("///           |           5. Usuarios Cadastrados                           |   ///\n");
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

Usuario* cadastroUsuario() {
 Usuario* usu;
 usu = (Usuario*) malloc(sizeof(Usuario));

  do
    {
        printf(" | Informe o nome do usuario: ");
        scanf(" %51[^\n]", usu->nome);
        getchar();
        
    } while (!validaNome(usu->nome));

do
    {
        printf(" | Informe o cpf do usuario: ");
        scanf(" %20[^\n]", usu->cpf);
        getchar();
        
    } while (!validaCpf(usu->cpf));

do
    {
        printf(" | Informe o Telefone do usuario: ");
        scanf(" %15[^\n]", usu->telefone);
        getchar();
        
    } while (!validaTelefone(usu->telefone));
    usu->status = 'a';

return usu;
}
void exibeUsuario(const Usuario* usu) {
    char situacao[20];
    printf("\n= = = Usuario Cadastrado = = =\n");
    printf("Nome do Usuario: %s\n", usu->nome);
    printf("CPF do Usuario: %s\n", usu->cpf);
    printf("Telefone do Usuario: %s\n", usu->telefone);
    if (usu->status == 'a'){
    strcpy(situacao, "cadastrado");
    } else if (usu->status == 'x') {
    strcpy(situacao, "nao cadastrado");
    } else {
    strcpy(situacao, "Não informada");
    }
    printf("Situação do usuario: %s\n", situacao);

}

void gravaUsuario(Usuario* usu) {
  FILE* fp;
  fp = fopen("usuarios.dat", "ab");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar este programa...\n");
    exit(1);
  }
  fwrite(usu, sizeof(Usuario), 1, fp);
  fclose(fp);
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