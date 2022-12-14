#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "modUsuario.h"
#include "validacaoProjeto.h"
void modulo_usuario(void) {
    char opcao;
    do {
        opcao = menu_usuario();
        switch(opcao) {
            case '1': 	cadastrarusuario(); //Cadastrar Usuario!.
                        break;
            case '2': 	buscausuario(); //Pesquisar Por um Usuario Cadastrado!.
                        break;
            case '3': 	atualizarusuario(); //Parte de Atualizar um usuario desejado.
                        break;
            case '4': 	deletarusuario(); //Deletando Usuario de Maneira Logica.
                        break;
            case '5': 	listaUsuarios(); //Ira Listar Os Usuario Cadastrado no Sistema.!
                        break;            
        } 		
    } while (opcao != '0');
}
char menu_usuario(void) {
        system ( " clear||cls " );
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
    printf("///           |           1. Cadastrar Usuario                              |   ///\n");
    printf("///           |           2. Procurar Usuario                               |   ///\n");
    printf("///           |           3. Editar Usuario                                 |   ///\n");
    printf("///           |           4. Deletar Usuario                                |   ///\n");
    printf("///           |           5. Listar Usuarios                                |   ///\n");
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

void cadastrarusuario(void){
  Usuario* busca;
  int a = 0;
  char dia[20];
  char mes[20];
  char ano[20];
  system ( " clear||cls " );
  Usuario* usu;
  usu = (Usuario*) malloc(sizeof(Usuario));
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" |                   Cadastro Usuario                        | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ========================================================= | \n");
do
  {
    printf("Informe o nome do usuario:");
    scanf(" %50[^\n]", usu->nome);
    getchar();     
  }while (!validaPalavra(usu->nome));
do
  {
    printf("Informe o cpf do usuario: ");
    scanf(" %19[^\n]", usu->cpf);
    getchar();   
  }while (!validaCpf(usu->cpf));

  busca=usuario_buscadois(usu->cpf);

  if (busca==NULL){

    do
      {
        printf(" Digite o dia que voce nasceu: ");
        scanf(" %9[^\n]",dia);
        getchar();
        printf(" Digite o seu mes de nascimento: ");
        scanf(" %9[^\n]",mes);
        getchar();
        printf(" Digite o seu ano de nascimento: ");
        scanf(" %9[^\n]",ano);
        getchar();  

        if ((isDigit(dia)) && (isDigit(mes)) && (isDigit(ano))){
          usu->dd = atoi(dia);
          usu->mm = atoi(mes);
          usu->aa = atoi(ano);

          if(validaData(usu->dd, usu->mm, usu->aa)){
            a = 1;
          }
        }

      } while(!a);

      do
        {
          printf("Informe o Telefone do usuario DDD Obrigatorio.Ex(84)923456789: ");
          scanf(" %14[^\n]", usu->telefone);
          getchar();    
      }while(!validaTelefone(usu->telefone));

    usu->status = 'a';
    gravaUsuario(usu);
  }

  else {
    printf("\n Ja existe um Usuario com este cpf.");
  }
free(busca);
free(usu);
printf("\n Pressione qualquer tecla para sair.... ");
getchar();
}
void buscausuario(void){
system ( " clear||cls " );

FILE* fp;
Usuario* usu;
int achou;
char cpf_busca[20];
fp = fopen("usuarios.dat", "rb");
  if (fp == NULL)
    {
        printf("Ops! Erro na abertura do arquivo!\n");
        exit(1);
    }
  printf("\n = Buscar Usuario = \n"); 
  printf("Informe CPF: "); 
  scanf(" %19[^\n]", cpf_busca);
  usu = (Usuario*) malloc(sizeof(Usuario));
  achou = 0;
while((!achou) && (fread(usu,sizeof(Usuario), 1, fp))) 
  {
      if ((strcmp(usu->cpf, cpf_busca) == 0) && (usu->status != 'x'))
      {
        achou =1;
      }
  }
if (achou)
  {
    exibeusuario(usu);
  }
else
  {
    printf("Os dados do usuario nao foram encontrados\n");
  }
fclose(fp);
free(usu);
printf("Pressione qualquer tecla para sair.... ");
getchar();
getchar();
}
void atualizarusuario(void){
  char dia[10];
  char mes[10];
  char ano[10];
   system ( " clear||cls " );
   FILE* fp;
    Usuario* usu;
    int achou;
    char resp;
    char cpf_busca[20];
    usu = (Usuario*) malloc(sizeof(Usuario));
    achou = 0;
    fp = fopen("usuarios.dat", "r+b");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Nao e possivel continuar o programa...\n");
        exit(1);
  }
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ------------------- Atualizar usuario ------------------- | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ========================================================= | \n");
    printf("Digite o CPF do usuario cadastrado: ");
    scanf("%s", cpf_busca);
    getchar();
while((!achou) && (fread(usu, sizeof(Usuario), 1, fp)))
  {
  if ((strcmp(usu->cpf, cpf_busca) == 0) && (usu->status == 'a'))
    {
      achou = 1;
    }
  }
