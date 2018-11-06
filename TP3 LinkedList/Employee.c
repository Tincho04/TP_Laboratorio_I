#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "string.h"
#include "Validaciones.h"

Employee* employee_new(void)
{
    return (Employee*) malloc(sizeof(Employee));
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* this = NULL;

    this = employee_new();
    if(this == NULL)
    {
        employee_delete(this);
        this = NULL;
    }
    return this;
}

int employee_delete(Employee* this)
{
    int retorno = -1;

    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

int employee_altaEmployee(LinkedList* pArrayEmployee)
{
    char auxNombre[1024];
    char auxID[1024] = "-1";
    int auxHoras;
    char bufferHorasTrabajadas[1024];
    int auxSueldo;
    char bufferSueldo[1024];
    Employee* auxPunteroEmployee;
    int retorno = -1;

    strcpy(auxNombre, getString("Ingrese nombre del empleado: ", 30));
    auxHoras = getInt("Ingrese horas trabajadas: ");
    auxSueldo = getInt("Ingrese sueldo: ");

    itoa(auxHoras, bufferHorasTrabajadas, 10);
    itoa(auxSueldo, bufferSueldo, 10);
    auxPunteroEmployee = employee_newParametros(auxID, auxNombre, bufferHorasTrabajadas, bufferSueldo);

    if(auxPunteroEmployee != NULL)
    {
        ll_add(pArrayEmployee, auxPunteroEmployee);
        retorno = 0;
    }

    return retorno;
}

int employee_setName(Employee* this, char* nombre)
{
    int retorno = -1;

    if(this != NULL && strlen(nombre) >= 3)
    {
        strcpy(this->nombre,nombre);
        retorno = 0;
    }
    return retorno;
}

int employee_getName(Employee* this, char* nombre)
{
    int retorno = -1;

    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre,this->nombre);
        retorno = 0;
    }
    return retorno;
}

int employee_setHours(Employee* this, char* horasTrabajadas)
{
    int retorno = -1;

    if(this != NULL && isValidHours(horasTrabajadas) == 0)
    {
        this->horasTrabajadas =  atoi(horasTrabajadas);
        retorno = 0;
    }
    return retorno;
}

int employee_getHours(Employee* this, int* horasTrabajadas)
{
    int retorno = -1;

    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}

int isValidHours(char* horasTrabajadas)
{
    int retorno = -1;

    if(isInt(horasTrabajadas) == -1)
    {
        printf("Las horas trabajadas son invalidas");
    }
    else
    {
        retorno = 0;
    }

    return retorno;
}

int employee_setSalary(Employee* this, char* sueldo)
{
    int retorno = -1;

    if(this != NULL && isValidSalary(sueldo))
    {
        this->sueldo = atoi(sueldo);
        retorno = 0;
    }
    return retorno;
}

int employee_getSalary(Employee* this, int* sueldo)
{
    int retorno = -1;

    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        retorno = 0;
    }
    return retorno;
}

int isValidSalary(char* sueldo)
{
    int retorno = -1;

    if(isInt(sueldo) == -1)
    {
        printf("El sueldo ingresado es invalido");
    }
    else
    {
        retorno = 0;
    }

    return retorno;
}

int employee_setId(Employee* this, char* id)
{
    int siguienteId = -1;
    int auxId;
    int retorno = -1;

    atoi(id);
    if(this != NULL && isValidId(id) == 0)
    {
        auxId = atoi(id);
        if(auxId == -1)
        {
            siguienteId++;
            this->id = siguienteId;
            retorno = 0;
        }
        else if(auxId > siguienteId)
        {
            siguienteId = auxId;
            this->id = siguienteId;
            retorno = 0;
        }
    }
    return retorno;
}

int employee_getId(Employee* this, int* id)
{
    int retorno = -1;

    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}


int isValidId(char* id)
{
    int retorno = -1;

    if(isIntConGuiones(id) == -1)
    {
        printf("\El id es invalido");
    }
    else
    {
        retorno = 0;
    }
    return retorno;
}

/*void employee_List(LinkedList* pArrayListEmployee)    FALTA VALIDAR DIMENSIONES DEL FOR
{
int i;
int size=ll_len(pArrayListEmployee);
for (i=0;i<size;i++)
    {
        if(pArrayListEmployee[i]!=NULL)
            {
            employee_List(pArrayListEmployee[i]);
            }
    }
}
*/
void employee_List(LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;
    int auxId;
    char auxNombre[50];
    int auxHoras;
    int auxSueldo;
    int size;
    int i;

    size = ll_len(pArrayListEmployee);
    if(size > 0)
    {
        printf("ID      Nombre     Horas trabajadas       Sueldo\n");
        for(i=0; i < size; i++)
        {
            auxEmployee = ll_get(pArrayListEmployee, i);
            if( employee_getId(auxEmployee, &auxId) == 0 && employee_getName(auxEmployee, auxNombre) == 0 &&
                employee_getHours(auxEmployee, &auxHoras) == 0 &&
                employee_getSalary(auxEmployee, &auxSueldo) == 0)
            {
                printf("%4d %20s %3d %6d\n", auxId, auxNombre, auxHoras, auxSueldo);
            }
        }
        printf("\nLa cantidad de empleados es de: %d.", size);
    }
    else
    {
        printf("\n Fallo en carga de lista.\n");
    }
}
