#include "jugador.h"
#include "division.h"
#include <string.h>

registroArchivoJugador cargarUnJugador(int dni, int legajo){
    registroArchivoJugador aux;
    char validarP[30];

    aux.dni = dni;
    aux.legajo = legajo+1;

    do{
        printf("\nNOMBRE DIVISION: ");
        fflush(stdin);
        gets(validarP);
    }while((validarPalabra(validarP) != 0));
    strcpy(aux.nombreDivision, validarP);

    do{
        printf("ID DIVISION: ");
        fflush(stdin);
        gets(validarP);
    }while((validarNumero(validarP) != 0));
    aux.idDivision = atoi(validarP);

    do{
        printf("NOMBRE: ");
        fflush(stdin);
        gets(validarP);
    }while((validarPalabra(validarP) != 0));
    strcpy(aux.nombre, validarP);

    do{
        printf("APELLIDO: ");
        fflush(stdin);
        gets(validarP);
    }while((validarPalabra(validarP) != 0));
    strcpy(aux.apellido, validarP);

    do{
        printf("EDAD: ");
        fflush(stdin);
        gets(validarP);
    }while((validarNumero(validarP) != 0));
    aux.edad = atoi(validarP);

    do{
        printf("POSICION: ");
        fflush(stdin);
        gets(validarP);
    }while((validarPalabra(validarP) != 0));
    strcpy(aux.posicion, validarP);

    printf("SUELDO: ");
    fflush(stdin);
    scanf("%f", &aux.sueldo);

    printf("VALOR PASE: ");
    fflush(stdin);
    scanf("%f", &aux.valorpase);

    do{
        printf("GOLES: ");
        fflush(stdin);
        gets(validarP);
    }while((validarNumero(validarP) != 0));
    aux.goles = atoi(validarP);

    aux.activo = 1;

    return aux;
}

