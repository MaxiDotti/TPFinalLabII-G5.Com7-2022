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
    int goles;
    int activo; /// 1 ACTIVO / 0 INACTIVO
}stJugador; /// REGISTRO ARCHIVO

typedef struct ArbolJugador{
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
}stCT;///CUERPO TECNICO

typedef struct nodoCT{
    stCT dato;
    struct nodoCT *ant;
    struct nodoCT *sig;
}nodoCT;

typedef struct{
    int legajo;
    char nombre[20];
    char apellido[20];
    int dni;
    int tel;
    char puesto[20]; /// AYUDANTE - PROFE - MEDICO - MAESTRANZA
    float sueldo;
}stEmpleado;

typedef struct nodoEmpleado{
    stEmpleado dato;
    struct nodoEmpleado *sig;
}nodoEmpleado;


typedef struct celdaDivision{
    char nombreDivision[15]; /// primera , segunda , tercera
    int idDivision; /// 1, 2 ,3
    nodoEmpleado* emp;
    nodoCT* ct;
    ArbolJugador* jug;
}celdaDivision;

int main()
{
    return 0;
}

