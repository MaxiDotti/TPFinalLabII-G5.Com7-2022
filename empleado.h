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
}stEmpleado;

typedef struct nodoEmpleado{
    stEmpleado dato;
    struct nodoEmpleado *sig;
}nodoEmpleado;

#endif // EMPLEADO_H_INCLUDED
