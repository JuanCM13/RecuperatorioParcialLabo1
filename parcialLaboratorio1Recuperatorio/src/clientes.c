#include "clientes.h"

int inicializarArrayClientes(eCliente lista[] , int rango)
{
    int ret;
    int i;

    ret = -1;

    if(lista != NULL && rango > 0)
    {
        ret = 0;
        //0 para el hardcodeo
        for(i=6 ; i<rango ; i++)
        {
            lista[i].isEmpty = 1;
        }
    }

    return ret;
}

//-------------------------------------------------------------------------------------------------------------------

int desplegarMenu(int* respuesta)
{
    int aux;
    int ret;

    ret = -1;

    if(respuesta != NULL)
    {
        printf("\n\n|----------------------------------------MENU--------------------------------------------------|\n");
        printf("|   1) Alta de cliente                                                                         |\n");
        printf("|   2) Modificar datos de cliente                                                              |\n");
        printf("|   3) Baja de cliente                                                                         |\n");
        printf("|   4) Crear pedido de recolección                                                             |\n");
        printf("|   5) Procesar residuos                                                                       |\n");
        printf("|   6) Imprimir Clientes                                                                       |\n");
        printf("|   7) Imprimir Pedidos pendientes                                                             |\n");
        printf("|   8) Imprimir Pedidos procesados                                                             |\n");
        printf("|   9) Ingresar una localidad e indicar la cantidad de pedidos pendientes para dicha localidad |\n");
        printf("|   10) Cantidad de kilos de polipropileno reciclado promedio por cliente                      |\n");
        printf("|   11) Cliente con más pedidos pendientes                                                     |\n");
        printf("|   12) Cliente con más pedidos completados                                                    |\n");
        printf("|   13) Cliente con más pedidos                                                                |\n");
        printf("|   0)  SALIR                                                                                  |\n");
        printf("|----------------------------------------------------------------------------------------------|\n\n");

        if(Get_numeroConLimites("SELECCIONE UNA OPCION..", "ERROR, INGRESE UNA OPCION ENTRE LAS MOSTRADAS..",0,14,&aux) == 0)
        {
            ret = 0;
            *respuesta = aux;
        }
    }

    return ret;
}

//-------------------------------------------------------------------------------------------------------------------

int isEmptyClientes(eCliente lista[] , int rango)
{
    int i;
    int ret;

    ret = -1;

    if(lista != NULL && rango > 0)
    {
        for(i=0 ; i<rango ; i++)
        {
            if(lista[i].isEmpty == 0)
            {
                ret = 0;
                break;
            }
        }
    }

    return ret;
}

//-------------------------------------------------------------------------------------------------------------------

int hayLugar(eCliente lista[] , int rango)
{
    int i;
    int ret;

    ret = -1;

    if(lista != NULL && rango > 0)
    {
        for(i=0 ; i<rango ; i++)
        {
            if(lista[i].isEmpty == 1)
            {
                ret = 0;
                break;
            }
        }
    }

    return ret;
}

//----------------------------------------------------------------------------------------------

eCliente generarCliente(int* id)
{
    eCliente auxiliar;
    int resultadoId;

    Get_NombreEmpresa("Ingrese el nombre de la empresa.." , "El nombre de la empresa no puede ser tan grande.." , auxiliar.nombreEmpresa , TAMNOMBRE);
    OrdenarNombre(auxiliar.nombreEmpresa , TAMNOMBRE);


    Get_cuit("Ingrese el cuit, 11 numeros sin guiones ni espacios..", "Respete el formato del ejemplo: EJ: 20123456789", auxiliar.cuit , TAMCUIT);


    Get_cadena("Ingrese la direccion donde vive...", "Error, la direccion no puede ser tan larga, reingrese..",auxiliar.direccion, TAMDIRECCION);

    OrdenarNombre(auxiliar.direccion , TAMDIRECCION);



    Get_numeroConLimites("Ingrese la localidad por el momento solo admitimos  1- Lanus , 2- Lomas De Zamora , 3- Quilmes , 4- Avellaneda , 5- Recoleta...",
                           "Error, ingrese una localidad entre las dadas..", 1 , 5 , &auxiliar.idRelacionLocalidad);


    if(QueresSeguir("Esta seguro de cargar este empleado? s/n...") == 0)
    {
        resultadoId = incrementarId(id);

        if(resultadoId != -1)
        {
            auxiliar.id = resultadoId;
            auxiliar.isEmpty = 0;
            printf("\nEl cliente fue cargado con exito.\nSu id para identificarlo es:  %d\n",*id);
            printf("\n---Si se equivoco en el ingreso de algun dato, podra modificarlo luego en la opcion 2 del menu..\n");
        }
    }

    return auxiliar;
}

