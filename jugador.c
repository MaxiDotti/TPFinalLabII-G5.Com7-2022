#include "jugador.h"
#include <string.h>

registroArchivoJugador cargarUnJugador(int dni, int legajo){
    registroArchivoJugador aux;

    aux.dni = dni;
    aux.legajo = legajo+1;

    printf("\nNOMBRE DIVISION: ");
    fflush(stdin);
    gets(aux.nombreDivision);

    printf("ID DIVISION: ");
    fflush(stdin);
    scanf("%i", &aux.idDivision);

    printf("NOMBRE: ");
    fflush(stdin);
    gets(aux.nombre);

    printf("APELLIDO: ");
    fflush(stdin);
    gets(aux.apellido);

    printf("POSICION: ");
    fflush(stdin);
    gets(aux.posicion);

    printf("SUELDO: ");
    fflush(stdin);
    scanf("%f", &aux.sueldo);

    printf("VALOR PASE: ");
    fflush(stdin);
    scanf("%f", &aux.valorpase);

    printf("GOLES: ");
    fflush(stdin);
    scanf("%i", &aux.goles);

    aux.activo = 1;

    return aux;
}

int verificarDNIenArchivo (FILE *buf, int dni){
    registroArchivoJugador aux;
    int flag=0;

    fseek(buf, 0, 0);
    while ((fread (&aux, sizeof(registroArchivoJugador), 1, buf) > 0) && flag != -1) /// verifica si el DNI ingresado es de un cliente ya existente.
    {
        if (dni == aux.dni){
            flag = -1;
        }
        else{
            flag = aux.legajo;
        }
    }
    return flag;
}

void cargarJugadorRegistroArchivo(char archiJugador[]){
    FILE *buf = fopen (archiJugador, "a+b");
    registroArchivoJugador nuevo;
    char control = 's';
    int flag=0, dni=0;

    if(!buf){
        printf("\nEL ARCHIVO NO SE PUEDE ABRIR.\n");
    }
    else{
        while(control == 's' || control == 'S'){
            printf("\n-------> COMPLETE LOS DATOS SEGUN CORRESPONDA <-------\n\n");
            printf("\nDNI: ");
            scanf("%i", &dni);
            flag = verificarDNIenArchivo(buf, dni);
            if(flag != -1){ /// SI EL DNI NO EXISTE EN EL ARCHIVO, CARGA EL JUGADOR
                nuevo = cargarUnJugador(dni, flag); /// FLAG = ULTIMO NUMERO DE LEGAJO CARGADO EN EL ARCHIVO
                fwrite(&nuevo, sizeof(registroArchivoJugador), 1, buf);
                system("cls");
            }
            else{
                printf("\nEL DNI CARGADO YA EXISTE EN EL SISTEMA.\n");
            }
            printf("DESEA SEGUIR CARGANDO JUGADORES? s/n: ");
            fflush(stdin);
            scanf("%c", &control);
            system("cls");
        }
        fclose(buf);
    }
}

void mostrarUnJugadorRegistro(registroArchivoJugador aux){
    printf("\n---------- LEGAJO: %i ----------", aux.legajo);
    printf("\n| NOMBRE DIVISION: %s", aux.nombreDivision);
    printf("\n|     ID DIVISION: %i", aux.idDivision);
    printf("\n|          NOMBRE: %s", aux.nombre);
    printf("\n|        APELLIDO: %s", aux.apellido);
    printf("\n|             DNI: %i", aux.dni);
    printf("\n|        POSICION: %s", aux.posicion);
    printf("\n|          SUELDO: %.2f", aux.sueldo);
    printf("\n|      VALOR PASE: %.2f", aux.valorpase);
    printf("\n|           GOLES: %i", aux.goles);
    if(aux.activo == 1){
        printf("\n|          ESTADO: ACTIVO");
    }
    else{
        printf("\n|          ESTADO: INACTIVO");
    }
    printf("\n-------------------------------");
}

void mostrarArchivoJugador(char archiJugador[]){
    FILE *buf = fopen (archiJugador, "rb");
    registroArchivoJugador aux;

    if(!buf){
        printf("\nEL ARCHIVO NO SE PUEDE ABRIR.\n");
    }
    else{
        while(fread(&aux, sizeof(registroArchivoJugador), 1, buf) > 0){
            mostrarUnJugadorRegistro(aux);
        }
        fclose(buf);
    }
}

