// 5. Ingresar la edad y sueldo de los empleados de una empresa hasta que ambas sean
// cero. Calcular y mostrar:
// a) El promedio de edad de los que ganan más de $10000
// b) El sueldo de aquellas personas mayores a 58 años, sabiendo que
// cobran un plus del 5% de su sueldo.
// c) El porcentaje de empleados cuyo sueldo es menor a 15000, que está
// entre 15000 y 20000, y mayor a 20000

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int edad[100], sueldo[100], i=0, j, sumaEdad=0, contador=0;

    //Contadores para el ejercicio c
    int contadorA=0, contadorB=0, contadorC=0;

    printf("Ingrese una edad: ");
    scanf("%d", &edad[i]);
    printf("Ingrese un sueldo: ");
    scanf("%d", &sueldo[i]);

    while (edad[i] != 0 && sueldo[i] != 0)
    {
        i++;

        printf("Ingrese una edad: ");
        scanf("%d", &edad[i]);
        printf("Ingrese un sueldo: ");
        scanf("%d", &sueldo[i]);
    }

    printf("\nEjercicio a)\n");
    for(j=0;j<i;j++)
    {
        if (sueldo[j] > 10000)
        {
            sumaEdad += edad[j];
            contador += 1;
        }
    }
    printf("El promedio de edad de personas con sueldo mayores a 10000 es de: %d", sumaEdad/contador);

    printf("\nEjercicio b) ");
    printf("\nLos sueldos de las personas mayores a 58 años son: \n");
    for(j=0;j<i;j++)
    {
        if(edad[j] > 58)
        {
            printf("%f ", sueldo[j]*1.05);
        }
    }
    j=0;

    printf("\n");
    printf("Ejercicio c) ");
    for(j=0;j<i;j++)
    {
        if(sueldo[j] < 15000)
        {
            contadorA++;
        } else if (sueldo[j] > 15000 && sueldo[j] < 20000)
        {
            contadorB++;
        } else
        {
            contadorC++;
        }
        
    }
    
    printf("\nEl porcentaje de empleados con sueldo menor a 15000 es: %d", contadorA*100/i);
    printf("\nEl porcentaje de empleados con sueldo entre 15000 y 20000 es: %d", contadorB*100/i);
    printf("\nEl porcentaje de empleados con sueldo mayor a 20000 es: %d", contadorC*100/i);

    printf("\n");

    return 0;
}
