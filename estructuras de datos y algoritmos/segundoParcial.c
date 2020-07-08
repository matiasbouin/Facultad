// Crear y Mostrar un árbol binario de búsqueda.
//  Escribir las funciones necesarias para calcular y luego mostrar;
// a)   Buscar el menor elemento del árbol divisor par de la raíz
// b)  Cantidad de nodos hojas impares.
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct arbol
{
    int num;
    struct arbol *izq;
    struct arbol *der;
} treenode;

void insertar(treenode **hoja, int elemento)
{
    int numero = elemento;
    if (elemento == -1)
    {
        return;
    }
    if (*hoja == NULL)
    {
        (*hoja) = (treenode *)malloc(sizeof(treenode));
        (*hoja)->num = elemento;
        (*hoja)->der = NULL;
        (*hoja)->izq = NULL;
    }
    else
    {
        if (numero > (*hoja)->num)
        {
            insertar(&(*hoja)->der, elemento);
        }
        else
        {
            insertar(&(*hoja)->izq, elemento);
        }
    }
    return;
}

void crear(treenode **hoja, int *raiz, int *menorDiv)
{
    int numero;
    printf("\nIngrese un numero: ");
    scanf("%d", &numero);
    *raiz = numero;
    if (numero % 2 == 0)
    {
        *menorDiv == numero;
    }
    while (numero != -1)
    {
        insertar(&(*hoja), numero);
        printf("\nIngrese numero: ");
        scanf("%d", &numero);
        if (numero != 0 && *raiz % numero == 0 && numero < *menorDiv && numero % 2 == 0)
        {
            *menorDiv = numero;
        }
    }
}

void mostrar(treenode *hoja, int *cantHojasImpar)
{
    if (hoja != NULL)
    {
        mostrar(hoja->izq, &(*cantHojasImpar));
        printf("%d ", hoja->num);
        if (hoja->num % 2 != 0 && hoja->izq == NULL && hoja->der == NULL)
        {
            *cantHojasImpar = *cantHojasImpar + 1;
        }
        mostrar(hoja->der, &(*cantHojasImpar));
    }
    return;
}

int main()
{
    treenode *arbol = NULL;
    int raiz, menorDiv, cantHojasImpar = 0;
    crear(&arbol, &raiz, &menorDiv);
    printf("\nArbol:");
    mostrar(arbol, &cantHojasImpar);
    printf("\nRaiz: %d", raiz);
    printf("\nEl menor elemento divisor par de la raiz es %d", menorDiv);
    printf("\nLa cantidad de hojas impares es %d", cantHojasImpar);
    return 0;
}

// Crear una pila con la siguiente información:
//            num: numero entero.
//            siguiente: puntero al próximo elemento de la pila.
// El ingreso de datos termina con -1.
// Escribir una función que permita calcular la sumatoria de números múltiplos del primer elemento ingresado en la pila. Si no hubiera ningún número mostrar una leyenda.

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

