#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED
#include "LinkedList.h"
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;
//agregar el nextId

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);
int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);
int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);
Employee* employee_new();
int employee_delete(Employee* this);
Employee* employee_newConParametros(char* idString,char* nombre,int lenNombre,
                                    char* horasTrabajadasString,char* sueldoString);
int employee_add(LinkedList* pArrayListEmployee);
int employee_list(LinkedList* pArrayListEmployee);
int employee_sort(LinkedList* pArrayListEmployee);



int employee_criterioSortId(void* thisA, void* thisB);
int employee_criterioSortNombre(void* thisA, void* thisB);
int employee_criterioSortHorasTrabajadas(void* thisA, void* thisB);
int employee_criterioSortSueldo(void* thisA, void* thisB);

#endif // EMPLOYEE_H_INCLUDED
