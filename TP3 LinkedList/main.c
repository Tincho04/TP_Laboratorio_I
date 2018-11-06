#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "string.h"
#include "Validaciones.h"
#include "parser.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do
    {
        system("cls");
        option = menu();
        switch(option)
        {
        case 1:
            controller_loadFromText("data.csv",listaEmpleados);
            break;
        case 2:
            controller_loadFromBinary("data.bin", listaEmpleados);
            break;
        case 3:
            system("cls");
            controller_addEmployee(listaEmpleados);
            break;
        case 4:
            system("cls");
            break;
        case 5:
            system("cls");
            break;
        case 6:
            system("cls");
            controller_ListEmployee(listaEmpleados);
            break;
        case 7:
            system("cls");
            break;
        case 8:
            system("cls");
//            controller_saveAsText("salida.csv",listaEmpleados);
            break;
        case 9:
            system("cls");
            controller_saveAsBinary("salida.dat",listaEmpleados);
            break;
        case 10:
            ll_deleteLinkedList(listaEmpleados);
            break;
        default:
            printf("Ingrese una opcion valida \n");
            system("pause");
        }
    }
    while(option != 10);
    return 0;
}
