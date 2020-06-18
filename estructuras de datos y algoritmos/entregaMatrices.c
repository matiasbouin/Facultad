// Desarrollar un programa en C (con funciones) que permita cargar una matriz de nxn elementos. Mostrarla. Determinar si es una matriz antisimétrica.
// Una matriz antisimétrica es aquella matriz cuadrada que coincide con la opuesta de su traspuesta.
// DESARROLLO:

#include <stdio.h>
#include <stdlib.h>

void generarMatriz(int A[10][10], int filas, int columnas)
{
    int i, j, num;

    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            printf("Ingrese numero en Matriz: \n");
            scanf("%d", &num);
            A[i][j] = num;
        }
    }
}

void mostrarMatriz(int A[10][10], int filas, int columnas)
{
    int i, j;

    printf("Su matriz es: \n");

    for (i = 0; i < filas; i++)
    {
        printf("\n");

        for (j = 0; j < columnas; j++)
        {
            printf("%d \t", A[i][j]);
        }
    }

    printf("\n");
}

void esAntisimetrica(int A[10][10], int filas, int columnas)
{
    int i, j, contador=0;

    for (i=0;i<filas;i++)
    {
        for (j=0;j<columnas;j++)
        {
            if (A[i][j] == -A[j][i])
            {
                contador ++;
            }
        }
    }

    if (contador == filas * columnas)
    {
        printf("La matriz es antisimétrica \n");
    } else {
        printf("La matriz no es antisimetrica \n");
    }

    printf("El contador da: %d \n", contador);
}

int main()
{
    int A[10][10], columnas, filas;

    printf("Ingrese numero de filas: \n");
    scanf("%d", &filas);

    printf("Ingrese numero de columnas: \n");
    scanf("%d", &columnas);

    generarMatriz(A, columnas, filas);
    mostrarMatriz(A, columnas, filas);
    esAntisimetrica(A, columnas, filas);
}
