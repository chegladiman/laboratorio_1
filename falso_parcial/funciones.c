#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

#define CANTPROD 5
#define CANTPROV 5
#define CANTPRODPROV 25
#define LETRAS_DESCR 51


int limpiaTodo(Producto prod[], Proveedor prov[], ProductoProveedor prodProv[])
{
    int i;

    for (i=0;i<CANTPROD;i++)
    {
        prod[i].estado=0;
    }

    for (i=0;i<CANTPROV;i++)
    {
        prov[i].estado = 0;
    }

    for (i=0;i<CANTPRODPROV;i++)
    {
        prodProv[i].estado=0;
    }
return 0;
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
        auxMenu = atoi(opcionMenu);
        if (auxMenu<1||auxMenu>5)
        {
            printf("\nLa opcion ingresada no es valida. Por favor ingrese una opcion valida\n");
            menuInicial();
        }
    }
    return (auxMenu);
}

int altaProducto(ProductoProveedor prodProv[],Producto prod[],Proveedor prov[])
{
    int i=0, valor,contcant=0;
    char strCod[11];
    char strDescr[LETRAS_DESCR];

    system("cls");
    for(i=0;i<CANTPROD;i++)
    {
        if (contcant==CANTPROD)
        {
            if (prod[i].estado==0)
            {
                do
                {
                    printf("Codigo del producto: ");
                    scanf("%s", strCod);
                    valor = validarEntero(strCod);
                }while(valor == 0);
                prod[i].codigo = atoi(strCod);

                do
                {
                    printf("Codigo del proveedor: ");
                    scanf("%s", strCod);
                    valor = validarEntero(strCod);
                }while(valor == 0);
                prodProv[i].codProv = atoi(strCod);

                do
                {
                    printf("Descripcion del producto (max. 50 caracteres): ");
                    scanf ("%s",strDescr);
                    valor = validarString (strDescr);
                }while(valor == 0);
                strcpy (prod[i].descProd,strDescr);

                do
                {
                    printf("Importe del producto: ");
                    scanf("%s", strCod);
                    valor = validarFloat(strCod);
                }while(valor == 0);
                prod[i].impProd = atoi(strCod);

                do
                {
                    printf("Cantidad del producto: ");
                    scanf("%s", strCod);
                    valor = validarEntero(strCod);
                }while(valor == 0);
                prod[i].cantProd = atoi(strCod);

                prod[i].estado=1;
                prodProv[i].codProd = prod[i].codigo;
                prodProv[i].estado = 1;
                break;
            }
            if (prod[i].estado==1)
            {
                contcant++;
            }
        }
        else
        {
            printf("No se pueden ingresar mas productos.\n");
        }
    }
return 0;
}

/* Error:0; Ok:1 */
int validarEntero(char strCod[])
{
    int i,flag=1,largo;

    largo = strlen(strCod);
    for(i=0;i<largo;i++)
    {
        if(!isdigit(strCod[i]))
        {
            flag=0;
            printf("El dato ingresado no es valido. Por favor ingrese un numero entero.\n");
            break;
        }
    }
    return flag;
}

int validarFloat(char strCod[])
{
    int i,flag=1,largo;

    largo = strlen(strCod);
    for(i=0;i<largo;i++)
    {
        if(!isdigit(strCod[i])&&(strCod[i]!='.'))
        {
            flag=0;
            printf("El dato ingresado no es valido. Por favor ingrese un importe valido.\n");
            break;
        }
    }
    return flag;
}

int validarString (char strDescr[])
{
    int flag=0,i;

    for (i=0;i<=LETRAS_DESCR;i++)
    {
        if (strDescr[i]=='\0')
        {
            flag=1;
            break;
        }
    }
    if (flag==0)
    {
        printf ("La descripcion ingresada excede los 50 caracteres. Por favor ingrese una descripcion valida.\n");
    }
return flag;
}

