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
        printf("\n                    3- Calcular todas las operaciones                 ");
        printf("\n         |                                                           |");
        printf("\n                    4- informar resultados                            ");
        printf("\n         |                                                           |");
        printf("\n                    5- Salir                                          ");
        printf("\n         |                                                           |");
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
            printf("\n         #############################################################");
            printf("\n         *                                                           *");
            printf("\n         *                >> Calculos realizados <<                  *");
            printf("\n         *                                                           *");
            printf("\n         #############################################################");
            printf("\n         |                                                           |");
            printf("\n                    a- Calcular la suma (%.2f+%.2f)                  ",valorUno,valorDos);
            printf("\n         |                                                           |");
            printf("\n                    b- Calcular la resta (%.2f-%.2f)                 ",valorUno,valorDos);
            printf("\n         |                                                           |");
            printf("\n                    c- Calcular la division (%.2f/%.2f)              ",valorUno,valorDos);
            printf("\n         |                                                           |");
            printf("\n                    d- Calcular la multiplicacion (%.2f*%.2f)        ",valorUno,valorDos);
            printf("\n         |                                                           |");
            printf("\n                    e- Calcular el factorial (%.2f!) (%.2f!)         ",valorUno,valorDos);
            printf("\n         |                                                           |");
            printf("\n         xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
            printf("\n");
            float sumarValores(float valorUno, float valorDos);
            float restarValores(float valorUno, float valorDos);
            float multiplicarValores(float valorUno, float valorDos);
            float dividirValores(float valorUno, float valorDos);
            float factorial (float valorUno, float valorDos);
            system("Pause");
            break;
        case 4:
            system("cls");
            printf("\n          a- La suma de los valores es: %.2f\n",sumarValores(valorUno,valorDos));
            printf("\n          b- La resta de los valores es: %.2f\n",restarValores(valorUno,valorDos));
            dividirValores(valorUno,valorDos);
            printf("\n          c- La multiplicacion de los valores es: %.2f\n",multiplicarValores(valorUno,valorDos));
            factorial(valorUno,valorDos);
            system("Pause");
            break;
        case 5:
            seguir=0;
            printf("Finalizando calculadora...\n");
            break;
        default:
            printf("El valor ingresado no pertenece a una opcion existente \n");
            system("Pause");
        }
        }
        system("Pause");
        return 0;
    }




    //movilizar los ifs al main para delucidar los valores negativos y fallos de div y factorial
