// a) Dados dos números enteros A y B, calcule su potencia (AB) en forma recursiva.

#include<stdio.h>

int potencia(int A, int B)
{
    if (B==0){
        return 1;
    }

    return potencia(a)
}

int main() {

    int A, B;

    printf("Ingrese 2 numeros enteros: \n");
    scanf("%d", &A);
    scanf("%d", &B);

    printf("La potencia de %d and %d is: %d \n", A, B, potencia(A, B));

    return 0;
}



// b) Cargar una matriz de nxn elementos enteros. Mostrarla. Calcular la suma de los elementos de la

// diagonal principal en forma recursiva.