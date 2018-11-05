#include "Employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
/**
* \brief Evalua si se trata de un id valido
* \param pBuffer Es la cadena que evaluamos
* \param limite Es el numero maximo de cifras
* \return En caso de exito retorna 1, si no 0
*
*/
static int isValidId(char *pBuffer, int limite)
{
    int retorno;
    retorno = utn_isValidEnteroSoloNumeros(pBuffer,limite);
    return retorno;
}
/**
* \brief    Evalua si es un nombre valido
* \param pBuffer Es la cadena que evaluamos
* \param limite Es el tamano maximo del string
* \return En caso de exito retorna 1, si no 0
*
*/
static int isValidNombre(char *pBuffer, int limite)
{
    int retorno = -1;
    retorno = utn_isValidNombre(pBuffer,limite);
    return retorno;
}
/**
* \brief Evalua si se trata de una cantidad de horas trabajada valida
* \param pBuffer Es la cadena que evaluamos
* \param limite Es el numero maximo de cifras
* \return En caso de exito retorna 1, si no 0
*
*/
static int isValidHorasTrabajadas(char *pBuffer, int limite)
{
    int retorno;
    retorno = utn_isValidEnteroSoloNumeros(pBuffer,limite);
    return retorno;
}
/**
* \brief Evalua si se trata de un sueldo valido
* \param pBuffer Es la cadena que evaluamos
* \param limite Es el numero maximo de cifras
* \return En caso de exito retorna 1, si no 0
*
*/
static int isValidSueldo(char *pBuffer, int limite)
{
    int retorno;
    retorno = utn_isValidEnteroSoloNumeros(pBuffer,limite);
    return retorno;
}

