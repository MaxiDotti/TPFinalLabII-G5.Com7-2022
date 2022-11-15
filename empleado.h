#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED



typedef struct{
    int legajo;
    char nombre[20];
    char apellido[20];
    int dni;
    char tel [15];
    char puesto[20]; /// AYUDANTE - PROFE - MEDICO - MAESTRANZA
    float sueldo;
    int activo;
    char nombreDivision[15]; /// primera , segunda , tercera
    int idDivision; /// 1, 2 ,3
}archiEmpleado;

typedef struct{
    int legajo;
    char nombre[20];
    char apellido[20];
    int dni;
    char tel[15];
    char puesto[20]; /// AYUDANTE - PROFE - MEDICO - MAESTRANZA
    float sueldo;
    int activo;

}stEmpleado;


typedef struct nodoEmpleado{
    stEmpleado dato;
    struct nodoEmpleado *sig;
}nodoEmpleado;


/////////////////////////////////////////////////////PROTOTIPADO/////////////////////////////////////////////////////////////////

////VALIDACIONES:

int validacionDeAlta2 (int dni);
int generarLegajo (archiEmpleado nuevo);

////CARGA:
int CargarEmpleado ();
void CargarArchivoE ();
stEmpleado nuevoEmpleado(archiEmpleado aux);

////MOSTRAR:
void MostrarEmpleado(stEmpleado nuevo);
void MostrarListaE (nodoEmpleado * ListaE);
void MostrararchEmpleado(archiEmpleado nuevo);
void MostrarArchiE();
void mostrarNombreE(nodoEmpleado* emp, char nombre[]);
void mostrarPorPuesto (char puesto[]);
int mostrarPorLegajo (int legajo);

////BAJAS:
int buscarPosLegajoArchivoE (int legajo);
void bajaReactivarPorLegajoE (int activar);

////MODIFICACIONES:
void modificarE ();
archiEmpleado modificarDatosE (archiEmpleado  E);

////FUNCIONES LISTA:
nodoEmpleado * inicListaS ();
nodoEmpleado * crearNodoS (stEmpleado nuevo);
nodoEmpleado * agregarPpioS (nodoEmpleado * listaE, nodoEmpleado * nuevoNodoE);
nodoEmpleado * agregarEnOrden (nodoEmpleado * listaE, nodoEmpleado * nuevoNodoE);
nodoEmpleado * ArchiaListaE (nodoEmpleado * listaE);

////MENU
void menuEmpleados (int validos, int dim);

#endif // EMPLEADO_H_INCLUDED
