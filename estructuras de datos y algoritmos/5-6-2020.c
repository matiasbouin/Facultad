// DOBLE INDIRECCION O INDIRECCION MULTIPLE
//DOBLE PUNTERO **Puntero Guarda dirección de otro puntero
//PILA: estructura dinamica (No tengo que reservar memoria) (Lo trabajamos en recursión) (Los datos se pierden al mostrarla)
//LO IMPORTANTE: sacar estadisticas de la pila ej: Cuantos elementos pares hay en la pila? usar funcion mostrar
//COLA: La eliminacion es por cabeza de lista y la actualizacion es por final de lista. Si quisiera saber el ultimo elemento de una cola, debo eliminar los anteriores
//2do PARCIAL: ej, pila ej cola y ej arboles (No se toma archivos y multilistas) -> FINAL
// #define cantidad 4 //Declaración de variable global


//PILA
// #include <stdio.h>
// #include <stdlib.h>

// typedef struct pila
// {
//     int num;
//     struct pila *sig;
// } nodo;

// nodo *crearNodo(int dato)
// {
//     nodo *nuevo = NULL;
//     nuevo = (nodo *)malloc(sizeof(nodo));
//     nuevo->num = dato;
//     nuevo->sig = NULL;
//     return nuevo;
// }

// void apilar(nodo **tope, nodo *nuevo)
// {
//     nuevo->sig = *tope;
//     *tope = nuevo;
// }

// nodo desapilar(nodo **tope)
// {
//     nodo *aux;
//     nodo datos;
//     datos = **tope;
//     aux = *tope;
//     *tope = (*tope)->sig;
//     free(aux);
//     return datos;
// }

// void mostrar(nodo aux) 
// {
//     printf("%d \n", aux.num);
// }

// int main()
// {
//     int i, num, cant;
//     nodo *tope = NULL;
//     printf("Cuantos datos quiere ingresar? ");
//     scanf("%d", &cant);
//     for (i = 0; i < cant; i++)
//     {
//         printf("\nIngrese un numero: ");
//         scanf("%d", &num);
//         apilar(&tope, crearNodo(num));
//     }
//     printf("\nDesapilamos: \n");
//     while (tope != NULL)
//     {
//         mostrar(desapilar(&tope));
//     }
// }


//MOSTRAR NUMEROS PARES INGRESADOS EN LA PILA
// #include <stdio.h>
// #include <stdlib.h>

// typedef struct pila
// {
//     int num;
//     struct pila *sig;
// } nodo;

// nodo *crearNodo(int dato)
// {
//     nodo *nuevo = NULL;
//     nuevo = (nodo *)malloc(sizeof(nodo));
//     nuevo->num = dato;
//     nuevo->sig = NULL;
//     return nuevo;
// }

// void apilar(nodo **tope, nodo *nuevo)
// {
//     nuevo->sig = *tope;
//     *tope = nuevo;
// }

// nodo desapilar(nodo **tope)
// {
//     nodo *aux;
//     nodo datos;
//     datos = **tope;
//     aux = *tope;
//     *tope = (*tope)->sig;
//     free(aux);
//     return datos;
// }

// void mostrar(nodo aux, int *contador) 
// {
//     printf("%d \n", aux.num);
//     if (aux.num%2 == 0)
//     {
//         *contador += 1;
//     }
// }

// int main()
// {
//     int i, num, cant, contador = 0;
//     nodo *tope = NULL;
    
//     printf("Cuantos datos quiere ingresar? ");
//     scanf("%d", &cant);

//     for (i = 0; i < cant; i++)
//     {
//         printf("\nIngrese un numero: ");
//         scanf("%d", &num);
//         apilar(&tope, crearNodo(num));
//     }
//     printf("\nDesapilamos: \n");
//     while (tope != NULL)
//     {
//         mostrar(desapilar(&tope), &contador);
//     }

//     printf("\nLa cantidad de numeros pares es: %d \n", contador);
// }


//VALOR MAXIMO INGRESADO EN LA PILA
// #include <stdio.h>
// #include <stdlib.h>

// typedef struct pila
// {
//     int num;
//     struct pila *sig;
// } nodo;

