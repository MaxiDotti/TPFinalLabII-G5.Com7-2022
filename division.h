#ifndef DIVISION_H_INCLUDED
#define DIVISION_H_INCLUDED
#include "empleado.h"
#include "cuerpoTecnico.h"
#include "jugador.h"

typedef struct celdaDivision{
    char nombreDivision[15]; /// primera , segunda , tercera
    int idDivision; /// 1, 2 ,3
    nodoEmpleado* emp;
    nodoCT* ct;
    ArbolJugador* jug;
}celdaDivision;


#endif // DIVISION_H_INCLUDED
