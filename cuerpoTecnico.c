#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "cuerpoTecnico.h"
#include "division.h"
#include "string.h"

const char nombreArchivoCT[30] = "ArchivoCuerpoTecnico.bin";


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
            printf("\n\n\t\tUn dato ingresado no es un numero. Vuelva a ingresar el dato:\n\n\t\t");
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

    FILE *buf=fopen("ArchivoCuerpoTecnico.bin","rb");

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

    FILE *buf=fopen(nombreArchivoCT,"rb");

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

int generarID (registroArchivoCT ct)
{
    FILE *buff=fopen(nombreArchivoCT,"a+b");
    registroArchivoCT aux;
    if (buff!=NULL)
    {
        fseek(buff,sizeof(registroArchivoCT)*(-1),SEEK_END);
        if ((fread(&aux,sizeof(registroArchivoCT),1,buff))>0)
        {
            ct.idCT=(aux.idCT)+1;
        }
        else
        {
            ct.idCT=1;
        }
        fclose(buff);
    }
    return ct.idCT;
}

void cargarCT ()
{
    registroArchivoCT nuevo;
    int flag;
    char validarNum[30];
    char validarString[30];

    FILE* buf=fopen(nombreArchivoCT,"ab");

    if (buf)
    {
        nuevo.idCT=generarID(nuevo);


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
        strcpy(nuevo.telefono,validarNum);

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
        nuevo.sueldo= atof(validarNum);

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
nodoCT* agregarEnOrdenDobleId(nodoCT* lista, nodoCT* nuevoNodo)
{
    if(lista==NULL)
    {
        lista=nuevoNodo;
    }
    else
    {
        if(lista->dato.idCT > nuevoNodo->dato.idCT)
        {
            lista= agregarAlPpioDoble(lista,nuevoNodo);
        }
        else
        {
            nodoCT* ante=lista;
            nodoCT* seg=lista->sig;

            while((seg != NULL) && lista->dato.idCT < nuevoNodo->dato.idCT)
            {
                ante = seg;
                seg = seg->sig;
            }

            if (seg!=NULL)
            {
                seg->ant = nuevoNodo;
                nuevoNodo->sig=seg;
            }
            ante->sig=nuevoNodo;
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
    printf("\n---------- ID: %i ------------", dato.idCT);
    printf("\n|          NOMBRE: %s ",dato.nombre);
    printf("\n|        APELLIDO: %s ",dato.apellido);
    printf("\n|        SUELDO: %.02f ", dato.sueldo);
    printf("\n|             DNI: %d", dato.dni);
    printf("\n|        TELEFONO: %s ", dato.telefono);
    printf("\n|         CARGO: %s ",dato.cargo);

    if (dato.activo==1)
    {
        printf("\n|         ESTADO: ACTIVO");
    }
    else
    {
        printf("\n|          ESTADO: INACTIVO");
    }
    printf("\n-------------------------------");
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
    printf("Telefono: %s \n", dato.telefono);
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

void mostrarNombreCT (nodoCT* ct, char nombre[])
{
    while (ct)
 {
    if (strcmpi(ct->dato.nombre,nombre)==0)
    {
        printf("\nCuerpo Tecnico: \n");
        mostrarEstructuraCT(ct->dato);
    }
    ct=ct->sig;
 }
}

nodoCT* ArchiToListaCT (nodoCT* lista)
{
    FILE* buf=fopen(nombreArchivoCT,"rb");
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
    strcpy(aux.telefono,A.telefono);
    aux.idCT=A.idCT;
    strcpy(aux.nombre,A.nombre);
    strcpy(aux.apellido,A.apellido);
    strcpy(aux.cargo,A.cargo);

    return aux;
}

void mostrarPorCargo (char cargo[])
{
    FILE* buf=fopen(nombreArchivoCT,"rb");
    registroArchivoCT aux;
    if (buf)
    {
        while (fread(&aux,sizeof(registroArchivoCT),1,buf)>0)
        {
            if (strcmpi (aux.cargo,cargo)==0)
            {
                mostrarRegistroArchivoCT(aux);
            }
        }
    }
}

int mostrarPorId (int id)
{
    int flag=0;
    FILE* buf=fopen(nombreArchivoCT,"rb");
    registroArchivoCT aux;

    if (buf)
    {
        while (fread(&aux,sizeof(registroArchivoCT),1,buf)>0)
        {
            if (aux.idCT==id)
            {
                mostrarRegistroArchivoCT(aux);
                flag=1;
            }
        }
    }
    return flag;
}

///Modificar por id en el archivo
int buscarPosIdArchivoCT (int id)
{
    FILE *buffer=fopen(nombreArchivoCT,"rb");
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
    FILE *buffer=fopen(nombreArchivoCT,"r+b");
    registroArchivoCT aux;
    char validarNum[30];
    int flag;

    do
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
            strcpy(A.telefono,validarNum);

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
            A.sueldo= atof(validarNum);
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


///Baja y reactivar

void bajaReactivarPorIdCT (int activar) /// 1 alta 0 baja
{
    FILE *buffer=fopen(nombreArchivoCT,"r+b");
    registroArchivoCT aux;
    char validarNum[30];
    int flag;

    do
    {
        printf("\nIngrese el id: \n");
        fflush(stdin);
        gets(validarNum);
    }
    while((validarNumero(validarNum))!=0);
    aux.idCT= atoi(validarNum);

    flag = validacionIdCT (aux.idCT);
    system("cls");
    if (flag==1)
    {
        int posID = buscarPosIdArchivoCT (aux.idCT);

        if (buffer!=NULL)
        {
            fseek(buffer,sizeof(registroArchivoCT)*(posID),SEEK_SET);
            fread(&aux,sizeof(registroArchivoCT),1,buffer);
            aux.activo=activar;

            fseek(buffer,sizeof(registroArchivoCT)*(posID),SEEK_SET);
            fwrite(&aux,sizeof(registroArchivoCT),1,buffer);
            fclose(buffer);
            printf("Asi quedo: \n");
            mostrarRegistroArchivoCT(aux);
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

void menuCuerpoTecnico (int validos,int dim)
{
    int eleccion,controles,flag,id,pos;
    celdaDivision arr[dim];
    char cargo[20];

    system("cls");
    printf("------> MENU DE CUERPO TECNICO\n\n");
    printf("1.ALTA\n2.BAJA/REACTIVACION\n3.MODIFICAR\n4.LISTA DEL CUERPO TECNICO\n0.SALIR\n\n");
    fflush(stdin);
    scanf("%d",&controles);
    system("cls");
    switch(controles)
    {
    case 1:
    {
        cargarArchivoCT();
        break;
    }
    case 2:
    {
        printf("------> MENU DE BAJA/REACTIVACION\n0 PARA DAR DE BAJA, 1 PARA DAR DE ALTA\n");
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
            printf("OPCION ERRONEA INGRESADA\n");
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
        validos=archivoToArrCT(arr,dim);
        printf("------> MENU DE MOSTRAR\n1.MOSTRAR TODO\n2.MOSTRAR POR CARGO\n3.MOSTRAR POR ID\n4.MOSTRAR POR DIVISION\n");
        scanf("%d",&eleccion);
        system("cls");
        if (eleccion==1)
        {
            mostrarArregloCT(arr,validos);
        }
        else if (eleccion==2)
        {
            printf("INGRESE EL CARGO A MOSTRAR\n");
            fflush(stdin);
            gets(cargo);
            mostrarPorCargo (cargo);
        }
        else if (eleccion==3)
        {
            printf("INGRESE EL ID A BUSCAR\n");
            fflush(stdin);
            scanf("%d",&id);
            flag= mostrarPorId (id);
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
                    mostrarListaCT(arr[pos].ct);
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
                    mostrarListaCT(arr[pos].ct);
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
                    mostrarListaCT(arr[pos].ct);
                }
            }
        }
        break;
    }
    }
}

