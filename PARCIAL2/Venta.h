#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED
#include "LinkedList.h"
typedef struct
{
  int id;
  char fecha[11];
  char producto[50];
  int cantidad;
  float precio;
  char cuit[20];
}Venta;
Venta* Venta_new();
void Venta_delete(Venta* this);
Venta* Venta_newConParametros(  char* id,char* fecha,char* producto,
                                char* cantidad,char* precio, char* cuit);
int Venta_setId(Venta* this,int id);
int Venta_getId(Venta* this,int* id);
int Venta_setFecha(Venta* this,char* fecha);
int Venta_getFecha(Venta* this,char* fecha);
int Venta_setProducto(Venta* this,char* producto);
int Venta_getProducto(Venta* this,char* producto);
int Venta_setCantidad(Venta* this,int cantidad);
int Venta_getCantidad(Venta* this,int* cantidad);
int Venta_setPrecio(Venta* this,float precio);
int Venta_getPrecio(Venta* this,float* precio);
int Venta_setCuit(Venta* this,char* cuit);
int Venta_getCuit(Venta* this,char* cuit);
int Venta_setAll(   Venta* this, int id, char* fecha, char* producto,
                    int cantidad, float precio, char* cuit);
int Venta_CalculoMonto(Venta* this, float* monto);
int Venta_filtroPorMontoMayor(void* thisVoid, char* montoString);
int Venta_cantidadUnidades(void* thisVoid);
int Venta_filtroPorProducto(void* thisVoid, char* producto);

#endif // VENTA_H_INCLUDED
