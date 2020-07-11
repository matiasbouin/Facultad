/*Dada la siguiente estructura:
 typedef struct lista {
 int num;
 struct lista * sig;
 } nodo;
a) Cargar una lista con números ordenados de menor a mayor y con dos consecutivos cada
tanto. La carga termina con número = 1000.
b) Agregar el tercero consecutivo.
c) De dos consecutivos, eliminar el primero.
d) De dos consecutivos, eliminar el segundo.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int num;
    struct list *next;
} nodo;

void create(nodo *reg)
{
    printf("Enter a number: ");
    scanf("%d", &reg->num);
    if (reg->num != 1000)
    {
        reg->next = (nodo *)malloc(sizeof(nodo));
        create(reg->next);
    }
    else
    {
        reg->next = NULL;
    }
}

void show(nodo *reg)
{
    if (reg->next != NULL)
    {
        printf("\n%d", reg->num);
        show(reg->next);
    }
}

nodo *insert(nodo *reg)
{
    nodo *aux = NULL;
    while (reg->next != NULL)
    {
        if (reg->num == (reg->next->num) - 1)
        {
            aux = (nodo *)malloc(sizeof(nodo));
            aux->num = (reg->next->num) + 1;
            aux->next = reg->next->next;
            reg->next->next = aux;
            reg = reg->next->next->next;
        }
        else
        {
            reg = reg->next;
        }
    }
    return reg;
}

nodo *eraseFirst(nodo *reg)
{
    nodo *aux = NULL;
    while (reg->next != NULL && reg->next->next != NULL)
    {
        if (reg->next->num == (reg->next->next->num) - 1)
        {
            aux = reg->next->next;
            free(reg->next);
            reg->next = aux;
        }
        reg = reg->next;
    }
    return reg;
}

nodo *eraseFirstHead(nodo *reg)
{
    nodo *aux = NULL;
    if (reg->num == (reg->next->num) - 1)
    {
        aux = reg->next;
        free(reg);
        reg = aux;
    }
    return reg;
}

nodo *eraseSecond(nodo *reg)
{
    nodo *aux = NULL;
    while (reg->next != NULL && reg->next->next != NULL)
    {
        if (reg->num == (reg->next->num) - 1)
        {
            aux = reg->next->next;
            free(reg->next);
            reg->next = aux;
        }
        reg = reg->next;
    }
    return reg;
}

int main()
{
    nodo *head = NULL;
    head = (nodo *)malloc(sizeof(nodo));
    create(head);
    printf("\n\n****Original list****");
    show(head);
    insert(head);
    printf("\n\n****Insertions****");
    show(head);
    head = eraseFirstHead(head);
    eraseFirst(head);
    printf("\n\n****First numbers erased****");
    show(head);
    eraseSecond(head);
    printf("\n\n****Second numbers erased****");
    show(head);
}

/*Desarrollar un procedimiento que permita borrar una lista completa (deberá ser lo más
rápido posible).*/

#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int num;
    struct lista *sig;
} nodo;

void crear(nodo *registro)
{
    scanf("%d", &registro->num);
    if (registro->num != 0)
    {
        registro->sig = (nodo *)malloc(sizeof(nodo));
        crear(registro->sig);
    }
    else
    {
        registro->sig = NULL;
    }
}

void mostrar(nodo *registro)
{
    if (registro->sig != NULL)
    {
        printf("\n%d", registro->num);
        mostrar(registro->sig);
    }
    else
    {
        return;
    }
}

nodo *eliminar(nodo *registro)
{
    nodo *aux = NULL;
    if (registro->sig != NULL && registro->sig->sig != NULL)
    {
        aux = registro->sig->sig;
        free(registro->sig);
        registro->sig = aux;
        eliminar(registro);
    }
    else
    {
        if (registro->sig != NULL && registro->sig->sig == NULL)
        {
            free(registro->sig);
            registro->sig = NULL;
        }
        else
        {
            if (registro->sig == NULL)
            {
                free(registro);
            }
        }
    }
    return registro;
}

nodo *eliminarCabeza(nodo *registro)
{
}

