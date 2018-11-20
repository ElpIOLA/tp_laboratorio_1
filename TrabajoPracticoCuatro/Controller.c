#include <stdio_ext.h>
#include <stdlib.h>
#include "string.h"
#include "LinkedList.h"
#include "parser.h"
#include "Controller.h"
#include "utn.h"
#include "Employee.h"
/**
* \brief Inicializa el programa y muestra el menu principal
*
*/
int controller_init()
{
    int option;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        system("clear");
        printf( "1. Carga de empleados (modo texto)\n"
                "2. Carga de empleados (modo binario)\n"
                "3. Alta empleado\n"
                "4. Modificar empleado\n"
                "5. Baja empleado\n"
                "6. Listar empleados\n"
                "7. Ordenar empleados\n"
                "8. Guardar empleados (modo texto)\n"
                "9. Guardar empleados (modo binario)\n"
                "10. Borrar todos los empleados\n"
                "11. Borrar lista y salir\n"
                "12. Filtrar Por Sueldo Maximo\n"
                "13. Filtrar Por Sueldo Minimo\n"
                "14. Salir\n");
        option = 0;
        utn_getEntero(&option, 5, "Seleccione...\n", "", 0);
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
            case 2:
                controller_loadFromBinary("data.bin",listaEmpleados);
                break;
            case 3:
                controller_addEmployee(listaEmpleados);
                break;
            case 4:
                controller_editEmployee(listaEmpleados);
                break;
            case 5:
                controller_removeEmployee(listaEmpleados);
                break;
            case 6:
                controller_ListEmployee(listaEmpleados);
                break;
            case 7:
                controller_sortEmployee(listaEmpleados);
                break;
            case 8:
                controller_saveAsText("data.csv",listaEmpleados);
                break;
            case 9:
                controller_saveAsBinary("data.bin",listaEmpleados);
                break;
            case 10:
                controller_deleteAllEmployees(listaEmpleados);
                break;
            case 11:
                if(!controller_deleteList(listaEmpleados))
                {
                    option = 14;
                }
                break;
            case 12:
                controller_filterBySalaryMax(listaEmpleados);
                break;
            case 13:
                controller_filterBySalaryMin(listaEmpleados);
                break;
            case 14:
                break;
            default:
                printf("Opcion Incorrecta\n");
                break;
        }
        printf("\nPulse Enter para continuar");
        __fpurge(stdin);
        getchar();
    }while(option != 14);
    return 0;
}
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto)
 *
 * \param path char* Es el path donde se encuentra el archivo
 * \param pArrayListEmployee LinkedList* Es la LinkedList donde se guardan los empleados cargados
 * \return int retorna 0 si el archivo se cargo correctamente, y -1 si no se pudo cargar.
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* pFile;
    pFile = fopen(path,"r");
    if(!parser_EmployeeFromText(pFile,pArrayListEmployee))
    {
        printf("\nArchivo cargado");
        retorno = 0;
    }
    fclose(pFile);
    return retorno;
}
/** \brief Carga los datos de los empleados desde el archivo data.bin (modo binario)
 *
 * \param path char* Es el path donde se encuentra el archivo
 * \param pArrayListEmployee LinkedList* Es la LinkedList donde se guardan los empleados cargados
 * \return int retorna 0 si el archivo se cargo correctamente, y -1 si no se pudo cargar.
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* pFile;
    pFile = fopen(path,"rb");
    if(!parser_EmployeeFromBinary(pFile,pArrayListEmployee))
    {
        printf("\nArchivo cargado");
        retorno = 0;
    }
    fclose(pFile);
    return retorno;
}
/** \brief Realiza el alta de un nuevo empleado, agregandolo al final de la LinkedList.
 *
 * \param pArrayListEmployee LinkedList* Es la LinkedList donde se guarda el nuevo empleado.
 * \return retorna 0 si el empleado se cargo correctamente, y -1 si no se pudo cargar.
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno;
    retorno = employee_add(pArrayListEmployee);
    if(!retorno)
    {
        printf("\nLos datos han sido cargados correctamente");
    }
    else
    {
        printf("\nNo se pudo cargar el empleado");
    }
    return retorno;
}

/** \brief Edita un empleado seleccionado a traves de un Id.
 *
 * \param pArrayListEmployee LinkedList* Es la LinkedList donde se encuentran los empleados.
 * \return retorna 0 si el empleado se edito correctamente, y -1 si no se pudo editar.
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno;
    retorno = employee_edit(pArrayListEmployee);
    if(!retorno)
    {
        printf("\nEl empleado fue editado");
    }
    else
    {
        printf("\nNo se edito el empleado");
    }
    return retorno;
}
/** \brief Realiza la baja de un nuevo empleado, seleccionado a traves de un Id.
 *
 * \param pArrayListEmployee LinkedList* Es la LinkedList donde se encuentran los empleados.
 * \return retorna 0 si el empleado se borro correctamente, y -1 si no se pudo borrar.
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno;
    retorno = employee_remove(pArrayListEmployee);
    if(!retorno)
    {
        printf("\nEl empleado fue dado de baja");
    }
    else
    {
        printf("\nNo se pudo dar de baja el empleado");
    }
    return retorno;
}
/** \brief  Lista todos los empleados de un LinkedList con toda su info
 *          (Id, Nombre, Horas Trabajadas, Sueldo)
 * \param pArrayListEmployee LinkedList* Es la LinkedList donde se encuentran los empleados.
 * \return retorna 0 si el empleado se mostro correctamente, y -1 si no se pudo mostrar.
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno;
    retorno = employee_list(pArrayListEmployee);
    if(retorno != 0)
    {
        printf("\nNo se pudo mostrar la informacion");
    }
    return retorno;

}
/** \brief  Ordena todos los empleados de un LinkedList seleccionando el criterio de orden.
 *
 * \param pArrayListEmployee LinkedList* Es la LinkedList donde se encuentran los empleados.
 * \return retorna 0 si se realizo el ordenamiento correctamente, y -1 si no se pudo ordenar.
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno;
    retorno = employee_sort(pArrayListEmployee);
    if(!retorno)
    {
        printf("\nOrdenamiento realizado correctamente");
    }
    else
    {
        printf("\nNo se realizo el ordenamiento");
    }
    return retorno;
}
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto)
 *
 * \param path char* Es el path donde se guarda el archivo.
 * \param pArrayListEmployee LinkedList* Es la LinkedList donde se encuentran los empleados.
 * \return int retorna 0 si el archivo se guardo correctamente, y -1 si no se pudo guardar.
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* pFile;
    pFile = fopen(path,"w");
    if(!parser_saveAsText(pFile,pArrayListEmployee))
    {
        printf("\nArchivo guardado");
        retorno = 0;
    }
    fclose(pFile);
    return retorno;
}
/** \brief Guarda los datos de los empleados en el archivo data.bin (modo binario)
 *
 * \param path char* Es el path donde se guarda el archivo.
 * \param pArrayListEmployee LinkedList* Es la LinkedList donde se encuentran los empleados.
 * \return int retorna 0 si el archivo se guardo correctamente, y -1 si no se pudo guardar.
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* pFile;
    pFile = fopen(path,"wb");
    if(!parser_saveAsBinary(pFile,pArrayListEmployee))
    {
        printf("\nArchivo guardado");
        retorno = 0;
    }
    fclose(pFile);
    return retorno;
}
/** \brief Borra todos los empleados de la lista pero no elimina la lista
 *
 * \param this LinkedList* Es la LinkedList donde se encuentran los empleados.
 * \return int retorna 0 si se borraron todos los empleados, -1 si no
 *
 */
