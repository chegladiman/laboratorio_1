#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "lib.h"

#define CLIENTE 4
#define ALQUI 4
#define NOMBRE 21

int limpiaTodo(Cliente client[], Alquiler alqui[])
{
    int i;

    for (i=0;i<CLIENTE;i++)
    {
        client[i].estado=0;
    }

    for (i=0;i<ALQUI;i++)
    {
        alqui[i].estado = 0;
    }
return 0;
}

int menuInicial(void)
{
    char opcionMenu[15];
    int resultadoMenu;

    printf("Seleccione la opcion deseada:\n");
    printf("1. Alta del cliente\n2. Modificar datos del cliente\n3. Baja del cliente\n4. Nuevo alquiler\n5. Fin del alquiler\n6. Informar\n");
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

int altaCliente(Cliente client[],Alquiler alqui[])
{
    int i=0, valor,contcant=0,id=0;
    char strCod[11];
    char strNombre[NOMBRE];

    system("cls");
    for(i=0;i<CLIENTE;i++)
    {

            if (client[i].estado==0)
            {
                id++;
                client[i].idCliente = id;
                do
                {
                    printf("DNI: ");
                    scanf("%s", strCod);
                    valor = validarLong(strCod);
                }while(valor == 0);
                client[i].idCliente = atol(strCod);


                do
                {
                    printf("Nombre: ");
                    scanf ("%s",strNombre);
                    valor = validarString (strNombre);
                }while(valor == 0);
                strcpy (client[i].nombre,strNombre);

                do
                {
                    printf("Apellido: ");
                    scanf ("%s",strNombre);
                    valor = validarString (strNombre);
                }while(valor == 0);
                strcpy (client[i].apellido,strNombre);

                client[i].estado=1;
                break;
            }
            if (client[i].estado==1)
            {
                contcant++;
            }
    }
return 0;
}

/* Error:0; Ok:1 */
int validarLong(char strCod[])
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

int validarString (char strNombre[])
{
    int flag=0,i;

    for (i=0;i<=NOMBRE;i++)
    {
        if (strNombre[i]=='\0')
        {
            flag=1;
            break;
        }
    }
    if (flag==0)
    {
        printf ("El nombre es demasiado largo. Por favor ingrese un nombre mas corto\n");
    }
return flag;
}

int modificarCliente(Cliente client[],Alquiler alqui[])
{
    int i,codBusqueda,valor,flag=0;
    char strCod[11],strNombre[NOMBRE];

    printf("Ingrese ID del cliente a modificar: ");
    scanf("%d",&codBusqueda);
    for (i=0;i<CLIENTE;i++)
    {
        if (codBusqueda==client[i].idCliente&&client[i].estado==1)
        {
            flag=1;

            do
            {
                printf("Nombre actual del cliente: %s", client[i].nombre);
                printf("Nuevo nombre del cliente: ");
                scanf ("%s",strNombre);
                valor = validarString (strNombre);
            }while(valor == 0);
            strcpy (client[i].nombre,strNombre);

            do
            {
                printf("Apellido actual del cliente: %s", client[i].nombre);
                printf("Nuevo apellido del cliente: ");
                scanf ("%s",strNombre);
                valor = validarString (strNombre);
            }while(valor == 0);
            strcpy (client[i].apellido,strNombre);
        }
    }
    if (flag==0)
    {
        printf("El ID ingresado no coincide con uno existente.\n");
    }
return 0;
}

int bajaCliente(Cliente client[],Alquiler alqui[])
{
    int i,codBusqueda,flag=0;
    char vacio[] = " ";

    printf("Ingrese ID del cliente a borrar: ");
    scanf("%d",&codBusqueda);
    for (i=0;i<CLIENTE;i++)
    {
        if (codBusqueda==client[i].idCliente)
        {
            printf ("El cliente %d ha sido eliminado.\n",client[i].idCliente);
            flag=1;
            client[i].idCliente=0;
            client[i].dni=0;
            client[i].estado=0;
            strcpy (client[i].nombre,vacio);
            strcpy (client[i].apellido,vacio);
        }
    }
    if (flag==0)
    {
        printf("El codigo ingresado no coincide con un producto existente\n");
    }
return 0;
}

int nuevoAlquiler(Cliente client[],Alquiler alqui[])
{
    int i=0, valor,valor2,contcant=0,id=0;
    char strCod[11];

    system("cls");
    for(i=0;i<ALQUI;i++)
    {

            if (alqui[i].estado==0)
            {
                do
                {
                    printf ("***NUEVO ALQUILER***");
                    printf("Cliente: ");
                    scanf("%s", strCod);
                    valor = validarEntero(strCod);
                }while(valor == 0);
                alqui[i].idCliente = atoi(strCod);

                do
                {
                    printf("Equipo: ");
                    scanf ("%s",strCod);
                    valor = validarEntero (strCod);
                }while(valor == 0);
                alqui[i].equipo = atoi (strCod);

                do
                {
                    printf("Tiempo estimado (Dias): ");
                    scanf ("%s",strCod);
                    valor = validarEntero (strCod);
                }while(valor == 0);
                alqui[i].tiempo = atoi (strCod);

                do
                {
                    printf("Operador: ");
                    scanf ("%s",strCod);
                    valor = validarEntero (strCod);
                }while(valor == 0);
                alqui[i].operador = atoi (strCod);

                alqui[i].estado=1;
                break;
            }
            if (client[i].estado==1)
            {
                contcant++;
            }
    }
return 0;
}

int finAlquiler (Cliente client[],Alquiler alqui[])
{

}

