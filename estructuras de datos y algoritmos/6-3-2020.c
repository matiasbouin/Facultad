// #include<stdio.h>

// int main()
// {
//     printf("\nA sample C program\n\n");
//     return 0;
// }




// #include<stdio.h>

// int main()
// {
//     int num, acum = 0, cont = 0, cont1 = 0, contg = 0, div = 0, i = 0, cp = 0;
//     printf("Ingrese numero");
//     scanf("%d", &num);

//     while(num>0)
//     {
//         contg++;
        
//         if(num%3 == 0 && num%2 != 0)
//         {
//             acum = acum + num;
//             cont++;
//         }

//         if(4%num == 0)
//         {
//             cont1++;
//         }

//         for(i=1;i<num;i++)
//         {
//             if(num%i == 0)
//             {
//                 div++;
//             }
//         }

//         if(div==1){
//             cp++;
//         }

//         div = 0;

//         printf("\n Ingrese numero");
//         scanf("%d", &num);
//     }

//     if(cont != 0)
//     {
//         printf("\n El promedio es: %d", acum/cont);
//     }
//     else
//     {
//         printf("\n No se ingresaron valores bleble");
//     }

//     printf("\n El porcentaje es : %d", cont1*100 / contg);
//     printf("\n La cantidad de primos es: %d \n", cp);
    
// }


//Generar los primeros 4 numeros perfectos
// #include<stdio.h>

// int main()
// {
//     int numero = 2, contadorGeneral = 0, i, sumaNumeros = 0;

//     while (contadorGeneral < 4)
//     {
//         for (i=1;i<numero;i++)
//         {

//             if (numero%i == 0)
//             {
//                 sumaNumeros += i;
//             }
//         }

//         if (sumaNumeros == numero)
//         {
//             printf("Numero perfecto: %d \n", sumaNumeros);
//             contadorGeneral++;
//         }
        
//         sumaNumeros = 0;
//         numero++;
//     }
// }



#include<stdio.h>
#include<stdlib.h>

int main()
{
    int c, cont=0;
    
    printf("Ingrese la frase terminada en punto: ");

    c = getchar();
    
    while(c != '.'){

        if (c == 'a'){
            cont++;
        }

        c = getchar();
    }

    prinf("La cantidad de a es: %d",cont);
    
    
}