#ifndef DIVISION_H_INCLUDED
#define DIVISION_H_INCLUDED
#include "empleado.h"
#include "cuerpoTecnico.h"
#include "jugador.h"

typedef struct{
    char nombreDivision[15]; /// primera , segunda , tercera
    int idDivision; /// 1, 2 ,3
}division;

typedef struct celdaDivision{
    division dato;
    nodoEmpleado *emp;
    nodoCT *ct;
    arbolJugador *jug;
}celdaDivision;

#endif // DIVISION_H_INCLUDED