int main()
{
    nodo *head = NULL;
    head = (nodo *)malloc(sizeof(nodo));
    crear(head);
    mostrar(head);
    printf("\n\nLista eliminada");
    eliminar(head);
    mostrar(head);
}

/*Desarrollar un procedimiento para invertir una lista lineal, es decir, cambiar sus enlaces
para que aparezcan en orden inverso.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int num;
    struct lista *sig;
} nodo;

void crear(nodo *registro)
{
    scanf("%d", &registro->num);
    if (registro->num != 0)
    {
        registro->sig = (nodo *)malloc(sizeof(nodo));
        crear(registro->sig);
    }
    else
    {
        registro->sig = NULL;
    }
}

void mostrar(nodo *registro)
{
    if (registro->sig != NULL)
    {
        printf("\n%d", registro->num);
        mostrar(registro->sig);
    }
    else
    {
        printf("\n%d", registro->num);
    }
}

nodo *generarInversa(nodo *orig, nodo *nuevo)
{
    nodo *aux = orig;
    if (orig->sig != NULL)
    {
        while (aux->sig->sig != NULL)
        {
            aux = aux->sig;
        }
        if (aux->sig->sig == NULL)
        {
            nuevo->num = aux->sig->num;
            nuevo->sig = (nodo *)malloc(sizeof(nodo));
            free(aux->sig);
            aux->sig = NULL;
            generarInversa(orig, nuevo->sig);
        }
    }
    else
    {
        nuevo->num = orig->num;
        nuevo->sig = NULL;
        free(aux);
    }
    return nuevo;
}

int main()
{
    nodo *head = NULL, *new = NULL;
    head = (nodo *)malloc(sizeof(nodo));
    crear(head);
    printf("\n\n");
    mostrar(head);
    new = (nodo *)malloc(sizeof(nodo));
    generarInversa(head, new);
    printf("\n\n");
    mostrar(new);
}

/* Desarrollar un procedimiento que, dado un número M, elimine:
a) el elemento M-ésimo de la lista.
b) Todos los elementos menores a M.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int num;
    struct lista *sig;
} nodo;

void crear(nodo *registro)
{
    scanf("%d", &registro->num);
    if (registro->num != 0)
    {
        registro->sig = (nodo *)malloc(sizeof(nodo));
        crear(registro->sig);
    }
    else
    {
        registro->sig = NULL;
    }
}

void mostrar(nodo *registro)
{
    if (registro->sig != NULL)
    {
        printf("\n%d", registro->num);
        mostrar(registro->sig);
    }
    else
    {
        printf("\n%d", registro->num);
    }
}

nodo *eliminar(nodo *registro, int num)
{
    nodo *aux = NULL;
    int cont = 2;
    if (registro->sig != NULL && registro->sig->sig != NULL)
    {
        while (cont < num)
        {
            registro = registro->sig;
            cont++;
        }
        aux = registro->sig->sig;
        free(registro->sig);
        registro->sig = aux;
    }
    else
    {
        if (registro->sig != NULL && registro->sig->sig == NULL)
        {
            if (cont == num || num == 2)
            {
                free(registro->sig);
                registro->sig = NULL;
            }
        }
    }
    return registro;
}

nodo *eliminarCabeza(nodo *registro, int num)
{
    nodo *aux = NULL;
    if (num == 1)
    {
        if (registro->sig != NULL)
        {
            aux = registro->sig;
            free(registro);
            registro = aux;
        }
        else
        {
            free(registro);
            registro = NULL;
        }
    }
    return registro;
}

nodo *eliminarMenor(nodo *registro, int num)
{
    nodo *aux = NULL;
    if (registro->sig != NULL && registro->sig->sig != NULL)
    {
        if (registro->sig->num < num)
        {
            aux = registro->sig->sig;
            free(registro->sig);
            registro->sig = aux;
            eliminarMenor(registro, num);
        }
        else
        {
            eliminarMenor(registro->sig, num);
        }
    }
    if (registro->sig->sig == NULL && registro->sig->num < num)
    {
        free(registro->sig);
        registro->sig = NULL;
    }
}

nodo *eliminarMenorCabeza(nodo *registro, int num)
{
    nodo *aux = NULL;
    if (registro->num < num)
    {
        if (registro->sig != NULL)
        {
            aux = registro->sig;
            free(registro);
            registro = aux;
        }
        else
        {
            free(registro);
            registro = NULL;
        }
    }
    return registro;
}

int main()
{
    nodo *head = NULL;
    int a;
    head = (nodo *)malloc(sizeof(nodo));
    crear(head);
    mostrar(head);
    printf("\nIngrese un numero: ");
    scanf("%d", &a);
    eliminar(head, a);
    head = eliminarCabeza(head, a);
    printf("\n\nEliminacion nodo ");
    if (head != NULL)
    {
        mostrar(head);
        eliminarMenor(head, a);
        //eliminarMenorCabeza(head, a);
        printf("\n\nEliminacion menores ");
        mostrar(head);
    }
}

/*
Dada la siguiente información de los distintos vuelos en Aeroparque, 
crear una lista simplemente enlazada con:
 *Número de vuelo
 *Cantidad de asientos del avíon
 *Cantidad de asientos vendidos
La carga finaliza con el número de vuelo igual a 0.
a) Generar una nueva lista con el número de vuelo y su porcentaje de ocupación.
b) Eliminar aquellos vuelos que tengan una ocupación menor al 10% de la lista original. 
c) Insertar un vuelo más sumándole uno al número de vuelo para aquellos vuelos que estén 
completos con la misma cantidad de asientos y 0 en cantidad de asientos vendidos 
luego de la eliminación.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int vuelo;
    int asientos;
    int ventas;
    struct lista *sig;
} nodo;

typedef struct lista2
{
    int vuelo;
    int ocupacion;
    struct lista2 *sig;
} nodo2;

void crear(nodo *registro)
{
    printf("Ingrese numero de vuelo: ");
    scanf("%d", &registro->vuelo);
    if (registro->vuelo > 0)
    {
        printf("Ingrese cantidad de asientos: ");
        scanf("%d", &registro->asientos);
        printf("Ingrese asientos vendidos: ");
        scanf("%d", &registro->ventas);
        registro->sig = (nodo *)malloc(sizeof(nodo));
        crear(registro->sig);
    }
    else
    {
        registro->sig = NULL;
    }
}

void mostrar(nodo *registro)
{
    if (registro->sig != NULL)
    {
        printf("\nNumero de vuelo: %d", registro->vuelo);
        printf("\nCantidad de asientos: %d", registro->asientos);
        printf("\nAsientos vendidos: %d", registro->ventas);
        mostrar(registro->sig);
    }
}

void generar(nodo *orig, nodo2 *nuevo)
{
    if (orig->sig != NULL)
    {
        nuevo->vuelo = orig->vuelo;
        nuevo->ocupacion = orig->ventas * 100 / orig->asientos;
        nuevo->sig = (nodo2 *)malloc(sizeof(nodo2));
        generar(orig->sig, nuevo->sig);
    }
    else
    {
        nuevo->sig = NULL;
    }
}

void mostrar2(nodo2 *registro)
{
    if (registro->sig != NULL)
    {
        printf("\nVuelo: %d", registro->vuelo);
        printf("\nOcupacion: %d", registro->ocupacion);
        mostrar2(registro->sig);
    }
}

nodo *eliminar(nodo *registro)
{
    nodo *aux = NULL;
    while (registro->sig != NULL && registro->sig->sig != NULL)
    {
        if ((registro->sig->ventas * 100 / registro->sig->asientos) < 10)
        {
            aux = registro->sig->sig;
            free(registro->sig);
            registro->sig = aux;
        }
        else
        {
            registro = registro->sig;
        }
    }
    return registro;
}

nodo *eliminarCabeza(nodo *registro)
{
    nodo *aux = NULL;
    if (registro->sig != NULL && (registro->ventas * 100 / registro->asientos) < 10)
    {
        aux = registro->sig;
        free(registro);
        registro = aux;
    }
    return registro;
}

nodo *insertar(nodo *registro)
{
    nodo *aux = NULL;
    while (registro->sig != NULL)
    {
        if (registro->asientos == registro->ventas)
        {
            aux = (nodo *)malloc(sizeof(nodo));
            aux->vuelo = (registro->vuelo) + 1;
            aux->asientos = registro->asientos;
            aux->ventas = 0;
            aux->sig = registro->sig;
            registro->sig = aux;
        }
        registro = registro->sig;
    }
}

int main()
{
    nodo *head = NULL;
    nodo2 *new = NULL;
    head = (nodo *)malloc(sizeof(nodo));
    crear(head);
    printf("\n\nLista completa");
    mostrar(head);
    new = (nodo2 *)malloc(sizeof(nodo2));
    generar(head, new);
    printf("\n\nLista ocupacion");
    mostrar2(new);
    eliminar(head);
    head = eliminarCabeza(head);
    printf("\n\nLista con eliminaciones");
    mostrar(head);
    insertar(head);
    printf("\n\nLista con inserciones");
    mostrar(head);
}

/*
Estructura: numero, puntero.
a)	Crear y mostrar la lista con números enteros. Termina con num=-2.
b)	Insertar en otra lista los números impares. Mostrarla.
c)	Eliminar todos los valores menores al promedio de la lista original 
en la lista de números impares. Mostrarla
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int num;
    struct lista *sig;
} nodo;

void crear(nodo *registro)
{
    printf("Ingrese un numero: ");
    scanf("%d", &registro->num);
    if (registro->num != -2)
    {
        registro->sig = (nodo *)malloc(sizeof(nodo));
        crear(registro->sig);
    }
    else
    {
        registro->sig = NULL;
    }
}

void mostrar(nodo *registro)
{
    if (registro->sig != NULL)
    {
        printf("\n%d", registro->num);
        mostrar(registro->sig);
    }
}

void generar(nodo *orig, nodo *nuevo)
{
    while (orig->sig != NULL)
    {
        if (orig->num % 2 == 1 || orig->num % 2 == -1)
        {
            nuevo->num = orig->num;
            nuevo->sig = (nodo *)malloc(sizeof(nodo));
            orig = orig->sig;
            nuevo = nuevo->sig;
        }
        else
        {
            orig = orig->sig;
        }
    }
    nuevo->sig = NULL;
}

int promedio(nodo *registro)
{
    int cont = 0, acum = 0;
    while (registro->sig != NULL)
    {
        cont++;
        acum += registro->num;
        registro = registro->sig;
    }
    return acum / cont;
}

nodo *eliminar(nodo *registro, int promedio)
{
    nodo *aux = NULL;
    while (registro->sig != NULL && registro->sig->sig != NULL)
    {
        if (registro->sig->num < promedio)
        {
            aux = registro->sig->sig;
            free(registro->sig);
            registro->sig = aux;
        }
        registro = registro->sig;
    }
    return registro;
}

nodo *eliminarCabeza(nodo *registro, int promedio)
{
    nodo *aux = NULL;
    if (registro->num < promedio)
    {
        aux = registro->sig;
        free(registro);
        registro = aux;
    }
    return registro;
}

int main()
{
    nodo *head = NULL, *new = NULL;
    head = (nodo *)malloc(sizeof(nodo));
    crear(head);
    printf("\n\nLista original");
    mostrar(head);
    new = (nodo *)malloc(sizeof(nodo));
    generar(head, new);
    printf("\n\nNueva lista");
    mostrar(new);
    printf("\n\nPromedio: %d", promedio(head));
    eliminar(new, promedio(head));
    head = eliminarCabeza(new, promedio(head));
    printf("\n\nLista con eliminaciones");
    mostrar(new);
}

/* Estructura: numero, puntero.
a) Crear y mostrar la lista. Termina con num=1000.
b) Generar otra lista con aquellos números múltiplos de 3. Mostrarla  
c) Si la suma de 2 nodos consecutivos de la lista original es mayor a 20 
agregar adelante del primer nodo que se suma un nodo con num=0.
d) Si la suma de nodos consecutivos es menor a 10 eliminar el segundo nodo que se suma.
Mostrar la lista.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int num;
    struct lista *sig;
} nodo;

void crear(nodo *registro)
{
    printf("Ingrese un numero: ");
    scanf("%d", &registro->num);
    if (registro->num != 1000)
    {
        registro->sig = (nodo *)malloc(sizeof(nodo));
        crear(registro->sig);
    }
    else
    {
        registro->sig = NULL;
    }
}

void mostrar(nodo *registro)
{
    if (registro->sig != NULL)
    {
        printf("\n%d", registro->num);
        mostrar(registro->sig);
    }
}

void generar(nodo *orig, nodo *nuevo)
{
    if (orig->sig != NULL)
    {
        if ((orig->num % 3) == 0)
        {
            nuevo->num = orig->num;
            nuevo->sig = (nodo *)malloc(sizeof(nodo));
            generar(orig->sig, nuevo->sig);
        }
        else
        {
            generar(orig->sig, nuevo);
        }
    }
}

nodo *insertar(nodo *registro)
{
    nodo *aux = NULL;
    if (registro->sig != NULL && registro->sig->sig != NULL && registro->sig->sig->sig != NULL)
    {
        if ((registro->sig->num + registro->sig->sig->num) > 20)
        {
            aux = (nodo *)malloc(sizeof(nodo));
            aux->num = 0;
            aux->sig = registro->sig;
            registro->sig = aux;
            insertar(registro->sig->sig->sig);
        }
        else
        {
            insertar(registro->sig);
        }
    }
    return registro;
}

nodo *insertarCabeza(nodo *registro)
{
    nodo *aux = NULL;
    if (registro->sig != NULL && registro->sig->sig != NULL)
    {
        if ((registro->num + registro->sig->num) > 20)
        {
            aux = (nodo *)malloc(sizeof(nodo));
            aux->num = 0;
            aux->sig = registro;
            registro = aux;
        }
    }
    return registro;
}

nodo *eliminar(nodo *registro)
{
    nodo *aux = NULL;
    if (registro->sig != NULL && registro->sig->sig != NULL)
    {
        if ((registro->num + registro->sig->num) < 10)
        {
            aux = registro->sig->sig;
            free(registro->sig);
            registro->sig = aux;
        }
        eliminar(registro->sig);
    }
    return registro;
}

int main()
{
    nodo *head = NULL, *new = NULL;
    head = (nodo *)malloc(sizeof(nodo));
    crear(head);
    printf("\n\nLista original");
    mostrar(head);
    new = (nodo *)malloc(sizeof(nodo));
    generar(head, new);
    printf("\n\nLista generada");
    mostrar(new);
    insertar(head);
    head = insertarCabeza(head);
    printf("\n\nLista con inserciones");
    mostrar(head);
    eliminar(head);
    printf("\n\nLista con eliminaciones");
    mostrar(head);
}

/*Crear una lista con tres numeros enteros que termina con el primer valor en 0. Mostrarla.
Generar otra lista con la suma de los tres numeros del nodo si la suma de los mismos supera a 10.
Insertar antes de cada nodo otro nodo con la mitad de cada valor del nodo.
Eliminar aquellos nodos cuya productoria es menor a 30.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int num1;
    int num2;
    int num3;
    struct lista *sig;
} nodo;

typedef struct lista2
{
    int suma;
    struct lista2 *sig;
} nodo2;

void crear(nodo *registro)
{
    printf("\nIngrese numero 1: ");
    scanf("%d", &registro->num1);
    if (registro->num1 != 0)
    {
        printf("\nIngrese numero 2: ");
        scanf("%d", &registro->num2);
        printf("\nIngrese numero 3: ");
        scanf("%d", &registro->num3);
        registro->sig = (nodo *)malloc(sizeof(nodo));
        crear(registro->sig);
    }
    else
    {
        registro->sig = NULL;
    }
}

void mostrar(nodo *registro)
{
    if (registro->sig != NULL)
    {
        printf("\n%d\t%d\t%d", registro->num1, registro->num2, registro->num3);
        mostrar(registro->sig);
    }
}

void generar(nodo *original, nodo2 *nuevo)
{
    if ((original->num1 + original->num2 + original->num3) > 10)
    {
        nuevo->suma = original->num1 + original->num2 + original->num3;
        nuevo->sig = (nodo2 *)malloc(sizeof(nodo2));
        generar(original->sig, nuevo->sig);
    }
    else
    {
        if (original->sig != NULL)
        {
            generar(original->sig, nuevo);
        }
        else
        {
            nuevo->sig = NULL;
        }
    }
}

void mostrar2(nodo2 *registro)
{
    if (registro->sig != NULL)
    {
        printf("\n%d", registro->suma);
        mostrar2(registro->sig);
    }
}

nodo *insertar(nodo *registro)
{
    nodo *aux = NULL;
    if (registro->sig != NULL && registro->sig->sig != NULL)
    {
        aux = (nodo *)malloc(sizeof(nodo));
        aux->num1 = registro->sig->num1 / 2;
        aux->num2 = registro->sig->num2 / 2;
        aux->num3 = registro->sig->num3 / 2;
        aux->sig = registro->sig;
        registro->sig = aux;
        insertar(registro->sig->sig);
    }
    else
    {
        return registro;
    }
}

nodo *insertarCabeza(nodo *registro)
{
    nodo *aux = NULL;
    if (registro->sig != NULL)
    {
        aux = (nodo *)malloc(sizeof(nodo));
        aux->num1 = registro->num1 / 2;
        aux->num2 = registro->num2 / 2;
        aux->num3 = registro->num3 / 2;
        aux->sig = registro;
        registro = aux;
    }
    return registro;
}

nodo *eliminar(nodo *registro)
{
    nodo *aux = NULL;
    if (registro->sig != NULL && registro->sig->sig != NULL)
    {
        if ((registro->sig->num1 * registro->sig->num2 * registro->sig->num3) < 30)
        {
            aux = registro->sig->sig;
            free(registro->sig);
            registro->sig = aux;
            eliminar(registro);
        }
        else
        {
            eliminar(registro->sig);
        }
    }
    return registro;
}

nodo *eliminarCabeza(nodo *registro)
{
    nodo *aux = NULL;
    if ((registro->num1 * registro->num2 * registro->num3) < 30)
    {
        aux = registro->sig;
        free(registro);
        registro = aux;
    }
    return registro;
}

int main()
{
    nodo *head = NULL;
    nodo2 *new = NULL;
    head = (nodo *)malloc(sizeof(nodo));
    crear(head);
    printf("\n\nLista");
    mostrar(head);
    new = (nodo2 *)malloc(sizeof(nodo2));
    generar(head, new);
    printf("\n\nLista de sumas");
    mostrar2(new);
    insertar(head);
    head = insertarCabeza(head);
    printf("\n\nLista con insercion");
    mostrar(head);
    eliminar(head);
    head = eliminarCabeza(head);
    printf("\n\nLista con eliminaciones");
    mostrar(head);
}

/*
Crear y mostrar una lista que contenga dos números enteros (termina con ambos números en cero).
Generar una lista nueva con el promedio de ambos números.
Insertar en la lista originalinal la mitad del valor de cada número si la suma de los números 
es mayor a 15.
Eliminar aquellos nodos donde el primer valor es múltiplo del segundo valor.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int num1;
    int num2;
    struct lista *sig;
} nodo;

typedef struct lista2
{
    int prom;
    struct lista2 *sig;
} nodo2;

void crear(nodo *registro)
{
    printf("\nIngrese numero 1: ");
    scanf("%d", &registro->num1);
    printf("\nIngrese numero 2: ");
    scanf("%d", &registro->num2);
    if (registro->num1 == 0 && registro->num2 == 0)
    {
        registro->sig = NULL;
    }
    else
    {
        registro->sig = (nodo *)malloc(sizeof(nodo));
        crear(registro->sig);
    }
}

void mostrar(nodo *registro)
{
    if (registro->num1 != 0 || registro->num2 != 0)
    {
        printf("\n%d\t%d", registro->num1, registro->num2);
        mostrar(registro->sig);
    }
}

void generar(nodo *orig, nodo2 *nuevo)
{
    if (orig->sig != NULL)
    {
        nuevo->prom = (orig->num1 + orig->num2) / 2;
        nuevo->sig = (nodo2 *)malloc(sizeof(nodo2));
        generar(orig->sig, nuevo->sig);
    }
    else
    {
        nuevo->prom = 0;
        nuevo->sig = NULL;
    }
}

void mostrar2(nodo2 *registro)
{
    if (registro->sig != NULL)
    {
        printf("\n%d", registro->prom);
        mostrar2(registro->sig);
    }
}

nodo *insertar(nodo *registro)
{
    nodo *aux = NULL;
    if (registro->sig != NULL)
    {
        if ((registro->num1 + registro->num2) > 15)
        {
            aux = (nodo *)malloc(sizeof(nodo));
            aux->num1 = registro->num1 / 2;
            aux->num2 = registro->num2 / 2;
            aux->sig = registro->sig;
            registro->sig = aux;
            insertar(registro->sig->sig);
        }
        else
        {
            insertar(registro->sig);
        }
    }
    return registro;
}

nodo *eliminar(nodo *registro)
{
    nodo *aux = NULL;
    if (registro->sig != NULL && registro->sig->sig != NULL)
    {
        if (registro->sig->num2 != 0 && (registro->sig->num1 % registro->sig->num2) == 0)
        {
            aux = registro->sig->sig;
            free(registro->sig);
            registro->sig = aux;
        }
        eliminar(registro->sig);
    }
    return registro;
}

nodo *eliminarCabeza(nodo *registro)
{
    nodo *aux = NULL;
    if (registro->num1 != 0 && (registro->num1 % registro->num2) == 0)
    {
        aux = registro->sig;
        free(registro);
        registro = aux;
    }
    return registro;
}

int main()
{
    nodo *head = NULL;
    nodo2 *new = NULL;
    head = (nodo *)malloc(sizeof(nodo));
    crear(head);
    printf("\n\n Lista");
    mostrar(head);
    new = (nodo2 *)malloc(sizeof(nodo2));
    generar(head, new);
    printf("\n\n Promedios");
    mostrar2(new);
    insertar(head);
    printf("\n\nLista inserciones");
    mostrar(head);
    eliminar(head);
    head = eliminarCabeza(head);
    printf("\n\nLista eliminaciones");
    mostrar(head);
}

/*Crear y mostrar una lista simplemente enlazada con los siguientes datos
año de nacimiento
peso 
altura               
La carga termina cuando el año de nacimiento es 0.
Generar una nueva lista con el año de nacimiento y el índice de masa corporal. 
Este se calcula como peso/(altura*altura).
Insertar en esta lista despues de cada nodo donde el indice de masa corporal sea menor 
a 24, un nuevo nodo con el año de nacimiento y en el indice un 1.
Generar otra lista con el aquellas personas que tienen sobrepeso. 
El indice de maso corporal debe ser mayor a 25 para tener sobrepreso.
Eliminar de la lista original aquellas personas que nacieron en 1960 y 1970 y no tiene sobrepeso.
Mostrar todas las listas en cada caso.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int anio;
    int peso;
    int altura;
    struct lista *sig;
} nodo;

typedef struct lista2
{
    int anio;
    int masa;
    struct lista2 *sig;
} nodo2;

void crear(nodo *registro)
{
    printf("\nIngrese anio de nacimiento: ");
    scanf("%d", &registro->anio);
    while ((registro->anio < 1900 || registro->anio > 2020) && registro->anio != 0)
    {
        printf("\nReingrese: ");
        scanf("%d", &registro->anio);
    }
    if (registro->anio > 0)
    {
        printf("\nIngrese peso en kg: ");
        scanf("%d", &registro->peso);
        while (registro->peso < 0)
        {
            printf("\nReingrese: ");
            scanf("%d", &registro->peso);
        }
        printf("\nIngrese altura en cm: ");
        scanf("%d", &registro->altura);
        while (registro->peso < 0)
        {
            printf("\nReingrese: ");
            scanf("%d", &registro->altura);
        }
        registro->sig = (nodo *)malloc(sizeof(nodo));
        crear(registro->sig);
    }
    else
    {
        registro->sig = NULL;
    }
}

void mostrar(nodo *registro)
{
    if (registro->sig != NULL)
    {
        printf("\nNacimiento: %d", registro->anio);
        printf("\nPeso: %d", registro->peso);
        printf("\nAltura: %d", registro->altura);
        mostrar(registro->sig);
    }
}

void generar(nodo *orig, nodo2 *nuevo)
{
    if (orig->sig != NULL)
    {
        nuevo->anio = orig->anio;
        nuevo->masa = orig->peso / ((orig->altura / 100) * (orig->altura / 100));
        nuevo->sig = (nodo2 *)malloc(sizeof(nodo2));
        generar(orig->sig, nuevo->sig);
    }
    else
    {
        nuevo->sig = NULL;
    }
}

void mostrar2(nodo2 *registro)
{
    if (registro->sig != NULL)
    {
        printf("\nAnio de nacimiento: %d", registro->anio);
        printf("\nMasa corporal: %d", registro->masa);
        mostrar2(registro->sig);
    }
}

nodo2 *insertar(nodo2 *registro)
{
    nodo2 *aux = NULL;
    if (registro->sig != NULL)
    {
        if (registro->masa < 24)
        {
            aux = (nodo2 *)malloc(sizeof(nodo));
            aux->anio = registro->anio;
            aux->masa = 1;
            aux->sig = registro->sig;
            registro->sig = aux;
            insertar(registro->sig->sig);
        }
        else
        {
            insertar(registro->sig);
        }
    }
    return registro;
}

void generarSobrepeso(nodo2 *orig, nodo2 *nuevo)
{
    if (orig->sig != NULL)
    {
        if (orig->masa > 25)
        {
            nuevo->anio = orig->anio;
            nuevo->masa = orig->masa;
            nuevo->sig = (nodo2 *)malloc(sizeof(nodo2));
            generarSobrepeso(orig->sig, nuevo->sig);
        }
        else
        {
            generarSobrepeso(orig->sig, nuevo);
        }
    }
    else
    {
        nuevo->sig = NULL;
    }
}

nodo *eliminar(nodo *registro)
{
    nodo *aux = NULL;
    if (registro->sig != NULL && registro->sig->sig != NULL)
    {
        if (registro->sig->anio == 1960 || registro->sig->anio == 1970 && (registro->sig->peso / ((registro->sig->altura / 100) * (registro->sig->altura / 100)) < 25))
        {
            aux = registro->sig->sig;
            free(registro->sig);
            registro->sig = aux;
            eliminar(registro);
        }
        else
        {
            eliminar(registro->sig);
        }
    }
    return registro;
}

nodo *eliminarCabeza(nodo *registro)
{
    nodo *aux = NULL;
    if (registro->sig != NULL)
    {
        if (registro->anio == 1960 || registro->anio == 1970)
        {
            if (registro->peso / ((registro->altura / 100) * (registro->altura / 100)) < 25)
            {
                aux = registro->sig;
                free(registro);
                registro = aux;
            }
        }
    }
    return registro;
}

int main()
{
    nodo *head = NULL;
    nodo2 *im = NULL, *sp = NULL;
    head = (nodo *)malloc(sizeof(nodo));
    crear(head);
    printf("\n\nLista original");
    mostrar(head);
    im = (nodo2 *)malloc(sizeof(nodo2));
    generar(head, im);
    printf("\n\nLista indices");
    mostrar2(im);
    insertar(im);
    printf("\n\nLista inserciones");
    mostrar2(im);
    sp = (nodo2 *)malloc(sizeof(nodo2));
    generarSobrepeso(im, sp);
    printf("\n\nLista sobrepeso");
    mostrar2(sp);
    eliminar(head);
    head = eliminarCabeza(head);
    printf("\n\nLista eliminaciones");
    mostrar(head);
}
