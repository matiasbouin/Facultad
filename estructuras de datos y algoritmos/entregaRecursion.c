// EJERCICIO:
// a) Dados dos números enteros A y B, calcule su potencia (AB) en forma recursiva.
// b) Cargar una matriz de nxn elementos enteros. Mostrarla. Calcular la suma de los elementos de la
// diagonal principal en forma recursiva.

#include <stdio.h>
#include <stdlib.h>

int potencia(int BASE, int EXPONENTE)
{
    if (EXPONENTE != 0)
    
        return (BASE * potencia(BASE, EXPONENTE - 1));
    
    else
    
        return 1;
    
}

void cargar(int MATRIZ[8][8], int DIMENSION)
{
    int i, j;

    for (i = 0; i < DIMENSION; i++)
    {
        for (j = 0; j < DIMENSION; j++)
        {
            printf("\nIngrese número: ");
            scanf("%d", &MATRIZ[i][j]);
        }
    }
}

void mostrar(int MATRIZ[8][8], int DIMENSION)
{
    int i, j;
    printf("\n Su matriz es: \n");

    for (i = 0; i < DIMENSION; i++)
    {
        printf("\n");
        for (j = 0; j < DIMENSION; j++)
        {
            printf("%d \t", MATRIZ[i][j]);
        }
    }
}

int sumaDiagonal(int MATRIZ[8][8], int DIMENSION, int i, int j, int suma)
{
    if (j > DIMENSION)
    
        return suma;
    
    if (i == j)
    
        return suma += MATRIZ[i][j];
    
    return sumaDiagonal(MATRIZ, DIMENSION, i, j + 1, suma);
}

int main()
{

    //EJERCICIO POTENCIA
    int BASE, EXPONENTE, RESULTADO;

    printf("Ingrese 2 numeros: \n");
    scanf("%d", &BASE);
    scanf("%d", &EXPONENTE);

    RESULTADO = potencia(BASE, EXPONENTE);
    printf("%d**%d = %d \n", BASE, EXPONENTE, RESULTADO);

    //EJERCICIO MATRIZ
    int MATRIZ[8][8], DIMENSION, j, i, suma = 0, resultadoDiagonal;

    printf("\n MATRIZ \n");
    printf("\n Ingrese dimension: ");
    scanf("%d", &DIMENSION);

    cargar(MATRIZ, DIMENSION);

    mostrar(MATRIZ, DIMENSION);

    for (i = 0; i < DIMENSION; i++)
    {
        j = 0;
        suma += sumaDiagonal(MATRIZ, DIMENSION, i, j, 0);
    }

    printf("La suma de su diagonal es: %d", suma);
    printf("\n");

    return 0;
}