void apilar(nodo **tope, nodo *nuevo, int *primero)
{
    nuevo->sig = *tope;
    if (*tope == NULL)
    {
        *primero = nuevo->num;
    }
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

void mostrar(nodo aux, int *primerNodo, int *acum, int *cont)
{
    printf("%d \n", aux.num);
    if (aux.num % *primerNodo == 0)
    {
        *acum = *acum + aux.num;
        *cont = *cont + 1;
    }
}

int main()
{
    int i, num, cant, primerNodo, sumaMultiplosPrim = 0, contMultiplos = 0;
    nodo *tope = NULL;
    printf("Cuantos datos quiere ingresar? ");
    scanf("%d", &cant);
    for (i = 0; i < cant; i++)
    {
        printf("\nIngrese un numero: ");
        scanf("%d", &num);
        apilar(&tope, crearNodo(num), &primerNodo);
    }
    printf("\nDesapilamos: \n");
    while (tope != NULL)
    {
        mostrar(desapilar(&tope), &primerNodo, &sumaMultiplosPrim, &contMultiplos);
    }
    printf("\nEl primer nodo es %d", primerNodo);
    if (contMultiplos > 0)
    {
        printf("\nLa sumatoria de números múltiplos del primer elemento ingresado en la pila es %d", sumaMultiplosPrim);
    }
    else
    {
        printf("\nNo hay números múltiplos del primer elemento ingresado en la pila");
    }
}

// Crear una cola con la siguiente información:
//            num: numero entero.
//            siguiente: puntero al próximo elemento de la cola.
// El ingreso de datos termina con -1.
// Escribir una función que permita calcular la sumatoria de los números menores al último elemento ingresado en la cola. Si no hubiera ningún número, mostrar una leyenda.

#include <stdio.h>
#include <stdlib.h>

typedef struct numeros
{
    int num;
    struct numeros *sig;
} nodo;

nodo *crearNodo(int numero)
{
    nodo *nuevo = NULL;
    nuevo = (nodo *)malloc(sizeof(nodo));
    nuevo->num = numero;
    nuevo->sig = NULL;
    return nuevo;
}

void encolar(nodo **prim, nodo **anterior, nodo *nuevo)
{
    if (*prim == NULL)
    {
        *prim = *anterior = nuevo;
    }
    else
    {
        (*anterior)->sig = nuevo;
        (*anterior) = nuevo;
    }
}

nodo desencolar(nodo **head)
{
    nodo *aux = NULL;
    nodo dato;
    dato = **head;
    aux = *head;
    (*head) = (*head)->sig;
    free(aux);
    return dato;
}

void mostrar(nodo dato, int ultimo, int *sumatoria)
{
    printf("%d\n", dato.num);

    if (dato.num < ultimo)
    {
        *sumatoria = *sumatoria + dato.num; // ???????
    }
}

int main()
{
    nodo *comienzo = NULL, *apunt = NULL;
    int cant, i, num, contador = 0, ultimo, sumatoria = 0;

    printf("Cantidad de elementos a ingresar: ");
    scanf("%d", &cant);

    for (i = 0; i < cant; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &num);
        contador += 1;
        if (contador == cant)
        {
            ultimo = num;
            printf("TU ULTIMO NUMERO ES: %d\n", ultimo);
        }

        encolar(&comienzo, &apunt, crearNodo(num));
    }

    while (comienzo != NULL)
    {
        mostrar(desencolar(&comienzo), ultimo, &sumatoria);
    }

    if (sumatoria = !0)
    {
        printf("La sumatoria de los números menores al último elemento ingresado en la cola es: %d\n", sumatoria);
    }
    else
    {
        printf("Leyenda");
    }
}

//ENCONTRAR LOS 2 NUMEROS MAS CHICOS DE LA PILA

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

void mostrar(nodo aux, int *primero, int *segundo, int *contador)
{
    int i, auxiliar;

    printf("%d \n", aux.num);

    //Extraigo 2 primeros valores
    if (*contador == 0)
    {
        *primero = aux.num;
    }
    else if (*contador == 1)
    {
        *segundo = aux.num;
    }

    *contador += 1;

    //Solo busca otros valores si hay más de 2 elementos en la pila
    if (*contador > 2)
    {
        //Ordeno valores para que el proximo if siempre sea valido
        if (*segundo < *primero)
        {
            auxiliar = *primero;
            *primero = *segundo;
            *segundo = auxiliar;
        }

        //Comparo con el valor mas chico siempre
        if (aux.num < *primero)
        {
            *segundo = *primero;
            *primero = aux.num;
        }
    }
}

int main()
{
    int i, num, cant, primero, segundo, contador = 0; //Primer numero chico, segundo numero chico
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
        mostrar(desapilar(&tope), &primero, &segundo, &contador);
        // printf("El primero parcial es: %d\n", primero); // Descomentar para checkear resultado
        // printf("El segundo parcial es: %d\n", segundo);
    }

    printf("El primero definitivo es: %d\n", primero);
    printf("El segundo definitivo es: %d\n", segundo);
}