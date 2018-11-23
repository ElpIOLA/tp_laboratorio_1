#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Venta.h"
#include "Parser.h"
#include "utn.h"
#include "string.h"
int main()
{
    LinkedList* listaVentas = ll_newLinkedList();
    if(!parser_loadFromText("data.csv",listaVentas))
    {
        /*printf( "Cantidad Unidades: %d\n",
                ll_count_(listaVentas,Venta_cantidadUnidades));
        printf( "Ventas Mayores a 10000: %d\n",
                ll_count(listaVentas,Venta_filtroPorMontoMayor,"10000"));
        printf( "Ventas Mayores a 20000: %d\n",
                ll_count(listaVentas,Venta_filtroPorMontoMayor,"20000"));
        printf( "Cantidad de TV_LCD: %d\n",
                ll_count(listaVentas,Venta_filtroPorProducto,"LCD_TV"));*/
        parser_generateInforme("informe.csv", listaVentas);
    }

    return 0;
}
