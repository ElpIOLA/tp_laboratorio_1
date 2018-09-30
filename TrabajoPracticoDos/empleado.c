#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "empleado.h"
/**
* \brief    Se utiliza esta funcion para obtener un nuevo id
*           declarando una variable static para el id y suma 1 al anterior
* \return devuelve un id nuevo
*/
static int getNextId()
{
    static int ultimoId=-1;
    ultimoId++;
    return ultimoId;
}
/**
* \brief    Se utiliza esta funcion para obtener el primer lugar libre de un array de tipo empleado,
*           recorriendo el array hasta encontrar un isEmpty en 1
* \param array Es el array que se recorre
* \param len Es el limite de empleados que puede guardar el array
* \return devuelve el indice de la posicion libre, sino el return es -1.
*/
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
/**
* \brief compara a los empleados, primero por apellido y en caso de coincidir, por sector
* \param arrayUno es el primer empleado que se va a comparar
* \param arrayDos es el segundo empleado que se va a comparar
* \return si el primero es mayor devuelve 0(para que se realice el swap), si no -1
*/
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
/**
* \brief    Se utiliza esta funcion para inicializar un array de tipo empleado,
*           recorriendo el array y poniendo cada isEmpty en 1
* \param array Es el array que se recorre
* \param len Es el limite de empleados que puede guardar el array
* \return El retorno es 0 si se realizo de manera correcta, si no el retorno es -1.
*/
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
/**
* \brief    Se utiliza esta funcion para encontrar un empleado a través de un id,
*           recorriendo el array y comparando los id (donde el isEmpty es 0)
* \param array Es el array que se recorre
* \param len Es el limite de empleados que puede guardar el array
* \param id Es el id con que se compara cada id del array
* \return   retorna la direccion de la struct del empleado donde se encontro el id,
*           si no el retorno es NULL.
*/
Empleado* empleado_getById(Empleado* array, int len, int id)
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
/**
* \brief    Se utiliza esta funcion para dar de alta un empleado generando un id
*           de manera automatica y el usuario introduce el resto de datos,
*           si se realiza todo correctamente se guardan los datos y se coloca el isEmpty en 0
* \param array Es el array que se recorre
* \param len Es el limite de empleados que puede guardar el array
* \return El retorno es 0 si se realizo de manera correcta, si no el retorno es -1.
*/
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
        !utn_getNombre( nombre, 51,"Nombre empleado?\n",
                        "nombre no valido\nDebe empezar por mayuscula y el resto minusculas\n",2) &&
        !utn_getNombre( apellido, 51,"Apellido empleado?\n",
                        "apellido no valido\nDebe empezar por mayuscula y el resto minusculas\n",2) &&
        !utn_getFloatPositivo(&salario, 10,"Salario empleado?\n","salario no valido\n",2) &&
        !utn_getEnteroSoloNumeros(&sector, 4, "Sector empleado?\n", "sector no valido", 2))
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
/**
* \brief    Se utiliza esta funcion para modificar un empleado,
*           el usuario elige a traves de un menu
*           que dato modificar o modificarlos todos
* \param array Es el array que se recorre
* \param len Es el limite de empleados que puede guardar el array
* \param reintentos Veces que el usuario podra volver a introducir el id
* \return El retorno es 0 si se realizo de manera correcta, si no el retorno es -1.
*/
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
        utn_getEnteroSoloNumeros(&elegirOpcion, 5, "Seleccione...\n", "", 0);
        switch(elegirOpcion)
        {
            case 1:
                if( !utn_getNombre(nombre, 51,"Nombre empleado?\n",
                    "nombre no valido\nDebe empezar por mayuscula y el resto minusculas\n",2))
                {
                    strncpy(empleadoModificado->nombre, nombre, 51);
                    retorno = 0;
                }
                break;
            case 2:
                if( !utn_getNombre( apellido, 51,"Apellido empleado?\n",
                    "apellido no valido\nDebe empezar por mayuscula y el resto minusculas\n",2))
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
                if(!utn_getEnteroSoloNumeros(&sector, 4, "Sector empleado?\n", "sector no valido", 2))
                {
                    empleadoModificado->sector = sector;
                    retorno = 0;
                }
                break;
            case 5:
                if( !utn_getNombre( nombre, 51,"Nombre empleado?\n",
                    "nombre no valido\nDebe empezar por mayuscula y el resto minusculas\n",2) &&
                    !utn_getNombre( apellido, 51,"Apellido empleado?\n",
                    "apellido no valido\nDebe empezar por mayuscula y el resto minusculas\n",2) &&
                    !utn_getFloatPositivo(&salario, 10,"Salario empleado?\n","salario no valido\n",2) &&
                    !utn_getEnteroSoloNumeros(&sector, 4, "Sector empleado?\n", "sector no valido", 2))
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
/**
* \brief    Se utiliza esta funcion para dar de baja (baja logica) un empleado,
*           el usuario introduce el id, se le muestra el empleado y
*           confirma la baja(se coloca el isEmpty en 1)
* \param array Es el array que se recorre
* \param len Es el limite de empleados que puede guardar el array
* \param reintentos Veces que el usuario podra volver a introducir el id
* \return El retorno es 0 si se realizo de manera correcta, si no el retorno es -1.
*/
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
/**
* \brief    Se utiliza esta funcion para mostrar todos los datos de los
*           empleados del array (nombre, apellidos, salario, sector, id)
* \param array Es el array que se recorre
* \param len Es el limite de empleados que puede guardar el array
* \return El retorno es 0 si se mostraron los datos, si no el retorno es -1.
*/
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
/**
* \brief    Se utiliza esta funcion para cargar los datos de un
*           empleado del array (nombre, apellidos, salario, sector)
*           el id se genera de manera automatica y se pone el isEmpty en 0
* \param array Es el array que se recorre
* \param len Es el limite de empleados que puede guardar el array
* \return El retorno es 0 si se mostraron los datos, si no el retorno es -1.
*/
int empleado_ingresoForzado(Empleado* array, int len, char *nombre, char *apellido, float salario, int sector)
{
    int retorno = -1;
    int indice;
    indice = getLugarLibre(array,len);
    if( array != NULL && len > 0 && nombre != NULL &&
        apellido != NULL && salario > 0 && sector > 0)
    {
        strncpy(array[indice].nombre, nombre, 51);
        strncpy(array[indice].apellido, apellido, 51);
        array[indice].salario = salario;
        array[indice].sector = sector;
        array[indice].idEmpleado = getNextId();
        array[indice].isEmpty = 0;
        retorno = 0;
    }
    return retorno;
}
/**
* \brief    ordena un array de empleados por insercion, por 2 criterios,
*           primero por apellido y en caso de coincidir, por sector
* \param array Es el array que se recorre
* \param len Es el limite de empleados que puede guardar el array
* \param orden El orden debe ser 0 (Ascendente) o 1 (Descendente)
* \return El retorno es 0 si se realizo el ordenamiento, si no el retorno es -1.
*/
int empleado_sortEmpleadosPorApellidoSector(Empleado *array, int len, int orden)
{
    Empleado auxiliar;
    int retorno=-1;
    int i;
    int j;
    if(array != NULL && len > 0 && (orden == 0 || orden == 1))
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
/**
* \brief    Calcula el total de los salarios, el promedio
*           y la cantidad de empleados que superan el promedio.
*           Solo evalua los empleados que tienen el isEmpty en 0.
*           Finalmente muestra toda esa informacion
* \param array Es el array que se recorre
* \param len Es el limite de empleados que puede guardar el array
* \return El retorno es 0 si se mostro la informacion, si no el retorno es -1.
*/
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
