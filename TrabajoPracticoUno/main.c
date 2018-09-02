#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"
#include "utnmath.c"
int main(void)
{
    float primerOperando = 0;
    float segundoOperando = 0;
    float resultadoSuma;
    float resultadoResta;
    float resultadoDivision;
    int errorEnDivision;
    float resultadoMultiplicacion;
    float resultadoPrimerFactorial;
    float resultadoSegundoFactorial;
    int salidaDelMenu = 0;
    int operacionesRealizadas = 0;
    char opcionDelMenu;
    while(salidaDelMenu == 0)
    {
        system("clear");
        printf("1. Ingresar 1er operando (A=%f)\n"
               "2. Ingresar 2do operando (B=%f)\n"
               "3. Calcular todas las operaciones\n"
               "4. Informacion de los resultados\n"
               "5. Salir\n", primerOperando, segundoOperando);
        utn_getCaracter(&opcionDelMenu, "Seleccione...\n", "Opcion Incorrecta\n", '1', '5', 5);
        switch(opcionDelMenu)
        {
            case '1':
                if(utn_getFlotante(&primerOperando, "Ingrese valor de A:\n", "Error en el ingreso\n", 3)==0);
                {
                    operacionesRealizadas = 0;
                }
                break;
            case '2':
                if(utn_getFlotante(&segundoOperando, "Ingrese valor de B:\n", "Error en el ingreso\n", 3)==0);
                {
                    operacionesRealizadas = 0;
                }
                break;
            case '3':
                utnmath_sumarDosFlotantes();
                utnmath_restarDosFlotantes();
                utnmath_multiplicarDosFlotantes();
                utnmath_dividirDosFlotantes();
                utnmath_realizarFactorial();
                utnmath_realizarFactorial();
                operacionesRealizadas = 1;
                break;
            case '4':
                printf("h\n");
                break;
            case '5':
                salidaDelMenu = 1;
                break;
            default:
                printf("Opcion Incorrecta\n");
                break;
        }
        printf("Pulse una tecla para continuar\n");
        __fpurge(stdin);
        getchar();
    }
    return 0;
}
