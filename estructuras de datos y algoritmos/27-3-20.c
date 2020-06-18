// #include<stdio.h>
// #include<stdlib.h>

// int main()
// {
//     int c, cont=0, aux;
    
//     printf("Ingrese la frase terminada en punto: \n");

//     c = getchar();
    
//     while(c != '.'){
        
//         // putchar(c)

//         aux = c;
//         while(c != ' ' && c != '.'){
//             c = getchar();
//         }
        
//         if (aux == 's'){
//             cont++;
//         }

//         if (c != '.'){
//             c = getchar();
//         }
        
//     }

//     printf("La cantidad de palabras que empiezan con s es: %d \n",cont);
    
    
// }

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int c, cont=0, aux;
    
    printf("Ingrese la frase y pulse enter: \n");

    c = getchar();
    
    while(c != '\n'){
        
        // putchar(c)

        while(c == ' ' && c != '\n'){
            c = getchar();
        }

        while(c != ' ' && c != '.'){
            putchar(c);
            c = getchar();
        }
        
        
        

        // if (c != '.'){
        //     c = getchar();
        // }
        
    }

    //printf("La cantidad de palabras que empiezan con s es: %d \n",cont);
    
    
}

