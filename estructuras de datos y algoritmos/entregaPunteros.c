#include <stdio.h>
#include <stdlib.h>

// 5. Escribir un programa efectúe las siguientes operaciones:
//
// a) Declarar un arreglo de quince posiciones de tipo float. Cargar sus elementos y mostrarlo.
// b) Declarar un puntero a float.
// c) Asignar al puntero la dirección del arreglo.
// d) Recorrer con el puntero el arreglo, mostrando la dirección y el contenido de cada posición.


float cargarArreglo(float array[], int dimension)
{
    int i;
    for (i = 0; i < dimension; i++)
    {
        printf("Ingresar float: \n");
        scanf("%f", &array[i]);
    }
}

float recorrerArreglo(float array[], float *p, int dimension)
{
    int i;
    for (i = 0; i < dimension; i++)
    {
        printf("%f \n", *(p + i));
    }
}

int main()
{
    float array[15], *p;
    int dimension = 15;

    cargarArreglo(array, dimension);

    p = array;

    recorrerArreglo(array, p, dimension);

    return 0;
}

// 8. Un programa en C contiene las siguientes sentencias:
//
// int A[10]={12,15,17,21,34,45};
// int *B;
// B=A;
// *B=A[4];
//
// a) ¿Qué valor representa A[4]?
// b) ¿Qué valor representa *(&B[3])?
// c) ¿Qué valor representa *(B+2)?
// d) ¿Qué valor representa A[0]?
// e) ¿Qué valor representa *(B+0)?

//a) Representa 34
//b) Representa una direccion de memoria
//c) Representa el valor de A[2] ==> 17
//d) Representa 12
//e) Representa A[0] ==> 12

