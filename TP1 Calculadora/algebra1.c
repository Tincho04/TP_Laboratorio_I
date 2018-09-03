#include <stdio.h>
#include <stdlib.h>
#include "algebra1.h"

int pedirValor (void)
{
    int valor;
    printf("Ingrese un numero entero: ");
    scanf("%d", &valor);
    return valor;
}
int sumarValores(int a, int b)
{
    return a+b;
}

int restarValores(int a, int b)
{
    return a-b;
}

float dividirValores(float a,float b)
{
    return a/b;
}

int multiplicarValores(int a, int b)
{
    return a*b;
}
int factorial(int a, int b)
{
    int factorA;
    int factorB;
    int factorialDeA;
    int factorialDeB;
    factorA=1;
    factorB=1;
    for (factorialDeA = a; factorialDeA >= 1; factorialDeA--)
        {
            factorA = factorA * factorialDeA;
        }
        for (factorialDeB = b; factorialDeB >= 1; factorialDeB--)
        {
            factorB = factorB * factorialDeB;
        }
        return printf("\n                 e- El factorial del valor %d es: %d y el de %d es: %d \n",a,factorA,b,factorB);

}
