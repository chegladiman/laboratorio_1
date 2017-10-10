#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

#define CLIENTE 5
#define ALQUI 5
#define CLIENTEALQUI 25

int main()
{
    int opcionMenu,flagClient=0,flagAlqui=0;
    char seguir='s';

    Cliente client[CLIENTE];
    Alquiler alqui[ALQUI];

    limpiaTodo(client, alqui);
    while (seguir=='s')
    {
    opcionMenu = menuInicial();

        switch (opcionMenu)
        {
        case 1:
            altaCliente(client, alqui);
            flagClient=1;
            break;
        case 2:
            if (flagClient==1)
            {
                modificarCliente(client, alqui);
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
                bajaCliente(client, alqui);
            }
            else
            {
                printf("Aun no se han ingresado clientes\n");
            }
            break;
        case 4:
            if (flagClient==1)
            {
                nuevoAlquiler (client, alqui);
            }
            else
            {
                printf("Aun no se han ingresado clientes\n");
            }
            break;
        case 5:
            if (flagAlta==1)
            {
                finAlquiler(client, alqui);
            }
            else
            {
                printf("Aun no se han ingresado clientes\n");
            }
        case 6:
            {

            }
        }
        printf("\nDesea realizar otra operacion? [s/n]: ");
        fflush(stdin);
        scanf ("%c",&seguir);
    }
return 0;
}
