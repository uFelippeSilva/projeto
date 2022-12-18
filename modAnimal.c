#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
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
                        break;
            case '6':   ListaPetCPF();
                        break;
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
printf("///           |           6. Listar Pets Por CPF                            |   ///\n");
printf("///           |           0. Voltar Menu Principal                          |   ///\n");
printf("///           |                                                             |   ///\n");
printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =    ///\n");
printf("///                                                                             ///\n");
printf("///////////////////////////////////////////////////////////////////////////////////\n");
printf("\n");
printf("escolha oque deseja:\n");
scanf("%c",&op);
getchar();
system("clear||cls");
printf("///////////////////////////////////////////////////////////////////////////////////\n");
printf("///                                                                             ///\n");
printf("///             |-----------------------------------------|                     ///\n");
printf("///             |>>>>>>>>>>                               |                     ///\n");
printf("///             |-----------------------------------------|                     ///\n");
printf("///                                                                             ///\n");
printf("///////////////////////////////////////////////////////////////////////////////////\n");
sleep(1);
system("clear||cls");
printf("///////////////////////////////////////////////////////////////////////////////////\n");
printf("///                                                                             ///\n");
printf("///             |-----------------------------------------|                     ///\n");
printf("///             |>>>>>>>>>>>>>>>>>>>>>>>>>>>>>            |                     ///\n");
printf("///             |-----------------------------------------|                     ///\n");
printf("///                                                                             ///\n");
printf("///////////////////////////////////////////////////////////////////////////////////\n");
sleep(1);
system("clear||cls");
printf("///////////////////////////////////////////////////////////////////////////////////\n");
printf("///                                                                             ///\n");
printf("///             |-----------------------------------------|                     ///\n");
printf("///             |>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|                     ///\n");
printf("///             |-----------------------------------------|                     ///\n");
printf("///                                                                             ///\n");
printf("///////////////////////////////////////////////////////////////////////////////////\n");
sleep(1);
return op;
}

void cadastraranimal(void){
char peso[10];
int tam;
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
            printf("Não encontrado, Digite novamente\n");
            achou = 0;
        }
}
while(achou == 0);
strcpy(pet-> cpf, usu -> cpf);
strcpy(cpf_busca_dig, pet->cpf);
system("cls||clear");
printf(" | ========================================================= | \n");
printf(" |                                                           | \n");
printf(" |                   Cadastrar Animal                        | \n");
printf(" |                                                           | \n");
printf(" | ========================================================= | \n");
do
{
    printf("Informe o Nome do animal: ");
    scanf(" %19[^\n]", pet->animal);
    getchar();
}
while (!validaPalavra(pet->animal));
do
{
    printf("Informe A Raça do animal: ");
    scanf(" %19[^\n]", pet->raca);
    getchar();
}
while (!validaPalavra(pet->raca));
do{
printf("Informe o Peso do Animal: ");
scanf(" %9[^\n]", peso);
getchar();
tam=strlen(peso);
if (!validar_peso(peso, tam)){
  printf("Peso inserido esta incorreto com a validacao.\n");
}
}
while (!validar_peso(peso, tam));
pet->peso = atof(peso);

pet->id_animal=idAnimal();
printf("Informe o Sexo do Animal (M/F): ");
scanf("%c", &pet->sexo);
getchar();
pet->sexo = toupper(pet->sexo);
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
int id;
fp = fopen("animais.dat", "rb");
if (fp == NULL){
    printf("Ops! Erro na abertura do arquivo!\n");
    exit(1);
}
printf("\n = Buscar PET = \n"); 
printf("Informe CPF Do Dono Do Animal: "); 
scanf(" %19[^\n]", cpf_busca);
getchar();
printf("Informe ID do Animal:");
scanf(" %9[^\n]", id_pet);
getchar();
id=atoi(id_pet);
pet = (Animal*) malloc(sizeof(Animal));
achou = 0;
while ((!achou) && (fread(pet, sizeof(Animal), 1, fp))){
    if ((strcmp(pet->cpf, cpf_busca) == 0) && ((pet->id_animal==id) &&(pet->status =='a')))
    {
        achou=1;
    }
}
if(achou){
    exibepet(pet);
}
else{
    printf("Os dados do Pet não foram encontrados\n");
    getchar();
}
fclose(fp);
free(pet);
printf("Pressione qualquer tecla para sair.... ");
getchar();
getchar();
}

