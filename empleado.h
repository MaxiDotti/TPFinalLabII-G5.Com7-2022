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
int validarPalabra (char palabra[]);
int validarNumero (char numeros[]);
int validacionDeAlta (int legajo);

////CARGA:
int CargarEmpleado (archiEmpleado nuevo);

////MOSTRAR:
void MostrarEmpleado(stEmpleado nuevo);
void MostarNodoE (nodoEmpleado * NodoE);
void MostrarListaE (nodoEmpleado * ListaE);

////FUNCIONES LISTA:
nodoEmpleado * inicListaS ();
nodoEmpleado * crearNodoS (stEmpleado nuevo);
nodoEmpleado * agregarPpioS (nodoEmpleado * listaE, nodoEmpleado * nuevoNodoE);
nodoEmpleado * agregarEnOrden (nodoEmpleado * listaE, nodoEmpleado * nuevoNodoE);
nodoEmpleado * buscarNodoE (nodoEmpleado * listaE, int legajo);
nodoEmpleado * ArchiaListaE (nodoEmpleado * listaE);

#endif // EMPLEADO_H_INCLUDED
