#include "ArrayEmployees.h"

int iniciarEmpleados (sEmpleado listado[], int tam)
{
    int i;
    for (i=0; i<tam; i++)
    {
        listado[i].vacio=1;
    }
    return 0;
}

void menuEmpleados(sEmpleado listado[], int tam)
{
    char opcion;
    char carga='N';
    do
    {
        system ("COLOR F0");
        system("cls");
        printf("\n         #############################################################");
        printf("\n         *                                                           *");
        printf("\n         *                 - Trabajo Practico Nro. 2 -               *");
        printf("\n         *                                                           *");
        printf("\n         *                 >> Nomina de Empleados <<                 *");
        printf("\n         *                                                           *");
        printf("\n         *                  x Silva Chauvie Martin x                 *");
        printf("\n         *                                                           *");
        printf("\n         #############################################################");
        printf("\n         |                                                           |");
        printf("\n             A - Altas");
        printf("\n         |                                                           |");
        printf("\n             M - Modificaciones");
        printf("\n         |                                                           |");
        printf("\n             B - Bajas");
        printf("\n         |                                                           |");
        printf("\n             I - Informes");
        printf("\n         |                                                           |");
        printf("\n             S - Salir");
        printf("\n         |                                                           |");
        printf("\n         xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
        printf("\n");
        printf("\n          Ingrese una opcion: ");
        opcion=getch();
        opcion=toupper(opcion);
        switch(opcion)
        {
        case 'A':
            system("cls");
            cargarLibre(listado,tam);
            carga='S';
            break;
        case 'M':
            if (carga=='S')
            {
                system("cls");
                modificarValor(listado, tam);
                break;
            }
            else
            {
                printf("No se han ingresado datos de empleados. \n ");
                system("pause");
                break;
            }
        case 'B':
            if (carga=='S')
            {
                system("cls");
                darBaja(listado, tam);
                break;
            }
            else
            {
                printf("No se han ingresado datos de empleados. \n ");
                system("pause");
                break;
            }
        case 'I':
            if (carga=='S')
            {
                system("cls");
                subMenuInformes(listado, tam);
                break;
            }
            else
            {
                printf("No se han ingresado datos de empleados. \n ");
                system("pause");
                break;
            }
        case 'S':
            break;
        default:
            printf("No es una opcion valida");
        }
    }
    while(opcion!='S');
}

void subMenuInformes(sEmpleado listado[], int tam)
{
    char opcion;
    do
    {
        system("cls");
        printf("\n         #############################################################");
        printf("\n         *                                                           *");
        printf("\n         *                                                           *");
        printf("\n         *                      >> Informes <<                       *");
        printf("\n         *                                                           *");
        printf("\n         *                                                           *");
        printf("\n         #############################################################");
        printf("\n         |                                                           |");
        printf("\n             O - Ordenar por apellido y sector");
        printf("\n         |                                                           |");
        printf("\n             S - Salarios");
        printf("\n         |                                                           |");
        printf("\n             R - Regresar");
        printf("\n         |                                                           |");
        printf("\n         xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
        printf("\n");
        printf("\n          Ingrese una opcion: ");
        opcion=getch();
        opcion=toupper(opcion);
        switch(opcion)
        {
        case 'O':
            system("cls");
            ordenarApellidos(listado, tam);
            break;
        case 'S':
            system("cls");
            compararSalarios(listado, tam);
            break;
        case 'R':
            break;
        default:
            printf("No es una opcion valida");
        }
    }
    while(opcion!='R');
}

sEmpleado agregarEmpleados()
{
    sEmpleado empleadoBase;
    char numero[10];
    int n;
    fflush(stdin);
    printf("Ingrese el nombre del empleado: ");
    gets(empleadoBase.nombre);
    fflush(stdin);
    validarNombre(empleadoBase);
    printf("Ingrese el apellido del empleado: ");
    gets(empleadoBase.apellido);
    fflush(stdin);
    validarApellido(empleadoBase);
    printf("Ingrese el salario del empleado: ");
    scanf("%f",&empleadoBase.salario);
    fflush(stdin);
    do
    {
        printf("Ingrese el sector al que pertenece: ");
        scanf("%s",numero);
        fflush(stdin);
        n=validarNumero(numero);
    }
    while(n==0);
    empleadoBase.sector=atoi(numero);
    empleadoBase.vacio=0;
    empleadoBase.id=cargarIDs();
    return empleadoBase;
}

int cargarIDs (void)
{
    static int IDEmpleado=0;

    IDEmpleado++;
return IDEmpleado;
}

int buscarLibre(sEmpleado listado[],int tam)
{
    int index=-1;
    int i;
    for(i=0; i<tam; i++)
    {
        if(listado[i].vacio==1)
        {
            index = i;
            break;
        }
    }
    return index;
}

void cargarLibre (sEmpleado listado[],int tam)
{
    int indice;
    char seguir='s';
    do
    {
        indice = buscarLibre(listado,tam);
        if(indice>=0)
        {
            listado[indice]=agregarEmpleados();
                }
        else
        {
            printf("Todos los IDs se encuentran actualmente en uso, no es posible cargar mas datos. ");
            system("pause");
            break;
        }

        printf("Desea ingresar otro? s / n \n");
        seguir=getch();
    }
    while(seguir=='s');
    correccionNombres(listado,tam);
    correccionApellidos(listado,tam);
}

void correccionNombres(sEmpleado listado[], int tam)
{
    int i;
    int j;
    for(i=0; i<tam; i++)
    {
        strlwr(listado[i].nombre);
    }
    for(i=0; i<tam; i++)
    {
        listado[i].nombre[0]=toupper(listado[i].nombre[0]);
        for(j=0; j<strlen(listado[i].nombre); j++)
        {
            if(listado[i].nombre[j]==' ')
            {
                listado[i].nombre[j+1]=toupper(listado[i].nombre[j+1]);
            }
        }
    }
}

void correccionApellidos(sEmpleado listado[], int tam)
{
    int i;
    int j;
    for(i=0; i<tam; i++)
    {
        strlwr(listado[i].apellido);
    }
    for(i=0; i<tam; i++)
    {
        listado[i].apellido[0]=toupper(listado[i].apellido[0]);
        for(j=0; j<strlen(listado[i].apellido); j++)
        {
            if(listado[i].apellido[j]==' ')
            {
                listado[i].apellido[j+1]=toupper(listado[i].apellido[j+1]);
            }
        }
    }
}

void modificarValor (sEmpleado listado[], int tam)
{
    mostrarEmpleados(listado,tam);
    int idaux;
    int i;
    char posicion;
    char validar;
    printf("ingrese el ID a buscar: ");
    scanf("%d", &idaux);
    for (i=0; i<tam; i++)
    {
        if(idaux == listado[i].id)
        {
            printf("%5s\t %5s\t %5s\t %5s\t %5s\t","ID","Nombre","Apellido","Salario", "Sector \n");
            mostrarEmpleado(listado[i]);
            printf("¿Desea modificar alguno de los parametros?  \n  s / n ");
            validar=getch();
            validar=tolower(validar);
            char numero[10];
            int n;
            if(validar=='s')
            {
                printf("¿Que parametro desea modificar?  \n  1 - Nombre \n 2 - Apellido \n 3 - Salario \n 4 - Sector \n ");
                posicion=getch();
                switch(posicion)
                {
                case '1':
                    fflush(stdin);
                    printf("Ingrese el nombre: ");
                    gets(listado[i].nombre);
                    validarNombre(listado[i]);
                    correccionNombres(listado,tam);

                    system("pause");
                    break;
                case '2':
                    fflush(stdin);
                    printf("Ingrese el apellido: ");
                    gets(listado[i].apellido);
                    validarApellido(listado[i]);
                    correccionApellidos(listado,tam);
                    system("pause");
                    break;
                case '3':
                    fflush(stdin);
                    printf("Ingrese el salario: ");
                    scanf("%f",&listado[i].salario);
                    fflush(stdin);
                    system("pause");
                    break;
                case '4':
                    do
                    {
                        fflush(stdin);
                        printf("Ingrese el sector: ");
                        scanf("%s",numero);
                        fflush(stdin);
                        n=validarNumero(numero);
                    }
                    while(n==0);
                    listado[i].sector=atoi(numero);
                    system("pause");
                    break;
                default:
                    printf("No existe esa opción. \n");
                    break;
                }
            }
            else
            {
                break;
            }

        }
    }
    correccionNombres(listado,tam);
    correccionApellidos(listado,tam);
}
void mostrarEmpleado(sEmpleado empleadoBase)
{
    if(empleadoBase.vacio==0)
    {
        printf("\n %4d\t %5s\t %5s\t %7.2f\t %7d\t \n", empleadoBase.id, empleadoBase.nombre, empleadoBase.apellido, empleadoBase.salario, empleadoBase.sector);
    }
}

void mostrarEmpleados(sEmpleado listado[], int tam)
{
    int i;
    printf("%5s\t %5s\t %5s\t %5s\t %5s\t","ID","Nombre","Apellido","Salario", "Sector \n");
    for (i=0; i<tam; i++)
    {
        if(listado[i].vacio!=1)
        {
            mostrarEmpleado(listado[i]);
        }
    }
    system("pause");
}

void darBaja (sEmpleado listado[], int tam)
{
    mostrarEmpleados(listado,tam);
    int idaux;
    int i;
    char validar;
    int flag=0;
    printf("ingrese el ID a dar de baja: ");
    scanf("%d", &idaux);
    for (i=0; i<tam; i++)
    {
        if(listado[i].vacio==0 && idaux == listado[i].id)
        {
            printf("%5s\t %5s\t %5s\t %5s\t %5s\t","ID","Nombre","Apellido","Salario", "Sector \n");
            mostrarEmpleado(listado[i]);
            printf("¿Desea dar de baja este empleado?  \n  s / n ");
            validar=getch();
            validar=tolower(validar);
            if(validar=='s')
            {
                flag=1;
                listado[i].vacio=1;
            }
        }
    }
    if(flag==0)
    {
        printf("No se encontro el ID");
    }
}

void ordenarApellidos(sEmpleado listado[],int tam)
{
    int i;
    int j;
    sEmpleado auxEmpleado;
    printf("\n Valores ordenados alfabeticamente: \n");
    printf("%5s\t %5s\t %5s\t %5s\t %5s\t","ID","Nombre","Apellido","Salario", "Sector \n");
    for (i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if (strcmp(listado[i].apellido, listado[j].apellido)==0)
            {
                if(listado[i].sector>listado[j].sector)
                {
                    auxEmpleado=listado[i];
                    listado[i]=listado[j];
                    listado[j]=auxEmpleado;
                }
            }
            else if (strcmp(listado[i].apellido, listado[j].apellido)>0)
            {
                auxEmpleado=listado[i];
                listado[i]=listado[j];
                listado[j]=auxEmpleado;
            }
        }
    }
    for (i=0; i<tam; i++)
    {
        mostrarEmpleado(listado[i]);
    }
    system("pause");
}

float calcularPromedio(sEmpleado listado [], int tam)
{
    int i;
    int contSalarios=0;
    float sumaSalarios=0;
    float promedioSalarios;
    for (i=0; i<tam; i++)
    {
        if(listado[i].vacio==0)
        {
            sumaSalarios=sumaSalarios+listado[i].salario;
            contSalarios++;
        }
    }
    promedioSalarios=sumaSalarios/contSalarios;
    printf("La suma de los salarios es de: %f \n el promedio total seria: %f \n", sumaSalarios, promedioSalarios);
    return promedioSalarios;
}

void compararSalarios (sEmpleado listado[], int tam)
{
    int i;
    int contAsalariados=0;
    float promedio;
    promedio=calcularPromedio(listado,tam);
    for(i=0; i<tam; i++)
    {
        if(listado[i].vacio==0 && listado[i].salario>promedio)
        {
            mostrarEmpleado(listado[i]);
            contAsalariados++;
        }
    }
    printf("La cantidad de empleados que superan el salario promedio es de: %d \n ", contAsalariados);

    system("pause");
}


void validarNombre (sEmpleado empleado)
{
    int i;
    for (i=0; i<strlen(empleado.nombre); i++)
    {
        if (empleado.nombre[i]==' ')
        {
            break;
        }
        while (!(isalpha(empleado.nombre[i])))
        {
            printf("Reingrese un nombre valido \n");
            gets(empleado.nombre);
            fflush(stdin);
        }
    }
}

void validarApellido (sEmpleado empleado)
{
    int i;
    for (i=0; i<strlen(empleado.apellido); i++)
    {
        if (empleado.apellido[i]==' ')
        {
            break;
        }
        while (!(isalpha(empleado.apellido[i])))
        {
            printf("Reingrese un apellido valido \n");
            gets(empleado.apellido);
            fflush(stdin);
        }
    }
}

int validarNumero (char valores[])
{
    int i;
    for(i=0; i<strlen(valores); i++)
    {
        if(!(isdigit(valores[i])))
        {
            printf("Reingrese un valor valido \n");
            getch();
            return 0;
        }
    }
    return 1;
}
