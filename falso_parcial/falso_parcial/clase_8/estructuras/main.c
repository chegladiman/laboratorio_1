#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int main()
{
    struct alumno alu;

    printf ("Ingrese legajo: ");
    scanf ("%d",&alu.legajo);
    printf ("Ingrese nombre: ");
    fflush(stdin);
    scanf ("%[^\n]",alu.nombre);
    printf ("Ingrese nota de primer parcial: ");
    scanf ("%d",&alu.parcial1);
    printf ("Ingrese nota de segundo parcial: ");
    scanf ("%d",&alu.parcial2);
    alu.prom=promedio(alu.parcial1,alu.parcial2);
    printf ("El alumno %s legajo %d saco %d en el primer parcial y %d en el segundo parcial.\nSu promedio es: %.2f",alu.nombre,alu.legajo,alu.parcial1,alu.parcial2,alu.prom);

    return 0;
}
