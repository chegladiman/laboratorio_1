#include <stdio.h>
#include <string.h>

typedef struct
{
    int idCliente;
    long int dni;
    char nombre[21];
    char apellido[21];
    int estado;
}Cliente;

typedef struct
{
    int idCliente;
    int equipo;
    int tiempo;
    int operador;
    int estado;
}Alquiler;

typedef struct
{
    char nombreYApellido[42];
    int equipoMasAlquilado;
    int tiempoPromedio;
    int estado;
}ClienteAlquiler;

int inicializar(Cliente client[], Alquiler alqui[], ClienteAlquiler clienteAlquiler[]);
int menuInicial(void);
int validarMenu(char opcionMenu[]);
int funcionAlta(Cliente client[]);
int funcionModificar(Cliente client[]);
int funcionBaja(Cliente client[]);
int nuevoAlquiler(Cliente client[], Alquiler alqui[]);
int finAlquiler(Alquiler alqui[]);
int informar(Cliente client[], ClienteAlquiler clienteAlquiler[]);
int validarInt(char strInt[]);
int validarLong(char strLong[]);
int validarString (char strString[]);
int validarId(int valor2, Cliente client[]);
int validarIdAlquiler(int idAlqui, Alquiler alqui[]);
