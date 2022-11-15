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
stEmpleado nuevoEmpleado(archiEmpleado aux);

////MOSTRAR:
void MostrarEmpleado(stEmpleado nuevo);
void MostarNodoE (nodoEmpleado * NodoE);
void MostrarListaE (nodoEmpleado * ListaE);
void MostararchEpleado(archiEmpleado nuevo);
void MostarArchiE();

////BAJAS:
int buscarPosLegajoArchivoE (int legajo);
void bajaReactivarPorLegajoE (int activar);

////MODIFICACIONES:
archiEmpleado modificarDatosE (archiEmpleado  E);

////FUNCIONES LISTA:
nodoEmpleado * inicListaS ();
nodoEmpleado * crearNodoS (stEmpleado nuevo);
nodoEmpleado * agregarPpioS (nodoEmpleado * listaE, nodoEmpleado * nuevoNodoE);
nodoEmpleado * agregarEnOrden (nodoEmpleado * listaE, nodoEmpleado * nuevoNodoE);
nodoEmpleado * buscarNodoE (nodoEmpleado * listaE, int dni);
nodoEmpleado * ArchiaListaE (nodoEmpleado * listaE);
nodoEmpleado * borrarNodoE(nodoEmpleado* listaE, int dni);

#endif // EMPLEADO_H_INCLUDED
