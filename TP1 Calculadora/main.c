#include <stdio.h>
#include <stdlib.h>
#include "algebra1.h"

int main()
{
    int valorUno=0;
    int valorDos=0;
    int opcion=0;
    int seguir=1;
    int validacion=0;

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
        printf("\n                    1- Ingresar 1er operando: (A= %d)              ",valorUno);
        printf("\n         |                                                           |");
        printf("\n                    2- Ingresar 2do operando: (B= %d)              ",valorDos);
        printf("\n         |                                                           |");
        printf("\n                    3- Calcular todas las operaciones                 ");
        printf("\n         |                                                           |");
        printf("\n                    4- informar resultados                            ");
        printf("\n         |                                                           |");
        printf("\n                    5- Salir                                          ");
        printf("\n         |                                                           |");
        printf("\n         xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
        printf("\n");
        printf("\n          Digite la opcion elegida: ");
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
            printf("\n                    a- Calcular la suma (%d+%d)                  ",valorUno,valorDos);
            int sumarValores(int valorUno, int valorDos);
            printf("\n         |                                                           |");
            printf("\n                    b- Calcular la resta (%d-%d)                 ",valorUno,valorDos);
            int restarValores(int valorUno, int valorDos);
            printf("\n         |                                                           |");
            printf("\n                    c- Calcular la division (%d/%d)              ",valorUno,valorDos);
                valorUno=(float)valorUno;
                valorDos=(float)valorDos;
                float dividirValores(float valorUno, float valorDos);
            printf("\n         |                                                           |");
            printf("\n                    d- Calcular la multiplicacion (%d*%d)        ",valorUno,valorDos);
            int multiplicarValores(int valorUno, int valorDos);
            printf("\n         |                                                           |");

            printf("\n                    e- Calcular el factorial (%d!) (%d!)         ",valorUno,valorDos);
                int factorial (int valorUno);
                int factorial (int valorDos);
            printf("\n         |                                                           |");
            printf("\n         xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
            printf("\n");
            system("Pause");
            validacion=1;
            break;
        case 4:
            system("cls");
            if (validacion==1)
            {
        printf("\n         #############################################################");
        printf("\n         *                                                           *");
        printf("\n         *                      >> Resultados <<                     *");
        printf("\n         *                                                           *");
        printf("\n         #############################################################");
        printf("\n         |                                                           |");
        printf("\n                     La suma de los valores es: %d                  ",sumarValores(valorUno,valorDos));
        printf("\n         |                                                           |");
        printf("\n                     La resta de los valores es: %d                 ",restarValores(valorUno,valorDos));
        printf("\n         |                                                           |");
                  if(valorDos!=0)
            {
        printf("\n                     La division de los valores es de: %.2f         ",dividirValores(valorUno,valorDos));
            }
            else
            {
                printf("\n                     No es posible dividir por cero.");
            }
        printf("\n         |                                                           |");
        printf("\n                     La multiplicacion de los valores es: %d        ",multiplicarValores(valorUno,valorDos));
        printf("\n         |                                                           |");
                    if (valorUno>=0)
            {
               factorial (valorUno);
            }
            else
            {
                        printf("\n                No se puede obtener el factorial de este valor ");
            }
                   printf("\n         |                                                           |");

            if (valorDos>=0)
            {
             factorial (valorDos);
            }
            else {
                    printf("\n                No se puede obtener el factorial de este valor ");
}
        printf("\n         |                                                           |");
        printf("\n         xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
        printf("\n");
            }
            else {
        printf("\n         #############################################################");
        printf("\n         *                                                           *");
        printf("\n         *                      >> Resultados <<                     *");
        printf("\n         *                                                           *");
        printf("\n         #############################################################");
        printf("\n                                                                      ");
        printf("\n         |                                                           |");
        printf("\n                      Primero debe realizar los calculos              ");
        printf("\n         |                                                           |");
        printf("\n                                                                      ");
        printf("\n         xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
        printf("\n");
            }
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