// nodo *crearNodo(int dato)
// {
//     nodo *nuevo = NULL;
//     nuevo = (nodo *)malloc(sizeof(nodo));
//     nuevo->num = dato;
//     nuevo->sig = NULL;
//     return nuevo;
// }

// void apilar(nodo **tope, nodo *nuevo)
// {
//     nuevo->sig = *tope;
//     *tope = nuevo;
// }

// nodo desapilar(nodo **tope)
// {
//     nodo *aux;
//     nodo datos;
//     datos = **tope;
//     aux = *tope;
//     *tope = (*tope)->sig;
//     free(aux);
//     return datos;
// }

// void mostrar(nodo aux, int *maximo) 
// {
//     printf("%d \n", aux.num);
//     if (aux.num > *maximo)
//     {
//         *maximo = aux.num;
//     }
// }

// int main()
// {
//     int i, num, cant, maximo = 0;
//     nodo *tope = NULL;

//     printf("Cuantos datos quiere ingresar? ");
//     scanf("%d", &cant);

//     for (i = 0; i < cant; i++)
//     {
//         printf("\nIngrese un numero: ");
//         scanf("%d", &num);
//         apilar(&tope, crearNodo(num));
//     }
//     printf("\nDesapilamos: \n");
//     while (tope != NULL)
//     {
//         mostrar(desapilar(&tope), &maximo);
//     }
    
//     printf("El valor máximo ingresado es: %d\n", maximo);
// }

//Posibles ejercicios: Cual es el elemento en x posicion? (Contador descendente en mostrar si contador == x => guardar en puntero)
//Posibles ejercicios: Cuantos elementos fueron mayores al ultimo ingresado a la pila? (?)


//COLAS
//La eliminacion es por de cabeza lista y la insercion es por final de lista (Puntero al final y puntero al principio)
// #include <stdio.h>
// #include <stdlib.h>

// typedef struct numeros {
//         int num;
//         struct numeros *sig;
//         } nodo;

// nodo* crearNodo (int numero)
// {
//     nodo *nuevo = NULL;
//     nuevo = (nodo*)malloc(sizeof(nodo));
//     nuevo -> num = numero;
//     nuevo -> sig = NULL;
//     return nuevo;
// }

// void encolar (nodo **prim, nodo **anterior, nodo *nuevo)
// {
//     if (*prim == NULL)
//     {
//         *prim = *anterior = nuevo;
//     }
//     else
//     {
//         (*anterior) -> sig = nuevo;
//         (*anterior) = nuevo;
//     }
// }

// nodo desencolar (nodo** head)
// {
//     nodo *aux = NULL;
//     nodo dato;
//     dato = **head;
//     aux = *head;
//     (*head) = (*head) -> sig;
//     free(aux);
//     return dato;
// }

// void mostrar (nodo dato)
// {
//     printf("%d\n", dato.num);
// }

// int main()
// {
//     nodo *comienzo = NULL, *apunt = NULL;
//     int cant, i, num;
//     printf("Ingrese cantidad de numeros a ingresar: ");
//     scanf("%d", &cant);
//     for (i = 0; i < cant; i++)
//     {
//         printf("Ingrese un numero: ");
//         scanf("%d", &num);
//         encolar(&comienzo, &apunt, crearNodo(num));
//     }
//     while (comienzo != NULL)
//     {
//         mostrar(desencolar(&comienzo));
//     }
// }


//ARBOLES BINARIOS
// #include <stdio.h>
// #include <conio.h>
// #include <stdlib.h>

// typedef struct arbol {
//         int num;
//         struct arbol *izq;
//         struct arbol *der;
//         }treenode;

// void insertar (treenode **hoja, int elem)
// {
//     int numero = elem;
//     if (elem == -1)
//     {
//         return;
//     }
//     if (*hoja == NULL)
//     {
//         (*hoja) = (treenode*)malloc(sizeof(treenode));
//         (*hoja) -> num = elem;
//         (*hoja) -> der = NULL;
//         (*hoja) -> izq = NULL;
//     }
//     else
//     {
//         if (numero > (*hoja) -> num)
//         {
//             insertar (&(*hoja) -> der, elem);
//         }
//         else
//         {
//             insertar (&(*hoja) -> izq, elem);
//         }
//     }
//     return;
// }

