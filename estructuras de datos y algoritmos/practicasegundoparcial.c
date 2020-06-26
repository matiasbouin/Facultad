// EL ULTIMO Y DESESPERADO INTENTO POR APROBAR


// EJERCICIOS PILAS Y COLAS

// EJERCICIOS ARBOLES

// MODELO DE PARCIAL 1

// Crear y Mostrar un árbol binario de búsqueda.
//  Escribir las funciones necesarias para calcular y luego mostrar:
// a) Buscar el mayor elemento del árbol divisor de la raíz
// b) Cantidad de nodos hojas impares.

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct arbol {
        int num;
        struct arbol *izq;
        struct arbol *der;
        }treenode;

void insertar (treenode **hoja, int elem)
{
    int numero = elem;
    if (elem == -1)
    {
        return;
    }
    if (*hoja == NULL)
    {
        (*hoja) = (treenode*)malloc(sizeof(treenode));
        (*hoja) -> num = elem;
        (*hoja) -> der = NULL;
        (*hoja) -> izq = NULL;
    }
    else
    {
        if (numero > (*hoja) -> num)
        {
            insertar (&(*hoja) -> der, elem);
        }
        else
        {
            insertar (&(*hoja) -> izq, elem);
        }
    }
    return;
}

void crear (treenode **hoja, int *raiz, int *mayorDiv)
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
        if (numero != 0 && *raiz % numero == 0 && numero > *mayorDiv)
        {
            *mayorDiv = numero;
        }
    }
}


void mostrar (treenode *hoja, int *cantHojasImpar)
{
    if (hoja != NULL)
    {
        mostrar(hoja -> izq, &(*cantHojasImpar));
        printf("%d ", hoja -> num);
        if (hoja -> num % 2 != 0 && hoja -> izq == NULL && hoja -> der == NULL) 
        {
            *cantHojasImpar = *cantHojasImpar + 1;
        }
        mostrar(hoja -> der, &(*cantHojasImpar));
    }
    return;
}

int main ()
{
    treenode* arbol=NULL;
    int raiz, mayorDiv = 0, cantHojasImpar = 0;
    crear(&arbol, &raiz, &mayorDiv);
    printf ("\nArbol:");
    mostrar (arbol, &cantHojasImpar);
    printf("\nRaiz: %d", raiz);
    printf("\nEl mayor divisor de la raiz es %d", mayorDiv);
    printf("\nLa cantidad de hojas impares es %d", cantHojasImpar);
    return 0;
}


// Crear una pila con la siguiente información:
//  num: numero entero.
//  siguiente: puntero al próximo elemento de la pila.
// Desarrollar una función que permita mostrar la sumatoria de números
// mayores al primer elemento ingresado en la pila. Si no hubiera ningún
// número mostrar una leyenda.

#include<stdio.h>
#include<stdlib.h>

typedef struct pila {
	    int num;
        struct pila *sig;
        }nodo;

nodo* crearNodo(int dato)
{
   nodo *nuevo = NULL;
   nuevo = (nodo*)malloc(sizeof(nodo));
   nuevo -> num = dato;
   nuevo -> sig = NULL;
   return nuevo;
}

void apilar(nodo** tope, nodo* nuevo, int *primero)
{
  	nuevo -> sig = *tope;
	if (*tope == NULL)
	{
	    *primero = nuevo -> num;
	}
	*tope = nuevo;
}

nodo desapilar(nodo** tope)
{
	nodo* aux;
    nodo datos;
	datos = **tope;
	aux = *tope;
	*tope = (*tope) -> sig;
	free(aux);
    return datos;
}

void mostrar (nodo aux, int *primerNodo, int *acum, int *cont)
{
    printf("%d \n", aux.num);
    if (aux.num > *primerNodo)
    {
        *acum = *acum + aux.num;
        *cont = *cont + 1;
    }
}

int main()
{
    int i, num, cant, primerNodo, sumMayoresPrim = 0, contMayores = 0;
    nodo *tope = NULL;
    printf("Cuantos datos quiere ingresar? ");
    scanf("%d", &cant);
    for (i = 0; i < cant; i++)
    {
   	    printf("\nIngrese un numero: ");
   	    scanf("%d",&num);
   	    apilar(&tope, crearNodo(num), &primerNodo);
    }
    printf("\nDesapilamos: \n");
    while(tope != NULL)
    {
        mostrar(desapilar(&tope), &primerNodo, &sumMayoresPrim, &contMayores);
    }
    printf("\nEl primer nodo es %d", primerNodo);
    if (contMayores > 0)
    {
        printf("\nLa sumatoria de los numeros mayores al primero es %d", sumMayoresPrim);
    }
    else
    {
        printf("\nNo hay valores mayores al primero ingresado");
    }
}

