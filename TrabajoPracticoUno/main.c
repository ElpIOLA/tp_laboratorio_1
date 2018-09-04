#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"
#include "utnmath.h"
int main(void)
{
    float primerOperando = 0;
    float segundoOperando = 0;
    float resultadoSuma;
    float resultadoResta;
    float resultadoDivision;
    int errorEnDivision;
    float resultadoMultiplicacion;
    unsigned long long int resultadoPrimerFactorial;
    unsigned long long int resultadoSegundoFactorial;
    int errorEnPrimerFactorial;
    int errorEnSegundoFactorial;
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
                if(utn_getFlotante(&primerOperando, "Ingrese valor de A:\n", "Error en el ingreso\n", 3) == 0)
                {
                    operacionesRealizadas = 0;
                }
                break;
            case '2':
                if(utn_getFlotante(&segundoOperando, "Ingrese valor de B:\n", "Error en el ingreso\n", 3) == 0)
                {
                    operacionesRealizadas = 0;
                }
                break;
            case '3':
                resultadoSuma = utnMath_sumarDosFlotantes(primerOperando, segundoOperando);
                resultadoResta = utnMath_restarDosFlotantes(primerOperando, segundoOperando);
                errorEnDivision = utnMath_dividirDosFlotantes(primerOperando, segundoOperando, &resultadoDivision);
                resultadoMultiplicacion = utnMath_multiplicarDosFlotantes(primerOperando, segundoOperando);
                errorEnPrimerFactorial = utnMath_realizarFactorialConFlotante(primerOperando, &resultadoPrimerFactorial);
                errorEnSegundoFactorial = utnMath_realizarFactorialConFlotante(segundoOperando, &resultadoSegundoFactorial);
                operacionesRealizadas = 1;
                break;
            case '4':
                if(operacionesRealizadas == 1)
                {
                    printf("El resultado de A+B es: %.5f\n", resultadoSuma);
                    printf("El resultado de A-B es: %.5f\n", resultadoResta);
                    utn_imprimirResultadoFloatOErrorEnPantalla( errorEnDivision,
                                                                "El resultado de A/B es:",
                                                                resultadoDivision,
                                                                "No es posible dividir por cero",
                                                                "Se produjo un error");
                    printf("El resultado de A*B es: %.5f\n", resultadoMultiplicacion);
                    utn_imprimirResultadoLongLongOErrorEnPantalla(  errorEnPrimerFactorial,
                                                                    "El factorial de A es:",
                                                                    resultadoPrimerFactorial,
                                                                    "No se pudo realizar el factorial",
                                                                    "Se produjo un error");
                    utn_imprimirResultadoLongLongOErrorEnPantalla(  errorEnSegundoFactorial,
                                                                    "El factorial de B es:",
                                                                    resultadoSegundoFactorial,
                                                                    "No se pudo realizar el factorial",
                                                                    "Se produjo un error");
                }
                else
                {
                    printf("Primero se deben calcular las operaciones\n");
                }
                break;
            case '5':
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
    return 0;
}
