#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include "funciones.h"

int agregarPelicula(EMovie *pelicula)
{
    FILE *bin;
    pelicula->flagestado=0;


        printf("Titulo de la pelicula:\n");
        fflush(stdin);
        gets(pelicula->titulo);
        ValCadenas(pelicula->titulo,41);
        printf("Genero de pelicula:\n");
        fflush(stdin);
        gets(pelicula->genero);
        ValCadenas(pelicula->genero,41);
        printf("Duracion de pelicula (en minutos):\n");
        scanf("%d",&pelicula->duracion);
        pelicula->duracion=ValidacionInt(pelicula->duracion, 1, 300);
        printf("Descripcion de pelicula:\n");
        fflush(stdin);
        gets(pelicula->descripcion);
        ValCadenas(pelicula->descripcion, 301);
        printf("Puntaje de pelicula (1-100) :\n");
        scanf("%d",&pelicula->puntaje);
        pelicula->puntaje=ValidacionInt(pelicula->puntaje,1,100);
        printf("Ingrese link de imagen:\n");
        fflush(stdin);
        gets(pelicula->linkImagen);
        ValCadenas(pelicula->linkImagen, 201);
        pelicula->flagestado=1;

        if((bin=fopen("peliculas.bin","ab+"))==NULL)
        {
            printf("ERROR.No se pudo realizar la carga de datos en el archivo binario.\n");
        }
        else
        {
             fwrite(pelicula,sizeof(EMovie),1,bin);
        }

        printf("Se han guardado los datos de la pelicula dentro del archivo binario!\n");
        fclose(bin);
        return 0;
}

int borrarPelicula(EMovie *pelicula)
{
    FILE *Punt;
    char auxTitulo[40];
    int encontro=0;

    printf("Ingrese nombre de la pelicula que desea borrar:");
    fflush(stdin);
    strlwr(gets(auxTitulo));

    if((Punt=fopen("peliculas.bin","r+"))==NULL)
    {
      printf("ERROR.El archivo no pudo abrirse!");
      return 0;

    }
    else
    {
        while((fread(pelicula,sizeof(EMovie),1,Punt))!=0)
        {
           if(pelicula->flagestado==1)
            {
                strlwr(pelicula->titulo);
                if(strcmp(pelicula->titulo,auxTitulo)==0)
               {
                   fseek(Punt,-sizeof(EMovie),SEEK_CUR);
                   pelicula->flagestado=0;
                   fwrite(pelicula,sizeof(EMovie),1,Punt);


                   encontro=1;
                   printf("La pelicula ha sido borrada!");
                   return 1;
                   break;
               }
            }
        }

        if(encontro==0)
        {
            printf("ERROR. La pelicula no fue encontrada!");
            return 0;
        }

    }


}

int generarPagina(EMovie *pelicula)
{
    FILE *Punt, *puntHtml;

    if((Punt=fopen("peliculas.bin","rb"))!=NULL)
    {
        if((puntHtml=fopen("peliculas.html","wb"))!=NULL)
        {
            fprintf(puntHtml,"<!DOCTYPE html>\n"
            "<!-- Template by Quackit.com -->\n"
            "<html lang='en'>\n"
            "<head>\n"
            "    <meta charset='utf-8'>\n"
            "    <meta http-equiv='X-UA-Compatible' content='IE=edge'>\n"
            "    <meta name='viewport' content='width=device-width, initial-scale=1'>\n"
            "    <!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->\n"
            "    <title>Lista peliculas</title>\n"
            "    <!-- Bootstrap Core CSS -->\n"
            "    <link href='css/bootstrap.min.css' rel='stylesheet'>\n"
            "    <!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles -->\n"
            "    <link href='css/custom.css' rel='stylesheet'>\n"
            "    <!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->\n"
            "    <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->\n"
            "    <!--[if lt IE 9]>\n"
            "        <script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script>\n"
            "        <script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>\n"
            "    <![endif]-->\n"
            "</head>\n"
            "<body>\n"
            "    <div class='container'>\n"
            "        <div class='row'>\n");
            while((fread(pelicula,sizeof(EMovie),1,Punt))!=0)
            {

               if(pelicula->flagestado==1)
               {
                    fprintf(puntHtml,"<!-- Repetir esto para cada pelicula -->\n"
                    "<article class='col-md-4 article-intro'>\n"
                    "<a href='#'>\n"
                    "<img class='img-responsive img-rounded' src='%s' alt=''>\n"
                    "</a>\n"
                    "<h3>\n"
                    "<a href='#'>%s</a>\n"
                    "</h3>\n"
                    "<ul>\n"
                    "<li>Genero:%s</li>\n"
                    "<li>Puntaje:%d</li>\n"
                    "<li>Duracion:%d</li>\n"
                    "</ul>\n"
                    "<p>%s</p>\n"
                    " </article>\n"
                    "<!-- Repetir esto para cada pelicula -->\n",pelicula->linkImagen,pelicula->titulo,pelicula->genero,pelicula->puntaje,pelicula->duracion,pelicula->descripcion);
               }

            }

            fprintf(puntHtml,"        </div>\n"
            "<!-- /.row -->\n"
            "</div>\n"
            "<!-- /.container -->\n"
            "<!-- jQuery -->\n"
            "<script src='js/jquery-1.11.3.min.js'></script>\n"
            "<!-- Bootstrap Core JavaScript -->\n"
            "<script src='js/bootstrap.min.js'></script>\n"
            "<!-- IE10 viewport bug workaround -->\n"
            "<script src='js/ie10-viewport-bug-workaround.js'></script>\n"
            "<!-- Placeholder Images -->\n"
            "<script src='js/holder.min.js'></script>\n"
            "</body>\n"
            "</html>\n");
        }
        else
        {
            printf("La pagina html no fue creada!\n");
            return 0;
        }

    }
    else
    {
        printf("No se pudo cargar los datos de las estructura!\n");
        return 0;
    }

    printf("Se ha creado correctamente una pagina html con los datos de la pelicula!\n");
    fclose(Punt);
    fclose(puntHtml);

    return 0;
}
    int ValidacionInt(int dato, int min, int max)
    {
        while(dato<min || dato>max)
        {
            printf("Error. Reingrese el dato entre %d y %d: \n", min, max);
            scanf("%d",&dato);
        }
        return dato;
    }

    void ValCadenas(char x[], int tan)
{
    while(strlen(x)>tan-1)
    {
     printf("ERROR. Reingrese una cadena que no exceda los %d caracteres: \n",tan-1);
     fflush(stdin);
     gets(x);
    }
}



