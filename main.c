#include <stdio.h>
#include <stdlib.h>
#include "division.h"
#include "empleado.h"
int main()
{
    char archivoJugador[] = "ArchivoJugadores";
    ///cargarJugadorRegistroArchivo(archivoJugador);
    ///mostrarArchivoJugador(archivoJugador);

    arbolJugador *arbol = inicArbol();
    arbol = archivoToArbol(archivoJugador);
    mostrarArbolDNI(arbol);

    arbolJugador *goleador = inicArbol();
    arbolJugador *goleadores = inicArbol();
    int i=0; /// SE INICIALIZA EL CONTADOR EN 0
    goleadores = top3Goleadores(arbol, goleador, goleadores, i);
    printf("\n\n------------------> GOLEADORES\n\n");
    if(goleadores){
        mostrarArbolDNI(goleadores);
    }
    else{
        printf("\nSALIO COMO EL ORTO\n");
    }
/*
    printf("\n\nARBOL ORDENADO POR D.N.I.\n\n");
    mostrarArbolDNI(arbol);
*/
    int corte;
    int opcion=0;
    int eleccion;
    int idAbuscar=0;
    do
    {
        system("cls");
        printf("A que menu desea ingresar: \n\n1.Jugador\n2.Empleados\n3.Cuerpo Tecnico\n4.Divisiones\n0.Salir\n\n");
        fflush(stdin);
        scanf("%i",&opcion);
        system("cls");




        printf("\nPRESIONE 1 PARA VOLVER AL MENU PRINCIPAL / 0 PARA SALIR\n");
        scanf("%i",&corte);
    }
    while(corte==1);

    return 0;
}