int verificarDNIenArchivo (FILE *buf, int dni){
    registroArchivoJugador aux;
    int flag=0;

    fseek(buf, 0, 0);
    while ((fread (&aux, sizeof(registroArchivoJugador), 1, buf) > 0) && flag != -1) /// verifica si el DNI ingresado es de un jugador ya existente.
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

void cargarJugadorRegistroArchivo(){
    FILE *buf = fopen ("archivoJugadores", "a+b");
    registroArchivoJugador nuevo;
    char control = 's', validar[30];
    int flag=0, dni=0;

    if(!buf){
        printf("\nEL ARCHIVO NO SE PUEDE ABRIR.\n");
    }
    else{
        while(control == 's' || control == 'S'){
            printf("\n-------> COMPLETE LOS DATOS SEGUN CORRESPONDA <-------\n\n");
            do{
                printf("DNI: ");
                fflush(stdin);
                gets(validar);
            }while((validarNumero(validar) != 0));
            dni = atoi(validar);

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
    printf("\n|            EDAD: %i", aux.edad);
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

void mostrarArchivoJugador(){
    FILE *buf = fopen ("archivoJugadores", "rb");
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

void bajaJugadorArchivo(int dni){
    FILE *buf = fopen ("archivoJugadores", "r+b");
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

void altaJugadorArchivo(int dni){
    FILE *buf = fopen ("archivoJugadores", "r+b");
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

registroArchivoJugador modificarUnJugadorAuxiliar (FILE *buf, registroArchivoJugador aux, int legajo){
    char control = 's';
    char validar[30];
    int flag=-1;

    aux.legajo = legajo;

    printf("\n\nModificar nombre? s/n: ");
    fflush(stdin);
    scanf("%c", &control);
    if(control=='s')
    {
        do{
        printf("NOMBRE: ");
        fflush(stdin);
        gets(validar);
        }while((validarPalabra(validar) != 0));
        strcpy(aux.nombre, validar);
    }

    printf("Modificar apellido? s/n: ");
    fflush(stdin);
    scanf("%c", &control);
    if(control=='s'){
        do{
        printf("APELLIDO: ");
        fflush(stdin);
        gets(validar);
        }while((validarPalabra(validar) != 0));
        strcpy(aux.apellido, validar);
    }

    printf("Modificar edad? s/n: ");
    fflush(stdin);
    scanf("%c", &control);
    if(control=='s'){
        do{
            printf("EDAD: ");
            fflush(stdin);
            gets(validar);
        }while((validarNumero(validar) != 0));
        aux.edad = atoi(validar);
    }

    printf("Modificar DNI? s/n: ");
    fflush(stdin);
    scanf("%c", &control);
    while(control=='s' && flag == -1){
        do{
            printf("DNI: ");
            fflush(stdin);
            gets(validar);
        }while((validarNumero(validar) != 0));

        flag = verificarDNIenArchivo(buf, atoi(validar));
        if(flag == -1){
            printf("\nEL DNI YA EXISTE EN EL ARCHIVO.\n");
        }
        else{
            aux.dni = atoi(validar);
            flag = 0;
        }
    }

    printf("Modificar goles? s/n: ");
    fflush(stdin);
    scanf("%c", &control);
    if(control=='s'){
        do{
        printf("GOLES: ");
        fflush(stdin);
        gets(validar);
        }while((validarNumero(validar) != 0));
        aux.goles = atoi(validar);
    }

    printf("Modificar division? s/n: ");
    fflush(stdin);
    scanf("%c", &control);
    if(control=='s'){
        do{
        printf("ID DIVISION: ");
        fflush(stdin);
        gets(validar);
        }while((validarNumero(validar) != 0));
        aux.idDivision = atoi(validar);

        do{
        printf("\nNOMBRE DIVISION: ");
        fflush(stdin);
        gets(validar);
        }while((validarPalabra(validar) != 0));
        strcpy(aux.nombreDivision, validar);
    }

    printf("Modificar posicion? s/n: ");
    fflush(stdin);
    scanf("%c", &control);
    if(control=='s'){
        do{
        printf("POSICION: ");
        fflush(stdin);
        gets(validar);
        }while((validarPalabra(validar) != 0));
        strcpy(aux.posicion, validar);
    }

    printf("Modificar valor del pase? s/n: ");
    fflush(stdin);
    scanf("%c", &control);
    if(control=='s'){
        printf("Ingrese valor del pase: ");
        scanf("%f", &aux.valorpase);
    }

    printf("Modificar sueldo? s/n: ");
    fflush(stdin);
    scanf("%c", &control);
    if(control=='s'){
        printf("Ingrese sueldo: ");
        scanf("%f", &aux.sueldo);
    }

    return aux;
}

int buscarPosicionDni (FILE* buf, int dni){
    registroArchivoJugador aux;
    int i = 0;
    int flag = 0;

    while((fread(&aux, sizeof(registroArchivoJugador), 1, buf)) > 0 && flag == 0){
        if (dni == aux.dni){
            flag = 1;
        }
        i++;
    }
    return i-1;
}

int buscarYModificarUnJugador (int dni){
    FILE *buf = fopen("archivoJugadores", "r+b");
    registroArchivoJugador aux;;
    int pos = 0;
    int flag = 0;

    if(!buf){
        printf("El archivo no se puede abrir.\n");
    }
    else{
        flag = verificarDNIenArchivo(buf, dni); /// SI ENCUENTRA EL DNI DEVUELVE -1

        if(flag == -1){
            pos = buscarPosicionDni(buf, dni);
            fseek(buf, sizeof(registroArchivoJugador)*(pos), 0);
            fread(&aux, sizeof(registroArchivoJugador), 1, buf);

            aux = modificarUnJugadorAuxiliar(buf, aux, aux.legajo);

            fseek(buf, sizeof(registroArchivoJugador)*(-1), 1);
            fwrite(&aux, sizeof(registroArchivoJugador), 1, buf);
            printf("\n\nJUGADOR MODIFICADO EXISTOSAMENTE\n\n");
            flag = 1;
        }
        else{
            printf("\nEL JUGADOR NO SE ENCUENTRA EN EL ARCHIVO\n");
        }
        fclose(buf);
    }
    return flag;
}

/************************ FUNCIONES ARBOL JUGADOR ************************/

void mostrarUnStJugador(stJugador aux){
    printf("\n---------- LEGAJO: %i ----------", aux.legajo);
    printf("\n|          NOMBRE: %s", aux.nombre);
    printf("\n|        APELLIDO: %s", aux.apellido);
    printf("\n|             DNI: %i", aux.dni);
    printf("\n|            EDAD: %i", aux.edad);
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
    jug.edad = aux.edad;
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

arbolJugador *archivoToArbolJugadores (){
    arbolJugador *arbol = inicArbol();
    arbolJugador *nuevo = inicArbol();
    registroArchivoJugador aux;
    stJugador jug;

    FILE *buf = fopen("archivoJugadores", "rb");

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

int mostrarNodoArbolPorLegajo (arbolJugador *arbol, int legajo){
    arbolJugador *buscar = inicArbol();
    int flag = 0;

    if(arbol && flag != -1){
        if(arbol->dato.legajo == legajo){
            buscar = arbol;
            mostrarUnStJugador(buscar->dato);
            flag = -1;
        }
        else{
            mostrarNodoArbolPorLegajo(arbol->der, legajo);
            mostrarNodoArbolPorLegajo(arbol->izq, legajo);
        }
    }
    return flag;
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

void menuJugador(int validos)
{

    int controles, eleccion, dni, flag = 0;
    char validar[30];
    celdaDivision celd[20];

    system("cls");
    printf("------> MENU DE JUGADORES\n\n");
    printf("[1] ALTA\n");
    printf("[2] BAJA - REACTIVACION\n");
    printf("[3] MODIFICAR\n");
    printf("[4] LISTAR JUGADORES\n");
    printf("[0] SALIR\n\n");

    printf("OPCION: ");
    fflush(stdin);
    scanf("%d",&controles);
    system("cls");

    switch(controles){
        case 1:{
            cargarJugadorRegistroArchivo();
            break;
        }case 2:
        {
            printf("------> MENU DE BAJA / REACTIVACION\n\n");
            printf("[0] BAJA\n");
            printf("[1] ALTA\n");
            printf("\nOPCION: ");
            scanf("%d",&eleccion);

            if (eleccion == 0){
                do{
                printf("INGRESE EL DNI PARA DAR DE BAJA: ");
                fflush(stdin);
                gets(validar);
            }while((validarNumero(validar) != 0));
            dni = atoi(validar);
            bajaJugadorArchivo(dni);
            }else if (eleccion == 1){
                do{
                printf("INGRESE EL DNI PARA DAR DE ALTA: ");
                fflush(stdin);
                gets(validar);
            }while((validarNumero(validar) != 0));
            dni = atoi(validar);
                altaJugadorArchivo(dni);
            }
            else{
                printf("INGRESO UNA OPCION INCORRECTA.\n");
            }
            break;
            }
        case 3:{
            do{
                printf("------> MENU DE MODIFICACIONES\n\n");
                printf("INGRESE EL DNI PARA MODIFICAR LOS DATOS: ");
                fflush(stdin);
                gets(validar);
            }while((validarNumero(validar) != 0));
            dni = atoi(validar);
            flag = buscarYModificarUnJugador(dni);

            if(flag == 1){
                arbolJugador *aux = inicArbol();
                aux = archivoToArbolJugadores();
                arbolJugador *buscar = inicArbol();
                buscar = buscarPorDNI(aux, dni);
                mostrarUnStJugador(buscar->dato);
            }
            break;
        }
            case 4:{
                arbolJugador *aux = inicArbol();
                arbolJugador *jug = inicArbol();
                aux = archivoToArbolJugadores();
                char cargo[20];
                int legajo, pos=0;
                printf("------> MENU DE LISTAR\n\n");
                printf("[1] MOSTRAR TODOS LOS JUGADORES\n");
                printf("[2] MOSTRAR POR DNI (menor a mayor)\n");
                printf("[3] MOSTRAR POR LEGAJO\n");
                printf("[4] MOSTRAR POR DIVISION\n");
                printf("[5] MOSTRAR GOLEADORES\n\n");

                printf("OPCION: ");
                scanf("%d",&eleccion);
                system("cls");

                if (eleccion==1){
                    mostrarArchivoJugador();
                }
                else if (eleccion==2){
                    mostrarArbolDNI(aux);
                }
                else if (eleccion==3){
                    printf("INGRESE LEGAJO A MOSTRAR: ");
                    scanf("%i", &legajo);
                    flag = mostrarNodoArbolPorLegajo(aux, legajo);
                }
                else if (eleccion==4){
                    validos = archivoToArrJug(celd, 5);

                    printf("------> MOSTRAR POR DIVISION\n\n");
                    printf("[1] PRIMERA\n");
                    printf("[2] SEGUNDA\n");
                    printf("[3] TERCERA\n\n");

                    printf("OPCION: ");
                    scanf("%d",&eleccion);
                    system("cls");
                    if(eleccion == 1){
                        pos = buscarPosDivision(celd, 1, validos);
                        if(pos == -1){
                            printf("\nLA DIVISION NO EXISTE.\n");
                        }
                        else{
                            mostrarArbolDNI(celd[pos].jug);
                        }
                    }
                    else if(eleccion == 2){
                        pos = buscarPosDivision(celd, 2, validos);
                        if(pos == -1){
                            printf("\nLA DIVISION NO EXISTE.\n");
                        }
                        else{
                            mostrarArbolDNI(celd[pos].jug);
                        }
                    }
                    else if(eleccion == 3){
                        pos = buscarPosDivision(celd, 3, validos);
                        if(pos == -1){
                            printf("\nLA DIVISION NO EXISTE.\n");
                        }
                        else{
                            mostrarArbolDNI(celd[pos].jug);
                        }
                    }
                }
                else if (eleccion==5){
                    validos = archivoToArrJug(celd, 5);
                    printf("MOSTRAR GOLEADORES\n\n");
                    printf("[1] GOLEADOR PRIMERA DIVISION\n");
                    printf("[2] GOLEADOR SEGUNDA DIVISION\n");
                    printf("[3] GOLEADOR TERCERA DIVISION\n");
                    printf("[4] MAXIMO GOLEADOR\n\n");

                    printf("OPCION: ");
                    scanf("%d",&eleccion);
                    system("cls");
                    if(eleccion == 1){
                        pos = buscarPosDivision(celd, 1, validos);
                        if (pos != -1){
                            jug = buscarGoleador(celd[pos].jug, jug);
                            mostrarUnStJugador(jug->dato);
                        }
                        else{
                            printf("NO ENCONTRO EL GOLEADOR\n");
                        }
                    }
                    else if(eleccion == 2){
                        pos = buscarPosDivision(celd, 2, validos);

                        jug = buscarGoleador(celd[pos].jug, jug);
                        mostrarUnStJugador(jug->dato);
                    }
                    else if(eleccion == 3){
                        pos = buscarPosDivision(celd, 3, validos);
                        jug = buscarGoleador(celd[pos].jug, jug);
                        mostrarUnStJugador(jug->dato);
                    }
                    else if(eleccion == 4){
                        jug = buscarGoleador(aux, jug);
                        mostrarUnStJugador(jug->dato);
                    }
                }
                else{
                    printf("INGRESO UNA OPCION INCORRECTA.\n");
                }
                break;
            }
        }
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

