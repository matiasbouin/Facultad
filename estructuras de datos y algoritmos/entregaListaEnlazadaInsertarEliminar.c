// Desarrollar un programa en C que permita crear una lista simplemente enlazada con la siguiente estructura:

// Typedef struct lista{

// int num;

// int num1;

// int num3;

// struct lista *sig;

// }nodo;

// Mostrar dicha lista (la carga finaliza con 0 en el primer número ingresado).
// Si la suma de los tres números del nodo es mayor a 20, insertar antes de cada nodo el doble de cada valor del nodo.
// Si la suma de los tres números es igual a 20, eliminar dicho nodo.
// Generar una nueva lista con aquellos nodos eliminados. Mostrar dicha lista

#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int num1;
    int num2;
    int num3;
    struct lista *sig;
} nodo;

//CREAR LISTA
void crearLista(nodo *registro)
{
    // int contador = 0; //???? esto no lo declaraba la profe pero lo usaba, creo que se puede sacar
    printf("Ingresa numero 1: \n");
    scanf("%d", &registro->num1);

    if (registro->num1 == 0) //Condicion de corte
    {
        registro->sig = NULL;
    }
    else
    {
        printf("Ingresa numero 2: \n");
        scanf("%d", &registro->num2);
        printf("Ingresa numero 3: \n");
        scanf("%d", &registro->num3);

        registro->sig = (nodo *)malloc(sizeof(nodo));
        // contador++; //???? acá aumentaba el contador en 1 no sé por qué, supongo que se puede sacar
        crearLista(registro->sig);
    }
}

//MOSTRAR LISTA
void mostrarLista(nodo *registro)
{
    if (registro->sig != NULL)
    {
        printf("numero 1: %d \n", registro->num1);
        printf("numero 2: %d \n", registro->num2);
        printf("numero 3: %d \n", registro->num3);
        mostrarLista(registro->sig);
    }
}

//INSERTAR EN CABEZA DE LISTA
nodo *insertarCabezaLista(nodo *registro) // nodo* Devuelve punteros, registro apunta a cabeza ya que la invoco con cabeza
{
    nodo *aux;
    int suma;
    suma = registro->num1 + registro->num2 + registro->num3;
    if (suma > 20) //Condicion de inserción?? Esto varía depende del ejercicio
    {
        aux = (nodo *)malloc(sizeof(nodo)); //Reservo espacio de memoria para nodo auxiliar
        aux->num1 = registro->num1 * 2;
        aux->num2 = registro->num2 * 2;
        aux->num3 = registro->num3 * 2; //Valor a insertar
        aux->sig = registro;            //Enlace del nuevo nodo a la lista (sig apunta a registro)
        registro = aux;                 //Hago que registro cómo cabeza de la lista apunte a la nueva cabeza (aux)
    }

    return registro; //Devuelvo registro con cabeza modificada al programa principal main
}

//INSERTAR NO EN CABEZA DE LISTA
void insertarNoCabezaLista(nodo *registro)
{
    nodo *aux;
    int suma;
    while (registro->sig != NULL) //Recorrer lista hasta que sig sea NULL
    {
        suma = registro->num1 + registro->num2 + registro->num3;
        if (suma > 20) //Condicion de inserción?? Esto varía depende del ejercicio
        {
            aux = (nodo *)malloc(sizeof(nodo)); //Reservo espacio de memoria
            aux->num1 = registro->num1 * 2;     //Valor a insertar
            aux->num2 = registro->num2 * 2;     //Valor a insertar
            aux->num3 = registro->num3 * 2;     //Valor a insertar
            aux->sig = registro->sig;           //Enlace a siguiente nodo
            registro->sig = aux;                //Enlace a nodo previo
        }
        registro = registro->sig; //No es necesario devolver un puntero ya que no se modifica la cabeza de la lista
    }
}

//ELIMINAR NODO EN CABEZA DE LISTA
nodo *eliminarCabezaLista(nodo *registro) //Uso nodo* ya que debo devolver la lista con la nueva cabeza al programa principal main
{
    nodo *aux;
    int suma;
    suma = registro->num1 + registro->num2 + registro->num3;
    while (suma == 20) //Condicion de eliminación (Que suma sea 20) Uso un while ya que el próximo nodo puede volver a ser 20
    {
        printf("ENTRA AL WHILE\n");
        aux = registro->sig; //Guardo el valor que será mi próxima cabeza luego de eliminar la existente
        free(registro);      //Funcion para liberar espacio de memoria reservado por malloc
        registro = aux;      //Apunto el nuevo nodo al siguiente nodo para que quede este último cómo cabeza
    }
    printf("SALE DEL WHILE\n");
    return registro; //Devuelvo el registro con su nueva cabeza al programa principal main
}

//ELIMINAR NODO QUE NO ES CABEZA DE LISTA
void eliminarNoCabezaLista(nodo *registro) //Uso Void ya que no necesito devolver la cabeza nueva
{
    nodo *aux;
    int suma;
    suma = registro->num1 + registro->num2 + registro->num3;
    while (registro->sig != NULL && registro->sig->sig != NULL) //Recorrer la lista
    {
        if (suma == 20) //Condición de eliminación (Que suma sea 20)
        {
            aux = registro->sig->sig;
            free(registro->sig);
            registro->sig = aux; //Para seguir recorriendo la lista
        }
        else
        {
            registro = registro->sig; //Para seguir recorriendo la lista
        }
    }
}

int main()
{
    nodo *cabeza;
    cabeza = (nodo *)malloc(sizeof(nodo));

    crearLista(cabeza);

    mostrarLista(cabeza);

    printf("ENTRANDO A INSERTAR CABEZA LISTA\n");
    insertarCabezaLista(cabeza);
    printf("SALIENDO DE INSERTAR CABEZA LISTA\n");

    printf("ENTRANDO A INSERTAR NO CABEZA LISTA\n");
    insertarNoCabezaLista(cabeza);
    printf("SALIENDO DE INSERTAR NO CABEZA LISTA\n");
    
    printf("ENTRANDO A ELIMINAR CABEZA LISTA\n");
    eliminarCabezaLista(cabeza);
    printf("SALIENDO DE ELIMINAR CABEZA LISTA\n");

    printf("ENTRANDO A ELIMINAR NO CABEZA LISTA\n");
    eliminarNoCabezaLista(cabeza);
    printf("SALIENDO DE ELIMINAR NO CABEZA LISTA\n");
}