//----------------------------------------------------------------------------------------------

int cargarCliente(eCliente listaClientes[], int rango , int* id)
{
    int i;
    int retorno;
    retorno = -1;

    for(i=0 ; i<rango ; i++)
    {
        if(listaClientes[i].isEmpty != 0)
        {
            listaClientes[i] = generarCliente(id);
            retorno = 0;
            break;
        }
    }

    return retorno;
}

//----------------------------------------------------------------------------------------------

int incrementarId(int* id)
{
    int ret;

    ret = -1;

    if(id != NULL)
    {
        ret = *id + 1;
        *id = ret;
    }

    return ret;
}

//----------------------------------------------------------------------------------------------

int Get_cuit(char mensaje[] , char mensajeError[] , char cadena[] , int rango)
{
    int ret;
    char auxiliar[12];
    int i;
    int j;
    int respuesta;

    ret = -1; //fallaron los nulls etc

    if(mensaje != NULL && mensajeError != NULL && cadena != NULL && rango > 0)
    {
        do
        {

            if(ingresarCuit(mensaje ,  auxiliar , 12) == 0)
            {
                if(strlen(auxiliar) == 11)
                {
                    if(esNumero(auxiliar , 12) == 0) //xxxxx
                    {
                        respuesta = 1;
                        break;
                    }
                    else
                    {
                        printf("El cuit debe estar compuesto solo por numeros...\n");
                    }
                }
                else
                {
                    printf("El cuit debe tener 11 numeros, ni mas ni menos.. reintente\n");
                }
            }
            else
            {
                printf("Algo fallo, reintente..\n");
            }


            printf("%s\n",mensajeError);


        }while(1);

            if(respuesta == 1)
            {
                j=0;

                for(i=0 ; i < 13 ; i++)
                {
                    if(i != 2 && i != 11)
                    {
                        cadena[i] = auxiliar[j];
                        j++;
                    }
                    else
                    {
                        cadena[i] = '-';
                    }
                }

                ret = 0;
            }
    }

    return ret;
}

//----------------------------------------------------------------------------------------------

int ingresarCuit(char mensaje[] , char cadena[] , int rango)
{
    int ret;
    char auxiliar[1000];

    ret = -1;

    if(mensaje != NULL && cadena != NULL && rango > 0)
    {
            ret = 0;
            printf ("%s \n", mensaje);
            fflush(stdin);
            scanf ("%[^\n]", auxiliar);

            if(strlen(auxiliar) < rango)
            {
                strcpy(cadena , auxiliar);
            }
    }

    return ret;
}
//-----------------------------------------------------------------------------------------------

int mostrarClientesAux(eCliente lista[], int rango)
{
    int ret;
    int i;

    ret = -1;

    if(lista != NULL && rango > 0)
    {
        ret = 0;
        printf("----------------------------------------------------------------------------|\n");
        printf(" ID         NOMBRE                 DIRECCION                CUIT            |\n");
        printf("----------------------------------------------------------------------------|\n");
        for(i=0 ; i<rango ; i++)
        {
            if(lista[i].isEmpty == 0)
            {
                printf("\n%-10d  %-21s  %-21s  %-21s   \n ",lista[i].id ,lista[i].nombreEmpresa, lista[i].direccion,
                                                                 lista[i].cuit);
            }
        }
        printf("----------------------------------------------------------------------------|\n\n");

    }
    return ret;
}

