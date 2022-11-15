#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "empleado.h"
#include "string.h"
#include "division.h"


const char nombreArchivo[20] = "ArchivoEmpleados";



int validacionDeAlta2 (int dni) // recorriendo el archivo y verifica si existe
{
    int flag=0;
    archiEmpleado aux;

    FILE*archi=fopen(nombreArchivo,"rb");

    if (archi!=NULL)
    {
        while(fread(&aux,sizeof(archiEmpleado),1,archi)>0 && flag == 0)
        {
            if (aux.dni == dni)
            {
                printf("\nEl empleado ya se encuentra cargado en el archivo.\n"); // si ya exite corta la busqueda con el flag si no el cliente se puede agregar a la lista.
                flag = 1;
            }
        }
        fclose(archi);
    }
    else
    {
        printf("\nNo pudo abrirse el archivo.\n");
    }

    return flag;
}

int validacionDeLegajo2 (int legajo) // recorriendo el archivo y verifica si existe
{
    int flag=0;
    archiEmpleado aux;

    FILE*archi=fopen(nombreArchivo,"rb");

    if (archi!=NULL)
    {
        while(fread(&aux,sizeof(archiEmpleado),1,archi)>0 && flag == 0)
        {
            if (aux.legajo == legajo)
            {
                flag = 1;
            }
        }
        fclose(archi);
    }
    else
    {
        printf("\nNo pudo abrirse el archivo.\n");
    }

    return flag;
}

int generarLegajo (archiEmpleado nuevo)
{
    FILE *buff=fopen(nombreArchivo,"a+b");
    archiEmpleado aux;
    if (buff!=NULL)
    {
        fseek(buff,sizeof(archiEmpleado)*(-1),SEEK_END);

        if ((fread(&aux,sizeof(archiEmpleado),1,buff))>0)
        {
            nuevo.legajo=(aux.legajo)+1;
        }
        else
        {
            nuevo.legajo=1;
        }
        fclose(buff);
    }
    return nuevo.legajo;
}


///Carga
void CargarArchivoE ()
{
    char control='s';
    int flag=0;
    do
    {
        flag=CargarEmpleado();
        if (flag!=0)
        {
            printf("\nYa se encuentra cargado el dni\n");
        }
        printf("\nDesea seguir ingresando? s/n\n");
        fflush(stdin);
        scanf("%c",&control);
    }
    while(control!='n');
}



///Carga
int CargarEmpleado ()
{
    archiEmpleado nuevo;
    int flag = -1;

    char validarNum [20];
    char validarString [20];

    FILE * archi=fopen(nombreArchivo,"ab");

    if(archi)
    {
        do
        {
            printf("\nIngrese el dni del empleado: \n");
            fflush(stdin);
            gets(validarNum);
        }
        while((validarNumero(validarNum))!=0);
        nuevo.dni= atoi(validarNum);
        flag=validacionDeAlta2(nuevo.dni);///arreglado


        if(flag == 0)
        {

            nuevo.legajo=generarLegajo(nuevo);

            do
            {
                printf("\nIngrese el nombre  del empleado: \n");
                fflush(stdin);
                gets(validarString);
            }
            while((validarPalabra(validarString))!=0);
            strcpy(nuevo.nombre,validarString);

            do
            {
                printf("\nIngrese el apellido del empleado:\n");
                fflush(stdin);
                gets(validarString);
            }
            while((validarPalabra(validarString))!=0);
            strcpy(nuevo.apellido,validarString);


            do
            {
                printf("\nIngrese el numero de telefono :\n");
                fflush(stdin);
                scanf("%s",&validarNum);
            }
            while ((validarNumero(validarNum))!=0);
            strcpy(nuevo.tel,validarNum);

            do
            {
                printf("\n Ingrese el puesto del empleado: \n");
                fflush(stdin);
                gets(validarString);
            }
            while((validarPalabra(validarString))!=0);
            strcpy(nuevo.puesto,validarString);

            do
            {
                printf("\n Ingrese el sueldo del empleado:\n");
                fflush(stdin);
                scanf("%s",&validarNum);
            }
            while((validarNumero(validarNum))!=0);
            nuevo.sueldo= atof(validarNum);

            nuevo.activo=1;/// alta

            do
            {
                printf("\nIngrese la categoria a la que pertenece el empleado\n");
                fflush(stdin);
                gets(validarString);
            }
            while((validarPalabra(validarString))!=0);
            strcpy(nuevo.nombreDivision,validarString);

            if(strcmpi(nuevo.nombreDivision,"primera")== 0)
            {
                nuevo.idDivision =1;
            }
            else if (strcmpi(nuevo.nombreDivision,"segunda")== 0)
            {
                nuevo.idDivision =2;
            }
            else
            {
                nuevo.idDivision =3;
            }

            fwrite(&nuevo,sizeof(archiEmpleado),1,archi);

        }
        fclose(archi);

    }
    else
    {
        printf("\nEl archivo no se pudo abrir.\n");
    }

    return flag; // si el cliente ya existe retorna 1

}

