#include <stdio.h>
#include <stdlib.h>

//MATRICES
//Arreglo bidimensional. Notacion: Aij, A = Nombre de matrices, i = Fila, j = Columna. Al crearlas debo dar la dimension.
//Hacer toda la guia y entregarla

//Compilador C pide al menos definir una dimension de la matriz
//Punto 1
void generarMatriz(int matriz[10][10], int filas, int columnas);
void mostrarMatriz(int matriz[10][10], int filas, int columnas);
void funcionA(int matriz[10][10], int columnas);
void funcionB(int matriz[10][10], int filas);
void funcionC(int matriz[10][10], int filas, int columnas);
void funcionD(int A[10][10], int filas, int columnas);
void funcionE(int matriz[10][10], int filas, int columnas);
void funcionF(int matriz[10][10], int filas, int columnas);
void funcionG(int matriz[10][10], int filas, int columnas);
void funcionH(int matriz[10][10], int filas, int columnas);

//Punto 2
void funcion2A(int matriz[10][10], int filas, int columnas);
void funcion2B(int matriz[10][10], int filas, int columnas);
void funcion2C(int matriz[10][10], int filas, int columnas);
void funcion2D(int matriz[10][10], int filas, int columnas);

int main()
{
    //Declaración de Matriz estática, PARA FINAL!!! <<<<<
    int matrizEstatica[3][3] = {
        {8, -5, 1},
        {2, 6, -9},
        {0, -3, 7}};

    //Declaración de matriz dinámica
    int matrizDinamica[10][10], filas, columnas;

    printf("Ingrese cantidad de filas: \n");
    scanf("%d", &filas);
    printf("Ingrese cantidad de columnas: \n");
    scanf("%d", &columnas);

    generarMatriz(matrizDinamica, filas, columnas);
    mostrarMatriz(matrizDinamica, filas, columnas);

    //Ejercicios Guia

    //PUNTO 1
    //Sumatoria elementos 2da fila
    funcionA(matrizDinamica, columnas);

    //Mayor elemento de la 2da columna
    funcionB(matrizDinamica, filas);

    //Promedio de todos los multiplos de 5 en la matriz
    funcionC(matrizDinamica, filas, columnas);

    //Sumatoria de la diagonal principal de la raiz
    funcionD(matrizDinamica, filas, columnas);

    //Minimo elemento de cada fila
    funcionE(matrizDinamica, filas, columnas);

    //Elementos de la diagonal secundaria
    funcionF(matrizDinamica, filas, columnas);

    //Elementos que se encuentran debajo de la diagonal principal
    funcionG(matrizDinamica, filas, columnas);

    //Es simetrica
    funcionH(matrizDinamica, filas, columnas);

    //PUNTO 2
    //Matriz transpuesta
    funcion2A(matrizDinamica, filas, columnas);

    //Promedio de los elementos de ambas diagonales
    funcion2B(matrizDinamica, filas, columnas);

    //Multiplicacion de matriz por su transpuesta
    funcion2C(matrizDinamica, filas, columnas);

    //Numeros primos dentro de la matriz
    funcion2D(matrizDinamica, filas, columnas);

    printf("Programa terminado \n");

    return 0;
}

//Compilador C pide al menos definir una dimension de la matriz
void generarMatriz(int matriz[10][10], int filas, int columnas)
{
    int i, j, valor;

    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            printf("Ingrese un valor: \n");
            scanf("%d", &matriz[i][j]);
        }
    }
    printf("\n");
}

void mostrarMatriz(int matriz[10][10], int filas, int columnas)
{
    int i, j;

    printf("Su matriz es: \n");

    for (i = 0; i < filas; i++)
    {
        printf("\n");
        for (j = 0; j < columnas; j++)
        {
            printf("%d\t", matriz[i][j]);
        }
    }
    printf("\n");
}

void funcionA(int matriz[10][10], int columnas)
{
    int j, suma = 0;

    for (j = 0; j < columnas; j++)
    {
        suma += matriz[1][j];
    }

    printf("La suma de los elementos de la segunda fila es: %d \n", suma);
}

void funcionB(int matriz[10][10], int filas)
{
    int i, mayor = 0;

    for (i = 0; i < filas; i++)
    {
        if (matriz[i][1] > mayor)
        {
            mayor = matriz[i][1];
        }
    }

    printf("El mayor de la segunda columna es: %d \n", mayor);
}

