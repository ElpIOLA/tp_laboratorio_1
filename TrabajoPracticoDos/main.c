#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "empleado.h"
#define CANTIDAD_EMPLEADOS 1000
int main()
{
    int elegirOpcion;
    int salidaDelMenu = 0;
    int cantidadEmpleadosActivos = 0;
    Empleado empleados[CANTIDAD_EMPLEADOS];
    empleado_init(empleados, CANTIDAD_EMPLEADOS);
    //cantidadEmpleadosActivos = 6;
    //empleado_ingresoForzado(empleados, CANTIDAD_EMPLEADOS, "Daniel", "Perez", 43000.25, 4);
    //empleado_ingresoForzado(empleados, CANTIDAD_EMPLEADOS, "Martina", "Gomez", 50000, 22);
    //empleado_ingresoForzado(empleados, CANTIDAD_EMPLEADOS, "Rolando", "Mora", 100.2, 2);
    //empleado_ingresoForzado(empleados, CANTIDAD_EMPLEADOS, "Marcos", "Lopez", 600, 7);
    //empleado_ingresoForzado(empleados, CANTIDAD_EMPLEADOS, "David", "Lopez", 6000.2, 4);
    //empleado_ingresoForzado(empleados, CANTIDAD_EMPLEADOS, "Rafael", "Lopez", 300.2, 1);
    while(salidaDelMenu == 0)
    {
        system("clear");
        printf("1. Alta empleado\n"
               "2. Modificar empleado\n"
               "3. Baja empleado\n"
               "4. Informacion empleado\n"
               "5. Salir\n");
        elegirOpcion = 0;
        utn_getEntero(&elegirOpcion, 5, "Seleccione...\n", "", 0);
        switch(elegirOpcion)
        {
            case 1:
                if(!empleado_alta(empleados, CANTIDAD_EMPLEADOS))
                {
                    cantidadEmpleadosActivos++;
                }
                else
                {
                    printf("No se pudo dar de alta el empleado\n");
                }
                break;
            case 2:
                if(cantidadEmpleadosActivos != 0 && !empleado_modificar(empleados, CANTIDAD_EMPLEADOS, 2))
                {
                    printf("Empleado modificado\n");
                }
                else
                {
                    printf("No se pudo modificar el empleado\n");
                }
                break;
            case 3:
                if(cantidadEmpleadosActivos != 0 && !empleado_baja(empleados, CANTIDAD_EMPLEADOS, 2))
                {
                    cantidadEmpleadosActivos--;
                }
                else
                {
                    printf("No se pudo dar de baja el empleado\n");
                }
                break;
            case 4:
                if(cantidadEmpleadosActivos != 0)
                {
                    printf( "1. Lista empleados\n"
                            "2. Informacion salarios\n"
                            "3. Salir\n");
                    elegirOpcion = 0;
                    utn_getEntero(&elegirOpcion, 5, "Seleccione...\n", "", 0);
                    switch(elegirOpcion)
                    {
                        case 1:
                            empleado_sortEmpleadosPorApellidoSector(empleados, CANTIDAD_EMPLEADOS, 0);
                            empleado_mostrar(empleados, CANTIDAD_EMPLEADOS);
                            break;
                        case 2:
                            empleado_informacionEmpleados(empleados, CANTIDAD_EMPLEADOS);
                            break;
                        default:
                            printf("Opcion Incorrecta\n");
                            break;
                    }
                }
                else
                {
                    printf("No hay empleados dados de alta\n");
                }
                break;
            case 5:
                salidaDelMenu = 1;
                break;
            default:
                printf("Opcion Incorrecta\n");
                break;
        }
        printf("Pulse Enter para continuar\n");
        __fpurge(stdin);
        getchar();
    }
}
