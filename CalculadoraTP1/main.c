#include <stdio.h>
#include <stdlib.h>

float sumar (float, float);
float restar (float, float);
float multiplicar (float, float);
float dividir (float, float);
float factorial (float, float);

int main()
{
    int opcion;
    float valorA;
    float valorB;
    float resultado;
    do
    {
        printf("\n         #############################################################");
        printf("\n         *                - Trabajo Practico Nro. 1 -                *");
        printf("\n         *                                                           *");
        printf("\n         *                >> C A L C U L A D O R A <<                *");
        printf("\n         *                                                           *");
        printf("\n         *                  x Silva Chauvie Martin x                 *");
        printf("\n         #############################################################");
        printf("\n         |                     Elija una opcion:                     |");
        printf("\n         |                                                           |");
        printf("\n         |       1)  Suma                     2) Resta               |");
        printf("\n         |                                                           |");
        printf("\n         |       3)  Division                 4) Multiplicacion      |");
        printf("\n         |                                                           |");
        printf("\n         |       5)  Factorial                6) Salir               |");
        printf("\n         |                                                           |");
        printf("\n         |                                                           |");
        printf("\n         xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
        printf("\n");
        printf("\n                              Elija una opcion: ");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            system("cls");
            printf("Ingrese el primer numero a sumar: ");
            scanf("%f", &valorA);
            printf("Ingrese el segundo numero a sumar: ");
            scanf("%f", &valorB);
            sumar(valorA,valorB);
            break;
        case 2:
            system("cls");
            printf("Ingrese el primer numero a restar: ");
            scanf("%f", &valorA);
            printf("Ingrese el segundo numero a restar: ");
            scanf("%f", &valorB);
            restar(valorA,valorB);
            break;
        case 3:
            system("cls");
            printf("Ingrese el dividendo: ");
            scanf("%f", &valorA);
            printf("Ingrese el divisor: ");
            scanf("%f", &valorB);
            dividir(valorA,valorB);
            break;
        case 4:
            system("cls");
            printf("Ingrese el primer numero a multiplicar: ");
            scanf("%f", &valorA);
            printf("Ingrese el segundo numero a multiplicar: ");
            scanf("%f", &valorB);
            multiplicar(valorA,valorB);
            break;
        case 5:
            system("cls");
            printf("Ingrese el primer valor a factorear: ");
            scanf("%f", &valorA);
            printf("Ingrese el segundo valor a factorear: ");
            scanf("%f", &valorB);
            factorial(valorA,valorB);
            break;
        case 6:
            opcion = 6;
            break;
        default:
            printf("No es un numero correcto \n");
        }
        system("pause");
        system("cls");
    }
    while (opcion!=6);

    return 0;
}

float sumar(float sumandoUno, float sumandoDos)
{
    float suma;
    suma=sumandoUno+sumandoDos;
    printf("\n La Suma de %.2f + %.2f es igual a %.2f \n",sumandoUno,sumandoDos,suma);
}
float restar(float restandoUno, float restandoDos)
{
    float resta;
    resta=restandoUno-restandoDos;
    printf("\n La Resta de %.2f - %.2f es igual a %.2f \n",restandoUno,restandoDos,resta);
}
float dividir(float dividendo, float divisor)
{
    float division;
    if (divisor!=0)
    {
        division=dividendo/divisor;
        printf("\n La Division de %.2f / %.2f da: %.2f \n",dividendo,divisor,division);
    }
    else
        printf("\n No es posible dividir por cero \n");
}
float multiplicar(float multiplicandoUno, float multiplicandoDos)
{
    float multiplicacion;
    multiplicacion=multiplicandoUno*multiplicandoDos;
    printf("\n La Multiplicacion de %.2f * %.2f es igual a %.2f \n",multiplicandoUno,multiplicandoDos,multiplicacion);
}
float factorial(float factorialUno, float factorialDos)
{
    float factorA;
    float factorB;
    float factorialDeUno;
    float factorialDeDos;
    factorA=1;
    factorB=1;

    if (factorialUno>0)
    {
        for (factorialDeUno = factorialUno; factorialDeUno > 1; factorialDeUno--)
        {
            factorA = factorA * factorialDeUno;
        }
        printf("\n El factorial de %.2f es: %.2f \n",factorialUno,factorA);
    }
    else
        printf("\n Para obtener el factorial de un entero no debe ingresar numeros negativos \n");
    if (factorialDos>0)
    {
            for (factorialDeDos = factorialDos; factorialDeDos > 1; factorialDeDos--)
            {
                factorB = factorB * factorialDeDos;
            }
            printf("\n El factorial de %.2f es: %.2f \n",factorialDos,factorB);
        }
        else
            printf("\n Para obtener el factorial de un entero no debe ingresar numeros negativos \n");

    }
