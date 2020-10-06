#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void funcion1();
void funcion2();
void funcion3();

int main()
{

    funcion1();

    funcion2();

    funcion3();

    return 0;
}

void funcion1()
{
    int c, contador1 = 0, contador2 = 0;
    printf("Ingrese la frase\n");

    c = getchar();
    putchar(c);

    while (c != '.')
    {
        //while de espacio
        while (c == ' ')
        {
            //Podria ir entre los while
            contador1 = 0;
            c = getchar();
            putchar(c);
        }

        //while de palabras
        while (c != ' ' && c != '.')
        {
            contador1++;
            c = getchar();
            putchar(c);
        }

        if (contador1 > 3)
        {
            contador2++;
        }
    }

    printf("\n");
    printf("Hay %d palabras con mas de 3 letras\n", contador2);
}

void funcion2() //No pude encontrar lógica para resolverlo
{
    int c, aux;

    printf("Ingrese la frase: \n");

    c = getchar();

    while (c != '.')
    {
        aux = c;
        //while de espacio
        while (c == ' ')
        {

            c = getchar();
            // putchar(c);
        }
        //Si quisiera un solo espacio entre palabras:
        putchar(' ');

        //while de palabras
        while (c != ' ' && c != '.')
        {

            c = getchar();
        }

        if (aux != ' ')
        {
            putchar(c);
        }   

        //Estadisticas y analisis se performean afuera del while

        //Hacer ejercicos 1 y pares ---> Entregar
    }

    printf("\n");
}

void funcion3() //Tampoco logre resolver este punto
{
    int c, contador1 = 0, contador2 = 0, contador3 = 0;
    char *aux;

    printf("Ingrese la frase\n");                                                                                                                                                                                                                                                                 

    c = getchar();
    putchar(c);

    while (c != '.')
    {
        //while de espacio
        
        while (c == ' ')
        {                                                                                                                                                                                                                                                                                                               
            if (aux == 's')
            {
                contador3++;
            }
            
            contador1 = 0;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
            c = getchar();
            putchar(c);
        }

        //while de palabras
        while (c != ' ' && c != '.')
        {
            contador1++;
            c = getchar();
            strcpy(aux, c);
            putchar(c);
            
        }

        if (contador1 > 2)
        {
            contador2++;
        }
    }

    printf("\n");
    printf("Hay %d palabras con mas de 2 letras\n", contador2);
    printf("Hay %d palabras que terminan con 's' \n", contador3);
}