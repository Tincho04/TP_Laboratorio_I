#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
} Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
int employee_delete();

int employee_setId(Employee* this,char* id);
int employee_getId(Employee* this,int* id);
int isValidId(char* id);

int employee_setName(Employee* this,char* nombre);
int employee_getName(Employee* this,char* nombre);

int employee_setHours(Employee* this,char* horasTrabajadas);
int employee_getHours(Employee* this,int* horasTrabajadas);
int isValidHours(char* horasTrabajadas);

int employee_setSalary(Employee* this,char* sueldo);
int employee_getSalary(Employee* this,int* sueldo);
int isValidSalary(char* sueldo);

void employee_List(LinkedList* pArrayListEmployee);
int employee_altaEmployee(LinkedList* pArrayEmployee);
#endif // employee_H_INCLUDED