registroArchivoJugador bajaJugador(registroArchivoJugador aux){
    aux.activo = 0;
    return aux;
}

void bajaJugadorArchivo(char archiJugador[], int dni){
    FILE *buf = fopen (archiJugador, "r+b");
    registroArchivoJugador aux;
    int flag=0;

    if(!buf){
        printf("\nEL ARCHIVO NO SE PUEDE ABRIR.\n");
    }
    else{
        while(fread(&aux, sizeof(registroArchivoJugador), 1, buf) > 0 && flag==0){
            if(aux.dni == dni){
                aux = bajaJugador(aux);
                flag = 1;
                fseek(buf, sizeof(registroArchivoJugador)*(-1),1);
                fwrite(&aux, sizeof(registroArchivoJugador), 1, buf);
            }
        }
        if(flag == 0){
            printf("\nEL DNI DEL JUGADOR INGRESADO NO SE ENCUENTRA EN EL ARCHIVO.\n");
        }
        fclose(buf);
    }
}

registroArchivoJugador altaJugador(registroArchivoJugador aux){
    aux.activo = 1;
    return aux;
}

void altaJugadorArchivo(char archiJugador[], int dni){
    FILE *buf = fopen (archiJugador, "r+b");
    registroArchivoJugador aux;
    int flag=0;

    if(!buf){
        printf("\nEL ARCHIVO NO SE PUEDE ABRIR.\n");
    }
    else{
        while(fread(&aux, sizeof(registroArchivoJugador), 1, buf) > 0 && flag==0){
            if(aux.dni == dni){
                aux = altaJugador(aux);
                flag = 1;
                fseek(buf, sizeof(registroArchivoJugador)*(-1),1);
                fwrite(&aux, sizeof(registroArchivoJugador), 1, buf);
            }
        }
        if(flag == 0){
            printf("\nEL DNI DEL JUGADOR INGRESADO NO SE ENCUENTRA EN EL ARCHIVO.\n");
        }
        fclose(buf);
    }
}

/************************ FUNCIONES ARBOL JUGADOR ************************/

void mostrarUnStJugador(stJugador aux){
    printf("\n---------- LEGAJO: %i ----------", aux.legajo);
    printf("\n|          NOMBRE: %s", aux.nombre);
    printf("\n|        APELLIDO: %s", aux.apellido);
    printf("\n|             DNI: %i", aux.dni);
    printf("\n|        POSICION: %s", aux.posicion);
    printf("\n|          SUELDO: %.2f", aux.sueldo);
    printf("\n|      VALOR PASE: %.2f", aux.valorpase);
    printf("\n|           GOLES: %i", aux.goles);
    if(aux.activo == 1){
        printf("\n|          ESTADO: ACTIVO");
    }
    else{
        printf("\n|          ESTADO: INACTIVO");
    }
    printf("\n-------------------------------");
}

arbolJugador *inicArbol(){
    return NULL;
}

arbolJugador *crearNodoArbol (stJugador aux){
    arbolJugador *nuevo = (arbolJugador*)malloc(sizeof(arbolJugador));

    nuevo->dato = aux;
    nuevo->der = NULL;
    nuevo->izq = NULL;
    return nuevo;
}

stJugador cargarUnStJugador (registroArchivoJugador aux){
    stJugador jug;

    jug.legajo = aux.legajo;
    jug.activo = aux.activo;
    strcpy(jug.apellido, aux.apellido);
    strcpy(jug.nombre, aux.nombre);
    strcpy(jug.posicion, aux.posicion);
    jug.dni = aux.dni;
    jug.goles = aux.goles;
    jug.sueldo = aux.sueldo;
    jug.valorpase = aux.valorpase;

    return jug;
}

arbolJugador *insertarEnArbol(arbolJugador *arbol, arbolJugador *nuevo){
    if(!arbol){
        arbol = nuevo;
    }
    else{
        if(arbol->dato.dni < nuevo->dato.dni){
            arbol->der = insertarEnArbol(arbol->der, nuevo);
        }
        else{
            arbol->izq = insertarEnArbol(arbol->izq, nuevo);
        }
    }
    return arbol;
}

