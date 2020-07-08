// Crear una pila con la siguiente información :
// num : numero entero.
// siguiente : puntero al próximo elemento de la pila.

// Escribir la función necesaria para obtener el valor máximo de la pila y la posicion que ocupa dentro de la pila.Mostrar si se repite,
// en todas las posiciones.

#include <stdio.h>
#include <stdlib.h>

    typedef struct pila
{
    int num;
    struct pila *sig;
} nodo;

nodo *crearNodo(int dato)
{
    nodo *nuevo = NULL;
    nuevo = (nodo *)malloc(sizeof(nodo));
    nuevo->num = dato;
    nuevo->sig = NULL;
    return nuevo;
}

void apilar(nodo **tope, nodo *nuevo)
{
    nuevo->sig = *tope;
    *tope = nuevo;
}

nodo desapilar(nodo **tope)
{
    nodo *aux;
    nodo datos;
    datos = **tope;
    aux = *tope;
    *tope = (*tope)->sig;
    free(aux);
    return datos;
}

void mostrar(nodo aux, int *maximo, int *contador, int *posicion)
{
    printf("%d \n", aux.num);
    if (*contador == 0)
    {
        *maximo = aux.num;
    }
    
    *contador += 1;
    
    if (aux.num > *maximo)
    {
        *maximo = aux.num;
        *posicion = *contador;
    }
}

int main()
{
    int i, num, cant, maximo, contador = 0, posicion;
    nodo *tope = NULL;

    printf("Cuantos datos quiere ingresar? ");
    scanf("%d", &cant);

    for (i = 0; i < cant; i++)
    {
        printf("\nIngrese un numero: ");
        scanf("%d", &num);
        apilar(&tope, crearNodo(num));
    }
    printf("\nDesapilamos: \n");
    while (tope != NULL)
    {
        mostrar(desapilar(&tope), &maximo, &contador, &posicion);
    }

    printf("El valor máximo ingresado es: %d y su posicion es: %d\n", maximo, posicion);
}

// Crear y Mostrar un árbol binario de búsqueda.
//        Escribir las funciones necesarias para calcular y luego mostrar;
// a) El valor minimo de los elementos mayores a la raiz.
// b) Contar cuantas veces los valores de los nodos hojas son menores al valor de la raiz

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct arbol
{
    int num;
    struct arbol *izq;
    struct arbol *der;
} treenode;

void insertar(treenode **hoja, int elem)
{
    int numero = elem;
    if (elem == -1)
    {
        return;
    }
    if (*hoja == NULL)
    {
        (*hoja) = (treenode *)malloc(sizeof(treenode));
        (*hoja)->num = elem;
        (*hoja)->der = NULL;
        (*hoja)->izq = NULL;
    }
    else
    {
        if (numero > (*hoja)->num)
        {
            insertar(&(*hoja)->der, elem);
        }
        else
        {
            insertar(&(*hoja)->izq, elem);
        }
    }
    return;
}

void crear(treenode **hoja, int *raiz)
{
    int numero;
    printf("\nIngrese un numero: ");
    scanf("%d", &numero);
    *raiz = numero;
    while (numero != -1)
    {
        insertar(&(*hoja), numero);
        printf("\nIngrese numero: ");
        scanf("%d", &numero);
    }
}

void mostrar(treenode *hoja, int *contador, int raiz, int *contadorRaiz, int *minimo) //EN ORDEN
{
    if (hoja != NULL)
    {
        mostrar(hoja->izq, contador, raiz, contadorRaiz, minimo);
        printf("%d ", hoja->num);
        //Logica ejercicio b
        if (hoja->izq == NULL && hoja->der == NULL && hoja->num < raiz)
        {
            // printf("\n -> Hoja menor que raiz = %d\n", hoja->num);
            *contador += 1;
        }

        //Logica ejercicio a
        if (hoja->num > raiz && *contadorRaiz == 0)
        {
            *minimo = hoja->num;
            *contadorRaiz += 1;
        }

        if (hoja->num > raiz && hoja->num < *minimo)
        {
            *minimo = hoja->num;
        }

        mostrar(hoja->der, contador, raiz, contadorRaiz, minimo);
    }
    return;
}

int main()
{
    int contador = 0, raiz, contadorRaiz = 0, minimo;
    treenode *arbol = NULL;

    crear(&arbol, &raiz);

    printf("\nArbol:");
    mostrar(arbol, &contador, raiz, &contadorRaiz, &minimo);

    printf("\n El valor minimo de los elementos mayores a la raiz es: %d\n", minimo);
    printf("La cantidad de nodo hojas menores que la raiz son: %d\n", contador);
    // printf("La raiz es: %d\n", raiz);

    return 0;
}

// --------------->>>>> EJERCICIO IMPORTANTE !!!!!!! <<<<<-------------
// Desarrollar un algoritmo y codificarlo en C para :

//     · Crear y mostrar la lista simplemente enlazada con dos numeros enteros en cada
//     nodo(termina si num1 = num2 = -1)

//         · Mostrarla.

//     · Generar otra lista con el promedio de ambos números de cada nodo.

//     · Si la suma de los valores del nodo es mayor a 10,
//     Insertar antes el triple de cada número del nodo

//     · Si suma de los dos números del nodo es menor a 30 eliminar dichos nodos.

//     Ejemplo

//     Ingreso :

//     10 5 20 10 7 2 30 10 4 2 10 3 6 5 5 3 60 30

//     Lista generada

//     7 15 3 20 3 6 5 4 45

//     Luego de insertar

//     30 15 10 5 60 30 20 10 7 2 90 30 30 10 4 2 30 9 10 3 18 15 6 5 5 3 180 90 60 30

//     Luego de Eliminar

//     30 15 60 30 20 10 90 30 30 10 30 9 18 15 180 90 60 30