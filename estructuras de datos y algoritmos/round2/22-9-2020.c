//Listas simplemente enlazadas

//Primero importo librerías
#include<stdlib.h>
#include<stdio.h>

//Luego el struct (Tipo de dato propio)
typedef struct persona
{
    int edad;
    int dni;
    float estatura;
    char sexo;
}humano; //typedef me deja redefinir el tipo de dato struct persona con humano 

//Ejemplo listas => Importante
typedef struct lista
{
    int num;
    struct lista *sig;
}nodo; 
//asdasd
//Luego los prototipos de funciones
void crear(nodo *registro);
void mostrar(nodo *registro);
void mostrarWhile(nodo *registro);

int main() {
 
    //declaramos variable con tipo de dato humano
    humano jose;
    //Puedo asignar variable a un dato particular de mi struct persona (typedef humano)
    int dniJose = jose.dni;

    //Ejemplo listas
    //El primer nodo(prin) se declara en el main para no perderlo
    //Declaro puntero hacia tipo de dato nodo
    nodo *prin;

    //Asigno espacio en memoria de tamaño nodo y se la asigno a prin
    prin = (nodo *)malloc(sizeof(nodo));
    crear(prin);
    mostrar(prin);
    mostrarWhile(prin);


    return 0;
}

void crear(nodo *registro)
{
    int n, CORTE = 0; //Ver declaracion de CORTE
    scanf("%d", &n);
    registro->num = n;

    if (n == CORTE) //Puedo hardcodear la condicion de corte => n == 0
    {
        registro->sig = NULL;
    }
    else
    {
        registro->sig = (nodo *)malloc(sizeof(nodo));
        crear(registro->sig);
    }
    
    return;
}

//Mostrar con recursividad
void mostrar(nodo *registro)
{
    if (registro->sig != NULL)
    {
        printf("%d\n", registro->num);
        mostrar(registro->sig);
    }
    return;
}

//Mostrar con while
void mostrarWhile(nodo *registro)
{
    while (registro->sig != NULL)
    {
        printf("%d\n", registro->num);
        registro = registro->sig;
    }
    return;
}