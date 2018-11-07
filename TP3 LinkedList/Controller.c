#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "controller.h"
#include "Validaciones.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int retorno = -1;

    pArchivo = fopen(path,"r");
    if(!parser_EmployeeFromText(pArchivo, pArrayListEmployee))
    {
        printf("\n La carga de datos del Archivo tipo Texto se realizo efectivamente.\n");
        retorno = 0;
    }
    else
    {
        printf("\n Archivo de Texto no encontrado.\n");
    }
    fclose(pArchivo);
    system("pause");
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int retorno = -1;

    pArchivo = fopen(path, "rb");
    if(!parser_EmployeeFromBinary(pArchivo, pArrayListEmployee))
    {
        printf("\n La carga de datos del Archivo tipo Binario se realizo efectivamente. \n");
        retorno = 0;
    }
    else
    {
        printf("\n Archivo Binario no encontrado.\n");
    }
    fclose(pArchivo);
    system("pause");
    return retorno;
}

/** \brief Alta de empleados.
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int sueldo;
    int horasTrabajadas;
    char nombre[51];

    if(!getName(nombre,51,"Ingrese el nombre: ","Reingrese el nombre: ",2)&&
    !getInt(&horasTrabajadas,"\nIngrese las horas: ","Reingrese las horas: ",0,99999,2)&&
    !getInt(&sueldo,"\nIngrese el sueldo: ","Reingrese el sueldo: ",0,99999,2)
    )
    {
        Employee* empleado = employee_IdGen(nombre,horasTrabajadas,sueldo);
        if(empleado != NULL)
        {
            retorno = ll_add(pArrayListEmployee,empleado);
        }
    }

    return retorno;
}

/** \brief Modificar datos de empleado.
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i;
    int id, idAux;
    Employee* empleado;
    int sueldo;
    int horasTrabajadas;
    char nombre[51];
    char option='n';
    int opcionM=0;

    printf("Desea ver la lista de empleados?");
    scanf("%s", &option);
    fflush(stdin);
    if(option=='s')
    {
        controller_ListEmployee(pArrayListEmployee);
    }

    if(pArrayListEmployee != NULL)
    {
        if(!getInt(&id,"Ingrese el ID del empleado a modificar: ","Reingrese un numero valido",0,99999,2))
        {
            for(i = 0;i< ll_len(pArrayListEmployee);i++)
            {
               empleado = ll_get(pArrayListEmployee,i);
               employee_getId(empleado,&idAux);
               if(idAux == id)
               {
                   printf("Elija que campo desea modificar:\n 1- Nombre \n 2- Horas de trabajo \n 3- Sueldo \n");
                   scanf("%d", &opcionM);
                   switch(opcionM)
                   {
                   case 1:
                    if(!getName(nombre,51,"Ingrese el nuevo nombre: ","Reingrese un nombre valido",2))
                    {
                        if(
                            !employee_setName(empleado, nombre))
                          {
                            retorno = 0;
                            break;
                          }
                    }
                    else{
                        break;
                    }
                   case 2:
                    if(!getInt(&horasTrabajadas,"Ingrese las nuevas horas: ","Reingrese un numero valido",0,99999,2))
                    {
                        if(!employee_setHours(empleado, horasTrabajadas))
                        {
                            retorno=0;
                            break;
                        }
                    }
                    else{
                        break;
                    }
                   case 3:
                    if(!getInt(&sueldo,"Ingrese el nuevo sueldo: ","Reingrese un numero valido",0,99999,2))
                    {
                        if(!employee_setSalary(empleado, sueldo))
                        {
                            retorno=0;
                            break;
                        }
                    }
                    else{
                        break;
                    }
                   default: printf("Opcion invalida");
                   }
               }
            }
        }

    }
    return retorno;
}

/** \brief Baja de empleado.
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i;
    int id, idAux;
    Employee* empleado;

    if(pArrayListEmployee != NULL)
    {
        if(!getInt(&id,"Ingrese el ID del empleado a borrar: ","Ingrese un ID valido",0,99999,2))
        {
            for(i = 0;i< ll_len(pArrayListEmployee);i++)
            {
               empleado = ll_get(pArrayListEmployee,i);
               employee_getId(empleado,&idAux);

               if(idAux == id)
               {
                    employee_delete(empleado);
                    ll_remove(pArrayListEmployee,i);
                    retorno = 0;
                    break;
               }
            }
        }

    }
    return retorno;
}

/** \brief Listar empleados.
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i;
    char nombre[128];
    int id;
    int sueldo;
    int horasTrabajadas;
    Employee* auxPunteroEmpleado;

    if(pArrayListEmployee != NULL)
    {
        retorno = 0;
        for(i=0;i < ll_len(pArrayListEmployee);i++)
        {
             if(i%252==0)
            {
                system("pause");
            }
            else
            {
            auxPunteroEmpleado = ll_get(pArrayListEmployee,i);
            employee_getId(auxPunteroEmpleado,&id);
            employee_getName(auxPunteroEmpleado,nombre);
            employee_getSalary(auxPunteroEmpleado,&sueldo);
            employee_getHours(auxPunteroEmpleado,&horasTrabajadas);

            printf("\nID: %d",id);
            printf("\nNombre: %s",nombre);
            printf("\nSueldo: %d",sueldo);
            printf("\nHoras trabajadas: %d",horasTrabajadas);
            printf("\n");
            }
        }
    }
    system("pause");
    return retorno;
}

/** \brief Ordenar empleados.
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;

    if(pArrayListEmployee != NULL)
    {
        printf("Realizando reordenamiento alfabetico\n");
        if(!ll_sort(pArrayListEmployee,employee_sortByName,1))
        {
            controller_ListEmployee(pArrayListEmployee);
            retorno = 0;
        }
    }

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo salida.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo = fopen(path,"w");
    int retorno = -1;

    if(pArchivo != NULL && !parser_SaveToText(pArchivo,pArrayListEmployee))
    {
        printf("\n El grabado de datos en formato texto ha sido un exito.\n");
        retorno = 0;
    }
    fclose(pArchivo);
    system("pause");
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo salida.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo = fopen(path,"wb");
    int retorno = -1;
    if(pArchivo != NULL && !parser_SaveToBinary(pArchivo,pArrayListEmployee))
    {
        printf("\n El grabado de datos en formato binario ha sido un exito.\n");
        retorno = 0;
    }
    fclose(pArchivo);
    system("pause");
    return retorno;
}

