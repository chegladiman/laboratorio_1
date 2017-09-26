#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define CANT 30
#define CANT2 60

int main()
{
    char nombre[CANT],apellido[CANT],apellidoNombre[CANT2];
    int i;

        printf ("Ingrese nombre: ");
        fflush(stdin);
        scanf ("%[^\n]",nombre);
        strlwr (nombre);
        printf ("Ingrese apellido: ");
        fflush(stdin);
        scanf("%[^\n]",apellido);
        strlwr (apellido);
        nombre[0]=toupper (nombre[0]);
        apellido[0]=toupper (apellido[0]);
        for (i=0;i<CANT;i++)
        {
            if (nombre[i-1]==' '&&nombre[i]!=' ')
            {
                nombre[i]=toupper(nombre[i]);
            }
            if (apellido[i-1]==' '&&apellido[i]!=' ')
            {
                apellido[i]=toupper(apellido[i]);
            }
        }

        strcpy (apellidoNombre,apellido);
        strcat (apellidoNombre," ");
        strcat (apellidoNombre,nombre);

        printf("Apellido y Nombre: %s",apellidoNombre);

    return 0;
}
