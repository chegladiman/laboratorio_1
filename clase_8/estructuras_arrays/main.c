#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CANT 5

struct alumno
{
    int legajo;
    char nombre[31];
};

int main()
{
    struct alumno alumnos[CANT];
    int i;

    for (i=0;i<CANT;i++)
    {
        printf ("Ingrese Legajo: ");
        scanf ("%d",&alumnos[i].legajo);
        printf ("Ingrese Nombre: ");
        fflush(stdin);
        scanf ("%[^\n]",alumnos[i].nombre);
        system ("cls");
    }
    for (i=0;i<CANT;i++)
    {
        printf ("Legajo: %d\nNombre: %s\n",alumnos[i].legajo,alumnos[i].nombre);
    }
    return 0;
}
