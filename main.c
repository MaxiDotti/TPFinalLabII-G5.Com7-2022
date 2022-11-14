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
    int controles;
    int validos=0;
    celdaDivision arr[5];
    do
    {
        system("cls");
        printf("A que menu desea ingresar: \n\n1.Jugador\n2.Empleados\n3.Cuerpo Tecnico\n4.Divisiones\n0.Salir\n\n");
        fflush(stdin);
        scanf("%i",&opcion);
        system("cls");

        if (opcion==1)
        {

        }
        else if (opcion==2)
        {

        }
        else if (opcion==3)
        {
            system("cls");
            printf("Menu de Cuerpo Tecnico\n\n");
            printf("1.Alta\n2.Baja/reactivacion\n3.Modificar\n4.Lista del Cuerpo Tecnico\n0.Salir\n\n");
            fflush(stdin);
            scanf("%d",&controles);
            system("cls");
            switch(controles)
            {
            case 1:
            {
                cargarArchivo();
                break;
            }
            case 2:
            {
                printf("Menu de baja/Reactivacion\nSeleccione 0 para dar de baja, 1 para dar de alta\n");
                scanf("%d",&eleccion);
                if (eleccion == 0)
                {
                    bajaReactivarPorIdCT(0);
                }
                else if (eleccion == 1)
                {
                    bajaReactivarPorIdCT(1);
                }
                else
                {
                    printf("Opcion erronea ingresada\n");
                }
                break;
            }
            case 3:
            {
                modificarCTEleccion();
                break;
            }
            case 4:
            {
                validos=archivoToArrCT(arr,5);
                char cargo[20];
                int id;
                int flag;
                printf("Menu de mostrar\n1.Mostrar todo\n2.Mostrar por cargo\n3.Buscar por id\n");
                scanf("%d",&eleccion);
                system("cls");
                if (eleccion==1)
                {
                    mostrarArregloCT(arr,validos);
                }
                else if (eleccion==2)
                {
                    printf("Ingrese el cargo a mostrar\n");
                    fflush(stdin);
                    gets(cargo);
                    mostrarPorCargo (cargo);
                }
                else if (eleccion==3)
                {
                    printf("Ingrese el id a buscar\n");
                    fflush(stdin);
                    scanf("%d",&id);
                    flag= mostrarPorId (id);
                    if (flag==0)
                    {
                        printf("No se ha encontrado el id\n");
                    }
                }
                break;
            }
            }
        }
        else if (opcion==4)
        {

        }
        else
        {

        }


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