arbolJugador *archivoToArbol (char archiJugador[]){
    arbolJugador *arbol = inicArbol();
    arbolJugador *nuevo = inicArbol();
    registroArchivoJugador aux;
    stJugador jug;

    FILE *buf = fopen(archiJugador, "rb");

    if(!buf){
        printf("\nEL ARCHIVO NO SE PUDO ABRIR.\n");
    }
    else{
        while(fread(&aux, sizeof(registroArchivoJugador), 1, buf) > 0){
            jug = cargarUnStJugador(aux);
            nuevo = crearNodoArbol(jug);
            arbol = insertarEnArbol(arbol, nuevo);
        }
        fclose(buf);
    }
    return arbol;
}

void mostrarArbolDNI(arbolJugador *arbol){
    if(arbol){
        mostrarArbolDNI(arbol->izq);
        mostrarUnStJugador(arbol->dato);
        mostrarArbolDNI(arbol->der);
    }
}

arbolJugador *buscarPorDNI (arbolJugador *arbol, int dni){
    arbolJugador *buscar = inicArbol();

    if(arbol){
        if(arbol->dato.dni == dni){
            buscar = arbol;
        }
        else{
            if(arbol->dato.dni < dni){
                buscar = buscarPorDNI(arbol->der, dni);
            }
            else{
                buscar = buscarPorDNI(arbol->izq, dni);
            }
        }
    }
    return buscar;
}

arbolJugador *buscarGoleador (arbolJugador *arbol, arbolJugador *goleador){ /// SE LE PASA POR PARAMETRO UN GOLEADOR EN NULL
    if(arbol){
        if(!goleador){
            goleador = arbol;
        }
        else if(arbol->dato.goles > goleador->dato.goles){
            goleador = arbol;
        }
        goleador = buscarGoleador(arbol->der, goleador);
        goleador = buscarGoleador(arbol->izq, goleador);
    }
    return goleador;
}

int sumarGolesDivision (arbolJugador *arbol){
    int goles=0;
    if(arbol){
        goles = arbol->dato.goles + sumarGolesDivision(arbol->der) + sumarGolesDivision(arbol->izq);
    }
    return goles;
}






/*
arbolJugador *buscarPorDNIyDarDeBaja (arbolJugador *arbol, int dni){
    if(arbol){
        if(arbol->dato.dni == dni){
            arbol->dato.activo = 0;
        }
        else{
            if(arbol->dato.dni < dni){
                arbol = buscarPorDNI(arbol->der, dni);
            }
            else{
                arbol = buscarPorDNI(arbol->izq, dni);
            }
        }
    }
    return arbol;
}

arbolJugador *buscarGoleadorActivo (arbolJugador *arbol, arbolJugador *goleador){ /// SE LE PASA POR PARAMETRO UN GOLEADOR EN NULL
    if(arbol){
        if(!goleador && arbol->dato.activo == 1){
            goleador = arbol;
        }
        else if(arbol->dato.goles > goleador->dato.goles && arbol->dato.activo == 1){
            goleador = arbol;
        }
        goleador = buscarGoleadorActivo(arbol->der, goleador);
        goleador = buscarGoleadorActivo(arbol->izq, goleador);
    }
    return goleador;
}

arbolJugador *top3Goleadores (arbolJugador *arbol, arbolJugador *goleador, arbolJugador *goleadores, int cont){
    if(arbol){
        printf("\nENTRA AL IF BUSCARGOLEADORACTIVO ------------\n");
        goleador = buscarGoleadorActivo(arbol, goleador);
        printf("\nSALE DEL IF BUSCARGOLEADORACTIVO ------------\n");
        goleadores = insertarEnArbol(goleadores, goleador); /// INSERTO EL GOLEADOR EN EL ARBOL DE GOLEADORES
        arbol = buscarPorDNIyDarDeBaja(arbol, goleador->dato.dni); /// BUSCO EL DNI DEL GOLEADOR EN EL ARBOL Y LO DOY DE BAJA
    }

    if(cont<1){ /// REPETIMOS LA FUNCION 3 VECES
        printf("\nENTRA AL IF ------------\n");
        printf("\nCONTADOR: %i ------------\n", cont);
        cont++;
        goleador = inicArbol(); /// INICIO EL ARBOL GOLEADOR PARA BUSCAR EL OTRO GOLEADOR MENOR
        goleadores = top3Goleadores(arbol, goleador, goleadores, cont);
    }
    return goleadores;
}
*/

