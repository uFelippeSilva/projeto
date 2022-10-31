#include <stdio.h>
#include <stdlib.h>
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
int ehLetra(char c) {
 if (c>='A' && c<='Z') {
 return 1;
 }
 else if (c>='a' && c<='z') {
 return 1;
 }
 else {
 return 0;
 }
}

int validaNome(char* nome) {
    for (int i=0; nome[i]!='\0'; i++) {
        if (!ehLetra(nome[i])) {
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