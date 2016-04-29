#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
typedef struct {

    char nombre[50];
    int edad;
    int estado;
    long int dni;

}EPersona;
/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
 int obtenerEspacioLibre(EPersona x[]);
/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona x[], long int dni);
void Altas(EPersona x[]);//FUNCION DE AGREGAR A LOS EMPLEADOS
void Eliminar(EPersona x[]);//FUNCION DE ELIMINAR A UN EMPLEADO Y SUS DATOS SEGUN SU DNI
void Mostrar(EPersona x[]);//FUNCION DE MOSTRAR ALFABETICAMENTE A LOS EMPLEADOS
int val_int(int, int, int); //FUNCION DE VALIDACION PARA LA EDAD Y DNI
void Grafico(EPersona x[]);//FUNCION DEL GRAFICO DE LAS EDADES

#endif // FUNCIONES_H_INCLUDED
