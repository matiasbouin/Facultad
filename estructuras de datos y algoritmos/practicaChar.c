#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// void nombreJuan(char mejor[30])
// {
//     if (strcmp(mejor, "Juan") == 0)
//     {
//         printf("Es Juan! \n");
//     }
//     else
//     {
//         printf("No es Juan \n");
//     }
// }

// int main()
// {
//     int i, contador = 0, c;
//     char nombre[30], mejor[30];
//     float promedio, auxiliarPromedio;
//     for (i = 1; i <= 5; i++)
//     {
//         printf("Ingrese el nombre del alumno: \n");
//         scanf(" %[^\n]", nombre);
//         printf("\nSu promedio es: \n");
//         scanf("%f", &promedio);

//         if (promedio > auxiliarPromedio)
//         {
//             auxiliarPromedio = promedio;
//             strcpy(mejor, nombre);
//         }
//     }

//     printf("El mejor promedio es %.2f del alumno %s \n", auxiliarPromedio, mejor);

//     nombreJuan(mejor);

//     printf("Ingrese un frase terminada en punto: \n");

//     c = getchar();
//     while (c != '.')
//     {
//         if (c == ' ')
//         {
//             contador++;
//         }
//         c = getchar();
//     }

//     printf("La cantidad de palabras es: %d", contador + 1);

//     return 0;
// }

//1
// void ejercicio1()
// {
//     int c, contadorLetras = 0, contadorPalabras = 0;

//     printf("Ingrese una frase terminada en punto: \n");
//     c = getchar();

//     while (c != '.')
//     {
//         if (c != ' ')
//         {
//             contadorLetras += 1;
//         }

//         if (c == ' ')
//         {
//             if (contadorLetras >= 3)
//             {
//                 contadorPalabras += 1;
//             }
//             contadorLetras = 0;
//         }

//         c = getchar();
//     }

//     printf("La cantidad de palabras con mas de 3 letras son: %d", contadorPalabras);
// }

void ejercicio2()
{
    int c, d, contadorLetras = 0;

    printf("Ingrese una frase terminada en punto: \n");
    c = getchar();

    while (c != '.')
    {
        if (c != ' ')
        {
            contadorLetras += 1;
        }

        d = getchar();

        if (d == ' ')
        {
            if (contadorLetras == 1)
            {
                putchar(' ');
            }
            else
            {
                putchar(c);
            }
            contadorLetras = 0;
        }
        else
        {
            putchar(c);
        }
        c = getchar();
    }
}

void ejercicio3()
{
    
}

int main()
{
    //ejercicio1();
    //ejercicio2();
    ejercicio3();
}
