// RECURSIVIDAD
// 
// Primero hacemos un ejercicio sin recursividad, con forma iterativa
// #include<stdio.h>

// int prod(int a, int b)
// {
//     int i, acumulador=0;
//     for (i=0;i<b;i++)
//     {
//         acumulador += a;
//     }

//     return acumulador;
// }
// int main()
// {
//     int a, b;

//     printf("Ingrese 2 numeros: ");

//     scanf("%d", &a);
//     scanf("%d", &b);

//     printf("El producto es: %d \n", prod(a,b));
    
//     return 0;
// }

//Ahora en forma recursiva - Recursividad es Armar funcion con siguientes caracteristicas: 
//#1 la funcion se llama así misma #2 Caso base o punto de corte(if statement) #3 No puedo usar ciclos repetitivos #4 No puedo usar contadores
// #include<stdio.h>

// int prod(int a, int b)
// {
//     if (b==0){
//         return 0;
//     }

//     return prod(a, b-1)+a;
// }

// int main()
// {
//     int a, b;

//     printf("Ingrese 2 numeros: ");

//     scanf("%d", &a);
//     scanf("%d", &b);

//     printf("El producto es: %d \n", prod(a,b));
    
//     return 0;
// }

//Factorrial de un numero
#include<stdio.h>

int factorial(int a)
{
    if (a==0) //Condicion de corte
    {
        return 1; //El factorial de 0 es 1
    }

    return factorial(a-1)*a; //Va acumulando a-1 en memoria para luego multiplicar por a
}

int main()
{
    int a;

    printf("Ingrese 1 numero: ");

    scanf("%d", &a);

    printf("El factorial es: %d \n", factorial(a));
    
    return 0;
}


// Ejercicios:
// Ingresar los n elemntos de un vector y mostrarlos. Construir una funcion en forma recursiva que sume sus elementos
// Ingresar los n+n elementos de una matriz y mostrarlos. COnstruir una funcion recursiva para calcular la productoria de los elementos de la diagonal principal
// Ingresar un tecto caracter a caracter terminado en punto. Construir una funcion recursiva para calcular la productoria de los elementos de la diagonal principal
// Ingresar un tecto caracter a caracter terminado en punto. Construir una funcion recursiva que permita mostrar el texto en forma invertida

#include<stdio.h>



int cargarVector (int vector[30], dimension)
{
    
}

int main()
{
    int vector[30], dimension;

    cargarVector(vector, dimension);


}