#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "cuerpoTecnico.h"
#include "division.h"
#include "string.h"

int validarNumero (char numeros[])
{
    int i=0;
    int flag=0;

    while(i<strlen(numeros) && flag==0)
    {
        if ((isdigit(numeros[i]))!=0)
        {
            i++;
        }
        else
        {
            printf("\n\n\t\tUn dato ingresado no es un numero.Vuelva a ingresar el dato:\n\n\t\t");
            flag=1;
        }
    }

    return flag;
}

int validarPalabra (char palabra[])
{
    int i=0;
    int flag=0;

    while(i<strlen(palabra) && flag==0)
    {
        if ((isalpha(palabra[i]))!=0 || (isspace(palabra[i])!=0))
        {
            i++;
        }
        else
        {
            printf("\n\n\t\tIngreso un caracter erroneo. Solo ingrese letras: \n\n\t\t");
            flag=1;
        }
    }

    return flag;
}

int validacionIdCT (int idCT) // recorriendo el archivo y verifica si existe
{
    int flag=0;
    registroArchivoCT aux;

    FILE *buf=fopen("ArchivoCuerpoTecnico","rb");

    if (buf!=NULL)
    {
        while(fread(&aux,sizeof(registroArchivoCT),1,buf)>0 && flag == 0)
        {
            if (aux.idCT == idCT)
            {
                printf("\n\n\t\tEl id ya se encuentra cargado en el archivo.\n\n\t\t"); // si ya exite corta la busqueda con el flag si no el cliente se puede agregar a la lista.
                flag = 1;
            }
        }
        fclose(buf);
    }
    else
    {
        printf("\n\n\t\tNo pudo abrirse el archivo.\n\n\t\t");
    }

    return flag;
}

int validacionDniCT (int dni)
{
    int flag=0;
    registroArchivoCT aux;

    FILE *buf=fopen("ArchivoCuerpoTecnico","rb");

    if (buf!=NULL)
    {
        while(fread(&aux,sizeof(registroArchivoCT),1,buf)>0 && flag == 0)
        {
            if (aux.dni == dni)
            {
                printf("\n\n\t\tEl dni ya se encuentra cargado en el archivo.\n\n\t\t"); // si ya exite corta la busqueda con el flag si no el cliente se puede agregar a la lista.
                flag = 1;
            }
        }
        fclose(buf);
    }
    else
    {
        printf("\n\n\t\tNo pudo abrirse el archivo.\n\n\t\t");
    }

    return flag;
}

registroArchivoCT cargarCT ()
{
    registroArchivoCT nuevo;
    int flag=-1;
    char validarNum[30];
    char validarString[30];

    FILE* buf=fopen("ArchivoCuerpoTecnico","ab");

    if (buf)
    {
        do
        {
            do
            {
                printf("\nIngrese el id: \n");
                fflush(stdin);
                gets(validarNum);
            }
            while((validarNumero(validarNum))!=0);
            nuevo.idCT= atoi(validarNum);

            flag = validacionIdCT (nuevo.idCT);
        }
        while(flag==1);

        do
        {
            printf("\nIngrese el nombre: \n");
            fflush(stdin);
            gets(validarString);
        }
        while((validarPalabra(validarString))!=0);
        strcpy(nuevo.nombre,validarString);

        do
        {
            printf("\nIngrese el apellido:\n");
            fflush(stdin);
            gets(validarString);
        }
        while((validarPalabra(validarString))!=0);
        strcpy(nuevo.apellido,validarString);

        do
        {
            do
            {
                printf("\nIngrese el dni: \n");
                fflush(stdin);
                gets(validarNum);
            }
            while((validarNumero(validarNum))!=0);
            nuevo.dni= atoi(validarNum);

            flag= validacionDniCT (nuevo.dni);
        }
        while (flag==1);

        do
        {
            printf("\nIngrese el numero de telefono :\n");
            fflush(stdin);
            scanf("%s",validarNum);
        }
        while ((validarNumero(validarNum))!=0);
        nuevo.telefono=(atoi(validarNum));

        do
        {
            printf("\nIngrese el cargo en el cuerpo tecnico: \n");
            fflush(stdin);
            gets(validarString);
        }
        while((validarPalabra(validarString))!=0);
        strcpy(nuevo.cargo,validarString);

        do
        {
            printf("\nIngrese el sueldo:\n");
            fflush(stdin);
            gets(validarNum);
        }
        while((validarNumero(validarNum))!=0);
        nuevo.sueldo= atof(validarNum);///no me funciona con comas

        nuevo.activo=1;

        do
        {
            flag=0;
            do
            {
                printf("\nIngrese la categoria a la que pertenece\n");
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
            else if (strcmpi(nuevo.nombreDivision,"tercera")== 0)
            {
                nuevo.idDivision =3;
            }
            else
            {
                printf("\nCategoria erronea, vuelva a ingresar\n");
                flag=1;
            }
        }
        while (flag==1);
    }
    fclose(buf);


    return nuevo;

}

nodoCT* inicListaDoble ()
{
    return NULL;
}

nodoCT* crearNodoCT(stCT dato)
{
    nodoCT* aux=(nodoCT*)malloc(sizeof(nodoCT));
    aux->dato=dato;
    aux->sig=NULL;
    aux->ant=NULL;

    return aux;
}

nodoCT* agregarAlPpioDoble(nodoCT* lista, nodoCT* nuevoNodo)
{
    if(lista!=NULL)
    {
        nuevoNodo->sig=lista;
        lista->ant=nuevoNodo;
    }
    lista=nuevoNodo;

    return lista;
}

void mostrarListaCT (nodoCT* lista)
{
    while(lista!=NULL)
    {
        printf("\n----------------------------------------------\n");
        printf("ID: %d \n", lista->dato.idCT);
        printf("Nombre: %s \n", lista->dato.nombre);
        printf("Apellido: %s \n", lista->dato.apellido);
        printf("Sueldo: %.02f \n", lista->dato.sueldo);
        printf("DNI: %d \n", lista->dato.dni);
        printf("Telefono: %d \n", lista->dato.telefono);
        printf("Cargo en el cuerpo tecnico: %s \n", lista->dato.cargo);
        if (lista->dato.activo==1)
        {
            printf("Estado: Activo");
        }
        else
        {
            printf("Estado: Inactivo");
        }
        printf("\n----------------------------------------------\n");
        lista=lista->sig;
    }

}

