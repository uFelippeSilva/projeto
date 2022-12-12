typedef struct usuario Usuario;
typedef struct usuarioDin UsuarioDin;

struct usuario {
  char nome[51];
  char cpf[20];
  char telefone[15];
  int  dd;
  int  mm;
  int  aa;
  char status;
};

struct usuarioDin {
  char* nome;
  char* cpf;
  char* telefone;
  int  dd;
  int  mm;
  int  aa;
  char status;
  UsuarioDin* prox;
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

Usuario* usuario_busca(void);
Usuario* usuario_buscadois(char* cpf);
void relatorio_ordenado(void);
void usuarioDinamico(UsuarioDin* usu);
