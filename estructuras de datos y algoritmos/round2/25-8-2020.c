#include <stdio.h>
#include <stdlib.h>

//Caracteres TOMA CARACTER POR CARACTER EN FINAL
int main()
{
    //<var> = getchar() permite recorrer caracter a caracter
    //putchar(<var>) Mostrar en pantalla caracter a caracter
    // char c; //Puede ser int o char

    // c = getchar(); //Pausa en consola para ingresar frase (Acá solo toma el primer caracter) (El resto de la frase se guarda en un buffer de memoria)
    // while (c != '.') //Para una frase usar comillas dobles, para usar un solo caracter, debo usar comilla simple
    // {
    //     c = getchar(); //Siempre debe haber getchar() dentro de while
    // }

    // //While de espacios
    // while (c == ' ')
    // {
    //     c = getchar();
    // }

    // //While de palabras
    // while (c != ' ')
    // {
    //     c = getchar();
    // }

    //Plantilla -> Importa mucho el orden de ejecucion
    int c, contador1=0, contador2=0;
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
        //Si quisiera un solo espacio entre palabras:
        //putchar(' ');

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
        //Estadisticas y analisis se performean afuera del while

        //Hacer ejercicos 1 y pares ---> Entregar
    }

    printf("Hay %d palabras con mas de 3 letras", contador2);

    return 0;
}

void plantilla()
{
    int c;

    printf("Ingrese la frase: \n");

    c = getchar();
    putchar(c);

    while (c != '.')
    {
        //while de espacio
        while (c == ' ')
        {
            //Podria ir entre los while
            c = getchar();
            putchar(c);
        }
        //Si quisiera un solo espacio entre palabras:
        //putchar(' ');

        //while de palabras
        while (c != ' ' && c != '.')
        {
            c = getchar();
            putchar(c);
        }

        //Estadisticas y analisis se performean afuera del while

        //Hacer ejercicos 1 y pares ---> Entregar
    }

    printf("\n");
}