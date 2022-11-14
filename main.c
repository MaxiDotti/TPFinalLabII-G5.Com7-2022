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




    return 0;
}