// Crear una cola con la siguiente información:
//  num: numero entero.
//  siguiente: puntero al próximo elemento de la cola.
// Desarrollar una función que permita mostrar el promedio de tres primeros
// números ingresados a la cola. Si no hubiese tres números, mostrar una leyenda y
// no calcular el promedio. 

#include<stdio.h>
#include<stdlib.h>

typedef struct cola {
        int num;
        struct tiponodo *sig;
        }nodo;

nodo* crearNodo (int dato)
{
   nodo *nuevo;
   nuevo = (nodo*)malloc(sizeof(nodo));
   nuevo -> num = dato;
   nuevo -> sig = NULL;
   return nuevo;
}

void acolar(nodo **prim ,nodo **anterior, nodo *nuevo)
{
	if(*prim == NULL)
	{
        *prim = *anterior = nuevo;
	}
    else
    {
        (*anterior) -> sig = nuevo;
    	(*anterior) = nuevo;
    }
}

nodo desacolar(nodo **inicio)
{
    nodo* aux;
    nodo datos;
	datos = **inicio;
	aux= *inicio;
	*inicio = (*inicio) -> sig;
	free(aux);
    return datos;
}

void mostrar (nodo aux, int *acum, int *cont)
{
  	int i;
  	printf("%d\n", aux.num);
  	if (*cont < 3)
  	{
  	    *acum = *acum + aux.num;
  	    *cont = *cont + 1;
  	}
}

int main()
{

    int i, num, cant, acumPrim = 0, cont = 0;
    nodo *prim = NULL, *ultNodo = NULL;
    printf("Cuantos datos quiere ingresar? ");
    scanf("%d", &cant);
    for(i = 0; i < cant; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &num);
        acolar(&prim, &ultNodo, crearNodo(num));
    }
    printf("\nDesacolar: \n");
	while(prim != NULL)
    {
        mostrar(desacolar(&prim), &acumPrim, &cont);
    }
    if (cant >= 3)
    {
        printf("\nEl promedio de los 3 primeros numeros es %d", acumPrim / 3);
    }
    else
    {
        printf("\nNo hay suficientes numeros para sacar el promedio.");
    }
    return 0;
}



// MODELO DE PARCIAL 2

// Crear y Mostrar un árbol binario de búsqueda.
//  Escribir las funciones necesarias para calcular y luego mostrar:
// a) Cantidad de los elementos pares con un hijo.
// b) Mínimo elemento impar del árbol. 
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct arbol {
        int num;
        struct arbol *izq;
        struct arbol *der;
        }treenode;

void insertar (treenode **hoja, int elem)
{
    int numero = elem;
    if (elem == -1)
    {
        return;
    }
    if (*hoja == NULL)
    {
        (*hoja) = (treenode*)malloc(sizeof(treenode));
        (*hoja) -> num = elem;
        (*hoja) -> der = NULL;
        (*hoja) -> izq = NULL;
    }
    else
    {
        if (numero > (*hoja) -> num)
        {
            insertar (&(*hoja) -> der, elem);
        }
        else
        {
            insertar (&(*hoja) -> izq, elem);
        }
    }
    return;
}

void crear (treenode **hoja, int *minImpar, int *p)
{
    int numero;
    printf("\nIngrese un numero: ");
    scanf("%d", &numero);
    while (numero != -1)
    {
        if (numero % 2 != 0 && p == NULL)
        {
            *minImpar = numero;
            p = &(*minImpar);
        }
        if (numero % 2 != 0 && p != NULL && numero < *minImpar)
        {
            *minImpar = numero;
        }
        insertar(&(*hoja), numero);
        printf("\nIngrese numero: ");
        scanf("%d", &numero);
    }
}


void mostrar (treenode *hoja, int *cantParesConHijo)
{
    if (hoja != NULL)
    {
        mostrar(hoja -> izq, &(*cantParesConHijo));
        printf("%d ", hoja -> num);
        if (hoja -> num % 2 == 0 && ((hoja -> izq == NULL && hoja -> der != NULL) || (hoja -> izq != NULL && hoja -> der == NULL)))
        {
            *cantParesConHijo = *cantParesConHijo + 1;
        }
        mostrar(hoja -> der, &(*cantParesConHijo));
    }
    return;
}

