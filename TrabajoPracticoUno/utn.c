#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"
static void myFpurge()
{
    __fpurge(stdin);
    //fflush(stdin);
}
static int getInt(int* numeroIngresado)
{
    myFpurge();
    return scanf("%d", numeroIngresado);
}
static int getFloat(float* numeroIngresado)
{
    myFpurge();
    return scanf("%f", numeroIngresado);
}
static int getChar(char* caracterIngresado)
{
    myFpurge();
    return scanf("%c", caracterIngresado);
}
static int getString(char textoIngresado[])
{
    myFpurge();
    return scanf("%s", textoIngresado);
}
/**
* \brief Solicita un entero al usuario y lo devuelve a traves de pResultado si es validado
* \param pResultado Puntero a la variable resultado
* \param mensaje Es el mensaje a ser mostrado
* \param mensajeError ES el mensaje que se muestra en caso de error
* \param minimo Es el entero minimo aceptado
* \param maximo Es el entero maximo aceptado
* \param reintentos Es la cantidad de intentos que tiene el usuario para ingresar un entero
* \return En caso de exito retorna 0, si no es un entero validado 1 y si no es un entero -1
*
*/
int utn_getEntero(  int *pResultado,
                    char mensaje[],
                    char mensajeError[],
                    int minimo,
                    int maximo,
                    int reintentos)
{
    int retorno;
    int cantidadDeIntentos = 0;
    int numeroIngresado;
    do
    {
        printf("%s", mensaje);
        if(getInt(&numeroIngresado) == 1)
        {
            retorno = utn_validarEnteroEnIntervalo(numeroIngresado, minimo, maximo);
            if(retorno == 0)
            {
                *pResultado = numeroIngresado;
                break;
            }
            else
            {
                printf("%s", mensajeError);
            }
        }
        else
        {
            printf("Error\n");
            retorno = -1;
        }
        cantidadDeIntentos++;
    }while(cantidadDeIntentos<reintentos);
    return retorno;
}
/**
* \brief Valida si un entero esta entre un maximo y un minimo
* \param numeroIngresado Es el numero se va a evaluar si esta entre el minimo y el maximo (incluidos)
* \param minimo Es el numero minimo aceptado
* \param maximo Es el numero maximo aceptado
* \return En caso de exito retorna 0, si esta fuera del rango 1
*
*/
int utn_validarEnteroEnIntervalo(int numeroIngresado, int minimo, int maximo)
{
    int retorno;
    if(numeroIngresado >= minimo && numeroIngresado <= maximo)
    {
        retorno = 0;
    }
    else if(numeroIngresado < minimo || numeroIngresado > maximo)
    {
        retorno = 1;
    }
    return retorno;
}
/**
* \brief Solicita un flotante al usuario y lo devuelve a traves de pResultado si es validado
* \param pResultado Puntero a la variable resultado
* \param mensaje Es el mensaje a ser mostrado
* \param mensajeError Es el mensaje que se muestra en caso de error
* \param reintentos Es la cantidad de intentos que tiene el usuario para ingresar un flotante
* \return En caso de exito retorna 0, si no es un flotante retorna 1
*
*/
int utn_getFlotante(float *pResultado,
                    char mensaje[],
                    char mensajeError[],
                    int reintentos)
{
    int retorno;
    int cantidadDeIntentos = 0;
    float numeroIngresado;
    do
    {
        printf("%s", mensaje);
        if(getFloat(&numeroIngresado) == 1)
        {
            *pResultado = numeroIngresado;
            retorno = 0;
            break;
        }
        else
        {
            printf("%s", mensajeError);
            retorno = 1;
        }
        cantidadDeIntentos++;
    }while(cantidadDeIntentos<reintentos);
    return retorno;
}
/**
* \brief Solicita un flotante al usuario y lo devuelve a traves de pResultado si es validado
* \param pResultado Puntero a la variable resultado
* \param mensaje Es el mensaje a ser mostrado
* \param mensajeError ES el mensaje que se muestra en caso de error
* \param minimo Es el flotante minimo aceptado
* \param maximo Es el flotante maximo aceptado
* \param reintentos Es la cantidad de intentos que tiene el usuario para ingresar un flotante
* \return En caso de exito retorna 0, si no es un flotante validado 1 y si no es un flotante -1
*
*/
int utn_getFlotanteEnIntervalo(float *pResultado,
                    char mensaje[],
                    char mensajeError[],
                    float minimo,
                    float maximo,
                    int reintentos)
{
    int retorno;
    int cantidadDeIntentos = 0;
    float numeroIngresado;
    do
    {
        printf("%s", mensaje);
        if(getFloat(&numeroIngresado) == 1)
        {
            retorno = utn_validarFlotanteEnIntervalo(numeroIngresado, minimo, maximo);
            if(retorno == 0)
            {
                *pResultado = numeroIngresado;
                break;
            }
            else
            {
                printf("%s", mensajeError);
            }
        }
        else
        {
            printf("Error\n");
            retorno = -1;
        }
        cantidadDeIntentos++;
    }while(cantidadDeIntentos<reintentos);
    return retorno;
}
/**
* \brief Valida si un flotante esta entre un maximo y un minimo
* \param numeroIngresado Es el numero se va a evaluar si esta entre el minimo y el maximo (incluidos)
* \param minimo Es el numero minimo aceptado
* \param maximo Es el numero maximo aceptado
* \return En caso de exito retorna 0, si esta fuera del rango 1
*
*/
int utn_validarFlotanteEnIntervalo(float numeroIngresado, float minimo, float maximo)
{
    int retorno;
    if(numeroIngresado >= minimo && numeroIngresado <= maximo)
    {
        retorno = 0;
    }
    else if(numeroIngresado < minimo || numeroIngresado > maximo)
    {
        retorno = 1;
    }
    return retorno;
}
/**
* \brief Solicita un caracter al usuario y le muestra el resultado
* \param pCaracterResultante Puntero a la variable resultado
* \param mensaje Es el mensaje a ser mostrado
* \param mensajeError Es el mensaje que se muestra en caso de error
* \param minimo Es el caracter minimo aceptado
* \param maximo Es el caracter maximo aceptado
* \param reintentos Es la cantidad de intentos que tiene el usuario para ingresar un caracter
* \return En caso de exito retorna 0, si no es un caracter validado 1 y si no es un caracter -1
*
*/
int utn_getCaracter(char *pCaracterResultante,
                    char mensaje[],
                    char mensajeError[],
                    char minimo,
                    char maximo,
                    int reintentos)
{
    int retorno;
    int cantidadDeIntentos = 0;
    char caracterIngresado;
    do
    {
        printf("%s", mensaje);
        if(getChar(&caracterIngresado) == 1)
        {
            retorno = utn_validarCaracterEnIntervalo(caracterIngresado, minimo, maximo);
            if(retorno == 0)
            {
                *pCaracterResultante = caracterIngresado;
                break;
            }
            else
            {
                printf("%s", mensajeError);
            }
        }
        else
        {
            printf("Error\n");
            retorno = -1;
        }
        cantidadDeIntentos++;
    }while(cantidadDeIntentos<reintentos);
    return retorno;
}
/**
* \brief Valida si un caracter esta entre un maximo y un minimo
* \param caracterIngresado Es el caracter se va a evaluar si esta entre el minimo y el maximo (incluidos)
* \param minimo Es el caracter minimo aceptado
* \param maximo Es el caracter maximo aceptado
* \return En caso de exito retorna 0, si esta fuera del rango 1
*
*/
int utn_validarCaracterEnIntervalo(char caracterIngresado, char minimo, char maximo)
{
    int retorno;
    if(caracterIngresado >= minimo && caracterIngresado <= maximo)
    {
        retorno = 0;
    }
    else if(caracterIngresado < minimo || caracterIngresado > maximo)
    {
        retorno = 1;
    }
    return retorno;
}
/**
* \brief Solicita una cadena al usuario y le muestra el resultado
* \param pCadenaResultante Puntero a la variable resultado
* \param mensaje Es el mensaje a ser mostrado
* \param mensajeError Es el mensaje que se muestra en caso de error
* \param longitudMinima Es la longitud de la cadena minima aceptada
* \param longitudMaxima Es la longitud de la cadena maxima aceptada
* \param reintentos Es la cantidad de intentos que tiene el usuario para ingresar una cadena
* \return En caso de exito retorna 0, si no es una cadena validada 1 y si no se recibio el string -1
*
*/
int utn_getCadena(  char *pCadenaResultante,
                    char mensaje[],
                    char mensajeError[],
                    int longitudMinima,
                    int longitudMaxima,
                    int reintentos)
{
    int retorno;
    int cantidadDeIntentos = 0;
    char cadenaIngresada[longitudMaxima*3];
    int longitudCadenaIngresada;
    do
    {
        printf("%s", mensaje);
        if(getString(cadenaIngresada) == 1)
        {
            longitudCadenaIngresada = utn_obtenerLongitudCadena(cadenaIngresada);
            retorno = utn_validarLongitudDeLaCadena(longitudCadenaIngresada, longitudMinima, longitudMaxima);
            if(retorno == 0)
            {
                retorno = utn_copiarCadenaEnOtraCadena(cadenaIngresada, pCadenaResultante);
                break;
            }
            else
            {
                printf("%s", mensajeError);
            }
        }
        else
        {
            printf("Error\n");
            retorno = -1;
        }
        cantidadDeIntentos++;
    }while(cantidadDeIntentos<reintentos);
    return retorno;
}
/**
* \brief Valida si una cadena tiene una longitud entre un maximo y un minimo
* \param longitudCadenaIngresada Es la longitud que se va a evaluar si esta entre el minimo y el maximo (incluidos)
* \param longitudMinima Es la longitud de la cadena minima aceptada
* \param longitudMaxima Es la longitud de la cadena maxima aceptada
* \return En caso de exito retorna 0, si esta fuera del rango de longitud 1
*
*/
int utn_validarLongitudDeLaCadena(int longitudCadenaIngresada, int longitudMinima, int longitudMaxima)
{
    int retorno;
    if(longitudCadenaIngresada >= longitudMinima && longitudCadenaIngresada <= longitudMaxima)
    {
        retorno = 0;
    }
    else if(longitudCadenaIngresada < longitudMinima || longitudCadenaIngresada > longitudMaxima)
    {
        retorno = 1;
    }
    return retorno;
}
/**
* \brief Copia el contenido de una cadena otra
* \param pCadenaInicial Es la cadena que se recibe
* \param pCadenaCopiada Es la cadena donde se va a copiar el contenido
* \return En caso de exito retorna 0, si se produce un error devuelve 1
*
*/
int utn_copiarCadenaEnOtraCadena(char *pCadenaInicial, char *pCadenaCopiada)
{
    while(*pCadenaInicial!='\0')
    {
        *pCadenaCopiada = *pCadenaInicial;
        pCadenaInicial++;
        pCadenaCopiada++;
    }
    *pCadenaCopiada = '\0';
    return 0;
}
/**
* \brief Obtiene la longitud de la cadena
* \param pCadenaIngresada Es la cadena que se recibe
* \return Retorna el valor de la longitud
*
*/
int utn_obtenerLongitudCadena(char *pCadenaIngresada)
{
    int longitudCadena = 0;
    while(*pCadenaIngresada!='\0')
    {
        longitudCadena++;
        pCadenaIngresada++;
    }
    return longitudCadena;
}
/**
* \brief Verifica si la cadena ingresada puede ser un mail valido o no
* \param pPosibleMail Es la cadena que vamos a evaluar
* \return Retorna un 0 si puede ser un mail y un 1 si no
*
*/
int utn_validarMail(char *pPosibleMail)
{
    int contadorPosicionesTrasCaracterImportante=0;
    int retorno = 0;
    int contadorDeArrobas = 0;
    int contadorDePuntosTrasArroba = 0;
    while(*pPosibleMail!='\0')
    {
        if(*pPosibleMail == '@')
        {
            if(contadorDeArrobas>0)
            {
                printf("El Mail puede contener un unico @\n");
                retorno = 1;
                break;
            }
            if(contadorPosicionesTrasCaracterImportante == 0)
            {
                printf("Debe ingresar algun caracter antes del @\n");
                retorno = 1;
                break;
            }
            contadorDeArrobas++;
            contadorPosicionesTrasCaracterImportante = -1;
        }
        else if(*pPosibleMail==' ')
        {
            printf("El Mail no puede contener espacios\n");
            retorno = 1;
            break;
        }
        else if(contadorDeArrobas==1 && *pPosibleMail == '.')
        {
            if(contadorPosicionesTrasCaracterImportante == 0)
            {
                printf("Debe ingresar algun caracter antes del '.'\n");
                retorno = 1;
                break;
            }
            contadorDePuntosTrasArroba++;
            contadorPosicionesTrasCaracterImportante = -1;
        }
        contadorPosicionesTrasCaracterImportante++;
        pPosibleMail++;
    }
    if(retorno == 0)
    {
        if(contadorDeArrobas == 1 && contadorDePuntosTrasArroba>0 && contadorPosicionesTrasCaracterImportante>0)
        {
            retorno = 0;
        }
        else
        {
            printf("El mail debe contener un @ y luego un .(dominio)");
            retorno = 1;
        }
    }
    return retorno;
}
/**
* \brief imprime un resultado, el error producido en la operacion o un error en caso de que se pase otro valor
* \param opcionAMostrar Debe valer 0 o 1 para que el usuario la vea
* \param mensajeResultado mensaje que se muestra cuando opcionAMostrar es 0
* \param resultado Es el flotante que muestra el resultado obtenido
* \param mensajeNoExisteResultado mensaje que se muestra cuando opcionAMostrar es 1
* \param mensajeError mensaje que se muestra cuando opcionAMostrar es distinta de 0 y 1
*
*/
void utn_imprimirResultadoFloatOErrorEnPantalla(int opcionAMostrar,
                                                char mensajeResultado[],
                                                float resultado,
                                                char mensajeNoExiteResultado[],
                                                char mensajeError[])
{
    if(opcionAMostrar == 0)
    {
        printf("%s %.5f\n", mensajeResultado, resultado);
    }
    else if(opcionAMostrar == 1)
    {
        printf("%s\n", mensajeNoExiteResultado);
    }
    else
    {
        printf("%s\n", mensajeError);
    }
}
/**
* \brief imprime un resultado, el error producido en la operacion o un error en caso de que se pase otro valor
* \param opcionAMostrar Debe valer 0 o 1 para que el usuario la vea
* \param mensajeResultado mensaje que se muestra cuando opcionAMostrar es 0
* \param resultado Muestra el resultado obtenido si la operacion es correcta
* \param mensajeNoExisteResultado mensaje que se muestra cuando opcionAMostrar es 1
* \param mensajeError mensaje que se muestra cuando opcionAMostrar es distinta de 0 y 1
*
*/
void utn_imprimirResultadoLongLongOErrorEnPantalla( int opcionAMostrar,
                                                    char mensajeResultado[],
                                                    unsigned long long int resultado,
                                                    char mensajeNoExiteResultado[],
                                                    char mensajeError[])
{
    if(opcionAMostrar == 0)
    {
        printf("%s %llu\n", mensajeResultado, resultado);
    }
    else if(opcionAMostrar == 1)
    {
        printf("%s\n", mensajeNoExiteResultado);
    }
    else
    {
        printf("%s\n", mensajeError);
    }
}




