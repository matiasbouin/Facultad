//MATRICES (MULTIMENSIONAL ARRAYS)

// #include<stdio.h>
// #include<stdlib.h>

// void generarMatriz (int A[][8], int filas, int columnas){
//     int i, j, num;
    
//     for (i=0;i<filas;i++)
//     {
//         for (j=0;j<columnas;j++)
//         {
//             printf("Ingresa un número para completar la matriz: ");
//             scanf("%d", &num);
//             A[i][j] = num;
//         }
//     }
// }

// void mostrarMatriz (int A[][8], int filas, int columnas){
//     int i, j;
//     for (i=0;i<filas;i++)
//     {
//         printf("\n");
//         for (j=0;j<columnas;j++)
//         {
//             printf("%d \t", A[i][j]); // \t == tabulacion entre elementos
//         }
//     }
// }

// int main()
// {
//     int A[8][8], filas, columnas;
//     printf("Ingrese cantidad de filas: ");
//     scanf("%d",&filas);
//     printf("\n Ingrese cantidad de columnas");
//     scanf("%d", &columnas);
    
//     generarMatriz(A, filas, columnas);
//     mostrarMatriz(A, filas, columnas);
// }

// Desarrollar un programa en C (con funciones) que permita cargar una matriz de nxn elementos. Mostrarla. Determinar si es una matriz antisimétrica.
// Una matriz antisimétrica es aquella matriz cuadrada que coincide con la opuesta de su traspuesta.
// DESARROLLO:

#include<stdio.h>
#include<stdlib.h>

void generarMatriz (int A[][8], int filas, int columnas){
    int i, j, num;
    
    for (i=0;i<filas;i++)
    {
        for (j=0;j<columnas;j++)
        {
            printf("Ingresa un número para completar la matriz: ");
            scanf("%d", &num);
            A[i][j] = num;
        }
    }
}

void mostrarMatriz (int A[][8], int filas, int columnas){
    int i, j;
    for (i=0;i<filas;i++)
    {
        printf("\n");
        for (j=0;j<columnas;j++)
        {
            printf("%d \t", A[i][j]); // \t == tabulacion entre elementos
        }
    }
}

void antisimetrica (int A[][8], int filas, int columnas){ //No pude encontar la lógica para resolver este problema
    int i, j;
    for (i=0;i<filas;i++)
    {
        for (j=0;j<columnas;j++)
        {
            if (A[i][j] == A[][]) //No pude encontar la lógica para resolver este problema
            {
                
            }
        }
    }
}

int main()
{
    int A[8][8], filas, columnas;
    printf("Ingrese cantidad de filas: ");
    scanf("%d",&filas);
    printf("\n Ingrese cantidad de columnas");
    scanf("%d", &columnas);
    
    generarMatriz(A, filas, columnas);
    mostrarMatriz(A, filas, columnas);
    antisimetrica(A, filas, columnas);
}