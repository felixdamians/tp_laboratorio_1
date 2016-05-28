#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[40];
    char genero[40];
    int duracion;
    char descripcion[300];
    int puntaje;
    char linkImagen[200];
    int flagestado;
}EMovie;

/**
 *  Agrega una pelicula al archivo binario
 *  @param pelicula puntero a la estructura EMovie a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(EMovie *pelicula);

/**
 *  Borra una pelicula del archivo binario
 *  @param pelicula puntero de la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(EMovie *pelicula);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 */
int generarPagina(EMovie *pelicula);
void ValCadenas(char x[], int tan);
int ValidacionInt(int dato, int min, int max);


#endif // FUNCIONES_H_INCLUDED