///Mostrar
void MostrarEmpleado (stEmpleado nuevo)
{


    printf("\n---------- LEGAJO: %i ----------", nuevo.legajo);
    printf("\n|          NOMBRE: %s ",nuevo.nombre);
    printf("\n|        APELLIDO: %s ",nuevo.apellido);
    printf("\n|             DNI: %d", nuevo.dni);
    printf("\n|        TELEFONO: %s ", nuevo.tel);
    printf("\n|        PUESTO: %s ",nuevo.puesto);
    printf("\n|        SUELDO: %.02f ", nuevo.sueldo);
    if(nuevo.activo == 1)
    {
        printf("\n|          ESTADO: ACTIVO");
    }
    else
    {
        printf("\n|          ESTADO: INACTIVO");
    }
    printf("\n-------------------------------");
}



void MostrarListaE (nodoEmpleado * ListaE)
{

    while(ListaE != NULL)
    {
        MostrarEmpleado(ListaE->dato);
        ListaE = ListaE->sig;
    }
}
void MostrararchEmpleado(archiEmpleado nuevo)
{
    printf("\n---------- LEGAJO: %i ----------", nuevo.legajo);
    printf("\n|          NOMBRE: %s ",nuevo.nombre);
    printf("\n|        APELLIDO: %s ",nuevo.apellido);
    printf("\n|             DNI: %d", nuevo.dni);
    printf("\n|        TELEFONO: %s ", nuevo.tel);
    printf("\n|        PUESTO: %s ",nuevo.puesto);
    printf("\n|        SUELDO: %.02f ", nuevo.sueldo);
    if(nuevo.activo == 1)
    {
        printf("\n|          ESTADO: ACTIVO");
    }
    else
    {
        printf("\n|          ESTADO: INACTIVO");
    }
    printf("\n|        DIVISION: %s",nuevo.nombreDivision);
    printf("\n|        ID DIVISION: %d\n",nuevo.idDivision);
}


void MostrarArchiE()
{
    FILE * archi= fopen(nombreArchivo,"rb");
    archiEmpleado aux;
    if(archi)
    {
        while(fread(&aux,sizeof(archiEmpleado),1,archi)>0)
        {
            MostrararchEmpleado(aux);
        }

        fclose(archi);
    }
    else
    {

        printf("\nEl archivo no se pudo abrir.\n");

    }
}

void mostrarNombreE(nodoEmpleado* emp, char nombre[])
{
    while (emp)
    {
        if (strcmpi(emp->dato.nombre,nombre)==0)
        {
            printf("\nEmpleados: \n");
            MostrarEmpleado(emp->dato);
        }
        emp=emp->sig;
    }
}

void mostrarPorPuesto (char puesto[])
{
    FILE* buf=fopen(nombreArchivo,"rb");
    archiEmpleado aux;
    if (buf)
    {
        while (fread(&aux,sizeof(archiEmpleado),1,buf)>0)
        {
            if (strcmpi (aux.puesto,puesto)==0)
            {
                MostrararchEmpleado(aux);
            }
        }
    }
}

int mostrarPorLegajo (int legajo)
{
    int flag=0;
    FILE* buf=fopen(nombreArchivo,"rb");
    archiEmpleado aux;

    if (buf)
    {
        while (fread(&aux,sizeof(archiEmpleado),1,buf)>0)
        {
            if (aux.legajo==legajo)
            {
                MostrararchEmpleado(aux);
                flag=1;
            }
        }
    }
    return flag;
}
/// Funciones Lista

nodoEmpleado * inicListaS()
{

    return NULL;

}

