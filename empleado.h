#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED


<<<<<<< HEAD

=======
>>>>>>> 242058895cfd75939e261285babd392abd517cc8
typedef struct{
    int legajo;
    char nombre[20];
    char apellido[20];
    int dni;
    int tel;
    char puesto[20]; /// AYUDANTE - PROFE - MEDICO - MAESTRANZA
    float sueldo;
    int activo;
<<<<<<< HEAD
=======
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
>>>>>>> 242058895cfd75939e261285babd392abd517cc8
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








#endif // EMPLEADO_H_INCLUDED
