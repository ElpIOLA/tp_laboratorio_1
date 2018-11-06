#include "LinkedList.h"
#include "Controller.h"
int main()
{
    controller_init();
}



/*
Employee* employee_menuEdicion()
{
    int retorno = -1;
    Employee* pEmpleadoSinEditar;
    Employee* pEmpleadoAux;
    char previousNombre[128];
    int previousHorasTrabajadas;
    int previousSueldo;
    char bufferNombre[128];
    char bufferId[20];
    char bufferHorasTrabajadas[20];
    char bufferSueldo[20];
    int bufferIdInt;
    int bufferHorasTrabajadasInt;
    int bufferSueldoInt;




    if(this != NULL)
    {
        employee_getNombre(this, previousNombre);
        printf("\nEditar Nombre: %s", previousNombre);
        if(!employee_confirm())
        {
            utn_getTexto(bufferNombre,128,"\nIntroduzca nombre del empleado: ","",0);
        }
        else
        {
            employee_getNombre(this, bufferNombre);
        }

        employee_getHorasTrabajadas(this, &previousHorasTrabajadas);
        printf("\nEditar Horas: %d", previousHorasTrabajadas);
        if(!employee_confirm())
        {
            utn_getTexto(bufferHorasTrabajadas,128,"\nIntroduzca horas del empleado: ","",0);
        }
        else
        {
            employee_getHorasTrabajadas(this, &bufferHorasTrabajadasInt);
            snprintf(bufferHorasTrabajadas, 20*sizeof(char), "%d", bufferHorasTrabajadasInt);
        }

        employee_getSueldo(this, &previousSueldo);
        printf("\nEditar Sueldo: %d",previousSueldo);
        if(!employee_confirm())
        {
            utn_getTexto(bufferSueldo,128,"\nIntroduzca sueldo del empleado: ","",0);
        }
        else
        {
            employee_getSueldo(this, &bufferSueldoInt);
            snprintf(bufferSueldo, 20*sizeof(char), "%d", bufferSueldoInt);
        }
        employee_getId(this, &bufferIdInt);
        snprintf(bufferId, 20*sizeof(char), "%d", bufferIdInt);
        pEmpleadoAux = employee_newConParametros(   bufferId, bufferNombre, 128,
                                                    bufferHorasTrabajadas,bufferSueldo);
        if(pEmpleadoAux != NULL)
        {
            printf("\nEmpleado sin editar");
            employee_showInfo(this);
            printf("\nEmpleado editado");
            employee_showInfo(pEmpleadoAux);
            if(!employee_confirm())
            {
                this = pEmpleadoAux;
                employee_showInfo(this);
                retorno = 0;
            }
        }
    }
    return retorno;
}*/
