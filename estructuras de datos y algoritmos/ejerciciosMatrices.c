
#include <stdio.h>
#include <stdlib.h>

void generarMatriz(int A[10][10], int filas, int columnas)
{
    int i, j, num;

    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            printf("Ingrese numero: \n");
            scanf("%d", &num);
            A[i][j] = num;
        }
    }

    printf("Matriz generada\n");
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

void funcionA(int A[10][10], int columnas)
{
    int j, suma = 0;

    for (j = 0; j < columnas; j++)
    {
        suma += A[1][j];
    }

    printf("La suma es: %d \n", suma);
}

void funcionB(int A[10][10], int filas)
{
    int i, mayor = 0;

    for (i = 0; i < filas; i++)
    {
        if (A[i][1] > mayor)
        {
            mayor = A[i][1];
        }
    }

    printf("El mayor de la segunda columna es: %d \n", mayor);
}

void funcionC(int A[10][10], int filas, int columnas)
{
    int suma = 0, i, j;
    float promedio, contador = 0;

    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            if (A[i][j] % 5 == 0)
            {
                suma += A[i][j];
                contador += 1;
            }
        }
    }

    promedio = suma / contador;

    printf("El promedio de los multiplos de 5 es: %f \n", promedio);
}

void funcionD(int A[10][10], int filas, int columnas)
{
    int i, j, suma = 0;

    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            if (i == j)
            {
                suma += A[i][j];
            }
        }
    }
    printf("La suma de la daigonal principal es: %d \n", suma);
}

void funcionE(int A[10][10], int filas, int columnas)
{
    int i, j, menores[filas], menor = A[0][0];

    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            if (A[i][j] < menor)
            {
                menor = A[i][j];
            }
        }

        menores[i] = menor;

        menor = A[i + 1][0];
    }

    printf("Los menores de cada fila son: ");

    for (i = 0; i < filas; i++)
    {
        printf("  %d  ", menores[i]);
    }

    printf("\n");
}

void funcionF(int A[10][10], int filas, int columnas)
{
    int i, j, contadorColumnas = columnas - 1;

    printf("La segunda diagonal es: ");

    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            if (j == contadorColumnas)
            {
                printf("%d \t", A[i][j]);
                contadorColumnas -= 1;
            }
        }
    }

    printf("\n");
}

void funcionG(int A[10][10], int filas, int columnas)
{
    int i, j, resta, suma;

    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            if (i == j && i < 1)
            {
                resta = i-1;
                suma = j+columnas;
                printf("%d", A[resta][suma]);
            }
        }
    }
}

int main()
{
    int A[10][10], filas, columnas;

    printf("Inserte numero de filas: \n");
    scanf("%d", &filas);

    printf("Inserte numero de columnas: \n");
    scanf("%d", &columnas);

    printf("Ustede escribio: %d \n", filas);
    printf("Ustede escribio: %d \n", columnas);

    generarMatriz(A, filas, columnas);
    mostrarMatriz(A, filas, columnas);
    funcionA(A, columnas);
    funcionB(A, filas);
    funcionC(A, filas, columnas);
    funcionD(A, filas, columnas);
    funcionE(A, filas, columnas);
    funcionF(A, filas, columnas);
    funcionG(A, filas, columnas);
}