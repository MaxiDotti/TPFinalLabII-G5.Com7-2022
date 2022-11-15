#include "division.h"
#include "jugador.h"
#include "empleado.h"
#include "cuerpoTecnico.h"
#include "string.h"



///Funciones arreglo ct

int altaCT (celdaDivision celd[], stCT nuevoCT, char nombreDivision[], int idDivision, int validos)
{
    nodoCT* aux=crearNodoCT(nuevoCT);
    int pos=buscarPosDivision (celd,idDivision,validos);
    if(pos==-1)
    {
        validos= agregarDivision(celd, nombreDivision, idDivision, validos);
        pos=validos-1;
    }
    celd[pos].ct=agregarEnOrdenDobleId(celd[pos].ct, aux);

    return validos;
}

int buscarPosDivision (celdaDivision celd[],int idDivision,int validos)
{
    int rta=-1;
    int i=0;

    while (validos>i && (rta==-1))
    {
        if (idDivision == celd[i].dato.idDivision)
        {
            rta=i;
        }
        i++;
    }
    return rta;
}

int agregarDivision(celdaDivision celd[],char nombreDivision[],int idDivision,int validos)
{
    strcpy(celd[validos].dato.nombreDivision, nombreDivision);
    celd[validos].ct=inicListaDoble();
    celd[validos].dato.idDivision=idDivision;
    validos++;

    return validos;
}

int archivoToArrCT (celdaDivision arr[], int dim)
{
    FILE* buf=fopen("ArchivoCuerpoTecnico.bin","rb");
    registroArchivoCT aux;
    stCT ct;

    int  validos=0;

    if (buf)
    {
        while(fread(&aux,sizeof(registroArchivoCT),1,buf)>0 && validos<dim)
        {
            ct=registroToCT(aux);
            validos=altaCT(arr,ct,aux.nombreDivision,aux.idDivision,validos);
        }
    }
    else
    {
        printf("\nEl archivo no se pudo abrir.\n");
    }
    return validos;
}

void mostrarArregloCT (celdaDivision arr[], int validos)
{
    int i=0;
    while (i<validos)
    {
        printf("Division: %s\n",arr[i].dato.nombreDivision);
        printf("Id de la division : %d\n",arr[i].dato.idDivision);
        mostrarListaCT(arr[i].ct);
        i++;
        system("pause");
        system("cls");
    }
}



///Funciones arreglo empleado:
int altaEmpleado(celdaDivision celd[], stEmpleado nuevo, char nombreDivision[], int idDivision, int validos)
{
    nodoEmpleado * aux=crearNodoS(nuevo);
    int pos=buscarPosDivision (celd,idDivision,validos);
    if(pos==-1)
    {
        validos= agregarDivisionSimple(celd, nombreDivision, idDivision, validos);
        pos=validos-1;
    }
    celd[pos].emp=agregarEnOrden(celd[pos].emp,aux);

    return validos;
}

int archivoArrE (celdaDivision arr[], int dim)
{
    FILE* buf=fopen("ArchivoEmpleados","rb");
    archiEmpleado aux;
    stEmpleado E;

    int  validos=0;

    if (buf)
    {
        while(fread(&aux,sizeof(archiEmpleado),1,buf)>0 && validos<dim)
        {
            E=nuevoEmpleado(aux);
            validos=altaEmpleado(arr,E,aux.nombreDivision,aux.idDivision,validos);
        }
    }
    else
    {
        printf("\nEl archivo no se pudo abrir.\n");
    }
    return validos;
}

int agregarDivisionSimple(celdaDivision celd[],char nombreDivision[],int idDivision,int validos)
{
    strcpy(celd[validos].dato.nombreDivision, nombreDivision);
    celd[validos].emp=inicListaS();
    celd[validos].dato.idDivision=idDivision;
    validos++;

    return validos;
}

void mostrarArregloEmpleado (celdaDivision arr[], int validos)
{
    int i=0;
    while (i<validos)
    {
        printf("Division: %s\n",arr[i].dato.nombreDivision);
        printf("Id de la division : %d\n",arr[i].dato.idDivision);
        MostrarListaE(arr[i].emp);
        i++;
        system("pause");
        system("cls");
    }
}



