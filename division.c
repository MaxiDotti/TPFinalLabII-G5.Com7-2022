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

    FILE* buf=fopen("archivoEmpleados","rb");
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

/// FUNCIONES JUGADOR

int altaJugadorDivision (celdaDivision celd[], stJugador nuevoJug, char nombreDivision[], int idDivision, int validos)
{
    arbolJugador *aux = crearNodoArbol(nuevoJug);
    int pos=buscarPosDivision (celd,idDivision,validos);
    if(pos==-1)
    {
        validos = agregarDivisionJugador(celd, nombreDivision, idDivision, validos);
        pos=validos-1;
    }
    celd[pos].jug = insertarEnArbol(celd[pos].jug, aux);

    return validos;
}

int agregarDivisionJugador(celdaDivision celd[],char nombreDivision[],int idDivision,int validos)
{
    strcpy(celd[validos].dato.nombreDivision, nombreDivision);
    celd[validos].jug = inicArbol();
    celd[validos].dato.idDivision=idDivision;
    validos++;

    return validos;
}

int archivoToArrJug (celdaDivision arr[], int dim)
{
    FILE* buf=fopen("archivoJugadores","rb");
    registroArchivoJugador aux;
    stJugador jugador;

    int  validos=0;

    if (buf)
    {
        while(fread(&aux,sizeof(registroArchivoJugador),1,buf)>0 && validos<dim)
        {
            jugador = cargarUnStJugador(aux);
            validos = altaJugadorDivision(arr, jugador, aux.nombreDivision, aux.idDivision, validos);
        }
    }
    else
    {
        printf("\nEL ARCHIVO NO SE PUDO ABRIR.\n");
    }
    return validos;
}
///FUNCIONES GENERALES

void mostrarArrDivGeneral(celdaDivision arr[], int validos) ///Muestra el arreglo completo
{
    int i=0;
    system("cls");
    while (i<validos)
    {
        printf("Division: %s\n",arr[i].dato.nombreDivision);
        printf("Id de la division : %d\n\n\n",arr[i].dato.idDivision);
        if (arr[i].jug)
        {
            printf("\nJugadores: \n");
            mostrarArbolDNI(arr[i].jug);
        }
        if (arr[i].emp)
        {
            printf("\nEmpleados: \n");
            MostrarListaE(arr[i].emp);
        }
        if (arr[i].ct)
        {
            printf("\nCuerpo Tecnico: \n");
            mostrarListaCT(arr[i].ct);
        }
        printf("\n\n\n");
        i++;
    }
}

void mostrarUnaDivision (celdaDivision arr[], int i) ///Muestra una division especifica
{
    system("cls");

    printf("Division: %s\n",arr[i].dato.nombreDivision);
    printf("Id de la division : %d\n\n\n",arr[i].dato.idDivision);
    if (arr[i].jug)
    {
        printf("\nJugadores: \n");
        mostrarArbolDNI(arr[i].jug);
    }
    if (arr[i].emp)
    {
        printf("\nEmpleados: \n");
        MostrarListaE(arr[i].emp);
    }
    if (arr[i].ct)
    {
        printf("\nCuerpo Tecnico: \n");
        mostrarListaCT(arr[i].ct);
    }
    printf("\n\n\n");
}

void mostrarPorNombreDiv(celdaDivision arr[],char nombre[], int validos) ///Muestra por nombre en las divisiones
{
    int i=0;
    while (validos>i)
    {

        printf("Division: %s\n",arr[i].dato.nombreDivision);
        printf("Id de la division : %d\n",arr[i].dato.idDivision);
        if (arr[i].jug)
        {
            mostrarNombreArbol (arr[i].jug,nombre);
        }
        if (arr[i].emp)
        {
            mostrarNombreE(arr[i].emp,nombre);
        }
        if (arr[i].ct)
        {
            mostrarNombreCT (arr[i].ct,nombre);
        }
        printf("\n\n\n");
        i++;
    }
}

void inicializarArreglo (celdaDivision arr[], int dim)
{
    int i=0;
    while (i<dim)
    {
        arr[i].ct=inicListaDoble();
        arr[i].emp=inicListaS();
        arr[i].jug=inicArbol();
        i++;
    }
}

void menuDivision (int validos, int dim)
{
    int controles,pos,maxValidos,i;
    celdaDivision arr[dim];

    system("cls");
    printf("------> MENU DE DIVISION\n\n");
    printf("1.MOSTRAR TODAS LAS DIVISIONES\n2.MOSTRAR POR DIVISION\n3.BUSCAR NOMBRES\n0.SALIR\n");
    fflush(stdin);
    scanf("%d",&controles);
    system("cls");
    inicializarArreglo (arr,dim);

    switch(controles)
    {
    case 1:
    {

        validos=archivoToArrCT(arr,dim);
        maxValidos=validos;///Guarda los validos maximos

        validos = archivoToArrJug(arr, dim);
        if(validos>maxValidos)
        {
            maxValidos=validos;
        }
        validos=archivoArrE(arr,dim);
        if(validos>maxValidos)
        {
            maxValidos=validos;
        }
        mostrarArrDivGeneral(arr,maxValidos);
        break;
    }
    case 2:
    {
        validos=archivoToArrCT(arr,dim);
        maxValidos=validos;

        validos = archivoToArrJug(arr, dim);
        if(validos>maxValidos)
        {
            maxValidos=validos;
        }
        validos=archivoArrE(arr,dim);
        if(validos>maxValidos)
        {
            maxValidos=validos;
        }

        printf("DIVISION 1\nDIVISION 2\nDIVISION 3\n");
        scanf("%d",&i);

        pos=buscarPosDivision(arr,i,maxValidos);
        if (pos != -1)
        {
            mostrarUnaDivision (arr,pos);
        }
        else
        {
            printf("\nLA DIVISION NO EXISTE\n");
        }
        break;

    }
    case 3:
    {
        char nombre[15];

        validos=archivoToArrCT(arr,dim);
        maxValidos=validos;

        validos = archivoToArrJug(arr, dim);
        if(validos>maxValidos)
        {
            maxValidos=validos;
        }
        validos=archivoArrE(arr,dim);
        if(validos>maxValidos)
        {
            maxValidos=validos;
        }

        printf("INGRESE EL NOMBRE A BUSCAR\n");
        fflush(stdin);
        gets(nombre);
        system("cls");
        mostrarPorNombreDiv(arr,nombre,maxValidos);
        break;
    }
    }
}