nodoEmpleado * crearNodoS(stEmpleado nuevo)
{

    nodoEmpleado * aux = malloc(sizeof(nodoEmpleado));

    aux->dato = nuevo;
    aux->sig = NULL;

    return aux;

}


nodoEmpleado * agregarPpioS (nodoEmpleado * listaE, nodoEmpleado * nuevoNodoE)
{

    if(listaE!=NULL)
    {
        nuevoNodoE->sig=listaE;
    }
    listaE=nuevoNodoE;

    return listaE;
}

nodoEmpleado * agregarEnOrden(nodoEmpleado * listaE, nodoEmpleado * nuevoNodoE)
{

    if(listaE == NULL)
    {
        listaE = nuevoNodoE;
    }
    else
    {


        if(strcmp(nuevoNodoE->dato.nombre,listaE->dato.nombre)<0)
        {
            listaE = agregarPpioS(listaE, nuevoNodoE);
        }
        else
        {

            nodoEmpleado * ante = listaE;
            nodoEmpleado * seg = listaE->sig;

            while((seg != NULL) && (strcmp(nuevoNodoE->dato.nombre,seg->dato.nombre)>0))
            {
                ante = seg;
                seg = seg->sig;
            }

            if (seg)
            {
                nuevoNodoE->sig = seg;
            }
            ante->sig = nuevoNodoE;
        }
    }
    return listaE;
}

nodoEmpleado * buscarNodoE (nodoEmpleado * listaE, int dni)
{

    nodoEmpleado * seg;

    while ((seg != NULL) && ( dni != seg->dato.dni))
    {
        seg=seg->sig;
    }

    return seg;
}
stEmpleado nuevoEmpleado(archiEmpleado aux)
{
    stEmpleado nuevo;

    nuevo.legajo = aux.legajo;
    strcpy(nuevo.nombre,aux.nombre);
    strcpy(nuevo.apellido,aux.apellido);
    nuevo.dni = aux.dni;
    strcpy(nuevo.tel,aux.tel);
    strcpy(nuevo.puesto,aux.puesto);
    nuevo.sueldo = aux.sueldo;
    nuevo.activo = aux.activo;

    return nuevo;
}

nodoEmpleado * ArchiaListaE (nodoEmpleado * listaE)
{
    FILE * archi = fopen(nombreArchivo,"rb");
    archiEmpleado aux;
    stEmpleado nuevo;

    while(fread(&aux,sizeof(archiEmpleado),1,archi)>0)
    {
        nuevo = nuevoEmpleado(aux);
        nodoEmpleado * nuevoNdo = crearNodoS(nuevo);
        listaE = agregarEnOrden(listaE,nuevoNdo);
    }

    return listaE;
}

nodoEmpleado * borrarNodoE(nodoEmpleado* listaE, int dni)
{
    nodoEmpleado * seg;
    nodoEmpleado * ante;
    if((listaE != NULL) && (listaE->dato.dni == dni ))
    {

        nodoEmpleado * aux = listaE;
        listaE = listaE->sig;
        free(aux);
    }
    else
    {
        seg = listaE;
        while((seg != NULL) && (listaE->dato.dni != dni))
        {
            ante = seg;
            seg = seg->sig;
        }

        if(seg!=NULL)
        {
            ante->sig = seg->sig;
            free(seg);

        }
    }
    return listaE;
}

///Baja y reactivar

int buscarPosLegajoArchivoE (int legajo)
{
    FILE *buffer=fopen(nombreArchivo,"rb");
    archiEmpleado aux;
    int flag=0;
    int i=0;
    int rta=-1;

    if (buffer)
    {
        while(fread(&aux,sizeof(archiEmpleado),1,buffer)>0 && flag==0)
        {
            if (aux.legajo == legajo)
            {
                rta=i;
                flag=1;
            }
            i++;
        }

    }
    return rta;
}

