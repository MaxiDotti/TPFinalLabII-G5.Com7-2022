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


////PROTOTIPADO CT:
int altaCT (celdaDivision celd[], stCT nuevoCT, char nombreDivision[], int idDivision, int validos);
int buscarPosDivision (celdaDivision celd[],int idDivision,int validos);
int agregarDivision(celdaDivision celd[],char nombreDivision[],int idDivision,int validos);
int archivoToArrCT (celdaDivision arr[], int dim);
void mostrarArregloCT (celdaDivision arr[], int validos);

////PROTOTIPADO EMPLEADO:
int altaEmpleado(celdaDivision celd[], stEmpleado nuevo, char nombreDivision[], int idDivision, int validos);
int archivoArrE (celdaDivision arr[], int dim);
int agregarDivisionSimple(celdaDivision celd[],char nombreDivision[],int idDivision,int validos);
void mostrarArregloEmpleado (celdaDivision arr[], int validos);

////PROTOTIPADO JUGADOR:
int altaJugadorDivision (celdaDivision celd[], stJugador nuevoJug, char nombreDivision[], int idDivision, int validos);
int archivoToArrJug (celdaDivision arr[], int dim);
int agregarDivisionJugador(celdaDivision celd[],char nombreDivision[],int idDivision,int validos);
void menuJugador(int validos,int dim);

////PROTOTIPADO DIVISION
void mostrarArrDivGeneral(celdaDivision arr[], int validos);
void inicializarArreglo (celdaDivision arr[], int dim);
void menuDivision (int validos, int dim);
void mostrarUnaDivision (celdaDivision arr[], int i);
void mostrarPorNombreDiv(celdaDivision arr[],char nombre[], int validos);


#endif // DIVISION_H_INCLUDED
