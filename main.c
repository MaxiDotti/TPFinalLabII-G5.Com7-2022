#include <stdio.h>
#include <stdlib.h>
#include "division.h"
#include "empleado.h"
int main()
{
<<<<<<< HEAD
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
=======





>>>>>>> 71b06a2d261b73959dfb0d86db2c37a51e071a0f
    return 0;
}

