#include <stdio_ext.h>
#include <stdlib.h>
#include "string.h"
#include "LinkedList.h"
#include "parser.h"
#include "Controller.h"
#include "utn.h"
#include "Employee.h"
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
                "10. Salir\n");
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
                break;
            default:
                printf("Opcion Incorrecta\n");
                break;
        }
        printf("\nPulse Enter para continuar");
        __fpurge(stdin);
        getchar();
    }while(option != 10);
    return 0;

}



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
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

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
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

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    return employee_add(pArrayListEmployee);
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
 //intentar hacerlo un poco mas copado
 //le mostras lo q tiene cada campo y si lo quiere cambiar
 //le muestra el nuevo y el viejo, y que confirme si desea cambiar
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
 //ll_remove hace la baja fisica, pero  no es obligatorio usarla???
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
    return employee_list(pArrayListEmployee);
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
    return employee_sort(pArrayListEmployee);
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
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

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
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