if (achou)
  {
    exibeusuario(usu);
    printf(" Deseja realmente editar este usuario? [s/n] ");
    scanf("%c", &resp);
    getchar();
    if (resp == 's' || resp == 'S')
    {
      do
      {
        printf("Informe o nome do usuario: ");
        scanf(" %50[^\n]", usu->nome);
        getchar();   
      } while (!validaPalavra(usu->nome));
      do 
      {
        printf("Digite o dia que voce nasceu: ");
        scanf(" %9[^\n]",dia);
        getchar();
        printf("Digite o seu mes de nascimento: ");
        scanf(" %9[^\n]",mes);
        getchar();
        printf("Digite o seu ano de nascimento: ");
        scanf(" %9[^\n]",ano);
        getchar();   
        usu->dd = atoi(dia);
        usu->mm = atoi(mes);
        usu->aa = atoi(ano);

      } while(!validaData(usu->dd, usu->mm, usu->aa));
      do
      {
        printf("Informe o Telefone do usuario: ");
        scanf(" %14[^\n]", usu->telefone);
        getchar();  
      }while (!validaTelefone(usu->telefone));
        usu->status = 'a'; // a = Ativo. x = Inativo
        fseek(fp, (-1)*sizeof(Usuario), SEEK_CUR);
        fwrite(usu, sizeof(Usuario), 1, fp);
        printf("\nUsuario editado com sucesso!!!\n");
        printf("Pressione qualquer tecla para sair... ");
        getchar();
    }
  else
    {
      printf("Os dados nao foram alterados!\n");
      printf("Pressione qualquer tecla para sair...");
      getchar();
    }
    } else {
    printf("usuario nao encontrado!\n");
    printf("Pressione qualquer tecla para sair...");
    getchar();
  }
  
free(usu);
fclose(fp);

}      
void deletarusuario(void){
  system ("clear||cls");
  FILE* fp;
    Usuario* usu;
    int achou;
    char resp;
    char cpf_busca[20];
    fp = fopen("usuarios.dat", "r+b");

    if (fp == NULL){
        printf("Ops! Erro na abertura do arquivo!\n");
        exit(1);
    }
    usu = (Usuario*) malloc(sizeof(Usuario));
    printf(" | ============================================================== | \n");
    printf(" | -------------------------------------------------------------- | \n");
    printf(" | ---------------------- Excluir usuario ----------------------- | \n");
    printf(" | -------------------------------------------------------------- | \n");
    printf(" | ============================================================== | \n");
    printf("Informe o CPF do usuario que você quer excluir: ");
    scanf("%s", cpf_busca);
    getchar();
    achou=0;
    while ((!achou) && (fread(usu, sizeof(Usuario), 1, fp))){
    if ((strcmp(usu->cpf, cpf_busca) == 0) && (usu->status == 'a')){
        achou = 1;
        }
    }
    if (achou){
        exibeusuario(usu);
        printf("Deseja realmente excluir os dados deste usuario? (s/n)");
        scanf("%c", &resp);
        if (resp == 's' || resp == 'S'){
            usu->status = 'x';
            fseek(fp, (-1)*sizeof(Usuario), SEEK_CUR);
            fwrite(usu, sizeof(Usuario), 1, fp);
            printf("\nUsuario excluido com sucesso!");
            printf("Pressione qualquer tecla para sair... ");
            getchar();
        }else{
            printf("\nTudo bem, os dados nao foram alterados!");
            getchar();
        }
        }else{
        printf("O usuario nao foi encontrado!");
        getchar();
    }
    free(usu);
    fclose(fp);
    printf("Pressione qualquer tecla para sair.... ");
    getchar();
    
}
void gravaUsuario(Usuario* usu) {
  system ("clear||cls");
  FILE* fp;
  fp = fopen("usuarios.dat", "ab");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Nao e possivel continuar este programa...\n");
    exit(1);
  }
  fwrite(usu, sizeof(Usuario), 1, fp);
  fclose(fp);
}
void listaUsuarios(void) {
  system ( " clear||cls " );
  FILE* fp;
  Usuario* usu;
  printf("\n = Lista de Usuarios = \n"); 
  usu = (Usuario*) malloc(sizeof(Usuario));
  fp = fopen("usuarios.dat", "rb");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Nao e possivel continuar este programa...\n");
    exit(1);
  }
    printf("\n\n");
    printf(" | ----------------------- Exibe usuario ------------------- | \n");
    printf(" |                                                           | \n");
    printf(" | --------------------------------------------------------- | \n");
  while(fread(usu, sizeof(Usuario), 1, fp)) {
  if (usu->status != 'x')
    {
      exibeusuario(usu);
    }
  }
  fclose(fp);
  free(usu);
  printf("Pressione qualquer tecla para sair.... ");
  getchar();
  getchar();
}
void exibeusuario(Usuario* usu) {
  system ("clear||cls");
  {
  printf("\n= = = Usuario Cadastrado = = =\n");
  printf("Nome do Usuario: %s\n", usu->nome);
  printf("CPF do Usuario: %s\n", usu->cpf);
  printf("Dia Que Nasceu: %d\n", usu->dd);
  printf("Mes Que Nasceu: %d\n", usu->mm);
  printf("Ano Que Nasceu: %d\n", usu->aa);
  printf("Telefone do Usuario: %s\n", usu->telefone);
  printf("Status:%c\n", usu->status);
  }
}

