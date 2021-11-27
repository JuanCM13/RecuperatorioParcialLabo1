#include "input.h"


//----------------------------------------------------------------------------------------------------------------------


int Get_numeroConLimites(char mensaje[] , char mensajeError[] , int minimo , int maximo , int* numero)
{

    int retorno;
    int bufferAux;
    char buffer[1000];

    retorno = -1;

    if(mensajeError != NULL && mensaje != NULL && minimo <= maximo && numero != NULL) //REVISAR ESTO CON SORT EMPLOYEE
    {
        do
        {
            printf("%s\n",mensaje);
            fflush(stdin);
            scanf("%[^\n]",buffer);

            if(esNumero(buffer , 1000) == 0)
            {
                bufferAux = atoi(buffer);

                if(bufferAux >= minimo && bufferAux <= maximo)
                {
                    *numero = bufferAux;
                    retorno = 0;
                    break;
                }
            }

            printf("%s\n",mensajeError);

        }while(1);
    }

    return retorno;
}

//----------------------------------------------------------------------------------------------------------------------


int Get_floatConLimites(char mensaje[] , char mensajeError[] , float minimo , float maximo , float* numero)
{
    int retorno;
    float bufferAux;
    char buffer[1000];

    retorno = -1;

    if(mensajeError != NULL && mensaje != NULL && minimo <= maximo && numero != NULL)
    {
        do
        {
            printf("%s\n",mensaje);
            fflush(stdin);
            scanf("%[^\n]",buffer);

            esFloat(buffer , 1000);
			bufferAux = atof(buffer);

			if(bufferAux >= minimo && bufferAux <= maximo)
			{
				*numero = bufferAux;
				retorno = 0;
				break;
			}

            printf("%s\n",mensajeError);

        }while(1);
    }

    return retorno;
}

//----------------------------------------------------------------------------------------------------------------------


int esFloat(char cadena[] , int rango)
{
    int ret;
    int i;
    int contadorPunto;

    ret = -1;
    contadorPunto = 0;

    if(cadena != NULL && rango > 0)
    {
        ret = 0;

        for(i=0; cadena[i] != '\0' ; i++)
        {
            if(cadena[i] == '.'  || !(cadena[i] >= '0' && cadena[i] <= '9') || (i == 0 && cadena[0] == '-') )
            {
                if( (i == 0 && cadena[0] == '-' ) || contadorPunto == 0)
                {
                    contadorPunto = 1;
                    continue;
                }
                else
                {
                    ret = -2;
                    break;
                }
            }
        }
    }

    return ret;
}

//----------------------------------------------------------------------------------------------------------------------


int esNumero(char cadena[] , int rango)
{
    int ret;
    int i;

    ret = -1;

    if(cadena != NULL && rango > 0)
    {
        ret = 0;

        for(i=0; cadena[i] != '\0' ; i++)
        {
            if(cadena[i] < '0' || cadena[i] > '9' || (i == 0 && cadena[0] == '-') )
            {
                if(i == 0 && cadena[0] == '-')
                {
                    continue;
                }
                else
                {
                    ret = -2;
                    break;
                }
            }
        }
    }

    return ret;
}
//----------------------------------------------------------------------------------------------------------------------


int QueresSeguir(char mensaje[])
{
    int ret;
    char respuesta;

    ret = -1;

    if(mensaje != NULL)
    {
        printf("%s\n",mensaje);
        fflush(stdin);
        scanf("%c",&respuesta);

        if(respuesta == 's' || respuesta == 's')
        {
            ret = 0;
        }
    }

    return ret;
}

//----------------------------------------------------------------------------------------------------------------------


int get_promedio(float acumulado , int divisor , float* promedio)
{
    int ret;
    float resultado;

    ret = -1;

    if(promedio != NULL && divisor > 0)
    {
        resultado = acumulado / divisor;
        *promedio = resultado;
        ret = 0;
    }

    return ret;
}

//----------------------------------------------------------------------------------------------------------------------


int Get_cadena(char mensaje[] ,char mensajeError[] , char cadena[] , int rango)
{
    int ret;
    char auxiliar[1000];

    ret = -1;

    if(mensaje != NULL && cadena != NULL && rango > 0)
    {
        do
        {
            printf ("%s \n", mensaje);
            fflush(stdin);
            scanf ("%[^\n]", auxiliar);

            if(strlen(auxiliar) < rango)
            {
                strcpy(cadena , auxiliar);
                ret = 0;
                break;
            }

            printf("%s\n",mensajeError);

        }while(1);
    }

    return ret;
}


//----------------------------------------------------------------------------------------------------------------------