void editapet(void){
char peso[10];
int tam;
system ( " clear||cls " );
FILE* fp;
Animal* pet;
int achou;
char resp;
char cpf_busca[20];
char id_pet[10];
int id;
pet = (Animal*) malloc(sizeof(Animal));
achou=0;
fp= fopen("animais.dat","r+b");
if (fp == NULL){
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não e possível continuar o programa...\n");
    exit(1);
}
printf(" | ========================================================= | \n");
printf(" |                                                           | \n");
printf(" |                     Atualizar Animal                      | \n");
printf(" |                                                           | \n");
printf(" | ========================================================= | \n");
printf("Informe o CPF Do Dono do Animal Cadastrado:");
scanf("%s", cpf_busca);
getchar();
printf("Informe O ID Único do Animal Cadastrado:");
scanf("%s", id_pet);
id= atoi(id_pet);
getchar();
while ((!achou) && (fread(pet, sizeof(Animal), 1, fp))){
if ((strcmp(pet->cpf, cpf_busca) == 0) && ((pet->id_animal==id) &&(pet->status =='a')))
    {
        achou=1;
    }
}
if(achou)
{
    exibepet(pet);
    printf("Deseja realmente editar este Animal?[s/n] ");
    scanf("%c",&resp);
    getchar();
if (resp == 's' || resp == 'S')
{
    do
    {
        printf("Informe o Novo Nome do Animal: ");
        scanf(" %19[^\n]", pet->animal);
        getchar();        
    }
    while(!validaPalavra(pet->animal)); 
    do
    {
        printf("Informe A Raça do Animal: ");
        scanf(" %19[^\n]", pet->raca);
        getchar();    
    }
    while (!validaPalavra(pet->raca));
    
    printf("Informe o Sexo do Animal (M/F): ");
    scanf("%c", &pet->sexo);
    getchar();
do{
            printf("Informe o Novo Peso do Animal: ");
            scanf(" %9[^\n]", peso);
            getchar();
            tam=strlen(peso);
        if (!validar_peso(peso, tam)){
            printf("Peso inserido esta incorreto com a Validacao.\n");
}
}
while (!validar_peso(peso, tam));
    pet->peso = atof(peso);
    pet->status = 'a';
    fseek(fp, (-1)*sizeof(Animal), SEEK_CUR);
    fwrite(pet, sizeof(Animal), 1, fp);
    printf("\nPet editado com sucesso!!!\n");
    printf("Pressione qualquer tecla para sair...");
    getchar();
} 
    else
    {
        printf("Tudo bem, os dados não foram alterados! \n");
        printf("Aperte Enter para continuar!\n");
        getchar();
        getchar();
    }
}
else
{
    printf("usuario ou Pet não encontrado!\n");
    printf("Pressione qualquer tecla para sair...");
    getchar();
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
int id;
fp= fopen("animais.dat","r+b");
if(fp == NULL)
    {
        printf("Ops! Erro na abertura do arquivo!\n");
        exit(1);
    }
pet = (Animal*) malloc(sizeof(Animal));
printf(" | ============================================================== | \n");
printf(" |                                                                | \n");
printf(" |                        Excluir Animal                          | \n");
printf(" |                                                                | \n");
printf(" | ============================================================== | \n");
printf("Informe o CPF do Dono do Animal que Você quer Excluir: ");
scanf("%s", cpf_busca);
getchar();
printf("Informe ID Único do Animal que Você deseja Excluir:");
scanf("%s", id_pet);
getchar();  
id=atoi(id_pet);
achou=0;    
while ((!achou) && (fread(pet, sizeof(Animal), 1, fp))){
    if ((strcmp(pet->cpf, cpf_busca) == 0) && ((pet->id_animal==id) &&(pet->status =='a')))
    {
        achou=1;
    }
}
if(achou)
{
exibepet(pet);
printf("Deseja realmente excluir os dados deste animal?(s/n)");
scanf("%c", &resp);
getchar();
    if (resp == 's' || resp == 'S')
    {
        pet->status = 'x';
        fseek(fp, (-1)*sizeof(Animal), SEEK_CUR);
        fwrite(pet, sizeof(Animal), 1, fp);
        printf("\n Animal excluído com sucesso!");
        gravaPet(pet);
        printf("Pressione qualquer tecla para sair... ");
        getchar();
    }
    else
    {
        printf("\nTudo bem, os dados não foram alterados!");
    }
}
else
{
    printf("O Animal não foi encontrado!");
}
free(pet);
fclose(fp);
printf("Pressione qualquer tecla para sair.... ");
getchar(); 
}

void gravaPet(Animal* pet){
FILE* fp;
fp = fopen("animais.dat","ab");
if (fp == NULL){
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não e Póssivel continuar este programa...\n");
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
if (fp == NULL){
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não e Póssivel continuar este programa...\n");
    exit(1);
}
printf("\n\n");
printf(" | ----------------------- Lista Pets ---------------------- | \n");
printf(" |                                                           | \n");
printf(" | --------------------------------------------------------- | \n");
while(fread(pet, sizeof(Animal), 1, fp)){
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
        printf("ID Único do Pet:%d\n", pet->id_animal);
        printf("Sexo do Animal:%c\n", pet->sexo);
        printf("Peso do Animal: %.2f\n", pet->peso);
        printf("Status:%c\n", pet->status);
    }
}

int busca_petfile(char* cpf_busca, int id){
system ( " clear||cls " );
FILE* fp;
Animal* pet;
int achou;
fp = fopen("animais.dat", "rb");
if (fp == NULL) {
    printf("Ops! Erro na abertura do arquivo!\n");
    exit(1);
}
pet = (Animal*) malloc(sizeof(Animal));
achou = 0;
 while ((!achou) && (fread(pet, sizeof(Animal), 1, fp))){
    if ((strcmp(pet->cpf, cpf_busca) == 0) && ((pet->id_animal==id) &&(pet->status =='a'))){
        achou=1;
    }
 }

if (achou){
    fclose(fp);
    free(pet);
    getchar();
    return 1;
}else{
    printf("Os dados do Pet  não foram encontrados\n");
    fclose(fp);
    free(pet);
    return 0;
}

}

void listaPetsMacho(void){
system ( " clear||cls " );
FILE* fp;
Animal* pet;
pet = (Animal*) malloc(sizeof(Animal));
fp = fopen("animais.dat","rb");
if (fp == NULL){
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não e Póssivel continuar este programa...\n");
    exit(1);
}
printf("\n\n");
printf(" | ----------------------- Lista Pets ---------------------- | \n");
printf(" |                                                           | \n");
printf(" | --------------------------------------------------------- | \n");
while(fread(pet, sizeof(Animal), 1, fp)){
    if (pet->sexo == 'M')
    {
        exibepet(pet);
    }
}
fclose(fp);
free(pet);
getchar();
getchar();
}

void listaPetsFemea(void){
system ( " clear||cls " );
FILE* fp;
Animal* pet;
pet = (Animal*) malloc(sizeof(Animal));
fp = fopen("animais.dat","rb");
if (fp == NULL){
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Nao e possivel continuar este programa...\n");
    exit(1);
}
printf("\n\n");
printf(" | ----------------------- Lista Pets ---------------------- | \n");
printf(" |                                                           | \n");
printf(" | --------------------------------------------------------- | \n");
while(fread(pet, sizeof(Animal), 1, fp)){
    if (pet->sexo == 'F'){
        exibepet(pet);
    }
}
fclose(fp);
free(pet);
getchar();
getchar();
}


int idAnimal(void)
{
    Animal *pet;
    pet = (Animal *)malloc(sizeof(Animal));
    FILE *fp;
    fp = fopen("animais.dat", "rb");
    if (fp == NULL)
    {
        return 1;
    }

    else
    {
        fseek(fp, (-1) * sizeof(Animal), SEEK_END);
        fread(pet, sizeof(Animal), 1, fp);
        return pet->id_animal + 1;
    }
}

void ListaPetCPF(void){
system ( " clear||cls " );
FILE* fp;
Animal* pet;
char cpf_busca[20];
fp = fopen("animais.dat", "rb");
if (fp == NULL){
    printf("Ops! Erro na abertura do arquivo!\n");
    exit(1);
}
printf("\n = Buscar PET = \n"); 
printf("Informe CPF Do Dono Do Animal: "); 
scanf(" %19[^\n]", cpf_busca);
getchar();
pet = (Animal*) malloc(sizeof(Animal));
while  (fread(pet, sizeof(Animal), 1, fp)){
    if ((strcmp(pet->cpf, cpf_busca) == 0))
    {
        exibepet(pet);
    }
}

fclose(fp);
free(pet);
printf("Pressione qualquer tecla para sair.... ");
getchar();
getchar();
}
