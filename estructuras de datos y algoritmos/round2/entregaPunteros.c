// Guia de ejercicios

//1: 5, 4
//2: 3, 9
//3: 3, 9
//4: 92345
// (...)

// Escribir un programa efectúe las siguientes operaciones:
// a) Declarar un arreglo de quince posiciones de tipo float. Cargar sus elementos y
// mostrarlo.
// b) Declarar un puntero a float.
// c) Asignar al puntero la dirección del arreglo.
// d) Recorrer con el puntero el arreglo, mostrando la dirección y el contenido de cada
// posición.

#include<stdio.h>
#include<stdlib.h>

void ejercicio5();
void ejercicio6();

int main() {
    
    ejercicio5();
    ejercicio6();

    return 0;
}

void ejercicio5(){

    printf("Ejercicio 5\n");

    int i;
    float *punt;
    float x[15];

    punt = x;


    for ( i = 0; i < 15; i++)
    {
        printf("Ingrese un valor: ");
        scanf("%f", &x[i]);
    }
    
    for ( i = 0; i < 15; i++)
    {
        printf("%f ", x[i]);
    }
    
    for ( i = 0; i < 15; i++)
    {
        printf("%f ", *(punt+i));
    }

    printf("\n");
}

void ejercicio6(){
    pritnf("Ejercicio 6\n");
    int matriz[3][4], i, j;
    int *puntero = NULL;

    puntero = matriz[0];

    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 4; j++)
        {
            printf("gimme number pls:");
            scanf("%d", &matriz[i][j]);
        }    
    }

    for ( i = 0; i < 3; i++)
    {
        printf("\n");
        for ( j = 0; j < 4; j++)
        {
            printf("%d ", matriz[i][j]);
        }
    }

    for ( i = 0; i < 3; i++)
    {
        printf("\n");
        for ( j = 0; j < 4; j++)
        {
            printf("%d ", matriz[i][j]);
        }
    }

    printf("\n");

}