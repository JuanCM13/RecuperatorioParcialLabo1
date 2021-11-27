#include "nombres.h"


//----------------------------------------------------------------------------------------------------------------------


int Get_NombreEmpresa(char mensaje[], char mensajeError[], char cadena[], int rango)
{
    int ret;
    int respuesta;

    ret = -1;

    if(mensajeError != NULL && mensaje != NULL && cadena != NULL && rango > 0)
    {
        do
	    {
	        respuesta = Get_string (mensaje, mensajeError, cadena, rango);

            switch (respuesta)
            {
                case -3:
                    printf("El nombre/apellido no puede estar compuesto por numeros, solo letras..\n");
                break;
                case -2:
                    printf("El nombre/apellido ingresado no puede ser tan largo..\n");
                break;
                case -1:
                    printf("Algo salio mal con la carga del nombre/apellido, reintente..\n");
                break;
                case 0:
              //convertirEnNombre(cadena , rango);
                    ret = 0;
                break;
            }

	    }while (respuesta != 0);

    }

    return ret;
}

//----------------------------------------------------------------------------------------------------------------------


int Get_string (char mensaje[], char mensajeError[], char cadena[], int rango)
{
    int ret;
    char aux[1000];
    int respuesta;

    ret = -1;

    if(mensajeError != NULL && mensaje != NULL && cadena != NULL && rango > 0)
    {
        printf ("%s \n", mensaje);
        fflush(stdin);
        scanf ("%[^\n]", aux);

        respuesta = sonLetras (aux, sizeof (aux));
        switch (respuesta)
	    {
            case 0:

                if (strlen(aux) > rango)
                {
                    ret = -2;		//--- no puede ser tan largo el texto a ingresar...
                }
        	    else
        	    {
        	        ret = 0;		// se logro cargar bien...
        	        strcpy (cadena,aux);
        	    }

            break;
            case -1:

	            ret = -1;		//algo fallo con la carga---

	        break;
	        case -2:

	            ret = -3;		// no pueden ser numeros, solo letras

	        break;
	    }
    }

    return ret;
}

//----------------------------------------------------------------------------------------------------------------------

int sonLetras (char cadena[], int rango)
{
    int i;
    int ret;

    ret = -1;

    if(cadena != NULL && rango > 0)
    {
        ret = 0;

        for (i = 0; cadena[i] != '\0'; i++)
	    {
	        if (!( (cadena[i] >= 'a' && cadena[i] <= 'z') || (cadena[i] >= 'A' && cadena[i] <= 'Z') || cadena[i] == 32))
            {
	            ret = -2;
	            break;
	        }
	    }
    }

    return ret;

}

//----------------------------------------------------------------------------------------------------------------------

int OrdenarNombre(char lista[], int rango)
{
    int ret;
    int i;

    ret = -1;

    if(lista != NULL && rango > 0)
    {
        ret = 0;

        for (int i = 0; lista[i] != '\0'; i++)	// hago esto para que ande en gdb (descomentar y comentar strlw)
	    {
	        lista[i] = tolower (lista[i]);
	    }

        for(i = 0; i < rango; i++)
        {
	        if(i == 0 || lista[i-1] == 32)
	        {
	            lista[i] = toupper(lista[i]);
	        }
	    }
    }

    return ret;
}

//----------------------------------------------------------------------------------------------------------------------