void bajaReactivarPorLegajoE (int activar) /// 1 alta 0 baja
{
    FILE *buffer=fopen(nombreArchivo,"r+b");
    archiEmpleado aux;
    char validarNum[30];
    int flag;


    do
    {
        printf("\nIngrese el legajo: \n");
        fflush(stdin);
        gets(validarNum);
    }
    while((validarNumero(validarNum))!=0);
    aux.legajo= atoi(validarNum);

    flag = validacionDeLegajo2(aux.legajo);

    if (flag==1)
    {
        int posLegajo = buscarPosLegajoArchivoE (aux.legajo);

        if (buffer!=NULL)
        {
            fseek(buffer,sizeof(archiEmpleado)*(posLegajo),SEEK_SET);
            fread(&aux,sizeof(archiEmpleado),1,buffer);
            aux.activo=activar;

            fseek(buffer,sizeof(archiEmpleado)*(posLegajo),SEEK_SET);
            fwrite(&aux,sizeof(archiEmpleado),1,buffer);
            fclose(buffer);

            printf("Asi quedo: \n");
            MostrararchEmpleado(aux);
        }
        else
        {
            printf("\nEl archivo no se pudo abrir.\n");
        }
    }
    else
    {
        printf("El Legajo no existe\n");
    }

}

void modificarE ()
{
    FILE *buffer=fopen(nombreArchivo,"r+b");
    archiEmpleado aux;
    char validarNum[30];
    int flag;

    do
    {
        printf("\nIngrese el legajo: \n");
        fflush(stdin);
        gets(validarNum);
    }
    while((validarNumero(validarNum))!=0);
    aux.legajo= atoi(validarNum);

    flag = validacionDeLegajo2(aux.legajo);
    if (flag==1)
    {
        int posLegajo = buscarPosLegajoArchivoE (aux.legajo);

        if (buffer!=NULL)
        {
            fseek(buffer,sizeof(archiEmpleado)*(posLegajo),SEEK_SET);
            fread(&aux,sizeof(archiEmpleado),1,buffer);
            aux= modificarDatosE (aux);

            fseek(buffer,sizeof(archiEmpleado)*(posLegajo),SEEK_SET);
            fwrite(&aux,sizeof(archiEmpleado),1,buffer);
            fclose(buffer);
        }
        else
        {
            printf("\nEl archivo no se pudo abrir.\n");
        }
    }
    else
    {
        printf("El Legajo no existe\n");
    }

}

///modificar


archiEmpleado modificarDatosE (archiEmpleado  E)
{
    system("cls");
    printf("\nDatos actuales del ingresado\n");
    MostrararchEmpleado(E);
    int flag;
    int bucle=0;
    char validarNum[30];
    char validarString[30];

    do
    {
        printf("Menu para modificar\n\n1.Modificar nombre\n2.Modificar apellido\n3.Modificar telefono\n4.Modificar puesto\n5.Modificar sueldo\n6.Modificar DNI\n7.Modificar Division\n0.Salir\n\n");
        fflush(stdin);
        scanf("%i",&bucle);
        switch (bucle)
        {
        case 0:
        {
            break;
        }
        case 1:
        {
            do
            {
                printf("\nIngrese el nombre: \n");
                fflush(stdin);
                gets(validarString);
            }
            while((validarPalabra(validarString))!=0);
            strcpy(E.nombre,validarString);

            break;
        }
        case 2:
        {
            do
            {
                printf("\nIngrese el apellido:\n");
                fflush(stdin);
                gets(validarString);
            }
            while((validarPalabra(validarString))!=0);
            strcpy(E.apellido,validarString);

            break;
        }
        case 3:
        {
            do
            {
                printf("\nIngrese el numero de telefono :\n");
                fflush(stdin);
                scanf("%s",validarNum);
            }
            while ((validarNumero(validarNum))!=0);
            strcpy(E.tel,validarNum);

            break;
        }
        case 4:
        {
            do
            {
                printf("\nIngrese el puesto: \n");
                fflush(stdin);
                gets(validarString);
            }
            while((validarPalabra(validarString))!=0);
            strcpy(E.puesto,validarString);
            break;
        }
        case 5:
        {
            do
            {
                printf("\nIngrese el sueldo:\n");
                fflush(stdin);
                gets(validarNum);
            }
            while((validarNumero(validarNum))!=0);
            E.sueldo= atof(validarNum);///no me funciona con comas
            break;
        }
        case 6:
        {
            do
            {
                do
                {
                    printf("\nIngrese el dni: \n");
                    fflush(stdin);
                    gets(validarNum);
                }
                while((validarNumero(validarNum))!=0);
                E.dni= atoi(validarNum);

                flag= validacionDeAlta2(E.dni);
            }
            while (flag==1);

            break;
        }
        case 7:
        {
            do
            {
                flag=0;
                do
                {
                    printf("\nIngrese la nueva categoria\n");
                    fflush(stdin);
                    gets(validarString);
                }
                while((validarPalabra(validarString))!=0);
                strcpy(E.nombreDivision,validarString);

                if(strcmpi(E.nombreDivision,"primera")== 0)
                {
                    E.idDivision =1;
                }
                else if (strcmpi(E.nombreDivision,"segunda")== 0)
                {
                    E.idDivision =2;
                }
                else if (strcmpi(E.nombreDivision,"tercera")== 0)
                {
                    E.idDivision =3;
                }
                else
                {
                    printf("\nCategoria erronea, vuelva a ingresar\n");
                    flag=1;
                }
            }
            while (flag==1);

            break;
        }

        default:
        {
            system("cls");
            printf("Numero equivocado, elija otra vez\n");
            break;
        }
        }
        system("cls");
        printf("\nAsi quedo modificado\n");
        MostrararchEmpleado(E);
    }
    while (bucle!=0);
    return E;
}


