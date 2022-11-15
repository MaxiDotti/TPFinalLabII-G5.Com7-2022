#include <stdio.h>
#include <stdlib.h>
#include "division.h"

int main()
{
    int corte=0;
    int opcion=0;
    int validos=0;
    int dim=5;
    do
    {
        system("cls");
        printf("------> MENU GENERAL\n\n[1] JUGADOR\n[2] EMPLEADO\n[3] CUERPO TECNICO\n[4] DIVISIONES\n[0] SALIR\n");
        printf("\nOPCION: ");
        fflush(stdin);
        scanf("%i",&opcion);
        system("cls");

        if (opcion==1)
        {
            menuJugador(validos,dim);
        }
        else if (opcion==2)
        {
            menuEmpleados (validos,dim);
        }
        else if (opcion==3)
        {
            menuCuerpoTecnico (validos,dim);
        }
        else if (opcion==4)
        {
            menuDivision (validos,dim);
        }
        printf("\nPRESIONE 1 PARA VOLVER AL MENU PRINCIPAL / 0 PARA SALIR: ");
        scanf("%i",&corte);
    }
    while(corte==1);
    return 0;
}
