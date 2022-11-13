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

void cargarArchivoCT ()
{
    char control='s';
    do
    {
        cargarCT ();
        printf("\nDesea seguir ingresando? s/n\n");
        fflush(stdin);
        scanf("%c",&control);
    }
    while(control!='n');
}

void cargarCT ()
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
            printf("\nIngrese el id: \n");
            fflush(stdin);
            gets(validarNum);
        }
        while((validarNumero(validarNum))!=0);
        nuevo.idCT= atoi(validarNum);

        flag = validacionIdCT (nuevo.idCT);


        if (flag!=1)
        {
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

            fwrite(&nuevo,sizeof(registroArchivoCT),1,buf);

        }
    }
    else
    {
        printf("\nEl archivo no se pudo abrir.\n");
    }
    fclose(buf);
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

nodoCT* agregarEnOrdenDoble(nodoCT* lista, nodoCT* nuevoNodo) ///no funciona creo
{
    if(lista==NULL)
    {
        lista=nuevoNodo;
    }
    else
    {
        if(strcmpi(lista->dato.nombre,nuevoNodo->dato.nombre)<0)
        {
            lista= agregarAlPpioDoble(lista,nuevoNodo);
        }
        else
        {
            nodoCT* ante=lista;
            nodoCT* seg=lista->sig;

            while((seg != NULL) && (strcmpi(nuevoNodo->dato.nombre,seg->dato.nombre)>0))
            {
                ante = seg;
                seg = seg->sig;
            }

            ante->sig=nuevoNodo;
            seg->ant = nuevoNodo;
            nuevoNodo->sig=seg;
            nuevoNodo->ant=ante;
        }
    }
    return lista;
}

void mostrarListaCT (nodoCT* lista)
{
    while(lista!=NULL)
    {
        mostrarEstructuraCT (lista->dato);
        lista=lista->sig;
    }
}

void mostrarEstructuraCT (stCT dato)
{
    printf("\n----------------------------------------------\n");
    printf("ID: %d \n", dato.idCT);
    printf("Nombre: %s \n", dato.nombre);
    printf("Apellido: %s \n", dato.apellido);
    printf("Sueldo: %.02f \n", dato.sueldo);
    printf("DNI: %d \n", dato.dni);
    printf("Telefono: %d \n", dato.telefono);
    printf("Cargo en el cuerpo tecnico: %s \n", dato.cargo);
    if (dato.activo==1)
    {
        printf("Estado: Activo");
    }
    else
    {
        printf("Estado: Inactivo");
    }
    printf("\n----------------------------------------------\n");
}

void mostrarRegistroArchivoCT (registroArchivoCT dato)
{
    printf("\n----------------------------------------------\n");
    printf("Division: %s \n", dato.nombreDivision);
    printf("ID de la division: %d \n", dato.idDivision);
    printf("ID: %d \n", dato.idCT);
    printf("Nombre: %s \n", dato.nombre);
    printf("Apellido: %s \n", dato.apellido);
    printf("Sueldo: %.02f \n", dato.sueldo);
    printf("DNI: %d \n", dato.dni);
    printf("Telefono: %d \n", dato.telefono);
    printf("Cargo en el cuerpo tecnico: %s \n", dato.cargo);
    if (dato.activo==1)
    {
        printf("Estado: Activo");
    }
    else
    {
        printf("Estado: Inactivo");
    }
    printf("\n----------------------------------------------\n");
}

nodoCT* ArchiToListaCT (nodoCT* lista)
{
    FILE* buf=fopen("ArchivoCuerpoTecnico","rb");
    registroArchivoCT nuevo;
    stCT ct;

    if(buf)
    {
        while(fread(&nuevo,sizeof(registroArchivoCT),1,buf)>0)
        {
            ct = registroToCT (nuevo);
            nodoCT* nuevoNodo=crearNodoCT(ct);
            lista=agregarAlPpioDoble(lista,nuevoNodo);
        }
    }
    else
    {
        printf("\nEl archivo no se pudo abrir.\n");
    }
    fclose(buf);

    return lista;
}

stCT registroToCT (registroArchivoCT A)
{
    stCT aux;
    aux.activo=A.activo;
    aux.dni=A.dni;
    aux.sueldo=A.sueldo;
    aux.telefono=A.telefono;
    aux.idCT=A.idCT;
    strcpy(aux.nombre,A.nombre);
    strcpy(aux.apellido,A.apellido);
    strcpy(aux.cargo,A.cargo);

    return aux;
}

nodoCT* buscarPorIdCT (nodoCT* lista, int id)
{
    while(lista!=NULL && lista->dato.idCT != id)
    {
        lista=lista->sig;
    }

    return lista;
}

