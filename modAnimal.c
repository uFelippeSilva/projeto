#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "modAnimal.h"
#include "validacaoProjeto.h"
void modulo_animal(void) {
    Animal* pet;

    char op;
    do {
        op = menu_animal();
        switch(op) {
            case '1': 	pet=cadastroanimal();
                        break;
            case '2': 	editar_animal();
                        break;
            case '3': 	delete_animal();
                        break;
            case '4': 	pesquisar_animal();
                        break;
        } 		
    } while (op != '0');
    free(pet);
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
Animal* cadastroanimal() 
{
 Animal* anm;
 anm = (Animal*) malloc(sizeof(Animal));
 do
    {
        printf(" | Informe o cpf do usuario: ");
        scanf(" %20[^\n]", anm->cpf);
        getchar();
        
    } while (!validaCpf(anm->cpf));
printf (" Innforme a Raca do  animal:");
scanf(" %20[^\n]", anm->animal);
printf("Informe Cor do Animal:");
scanf(" %20[^\n]", anm->cor);
do
    {
        printf(" | Informe o ID Unico Que Deseja Para o Animal: ");
        scanf(" %15[^\n]", anm->id);
        getchar();
        
    } while (!validaTelefone(anm->id));
return anm;

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