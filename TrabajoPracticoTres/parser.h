#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED
#include "LinkedList.h"
#include <stdio.h>
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_saveAsText(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_saveAsBinary(FILE* pFile , LinkedList* pArrayListEmployee);
#endif
