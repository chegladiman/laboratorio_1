#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define CANTPROV 5
#define CANTPROD 5
#define CANTPRODPROV 25

int main()
{
    int opcionMenu,flagAlta=0;
    char seguir='s';

    Producto prod[CANTPROD];
    Proveedor prov[CANTPROV];
    ProductoProveedor prodProv[CANTPRODPROV];

    limpiaTodo(prod, prov, prodProv);
    while (seguir=='s')
    {
    opcionMenu = menuInicial();

        switch (opcionMenu)
        {
        case 1:
            altaProducto(prodProv, prod, prov);
            flagAlta=1;
            break;
        case 2:
            if (flagAlta==1)
            {
                modificarProducto(prodProv, prod, prov);
            }
            else
            {
                printf("Aun no se han ingresado productos\n");
            }
            break;
        case 3:
            if (flagAlta==1)
            {
                bajaProducto(prodProv, prod, prov);
            }
            else
            {
                printf("Aun no se han ingresado productos\n");
            }
            break;
        case 4:
            if (flagAlta==1)
            {
                informarDatos(prodProv, prod, prov);
            }
            else
            {
                printf("Aun no se han ingresado productos\n");
            }
            break;
        case 5:
            if (flagAlta==1)
            {
                listarDatos(prodProv, prod, prov);
            }
            else
            {
                printf("Aun no se han ingresado productos\n");
            }
        }
        printf("\nDesea realizar otra operacion? [s/n]: ");
        fflush(stdin);
        scanf ("%c",&seguir);
    }
return 0;
}
