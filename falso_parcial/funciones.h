#include <stdio.h>
#include <string.h>

typedef struct
{
    int codigo;
    int cantProd;
    char descProd[51];
    float impProd;
    int estado;
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
int altaProducto(ProductoProveedor prodProv[],Producto prod[],Proveedor prov[]);
int validarEntero(char strCod[]);
int validarString (char strDescr[]);
int validarFloat (char strCod[]);
int modificarProducto(ProductoProveedor prodProv[],Producto prod[],Proveedor prov[]);
int bajaProducto(ProductoProveedor prodProv[],Producto prod[],Proveedor prov[]);
int informarDatos(ProductoProveedor prodProv[],Producto prod[],Proveedor prov[]);
int listarDatos(ProductoProveedor prodProv[],Producto prod[],Proveedor prov[]);
