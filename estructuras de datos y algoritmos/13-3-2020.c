// #include<stdio.h>
// #include<stdlib.h>

// int divisores(int c)
// {
//     int i, acum=0;

//     for(i = 1; i<c; i++)
//     {
//         if (c%i == 0)
//         {
//             acum = acum + 1;
//         }
//     }
//     return acum;
// }

// int main()
// {
//     int a, b, sumadiv1, sumadiv2, cont = 0;
//     printf("Ingresar dos enteros: ");
//     scanf("%d", &a);
//     printf("Ingresar dos enteros: ");
//     scanf("%d", &a);

//     while(a>0 && b>0)
//     {
//         sumadiv1 = divisores(a);
//         sumadiv2 = divisores(b);

//         if (a==sumadiv2 && b==sumadiv1)
//         {
//             cont++;
//             printf("%d %d \n", a, b);
//         }
    
//     printf("Ingresar dos enteros: ");
//     scanf("%d", &a);
//     printf("Ingresar dos enteros: ");
//     scanf("%d", &a);
//     }

//     printf("Cantidades de pares de numeros amigos es %d", cont);
//     return 0;
// }

#include<stdio.h>
#include<stdlib.h>

void cargarVector(int b[], int n) //int b[] es declarado de esta forma ya q es una lista
{
    int i;
    for (i=0; i<n; i++)
    {
        printf("Ingrese elemento : \n");
        scanf("%d", &b[i]); //%d representa el tipo de valor a ingresar, en este caso integer
    }
    return;
}

void mostrarVector(int b[], int n) 
{
    int i;
    for (i=0; i<n; i++)
    {
        printf("Elemento: ");
        printf("%d", b[i]); 
    }
    return;
}

int promedio(int b[], int n)
{
    int i, acum = 0, cont = 0;
    
    for (i=1;i<n;i+=2)
    {
        acum += b[i];
        cont += 1;
    }
    return acum/cont;
}

void maxMin(int b[], int n)
{
    int i, max = b[0], min = b[0];

    int posmax, posmin;

    for (i=o;i<n;i++)
    {

        if (b[i] >= max)
        {
            max = b[0];
            posmax = i;
        }

        if (b[i] <= min)
        {
            min = b[i];
            posmax = i;
        }

    }

    printf("%d %d", max, posmax);
    printf("%d %d", min, posmin);

}

void ordenar(int b[], int n)
{
    int i, j, aux;

    for (i=0;i<n;i++)
    {
        for (j=i+1;j<n;j++)
        {
            if (b[i]>b[j])
            {
                aux = b[i];
                b[i] = b[j];
                b[j] = aux;
            }
        }
    }

    printf("%d", b);
}

// CONSIGNA: 
//  Ingresar 10 numeros enteros y cargar un vector con aquellos multiplos de 5. Mostrarlo
//  Si el vector no tiene elementos mostrar cartel y finalizar programa
//  De lo contrario, calcular y mostrar
//  b. Generar otro arreglo con los multiplos de 3
//  c. Insertar el promedio del vector original al final del vector
//  d. Eliminar del vector original el elemento máximo y desplazar a la izquierda los elementos

void primerEjercicio(int b[], int n)
{
    int i, c = 0, aux;
    for (i=0; i<n; i++)
    {
        printf("Ingrese elemento : \n");
        scanf("%d", aux); //%d representa el tipo de valor a ingresar, en este caso integer

        if (aux%5 == 0)
        {
            b[i] = aux;
            c++;
        }
    }

    if (c == 0)
    {
        printf("El vector no tiene elementos");
    }
    else
    {
        printf("%d", b);
    }
    
    return;
}

void puntoD ()
{
    
}


int main()
{
    //Declaro mi array con posiciones estaticas (cantidad predefinida)
    int a[30], dimension, p;

    //Pido a usuario que ingrese dimension real de nuestro array
    printf("Ingrese dimensión: ");
    scanf("%d", &dimension);
    
    //LLamo a funcion para cargar y mostrar vector
    cargarVector(a, dimension);
    mostrarVector(a, dimension);

    //Calcular el promedio de las posiciones pares
    p = promedio(a, dimension);

    //Maximo y minimo
    maxMin(a, dimension);

    //Ordenar items en array
    ordenar(a, dimension);


    printf("%d", p);
}


