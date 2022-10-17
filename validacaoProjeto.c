#include <stdio.h>
#include <stdlib.h>
int validaData(int dd,int mm,int aa){
    
    //Verificar Ano
    if (aa >= 2020 && aa <= 9999)
    {
        //verifica mes
        if (mm >= 1 && mm <= 12)
        {
            //verifica  dia
            if ((dd >= 1 && dd <= 31) && (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12))
                printf("Data valida.\n");
            else if ((dd >= 1 && dd <= 30) && (mm == 4 || mm == 6 || mm == 9 || mm == 11))
                printf("Data valida.\n");
            else if ((dd >= 1 && dd <= 28) && (mm == 2))
                printf("Data  valida.\n");
            else if (dd == 29 && mm == 2 && (aa % 400 == 0 || (aa % 4 == 0 && aa % 100 != 0)))
                printf("Data  valida.\n");
            else
                printf("Dia  invalido.\n");
                return 1;
        }
        else
        {
            printf("Mes  invavalido.\n");
            return 1;
        }
    }
    else
    {
        printf("Ano  invvalido.\n");
    }

    return 0;
}