int main ()
{
    treenode* arbol=NULL;
    int cantParesConHijo = 0, minImpar, *p = NULL;
    crear(&arbol, &minImpar, p);
    printf ("\nArbol:");
    mostrar (arbol, &cantParesConHijo);
    printf("\nLa cantidad de nodos pares con un hijo es %d", cantParesConHijo);
    printf("\nEl minimo impar ingresado es %d", minImpar);
    return 0;
}
//15 9 20 6 14 17 64 13 26 72


// Crear una pila con la siguiente información:
//  num: numero entero.
//  siguiente: puntero al próximo elemento de la pila.
// Escribir la función necesaria para calcular la cantidad de elementos múltiplos del
// último número ingresado a la pila. Si no hubiera ningún número mostrar una
// leyenda
#include<stdio.h>
#include<stdlib.h>

typedef struct pila {
	    int num;
        struct pila *sig;
        }nodo;

nodo* crearNodo(int dato)
{
   nodo *nuevo = NULL;
   nuevo = (nodo*)malloc(sizeof(nodo));
   nuevo -> num = dato;
   nuevo -> sig = NULL;
   return nuevo;
}

void apilar(nodo** tope, nodo* nuevo)
{
  	nuevo -> sig = *tope;
	*tope = nuevo;
}

nodo desapilar(nodo** tope)
{
	nodo* aux;
    nodo datos;
	datos = **tope;
	aux = *tope;
	*tope = (*tope) -> sig;
	free(aux);
    return datos;
}

void mostrar (nodo aux, int *nroNodo, int *cant, int *ultIngresado, int *cont)
{
    printf("%d \n", aux.num);
    if (*nroNodo == *cant)
    {
        *ultIngresado = aux.num;
        *nroNodo = *nroNodo - 1;
    }
    else
    {
        if (aux.num % *ultIngresado == 0)
        {
            *cont = *cont + 1;
        }
    }
}

int main()
{
    int i, num, cant, nroNodo, cont = 0, ultIngresado;
    nodo *tope = NULL;
    printf("Cuantos datos quiere ingresar? ");
    scanf("%d", &cant);
    nroNodo = cant;
    for (i = 0; i < cant; i++)
    {
   	    printf("\nIngrese un numero: ");
   	    scanf("%d",&num);
   	    apilar(&tope, crearNodo(num));
    }
    printf("\nDesapilamos: \n");
    while(tope != NULL)
    {
        mostrar(desapilar(&tope), &nroNodo, &cant, &ultIngresado, &cont);
    }
    if (cont > 0)
    {
        printf("\nLa cantidad de multiplos del ultimo ingresado es %d", cont);
    }
    else
    {
        printf("\nNo hay multiplos del ultimo ingresado.");
    }
}

// Crear una cola con la siguiente información:
//  num: numero entero.
//  siguiente: puntero al próximo elemento de la cola.
//  Escribir una función para calcular el máximo elemento de la cola y en qué posición
// está.

#include<stdio.h>
#include<stdlib.h>

typedef struct cola {
        int num;
        struct tiponodo *sig;
        }nodo;

nodo* crearNodo (int dato)
{
   nodo *nuevo;
   nuevo = (nodo*)malloc(sizeof(nodo));
   nuevo -> num = dato;
   nuevo -> sig = NULL;
   return nuevo;
}

void acolar(nodo **prim ,nodo **anterior, nodo *nuevo)
{
	if(*prim == NULL)
	{
        *prim = *anterior = nuevo;
	}
    else
    {
        (*anterior) -> sig = nuevo;
    	(*anterior) = nuevo;
    }
}

nodo desacolar(nodo **inicio)
{
    nodo* aux;
    nodo datos;
	datos = **inicio;
	aux= *inicio;
	*inicio = (*inicio) -> sig;
	free(aux);
    return datos;
}

void mostrar (nodo aux, int *nroNodo, int *max, int *posic)
{
  	printf("%d\n", aux.num);
  	if (*nroNodo == 1)
  	{
  	    *max = aux.num;
  	    *posic = *nroNodo;
  	}
  	else
  	{
  	    if (aux.num > *max)
  	    {
  	        *max = aux.num;
  	        *posic = *nroNodo;
  	    }
  	}
  	*nroNodo = *nroNodo + 1;
}

int main()
{

    int i, num, cant, max, posic;
    nodo *prim = NULL, *ultNodo = NULL;
    printf("Cuantos datos quiere ingresar? ");
    scanf("%d", &cant);
    for(i = 0; i < cant; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &num);
        acolar(&prim, &ultNodo, crearNodo(num));
    }
    printf("\nDesacolar: \n");
	cant = 1;
	while(prim != NULL)
    {
        mostrar(desacolar(&prim), &cant, &max, &posic);
    }
    printf("\nEl maximo de la cola es %d en la posicion %d", max, posic);
    return 0;
}