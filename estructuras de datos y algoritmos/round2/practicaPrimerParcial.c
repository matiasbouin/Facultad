// // >>>>>>>>>>> EJERCICIO UNO <<<<<<<<<<
// //Librerias
// #include<stdlib.h>
// #include<stdio.h>

// //Declaro mi struct
// typedef struct lista{
//     int num;
//     struct lista *sig;
// }nodo;

// //Prototipos de funciones
// void crear(nodo *registro);
// void mostrar(nodo *registro);
// void insertar2 (nodo *p);
// void eliminar2(nodo* p);
// void eliminar2Segundo(nodo* p);

// //main
// int main() {
    
//     nodo *nodoCabeza;

//     nodoCabeza = (nodo *)malloc(sizeof(nodo));

//     printf("Inserte los valores de la lista:\n");
//     crear(nodoCabeza);
//     printf("\n");
//     //mostrar(nodo);
//     mostrar(nodoCabeza);
//     printf("\n");

//     //agregarTerceroConsecutivo NO FUNCIONA <======
//     // insertar2(nodoCabeza);
//     // printf("INSERTAR 2 EJECUTADO\n");
//     // mostrar(nodoCabeza);

//     eliminar2(nodoCabeza);
//     mostrar(nodoCabeza);
//     printf("\n");

//     eliminar2Segundo(nodoCabeza);
//     mostrar(nodoCabeza);

//     return 0;
// }

// void crear(nodo *registro)
// {
//     int n, CORTE = 1000; //Ver declaracion de CORTE
//     scanf("%d", &n);
//     registro->num = n;

//     if (n == CORTE) //Puedo hardcodear la condicion de corte => n == 0
//     {
//         registro->sig = NULL;
//     }
//     else
//     {
//         registro->sig = (nodo *)malloc(sizeof(nodo));
//         crear(registro->sig);
//     }
    
//     return;
// }

// //Mostrar con recursividad
// void mostrar(nodo *registro)
// {
//     if (registro->sig != NULL)
//     {
//         printf("%d\n", registro->num);
//         mostrar(registro->sig);
//     }
//     return;
// }

// //Insertar el tercero consecutivo // NO FUNCIONA => PREGUNTAR
// // void insertar2 (nodo *p)
// // {nodo *aux;
// //     while(p->sig!=NULL)
// //     {
// //         if(p->num == p->sig->num) //condicion de insercion
// //         {
// //             aux=(nodo *)malloc(sizeof(nodo));
// //             aux->num=p->num;//valor a insertar
// //             aux->sig=p->sig;
// //             p->sig=aux;
// //         }
// //         p=p->sig;
// //     }
// // }

// //De dos consecutivos, eliminar el primero
// void eliminar2(nodo* p)
// {nodo *aux;
//     while(p->sig!=NULL && p->sig->sig!=NULL)
//     {
//         if(p->sig->num == p->sig->sig->num)//condicion de eliminacion
//         {
//             aux=p->sig->sig;
//             free(p->sig);
//             p->sig=aux;
//         }
//         else
//         {
//             p=p->sig;
//         }
//     }

// }

// //De dos consecutivos, eliminar el segundo
// void eliminar2Segundo(nodo* p)
// {nodo *aux;
//     while(p->sig!=NULL && p->sig->sig!=NULL)
//     {
//         if(p->sig->num == p->sig->sig->num)//condicion de eliminacion
//         {
//             aux=p->sig->sig->sig;
//             free(p->sig->sig);
//             p->sig=aux;
//         }
//         else
//         {
//             p=p->sig;
//         }
//     }
// }


// // >>>>>>>>>>> EJERCICIO DOS <<<<<<<<<<
// //Librerias
// #include<stdlib.h>
// #include<stdio.h>

// //Declaro mi struct
// typedef struct lista{
//     int num;
//     struct lista *sig;
// }nodo;

