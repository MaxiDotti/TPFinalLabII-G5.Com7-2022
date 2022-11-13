#include <stdio.h>
#include <stdlib.h>
#include "division.h"

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
    return 0;
}