int employee_getNextId()
{
    static int ultimoId = -1;
    ultimoId++;
    return ultimoId;
}
int employee_getById(LinkedList* pArrayListEmployee, int* index)
{
    int retorno = -1;
    int id;
    if(pArrayListEmployee != NULL)
    {
        employee_list(pArrayListEmployee);
        if( !utn_getEntero(&id, 10, "\nIntroduzca el Id: ", "", 0) &&
            !employee_getIndexById(pArrayListEmployee, id, index))
        {
            retorno = 0;
        }
    }
    return retorno;

}
int employee_getIndexById(LinkedList* pArrayListEmployee,int id, int* index)
{
    int retorno = -1;
    Employee* pEmpleado;
    int bufferId;
    int i;
    if(pArrayListEmployee != NULL)
    {
        for(i=0;i < ll_len(pArrayListEmployee);i++)
        {
            pEmpleado = ll_get(pArrayListEmployee,i);
            employee_getId(pEmpleado,&bufferId);
            if(bufferId == id)
            {
                *index = ll_indexOf(pArrayListEmployee, pEmpleado);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}


int employee_setId(Employee* this,int id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->id=id;
        retorno=0;
    }
    return retorno;
}

int employee_getId(Employee* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id = this->id;
        retorno=0;
    }
    return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno = -1;
    if(this!=NULL)
    {
        this->sueldo=sueldo;
        retorno = 0;
    }
    return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno = -1;
    if(this!=NULL)
    {
        *sueldo=this->sueldo;
        retorno = 0;
    }
    return retorno;
}
int employee_showInfo(Employee* this)
{
    int retorno = -1;
    int bufferId;
    char bufferNombre[128];
    int bufferHorasTrabajadas;
    int bufferSueldo;
    if(this!=NULL)
    {
        employee_getId(this, &bufferId);
        employee_getNombre(this, bufferNombre);
        employee_getHorasTrabajadas(this, &bufferHorasTrabajadas);
        employee_getSueldo(this, &bufferSueldo);
        printf( "\nId: %d - Nombre: %s - Horas: %d - Sueldo: %d",
                bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);
        retorno = 0;
    }
    return retorno;
}
Employee* employee_new()
{
    Employee* this;
    this = malloc(sizeof(Employee));
    return this;
}
int employee_delete(Employee* this)
{
    int retorno = -1;
    if(this!=NULL)
    {
        free((void*)this);
        retorno = 0;
    }
    return retorno;
}

Employee* employee_newConParametros(char* idString,char* nombre,int lenNombre,
                                    char* horasTrabajadasString,char* sueldoString)
{
    Employee* this;
    this = employee_new();
    Employee* retorno = NULL;
    int idInt = atoi(idString);
    int horasTrabajadasInt = atoi(horasTrabajadasString);
    int sueldoInt = atoi(sueldoString);
    if( isValidId(idString,20) &&
        isValidNombre(nombre,lenNombre) &&
        isValidHorasTrabajadas(horasTrabajadasString,20) &&
        isValidSueldo(sueldoString,20) &&
        !employee_setId(this,idInt)&&
        !employee_setNombre(this,nombre)&&
        !employee_setHorasTrabajadas(this,horasTrabajadasInt)&&
        !employee_setSueldo(this,sueldoInt))
    {
        retorno = this;
    }
    else
    {
        employee_delete(this);
    }
    return retorno;
}
int employee_add(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* pEmpleado;
    char bufferIdString[20];
    int bufferIdInt;
    char bufferNombre[128];
    char bufferHorasTrabajadas[20];
    char bufferSueldo[20];
    if( pArrayListEmployee != NULL &&
        !utn_getTexto(  bufferNombre,128,"\nIntroduzca nombre del empleado: ","",0) &&
        !utn_getTexto(  bufferHorasTrabajadas,20,"\nIntroduzca horas trabajadas del empleado: ", "",0) &&
        !utn_getTexto(  bufferSueldo,20,"\nIntroduzca sueldo del empleado: ","",0))
    {
        bufferIdInt = employee_getNextId();
        snprintf(bufferIdString, 20*sizeof(char), "%d", bufferIdInt);
        pEmpleado = employee_newConParametros(  bufferIdString,bufferNombre, 128,
                                                bufferHorasTrabajadas,bufferSueldo);
        if(pEmpleado != NULL)
        {
            ll_add(pArrayListEmployee, pEmpleado);
            retorno = 0;
        }
    }
    return retorno;
}
int employee_edit(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* pEmpleado;
    int indexEmpleado;
    if( pArrayListEmployee != NULL &&
        !employee_getById(pArrayListEmployee,&indexEmpleado))
    {
        pEmpleado = ll_get(pArrayListEmployee, indexEmpleado);
        if( !employee_confirmEditOrRemove(pEmpleado))
        {
            //employee_menuEdicion




/*if( !utn_getTexto(  bufferNombre,128,"\nIntroduzca nombre del empleado: ","",0) &&
    !utn_getTexto(  bufferHorasTrabajadas,20,"\nIntroduzca horas trabajadas del empleado: ", "",0) &&
    !utn_getTexto(  bufferSueldo,20,"\nIntroduzca sueldo del empleado: ","",0))
{
    employee_setNombre(pEmpleado, buffer)
    if(pEmpleado != NULL)
    {
        ll_add(pArrayListEmployee, pEmpleado);
        retorno = 0;
    }
}*/

         //
        }
    }
    return retorno;
}
int employee_remove(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* pEmpleado;
    int indexRemove;
    if( pArrayListEmployee != NULL &&
        !employee_getById(pArrayListEmployee,&indexRemove))
    {
        pEmpleado = ll_get(pArrayListEmployee, indexRemove);
        if( !employee_confirmEditOrRemove(pEmpleado))
        {
            free(ll_pop(pArrayListEmployee, indexRemove));
            retorno = 0;
        }
    }
    return retorno;
}
int employee_confirmEditOrRemove(Employee* this)
{
    int retorno = -1;
    char confirmar[10];
    system("clear");
    printf("\nHa seleccionado el siguiente empleado");
    employee_showInfo(this);
    if( !utn_getTexto(confirmar, 10, "\nPulse 1 para confirmar: ", "\nError", 0) &&
        strcmp(confirmar, "1") == 0)
    {
        retorno = 0;
    }
    return retorno;
}

int employee_list(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* pEmpleado;
    int i;
    int numeroEmpleados = 0;
    if(pArrayListEmployee != NULL)
    {
        retorno = 0;
        for(i=0;i < ll_len(pArrayListEmployee);i++)
        {
            pEmpleado = ll_get(pArrayListEmployee,i);
            employee_showInfo(pEmpleado);
            numeroEmpleados++;
        }
        printf("\nHay %d empleados\n",numeroEmpleados);
    }
    return retorno;
}

int employee_sort(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int option = 0;
    if(pArrayListEmployee != NULL)
    {
        printf( "\n1. Id(Menor a Mayor)"
                "\n2. Id(Mayor a Menor)"
                "\n3. Nombre(A-Z)"
                "\n4. Nombre(Z-A)"
                "\n5. Horas(Menor a Mayor)"
                "\n6. Horas(Mayor a Menor)"
                "\n7. Sueldo(Menor a Mayor)"
                "\n8. Sueldo(Mayor a Menor)"
                "\n9. Cancelar");
        utn_getEntero(&option, 5, "Seleccione...\n", "", 0);
        if(option > 0 && option < 9)
        {
            printf("Esto puede llevar unos minutos...\n");
        }
        switch(option)
        {
            case 1:
                if(!ll_sort(pArrayListEmployee,employee_criterioSortId,1))
                {
                    retorno = 0;
                }
                break;
            case 2:
                if(!ll_sort(pArrayListEmployee,employee_criterioSortId,0))
                {
                    retorno = 0;
                }
                break;
            case 3:
                if(!ll_sort(pArrayListEmployee,employee_criterioSortNombre,1))
                {
                    retorno = 0;
                }
                break;
            case 4:
                if(!ll_sort(pArrayListEmployee,employee_criterioSortNombre,0))
                {
                    retorno = 0;
                }
                break;
            case 5:
                if(!ll_sort(pArrayListEmployee,employee_criterioSortHorasTrabajadas,1))
                {
                    retorno = 0;
                }
                break;
            case 6:
                if(!ll_sort(pArrayListEmployee,employee_criterioSortHorasTrabajadas,0))
                {
                    retorno = 0;
                }
                break;
            case 7:
                if(!ll_sort(pArrayListEmployee,employee_criterioSortSueldo,1))
                {
                    retorno = 0;
                }
                break;
            case 8:
                if(!ll_sort(pArrayListEmployee,employee_criterioSortSueldo,0))
                {
                    retorno = 0;
                }
                break;
            default:
                break;
        }
    }
    return retorno;
}

int employee_criterioSortId(void* thisA, void* thisB)
{
    int idA;
    int idB;
    int retorno = 0;
    employee_getId(thisA,&idA);
    employee_getId(thisB,&idB);
    if(idA > idB)
    {
        retorno = 1;
    }
    else if(idB > idA)
    {
        retorno = -1;
    }
    return retorno;
}

int employee_criterioSortNombre(void* thisA, void* thisB)
{
    char nombreA[128];
    char nombreB[128];
    int retorno = 0;
    employee_getNombre(thisA,nombreA);
    employee_getNombre(thisB,nombreB);
    if(strcmp(nombreA,nombreB) > 0)
    {
        retorno = 1;
    }
    else if(strcmp(nombreA,nombreB) < 0)
    {
        retorno = -1;
    }
    return retorno;
}

int employee_criterioSortHorasTrabajadas(void* thisA, void* thisB)
{
    int horasTrabajadasA;
    int horasTrabajadasB;
    int retorno = 0;
    employee_getHorasTrabajadas(thisA,&horasTrabajadasA);
    employee_getHorasTrabajadas(thisB,&horasTrabajadasB);
    if(horasTrabajadasA > horasTrabajadasB)
    {
        retorno = 1;
    }
    else if(horasTrabajadasB > horasTrabajadasA)
    {
        retorno = -1;
    }
    return retorno;
}

int employee_criterioSortSueldo(void* thisA, void* thisB)
{
    int sueldoA;
    int sueldoB;
    int retorno = 0;
    employee_getSueldo(thisA,&sueldoA);
    employee_getSueldo(thisB,&sueldoB);
    if(sueldoA > sueldoB)
    {
        retorno = 1;
    }
    else if(sueldoB > sueldoA)
    {
        retorno = -1;
    }
    return retorno;
}
