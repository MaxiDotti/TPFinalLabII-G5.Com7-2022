#ifndef CUERPOTECNICO_H_INCLUDED
#define CUERPOTECNICO_H_INCLUDED

typedef struct{
    int idCT;
    char nombre[20];
    char apellido[20];
    float sueldo;
    int dni;
    int tel;
    char cargo[20];
    int activo;
}stCT;///CUERPO TECNICO

typedef struct nodoCT{
    stCT dato;
    struct nodoCT *ant;
    struct nodoCT *sig;
}nodoCT;

#endif // CUERPOTECNICO_H_INCLUDED
