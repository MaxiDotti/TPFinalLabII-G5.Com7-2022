#ifndef CUERPOTECNICO_H_INCLUDED
#define CUERPOTECNICO_H_INCLUDED

typedef struct{
    int idCT;
    char nombre[20];
    char apellido[20];
    float sueldo;
    int dni;
    int telefono;
    char cargo[20];
    int activo;
    char nombreDivision[15]; /// primera , segunda , tercera
    int idDivision; /// 1, 2 ,3
}registroArchivoCT;

typedef struct{
    int idCT;
    char nombre[20];
    char apellido[20];
    float sueldo;
    int dni;
    int telefono;
    char cargo[20];
    int activo;
}stCT; ///CUERPO TECNICO

typedef struct nodoCT{
    stCT dato;
    struct nodoCT *ant;
    struct nodoCT *sig;
}nodoCT;

int validarNumero (char numeros[]);
int validarPalabra (char palabra[]);
int validacionIdCT (int idCT);
int validacionDniCT (int dni);
registroArchivoCT cargarCT ();
nodoCT* inicListaDoble ();
nodoCT* crearNodoCT(stCT dato);
nodoCT* agregarAlPpioDoble(nodoCT* lista, nodoCT* nuevoNodo);
void mostrarListaCT (nodoCT* lista);


#endif // CUERPOTECNICO_H_INCLUDED
