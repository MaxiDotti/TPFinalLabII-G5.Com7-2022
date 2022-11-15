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
int CargarEmpleado (archiEmpleado nuevo)
{

    int flag = -1;
    int dniAux = 0;

    char validarNum [20];
    char validarString [20];

    FILE * archi=fopen(nombreArchivo,"ab");

    if(archi)
    {
        printf("\nIngrese el dni del empleado: \n");
        scanf("%d",&dniAux);
        flag = validarNumero(dniAux);

        if(flag == 0)
        {
            nuevo.dni = dniAux;

            do
            {
                printf("\nIngrese el legajo del empleado: \n");
                fflush(stdin);
                scanf("%s",&validarNum);
            }
            while((validarNumero(validarNum))!=0);
            nuevo.legajo= atoi(validarNum);

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
            nuevo.tel=(atoi(validarNum));

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
            nuevo.sueldo= atof(validarNum); /// fijarse si esta es la funcion correcta para float

            nuevo.activo=1;/// si lo da de alta es por que va a estra activo

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

    printf("----------------------------");
    printf("\n LEGAJO: %d",nuevo.legajo);
    printf("\n NOMBRE: %s ",nuevo.nombre);
    printf("\n APELLIDO: %s ",nuevo.apellido);
    printf("\n DNI: %d ", nuevo.dni);
    printf("\n TELEFONO: %d ", nuevo.tel);
    printf("\n SUELDO: %f ", nuevo.sueldo);
    if(nuevo.activo == 1)
    {
        printf("\nACTIVO\n");
    }
    else
    {
        printf("\nINACTIVO\n");
    }
    printf("-----------------------------\n");
}

void MostarNodoE (nodoEmpleado * NodoE)
{
    MostrarEmpleado(NodoE->dato);
}

void MostrarListaE (nodoEmpleado * ListaE)
{
    nodoEmpleado * seg = ListaE;

    while(seg->sig != NULL)
    {
        MostarNodoE(ListaE);
        seg = seg->sig;
    }
}
void MostararchEpleado(archiEmpleado nuevo)
{
    printf("----------------------------");
    printf("\n LEGAJO: %d",nuevo.legajo);
    printf("\n NOMBRE: %s ",nuevo.nombre);
    printf("\n APELLIDO: %s ",nuevo.apellido);
    printf("\n DNI: %d ", nuevo.dni);
    printf("\n TELEFONO: %d ", nuevo.tel);
    printf("\n PUESTO: %s ",nuevo.puesto);
    printf("\n SUELDO: %f ", nuevo.sueldo);
    if(nuevo.activo == 1)
    {
        printf("\nACTIVO\n");
    }
    else
    {
        printf("\nINACTIVO\n");
    }
    printf("\n DIVISION: %s",nuevo.nombreDivision);
    printf("\n ID DIVISION: %d",nuevo.idDivision);
    printf("------------------------------\n");
}

void MostarArchiE()
{
    FILE * archi= fopen(nombreArchivo,"rb");
    archiEmpleado aux;
    if(archi)
    {
        while(fread(&aux,sizeof(archiEmpleado),1,archi)>0)
        {
            MostararchEpleado(aux);

        }

        fclose(archi);
    }
    else
    {

        printf("\nEl archivo no se pudo abrir.\n");

    }
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

    if(listaE == NULL)
    {
        listaE = nuevoNodoE;
    }
    else
    {
        nuevoNodoE->sig = listaE;
        listaE = nuevoNodoE;
    }

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

            nuevoNodoE->sig = seg;
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
    nuevo.tel = aux.tel;
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

void modificarE (int activar)
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
    int flag;
    MostarArchiE();
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
            E.tel=(atoi(validarNum));

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
        MostarArchiE();
    }
    while (bucle!=0);
    return E;
}















