#include <stdio.h>
#include <stdlib.h>

//RECURSIVIDAD

int factorial(int n);
int division(int dividendo, int divisor);
void invertir(int n);
int funcion3(int numero, int suma);
int funcion4(int array[10], int suma, int contador);
int funcion5();
int funcion6(int array[10], int contador, int suma);

int main()
{
    int n, a, suma = 0, contador = 0;
    int array[10] = {1, 2, 3, 4, 5, 0, 0, 0, 0};

    printf("Ingrese un numero: \n");
    scanf("%d", &n);

    printf("El factorial de %d es %d\n", n, factorial(n));

    printf("Ingrese otro numero: \n");
    scanf("%d", &a);

    printf("La division es: %d\n", division(n, a));

    printf("La suma de los digitos del primer numero es: %d\n", funcion3(n, suma));
    suma = 0;

    printf("La suma de los elementos del array [1, 2, 3, 4, 5] es: %d\n", funcion4(array, suma, contador));
    suma = 0;
    contador = 0;

    printf("El menor numero del array es: %d\n", funcion6(array, contador, suma));

    return 0;
}

int factorial(int n)
{
    //Importante definir caso base
    if (n == 0)
    {
        //Devuelvo caso base en funcion de lo que tengo que hacer (Elemento neutro) => En este caso, n * 1 = n, si fuese una suma => n + 0 = n  (El elemento neutro sería 0)
        //A veces puedo no tener q devolver caso base
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

int division(int dividendo, int divisor)
{
    if (dividendo < divisor)
    {
        return 0;
    }
    else
    {
        return division(dividendo - divisor, divisor) + 1;
    }
}

void invertir(int numero)
{
    if (numero > 0)
    {
        printf("%d", numero % 10);
        return invertir(numero / 10);
    }
}

int funcion3(int numero, int suma)
{
    if (numero > 0)
    {
        suma += numero % 10;
        return funcion3(numero / 10, suma);
    }

    if (numero == 0)
    {
        return suma;
    }
}

// PREGUNTAR
int funcion4(int array[10], int suma, int contador) //Pasar suma como puntero /funcion void
{
    if (contador < 10)
    {
        suma += array[contador]; //VER => *suma +=
        return funcion4(array, suma, contador++);
    }


    // if (contador == 10)
    // {
    //     return suma;
    // }
}

// int multiplicar(int vector[],int dimen)
// {
//     if(dimen<0)
//     {
//         return 1;
//     }
//     else
//     {
//         return multiplicar(vector,dimen-1)*vector[dimen];
//     }
// }

int funcion5()
{
    //Hacer
}

int funcion6(int array[10], int contador, int menor)
{
    if (contador < 10)
    {
        if (array[contador] < menor)
        {
            menor = array[contador];
        }
        
        return funcion6(array, contador++, menor);
    }

    if (contador == 10)
    {
        return menor;
    }
}