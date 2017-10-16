#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "lib.h"

#define CLIENTE 4
#define ALQUI 5
#define CLIENTEALQUI 20
#define MAX_MENU 5
#define MAX_STR 21
#define MAX_LONG 5
#define MAX_INT 5
#define MIN_OPC 1
#define MAX_OPC 5

int inicializar(Cliente client[], Alquiler alqui[], ClienteAlquiler clienteAlquiler[])
{
    int i;

    for (i=0;i<CLIENTE;i++)
    {
        client[i].estado = 0;
    }

    for (i=0;i<ALQUI;i++)
    {
        alqui[i].estado = 0;
    }

    for (i=0;i<CLIENTEALQUI;i++)
    {
        clienteAlquiler[i].estado = 0;
    }
return 0;
}

int menuInicial(void)
{
    char opcionMenu[MAX_MENU];
    int resultadoMenu;

    printf("Seleccione la opcion deseada:\n");
    printf("1. Alta del cliente\n2. Modificar datos del cliente\n3. Baja del cliente\n4. Nuevo alquiler\n5. Fin del alquiler\n6. Informar\n");
    scanf("%s",opcionMenu);
    resultadoMenu = validarMenu(opcionMenu);
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
        if (auxMenu<MIN_OPC||auxMenu>MAX_OPC)
        {
            printf("\nLa opcion ingresada no es valida. Por favor ingrese una opcion valida\n");
            menuInicial();
        }
    }
    return (auxMenu);
}

int funcionAlta(Cliente client[])
{
    int i=0, valor, flagFull=1;
    char strLong[MAX_LONG];
    char strString[MAX_STR];

    system("cls");
    printf("***ALTA DE CLIENTE***\n");
    for(i=0;i<CLIENTE;i++)
    {
        if (client[i].estado==0)
        {
            flagFull=0;
            client[i].estado=1;
            client[i].idCliente = i+1;

            do
            {
                printf("DNI: ");
                fflush(stdin);
                scanf("%s", strLong);
                valor = validarLong (strLong);
            }while(valor == 0);
            client[i].dni = atol(strLong);

            do
            {
                printf("Nombre: ");
                fflush(stdin);
                scanf ("%s",strString);
                valor = validarString (strString);
            }while(valor == 0);
            strcpy (client[i].nombre,strString);

            do
            {
                printf("Apellido: ");
                fflush(stdin);
                scanf ("%s",strString);
                valor = validarString (strString);
            }while(valor == 0);
            strcpy (client[i].apellido,strString);

            printf("El cliente %s %s con DNI %ld ha sido dado de alta con el Id %d",client[i].nombre,client[i].apellido,client[i].dni,client[i].idCliente);

            break;
        }
    }
    if (flagFull==1)
    {
        printf("No se pueden ingresar mas clientes. Recuerde que puede modificar o eliminar algun cliente existente");
    }
return 0;
}

int funcionModificar(Cliente client[])
{
    int i,codBusqueda,valor,flag=0;
    char strInt[MAX_INT],strString[MAX_STR];

    printf("***MODIFICACION DE CLIENTE***\n");

    do
    {
    printf("Ingrese ID del cliente a modificar: ");
    fflush(stdin);
    scanf("%s",strInt);
    valor = validarInt(strInt);
    }while (valor==0);
    codBusqueda = atoi(strInt);

    for (i=0;i<CLIENTE;i++)
    {
        if (codBusqueda==client[i].idCliente&&client[i].estado==1)
        {
            flag=1;

            do
            {
                printf("Nombre actual del cliente: %s", client[i].nombre);
                printf(" Nuevo nombre del cliente: ");
                fflush(stdin);
                scanf ("%s",strString);
                valor = validarString(strString);
            }while(valor == 0);
            strcpy (client[i].nombre,strString);

            do
            {
                printf("Apellido actual del cliente: %s", client[i].apellido);
                printf(" Nuevo apellido del cliente: ");
                fflush(stdin);
                scanf ("%s",strString);
                valor = validarString(strString);
            }while(valor == 0);
            strcpy (client[i].apellido,strString);

            break;
        }
    }
    printf("El nombre del cliente %d ha sido modificado a %s %s",client[i].idCliente,client[i].nombre,client[i].apellido);
    if (flag==0)
    {
        printf("El ID ingresado no coincide con uno existente.\n");
    }
return 0;
}

int funcionBaja(Cliente client[])
{
    int i,codBusqueda,valor,flag=0;
    char strInt[MAX_INT];

    printf("***BAJA DE CLIENTE***\n");

    do
    {
        printf("Ingrese ID del cliente a dar de baja: ");
        fflush(stdin);
        scanf("%s",strInt);
        valor = validarInt(strInt);
    }while (valor==0);
    codBusqueda = atoi(strInt);

    for (i=0;i<CLIENTE;i++)
    {
        if (codBusqueda==client[i].idCliente&&client[i].estado==1)
        {
            flag=1;
            client[i].estado = 0;
            printf("El cliente %s %s con DNI %ld ha sido dado de baja",client[i].nombre,client[i].apellido,client[i].dni);
            break;
        }
    }

    if (flag==0)
    {
        printf("El ID ingresado no coincide con uno existente.\n");
    }
return 0;
}

