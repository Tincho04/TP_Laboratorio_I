#include <stdio.h>
#include <stdlib.h>
#include "algebra1.h"

float pedirValor (void)
{
    float valor;
    printf("Ingrese un numero: ");
    scanf("%f", &valor);
    return valor;
}
float sumarValores(float a, float b)
{

    return a+b;
}

float restarValores(float a, float b)
{
    return a-b;
}

float dividirValores(float a,float b)
{
    float div;
    if(b!=0)
    {
        div= a/b;
        return printf("\n           c- La division es: %.2f \n",div);
    }
    else
    {
        return  printf("\n          c- No es posible dividir por cero. \n");
    }

}

float multiplicarValores(float a, float b)
{
    return a*b;
}
float factorial(float a, float b)
{
    float factorA;
    float factorB;
    float factorialDeA;
    float factorialDeB;
    factorA=1;
    factorB=1;

    if (a>0 && b>0)
    {
        for (factorialDeA = a; factorialDeA > 1; factorialDeA--)
        {
            factorA = factorA * factorialDeA;
        }
        for (factorialDeB = b; factorialDeB > 1; factorialDeB--)
        {
            factorB = factorB * factorialDeB;
        }
        return printf("\n          e- El factorial del valor %.2f es: %.2f y el de %.2f es: %.2f \n",a,factorA,b,factorB);
        }else
        return printf("\n          e-  No se puede obtener el factorial de uno o ambos valores ingresados. \n");
}

