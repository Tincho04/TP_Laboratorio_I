#include <stdio.h>
#include <stdlib.h>
#include "string.h"

int getInt(char* msg)
{
    int numero;

    printf("%s", msg);
    scanf("%d", &numero);

    return numero;
}

float getFlotante(char* msg)
{
    float numero;

    printf("%s", msg);
    scanf("%f", &numero);

    return numero;
}

char* getString(char* msg, int limite)
{
    char* pBufferString = (char*) malloc(sizeof(char*));

    fflush(stdin);
    printf("%s", msg);
    gets(pBufferString);

    if(strlen(pBufferString) > limite)
    {
        printf("Texto ingresado demasiado largo.\n");
        strcpy(pBufferString, getString(msg, limite));
    }

    return pBufferString;
}

int isInt(char* pBuffer)
{
    int retorno = 0;
    int i = 0;
    while(pBuffer[i] != '\0')
    {
        if(pBuffer[i] < '0' || pBuffer[i] > '9')
        {
            retorno=-1;
            break;
        }
        i++;
    }
    return retorno;
}

int isIntConGuiones(char* pBuffer)
{
    int contadorGuiones = 0;
    int i = 0;
    int retorno = 0;

    while(pBuffer[i] != '\0')
    {
        if(pBuffer[i] == '-' && contadorGuiones == 0)
        {
            contadorGuiones++;
            i++;
            continue;
        }

        if(pBuffer[i] < '0' || pBuffer[i] > '9')
        {
            retorno = -1;
            break;
        }
        i++;
    }
    return retorno;
}

int menu()
{
    int opcion;
        system ("COLOR F0");
        system("cls");
        printf("\n         ################################################################");
        printf("\n         *                                                              *");
        printf("\n         *                 - Trabajo Practico Nro. 3 -                  *");
        printf("\n         *                                                              *");
        printf("\n         *                      >> LinkedList <<                        *");
        printf("\n         *                                                              *");
        printf("\n         *                  x Silva Chauvie Martin x                    *");
        printf("\n         *                                                              *");
        printf("\n         ################################################################");
        printf("\n         |                                                              |");
        printf("\n             1 - Carga de datos tipo texto");
        printf("\n         |                                                              |" );
        printf("\n             2 - Carga de datos tipo binario");
        printf("\n         |                                                              |" );
        printf("\n             3 - Alta de empleado");
        printf("\n         |                                                              |" );
        printf("\n             4 - Modificacion de datos de empleado");
        printf("\n         |                                                              |" );
        printf("\n             5 - Baja de empleado");
        printf("\n         |                                                              |" );
        printf("\n             6 - Listar empleados");
        printf("\n         |                                                              |" );
        printf("\n             7 - Ordenar empleados");
        printf("\n         |                                                              |" );
        printf("\n             8 - Guardar datos tipo texto");
        printf("\n         |                                                              |" );
        printf("\n             9 - Guardar datos tipo binario");
        printf("\n         |                                                              |" );
        printf("\n             10 - Salir");
        printf("\n         |                                                              |" );
        printf("\n         xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" );
        printf("\n");
        printf("\n          Ingrese una opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);
    return opcion;
}