// void crear (treenode **hoja)
// {
//     int numero;
//     printf("\nIngrese un numero: ");
//     scanf("%d", &numero);
//     while (numero != -1)
//     {
//         insertar(&(*hoja), numero);
//         printf("\nIngrese numero: ");
//         scanf("%d", &numero);
//     }
// }


// void mostrar (treenode *hoja) //EN ORDEN
// {
//     if (hoja != NULL)
//     {
//         mostrar(hoja -> izq);
//         printf("%d ", hoja -> num);
//         mostrar(hoja -> der);
//     }
//     return;
// }

// int main ()
// {
//     treenode* arbol=NULL;

//     crear(&arbol);

//     printf ("\nArbol:");
//     mostrar (arbol);

//     return 0;
// }

//MOSTRAR CANTIDAD DE NODOS HOJAS
// #include <stdio.h>
// #include <conio.h>
// #include <stdlib.h>

// typedef struct arbol {
//         int num;
//         struct arbol *izq;
//         struct arbol *der;
//         }treenode;

// void insertar (treenode **hoja, int elem)
// {
//     int numero = elem;
//     if (elem == -1)
//     {
//         return;
//     }
//     if (*hoja == NULL)
//     {
//         (*hoja) = (treenode*)malloc(sizeof(treenode));
//         (*hoja) -> num = elem;
//         (*hoja) -> der = NULL;
//         (*hoja) -> izq = NULL;
//     }
//     else
//     {
//         if (numero > (*hoja) -> num)
//         {
//             insertar (&(*hoja) -> der, elem);
//         }
//         else
//         {
//             insertar (&(*hoja) -> izq, elem);
//         }
//     }
//     return;
// }

// void crear (treenode **hoja)
// {
//     int numero;
//     printf("\nIngrese un numero: ");
//     scanf("%d", &numero);
//     while (numero != -1)
//     {
//         insertar(&(*hoja), numero);
//         printf("\nIngrese numero: ");
//         scanf("%d", &numero);
//     }
// }


// void mostrar (treenode *hoja, int *contador) //EN ORDEN
// {
//     if (hoja != NULL)
//     {
//         mostrar(hoja -> izq, contador);
//         printf("%d ", hoja -> num);
//         //Logica ejercicio
//         if (hoja->izq==NULL && hoja->der == NULL)
//         {
//             *contador += 1;
//         }

//         mostrar(hoja -> der, contador);
//     }
//     return;
// }

// int main ()
// {
//     int contador = 0;
//     treenode* arbol=NULL;

//     crear(&arbol);

//     printf ("\nArbol:");
//     mostrar (arbol, &contador);

//     printf("La cantidad de nodo hojas son: %d\n", contador);
//     return 0;
// }


//CUALES DE LOS NODOS HOJAS SON PARES
// #include <stdio.h>
// #include <conio.h>
// #include <stdlib.h>

// typedef struct arbol {
//         int num;
//         struct arbol *izq;
//         struct arbol *der;
//         }treenode;

// void insertar (treenode **hoja, int elem)
// {
//     int numero = elem;
//     if (elem == -1)
//     {
//         return;
//     }
//     if (*hoja == NULL)
//     {
//         (*hoja) = (treenode*)malloc(sizeof(treenode));
//         (*hoja) -> num = elem;
//         (*hoja) -> der = NULL;
//         (*hoja) -> izq = NULL;
//     }
//     else
//     {
//         if (numero > (*hoja) -> num)
//         {
//             insertar (&(*hoja) -> der, elem);
//         }
//         else
//         {
//             insertar (&(*hoja) -> izq, elem);
//         }
//     }
//     return;
// }

// void crear (treenode **hoja)
// {
//     int numero;
//     printf("\nIngrese un numero: ");
//     scanf("%d", &numero);
//     while (numero != -1)
//     {
//         insertar(&(*hoja), numero);
//         printf("\nIngrese numero: ");
//         scanf("%d", &numero);
//     }
// }


