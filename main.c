#include <stdio.h>
#include <stdlib.h>
#include "division.h"
#include "empleado.h"
int main()
{
    char archivoJugador[] = "ArchivoJugadores";
    ///cargarJugadorRegistroArchivo(archivoJugador);
    ///mostrarArchivoJugador(archivoJugador);

    arbolJugador *arbol = inicArbol();
    arbol = archivoToArbol(archivoJugador);
    mostrarArbolDNI(arbol);
<<<<<<< HEAD
    arbolJugador *goleador = inicArbol();
    arbolJugador *goleadores = inicArbol();
    int i=0; /// SE INICIALIZA EL CONTADOR EN 0
    goleadores = top3Goleadores(arbol, goleador, goleadores, i);
    printf("\n\n------------------> GOLEADORES\n\n");
    if(goleadores){
        mostrarArbolDNI(goleadores);
    }
    else{
        printf("\nSALIO COMO EL ORTO\n");
    }
/*
    printf("\n\nARBOL ORDENADO POR D.N.I.\n\n");
    mostrarArbolDNI(arbol);
*/
    int corte;
    int opcion=0;
    int eleccion;
    int idAbuscar=0;
    do
    {
        system("cls");
        printf("A que menu desea ingresar: \n\n1.Jugador\n2.Empleados\n3.Cuerpo Tecnico\n4.Divisiones\n0.Salir\n\n");
        fflush(stdin);
        scanf("%i",&opcion);
        system("cls");
=======
>>>>>>> 2c8887f9178ff0453a83311b79ca4c14a36f2adf



        printf("\nPRESIONE 1 PARA VOLVER AL MENU PRINCIPAL / 0 PARA SALIR\n");
        scanf("%i",&corte);
    }
    while(corte==1);

    return 0;
}

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
    FILE* buf=fopen("ArchivoCuerpoTecnico","rb");
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
