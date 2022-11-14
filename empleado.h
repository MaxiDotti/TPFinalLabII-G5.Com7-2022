#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED



typedef struct{
    int legajo;
    char nombre[20];
    char apellido[20];
    int dni;
    int tel;
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
    int tel;
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
int validarPalabra2(char palabra[]) ;
int validarNumero2(char numeros[]) ;
int validacionDeAlta2 (int dni);

////CARGA:
int CargarEmpleado (archiEmpleado nuevo);
stEmpleado nuevoEmpleado(archiEmpleado aux);

////MOSTRAR:
void MostrarEmpleado(stEmpleado nuevo);
void MostarNodoE (nodoEmpleado * NodoE);
void MostrarListaE (nodoEmpleado * ListaE);
void MostararchEpleado(archiEmpleado nuevo);
void MostarArchiE();

////BAJAS:
archiEmpleado bajarEmpleado (archiEmpleado aux);
void bajarEmpleadoArchivo(int dni);

////MODIFICACIONES:
nodoEmpleado * modificarEmpleado(nodoEmpleado *listaE,int dni,char cambio[]);
stEmpleado editarEmpleado(stEmpleado editado , char cambio[]);

////FUNCIONES LISTA:
nodoEmpleado * inicListaS ();
nodoEmpleado * crearNodoS (stEmpleado nuevo);
nodoEmpleado * agregarPpioS (nodoEmpleado * listaE, nodoEmpleado * nuevoNodoE);
nodoEmpleado * agregarEnOrden (nodoEmpleado * listaE, nodoEmpleado * nuevoNodoE);
nodoEmpleado * buscarNodoE (nodoEmpleado * listaE, int dni);
nodoEmpleado * ArchiaListaE (nodoEmpleado * listaE);
nodoEmpleado * borrarNodoE(nodoEmpleado* listaE, int dni);

#endif // EMPLEADO_H_INCLUDED
