#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validacaoProjeto.h"

int isDigit(char n){
    if(n >= '0' && n <= '9'){
        return 1;
    }else{
        return 0;
    }
}
//Credito a Isa Kaillany e Felipe Souza
int validaTelefone(char *telefone)
{
  int tam = strlen(telefone);
  int digito = 0, i; 
  
  if (tam != 11) //verifica o tamanho
  {
    return 0;
  }
  else
  {
    for (i = 0; i < tam; i++)
      {
        char c = telefone[i];
  
        if (isdigit(c)) //verifica se é dígito
        {
          digito++;
        }
        else
        {
          return 0;
        }
      }
    if (digito == 0) //verifica se tem dígito
    {
      return 0;
    }
  }
  return 1;
}

int validaData(int dia,int mes,int ano){
    

    if ((dia >= 1 && dia <= 31) && (mes >= 1 && mes <= 12) && (ano >= 1900 && ano <= 2100)) //verifica se os numeros sao validos
        {
            if ((dia == 29 && mes == 2) && ((ano % 4) == 0)) //verifica se o ano e bissexto
            {
                return 1;
            }
            if (dia <= 28 && mes == 2) //verifica o mes de feveireiro
            {
                return 1;
            }
            if ((dia <= 30) && (mes == 4 || mes == 6 || mes == 9 || mes == 11)) //verifica os meses de 30 dias
            {
                return 1;
            }
            if ((dia <=31) && (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes ==8 || mes == 10 || mes == 12)) //verifica os meses de 31 dias
            {
                return 1;
            }
            else
            {
                return 0;
            }
      }
       else
           {
                return 0;
           }
}

//

int validaPalavra(char *palavra) {
    
    int i = 0;

    while (palavra[i] != '\0') {
        if (((palavra[i] >= 'a') && (palavra[i] <= 'z')) || (palavra[i] == ' ')) {
            i = i + 1;
        }
        else if ((palavra[i] >= 'A') && (palavra[i] <= 'Z')) {
            i = i + 1;
        }
        else {
            return 0;
        }

    }
    return 1;

}



// Credito A Dayane Xavier Pelo ValidadorDeCPF!
int validaCpf(char *cpf) {

    int soma = 0;
    int resto = 0;

    for (int i = 0; i < 9; i++) {
        soma = soma + ((cpf[i] - '0' ) * (i + 1));

    }

    resto = soma % 11;

    resto = (resto == 10) ? 0 : resto;

    if (resto == (cpf[9] - '0' )) {
        soma = 0;

        for (int i = 0; i < 10; i++) {
                soma = soma + ((cpf[i] - '0' ) * (i));

        }

        resto = soma % 11;

        resto = (resto == 10) ? 0 : resto;

        if (resto == (cpf[10] - '0' )) {
            return 1;

        }

        else {
            return 0;
        }

    }

    else {
        return 0;

    }

}

int validaHora(int hora, int min)
{

  if ((hora < 7 || hora > 17) || (min < 0 || min > 59))  // Hora  Menor que 7 Devido a Clinica so Ira Trabalhar Das 7 as 17 Horas.
  {
    return 0;      
  }
  else
  {
    return 1;
  }    

}

char* cpf_busca(void){
  //Creditos a Victor Ryan!. https://github.com/VictorRyan3612
    char* cpf_busca_dig;

    cpf_busca_dig = (char*) malloc(13*sizeof(char));
    printf("\n ==== Busca usuario ==== \n"); 
    printf("Informe o CPF:\n"); 
    scanf("%s", cpf_busca_dig);
    getchar();
    
    return cpf_busca_dig;
}