//Funçoes Mod Horarios.

typedef struct horario Horario;
struct horario {
  char cpf_busca[20];
  char id_animal[10];
  char id_servico[4];
  int dd;
  int mm;
  int aa;
  int hora;
  int min;
  char status;
  char id_consulta[7];
};
void exibeconsulta(Horario* hora);
void gravaConsulta(Horario*);


void modulo_horarios(void);
char menu_horarios(void);
void cadastrar_horario(void);
void editar_horario(void);
void deletar_horario(void);