void funcionC(int matriz[10][10], int filas, int columnas)
{
    int suma = 0, i, j;
    float promedio, contador = 0;

    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            if (matriz[i][j] % 5 == 0)
            {
                suma += matriz[i][j];
                contador += 1;
            }
        }
    }

    promedio = suma / contador;

    printf("El promedio de los multiplos de 5 es: %f \n", promedio);
}

void funcionD(int matriz[10][10], int filas, int columnas)
{
    int i, j, suma = 0;

    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            if (i == j)
            {
                suma += matriz[i][j];
            }
        }
    }
    printf("La suma de la diagonal principal es: %d \n", suma);
}

void funcionE(int matriz[10][10], int filas, int columnas)
{
    int i, j, menores[filas], menor = matriz[0][0];

    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            if (matriz[i][j] < menor)
            {
                menor = matriz[i][j];
            }
        }

        menores[i] = menor;

        menor = matriz[i + 1][0];
    }

    printf("Los menores de cada fila son: ");

    for (i = 0; i < filas; i++)
    {
        printf("  %d  ", menores[i]);
    }

    printf("\n");
}

void funcionF(int matriz[10][10], int filas, int columnas)
{
    int i, j, contadorColumnas = columnas - 1;

    printf("La segunda diagonal es: ");

    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            if (j == contadorColumnas)
            {
                printf("%d \t", matriz[i][j]);
                contadorColumnas -= 1;
            }
        }
    }

    printf("\n");
}

void funcionG(int matriz[10][10], int filas, int columnas)
{
    int i, j;

    printf("Los elementos que se encuentran debajo de la diagonal principal son:");
    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            if (i > j)
            {
                printf("%d\t", matriz[i][j]);
            }
        }
    }
    printf("\n");
}

void funcionH(int matriz[10][10], int filas, int columnas)
{
    int i, j, suma = 0, total = filas * columnas - filas, contador = 0;

    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            if (i != j)
            {
                if (matriz[i][j] == matriz[j][i])
                {
                    contador += 1;
                }
            }
        }
    }

    if (contador == total)
    {
        printf("La matriz es simetrica\n");
    }
    else
    {
        printf("La matriz no es simetrica\n");
    }
}

void funcion2A(int matriz[10][10], int filas, int columnas)
{
    int i, j;

    printf("Su matriz transpuesta es: \n");

    for (i = 0; i < filas; i++)
    {
        printf("\n");
        for (j = 0; j < columnas; j++)
        {
            printf("%d\t", matriz[j][i]);
        }
    }
    printf("\n");
}

void funcion2B(int matriz[10][10], int filas, int columnas)
{
    float promedioPrincipal, promedioSecundario;
    int i, j, sumaPrincipal = 0, sumaSecundaria = 0, contadorColumnas = columnas - 1;

    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            if (i == j)
            {
                sumaPrincipal += matriz[i][j];
            }
        }
    }

    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            if (j == contadorColumnas)
            {
                sumaSecundaria += matriz[i][j];
                contadorColumnas -= 1;
            }
        }
    }

    promedioPrincipal = sumaPrincipal / filas;
    promedioSecundario = sumaSecundaria / filas;

    printf("El promedio de los elementos de la diagonal principal es: %f\n", promedioPrincipal);
    printf("El promedio de los elementos de la diagonal secundaria es: %f\n", promedioSecundario);
}

void funcion2C(int matriz[10][10], int filas, int columnas)
{
    int i, j;

    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            matriz[i][j] *= matriz[j][i];
        }
    }

    printf("La matriz resultante del producto con su transpuesta es: \n");
    mostrarMatriz(matriz, filas, columnas);
}


//No logre hacer que funcione mi logica
void funcion2D(int matriz[10][10], int filas, int columnas)
{
    int i, j, n, tope, contador, numerosPrimos = 0;

    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            contador = 0;
            tope = matriz[i][j] - 1;
            for (n = 2; n < tope; n++)
            {    
                if (matriz[i][j]%n == 0)
                {
                    contador++;
                }
            }
            if (contador == 0)
            {
                numerosPrimos++;
            }
        }
    }
    printf("La cantidad de numeros primos en la matriz son: %d\n", numerosPrimos);
}