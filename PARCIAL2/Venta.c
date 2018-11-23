#include "Venta.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
/**
 * \brief Evalua si se trata de un id valido
 *
 * \param pBuffer Es la cadena que evaluamos
 * \param limite Es el numero maximo de cifras
 * \return En caso de exito retorna 1, si no 0
 *
 */
static int isValidId(char *pBuffer, int limite)
{
    int retorno;
    retorno = utn_isValidEnteroSoloNumeros(pBuffer,limite);
    return retorno;
}
static int isValidFecha(char *pBuffer, int limite)
{
    int retorno;
    /*int dia;
    int mes;
    int anio;
    char* diaS;
    char* mesS;
    char* anioS;
    char* token;
    token = strtok(pBuffer, "/");
    strncpy(diaS, token, 1024);
    token = strtok(NULL, "/");
    strncpy(mesS, token, 1024);
    token = strtok(NULL, "\n");
    strncpy(anioS, token, 1024);
    dia = atoi(diaS);
    mes = atoi(mesS);
    anio = atoi(anioS);*/
    retorno = 1; //utn_isValidFecha(dia,mes,anio);
    return retorno;
}
static int isValidProducto(char *pBuffer, int limite)
{
    int retorno;
    retorno = 1;
    return retorno;
}
/**
 * \brief Evalua si se trata de una cantidad
 *
 * \param pBuffer Es la cadena que evaluamos
 * \param limite Es el numero maximo de cifras
 * \return En caso de exito retorna 1, si no 0
 *
 */
static int isValidCantidad(char *pBuffer, int limite)
{
    int retorno;
    retorno = utn_isValidEnteroSoloNumeros(pBuffer,limite);
    return retorno;
}
/**
 * \brief Evalua si se trata de un precio
 *
 * \param pBuffer Es la cadena que evaluamos
 * \param limite Es el numero maximo de cifras
 * \return En caso de exito retorna 1, si no 0
 *
 */
static int isValidPrecio(char *pBuffer, int limite)
{
    int retorno;
    retorno = utn_isValidFloatPositivo(pBuffer,limite);
    return retorno;
}
/**
 * \brief Evalua si se trata de un cuit
 *
 * \param pBuffer Es la cadena que evaluamos
 * \param limite Es el numero maximo de cifras
 * \return En caso de exito retorna 1, si no 0
 *
 */
static int isValidCuit(char *pBuffer, int limite)
{
    int retorno;
    retorno = utn_isValidCuilOrCuit(pBuffer,limite);
    return retorno;
}
/**
 * \brief Asigna el espacio de memoria para la creacion de una venta
 * \return Venta* En caso de exito retorna el puntero a la venta, si no NULL
 *
 */
Venta* Venta_new()
{
    Venta* this;
    this=malloc(sizeof(Venta));
    return this;
}
/**
 * \brief Libera el espacio de memoria donde se encontraba la venta utilizando free()
 *
 * \param this Employee* Es el empleado que se desea eliminar
 * \return Int En caso de exito retorna 1, si no 0
 *
 */
void Venta_delete(Venta* this)
{
    free(this);
}
/**
 * \brief Asigna el espacio de memoria para la creacion de un venta con todos sus atributos cargados
 * \return Employee* En caso de exito retorna el puntero al empleado, si no NULL
 *
 */
Venta* Venta_newConParametros(  char* id,char* fecha,char* producto,
                                char* cantidad,char* precio, char* cuit)
{
    Venta* this;
    this=Venta_new();
    Venta* retorno = NULL;
    int idInt = atoi(id);
    int cantidadInt = atoi(cantidad);
    float precioFloat = atof(precio);
    if( isValidId(id,15) &&
        isValidFecha(fecha,11) &&
        isValidProducto(producto,50) &&
        isValidCantidad(cantidad,15) &&
        isValidPrecio(precio,20) &&
        isValidCuit(cuit,20) &&
        !Venta_setAll(this, idInt, fecha,producto,cantidadInt,precioFloat,cuit))
    {
        retorno = this;
    }
    else
    {
        Venta_delete(this);
    }
    return retorno;
}
/**
 * \brief Setter del id
 *
 * \param this Venta* Es la venta donde se guarda el id
 * \param int id Es el id que se guarda en la venta
 * \return En caso de exito retorna 1, si no 0
 *
 */
int Venta_setId(Venta* this,int id)
{
    int retorno=-1;
    static int proximoId=-1;

    if(this!=NULL && id==-1)
    {
        proximoId++;
        this->id=proximoId;
        retorno=0;
    }
    else if(id>proximoId)
    {
        proximoId=id;
        this->id=proximoId;
        retorno=0;
    }
    return retorno;
}

