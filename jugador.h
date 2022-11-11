#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

typedef struct{
    int legajo;
    char nombre[20];
    char apellido[20];
    int dni;
    float sueldo;
    int valorpase;
    char posicion[20]; /// ARQUERO - DEF - MEDIOC - DELANTERO
    int goles;
    int activo; /// 1 ACTIVO / 0 INACTIVO
    char nombreDivision[15]; /// primera , segunda , tercera
    int idDivision; /// 1, 2 ,3
}stJugador; /// REGISTRO ARCHIVO

typedef struct ArbolJugador{
    stJugador dato;
    struct nodoJugador *der;
    struct nodoJugador *izq;
}ArbolJugador;

#endif // JUGADOR_H_INCLUDED