nodoCT* buscarPorDniCT (nodoCT* lista, int dni)
{
    while(lista!=NULL && lista->dato.dni != dni)
    {
        lista=lista->sig;
    }

    return lista;
}

///Modificar por id en el archivo
int buscarPosIdArchivoCT (int id)
{
    FILE *buffer=fopen("ArchivoCuerpoTecnico","rb");
    registroArchivoCT aux;
    int flag=0;
    int i=0;
    int rta=-1;

    if (buffer)
    {
        while(fread(&aux,sizeof(registroArchivoCT),1,buffer)>0 && flag==0)
        {
            if (aux.idCT == id)
            {
                rta=i;
                flag=1;
            }
            i++;
        }

    }
    return rta;
}
void modificarCTEleccion()
{
    FILE *buffer=fopen("ArchivoCuerpoTecnico","r+b");
    registroArchivoCT aux;
    char validarNum[30];
    int flag;

    do ///No se si va en el menu
    {
        printf("\nIngrese el id: \n");
        fflush(stdin);
        gets(validarNum);
    }
    while((validarNumero(validarNum))!=0);
    aux.idCT= atoi(validarNum);

    flag = validacionIdCT (aux.idCT);


    if (flag==1)
    {
        int posID = buscarPosIdArchivoCT (aux.idCT);

        if (buffer!=NULL)
        {
            fseek(buffer,sizeof(registroArchivoCT)*(posID),SEEK_SET);
            fread(&aux,sizeof(registroArchivoCT),1,buffer);
            aux=modificarDatosCT(aux);

            fseek(buffer,sizeof(registroArchivoCT)*(posID),SEEK_SET);
            fwrite(&aux,sizeof(registroArchivoCT),1,buffer);
            fclose(buffer);

        }
        else
        {
            printf("\nEl archivo no se pudo abrir.\n");
        }
    }
    else
    {
        printf("El id no existe\n");
    }
}

registroArchivoCT modificarDatosCT (registroArchivoCT A)
{
    system("cls");
    printf("\nDatos actuales del ingresado\n");
    int flag;
    mostrarRegistroArchivoCT(A);
    int bucle=0;
    char validarNum[30];
    char validarString[30];

    do
    {
        printf("Menu para modificar\n\n1.Modificar nombre\n2.Modificar apellido\n3.Modificar telefono\n4.Modificar cargo\n5.Modificar sueldo\n6.Modificar DNI\n7.Modificar Division\n0.Salir\n\n");
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
            strcpy(A.nombre,validarString);

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
            strcpy(A.apellido,validarString);

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
            A.telefono=(atoi(validarNum));

            break;
        }
        case 4:
        {
            do
            {
                printf("\nIngrese el cargo en el cuerpo tecnico: \n");
                fflush(stdin);
                gets(validarString);
            }
            while((validarPalabra(validarString))!=0);
            strcpy(A.cargo,validarString);
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
            A.sueldo= atof(validarNum);///no me funciona con comas
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
                A.dni= atoi(validarNum);

                flag= validacionDniCT (A.dni);
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
                strcpy(A.nombreDivision,validarString);

                if(strcmpi(A.nombreDivision,"primera")== 0)
                {
                    A.idDivision =1;
                }
                else if (strcmpi(A.nombreDivision,"segunda")== 0)
                {
                    A.idDivision =2;
                }
                else if (strcmpi(A.nombreDivision,"tercera")== 0)
                {
                    A.idDivision =3;
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
        mostrarRegistroArchivoCT(A);
    }
    while (bucle!=0);
    return A;
}

void bajaPorIdCT ()
{
    FILE *buffer=fopen("ArchivoCuerpoTecnico","r+b");
    registroArchivoCT aux;
    char validarNum[30];
    int flag;

    do ///No se si va en el menu
    {
        printf("\nIngrese el id: \n");
        fflush(stdin);
        gets(validarNum);
    }
    while((validarNumero(validarNum))!=0);
    aux.idCT= atoi(validarNum);

    flag = validacionIdCT (aux.idCT);

    if (flag==1)
    {
        int posID = buscarPosIdArchivoCT (aux.idCT);

        if (buffer!=NULL)
        {
            fseek(buffer,sizeof(registroArchivoCT)*(posID),SEEK_SET);
            fread(&aux,sizeof(registroArchivoCT),1,buffer);
            aux.activo=0;

            fseek(buffer,sizeof(registroArchivoCT)*(posID),SEEK_SET);
            fwrite(&aux,sizeof(registroArchivoCT),1,buffer);
            fclose(buffer);

        }
        else
        {
            printf("\nEl archivo no se pudo abrir.\n");
        }
    }
    else
    {
        printf("El id no existe\n");
    }

}
