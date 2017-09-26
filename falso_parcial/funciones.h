#include <stdio.h>
#include <string.h>

typedef struct
{
    int codProd,codProv,cantProd;
    char descProd[51];
    float impProd;
}Producto;

typedef struct
{
    int codProv;
    char descProv[51];
}Proveedor;

int menuInicial(void);
int validarMenu(char opcionMenu[15]);
