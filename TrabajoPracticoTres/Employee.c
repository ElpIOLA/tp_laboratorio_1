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





int employee_setId(Employee* this,int id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->id=id;
        retorno=0;
    }
    //printf("retorno = %d\n",retorno);
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
    int retorno=-1;
    if(this!=NULL)
    {
        this->sueldo=sueldo;
        retorno=0;
    }
    return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *sueldo=this->sueldo;
        retorno=0;
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
    //printf("id = %d      id = %s\n",idInt,idString);
    if( isValidId(idString,20) &&
        isValidNombre(nombre,lenNombre) &&
        isValidHorasTrabajadas(horasTrabajadasString,20) &&
        isValidSueldo(sueldoString,20) &&
        !employee_setId(this,idInt)&&
        !employee_setNombre(this,nombre)&&
        !employee_setHorasTrabajadas(this,horasTrabajadasInt)&&
        !employee_setSueldo(this,sueldoInt))
    {
        printf("lololo\n");
        retorno = this;
    }
    else
    {
        printf("holiwis\n");
        employee_delete(this);
    }
    return retorno;
}
//falta el id automatico
int employee_add(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* pEmpleado;
    char bufferId[20];
    char bufferNombre[128];
    char bufferHorasTrabajadas[20];
    char bufferSueldo[20];
    if(pArrayListEmployee != NULL)
    {
        if( !utn_getTexto(bufferId,20,"","",0) &&
            !utn_getTexto(bufferNombre,128,"","",0) &&
            !utn_getTexto(bufferId,20,"","",0) &&
            !utn_getTexto(bufferSueldo,20,"","",0))
        {
            pEmpleado = employee_newConParametros(  bufferId,bufferNombre, 128,
                                                    bufferHorasTrabajadas,bufferSueldo);
            if(pEmpleado != NULL)
            {
                //printf("holis\n");
                ll_add(pArrayListEmployee, pEmpleado);
                retorno = 0;
            }
        }
    }
    return retorno;

}




int employee_list(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* pEmpleado;
    int bufferId;
    char bufferNombre[128];
    int bufferHorasTrabajadas;
    int bufferSueldo;
    int i;
    int numeroEmpleados = 0;
    if(pArrayListEmployee != NULL)
    {
        retorno = 0;
        for(i=0;i < ll_len(pArrayListEmployee);i++)
        {
            pEmpleado = ll_get(pArrayListEmployee,i);
            employee_getId(pEmpleado,&bufferId);
            employee_getNombre(pEmpleado,bufferNombre);
            employee_getHorasTrabajadas(pEmpleado,&bufferHorasTrabajadas);
            employee_getSueldo(pEmpleado,&bufferSueldo);
            printf( "\nId: %d - Nombre: %s - Horas: %d - Sueldo: %d",
                    bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);
            numeroEmpleados++;
        }
        printf("\nHay %d empleados\n",numeroEmpleados);
    }
    return retorno;
}

int employee_sort(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    /*Employee* pEmpleadoA;
    Employee* pEmpleadoB;
    if(pArrayListEmployee != NULL)
    {
        if(ll_sort(pArrayListEmployee,employee_criterioSortSueldo(pEmpleadoA,pEmpleadoB),0))
        {
            retorno = 0;
        }
    }*/
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
    else if(strcmp(nombreA,nombreB) > 0)
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