void menuEmpleados (int validos, int dim)
{
    int eleccion,controles,legajo,flag,pos;
    celdaDivision arr[dim];
    char puesto[15];


    system("cls");
    printf("------> MENU DE EMPLEADOS\n\n");
    printf("1.ALTA\n2.BAJA/REACTIVACION\n3.MODIFICAR\n4.LISTA DE EMPLEADOS\n0.SALIR\n\n");
    fflush(stdin);
    scanf("%d",&controles);
    system("cls");
    switch(controles)
    {
    case 1:
    {
        CargarArchivoE();
        break;
    }
    case 2:
        printf("------> MENU DE BAJA/REACTIVACION\n0 PARA DAR DE BAJA, 1 PARA DAR DE ALTA\n");
        scanf("%d",&eleccion);
        if (eleccion == 0)
        {
            bajaReactivarPorLegajoE(0);
        }
        else if (eleccion == 1)
        {
            bajaReactivarPorLegajoE(1);
        }
        else
        {
            printf("OPCION ERRONEA INGRESADA\n");
        }

        break;
    case 3:
    {
        modificarE();
    }
    case 4:
    {
        validos= archivoArrE (arr, dim);
        printf("%d",validos);
        printf("------> MENU DE MOSTRAR\n1.MOSTRAR TODO\n2.MOSTRAR POR PUESTO\n3.MOSTRAR POR ID\n4.MOSTRAR POR DIVISION\n");
        scanf("%d",&eleccion);
        system("cls");
        if (eleccion==1)
        {
            mostrarArregloEmpleado(arr,validos);
        }
        else if (eleccion==2)
        {
            printf("INGRESE EL PUESTO A MOSTRAR\n");
            fflush(stdin);
            gets(puesto);
            mostrarPorPuesto (puesto);
        }
        else if(eleccion==3)
        {
            printf("INGRESE EL LEGAJO A BUSCAR\n");
            fflush(stdin);
            scanf("%d",&legajo);
            flag= mostrarPorLegajo (legajo);
            if (flag==0)
            {
                printf("NO SE HA ENCONTRADO DEL ID\n");
            }
        }
        else if (eleccion==4)
        {
            printf("DIVISION 1\nDIVISION 2\nDIVISION 3\n");
            scanf("%d",&eleccion);
            system("cls");
            if (eleccion==1)
            {
                printf("DIVISION 1\n");
                pos=buscarPosDivision(arr,1,validos);
                if (pos==-1)
                {
                    printf("No existe la division\n");
                }
                else
                {
                    MostrarListaE (arr[pos].emp);
                }
            }
            else if (eleccion==2)
            {
                printf("DIVISION 2\n");
                pos=buscarPosDivision(arr,2,validos);
                if (pos==-1)
                {
                    printf("No existe la division\n");
                }
                else
                {
                    MostrarListaE (arr[pos].emp);
                }
            }
            else if (eleccion==3)
            {
                printf("DIVISION 3\n");
                pos=buscarPosDivision(arr,3,validos);
                if (pos==-1)
                {
                    printf("NO EXISTE LA DIVISION\n");
                }
                else
                {
                    MostrarListaE (arr[pos].emp);
                }
            }
        }
    }
    }
}












