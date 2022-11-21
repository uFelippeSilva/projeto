#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "modAnimal.h"
#include "modUsuario.h"
#include "validacaoProjeto.h"
void modulo_animal(void) {
    char op;
    do {
        op = menu_animal();
        switch(op) {
            case '1': 	cadastraranimal();
                        break;
            case '2': 	buscapet();
                        break;
            case '3': 	editapet();
                        break;
            case '4': 	excluipet();
                        break;
            case '5':   listaPets();
        } 		
    } while (op != '0');
}

char menu_animal(void) {
    char op;
    system ( " clear||cls " );
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
    printf("///           |           2. Pesquisar Animal                               |   ///\n");
    printf("///           |           3. Editar Animal                                  |   ///\n");
    printf("///           |           4. Deletar Animal                                 |   ///\n");
    printf("///           |           5. Listar Todos Pet                               |   ///\n");
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

void cadastraranimal(void){
Animal* pet;
pet = (Animal*) malloc(sizeof(Animal));
Usuario* usu;
usu = (Usuario*) malloc(sizeof(Usuario));
int achou;
achou=0;
char cpf_busca_dig[13];
do
{
usu = usuario_busca();
    if (usu != NULL)
        {
            achou = 1;
        }
    else
        {
            printf("Nao encontrado, Digite novamente\n");
            achou = 0;
        }
}
while(achou == 0);
strcpy(pet-> cpf, usu -> cpf);
strcpy(cpf_busca_dig, pet->cpf);
system("cls||clear");
printf(" | ========================================================= | \n");
printf(" | --------------------------------------------------------- | \n");
printf(" |                   Cadastrar Animal                        | \n");
printf(" | --------------------------------------------------------- | \n");
printf(" | ========================================================= | \n");
do
{
    printf("Informe o nome do animal: ");
    scanf(" %19[^\n]", pet->animal);
    getchar();
}
while (!validaPalavra(pet->animal));
do
{
    printf("Informe A Raca do animal: ");
    scanf(" %19[^\n]", pet->raca);
    getchar();
}
while (!validaPalavra(pet->raca));
printf("Informe o codigo Unico do Animal: ");
scanf(" %9[^\n]", pet->codigo);
getchar();
printf("Informe o sexo do animal (M/F): ");
scanf("%c", &pet->sexo);
pet->status = 'a';
gravaPet(pet);
free(pet);
printf("Pressione qualquer tecla para sair.... ");
getchar();
}  

void buscapet(void){
system ( " clear||cls " );
FILE* fp;
Animal* pet;
int achou;
char cpf_busca[20];
char id_pet[10];
fp = fopen("animais.dat", "rb");
if (fp == NULL)
    {
        printf("Ops! Erro na abertura do arquivo!\n");
        exit(1);
    }
printf("\n = Buscar PET = \n"); 
printf("Informe CPF Do Dono Do ANIMAL: "); 
scanf(" %19[^\n]", cpf_busca);
printf("Informe Codigo do ANIMAL:");
scanf(" %9[^\n]", id_pet);
pet = (Animal*) malloc(sizeof(Animal));
achou = 0;
while ((!achou) && (fread(pet, sizeof(Animal), 1, fp)))
    {
    if ((strcmp(pet->cpf, cpf_busca) == 0) && ((strcmp(pet->codigo,id_pet)==0) &&(pet->status =='a')))
        {
        achou=1;
        }
    }
if (achou)
    {
        exibepet(pet);
    }
else
    {
        printf("Os dados do Pet nao foram encontrados\n");
    }
fclose(fp);
free(pet);
printf("Pressione qualquer tecla para sair.... ");
getchar();
getchar();
}

void editapet(void){
system ( " clear||cls " );
FILE* fp;
Animal* pet;
int achou;
char resp;
char cpf_busca[20];
char id_pet[10];
pet = (Animal*) malloc(sizeof(Animal));
achou=0;
fp= fopen("animais.dat","r+b");
if (fp == NULL)
    {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Nao e possivel continuar o programa...\n");
        exit(1);
    }
printf(" | ========================================================= | \n");
printf(" | --------------------------------------------------------- | \n");
printf(" | ------------------- Atualizar Animal -------------------  | \n");
printf(" | --------------------------------------------------------- | \n");
printf(" | ========================================================= | \n");
printf("Digite o CPF Do Dono do Animal cadastrado:");
scanf("%s", cpf_busca);
getchar();
printf("Informe O ID Unico do Animal cadastrado:");
scanf("%s", id_pet);
while ((!achou) && (fread(pet, sizeof(Animal), 1, fp)))
    {
        if ((strcmp(pet->cpf, cpf_busca) == 0) && ((strcmp(pet->codigo,id_pet)==0) &&(pet->status =='a')))
            {
                achou=1;
            }
    }
if(achou)
{
        exibepet(pet);
        printf("Deseja realmente editar este usuario?[s/n]");
        scanf("%c",&resp);
        getchar();
    if (resp == 's' || resp == 'S')
    {
        do
            {
                printf("Informe o nome do animal: ");
                scanf(" %19[^\n]", pet->animal);
                getchar();        
            }while (!validaPalavra(pet->animal)); 
        do
            {
                printf("Informe o CPF Do Dono Do Animal: ");
                scanf(" %20[^\n]", pet->cpf);
                getchar();       
            }while (!validaCpf(pet->cpf));
        do
            {
                printf("Informe A Raca do animal: ");
                scanf(" %19[^\n]", pet->raca);
                getchar();    
            }while (!validaPalavra(pet->raca));
        printf("Informe o codigo Unico do Animal: ");
        scanf("%s", pet->codigo);
        getchar();
        printf("Informe o sexo do Animal (M/F): ");
        scanf("%c", &pet->sexo);
        pet->status = 'a';
        fseek(fp, (-1)*sizeof(Animal), SEEK_CUR);
        fwrite(pet, sizeof(Animal), 1, fp);
        printf("\nPet editado com sucesso!!!\n");
        gravaPet(pet);
        printf("Pressione qualquer tecla para sair... ");
        getchar();
    } 
        else
            {
            printf("Tudo bem, os dados nao foram alterados!");
            }
} 
free(pet);
fclose(fp);
}  

void excluipet(void){
system ( " clear||cls " );
FILE* fp;
Animal* pet;
int achou;
char resp;
char cpf_busca[20];
char id_pet[10];
fp= fopen("animais.dat","r+b");
if(fp == NULL)
    {
        printf("Ops! Erro na abertura do arquivo!\n");
        exit(1);
    }
pet = (Animal*) malloc(sizeof(Animal));
printf(" | ============================================================== | \n");
printf(" | -------------------------------------------------------------- | \n");
printf(" | ---------------------- Excluir Animal ------------------------ | \n");
printf(" | -------------------------------------------------------------- | \n");
printf(" | ============================================================== | \n");
printf("Informe o CPF do Dono do Animal que voce quer excluir: ");
scanf("%s", cpf_busca);
getchar();
printf("Informe ID Unico do Animal que voce deseja excluir:");
scanf("%s", id_pet);
getchar();  
achou=0;    
while ((!achou) && (fread(pet, sizeof(Animal), 1, fp)))
    {
        if ((strcmp(pet->cpf, cpf_busca) == 0) && ((strcmp(pet->codigo,id_pet)==0) &&(pet->status =='a')))
            {
                achou=1;
            }
    }
if(achou)
{
exibepet(pet);
printf("Deseja realmente excluir os dados deste usuario?(s/n)");
scanf("%c", &resp);
    if (resp == 's' || resp == 'S')
        {
            pet->status = 'x';
            fseek(fp, (-1)*sizeof(Animal), SEEK_CUR);
            fwrite(pet, sizeof(Animal), 1, fp);
            printf("\nUsuário excluido com sucesso!");
            gravaPet(pet);
            printf("Pressione qualquer tecla para sair... ");
            getchar();
        }
    else
        {
            printf("\nTudo bem, os dados nao foram alterados!");
        }
}
else
    {
        printf("O usuario nao foi encontrado!");
    }
free(pet);
fclose(fp);
printf("Pressione qualquer tecla para sair.... ");
getchar(); 
}

void gravaPet(Animal* pet){
FILE* fp;
fp = fopen("animais.dat","ab");
if (fp == NULL)
    {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Nao e possivel continuar este programa...\n");
        exit(1);
    }
fwrite(pet, sizeof(Animal),1,fp);
fclose(fp);    
}

void listaPets(void){
system ( " clear||cls " );
FILE* fp;
Animal* pet;
pet = (Animal*) malloc(sizeof(Animal));
fp = fopen("animais.dat","rb");
if (fp == NULL)
    {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Nao e possivel continuar este programa...\n");
        exit(1);
    }
printf("\n\n");
printf(" | ----------------------- Lista Pets ---------------------- | \n");
printf(" |                                                           | \n");
printf(" | --------------------------------------------------------- | \n");
while(fread(pet, sizeof(Animal), 1, fp))
    {
        if (pet->status != 'x')
                {
                exibepet(pet);
                }
    }
fclose(fp);
free(pet);
getchar();
getchar();
}
void exibepet(Animal* pet)
{
    {
        printf("\n= = = Pet Cadastrado = = =\n");
        printf("Nome do Pet: %s\n", pet->animal);
        printf("CPF do Dono do Pet: %s\n", pet->cpf);
        printf("Raça do Pet: %s\n", pet->raca);
        printf("ID Unico do Pet:%s\n", pet->codigo);
        printf("Sexo do Animal:%c\n", pet->sexo);
        printf("Status:%c\n", pet->status);
    }
}