// void mostrar (treenode *hoja, int *contador) //EN ORDEN
// {
//     if (hoja != NULL)
//     {
//         mostrar(hoja -> izq, contador);
//         printf("%d ", hoja -> num);
//         //Logica ejercicio
//         if (hoja->izq==NULL && hoja->der == NULL && hoja->num %2 == 0)
//         {
//             *contador += 1;
//         }

//         mostrar(hoja -> der, contador);
//     }
//     return;
// }

// int main ()
// {
//     int contador = 0;
//     treenode* arbol=NULL;

//     crear(&arbol);

//     printf ("\nArbol:");
//     mostrar (arbol, &contador);

//     printf("La cantidad de nodo hojas pares son: %d\n", contador);
//     return 0;
// }


//ELEMENTO MAXIMO DEL ARBOL
// #include <stdio.h>
// #include <conio.h>
// #include <stdlib.h>

// typedef struct arbol {
//         int num;
//         struct arbol *izq;
//         struct arbol *der;
//         }treenode;

// void insertar (treenode **hoja, int elem)
// {
//     int numero = elem;
//     if (elem == -1)
//     {
//         return;
//     }
//     if (*hoja == NULL)
//     {
//         (*hoja) = (treenode*)malloc(sizeof(treenode));
//         (*hoja) -> num = elem;
//         (*hoja) -> der = NULL;
//         (*hoja) -> izq = NULL;
//     }
//     else
//     {
//         if (numero > (*hoja) -> num)
//         {
//             insertar (&(*hoja) -> der, elem);
//         }
//         else
//         {
//             insertar (&(*hoja) -> izq, elem);
//         }
//     }
//     return;
// }

// void crear (treenode **hoja, int *maximo)
// {
//     int numero;
//     printf("\nIngrese un numero: ");
//     scanf("%d", &numero);
//     *maximo = numero;
//     while (numero != -1)
//     {
//         insertar(&(*hoja), numero);
//         printf("\nIngrese numero: ");
//         scanf("%d", &numero);
//     }
// }


// void mostrar (treenode *hoja, int *contador, int *maximo) //EN ORDEN
// {
//     if (hoja != NULL)
//     {
//         mostrar(hoja -> izq, contador, maximo);
//         printf("%d ", hoja -> num);
//         //Logica ejercicio
//         if (hoja->izq==NULL && hoja->der == NULL)
//         {
//             *contador += 1;
//         }

//         if (hoja->num > *maximo)
//         {
//             *maximo = hoja->num;
//         }

//         mostrar(hoja -> der, contador, maximo);
//     }
//     return;
// }

// int main ()
// {
//     int contador = 0, maximo;
//     treenode* arbol=NULL;

//     crear(&arbol, &maximo);

//     printf ("\nArbol:");
//     mostrar (arbol, &contador, &maximo);

//     printf("La cantidad de nodo hojas son: %d\n", contador);
//     printf("El máximo es: %d\n", maximo);

//     return 0;
// }

//COMPARACION CON LA RAIZ DEL ARBOL
//Numeros mayores que la raiz
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

void crear (treenode **hoja, int *raiz)
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


void mostrar (treenode *hoja, int *contador, int raiz, int *contadorRaiz) //EN ORDEN
{
    if (hoja != NULL)
    {
        mostrar(hoja -> izq, contador, raiz, contadorRaiz);
        printf("%d ", hoja -> num);
        //Logica ejercicio
        if (hoja->izq==NULL && hoja->der == NULL)
        {
            *contador += 1;
        }

        if (hoja->num > raiz)
        {
            *contadorRaiz += 1;
        }

        mostrar(hoja -> der, contador, raiz, contadorRaiz);
    }
    return;
}

int main ()
{
    int contador = 0, raiz, contadorRaiz = 0;
    treenode* arbol=NULL;

    crear(&arbol, &raiz);

    printf ("\nArbol:");
    mostrar (arbol, &contador, raiz, &contadorRaiz);

    printf("La cantidad de nodo hojas son: %d\n", contador);
    printf("La raiz es: %d\n", raiz);
    printf("La cantidad de numeros mayores a la raiz son: %d\n", contadorRaiz);

    return 0;
}

//CODIGO PARA SUMATORIA NUMEROS MAYORES A RAIZ EN CLASE TIEMPO 1:00 APROX