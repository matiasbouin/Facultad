//Insertar y elminar en listas
//Guia 1, 2 y 4

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

//Luego los prototipos de funciones
void crear(nodo *registro);
void mostrar(nodo *registro);
void mostrarWhile(nodo *registro);
nodo* insertar1(nodo *p);
void insertar2 (nodo *p);
nodo* eliminar1(nodo* p);
void eliminar2(nodo* p);

int main() {
    //Ejemplo listas
    //El primer nodo(prin) se declara en el main para no perderlo
    //Declaro puntero hacia tipo de dato nodo
    nodo *prin, *prinInsertado, *prinEliminado;

    //Asigno espacio en memoria de tamaño nodo y se la asigno a prin
    prin = (nodo *)malloc(sizeof(nodo));
    crear(prin);
    //mostrar(prin);
    mostrarWhile(prin);
    printf("\n");

    //Insertar por cabeza de lista
    prinInsertado = insertar1(prin);
    mostrarWhile(prinInsertado);
    printf("\n");

    //Insertar en NO cabeza de lista
    insertar2(prin);
    mostrarWhile(prin);
    printf("\n");

    //Eliminar por cabeza de lista
    prinEliminado = eliminar1(prinInsertado);
    mostrarWhile(prinEliminado);
    printf("\n");

    //Eliminar por NO cabeza de lista
    eliminar2(prin);
    mostrarWhile(prin);
    printf("\n");


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

//Insertar

nodo* insertar1(nodo *p)
{
    nodo *aux;
    if(p->num == 1)//condicion de insercion
    {
        aux=(nodo *)malloc(sizeof(nodo));
        aux->num=0;//valor a insertar
        aux->sig=p;
        p=aux;
    }
    return p;
}

//INSERTAR2 => Siemopre agrega delante de donde estoy parado, en funcion de donde estoy parado
void insertar2 (nodo *p)
{nodo *aux;
    while(p->sig!=NULL)
    {
        if(p->num%2 != 0) //condicion de insercion
        {
            aux=(nodo *)malloc(sizeof(nodo));
            aux->num=420;//valor a insertar
            aux->sig=p->sig;
            p->sig=aux;

        }
        p=p->sig;
    }
}

//Eliminar

nodo* eliminar1(nodo* p)
{nodo *aux;
    while(p->num == 0)//condicion de eliminacion
    {
        aux=p->sig;
        free(p);
        p=aux;

    }
    return p;
}

void eliminar2(nodo* p)
{nodo *aux;
    while(p->sig!=NULL && p->sig->sig!=NULL)
    {
        if(p->sig->num == 420)//condicion de eliminacion
        {
            aux=p->sig->sig;
            free(p->sig);
            p->sig=aux;
        }
        else
        {
            p=p->sig;
        }
    }

}