// //Prototipos de funciones
// void crear(nodo *registro);
// void mostrar(nodo *registro);
// nodo* eliminar1(nodo* p);
// void eliminar2(nodo* p);

// //main
// int main() {
    
//     nodo *nodoCabeza, *nodoCabezaEliminado;

//     nodoCabeza = (nodo *)malloc(sizeof(nodo));
//     nodoCabezaEliminado = (nodo *)malloc(sizeof(nodo));

//     printf("Inserte los valores de la lista:\n");
//     crear(nodoCabeza);
//     printf("\n");
//     //mostrar(nodo);
//     mostrar(nodoCabeza);
//     printf("\n");

//     //Eliminar elementos de la lista que esten entre p y q
//     //Importante => No es necesario crear un nuevo nodo para guardar la nueva cabeza de lista
//     nodoCabeza = eliminar1(nodoCabeza);
//     mostrar(nodoCabeza);
//     printf("\n");

//     eliminar2(nodoCabeza);
//     mostrar(nodoCabeza);

//     return 0;
// }

// void crear(nodo *registro)
// {
//     int n, CORTE = 1000; //Ver declaracion de CORTE
//     scanf("%d", &n);
//     registro->num = n;

//     if (n == CORTE) //Puedo hardcodear la condicion de corte => n == 0
//     {
//         registro->sig = NULL;
//     }
//     else
//     {
//         registro->sig = (nodo *)malloc(sizeof(nodo));
//         crear(registro->sig);
//     }
    
//     return;
// }

// //Mostrar con recursividad
// void mostrar(nodo *registro)
// {
//     if (registro->sig != NULL)
//     {
//         printf("%d\n", registro->num);
//         mostrar(registro->sig);
//     }
//     return;
// }


// nodo* eliminar1(nodo* p)
// {   
//     nodo *aux;
    
//     while(p->num >= 10 && p->num <= 20)//condicion de eliminacion
//     {
//         aux=p->sig;
//         free(p);
//         p=aux;

//     }
//     return p;
// }

// void eliminar2(nodo* p)
// {
//     nodo *aux;
   
//     while(p->sig!=NULL && p->sig->sig!=NULL)
//     {
//         if(p->sig->num >= 10 && p->sig->num <= 20)//condicion de eliminacion
//         {
//             aux=p->sig->sig;
//             free(p->sig);
//             p->sig=aux;
//         }
//         else
//         {
//             p=p->sig;
//         }
//     }
// }

// >>>>>>>>>>> EJERCICIO CUATRO <<<<<<<<<<
//Librerias
#include<stdlib.h>
#include<stdio.h>

//Declaro mi struct
typedef struct lista{
    int num;
    struct lista *sig;
}nodo;

//Prototipos de funciones
void crear(nodo *registro);
void mostrar(nodo *registro);
void eliminar2(nodo* p);

//main
int main() {
    
    nodo *nodoCabeza;

    nodoCabeza = (nodo *)malloc(sizeof(nodo));

    printf("Inserte los valores de la lista:\n");
    crear(nodoCabeza);
    printf("\n");

    //mostrar(nodo);
    mostrar(nodoCabeza);
    printf("\n");

    eliminar2(nodoCabeza);
    mostrar(nodoCabeza);

    return 0;
}

void crear(nodo *registro)
{
    int n, CORTE = 1000; //Ver declaracion de CORTE
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

nodo* eliminar1(nodo* p)
{   
    nodo *aux;
    while(p->num == 0)//condicion de eliminacion
    {
        aux=p->sig;
        free(p);
        p=aux;

    }
    return p;
}

void eliminar2(nodo* p)
{
    nodo *aux;
    int contador = 1;
    while(p->sig!=NULL && p->sig->sig!=NULL)
    {
        if(contador == 4)//condicion de eliminacion (Borrar el 5to elemento)
        {
            aux=p->sig->sig;
            free(p->sig);
            p->sig=aux;
        }
        else
        {
            p=p->sig;
        }
        contador++;
    }
}