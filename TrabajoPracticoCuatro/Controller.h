#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
#include "Employee.h"
int controller_init();
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
int controller_deleteAllEmployees(LinkedList* this);
int controller_deleteList(LinkedList* this);
int controller_filterBySalaryMax(LinkedList* this);
int controller_filterBySalaryMin(LinkedList* this);
LinkedList* controller_backUpList(LinkedList* this);
Employee* controller_backUpEmployee(LinkedList* this);
int controller_useBackUpEmployee(LinkedList* this, Employee* pEmpleado, Employee* pEmpleadoAux);
#endif
