typedef struct usuario Usuario;

struct usuario {
  char nome[51];
  char cpf[20];
  char telefone[15];
  int dd;
  int mm;
  int aa;
  char status;
};

//Funçoes Mod Usuario.
void modulo_usuario(void);
char menu_usuario(void);
void cadastrarusuario(void);
void buscausuario(void);
void deletarusuario(void);
void exibeusuario(Usuario* usu);
void gravaUsuario(Usuario*);
void listaUsuarios(void);
void atualizarusuario(void);

