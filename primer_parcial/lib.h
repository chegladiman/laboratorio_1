#include <stdio.h>
#include <string.h>

typedef struct
{
    int idCliente;
    long int dni;
    char nombre[21];
    char apellido[21];
    int estado;
    int equipo;
    int tiempo;
    int operador;
}Cliente;

typedef struct
{
    int idCliente;
    int equipo;
    int tiempo;
    int operador;
    int estado;
}Alquiler;

int limpiaTodo(Cliente client[], Alquiler alqui[]);
int menuInicial(void);
int validarMenu(char opcionMenu[]);
int altaCliente(Cliente client[], Alquiler alqui[]);
int validarEntero(char strCod[]);
int validarLong(char strCod[]);
int validarString (char strNombre[]);
int modificarCliente(Cliente client[], Alquiler alqui[]);
int bajaCliente(Cliente client[], Alquiler alqui[]);
int finAlquiler (Cliente client[],Alquiler alqui[]);


