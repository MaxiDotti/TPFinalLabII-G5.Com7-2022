#ifndef CUERPOTECNICO_H_INCLUDED
#define CUERPOTECNICO_H_INCLUDED

typedef struct{
    int idCT;
    char nombre[20];
    char apellido[20];
    float sueldo;
    int dni;
    char telefono[15];
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
    char telefono[15];
    char cargo[20]; ///Nutricionista, Analista, Psicologo, DT
    int activo;
}stCT; ///CUERPO TECNICO

typedef struct nodoCT{
    stCT dato;
    struct nodoCT *ant;
    struct nodoCT *sig;
}nodoCT;

///Validaciones
int validarNumero (char numeros[]);
int validarPalabra (char palabra[]);
int validacionIdCT (int idCT);
int validacionDniCT (int dni);

///Cargar CT
void cargarArchivoCT ();
void cargarCT ();

///Funciones lista doble
nodoCT* inicListaDoble ();
nodoCT* crearNodoCT(stCT dato);
nodoCT* agregarAlPpioDoble(nodoCT* lista, nodoCT* nuevoNodo);
nodoCT* agregarEnOrdenDobleId(nodoCT* lista, nodoCT* nuevoNodo);
void mostrarListaCT (nodoCT* lista);
void mostrarEstructuraCT (stCT dato);

///Funciones archivo
void mostrarRegistroArchivoCT (registroArchivoCT dato);
nodoCT* ArchiToListaCT (nodoCT* lista);
stCT registroToCT (registroArchivoCT A);
nodoCT* buscarPorIdCT (nodoCT* lista, int id);
nodoCT* buscarPorDniCT (nodoCT* lista, int dni);
void mostrarPorCargo(char cargo[]);
int mostrarPorId(int id);
int generarID (registroArchivoCT ct);

///modificar
registroArchivoCT modificarDatosCT (registroArchivoCT A);
void modificarCTEleccion();
int buscarPosIdArchivoCT (int id);

///baja
void bajaReactivarPorIdCT (int activar);

#endif // CUERPOTECNICO_H_INCLUDED
