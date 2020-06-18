// Crear una lista simplemente enlazada con el número de legajo, nombre y apellido y cantidad de materias aprobadas de los alumnos de una facultad. La carga de datos finaliza cuando el número de legajo es igual a cero.
// Mostrar la lista.
// Mostrar cuántos alumnos tiene más de 10 materias aprobadas.
// Generar una nueva lista con aquellos alumnos que tiene menos de 3 materias aprobadas.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Defino estructura nodo
typedef struct lista
{
    int legajo; //Si legajo == 0 finaliza la carga.
    char nombre[20];
    int materiasAprobadas;
    struct lista *sig;
} nodo;

//CREAR LISTA
void crearLista(nodo *registro)
{
    int contador = 0; //???? esto no lo declaraba la profe pero lo usaba, creo que se puede sacar
    printf("Ingresa un numero de legajo: \n");
    scanf("%d", &registro->legajo);

    if (registro->legajo == 0)
    {
        registro->sig = NULL;
    }
    else
    {
        printf("Ingresa un nombre: \n");
        scanf("%s", registro->nombre);
        printf("Ingresa un numero materias aprobadas: \n");
        scanf("%d", &registro->materiasAprobadas);

        registro->sig = (nodo *)malloc(sizeof(nodo));
        contador++; //???? acá aumentaba el contador en 1 no sé por qué, supongo que se puede sacar
        crearLista(registro->sig);
    }
}

//MOSTRAR LISTA
void mostrarLista(nodo *registro)
{
    if (registro->sig != NULL)
    {
        printf("legajo: %d \n", registro->legajo);
        printf("nombre: %s \n", registro->nombre);
        printf("Materias aprobadas: %d \n", registro->materiasAprobadas);
        mostrarLista(registro->sig);
    }
}

//Cuantos aprobaron más de 10 materias
int aprobo10(nodo *registro)
{
    int contador = 0;

    if (registro->sig != NULL)
    {
        if (registro->materiasAprobadas > 10)
        {
            contador++;
            aprobo10(registro->sig);
        }
    }

    return contador;
}

//Aprobaron menos de 3 materias
void nuevaLista(nodo *registro, nodo *registroBurros)
{
    if (registro->sig != NULL)
    {
        printf("ENTRE A LA FUNCION.\n");
        if (registro->materiasAprobadas < 3)
        {
            registroBurros->legajo = registro->legajo;
            strcpy(registroBurros->nombre, registro->nombre);
            registroBurros->materiasAprobadas = registro->materiasAprobadas;
            registroBurros->sig = (nodo *)malloc(sizeof(nodo));
            nuevaLista(registro->sig, registroBurros->sig);
        }
    }
}

int main()
{
    nodo *cabeza, *cabezaBurros;
    cabeza = (nodo *)malloc(sizeof(nodo));
    cabezaBurros = (nodo *)malloc(sizeof(nodo));

    crearLista(cabeza);
    mostrarLista(cabeza);

    printf("%d alumnx/s aprobaron más de 10 materias \n", aprobo10(cabeza)); //A veces funciona a veces no?

    nuevaLista(cabeza, cabezaBurros); //A veces funcion a veces no? No logra leer el ultimo dato con sig en NULL por lo que pierdo un registro
    printf("TERMINE DE LEER LA FUNCION NUEVA LISTA\n"); 
    mostrarLista(cabezaBurros);

    return 0;
}