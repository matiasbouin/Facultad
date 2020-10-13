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

// // >>>>>>>>>>> EJERCICIO CUATRO <<<<<<<<<<
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
// void eliminar2(nodo* p);

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
//     while(p->num == 0)//condicion de eliminacion
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
//     int contador = 1;
//     while(p->sig!=NULL && p->sig->sig!=NULL)
//     {
//         if(contador == 4)//condicion de eliminacion (Borrar el 5to elemento)
//         {
//             aux=p->sig->sig;
//             free(p->sig);
//             p->sig=aux;
//         }
//         else
//         {
//             p=p->sig;
//         }
//         contador++;
//     }
// }

// >>>>>>>>>>> MODELO PARCIAL EN CLASE <<<<<<<<<<
#include <stdio.h>
#include <stdlib.h>


typedef struct lista{
	int num;
	struct lista *sig;
 }nodo;


void crear (nodo *pt);
void mostrar(nodo *pt);
nodo* eliminar1(nodo* , int);
void insertar2 (nodo*, int);
void eliminar2(nodo* , int, int);


int main()
{
    
    nodo *prin=NULL;
    prin=(nodo*)malloc(sizeof(nodo));

    crear(prin);
    mostrar (prin);
    printf("\n");
    
    int a, b, c;

    printf("Ingrese dos numeros enteros: \n");
    scanf("%d", &a);
    scanf("%d", &b);

    printf("\n");

    if (a == 1)
    {
        prin = eliminar1(prin, b);
    } else if (a > 1)
    {
        eliminar2(prin, a, b);
    } else
    {
        printf("No se puede realizar la operacion\n");
    }
    
    mostrar(prin);


    printf("Ingrese otro numero entero: \n");
    scanf("%d", &c);

    insertar2(prin, c);
    mostrar(prin);

    return 0;
}

void crear (nodo *registro)
{

    scanf("%d",&registro->num);

    if (registro->num==1000)
        registro->sig=NULL;
    else
	{
        registro->sig=(nodo*)malloc(sizeof(nodo));
        crear (registro->sig);

	}
	return;
}

void mostrar (nodo *registro)
{
    if (registro->sig !=NULL)
	{
        printf ("%d\n",registro->num);
        mostrar (registro->sig);
	}
	return;
}

void insertar2 (nodo *p, int c)
{
    nodo *aux;
    int contador = 1, valor = c;

    while(p->sig!=NULL)
    {
        if(contador >= c && valor >= 0) //condicion de insercion
        {
            aux=(nodo *)malloc(sizeof(nodo));
            aux->num=valor;//valor a insertar
            aux->sig=p->sig;
            p->sig=aux;
            valor--;
        }
        p=p->sig;
        contador++;
    }
}

nodo* eliminar1(nodo* p, int b)
{
    nodo *aux;
    int contador=1;
    while(contador <= b)//condicion de eliminacion
    {
        aux=p->sig;
        free(p);
        p=aux;
        contador++;
    }
    return p;
}
void eliminar2(nodo* p, int a, int b)
{   
    nodo *aux;
    int contador=1;
    while(p->sig!=NULL&& p->sig->sig!=NULL)
    {
        if(contador >= a && contador <= b)//condicion de eliminacion
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

// >>>>>>>>>>> MODELO PARCIAL EN CLASE <<<<<<<<<<
