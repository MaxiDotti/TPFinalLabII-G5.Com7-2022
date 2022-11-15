#include <stdio.h>
#include <stdlib.h>
#include "division.h"
#include "empleado.h"

int main()
{
    int corte=0;
    int opcion=0;
    int validos=0;
    celdaDivision arr[5];

    do
    {
        system("cls");
        printf("A que menu desea ingresar: \n\n1. Jugador\n2. Empleados\n3. Cuerpo Tecnico\n4. Divisiones\n0. Salir\n\n");
        fflush(stdin);
        scanf("%i",&opcion);
        system("cls");

        if (opcion==1)
        {
            menuJugador(validos);
        }
        else if (opcion==2)
        {

        }
        else if (opcion==3)
        {
            menuCuerpoTecnico (validos);
        }
        else if (opcion==4)
        {
            ///cargarArchivoE();
            int maxValidos;

            validos=archivoToArrCT(arr,5);
            maxValidos=validos;

            validos = archivoToArrJug(arr, 5);
            if(validos>maxValidos)
            {
                maxValidos=validos;
            }

            validos=archivoArrE(arr,5);

            if(validos>maxValidos)
            {
                maxValidos=validos;
            }

            mostrarArrDivGeneral(arr,maxValidos);
        }
        else
        {

        }


        printf("\nPRESIONE 1 PARA VOLVER AL MENU PRINCIPAL / 0 PARA SALIR\n");
        scanf("%i",&corte);
    }
    while(corte==1);


    return 0;
}









