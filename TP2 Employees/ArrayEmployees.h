#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#define A 999
#define S 51

typedef struct
{
    int id;
    char nombre[S];
    char apellido[S];
    float salario;
    int sector;
    int vacio;
} sEmpleado;

/** \brief Inicializa el valor vacio en la estructura de empleados
 *
 * \param sEmpleado[]
 * \param int
 * \return int
 *
 */
int iniciarEmpleados(sEmpleado[], int);
/** \brief Muestra el menu principal
 *
 * \param sEmpleado[]
 * \param int
 * \return void
 *
 */
void menuEmpleados(sEmpleado[], int);
/** \brief Permite el agregado de datos de un empleado
 *
 * \return sEmpleado
 *
 */
sEmpleado agregarEmpleados();
/** \brief Submenu que muestra los informes disponibles
 *
 * \param sEmpleado[]
 * \param int
 * \return void
 *
 */
void subMenuInformes(sEmpleado[],int);
/** \brief Busca aquellos espacios en los que se pueda cargar algun dato
 *
 * \param sEmpleado[]
 * \param int
 * \return int
 *
 */
int buscarLibre(sEmpleado[],int);
/** \brief Permite la carga de datos siempre y cuando el valor se haya devuelto vacio
 *
 * \param sEmpleado[]
 * \param int
 * \return int
 *
 */
void cargarLibre (sEmpleado[],int);
/** \brief Corrección del string de nombre corrigiendo minusculas y mayusculas
 *
 * \param sEmpleado[]
 * \param int
 * \return void
 *
 */
void correccionNombres(sEmpleado[], int);
/** \brief Corrección del string de apellidos corrigiendo minusculas y mayusculas
 *
 * \param sEmpleado[]
 * \param int
 * \return void
 *
 */
void correccionApellidos(sEmpleado[], int);
/** \brief Carga de un valor numerico el ID de forma automatica
 *
 * \param sEmpleado[]
 * \param int
 * \return void
 *
 */
int cargarIDs(void);
/** \brief Permite la modificacion de algun valor en los datos del empleado por medio de su ID
 *
 * \param sEmpleado[]
 * \param void
 * \return int
 *
 */
void modificarValor (sEmpleado[], int);
/** \brief Muestra los datos de un empleado
 *
 * \param sEmpleado
 * \return void
 *
 */
void mostrarEmpleado(sEmpleado);
/** \brief Por medio de una iteración permite mostrar un listado de todos los empleados cargados
 *
 * \param sEmpleado[]
 * \param int
 * \return void
 *
 */
void mostrarEmpleados(sEmpleado[], int);
/** \brief Permite la dada de baja de algun empleado previamente registrado
 *
 * \param sEmpleado[]
 * \param int
 * \return void
 *
 */
void darBaja (sEmpleado[], int);
/** \brief Ordena alfabeticamente por apellido
 *
 * \param sEmpleado[]
 * \param int
 * \return void
 *
 */
void ordenarApellidos(sEmpleado[],int);
/** \brief Calcula la suma y el promedio de los salarios
 *
 * \param sEmpleado[]
 * \param int
 * \return float
 *
 */
float calcularPromedio(sEmpleado[], int);
/** \brief Compara el salario de cada empleado con el promedio
 *
 * \param sEmpleado[]
 * \param int
 * \return void
 *
 */
void compararSalarios (sEmpleado[], int);
/** \brief Valida que el nombre ingresado posea unicamente caracteres del tipo letra
 *
 * \param sEmpleado
 * \return void
 *
 */
void validarNombre (sEmpleado);
/** \brief  Valida que el apellido ingresado posea unicamente caracteres del tipo letra
 *
 * \param sEmpleado
 * \return void
 *
 */
void validarApellido (sEmpleado);
/** \brief Valida en una cadena de caracteres que todos los valores sean numericos y los devuelve como un entero
 *
 * \param char []
 * \return int
 *
 */
int validarNumero (char[]);

#endif // ARRAYEMPLOYEES_H_INCLUDED
