#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "empleado.h"
static int getNextId()
{
    static int ultimoId=-1;
    ultimoId++;
    return ultimoId;
}
static int getLugarLibre(Empleado* array, int len)
{
    int retorno = -1;
    int i;
    if(array != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(array[i].isEmpty)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
static int comparacionApellidoSector(Empleado* arrayUno, Empleado* arrayDos)
{
    int retorno=-1;
    if(arrayUno != NULL && arrayDos != NULL)
    {
        if( strcmp(arrayUno->apellido, arrayDos->apellido) > 0 ||
            (strcmp(arrayUno->apellido, arrayDos->apellido) == 0 && arrayUno->sector > arrayDos->sector))
        {
            retorno = 0;
        }
    }
    return retorno;
}
int empleado_init(Empleado* array, int len)
{
    int retorno = -1;
    int i;
    if(array != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            array[i].isEmpty = 1;
        }
        retorno = 0;
    }
    return retorno;
}
Empleado* empleado_getById(Empleado* array, int len,int id)
{
    Empleado* retorno = NULL;
    int i;
    if(array != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(!array[i].isEmpty && array[i].idEmpleado == id)
            {
                retorno = &array[i];
                break;
            }
        }
    }
    return retorno;
}
int empleado_alta(Empleado* array, int len)
{
    int retorno = -1;
    int indice;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;
    indice = getLugarLibre(array,len);
    if( array != NULL && len > 0 && indice >= 0 &&
        indice < len && array[indice].isEmpty &&
        !utn_getNombre(nombre, 51,"Nombre empleado?\n","nombre no valido\n",2) &&
        !utn_getNombre(apellido, 51,"Apellido empleado?\n","apellido no valido\n",2) &&
        !utn_getFloatPositivo(&salario, 10,"Salario empleado?\n","salario no valido\n",2) &&
        !utn_getEnteroPositivo(&sector, 4, "Sector empleado?\n", "sector no valido", 2))
    {
        strncpy(array[indice].nombre, nombre,51);
        strncpy(array[indice].apellido, apellido, 51);
        array[indice].salario = salario;
        array[indice].sector = sector;
        array[indice].isEmpty = 0;
        array[indice].idEmpleado = getNextId();
        retorno = 0;
    }
    return retorno;
}
int empleado_modificar(Empleado* array, int len, int reintentos)
{
    int retorno = -1;
    Empleado *empleadoModificado = NULL;
    int elegirOpcion = 0;
    int id;
    int i;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;
    if(array != NULL && len > 0 && reintentos >= 0)
    {
        empleado_mostrar(array, len);
        for(i=0; i <= reintentos; i++)
        {
            if( !utn_getEntero(&id, len, "Introduzca el Id que desea modificar\n", "", 0) &&
                empleado_getById(array, len, id) != NULL)
            {
                empleadoModificado = empleado_getById(array, len, id);
                break;
            }
            else
            {
                printf("Id erroneo\n");
            }
        }
    }
    if(empleadoModificado != NULL)
    {
        printf("1. Modificar nombre\n"
               "2. Modificar apellido\n"
               "3. Modificar salario\n"
               "4. Modificar sueldo\n"
               "5. Modificar todos los datos\n");
        utn_getEnteroPositivo(&elegirOpcion, 5, "Seleccione...\n", "", 0);
        switch(elegirOpcion)
        {
            case 1:
                if(!utn_getNombre(nombre, 51,"Nombre empleado?\n","nombre no valido\n",2))
                {
                    strncpy(empleadoModificado->nombre, nombre, 51);
                    retorno = 0;
                }
                break;
            case 2:
                if(!utn_getNombre(apellido, 51,"Apellido empleado?\n","apellido no valido\n",2))
                {
                    strncpy(empleadoModificado->apellido, apellido, 51);
                    retorno = 0;
                }
                break;
            case 3:
                if(!utn_getFloatPositivo(&salario, 10,"Salario empleado?\n","salario no valido\n",2))
                {
                    empleadoModificado->salario = salario;
                    retorno = 0;
                }
                break;
            case 4:
                if(!utn_getEnteroPositivo(&sector, 4, "Sector empleado?\n", "sector no valido", 2))
                {
                    empleadoModificado->sector = sector;
                    retorno = 0;
                }
                break;
            case 5:
                if( !utn_getNombre(nombre, 51,"Nombre empleado?\n","nombre no valido\n",2) &&
                    !utn_getNombre(apellido, 51,"Apellido empleado?\n","apellido no valido\n",2) &&
                    !utn_getFloatPositivo(&salario, 10,"Salario empleado?\n","salario no valido\n",2) &&
                    !utn_getEnteroPositivo(&sector, 4, "Sector empleado?\n", "sector no valido", 2))
                {
                    strncpy(empleadoModificado->nombre, nombre, 51);
                    strncpy(empleadoModificado->apellido, apellido, 51);
                    empleadoModificado->salario = salario;
                    empleadoModificado->sector = sector;
                    retorno = 0;
                }
                break;
            default:
                printf("Opcion Incorrecta\n");
                break;
        }
    }
    return retorno;
}
int empleado_baja(Empleado* array, int len, int reintentos)
{
    int retorno = -1;
    Empleado *empleadoModificado;
    char confirmarBaja[10];
    int id;
    int i;
    if(array != NULL && len > 0 && reintentos >= 0)
    {
        empleado_mostrar(array, len);
        for(i=0; i<= reintentos; i++)
        {
            if( !utn_getEntero(&id, len, "Introduzca el Id que desea dar de baja\n", "", 0) &&
                empleado_getById(array, len, id) != NULL)
            {
                empleadoModificado = empleado_getById(array, len, id);
                printf("Se eliminara el siguiente empleado\n");
                empleado_mostrar(empleadoModificado, 1);
                if( !utn_getTexto(confirmarBaja, 10, "Pulse 1 para confirmar\n", "Error\n", 2) &&
                    strcmp(confirmarBaja, "1") == 0)
                {
                    empleadoModificado->isEmpty = 1;
                    retorno = 0;
                }
                break;
            }
            else
            {
                printf("Id Erroneo\n");
            }
        }
    }
    return retorno;
}
int empleado_mostrar(Empleado* array, int len)
{
    int retorno = -1;
    int i;
    if(array != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(!array[i].isEmpty)
            {
                printf("\nNombre: %s\nApellido: %s\nSalario: %.2f\nSector: %d\nID: %d\n\n",
                array[i].nombre, array[i].apellido, array[i].salario, array[i].sector, array[i].idEmpleado);
            }
        }
        retorno = 0;
    }
    return retorno;
}
int empleado_ingresoForzado(Empleado* array, int len, char *nombre, char *apellido, float salario, int sector)
{
    int indice;
    indice = getLugarLibre(array,len);
    strncpy(array[indice].nombre, nombre, 51);
    strncpy(array[indice].apellido, apellido, 51);
    array[indice].salario = salario;
    array[indice].sector = sector;
    array[indice].idEmpleado = getNextId();
    array[indice].isEmpty = 0;
    return 0;
}
int empleado_sortEmpleadosPorApellidoSector(Empleado *array, int len, int orden)
{
    Empleado auxiliar;
    int retorno=-1;
    int i;
    int j;
    if(array != NULL && len > 0)
    {
        for(i=1; i < len; i++)
        {
            auxiliar = array[i];
            j = i - 1;
            if(orden == 0)
            {
                while ((j >= 0) && !comparacionApellidoSector(&array[j], &auxiliar))
                {
                    array[j + 1] = array[j];
                    j--;
                }
                array[j + 1] = auxiliar;
            }
            if(orden == 1)
            {
                while ((j >= 0) && !comparacionApellidoSector(&auxiliar, &array[j]))
                {
                    array[j + 1] = array[j];
                    j--;
                }
                array[j + 1] = auxiliar;
            }
        }
        retorno = 0;
    }
    return retorno;
}
int empleado_informacionEmpleados(Empleado *array, int len)
{
    int retorno=-1;
    int i;
    float totalSalarios = 0;
    int totalEmpleados = 0;
    float promedioSalarios;
    int cantidadSalariosSobrePromedio = 0;
    if(array != NULL && len > 0)
    {
        for(i=0; i < len; i++)
        {
            if(array[i].isEmpty == 0)
            {
                totalSalarios += array[i].salario;
                totalEmpleados++;
            }
        }
        promedioSalarios = totalSalarios/totalEmpleados;
        for(i=0; i < len; i++)
        {
            if(array[i].isEmpty == 0 && array[i].salario > promedioSalarios)
            {
                cantidadSalariosSobrePromedio++;
            }
        }
        printf("El total de los salarios es: %.2f\n", totalSalarios);
        printf("El promedio de los salarios es: %.2f\n", promedioSalarios);
        printf("Cantidad de salarios que superan el promedio: %d\n", cantidadSalariosSobrePromedio);
        retorno = 0;
    }
    return retorno;
}