int Venta_getId(Venta* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int Venta_setFecha(Venta* this,char* fecha)
{
    int retorno=-1;
    if(this!=NULL && fecha!=NULL)
    {
        strcpy(this->fecha,fecha);
        retorno=0;
    }
    return retorno;
}

int Venta_getFecha(Venta* this,char* fecha)
{
    int retorno=-1;
    if(this!=NULL && fecha!=NULL)
    {
        strcpy(fecha,this->fecha);
        retorno=0;
    }
    return retorno;
}

int Venta_setProducto(Venta* this,char* producto)
{
    int retorno=-1;
    if(this!=NULL && producto!=NULL)
    {
        strcpy(this->producto,producto);
        retorno=0;
    }
    return retorno;
}

int Venta_getProducto(Venta* this,char* producto)
{
    int retorno=-1;
    if(this!=NULL && producto!=NULL)
    {
        strcpy(producto,this->producto);
        retorno=0;
    }
    return retorno;
}

int Venta_setCantidad(Venta* this,int cantidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->cantidad=cantidad;
        retorno=0;
    }
    return retorno;
}

int Venta_getCantidad(Venta* this,int* cantidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *cantidad=this->cantidad;
        retorno=0;
    }
    return retorno;
}

int Venta_setPrecio(Venta* this,float precio)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->precio=precio;
        retorno=0;
    }
    return retorno;
}

int Venta_getPrecio(Venta* this,float* precio)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *precio=this->precio;
        retorno=0;
    }
    return retorno;
}

int Venta_setCuit(Venta* this,char* cuit)
{
    int retorno=-1;
    if(this!=NULL && cuit!= NULL)
    {
        strcpy(this->cuit,cuit);
        retorno=0;
    }
    return retorno;
}

int Venta_getCuit(Venta* this,char* cuit)
{
    int retorno=-1;
    if(this!=NULL && cuit!=NULL)
    {
        strcpy(cuit,this->cuit);
        retorno=0;
    }
    return retorno;
}
int Venta_setAll(   Venta* this, int id, char* fecha, char* producto,
                    int cantidad, float precio, char* cuit)
{
    int retorno = -1;
    if( !Venta_setId(this, id) &&
        !Venta_setFecha(this, fecha)&&
        !Venta_setProducto(this, producto) &&
        !Venta_setCantidad(this,cantidad) &&
        !Venta_setPrecio(this, precio)&&
        !Venta_setCuit(this, cuit))
    {
        retorno = 0;
    }
    return retorno;
}
/**
 * \brief Calcula el monto de una venta
 *
 * \param this Venta* Es la venta que se calcula el monto
 * \param monto float* Se retorna el monto
 * \return Int En caso de exito retorna 0, si no -1
 *
 */
int Venta_CalculoMonto(Venta* this, float* monto)
{
    int retorno = -1;
    int cantidad;
    float precio;
    if(this != NULL && !Venta_getCantidad(this, &cantidad) && !Venta_getPrecio(this, &precio))
    {
        *monto = precio * cantidad;
        retorno = 0;
    }
    return retorno;

}
/**
 * \brief Filtra las ventas por el monto total
 *
 * \param this Venta* Es la venta que se calcula el monto
 * \param montoString char* Es el monto al que debe ser mayor
 * \return Int En caso de que sea mayor retorna 1, si no 0
 *
 */
int Venta_filtroPorMontoMayor(void* thisVoid, char* montoString)
{
    Venta* this = (Venta*) thisVoid;
    int retorno = 0;
    float monto = atof(montoString);
    float montoThis;

    if( this != NULL && !Venta_CalculoMonto(this,&montoThis) &&
        montoThis > monto)

    {
        retorno = 1;
    }
    return retorno;
}
/**
 * \brief Filtra las ventas por el monto total
 *
 * \param thisVoid void* Es la venta donde se evalua la cantidad
 * \return Int Retorna la cantidad de unidades
 *
 */
int Venta_cantidadUnidades(void* thisVoid)
{
    Venta* this = (Venta*) thisVoid;
    int retorno = 0;
    int unidades;

    if(this != NULL && !Venta_getCantidad(this, &unidades))
    {
        retorno = unidades;
    }
    return retorno;
}
/**
 * \brief Filtra las ventas por el nombre del producto
 *
 * \param this Venta* Es la venta que tiene el producto a evaluar
 * \param producto char* Es el nombre del producto a comparar
 * \return Int En caso de que sea igual retorna 1, si no 0
 *
 */
int Venta_filtroPorProducto(void* thisVoid, char* producto)
{
    Venta* this = (Venta*) thisVoid;
    int retorno = 0;
    char productoThis[1024];
    Venta_getProducto(this,productoThis);
    if(this != NULL && strcmp(producto,productoThis) == 0)
    {
        retorno = 1;
    }
    return retorno;
}
