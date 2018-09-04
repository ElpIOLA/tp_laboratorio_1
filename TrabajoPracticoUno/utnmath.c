#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"
#include "utnmath.h"
/**
* \brief Suma numeros con decimales
* \param numeroUno Primer sumando
* \param numeroDos Segundo sumando
* \return Devuelve el resultado de la suma
*
*/
float utnMath_sumarDosFlotantes(float numeroUno, float numeroDos)
{
    float resultadoSuma;
    resultadoSuma = numeroUno + numeroDos;
    return resultadoSuma;
}
/**
* \brief Resta numeros con decimales
* \param numeroUno Minuendo de la resta
* \param numeroDos Sustraendo de la resta
* \return Devuelve el resultado de la resta
*
*/
float utnMath_restarDosFlotantes(float numeroUno, float numeroDos)
{
    float resultadoResta;
    resultadoResta = numeroUno - numeroDos;
    return resultadoResta;
}
/**
* \brief Multiplica numeros con decimales
* \param numeroUno Primer factor
* \param numeroDos Segundo factor
* \return Devuelve el resultado de la multiplicacion
*
*/
float utnMath_multiplicarDosFlotantes(float numeroUno, float numeroDos)
{
    float resultadoMultiplicacion;
    resultadoMultiplicacion = numeroUno * numeroDos;
    return resultadoMultiplicacion;
}
/**
* \brief Dividir numeros con decimales
* \param numeroUno Dividendo
* \param numeroDos Divisior
* \param resultadoDivision Es el resultado que se obtiene si es posible dividir
* \return Devuelve un 0 si la operacion se realizo con exito o un 1 si no se puede dividir
*/
int utnMath_dividirDosFlotantes(float numeroUno, float numeroDos, float *resultadoDivision)
{
    int retorno;
    if(numeroDos == 0)
    {
        retorno = 1;
    }
    else
    {
        *resultadoDivision = numeroUno / numeroDos;
        retorno = 0;
    }
    return retorno;
}
/**
* \brief Obtiene el resultado de
* \param numero Es el numero en el que se realiza el factorial
* \param resultadoFactorial Es el resultado que se obtiene si es posible realizar el factorial
* \return Devuelve un 0 si la operacion se realizo con exito o un 1 si no se puede realizar el factorial
*/
unsigned long long int utnMath_obternerResultadoFactorial(int numero)
{
    unsigned long long int resultado;
    if(numero == 1)
    {
        return 1;
    }
    resultado =  numero * utnMath_obternerResultadoFactorial(numero-1);
    return resultado;
}
/**
* \brief Realiza el factorial de un flotante
* \param numero Es el numero en el que se evalua si se puede realizar el factorial
* \param resultadoFactorial Es el resultado que se obtiene si es posible realizar el factorial
* \return Devuelve un 0 si la operacion se realizo con exito o un 1 si no se puede realizar el factorial
*/
int utnMath_realizarFactorialConFlotante(float numero, unsigned long long int *resultadoFactorial)
{
    unsigned long long int resultadoParcial;
    int numeroEntero;
    int retorno;
    if((numero - (int)numero) == 0)
    {
        numeroEntero = (int)numero;
        if(numeroEntero < 0)
        {
            printf("No se puede realizar el factorial de un numero negativo\n");
            retorno = 1;
        }
        else if(numeroEntero == 0)
        {
            *resultadoFactorial = 1;
            retorno = 0;
        }
        else if(numeroEntero > 0 && numeroEntero <=20)
        {
            resultadoParcial = utnMath_obternerResultadoFactorial(numeroEntero);
            *resultadoFactorial = resultadoParcial;
            retorno = 0;
        }
        else if(numero > 20)
        {
            printf("El numero es demasiado grande, solo es posible hasta el factorial de 20\n");
            retorno = 1;
        }
        else
        {
            printf("No se pudo realizar el factorial\n");
            retorno = 1;
        }
    }
    else
    {
        printf("No se puede realizar el factorial de un numero decimal\n");
        retorno = 1;
    }
    return retorno;
}
