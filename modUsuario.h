//Funçoes Mod Usuario.
void modulo_usuario(void);
char menu_usuario(void);
void cadastrar_usuario(void);
void editar_usuario(void);
void delete_usuario(void);
void pesquisar_usuario(void);

typedef struct usuario Usuario;

struct usuario {
  char nome[51];
  char cpf[16];
  char telefone[16];
};