int controller_deleteAllEmployees(LinkedList* this)
{
    int retorno = -1;
    if(!employee_deleteAll(this))
    {
        printf("\nSe han eliminado todos los empleados");
        retorno = 0;
    }
    return retorno;
}
/** \brief Borra todos los empleados de la lista y la lista donde se encuentran
 *
 * \param this LinkedList* Es la LinkedList donde se encuentran los empleados.
 * \return int retorna 0 si se borraron todos los empleados y la lista, -1 si no
 *
 */
int controller_deleteList(LinkedList* this)
{
    int retorno = -1;
    if(!employee_deleteList(this))
    {
        printf("\nSe han eliminado todos los empleados y la lista");
        retorno = 0;
    }
    return retorno;
}
/** \brief Filtra los empleados por un salario maximo
 *
 * \param this LinkedList* Es la LinkedList donde se encuentran los empleados.
 * \return int retorna 0 si se realizo el filtrado correctamente, -1 si no.
 *
 */
int controller_filterBySalaryMax(LinkedList* this)
{
    int retorno = -1;
    if(!employee_filterBySalaryMax(this))
    {
        retorno = 0;
    }
    return retorno;
}
/** \brief Filtra los empleados por un salario minimo
 *
 * \param this LinkedList* Es la LinkedList donde se encuentran los empleados.
 * \return int retorna 0 si se realizo el filtrado correctamente, -1 si no.
 *
 */
int controller_filterBySalaryMin(LinkedList* this)
{
    int retorno = -1;
    if(!employee_filterBySalaryMin(this))
    {
        retorno = 0;
    }
    return retorno;
}

