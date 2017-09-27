#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

#define CANTPROD 5
#define CANTPROV 5
#define CANTPRODPROV 25


int limpiaTodo(Producto prod[], Proveedor prov[], ProductoProveedor prodProv[])
{
    char vacio=" ";
    int i;

    for (i=0;i<CANTPROD;i++)
    {
        prod[i].cantProd=0;
        prod[i].impProd=0;
        strcpy (prod[i].descProd, vacio);
    }

    for (i=0;i<CANTPROV;i++)
    {
        prov[i].estado = 0;
        prov[i].codigo = 0;
        prov[i].descProv[0] = '\0';
    }

    for (i=0;i<CANTPRODPROV;i++)
    {
        prodProv[i].estado=0;
        prodProv[i].codProd = 0;
        prodProv[i].codProv = 0;
    }
}

int menuInicial(void)
{
    char opcionMenu[15];
    int resultadoMenu;

    printf("Seleccione la opcion deseada:\n");
    printf("1. Alta de producto\n2. Modificacion de producto\n3. Baja de producto\n4. Informe de producto\n5. Listar productos\n");
    scanf("%s",opcionMenu);
    resultadoMenu=validarMenu(opcionMenu);
    return resultadoMenu;
}

int validarMenu(char opcionMenu[])
{
    int i,flag=0,largo,auxMenu;

    largo = strlen(opcionMenu);
    for(i=0;i<largo;i++)
    {
        if(!isdigit(opcionMenu[i]))
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        printf("\nLa opcion ingresada no es valida. Por favor ingrese una opcion valida\n");
        menuInicial();
    }
    else
    {
        auxMenu=atoi(opcionMenu);
        if (auxMenu<1||auxMenu>5)
        {
            printf("\nLa opcion ingresada no es valida. Por favor ingrese una opcion valida\n");
            menuInicial();
        }
    }
    return (auxMenu);
}

int altaProducto(ProductoProveedor prodProv[],Producto prod[])
{
    int i=0, valor;
    char validarCodigo;
    char strCod[20];

    for(i=0;i<CANTPROD;i++)
    {
        /*Codigo de producto*/
        do
        {
            printf("Codigo del producto: ");
            scanf("%s", strCod);
            valor = validarEntero(strCod);
        }while(valor == 0);
        prod[i].codigo = atoi(strCod);

        /*Cantidad*/
        do
        {
            printf("Cantidad del producto: ");
            scanf("%s", strCod);
            valor=validarEntero(strCod);
        }while(valor == 0);
        prod[i].cantProd = atoi(strCod);

        do
        {
            printf("Descripcion del producto (max. 50 caracteres): ");
            scanf("%[^\n]",strCod);
            valor = validarDescr (strCod);
        }while(valor == 0);

    }


}

/* Error:0; Ok:1 */
int validarEntero(char validarCodigo[])
{
    int i,flag=1,largo,auxCod;

    largo = strlen(validarCodigo);
    for(i=0;i<largo;i++)
    {
        if(!isdigit(validarCodigo[i]))
        {
            flag=0;
            break;
        }
    }
    return flag;
}

int validarDescr(char productoDescripcion[])
{
    int largo=0,flag=0,i;

    for (i=0;i<CANTPROD;i++)
    {
        largo = strlen (productoDescripcion[i]);
        if (largo<50)
        {
            flag==1;
            break;
        }
        printf("La descripcion de producto excede los 50 caracteres. Vuelva a intentar");
    }
return flag;
}

int validarFloat(char validarImporte[])
{
    int i,flag=0,largo,auxCod;

    largo = strlen(validarImporte);
    for(i=0;i<largo;i++)
    {
        if(isdigit(validarImporte[i])||validarImporte[i]=='.')
        {
            flag=1;
            break;
        }
    }
    return flag;
}
