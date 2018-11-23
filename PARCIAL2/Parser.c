#include "LinkedList.h"
#include "Venta.h"
#include "stdio.h"
#include "string.h"
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto)
 *
 * \param fileName char* Es el nombre del archivo donde se encuentran las ventas
 * \param lista LinkedList* Es la LinkedList donde se guardan las ventas cargados
 * \return int retorna 0 si el archivo se cargo correctamente, y 1 si no se pudo cargar.
 *
 */
int parser_loadFromText(char* fileName, LinkedList* lista)
{
    int retorno = -1;
    char bufferLine[1024];
    char* delimitador = ",";
    char* token;

    char bufferId[1024];
    char bufferFecha[1024];
    char bufferProducto[1024];
    char bufferCantidad[1024];
    char bufferPrecio[1024];
    char bufferCuit[1024];

    int flagOnce = 1;
    Venta* pVenta = NULL;
    FILE* pFile;
    pFile = fopen(fileName,"r");
    if(pFile!=NULL)
    {
        while(!feof(pFile))
        {
            if(flagOnce && fscanf(pFile,"%[^\n]\n",bufferLine))
            {
                flagOnce = 0;
            }
            if(fscanf(pFile,"%[^\n]\n",bufferLine))
            {
                token = strtok(bufferLine, delimitador);
                strncpy(bufferId, token, 1024);
                token = strtok(NULL, delimitador);
                strncpy(bufferFecha, token, 1024);
                token = strtok(NULL, delimitador);
                strncpy(bufferProducto, token, 1024);
                token = strtok(NULL, delimitador);
                strncpy(bufferCantidad, token, 1024);
                token = strtok(NULL, delimitador);
                strncpy(bufferPrecio, token, 1024);
                token = strtok(NULL, delimitador);
                strncpy(bufferCuit, token, 1024);
                pVenta = Venta_newConParametros(bufferId,bufferFecha,bufferProducto,
                                                bufferCantidad,bufferPrecio,bufferCuit);
            }
            if(pVenta != NULL)
            {
                retorno = 0;
                ll_add(lista, pVenta);
            }
        }
    }
    return retorno;
}
/** \brief Guarda el informe de las ventas
 *
 * \param fileName char* Es el nombre del archivo donde se guardan los informes
 * \param listaVentas LinkedList* Es la LinkedList donde se guardan las ventas
 * \return int retorna 0 si el archivo se guardo correctamente, y 1 si no se pudo cargar.
 *
 */
int parser_generateInforme(char* fileName, LinkedList* listaVentas)
{
    int retorno = -1;
    FILE* pFile = fopen(fileName,"w");
    if(pFile != NULL)
    {
        retorno = 0;
        fprintf(pFile,"Cantidad Unidades: %d\n",
                ll_count_(listaVentas,Venta_cantidadUnidades));
        fprintf(pFile,"Ventas Mayores a 10000: %d\n",
                ll_count(listaVentas,Venta_filtroPorMontoMayor,"10000"));
        fprintf(pFile,"Ventas Mayores a 20000: %d\n",
                ll_count(listaVentas,Venta_filtroPorMontoMayor,"20000"));
        fprintf(pFile,"Cantidad de TV_LCD: %d\n",
                ll_count(listaVentas,Venta_filtroPorProducto,"LCD_TV"));
    }
    return retorno;
}
