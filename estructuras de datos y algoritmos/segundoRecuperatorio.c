// La cadena de hoteles Hilton tiene establecimientos en todo el mundo.
// Para conocer las ganancias, se ingresa código de país, numero de establecimiento y su recaudación mensual (en millones de dólares) en una lista simplemente enlazada.
// El ingreso de datos termina con el código de país igual a cero.
// Se deben ingresar los datos ordenados por país y establecimiento.
// Mostrar la lista.
// Generar una nueva lista con la recaudación total por país.
// Eliminar de la lista original aquellos establecimientos con recaudación inferior al promedio de todos los establecimientos ingresados.
// Ingresar dos nuevos establecimientos con el código de país y la recaudación mensual e Insertarlas en orden en la lista.

//   Ejemplo:
// Lista     2 1  1500 |  2 3 2000 | 3 1 5000 | 3 4 1800 | 5 1 3500
// Lista generada   2 3500 |  3 6800 | 5 3500
// Promedio:  2760
// Lista con eliminación      3 1 5000   | 5 1 3500
// Se ingresa:  1 3 4300
//             4 5 5500
// Lista con inserción:  1 3 4300 | 3 1 5000 |  4 5 5500 | 5 1 3500

#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int codigoPais;
    int numeroEstablecimiento;
    int recaudacion;
    struct lista *sig;
} nodo;

void crear(nodo *registro)
{
    printf("\nIngrese codigo de pais: ");
    scanf("%d", &registro->codigoPais);

    if (registro->codigoPais == 0)
    {
        registro->sig = NULL;
    }
    else
    {
        printf("\nIngrese numero de establecimiento: ");
        scanf("%d", &registro->numeroEstablecimiento);
        printf("\nIngrese recaudacion mensual: ");
        scanf("%d", &registro->recaudacion);

        registro->sig = (nodo *)malloc(sizeof(nodo));
        crear(registro->sig);
    }
}

void mostrar(nodo *registro)
{
    if (registro->codigoPais != 0)
    {
        printf("\n%d\t%d\t%d", registro->codigoPais, registro->numeroEstablecimiento, registro->recaudacion);
        mostrar(registro->sig);
    }
}

int main()
{
    nodo *head = NULL;
    int *contador = 0;
    int *suma = 0;
    int promedio;

    head = (nodo *)malloc(sizeof(nodo));

    crear(head);
    printf("\n\n Lista");
    mostrar(head);

    //Entrega en blanco
}
