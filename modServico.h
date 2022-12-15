typedef struct servicos Servicos;

struct servicos {
  char nome[20];
  int id_servico;
  float valor;
  char tempo[20];
  char status;
};

void modulo_servico(void);
char menu_servico(void);
void cadastraservico(void);
void buscaservico(void);
void atualizarservico(void);
void deletarservico(void);
void gravaServico(Servicos*);
void exibeservico(Servicos* ser);
void listaServicos(void);
int buscaservico_file(char*);
int idServico(void);
int validar_dinheiro(char* dinheiro, int tam);