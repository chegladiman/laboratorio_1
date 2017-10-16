#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

#define CLIENTE 4
#define ALQUI 5
#define CLIENTEALQUI 20

int main()
{
    int opcionMenu,flagClient=0,flagAlqui=0;
    char seguir='s';

    Cliente client[CLIENTE];
    Alquiler alqui[ALQUI];
    ClienteAlquiler clienteAlquiler[CLIENTEALQUI];

    inicializar(client, alqui, clienteAlquiler);
    while (seguir=='s')
    {
    opcionMenu = menuInicial();

        switch (opcionMenu)
        {
        case 1:
            funcionAlta(client);
            flagClient=1;
            break;
        case 2:
            if (flagClient==1)
            {
                funcionModificar(client);
                break;
            }
            else
            {
                printf("Aun no se han ingresado clientes\n");
            }
            break;
        case 3:
            if (flagClient==1)
            {
                funcionBaja(client);
            }
            else
            {
                printf("Aun no se han ingresado clientes\n");
            }
            break;
        case 4:
            if (flagClient==1)
            {
                nuevoAlquiler(client, alqui);
            }
            else
            {
                printf("Aun no se han ingresado clientes\n");
            }
            break;
        case 5:
            if (flagClient==1&&flagAlqui==1)
            {
                finAlquiler(alqui);
            }
            else if (flagClient==0)
            {
                printf("Aun no se han ingresado clientes\n");
            }
            else
            {
                printf("Aun no se han ingresado alquileres\n");
            }
        case 6:
            if (flagClient==1&&flagAlqui==1)
            {
                informar(alqui, clienteAlquiler);
            }
            else if (flagClient==0)
            {
                printf("Aun no se han ingresado clientes\n");
            }
            else
            {
                printf("Aun no se han ingresado alquileres\n");
            }
        }
        printf("\nDesea realizar otra operacion? [s/n]: ");
        fflush(stdin);
        scanf ("%c",&seguir);
    }
return 0;
}
