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

///Menu
void menuCuerpoTecnico (int validos, int dim);

///VALIDACIONES
int validarNumero (char numeros[]);
int validarPalabra (char palabra[]);
int validacionIdCT (int idCT);
int validacionDniCT (int dni);

///CARGAR CT
void cargarArchivoCT ();
void cargarCT ();

///FUNCIONES LISTAS DOBLES
nodoCT* inicListaDoble ();
nodoCT* crearNodoCT(stCT dato);
nodoCT* agregarAlPpioDoble(nodoCT* lista, nodoCT* nuevoNodo);
nodoCT* agregarEnOrdenDobleId(nodoCT* lista, nodoCT* nuevoNodo);

///MOSTRAR
void mostrarListaCT (nodoCT* lista);
void mostrarEstructuraCT (stCT dato);
void mostrarNombreCT (nodoCT* ct, char nombre[]);
void mostrarPorCargo(char cargo[]);
int mostrarPorId(int id);
void mostrarRegistroArchivoCT (registroArchivoCT dato);

///FUNCIONES ARCHIVO
nodoCT* ArchiToListaCT (nodoCT* lista);
stCT registroToCT (registroArchivoCT A);
nodoCT* buscarPorIdCT (nodoCT* lista, int id);
nodoCT* buscarPorDniCT (nodoCT* lista, int dni);
int generarID (registroArchivoCT ct);

///MODIFICAR
registroArchivoCT modificarDatosCT (registroArchivoCT A);
void modificarCTEleccion();
int buscarPosIdArchivoCT (int id);

///BAJA
void bajaReactivarPorIdCT (int activar);

#endif // CUERPOTECNICO_H_INCLUDED
