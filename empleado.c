#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "empleado.h"
#include "string.h"
#include "division.h"

int validarNumero2 (char numeros[]) // retorna 0 si el nro esta ok 1 si ingreso otro caracter
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

int validarPalabra2 (char palabra[]) // retorna 0 si la palabra esta ok 1 si ingreso otro caracter
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


int validacionDeAlta (int legajo) // recorriendo el archivo y verifica si existe
{
    int flag=0;
    archiEmpleado aux;

    FILE *archi=fopen("ArchivoEmpleados","rb");

    if (archi!=NULL)
    {
        while(fread(&aux,sizeof(archiEmpleado),1,archi)>0 && flag == 0)
        {
           if (aux.legajo == legajo)
           {
              printf("\n\n\t\tEl cliente ya se encuentra cargado en el archivo.\n\n\t\t"); // si ya exite corta la busqueda con el flag si no el cliente se puede agregar a la lista.
              flag = 1;
           }
        }
        fclose(archi);
    }
    else
    {
        printf("\n\n\t\tNo pudo abrirse el archivo.\n\n\t\t");
    }

    return flag;
}

int CargarEmpleado (archiEmpleado nuevo)
{

    int flag = -1;
    int legajoAux = 0;

    char validarNum [20];
    char validarString [20];

    FILE*archi=fopen("ArchivoEmpleados","ab");

    if(archi)
    {
        printf("\nIngrese el legajo del empleado: \n");
        fflush(stdin);
        scanf("%d",&legajoAux);
        flag = validacionDeAlta(legajoAux);

        if(flag == 0)
        {
            nuevo.legajo = legajoAux;

            do{
                printf("\nIngrese el nombre  del empleado: \n");
                fflush(stdin);
                gets(validarString);
               }while((validarPalabra(validarString))!=0);
               strcpy(nuevo.nombre,validarString);

               do{
                printf("\nIngrese el apellido del empleado:\n");
                fflush(stdin);
                gets(validarString);
               }while((validarPalabra(validarString))!=0);
               strcpy(nuevo.apellido,validarString);

               do{
                printf("\n Ingrese el dni: \n");
                fflush(stdin);
                scanf("%s",&validarNum);
               }while((validarNumero(validarNum))!=0);
               nuevo.dni= atoi(validarNum);

               do{
                printf("\nIngrese el numero de telefono :\n");
                fflush(stdin);
                scanf("%s",validarNum);
               }while ((validarNumero(validarNum))!=0);
               nuevo.tel=(atoi(validarNum));

               do{
                printf("\n Ingrese el puesto del empleado: \n");
                fflush(stdin);
                gets(validarString);
               }while((validarPalabra(validarString))!=0);
               strcpy(nuevo.puesto,validarString);

               do{
                printf("\n Ingrese el sueldo del empleado:\n");
                fflush(stdin);
                scanf("%f",&validarNum);
               }while((validarNumero(validarNum))!=0);
               nuevo.sueldo= atof(validarNum); /// fojarse si esta es la funcion correcta para float

               nuevo.activo=1;/// si lo da de alta es por que va a estra activo

               do{
                printf("\nIngrese la categoria a la que pertenece el empleado\n");
                fflush(stdin);
                gets(validarString);
               }while((validarPalabra(validarString))!=0);
               strcpy(nuevo.nombreDivision,validarString);

               if(strcmpi(nuevo.nombreDivision,"primera")== 0)
               {
                   nuevo.idDivision =1;
               }
               else if (strcmpi(nuevo.nombreDivision,"segunda")== 0)
               {
                   nuevo.idDivision =2;
               }
               else{
                nuevo.idDivision =3;
               }
            fclose(archi);

        }



    }
    else{
        printf("\nEl archivo no se pudo abrir.\n");
    }

    return flag; // si el cliente ya existe retorna 1

}








