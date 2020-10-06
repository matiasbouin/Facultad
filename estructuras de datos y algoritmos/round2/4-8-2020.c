#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 10, valor, i;
    char b[10] = "holaholaho";
    int vector[10];

    if (a == 10)
    {
        printf("el valor de a, es %d, y el valor de b es %s \n", a, b);
    }
    else if (a != 10)
    {
        printf("El valor de a, no es %d \n", a);
    }

    printf("Ingresa un valor a ver cara de verga: ");
    scanf("%d", &valor);
    printf("El valor que ingresaste es: %d \n", valor);

    for (i = 0; i < 10; i++)
    {
        printf("Ingresa un valor para el vector: ");
        scanf("%d", &vector[i]);
    }

    printf("El vector es: ");
    for (i = 0; i < 10; i++)
    {
        printf("%d ", vector[i]);
    }
    printf("\n");

    return 0;
}