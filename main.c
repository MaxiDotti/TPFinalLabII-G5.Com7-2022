#include <stdio.h>
#include <stdlib.h>
#include "jugador.h"

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
    printf("Hello world!\n");
    /// maxiii anda?
    return 0;
}

