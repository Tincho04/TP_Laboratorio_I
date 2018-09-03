#ifndef ALGEBRA1_H_INCLUDED
#define ALGEBRA1_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

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
        return printf("La division es: %.2f \n",div);
    }
    else
    {
        return  printf("No es posible dividir por cero. \n");
    }

}

float multiplicarValores(float a, float b)
{
    float multi;
    multi=a*b;
    return multi;
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
        return printf("El factorial del valor %.2f es: %.2f y el de %.2f es: %.2f \n",a,factorA,b,factorB);
        }else
        return printf("\n No se puede obtener el factorial de uno o ambos valores ingresados. \n");
}

#endif // ALGEBRA1_H_INCLUDED
