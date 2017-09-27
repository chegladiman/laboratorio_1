#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define CANTPROV 5
#define CANTPROD 5
#define CANTPRODPROV 25

int main()
{
    int auxMenu;

    Producto prod[CANTPROD];
    Proveedor prov[CANTPROV];
    ProductoProveedor prodProv[CANTPRODPROV];

    limpiaTodo(prod, prov, prodProv);
    menuInicial();

    switch (auxMenu)
    {
    case 1:
        altaProducto(prodProv, prod);
        break;
    }

    return 0;
}
