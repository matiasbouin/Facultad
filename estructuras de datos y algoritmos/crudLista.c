#include <stdio.h>
#include <stdlib.h>

//Defino estructura nodo
typedef struct lista
{
    int num;
    struct lista *sig;
} nodo;

//CREAR LISTA
void crearLista(nodo *registro)
{
    int contador = 0; //???? esto no lo declaraba la mina pero lo usaba, creo que se puede sacar
    printf("Ingresa un numero entero flaco: \n");
    scanf("%d", &registro->num);

    if (registro->num == 0)
    {
        registro->sig = NULL;
    }
    else
    {
        registro->sig = (nodo *)malloc(sizeof(nodo));
        contador++; //???? acá aumentaba el contador en 1 anda a saber por que, supongo que se puede sacar
        crearLista(registro->sig);
    }
}

//MOSTRAR LISTA
void mostrarLista(nodo *registro)
{
    if (registro->sig != NULL)
    {
        printf("%d", registro->num);
        mostrarLista(registro->sig);
    }
}

//INSERTAR EN CABEZA DE LISTA
nodo *insertarCabezaLista(nodo *registro) // nodo* Devuelve punteros, registro apunta a cabeza ya que la invoco con cabeza
{
    nodo *aux;
    if () //Condicion de inserción?? Esto varía depende del ejercicio
    {
        aux = (nodo *)malloc(sizeof(nodo)); //Reservo espacio de memoria para nodo auxiliar
        aux->num = 0;                       //Valor a insertar
        aux->sig = registro;                //Enlace del nuevo nodo a la lista (sig apunta a registro)
        registro = aux;                     //Hago que registro cómo cabeza de la lista apunte a la nueva cabeza (aux)
    }

    return registro; //Devuelvo registro con cabeza modificada al programa principal main
}

//INSERTAR NO EN CABEZA DE LISTA
void insertarNoCabezaLista(nodo *registro)
{
    nodo *aux;
    while (registro->sig != NULL) //Condicion de inserción?? Esto varía depende del ejercicio
    {
        if ()
        {
            aux = (nodo *)malloc(sizeof(nodo)); //Reservo espacio de memoria
            aux->num = -1;                      //Valor a insertar
            aux->sig = registro->sig;           //Enlace a siguiente nodo
            registro->sig = aux;                //Enlace a nodo previo
        }
        registro = registro->sig; //No es necesario devolver un puntero ya que no se modifica la cabeza de la lista
    }
}

//ELIMINAR NODO EN CABEZA DE LISTA (Ejemplo: eliminar numeros pares)
nodo *eliminarCabezaLista(nodo *registro) //Uso nodo* ya que debo devolver la lista con la nueva cabeza al programa principal main
{
    nodo *aux;
    while (registro->num % 2 == 0) //Condicion de eliminación (Que sea par) Uso un while ya que el próximo nodo puede volver a ser par
    {
        aux = registro->sig; //Guardo el valor que será mi próxima cabeza luego de eliminar la existente
        free(registro);      //Funcion para liberar espacio de memoria reservado por malloc
        registro = aux;      //Apunto el nuevo nodo al siguiente nodo para que quede este último cómo cabeza
    }
    return registro; //Devuelvo el registro con su nueva cabeza al programa principal main
}

//ELIMINAR NODO QUE NO ES CABEZA DE LISTA (Ejemplo: eliminar numeros pares)
void eliminarNoCabezaLista(nodo *registro) //Uso Void ya que no necesito devolver la cabeza nueva
{
    nodo *aux;
    while (registro->sig != NULL && registro->sig->sig != NULL) //Recorrer la lista
    {
        if (registro->num % 2 == 0) //Condición de eliminación (Que sea par)
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
    cabeza = (nodo *)malloc(sizeof(nodo)); //Le pongo cabeza por que refiere a la cabeza de la lista

    crearLista(cabeza);

    mostrarLista(cabeza);

    insertarCabezaLista(cabeza);

    insertarNoCabezaLista(cabeza);

    eliminarCabezaLista(cabeza);

    eliminarNoCabezaLista(cabeza);

    return 0;
}
