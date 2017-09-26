#include <stdio.h>
#include <string.h>
#include <ctype.h>

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
