#include<stdio.h>
#include<stdlib.h>

//Primero cargo prototipos
//Una suerte de declaracion de funcion para que el compilador sepa que existe => Prototipos ===>>> NECESARIO PARA APROBAR
int cargarVector(int vector[], int longitud);
void ordenarVector(int vector[], int longitud);
int sumarElementosVector(int vector[], int longitud);

//Luego el Main
//Main
int main()
{
    //Declaracion de vector con 7 posiciones. que arrancan del 0 al 6 => Guarda 7 lugares para 7 enteros
    int a[7], i, j, resultado;

    //Hardcoded
    int b[5] = {4,3,2,1,0};

    //Prestar atencion a sintaxis
    a[7] = cargarVector(a, 7);

    //Mostrar el vector
    printf("\nEl vector es: ");
    for (i=0;i<7;i++)
    {
        printf("%d ", a[i]);
    }

    //Llamado a ordenar vector
    ordenarVector(a, 7);
    printf("\n");
    printf("El vector ordenado es: ");
    for (i=0;i<7;i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");

    //Llamado a sumar elementos vector
    resultado = sumarElementosVector(a, 7);
    printf("La suma de los elemtnos del vector es: %d\n", resultado);

    return 0;
}

//Luego codeo mis funciones
//Funciones => Puedo no respetar el mismo nombre de variables que en el main
int cargarVector(int a[], int longitud)
{
    int i;
    for (i=0;i<longitud;i++)
    {
        printf("Ingrese un valor para el vector:");
        scanf("%d", &a[i]); 
    }
    return a[i];
}

//Algoritmo burbujeo
void ordenarVector(int vector[], int longitud)
{
    int i, j, aux;
    for (i=0;i<longitud;i++)
    {
        for (j=i+1;j<longitud;j++)
        {
            if (vector[i] > vector[j])
            {
                aux=vector[i];
                vector[i] = vector[j];
                vector[j] = aux;
            }
        }
    }
}

int sumarElementosVector(int vector[], int longitud)
{
    int suma = 0, i;

    for (i=0;i<longitud;i++)
    {
        suma += vector[i];
    }

    return suma;
}