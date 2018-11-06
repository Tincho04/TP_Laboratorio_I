#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"


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
    if(parser_EmployeeFromText(pArchivo, pArrayListEmployee) == 0) //Esta devolviendo -1
    {
        printf("\n Apertura exitosa del Archivo tipo Texto.\n");
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
    if(pArchivo != NULL && parser_EmployeeFromBinary(pArchivo, pArrayListEmployee) == 0)
    {
        printf("\n Apertura exitosa del Archivo tipo Binario \n");
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

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;

    if(employee_altaEmployee(pArrayListEmployee) == 0)
    {
        printf("\n Empleado cargado exitosamente.\n");
        retorno = 0;
    }
    else
    {
        printf("\n Fallo en la carga del Empleado.\n");
    }

    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    employee_List(pArrayListEmployee);

    system("pause");
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo salida.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
/*int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)  FALTA CONCLUSION DE CERRADO
{
    FILE *parchivo;
    char texto[ ]="Prueba de escritura";
    int cant, longi;
    if((parchivo=fopen("salida.txt","r"))==NULL)
    {
        if((parchivo=fopen("salida.txt","w"))==NULL)
    {
        printf("\nEl archivo no puede ser abierto");
        exit (1);
    }
    longi=strlen (texto );
    cant=fwrite ( texto, sizeof ( char ), longi, parchivo );
    if (cant<longi)
        printf("\n Fallo en escritura de archivo");
    else
        printf("\nSe escribieron %d caracteres", cant);
        fclose(parchivo);
    }else
    Printf("Archivo previamente existente, imposible su escritura.");
    fclose(parchivo);
    return 1;
}
*/
/** \brief Guarda los datos de los empleados en el archivo salida.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE *parch;
if((parch=fopen("salida.dat","rb"))==NULL)
{
if((parch=fopen("salida.dat","wb"))==NULL)
{
printf("\nEl archivo no puede ser abierto");
exit (1);
}
fclose(parch);
}
 //   return 1;
}

