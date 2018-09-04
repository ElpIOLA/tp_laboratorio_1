int utn_getEntero(  int *pResultado,
                    char mensaje[],
                    char mensajeError[],
                    int  minimo,
                    int  maximo,
                    int  reintentos);

int utn_validarEnteroEnIntervalo(int numero, int minimo, int maximo);

int utn_getFlotante(float *pResultado,
                    char mensaje[],
                    char mensajeError[],
                    int reintentos);

int utn_getFlotanteEnIntervalo(float *pResultado,
                    char mensaje[],
                    char mensajeError[],
                    float minimo,
                    float maximo,
                    int reintentos);

int utn_validarFlotanteEnIntervalo(float numeroIngresado, float minimo, float maximo);

int utn_getCaracter(char *pCaracterResultante,
                    char mensaje[],
                    char mensajeError[],
                    char minimo,
                    char maximo,
                    int reintentos);

int utn_validarCaracterEnIntervalo(char caracterIngresado, char minimo, char maximo);

int utn_getCadena(  char *pCadenaResultante,
                    char mensaje[],
                    char mensajeError[],
                    int longitudMinima,
                    int longitudMaxima,
                    int reintentos);

int utn_validarLongitudDeLaCadena(int longitudCadenaIngresada, int longitudMinima, int longitudMaxima);

int utn_copiarCadenaEnOtraCadena(char *pCadenaInicial, char *pCadenaCopiada);

int utn_obtenerLongitudCadena(char *cadenaIngresada);

int utn_validarMail(char *pPosibleMail);

void utn_imprimirResultadoFloatOErrorEnPantalla(int opcionAMostrar,
                                                char mensajeResultado[],
                                                float resultado,
                                                char mensajeNoExiteResultado[],
                                                char mensajeError[]);

void utn_imprimirResultadoLongLongOErrorEnPantalla( int opcionAMostrar,
                                                    char mensajeResultado[],
                                                    unsigned long long int resultado,
                                                    char mensajeNoExiteResultado[],
                                                    char mensajeError[]);