int nuevoAlquiler(Cliente client[], Alquiler alqui[])
{
    char strInt[MAX_INT];
    int i,valor=0,valor2=0, flagFull=1, idAlqui;

    printf("***NUEVO ALQUILER***");
    for (i=0;i<CLIENTEALQUI;i++)
    {
        if (alqui[i].estado==0)
        {
            flagFull=0;
            alqui[i].estado=1;

            do
            {
                do
                {
                    printf("ID del cliente: ");
                    fflush(stdin);
                    scanf("%s",strInt);
                    valor = validarInt(strInt);
                }while (valor == 0);
                idAlqui = atoi(strInt);
                valor2 = validarId(idAlqui,client);
            }while (valor2 == 0);
            alqui[i].idCliente = idAlqui;

            do
            {
            printf("Equipo [1: AMOLADORA][2: MEZCLADORA][3: TALADRO]");
            fflush(stdin);
            scanf("%s",strInt);
            valor = validarInt(strInt);
            }while (valor == 0);
            alqui[i].equipo = atoi(strInt);

            do
            {
            printf("Tiempo estimado (en dias): ");
            fflush(stdin);
            scanf("%s",strInt);
            valor = validarInt(strInt);
            }while (valor == 0);
            alqui[i].tiempo = atoi(strInt);

            do
            {
            printf("Operador [1: JUAN][2: PEDRO][3: LUIS]");
            fflush(stdin);
            scanf("%s",strInt);
            valor = validarInt(strInt);
            }while (valor == 0);
            alqui[i].operador = atoi(strInt);

            break;
        }
    }
    if (flagFull==1)
    {
        printf("No se pueden ingresar mas alquileres.");
    }
    return 0;
}

int finAlquiler(Alquiler alqui[])
{
    int i,codBusqueda,valor,valor2,flag=0,idAlqui;
    char strInt[MAX_INT];

    printf("***FIN DE ALQUILER***\n");

    do
    {
        do
        {
            printf("ID del cliente: ");
            fflush(stdin);
            scanf("%s",strInt);
            valor = validarInt(strInt);
        }while (valor == 0);
        idAlqui = atoi(strInt);
        valor2 = validarIdAlquiler(idAlqui,alqui);
    }while (valor2 == 0);
    codBusqueda = idAlqui;

    for (i=0;i<CLIENTEALQUI;i++)
    {
        if (codBusqueda==alqui[i].idCliente&&alqui[i].estado==1)
        {
            flag=1;
            alqui[i].estado = 0;

            do
            {
            printf("Tiempo de uso (en dias) :");
            fflush(stdin);
            scanf("%s",strInt);
            valor = validarInt(strInt);
            }while (valor == 0);
            alqui[i].tiempo = strInt;
            printf("El alquiler ha sido finalizado");
            break;
        }
    }

    if (flag==0)
    {
        printf("El ID ingresado no coincide con un alquiler existente.\n");
    }
return 0;
}

int informar(Cliente client[], ClienteAlquiler clienteAlquiler[])
{
    for (i=0;i<CLIENTEALQUI;i++)
    {

    }
}

/* Error:0; Ok:1 */
int validarLong(char strLong[])
{
    int i,flag=1,largo;

    largo = strlen(strLong);
    for(i=0;i<largo;i++)
    {
        if(!isdigit(strLong[i]))
        {
            flag=0;
            printf("El dato ingresado no es valido. Por favor ingrese un numero de DNI valido.\n");
            break;
        }
    }
    return flag;
}

/* Error:0; Ok:1 */
int validarString (char strString[])
{
    int flag=0,i;

    for (i=0;i<=MAX_STR;i++)
    {
        if (strString[i]=='\0')
        {
            flag=1;
            break;
        }
    }
    if (flag==0)
    {
        printf ("El dato ingresado tiene demasiadas letras. Por favor ingrese un dato mas corto\n");
    }
return flag;
}

int validarInt(char strInt[])
{
    int i,flag=1,largo;

    largo = strlen(strInt);
    for(i=0;i<largo;i++)
    {
        if(!isdigit(strInt[i]))
        {
            flag=0;
            printf("El dato ingresado no es valido. Por favor ingrese un numero entero.\n");
            break;
        }
    }
    return flag;
}

int validarId(int valor2, Cliente client[])
{
    int i,flag=0;

    for(i=0;i<CLIENTE;i++)
    {
        if(valor2==client[i].idCliente)
        {
            flag=1;
            break;
        }
    }
    if (flag==0)
    {
        printf("El ID ingresado no corresponde con un cliente activo. Por favor verifique el ID e intente nuevamente\n");
    }
    return flag;
}

int validarIdAlquiler(int idAlqui, Alquiler alqui[])
{
    int i,flag=0;

    for(i=0;i<CLIENTEALQUI;i++)
    {
        if(idAlqui==alqui[i].idCliente)
        {
            flag=1;
            break;
        }
    }
    if (flag==0)
    {
        printf("El ID ingresado no corresponde con un alquiler activo. Por favor verifique el ID e intente nuevamente\n");
    }
    return flag;
}