int modificarProducto(ProductoProveedor prodProv[],Producto prod[],Proveedor prov[])
{
    int i,codBusqueda,valor,flag=0;
    char strCod[11],strDescr[LETRAS_DESCR];

    printf("Ingrese codigo del producto a modificar: ");
    scanf("%d",&codBusqueda);
    for (i=0;i<CANTPROD;i++)
    {
        if (codBusqueda==prod[i].codigo&&prod[i].estado==1)
        {
            flag=1;
            do
            {
                printf ("Codigo actual del proveedor: %d",prodProv[i].codProv);
                printf("\nNuevo codigo del proveedor: ");
                scanf("%s", strCod);
                valor = validarEntero(strCod);
            }while(valor == 0);
            prodProv[i].codProv = atoi(strCod);

            do
            {
                printf("Nueva descripcion del producto (max. 50 caracteres): ");
                scanf ("%s",strDescr);
                valor = validarString (strDescr);
            }while(valor == 0);
            strcpy (prod[i].descProd,strDescr);

            do
            {
                printf("Nuevo importe del producto: ");
                scanf("%s", strCod);
                valor = validarFloat(strCod);
            }while(valor == 0);
            prod[i].impProd = atoi(strCod);

            do
            {
                printf("Nueva cantidad del producto: ");
                scanf("%s", strCod);
                valor = validarEntero(strCod);
            }while(valor == 0);
            prod[i].cantProd = atoi(strCod);

            prodProv[i].codProd = prod[i].codigo;
        }
    }
    if (flag==0)
    {
        printf("El codigo ingresado no coincide con un producto existente.\n");
    }
return 0;
}

int bajaProducto(ProductoProveedor prodProv[],Producto prod[],Proveedor prov[])
{
    int i,codBusqueda,flag=0;
    char vacio[] = " ";

    printf("Ingrese codigo del producto a borrar: ");
    scanf("%d",&codBusqueda);
    for (i=0;i<CANTPROD;i++)
    {
        if (codBusqueda==prod[i].codigo)
        {
            printf ("El producto %d ha sido eliminado.\n",prod[i].codigo);
            flag=1;
            prod[i].codigo=0;
            prod[i].cantProd=0;
            prod[i].estado=0;
            prod[i].impProd=0;
            strcpy (prod[i].descProd,vacio);
        }
    }
    if (flag==0)
    {
        printf("El codigo ingresado no coincide con un producto existente\n");
    }
return 0;
}

int informarDatos(ProductoProveedor prodProv[],Producto prod[],Proveedor prov[])
{
    int i, mayor=prod[i].cantProd, menor=prod[i].cantProd;

    for(i=0;i<CANTPROD;i++)
        {
        if(prod[i].cantProd>mayor)
            {
                mayor=prod[i].cantProd;
            }
        if(prod[i].cantProd<menor)
            {
                menor=prod[i].cantProd;
            }
        }
    for (i=0;i<CANTPROD;i++)
    {
        if (prod[i].cantProd==mayor)
        {
            printf("PRODUCTO CON MAYOR CANTIDAD:");
            printf("\nCodigo del producto: %d",prod[i].codigo);
            printf("\nCodigo del proveedor: %d",prodProv[i].codProd);
            printf("\nDescripcion del producto: %s",prod[i].descProd);
            printf("\nImporte del producto: %.2f",prod[i].impProd);
        }
        if (prod[i].cantProd==menor)
        {
            printf("PRODUCTO CON MENOR CANTIDAD:");
            printf("\nCodigo del producto: %d",prod[i].codigo);
            printf("\nCodigo del proveedor: %d",prodProv[i].codProd);
            printf("\nDescripcion del producto: %s",prod[i].descProd);
            printf("\nImporte del producto: %.2f",prod[i].impProd);
        }
    }
return 0;
}

int listarDatos(ProductoProveedor prodProv[],Producto prod[],Proveedor prov[])
{
    int i,j;
    int temp;
    for(i=1;i<CANTPROD;i++)
    {

    }
return 0;
}
