#include <stdio.h>
#include <stdlib.h>
#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

typedef struct{
    int legajo;
    char nombre[20];
    char apellido[20];
    int dni;
    int edad;
    float sueldo;
    float valorpase;
    char posicion[20]; /// ARQUERO - DEFENSOR - MEDIOCAMPISTA - DELANTERO
    int goles;
    int activo; /// 1 ACTIVO / 0 INACTIVO
    char nombreDivision[15]; /// primera , segunda , tercera
    int idDivision; /// 1, 2 ,3
}registroArchivoJugador;

typedef struct{
    int legajo;
    char nombre[20];
    char apellido[20];
    int dni;
    int edad;
    float sueldo;
    float valorpase;
    char posicion[20]; /// ARQUERO - DEF - MEDIOC - DELANTERO
    int goles;
    int activo; /// 1 ACTIVO / 0 INACTIVO
}stJugador;

typedef struct ArbolJugador{
    stJugador dato;
    struct arbolJugador *der;
    struct arbolJugador *izq;
}arbolJugador;


/******************** PROTOTIPADO FUNCIONES JUGADOR ********************/

registroArchivoJugador cargarUnJugador(int dni, int legajo);
int verificarDNIenArchivo (FILE *buf, int dni);
stJugador cargarUnStJugador (registroArchivoJugador aux);
registroArchivoJugador bajaJugador(registroArchivoJugador aux);
registroArchivoJugador altaJugador(registroArchivoJugador aux);
registroArchivoJugador modificarUnJugadorAuxiliar (FILE *buf, registroArchivoJugador aux, int legajo);
int buscarPosicionDni (FILE* buf, int dni);
int buscarYModificarUnJugador (int dni);

arbolJugador *inicArbol();
arbolJugador *crearNodoArbol (stJugador aux);
arbolJugador *insertarEnArbol(arbolJugador *arbol, arbolJugador *nuevo);
arbolJugador *archivoToArbolJugadores ();
arbolJugador *buscarPorDNI (arbolJugador *arbol, int dni);
arbolJugador *buscarGoleador (arbolJugador *arbol, arbolJugador *goleador);
int sumarGolesDivision (arbolJugador *arbol);
arbolJugador *top3Goleadores (arbolJugador *arbol, arbolJugador *goleador, arbolJugador *goleadores, int cont);
arbolJugador *buscarPorDNIyDarDeBaja (arbolJugador *arbol, int dni);
arbolJugador *buscarGoleadorActivo (arbolJugador *arbol, arbolJugador *goleador);
int mostrarNodoArbolPorLegajo (arbolJugador *arbol, int legajo);


/***********************************************************************/

#endif // JUGADOR_H_INCLUDED
