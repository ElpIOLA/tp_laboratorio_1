#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED
typedef struct
{
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;
    int idEmpleado;
    int isEmpty;
}Empleado;

int empleado_init(Empleado* array, int len);
Empleado* empleado_getById(Empleado* array, int len,int id);
int empleado_alta(Empleado* array, int len);
int empleado_modificar(Empleado* array, int len, int reintentos);
int empleado_baja(Empleado* array, int len, int reintentos);
int empleado_mostrar(Empleado* array, int len);
int empleado_ingresoForzado(Empleado* array, int len, char *nombre, char *apellido, float salario, int sector);
int empleado_sortEmpleadosPorApellidoSector(Empleado *array, int len, int orden);
int empleado_informacionEmpleados(Empleado *array, int len);
#endif
