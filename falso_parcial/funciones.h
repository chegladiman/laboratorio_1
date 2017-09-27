#include <stdio.h>
#include <string.h>

typedef struct
{
    int codigo;
    int cantProd;
    char descProd[51];
    float impProd;
}Producto;

typedef struct
{
    int codigo;
    char descProv[51];
    int estado;
}Proveedor;

typedef struct
{
    int codProd;
    int codProv;
    int estado;
}ProductoProveedor;

int limpiaTodo(Producto prod[], Proveedor prov[], ProductoProveedor prodProv[]);
int menuInicial(void);
int validarMenu(char opcionMenu[]);
int altaProducto(ProductoProveedor prodProv[],Producto prod[]);
int validarEntero(char validarCodigo[]);
int validarDescr (char productoDescripcion[]);
int validarFloat (char validarImporte[]);