Usuario* usuario_busca(void){
//Creditos a Victor Ryan!. https://github.com/VictorRyan3612    
  FILE* fp;
  Usuario* usu;
  usu = (Usuario*)malloc(sizeof(Usuario));

  char* cpf_busca_dig;
  cpf_busca_dig = cpf_busca();

  fp = fopen("usuarios.dat", "rb");
  if (fp == NULL) {
      printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
      printf("Nao e possivel continuar este programa...\n");
      exit(1);
  }

  while(!feof(fp)) {
      fread(usu, sizeof(Usuario), 1, fp);
      if ((strcmp(usu->cpf, cpf_busca_dig) == 0) && (usu->status != 'x')){
          fclose(fp);
          return usu;
      }
  }
  free(cpf_busca_dig);
  fclose(fp);
  return NULL;
}

Usuario* usuario_buscadois(char* cpf){  
  FILE* fp;
  Usuario* usu;
  usu = (Usuario*)malloc(sizeof(Usuario));
  fp = fopen("usuarios.dat", "rb");
  if (fp == NULL) {
      printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
      printf("Nao e possivel continuar este programa...\n");
      exit(1);
  }

  while(!feof(fp)) {
      fread(usu, sizeof(Usuario), 1, fp);
      if ((strcmp(usu->cpf, cpf) == 0) && (usu->status != 'x')){
          fclose(fp);
          return usu;
      }
  }
  fclose(fp);
  return NULL;
}

void relatorio_ordenado(void) {
system ("clear||cls");
FILE *fp;
Usuario *usu;
UsuarioDin* novoUsu;
UsuarioDin* lista;
int tam;

if (access("usuarios.dat", F_OK) != -1) {
fp = fopen("usuarios.dat","rb");
  if (fp == NULL) {
      printf("Erro com arquivo!");
    }
    else{
          lista = NULL;

          usu = (Usuario*) malloc(sizeof(Usuario));

          while(fread(usu, sizeof(Usuario), 1, fp)) {
              
              if (usu->status == 'a') {
                  //Para o nome
                  novoUsu = (UsuarioDin*) malloc(sizeof(UsuarioDin));

                  tam = strlen(usu->nome) + 1;

                  novoUsu->nome = (char*) malloc(tam*sizeof(char));
                  strcpy(novoUsu->nome, usu->nome);

                  //Para o cpf
                  tam = strlen(usu->cpf) + 1;

                  novoUsu->cpf = (char*) malloc(tam*sizeof(char));
                  strcpy(novoUsu->cpf, usu->cpf);

                  //Para o numero
                  tam = strlen(usu->telefone) + 1;

                  novoUsu->telefone = (char*) malloc(tam*sizeof(char));
                  strcpy(novoUsu->telefone, usu->telefone);

                  novoUsu->dd = usu->dd;
                  novoUsu->mm = usu->mm;
                  novoUsu->aa = usu->aa;

                  if (lista == NULL) {
                      lista = novoUsu;
                      novoUsu->prox = NULL;
                  } 

                  else if (strcmp(novoUsu->nome,lista->nome) < 0) {
                      novoUsu->prox = lista;
                      lista = novoUsu;
                  } 

                  else {
                      UsuarioDin* anter = lista;
                      UsuarioDin* atual = lista->prox;
                      while ((atual != NULL) && strcmp(atual->nome, novoUsu->nome) < 0) {
                        anter = atual;
                        atual = atual->prox;
                      }
                      anter->prox = novoUsu;
                      novoUsu->prox = atual;
                  }
              }
          }
          free(usu);
          // Exibindo a lista de palavras
          novoUsu = lista;
          while (novoUsu != NULL) {
              usuarioDinamico(novoUsu);
              novoUsu = novoUsu->prox;
          }
          // Limpando a memória
          novoUsu = lista;
          while (lista != NULL) {
              lista = lista->prox;
              free(novoUsu->nome);
              free(novoUsu->cpf);
              free(novoUsu->telefone);
              free(novoUsu);
              novoUsu = lista;
          }
      }
    fclose(fp);
  }
}

void usuarioDinamico(UsuarioDin* usu) {
  system ("clear||cls");
  {
  printf("\n= = = Usuario Cadastrado = = =\n");
  printf("Nome do Usuario: %s\n", usu->nome);
  printf("CPF do Usuario: %s\n", usu->cpf);
  printf("Dia Que Nasceu: %d\n", usu->dd);
  printf("Mes Que Nasceu: %d\n", usu->mm);
  printf("Ano Que Nasceu: %d\n", usu->aa);
  printf("Telefone do Usuario: %s\n", usu->telefone);
  printf("Status:%c\n", usu->status);
  }
}