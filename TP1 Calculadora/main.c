#include <stdio.h>
#include <stdlib.h>
#include "algebra1.h"

int main()
{
    float valorUno=0;
    float valorDos=0;
    int opcion=0;
    int seguir=1;

    while(seguir==1)
    {
        system ("COLOR 4F");
        system("cls");
        printf("\n         #############################################################");
        printf("\n         *                - Trabajo Practico Nro. 1 -                *");
        printf("\n         *                                                           *");
        printf("\n         *                >> C A L C U L A D O R A <<                *");
        printf("\n         *                                                           *");
        printf("\n         *                  x Silva Chauvie Martin x                 *");
        printf("\n         #############################################################");
        printf("\n                               Elija una opcion:                     ");
        printf("\n         |                                                           |");
        printf("\n                    1- Ingresar 1er operando: (A= %.2f)              ",valorUno);
        printf("\n         |                                                           |");
        printf("\n                    2- Ingresar 2do operando: (B= %.2f)              ",valorDos);
        printf("\n         |                                                           |");
        printf("\n                    3- Calcular la suma (%.2f+%.2f)                  ",valorUno,valorDos);
        printf("\n         |                                                           |");
        printf("\n                    4- Calcular la resta (%.2f-%.2f)                 ",valorUno,valorDos);
        printf("\n         |                                                           |");
        printf("\n                    5- Calcular la division (%.2f/%.2f)              ",valorUno,valorDos);
        printf("\n         |                                                           |");
        printf("\n                    6- Calcular la multiplicacion (%.2f*%.2f)        ",valorUno,valorDos);
        printf("\n         |                                                           |");
        printf("\n                    7- Calcular el factorial (%.2f!) (%.2f!)         ",valorUno,valorDos);
        printf("\n         |                                                           |");
        printf("\n                    8- Calcular todas las operaciones                ");
        printf("\n         |                                                           |");
        printf("\n                                 9- Salir                            ");
        printf("\n         xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
        printf("\n");
        printf("\n                         Digite la opcion elegida: ");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            system("cls");
            valorUno=pedirValor();
            break;
        case 2:
            system("cls");
            valorDos = pedirValor();
            break;
        case 3:
            system("cls");
            printf("La suma de los valores es: %.2f\n",sumarValores(valorUno,valorDos));
            system("Pause");
            break;
        case 4:
            system("cls");
            printf("La resta de los valores es: %.2f\n",restarValores(valorUno,valorDos));
            system("Pause");
            break;
        case 5:
            system("cls");
            dividirValores(valorUno,valorDos);
            system("Pause");
            break;
        case 6:
            system("cls");
            printf("La multiplicacion de los valores es: %.2f\n",multiplicarValores(valorUno,valorDos));
            system("Pause");
            break;
        case 7:
            system("cls");
            factorial(valorUno,valorDos);
            system("Pause");
            break;
        case 8:
            system("cls");
            printf("La suma de los valores es: %.2f\n",sumarValores(valorUno,valorDos));
            printf("La resta de los valores es: %.2f\n",restarValores(valorUno,valorDos));
            dividirValores(valorUno,valorDos);
            printf("La multiplicacion de los valores es: %.2f\n",multiplicarValores(valorUno,valorDos));
            factorial(valorUno,valorDos);
            system("Pause");
            break;
        case 9:
            seguir=0;
            printf("Finalizando calculadora...\n");
            break;
        default:
            printf("El valor ingresado no pertenece a una opcion existente \n");
            system("Pause");
            break;
        }
    }
    system("Pause");
return 0;
}
