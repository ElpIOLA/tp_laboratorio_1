/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "../testing/inc/Employee.h"
//preguntar donde las pongo
int salaryFilter (void* pElement)
{
    int returnAux = 0;
    Employee* pEmployee = pElement;
    if(pEmployee != NULL && pEmployee->salary == 20000)
    {
        returnAux = 1;
    }
    return returnAux;
}

void testFilter()
{
    printf("TEST FILTER\n");
    Employee* firstEmployee = newEmployee(1, "Leandro", "Egea", 20000, 7);
    Employee* secondEmployee = newEmployee(2, "Martin", "Riquelme", 50000, 8);
    Employee* thirdEmployee = newEmployee(3, "Laura", "Lopez", 20000, 3);
    Employee* fourthEmployee = newEmployee(4, "Esteban", "Quito", 30000, 7);
    Employee* firstEmployeeAux = NULL;
    Employee* secondEmployeeAux = NULL;

    printf("Lista original:\n");
    printEmployee(firstEmployee);
    printEmployee(secondEmployee);
    printEmployee(thirdEmployee);
    printEmployee(fourthEmployee);
    printf("\nLista filtrada(que se deberia obtener):\n");
    printEmployee(firstEmployee);
    printEmployee(thirdEmployee);

    LinkedList* llTestFilter = NULL;
    LinkedList* llTestFilterAux = ll_newLinkedList();
    ll_add(llTestFilterAux, firstEmployee);
    ll_add(llTestFilterAux, secondEmployee);
    ll_add(llTestFilterAux, thirdEmployee);
    ll_add(llTestFilterAux, fourthEmployee);
    llTestFilter = ll_filter(llTestFilterAux, salaryFilter);
    firstEmployeeAux = llTestFilter->pFirstNode->pElement;
    secondEmployeeAux = llTestFilter->pFirstNode->pNextNode->pElement;
    printf("\nLista filtrada(obtenida):\n");
    printEmployee(firstEmployeeAux);
    printEmployee(secondEmployeeAux);
}

int main(void)
{
    startTesting(1);  // ll_newLinkedList
    startTesting(2);  // ll_len
    startTesting(3);  // getNode - test_getNode
    startTesting(4);  // addNode - test_addNode
    startTesting(5);  // ll_add
    startTesting(6);  // ll_get
    startTesting(7);  // ll_set
    startTesting(8);  // ll_remove
    startTesting(9);  // ll_clear
    startTesting(10); // ll_deleteLinkedList
    startTesting(11); // ll_indexOf
    startTesting(12); // ll_isEmpty
    startTesting(13); // ll_push
    startTesting(14); // ll_pop
    startTesting(15); // ll_contains
    startTesting(16); // ll_containsAll
    startTesting(17); // ll_subList
    startTesting(18); // ll_clone
    startTesting(19); // ll_sort
    testFilter();

    return 0;
}
