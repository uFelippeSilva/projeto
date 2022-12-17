//Funçoes Mod Animal.
typedef struct animal Animal;

typedef struct usuario Usuario;

struct animal {
  char animal[20];
  char cpf[20];
  char raca[20];
  int id_animal;
  char sexo;
  char status;
};
void modulo_animal(void);
char menu_animal(void);
void cadastraranimal(void);
void buscapet(void);
void editapet(void);
void excluipet(void);
void listaPets(void);
void gravaPet(Animal* pet);
void exibepet(Animal* pet);
int busca_petfile(char*, int);
void listaPetsMacho(void);
void listaPetsFemea(void);
int idAnimal(void);