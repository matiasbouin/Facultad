// Crear y mostrar una lista simplemente enlazada con los siguientes datos

//  año de nacimiento
//  peso
//  altura
// La carga termina cuando el año de nacimiento es 0.

// Generar una nueva lista con el año de nacimiento y el índice de masa corporal. Este se calcula como peso/(altura*altura).
// Insertar en esta lista despues de cada nodo donde el indice de masa corporal sea menor a 24, un nuevo nodo con el año de nacimiento y en el indice un 1.
// Generar otra lista con el aquellas personas que tienen sobrepeso. El indice de maso corporal debe ser mayor a 25 para tener sobrepreso.
// Eliminar de la lista original aquellas personas que nacieron en 1960 y 1970 y no tiene sobrepeso.

// Mostrar todas las listas en cada caso.

#include <stdio.h>
#include <stdlib.h>

//Defino estructuras a utilizar
typedef struct lista
{
    int nacimiento;
    float peso;
    float altura;
    struct lista *sig;
} nodo;

typedef struct lista2
{
    int nacimiento;
    float bmi;
    struct lista2 *sig;
} nodo2;

//Crear lista enlazada principal
void crear(nodo *registro)
{
    printf("ingrese un año de nacimiento: ");
    scanf("%d", &registro->nacimiento);

    if (registro->nacimiento == 0)
    {
        registro->sig = NULL;
    }
    else
    {
        printf("ingrese un peso: \n");
        scanf("%f", &registro->peso);
        printf("ingrese una altura: \n");
        scanf("%f", &registro->altura);

        registro->sig = (nodo *)malloc(sizeof(nodo));
        crear(registro->sig);
    }
}

//Mostar listas de estructura principal
void mostrar(nodo *registro)
{
    if (registro->sig != NULL)
    {
        printf("Año de nacimiento: %d \n", registro->nacimiento);
        printf("Peso: %f \n", registro->peso);
        printf("Altura: %f \n", registro->altura);
        printf("\n");
        mostrar(registro->sig);
    }
    return;
}

//Mostrar listas de estructura secundaria
void mostrarListaBmi(nodo2 *registroBmi)
{
    if (registroBmi->sig != NULL)
    {
        printf("Año de nacimiento: %d \n", registroBmi->nacimiento);
        printf("BMI (Boddy mass index): %f \n", registroBmi->bmi);
        printf("\n");
        mostrarListaBmi(registroBmi->sig);
    }
    return;
}

//Creacion de lista BMI (Boddy mass index o indice de masa corporal)
void nuevaLista(nodo *registro, nodo2 *registroBmi)
{
    while (registro->sig != NULL)
    {
        registroBmi->nacimiento = registro->nacimiento;
        registroBmi->bmi = registro->peso / (registro->altura * registro->altura);
        registroBmi->sig = (nodo2 *)malloc(sizeof(nodo2));
        registroBmi = registroBmi->sig;
        registro = registro->sig;
    }
    registroBmi->sig = NULL;
}

//Insercion si en la cabeza de la lista coincide la condicion
nodo2 *insertarCabezaNuevaLista(nodo2 *registroBmi) // nodo* Devuelve punteros, registro apunta a cabeza ya que la invoco con cabeza
{
    nodo2 *aux;
    if (registroBmi->bmi < 24) //Condicion de inserción
    {
        aux = (nodo2 *)malloc(sizeof(nodo2));      //Reservo espacio de memoria para nodo auxiliar
        aux->nacimiento = registroBmi->nacimiento; //Valor a insertar
        aux->bmi = 1;
        aux->sig = registroBmi; //Enlace del nuevo nodo a la lista (sig apunta a registro)
        registroBmi = aux;      //Hago que registro cómo cabeza de la lista apunte a la nueva cabeza (aux)
    }

    return registroBmi; //Devuelvo registro con cabeza modificada al programa principal main
}

//Insercion entre nodos que no sean cabeza de lista
void insertarNuevaLista(nodo2 *registroBmi)
{
    nodo2 *aux;
    while (registroBmi->sig != NULL) //Recorrer lista hasta que sig sea NULL
    {
        if (registroBmi->bmi < 24) //Condicion de inserción
        {
            aux = (nodo2 *)malloc(sizeof(nodo2));      //Reservo espacio de memoria
            aux->nacimiento = registroBmi->nacimiento; //Valor a insertar
            aux->bmi = 1;                              //Valor a insertar
            aux->sig = registroBmi->sig;               //Enlace a siguiente nodo
            registroBmi->sig = aux;                    //Enlace a nodo previo
        }
        registroBmi = registroBmi->sig; //No es necesario devolver un puntero ya que no se modifica la cabeza de la lista
    }
}

//Generacion de lista sobrepeso con estructura principal
void generarListaSobrepeso(nodo *registro, nodo *registroSobrepeso)
{
    while (registro->sig != NULL)
    {
        if (registro->peso / (registro->altura * registro->altura) > 25)
        {
            registroSobrepeso->nacimiento = registro->nacimiento; //Asignacion de datos
            registroSobrepeso->peso = registro->peso;             //Asignacion de datos
            registroSobrepeso->altura = registro->altura;         //Asignacion de datos

            registroSobrepeso->sig = (nodo *)malloc(sizeof(nodo)); //Reservo memoria

            registroSobrepeso = registroSobrepeso->sig; //Recorro listas
            registro = registro->sig;
        }
    }
    registroSobrepeso->sig = NULL;
}

//Eliminacion de la cabeza de la lista si coincide con condicion
nodo *eliminarNodoCabezaLista(nodo *registro)
{
    nodo *aux;
    while (registro->nacimiento == 1960 || registro->nacimiento == 1970 && registro->peso / (registro->altura * registro->altura) < 25)
    {
        aux = registro->sig;
        free(registro);
        registro = aux;
    }
    return registro;
}

//Eliminacion de nodo que no es cabeza de lista segun condicion
void eliminarNodoLista(nodo *registro)
{
    nodo *aux;
    while (registro->sig != NULL && registro->sig->sig != NULL)
    {
        if (registro->nacimiento == 1960 || registro->nacimiento == 1970 && registro->peso / (registro->altura * registro->altura)) //Condicion de eliminacion
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
}

int main()
{
    nodo *cabeza = NULL;
    nodo *cabezaSobrepeso = NULL;
    nodo2 *cabezaBmi = NULL;

    //Reservo espacio en memoria
    cabeza = (nodo *)malloc(sizeof(nodo));
    cabezaSobrepeso = (nodo *)malloc(sizeof(nodo));
    cabezaBmi = (nodo2 *)malloc(sizeof(nodo2));

    crear(cabeza);
    mostrar(cabeza);

    nuevaLista(cabeza, cabezaBmi);
    mostrarListaBmi(cabezaBmi);

    insertarCabezaNuevaLista(cabezaBmi);
    insertarNuevaLista(cabezaBmi);

    generarListaSobrepeso(cabeza, cabezaSobrepeso);
    mostrar(cabezaSobrepeso);

    eliminarNodoCabezaLista(cabeza);
    eliminarNodoLista(cabeza);
}


// MAL: VOID ELIMINAR (DEBERIA CHECKEAR EL SIGUIENTE Y NO EL ACTUAL) e INSERTAR (insertar despues de la lista, error de como entendi el ejercicio)