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
int factorial(int a)
{
    long long int factorA;
    int factorialDeA;
    factorA=1;
    for (factorialDeA = a; factorialDeA >= 1; factorialDeA--)
        {
            factorA = factorA * factorialDeA;
        }
        return printf("\n                     El factorial del valor %d es: %d ",a,factorA);

}