//-----------------------------------------------------------------------------------------------

int get_id(eCliente lista[] , int rango , int* id , char mensaje[] , char mensajeError[])
{
    int ret;
    int aux;

    ret = -1;

    if(id != NULL && mensaje != NULL && mensajeError != NULL && lista != NULL && rango > 0)
    {
        mostrarClientesAux(lista, rango);

        if(Get_numeroConLimites(mensaje , mensajeError, 0 ,INT_MAX , &aux) == 0)
        {
            *id = aux;
            ret = 0;
        }
    }

    return ret;
}

//-----------------------------------------------------------------------------------------------

int encontrarId(eCliente lista[], int rango , int idAencontrar)
{
    int ret;
    int i;

    ret = -1;

    if(lista != NULL && rango > 0 && idAencontrar > 0)
    {
        for(i=0 ; i<rango ; i++)
        {
            if(lista[i].id == idAencontrar)
            {
                if(lista[i].isEmpty == 0)
                {
                    ret = i;
                }
            }
        }
    }

    return ret;
}

//-----------------------------------------------------------------------------------------------

int contadorTotalClientes(eCliente lista[] , int rango , int* contador)
{
    int ret;
    int aux;
    int i;

    ret = -1;

    if(lista != NULL && contador != NULL && rango > 0)
    {
        aux = 0;

        for(i=0 ; i<rango ; i++)
        {
            if(lista[i].isEmpty == 0)
            {
                aux++;
            }
        }
    }

    if(aux > 0)
    {
        *contador = aux;
        ret = 0;
    }

    return ret;
}

//-----------------------------------------------------------------------------------------------

int modificarCliente(eCliente lista[] , int rango , char mensaje[] , char mensajeError[])
{
    int ret;
    int idCliente;
    int resultado;
    int campoAmodificar;

    ret = -1;

    if(lista != NULL && rango > 0 && mensaje != NULL && mensajeError != NULL)
    {
    	get_id(lista, rango , &idCliente , "Ingrese el id del cliente a modificar.." , "Error, el id debe ser mayor a cero..");

		resultado = encontrarId(lista , rango , idCliente);

		if(resultado != -1)
		{

			Get_numeroConLimites("Ingrese el campo a modificar , 1 (direccion) , 2 (localidad)..","Error ingrese una opcion entre las dadas..",1,2,&campoAmodificar);

			if(QueresSeguir("Seguro que queres modificar ese campo?  s/n \n") == 0)
			{
				switch(campoAmodificar)
				{
					case 1:

						Get_cadena("Ingrese la direccion donde vive...", "Error, la direccion no puede ser tan larga, reingrese..",lista[resultado].direccion, sizeof(lista[resultado].direccion));

						OrdenarNombre(lista[resultado].direccion , sizeof(lista[resultado].direccion));

						ret = 0;

					break;

					/*
					case 2:

					if(Get_cadena("Ingrese la localidad donde reside...", "Error, la localidad no puede ser tan larga, reingrese..",lista[resultado].localidad, sizeof(lista[resultado].localidad)) != 0)
					{
						ret -1;
					}
					else
					{
						OrdenarNombre(lista[resultado].localidad , sizeof(lista[resultado].localidad));
						ret = 1;
					} //ACA TENDRIA QUE LLAMAR AL ABD DE LOCALIDAD

					break; //ACA TENDRIA QUE LLAMAR AL ABD DE LOCALIDAD */
				}
			}
			else
			{
				ret = -2;
			}
		}
		else
		{
			ret = -3;
		}
    }

    return ret;
}

