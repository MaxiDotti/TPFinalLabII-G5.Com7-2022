#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int legajo;
    char nombre[20];
    char apellido[20];
    int dni;
    float sueldo;
    int valorpase;
    char posicion[20]; /// ARQUERO - DEF - MEDIOC - DELANTERO
    int categoria; /// 1RA / 3RA / 4TA
    int goles;
    int activo; /// 1 ACTIVO / 0 INACTIVO
}stJugador; /// REGISTRO ARCHIVO

typedef struct{
    stJugador dato;
    struct nodoJugador *der;
    struct nodoJugador *izq;
}ArbolJugador;

typedef struct{
    int nrosocio;
    char nombre[20];
    char apellido[20];
    int dni;
    int tel;
    char categoria[20]; /// SIMPLE - PLENO
}stSocio;

typedef struct{
    stSocio dato;
    struct nodoJugador *ant;
    struct nodoJugador *sig;
}nodoSocio;

typedef struct{
    int legajo;
    char nombre[20];
    char apellido[20];
    int dni;
    int tel;
    char puesto[20]; /// DT - AYUDANTE - PROFE - MEDICO - MAESTRANZA
    float sueldo;
}stEmpleado;

typedef struct{
    stSocio dato;
    struct nodoJugador *sig;
}nodoEmpleado;

/*
typedef struct{
    nodoJugador *jugadores; /// pos 0
    nodoEmpleado *empleados; /// pos 1
    nodoSocio *socios; /// pos 2
}Club;
*/


int main()
{
    printf("tp!\n");
    return 0;
}
