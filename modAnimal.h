//Funçoes Mod Animal.
void modulo_animal(void);
char menu_animal(void);
void editar_animal(void);
void pesquisar_animal(void);
void delete_animal(void);
typedef struct animal Animal;

struct animal {
  char cpf[20];
  char animal[20];
  char cor[20];
  char id[20];
};


Animal* cadastroanimal();