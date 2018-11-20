#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "LinkedList.h"
#include "Employee.h"
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto)
 *
 * \param pFile FILE* Es el archivo donde se encuentran los empleados(abierto en modo lectura(r))
 * \param pArrayListEmployee LinkedList* Es la LinkedList donde se guardan los empleados cargados
 * \return int retorna 0 si el archivo se cargo correctamente, y 1 si no se pudo cargar.
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    char bufferId[1024];
    int lastId;
    char bufferNombre[1024];
    char bufferHorasTrabajadas[1024];
    char bufferSueldo[1024];
    int retorno = -1;
    int flagOnce = 1;
    int i;
    Employee* pEmpleado;
    if(pFile!=NULL)
    {
        while(!feof(pFile))
        {
            if(flagOnce)
            {
                flagOnce = 0;
                fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",
                                                        bufferId,
                                                        bufferNombre,
                                                        bufferHorasTrabajadas,
                                                        bufferSueldo);
            }
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",
                                                    bufferId,
                                                    bufferNombre,
                                                    bufferHorasTrabajadas,
                                                    bufferSueldo);
            pEmpleado = employee_newConParametros(  bufferId,
                                                    bufferNombre,
                                                    128,
                                                    bufferHorasTrabajadas,
                                                    bufferSueldo);
            if(pEmpleado != NULL)
            {
                retorno = 0;
                ll_add(pArrayListEmployee, pEmpleado);
                lastId = atoi(bufferId);
            }
        }
        for(i=0;i<=lastId;i++)
        {
            employee_getNextId();
        }
    }
    return retorno;
}
/** \brief Carga los datos de los empleados desde el archivo data.bin (modo binario)
 *
 * \param pFile FILE* Es el archivo donde se encuentran los empleados(abierto en modo lectura binaria(rb))
 * \param pArrayListEmployee LinkedList* Es la LinkedList donde se guardan los empleados cargados
 * \return int retorna 0 si el archivo se cargo correctamente, y 1 si no se pudo cargar.
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i;
    Employee* pEmpleado;
    int bufferId;
    int lastId;
    char bufferNombre[128];
    int bufferHorasTrabajadas;
    int bufferSueldo;
    if(pFile!=NULL)
    {
        retorno = 0;
        while(!feof(pFile))
        {
            pEmpleado = employee_new();
            fread(pEmpleado,sizeof(Employee),1,pFile);
            employee_getId(pEmpleado,&bufferId);
            employee_getNombre(pEmpleado,bufferNombre);
            employee_getHorasTrabajadas(pEmpleado,&bufferHorasTrabajadas);
            employee_getSueldo(pEmpleado,&bufferSueldo);
            if( bufferId >= 0 && strlen(bufferNombre) > 0 &&
                bufferHorasTrabajadas > 0 && bufferSueldo > 0)
            {
                ll_add(pArrayListEmployee, pEmpleado);
                lastId = bufferId;
            }
        }
        for(i=0;i<=lastId;i++)
        {
            employee_getNextId();
        }
    }
    return retorno;
}
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto)
 *
 * \param pFile FILE* Es el archivo donde se guardan los empleados(abierto en modo escritura(w))
 * \param pArrayListEmployee LinkedList* Es la LinkedList donde se encuentran los empleados.
 * \return int retorna 0 si el archivo se guardo correctamente, y 1 si no se pudo guardar.
 *
 */
int parser_saveAsText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* pEmpleado;
    int i;
    int bufferId;
    char bufferNombre[128];
    int bufferHorasTrabajadas;
    int bufferSueldo;
    if(pFile != NULL)
    {
        retorno = 0;
        fprintf(pFile,"id,nombre,horasTrabajadas,sueldo");
        for(i=0;i<ll_len(pArrayListEmployee);i++)
        {
            pEmpleado = ll_get(pArrayListEmployee,i);
            employee_getId(pEmpleado,&bufferId);
            employee_getNombre(pEmpleado,bufferNombre);
            employee_getHorasTrabajadas(pEmpleado,&bufferHorasTrabajadas);
            employee_getSueldo(pEmpleado,&bufferSueldo);
            if( bufferId >= 0 && strlen(bufferNombre) > 0 &&
                bufferHorasTrabajadas > 0 && bufferSueldo > 0)
            {
                fprintf(pFile,"\n%d,%s,%d,%d",  bufferId,bufferNombre,
                                                bufferHorasTrabajadas,
                                                bufferSueldo);
            }
        }
    }
    return retorno;
}
/** \brief Guarda los datos de los empleados en el archivo data.bin (modo binario)
 *
 * \param pFile FILE* Es el archivo donde se guardan los empleados(abierto en modo escritura binaria(wb))
 * \param pArrayListEmployee LinkedList* Es la LinkedList donde se encuentran los empleados.
 * \return int retorna 0 si el archivo se guardo correctamente, y 1 si no se pudo guardar.
 *
 */
int parser_saveAsBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* pEmpleado;
    int i;
    int bufferId;
    char bufferNombre[128];
    int bufferHorasTrabajadas;
    int bufferSueldo;
    if(pFile != NULL)
    {
        retorno = 0;
        for(i=0;i<ll_len(pArrayListEmployee);i++)
        {
            pEmpleado = ll_get(pArrayListEmployee,i);
            employee_getId(pEmpleado,&bufferId);
            employee_getNombre(pEmpleado,bufferNombre);
            employee_getHorasTrabajadas(pEmpleado,&bufferHorasTrabajadas);
            employee_getSueldo(pEmpleado,&bufferSueldo);
            if( bufferId >= 0 && strlen(bufferNombre) > 0 &&
                bufferHorasTrabajadas > 0 && bufferSueldo > 0)
            {
                fwrite(pEmpleado,sizeof(Employee),1,pFile);
            }
        }
    }
    return retorno;
}
