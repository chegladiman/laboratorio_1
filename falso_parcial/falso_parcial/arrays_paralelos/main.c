#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CANT 4

int main()
{
    int i,j,nota[CANT],auxNota;
    char nombre[CANT][31],auxNombre[31];

    for (i=0;i<CANT;i++)
    {
        printf("Nota: ");
        scanf("%d",&nota[i]);
        printf("Nombre: ");
        fflush(stdin);
        scanf("%[^\n]",nombre[i]);
    }

    for (i=0;i<CANT-1;i++)
    {
        for (j=i+1;j<CANT;j++)
        {
            if (nota[i]<nota[j])
            {
                strcpy(auxNombre,nombre[i]);
                strcpy(nombre[i],nombre[j]);
                strcpy(nombre[j],auxNombre);
                auxNota=nota[i];
                nota[i]=nota[j];
                nota[j]=auxNota;
            }
            if (nota[i]==nota[j])
            {
                if (strcmp(nombre[i],nombre[j])>0)
                {
                    strcpy(auxNombre,nombre[i]);
                    strcpy(nombre[i],nombre[j]);
                    strcpy(nombre[j],auxNombre);
                    auxNota=nota[i];
                    nota[i]=nota[j];
                    nota[j]=auxNota;
                }

            }
        }
    }

    for (i=0;i<CANT;i++)
    {
            printf("Nota: %d",nota[i]);
            printf("\nNombre: %s\n",nombre[i]);
    }

    return 0;
}
