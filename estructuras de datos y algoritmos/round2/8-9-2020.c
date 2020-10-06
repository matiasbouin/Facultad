//PUNTEROS
// Declaro => int *puntero;
// La asignacion en C, debe ser entre mismo tipo de dato
//EJ: int<var> = <floatValue> //Error
#include <stdio.h>
#include <stdlib.h>

void swap(int *, int *);

int main()
{
    int num = 10; //2 Bytes

    //Declaracion del puntero => Almacena direcciones de memoria
    int *puntero; // 4 Bytes Todas las direcciones de memoria ocupan 4 Bytes (Independientemente del tipo de dato)

    //Asigno la direccion de memoria de num a una variable
    //Asigna direccion de memoria inicial
    puntero = &num;

    //con *<puntero> se accede a la variable que se encuentra la posicion de memoria <puntero>
    *puntero = 20;

    printf("%d", num);

    int numero1 = 19, numero2 = 81;

    swap(&numero1, &numero2);

    //____________

    //Declaro puntero
    int *ptr;

    // Reservar cantidad de memoria que indique sizeof y guardarla en la direccion de memoria ptr
    ptr = () malloc(sizeof(int));

    *ptr = 20;

    //Libero memoria
    free(ptr);

    //Ver clase de archivos minuto 120
    //REPASAR PARA EL FINAL
    
    //Apunta a un puntero de tipo FILE
    FILE *pFile;

    //Escribir archivo
    pFile = fopen("nombre.txt", "w"); //read write append
    while (numero1 != -1)
    {
        scanf("%d", &numero1);
        scanf("%f", &numero2);
        fprintf(pFile, "%d-%f\n", numero1, numero2);
    }
    fclose(pFile);

    pFile = fopen("nombre.txt", "w");

    while (!feof(pFile))
    {
        fscanf(pFile, "%d-%f\n", &numero1, &numero2);
    }

    fclose(pFile);
    return 0;
}

void swap(int *numero1, int *numero2)
{

    int aux = *numero1;

    *numero1 = *numero2;

    *numero2 = aux;

    printf("numero1= %d numero2= %d\n", *numero1, *numero2);
}