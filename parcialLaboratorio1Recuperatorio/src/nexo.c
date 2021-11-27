
#include "nexo.h"

#define PENDIENTE 0
#define CARGADO 1


//----------------------------------------------------------

int bajaCliente(ePedidos listaPedidos[] , int rangoPedidos , eCliente listaClientes[] , int rangoClientes)
{
    int idClienteAborrar;
    int indexClienteAborrar;
    int ret;

    ret = -1;

    if(listaPedidos != NULL && listaClientes != NULL && rangoClientes > 0 && rangoPedidos > 0)
    {
        if(get_id(listaClientes , rangoClientes , &idClienteAborrar , "Ingrese el id a eliminar...", "Error, el id debe ser mayor a cero..\n") == 0 )
        {
            indexClienteAborrar = encontrarId(listaClientes , rangoClientes , idClienteAborrar);

            if(indexClienteAborrar != -1)
            {
                if(QueresSeguir("Esta seguro de borrar este cliente?? s/n..\n") == 0)
                {
                    listaClientes[indexClienteAborrar].isEmpty = 1;

                    ret = 0; // se dio de baja el cliente

                    if(darDeBajaPedido(listaPedidos , rangoPedidos , idClienteAborrar) != 0)
                    {
                        ret = 1;  //se dio de baja el cliente pero no los pedidos por que no le cargo ninguno todavia..
                    }
                }
                else
                {
                    ret = -3; //cancelo la operacion..
                }
            }
            else
            {
                ret = -2; //ese id no existe..
            }
        }
    }

    return ret;
}

//----------------------------------------------------------

int get_pedido(eCliente listaClientes[] , int rangoClientes , ePedidos listaPedidos[] , int rangoPedidos , int* idPedidos)
{
    int ret;
    int idClienteSeleccionado;
    int indexIdClienteSeleccionado;

    ret = -1;

    if(listaClientes != NULL && rangoClientes > 0 && listaPedidos != NULL && rangoPedidos > 0 && idPedidos != NULL)
    {
        if(get_id(listaClientes , rangoClientes , &idClienteSeleccionado , "Ingrese el id del cliente a generar el pedido..\n","Error, el id debe ser mayor a cero...\n") == 0)
        {
            indexIdClienteSeleccionado = encontrarId(listaClientes , rangoClientes , idClienteSeleccionado);

            if(indexIdClienteSeleccionado > -1 )
            {
                if(preCarga(listaPedidos , rangoPedidos , idPedidos , idClienteSeleccionado) == 0)
                {
                    ret = 0;
                }
            }
            else
            {
                ret = -2; //ESE ID NO ESTA EN LA LISTA..
            }
        }

    }
    return ret;
}


//----------------------------------------------------------

int imprimirClientesConPedidosPendientes(eCliente listaClientes[] , int rangoClientes , ePedidos listaPedidos[] , int rangoPedidos , eLocalidad listaLocalidades[] , int rangoLocalidades)
{
    int i;
    int ret;
    int contadorPendientes;
    int indexAux;

    ret = -1;

    if(listaPedidos != NULL && listaClientes != NULL && rangoClientes > 0 && rangoPedidos > 0 && listaLocalidades != NULL && rangoLocalidades > 0)
    {
        printf("----------------------------------------------------------------------------------------------------------------------------|\n");
        printf(" ID         NOMBRE                 CUIT                  DIRECCION           LOCALIDAD                PEDIDOS PENDIENTES:   |\n");
        printf("----------------------------------------------------------------------------------------------------------------------------|\n");

        for(i=0 ; i<rangoClientes ; i++)
        {
            if(listaClientes[i].isEmpty == 0)
            {
                contadorPendientes = contadorDePedidosPendientesOprocesadosPorCliente(listaPedidos , rangoPedidos , listaClientes[i].id , 1);
                if(contadorPendientes > -1)
                {
                    indexAux = getIndexLocalidadIdRelacion(listaLocalidades , rangoLocalidades , listaClientes[i].idRelacionLocalidad);
                    if(indexAux > -1)
                    {
                        ret = 0;
                        printf("\n %-10d %-21s %-21s %-21s %-31s %-5d\n", listaClientes[i].id ,listaClientes[i].nombreEmpresa, listaClientes[i].cuit ,
                                                                    listaClientes[i].direccion , listaLocalidades[indexAux].descripcion , contadorPendientes);
                    }                                                                           //listaClientes[i].localidad
                }
            }
        }

        printf("----------------------------------------------------------------------------------------------------------------------------|\n\n");
    }

    return ret;
}


//----------------------------------------------------------

int mostrarPedidosPendientesConClientes(ePedidos listaPedidos[] , int rangoPedidos , eCliente listaClientes[] , int rangoClientes)
{
    int ret;
    int i;
    int index;

    ret = -1;

    if(listaPedidos != NULL && listaClientes != NULL && rangoClientes > 0 && rangoPedidos > 0)
    {
        ret = -2; //No hay pedidos pendientes todavia....

        printf("-------------------------------------------------------------------------------------------------------------------------------|\n");
        printf(" ID                 CUIT                DIRECCION                         KILOS A RECOLECTAR                 ESTADO            |\n");
        printf("-------------------------------------------------------------------------------------------------------------------------------|\n");

        for(i=0 ; i<rangoPedidos ; i++)
        {
            if(listaPedidos[i].isEmpty == 0 && listaPedidos[i].estadoPedido == PENDIENTE)
            {
                index = encontrarId(listaClientes , rangoClientes , listaPedidos[i].idCliente);

                if(index > -1)
                {
                    ret = 0;
                    printf("%-15d %-21s %-35s %-14.2f                     *PENDIENTE*\n", listaPedidos[i].idPedidos , listaClientes[index].cuit ,
                                                                                                listaClientes[index].direccion , listaPedidos[i].kilosTotales);
                }

            }
        }
        printf("-------------------------------------------------------------------------------------------------------------------------------|\n\n");
    }

    return ret;
}


//----------------------------------------------------------

int mostrarPedidosProcesadosConClientes(ePedidos listaPedidos[] , int rangoPedidos , eCliente listaClientes[] , int rangoClientes)
{
    int ret;
    int i;
    int index;

    ret = -1;

    if(listaPedidos != NULL && listaClientes != NULL && rangoClientes > 0 && rangoPedidos > 0)
    {
        ret = -2; //No hay pedidos procesados todavia....

        printf("Pedidos procesados: \n");

        printf("------------------------------------------------------------------------------------------------------------------------------------|\n");
        printf(" ID         CUIT               DIRECCION                   HDPE           LDPE             PP            SOBREANTES                 |\n");
        printf("------------------------------------------------------------------------------------------------------------------------------------|\n");

        for(i=0 ; i<rangoPedidos ; i++)
        {
            if(listaPedidos[i].isEmpty == 0 && listaPedidos[i].estadoPedido == CARGADO)
            {
                index = encontrarId(listaClientes , rangoClientes , listaPedidos[i].idCliente);

                if(index > -1)
                {
                    ret = 0;
                    printf("%-10d %-20s %-25s %-15.2f %-15.2f %-15.2f %-15.2f\n", listaPedidos[i].idPedidos , listaClientes[index].cuit ,
                                                                                                listaClientes[index].direccion , listaPedidos[i].kilosHdpe , listaPedidos[i].kilosLdpe ,
                                                                                                listaPedidos[i].kilosPp , listaPedidos[i].kilosRestantes);
                }

            }
        }

        printf("------------------------------------------------------------------------------------------------------------------------------------|\n\n");
    }

    return ret;
}


//----------------------------------------------------------

int pedidosPendientesPorLocalidad(ePedidos listaPedidos[] , int rangoPedidos , eCliente listaClientes[] , int rangoClientes , eLocalidad listaLocalidades[] , int rangoLocalidades)
{
    int ret;
    int i;
    char auxiliar[51];
    int contador;
    int indexAux;

    contador = 0;
    ret = -1;

    if(listaPedidos != NULL && listaClientes != NULL && rangoClientes > 0 && rangoPedidos > 0 && listaLocalidades != NULL && rangoLocalidades > 0)
    {
        ret = -2; //No se encontro esa ubicacion


        	Get_cadena("Ingrese la localidad a buscar...", "Error, la localidad no puede ser tan larga, reingrese..", auxiliar , sizeof(auxiliar));

            for(i=0 ; i<rangoClientes ; i++)
            {
                indexAux = getIndexLocalidadIdRelacion(listaLocalidades , rangoLocalidades , listaClientes[i].idRelacionLocalidad);
                if(indexAux > -1)
                {
                    if(strcmp(listaLocalidades[indexAux].descripcion , auxiliar) == 0)
                    {
                        ret = -3; //No hay pedidos pendientes para esa localidad

                        contador += contadorDePedidosPendientesOprocesadosPorCliente(listaPedidos , rangoPedidos , listaClientes[i].id , 1);

                    }
                }
            }

        if(contador > 0)
        {
            ret = contador;
        }
    }

    return ret;
}

//----------------------------------------------------------

int mostrarTotalPpPorCliente(eCliente listaClientes[] , int rangoClientes , ePedidos listaPedidos[] , int rangoPedidos)
{
    int i;
    int ret;
    float acumulador;
    int contadorClientesCargados;
    float promedio;

    ret = -1;

    if(listaPedidos != NULL && listaClientes != NULL && rangoClientes > 0 && rangoPedidos > 0)
    {
        for(i=0 ; i<rangoClientes ; i++)
        {
            if(listaClientes[i].isEmpty == 0)
            {
                if(acumuladorPlasticosPorCliente(listaPedidos , rangoPedidos , listaClientes[i].id , &acumulador) == 0)
                {
                    if(contadorTotalClientes(listaClientes , rangoClientes , &contadorClientesCargados) == 0)
                    {
                        if(get_promedio(acumulador , contadorClientesCargados , &promedio) == 0)
                        {
                            printf("El promedio de plastico PP reciclado del cliente id: %d nombre: %s cuit: Nª%s es: %.2f Kilogramos\n" , listaClientes[i].id ,listaClientes[i].nombreEmpresa , listaClientes[i].cuit ,promedio);
                            ret = 0;
                        }
                    }
                }
            }
        }
    }

    return ret;
}

//----------------------------------------------------------

//11) Cliente con más pedidos pendientes

//recorro clientes, entro a uno y recorro los pedidos, todos los que tengan el mismo id de relacion y esten pendientes los acumulo
//uso un flag para ver cual es el que tiene mas pedidos, uso flag, auxiliar idCliente, contador

int BuscadorClienteConMasPedidosPendientes(eCliente listaClientes[] , int rangoClientes , ePedidos listaPedidos[] , int rangoPedidos)
{
    int ret;
    int i;
    int cantidadPedidos;
    int controladorCantidadDePedidos;
    int aux;
    int bandera;

    ret = -1; //fallan nulls

    if(listaPedidos != NULL && listaClientes != NULL && rangoClientes > 0 && rangoPedidos > 0)
    {
        bandera = 0;

        for(i=0 ; i<rangoClientes ; i++)
        {
            if(listaClientes[i].isEmpty == 0)
            {
                cantidadPedidos = contadorDePedidosPendientesOprocesadosPorCliente(listaPedidos , rangoPedidos , listaClientes[i].id , 1);

                if(cantidadPedidos > 0)
                {
                    if(bandera == 0 || cantidadPedidos > controladorCantidadDePedidos)
                    {
                        bandera = 1;
                        aux = listaClientes[i].id;
                        controladorCantidadDePedidos = cantidadPedidos;
                    }
                }
            }
        }

        if(bandera != 0)
        {
            ret = 0; //se encontro alguno
            aux = encontrarId(listaClientes , rangoClientes , aux);

            if(aux > -1)
            {
                printf("El cliente con mas pedidos pendientes es:\nCLIENTE: %s\nCUIT:%s\nCANTIDAD PEDIDOS PENDIENTES: %d\n",listaClientes[aux].nombreEmpresa,
                                                                                                    listaClientes[aux].cuit, controladorCantidadDePedidos);
            }
        }
        else
        {
            ret = -2; //Todos estan en cero..
        }
    }

    return ret;
}

//----------------------------------------------------------

int BuscadorClienteConMasPedidosProcesados(eCliente listaClientes[] , int rangoClientes , ePedidos listaPedidos[] , int rangoPedidos)
{
    int ret;
    int i;
    int cantidadPedidos;
    int controladorCantidadDePedidos;
    int aux;
    int bandera;

    ret = -1; //fallan nulls

    if(listaPedidos != NULL && listaClientes != NULL && rangoClientes > 0 && rangoPedidos > 0)
    {
        bandera = 0;

        for(i=0 ; i<rangoClientes ; i++)
        {
            if(listaClientes[i].isEmpty == 0)
            {
                cantidadPedidos = contadorDePedidosPendientesOprocesadosPorCliente(listaPedidos , rangoPedidos , listaClientes[i].id , 0);

                if(cantidadPedidos > 0)
                {
                    if(bandera == 0 || cantidadPedidos > controladorCantidadDePedidos)
                    {
                        bandera = 1;
                        aux = listaClientes[i].id;
                        controladorCantidadDePedidos = cantidadPedidos;
                    }
                }
            }
        }

        if(bandera != 0)
        {
            ret = 0; //se encontro alguno
            aux = encontrarId(listaClientes , rangoClientes , aux);

            if(aux > -1)
            {
                printf("El cliente con mas pedidos procesados es:\nCLIENTE: %s\nCUIT:%s\nCANTIDAD PEDIDOS PROCESADOS: %d\n",listaClientes[aux].nombreEmpresa,
                                                                                                    listaClientes[aux].cuit, controladorCantidadDePedidos);
            }
        }
        else
        {
            ret = -2; //Todos estan en cero..
        }
    }

    return ret;
}

//----------------------------------------------------------

int clienteConMasPedidos(eCliente listaClientes[] , int rangoClientes , ePedidos listaPedidos[] , int rangoPedidos)
{
    int ret;
    int i;
    int cantidadPedidos;
    int controladorCantidadDePedidos;
    //int aux;
    int bandera;
    eCliente aux;

    ret = -1; //fallan nulls

    if(listaPedidos != NULL && listaClientes != NULL && rangoClientes > 0 && rangoPedidos > 0)
    {
        bandera = 0;

        for(i=0 ; i<rangoClientes ; i++)
        {
            if(listaClientes[i].isEmpty == 0)
            {
                cantidadPedidos = contadorDePedidosPorCliente(listaPedidos , rangoPedidos , listaClientes[i].id);

                if(cantidadPedidos > 0)
                {
                    if(bandera == 0 || cantidadPedidos >= controladorCantidadDePedidos)
                    {
                        bandera = 1;
                        controladorCantidadDePedidos = cantidadPedidos;
                    }
                }
            }
        }

        if(bandera != 0)
        {
            ret = 0; //se encontro alguno
            printf("Cliente/s con mas pedidos (%d pedidos):\n\n",controladorCantidadDePedidos);

        	printf(" ID         NOMBRE                 DIRECCION                   CUIT          |\n");
            for(i=0 ; i<rangoClientes ; i++)
            {
            	cantidadPedidos = contadorDePedidosPorCliente(listaPedidos , rangoPedidos , listaClientes[i].id);
            	if(cantidadPedidos == controladorCantidadDePedidos)
            	{
            		aux = listaClientes[i];
                    mostrarCliente(aux);
            	}
            }
        }
        else
        {
            ret = -2; //Todos estan en cero..
        }
    }

    return ret;

}


//---------------------------------------------------FUNCIONES POST MODIFICACION AGREGADAS------------------------------------------------




int hardCodeo(eCliente lista[] , ePedidos listaPedidos[] , eLocalidad listaLocalidades[])
{
    int ret;

    ret = -1;

    if(lista != NULL)
    {
        ret = 0;

        //Clientes

        lista[0].id = 1;
        strcpy(lista[0].nombreEmpresa , "ARCOR");
        strcpy(lista[0].cuit , "22-14251425-3");
        strcpy(lista[0].direccion , "Cordoba 1939");
        //strcpy(lista[0].localidad , "Lanus");
        lista[0].idRelacionLocalidad = 1; //Lanus
        lista[0].isEmpty = 0;

        lista[1].id = 2;
        strcpy(lista[1].nombreEmpresa , "LAYS");
        strcpy(lista[1].cuit , "22-18526741-1");
        strcpy(lista[1].direccion , "Lujan 2112");
        //strcpy(lista[1].localidad , "Lomas de Zamora");
        lista[1].idRelacionLocalidad = 2; //Lomas De Zamora
        lista[1].isEmpty = 0;

        lista[2].id = 3;
        strcpy(lista[2].nombreEmpresa , "PEPSICO");
        strcpy(lista[2].cuit , "22-12579631-8");
        strcpy(lista[2].direccion , "Arias 596");
        //strcpy(lista[2].localidad , "Quilmes");
        lista[2].idRelacionLocalidad = 3; //Quilmes
        lista[2].isEmpty = 0;

        lista[3].id = 4;
        strcpy(lista[3].nombreEmpresa , "DANICA");
        strcpy(lista[3].cuit , "22-16585214-4");
        strcpy(lista[3].direccion , "Mitre 965");
        //strcpy(lista[3].localidad , "Avellaneda");
        lista[3].idRelacionLocalidad = 4; //Avellaneda
        lista[3].isEmpty = 0;

        lista[4].id = 5;
        strcpy(lista[4].nombreEmpresa , "AMEBA");
        strcpy(lista[4].cuit , "22-12378415-1");
        strcpy(lista[4].direccion , "Las heras 259");
        //strcpy(lista[4].localidad , "Recoleta");
        lista[4].idRelacionLocalidad = 5; //Recoleta
        lista[4].isEmpty = 0;

        lista[5].id = 6;
        strcpy(lista[5].nombreEmpresa , "WHISKAS");
        strcpy(lista[5].cuit , "22-19852173-7");
        strcpy(lista[5].direccion , "Av Rivadavia 268");
        //strcpy(lista[5].localidad , "Avellaneda");
        lista[5].idRelacionLocalidad = 4; //Avellaneda
        lista[5].isEmpty = 0;

        //----------------------------------------------------------

        //Pedidos cliente 1

        listaPedidos[0].idPedidos = 2; //va de 2 en dos el contador por eso queda 2 , 4 ,6 etc
        listaPedidos[0].idCliente = 1;
        listaPedidos[0].kilosTotales = 200;
        listaPedidos[0].kilosHdpe = 0;
        listaPedidos[0].kilosLdpe = 0;
        listaPedidos[0].kilosPp = 0;
        listaPedidos[0].kilosRestantes = 0;
        listaPedidos[0].isEmpty = 0;
        listaPedidos[0].estadoPedido = PENDIENTE;

        listaPedidos[1].idPedidos = 4; //va de 2 en dos el contador por eso queda 2 , 4 ,6 etc
        listaPedidos[1].idCliente = 1;
        listaPedidos[1].kilosTotales = 600;
        listaPedidos[1].kilosHdpe = 0;
        listaPedidos[1].kilosLdpe = 0;
        listaPedidos[1].kilosPp = 0;
        listaPedidos[1].kilosRestantes = 0;
        listaPedidos[1].isEmpty = 0;
        listaPedidos[1].estadoPedido = PENDIENTE;

        listaPedidos[2].idPedidos = 6; //va de 2 en dos el contador por eso queda 2 , 4 ,6 etc
        listaPedidos[2].idCliente = 1;
        listaPedidos[2].kilosTotales = 150;
        listaPedidos[2].kilosHdpe = 0;
        listaPedidos[2].kilosLdpe = 0;
        listaPedidos[2].kilosPp = 0;
        listaPedidos[2].kilosRestantes = 0;
        listaPedidos[2].isEmpty = 0;
        listaPedidos[2].estadoPedido = PENDIENTE;

        listaPedidos[3].idPedidos = 8; //va de 2 en dos el contador por eso queda 2 , 4 ,6 etc
        listaPedidos[3].idCliente = 1;
        listaPedidos[3].kilosTotales = 4200;
        listaPedidos[3].kilosHdpe = 0;
        listaPedidos[3].kilosLdpe = 0;
        listaPedidos[3].kilosPp = 0;
        listaPedidos[3].kilosRestantes = 0;
        listaPedidos[3].isEmpty = 0;
        listaPedidos[3].estadoPedido = PENDIENTE;

        listaPedidos[4].idPedidos = 10; //va de 2 en dos el contador por eso queda 2 , 4 ,6 etc
        listaPedidos[4].idCliente = 1;
        listaPedidos[4].kilosTotales = 4200;
        listaPedidos[4].kilosHdpe = 0;
        listaPedidos[4].kilosLdpe = 0;
        listaPedidos[4].kilosPp = 0;
        listaPedidos[4].kilosRestantes = 0;
        listaPedidos[4].isEmpty = 0;
        listaPedidos[4].estadoPedido = PENDIENTE;

        //----------------------------------------------------------

        //Pedidos cliente 8


        listaPedidos[5].idPedidos = 12; //va de 2 en dos el contador por eso queda 2 , 4 ,6 etc
        listaPedidos[5].idCliente = 2;
        listaPedidos[5].kilosTotales = 326;
        listaPedidos[5].kilosHdpe = 0;
        listaPedidos[5].kilosLdpe = 0;
        listaPedidos[5].kilosPp = 0;
        listaPedidos[5].kilosRestantes = 0;
        listaPedidos[5].isEmpty = 0;
        listaPedidos[5].estadoPedido = PENDIENTE;

        listaPedidos[6].idPedidos = 14; //va de 2 en dos el contador por eso queda 2 , 4 ,6 etc
        listaPedidos[6].idCliente = 2;
        listaPedidos[6].kilosTotales = 5325;
        listaPedidos[6].kilosHdpe = 0;
        listaPedidos[6].kilosLdpe = 0;
        listaPedidos[6].kilosPp = 0;
        listaPedidos[6].kilosRestantes = 0;
        listaPedidos[6].isEmpty = 0;
        listaPedidos[6].estadoPedido = PENDIENTE;

        listaPedidos[7].idPedidos = 16; //va de 2 en dos el contador por eso queda 2 , 4 ,6 etc
        listaPedidos[7].idCliente = 2;
        listaPedidos[7].kilosTotales = 1752;
        listaPedidos[7].kilosHdpe = 0;
        listaPedidos[7].kilosLdpe = 0;
        listaPedidos[7].kilosPp = 0;
        listaPedidos[7].kilosRestantes = 0;
        listaPedidos[7].isEmpty = 0;
        listaPedidos[7].estadoPedido = PENDIENTE;

        //----------------------------------------------------------

        //cliente 3

        listaPedidos[8].idPedidos = 18; //va de 2 en dos el contador por eso queda 2 , 4 ,6 etc
        listaPedidos[8].idCliente = 3;
        listaPedidos[8].kilosTotales = 128;
        listaPedidos[8].kilosHdpe = 0;
        listaPedidos[8].kilosLdpe = 0;
        listaPedidos[8].kilosPp = 0;
        listaPedidos[8].kilosRestantes = 0;
        listaPedidos[8].isEmpty = 0;
        listaPedidos[8].estadoPedido = PENDIENTE;

        listaPedidos[9].idPedidos = 20; //va de 2 en dos el contador por eso queda 2 , 4 ,6 etc
        listaPedidos[9].idCliente = 3;
        listaPedidos[9].kilosTotales = 9874;
        listaPedidos[9].kilosHdpe = 0;
        listaPedidos[9].kilosLdpe = 0;
        listaPedidos[9].kilosPp = 0;
        listaPedidos[9].kilosRestantes = 0;
        listaPedidos[9].isEmpty = 0;
        listaPedidos[9].estadoPedido = PENDIENTE;

        //----------------------------------------------------------

        //cliente 4

        listaPedidos[10].idPedidos = 22; //va de 2 en dos el contador por eso queda 2 , 4 ,6 etc
        listaPedidos[10].idCliente = 4;
        listaPedidos[10].kilosTotales = 84001;
        listaPedidos[10].kilosHdpe = 0;
        listaPedidos[10].kilosLdpe = 0;
        listaPedidos[10].kilosPp = 0;
        listaPedidos[10].kilosRestantes = 0;
        listaPedidos[10].isEmpty = 0;
        listaPedidos[10].estadoPedido = PENDIENTE;

        listaPedidos[11].idPedidos = 24; //va de 2 en dos el contador por eso queda 2 , 4 ,6 etc
        listaPedidos[11].idCliente = 4;
        listaPedidos[11].kilosTotales = 18001;
        listaPedidos[11].kilosHdpe = 0;
        listaPedidos[11].kilosLdpe = 0;
        listaPedidos[11].kilosPp = 0;
        listaPedidos[11].kilosRestantes = 0;
        listaPedidos[11].isEmpty = 0;
        listaPedidos[11].estadoPedido = PENDIENTE;

        listaPedidos[12].idPedidos = 26; //va de 2 en dos el contador por eso queda 2 , 4 ,6 etc
        listaPedidos[12].idCliente = 4;
        listaPedidos[12].kilosTotales = 32154;
        listaPedidos[12].kilosHdpe = 0;
        listaPedidos[12].kilosLdpe = 0;
        listaPedidos[12].kilosPp = 0;
        listaPedidos[12].kilosRestantes = 0;
        listaPedidos[12].isEmpty = 0;
        listaPedidos[12].estadoPedido = PENDIENTE;

        listaPedidos[13].idPedidos = 28; //va de 2 en dos el contador por eso queda 2 , 4 ,6 etc
        listaPedidos[13].idCliente = 4;
        listaPedidos[13].kilosTotales = 4523;
        listaPedidos[13].kilosHdpe = 0;
        listaPedidos[13].kilosLdpe = 0;
        listaPedidos[13].kilosPp = 0;
        listaPedidos[13].kilosRestantes = 0;
        listaPedidos[13].isEmpty = 0;
        listaPedidos[13].estadoPedido = PENDIENTE;

        listaPedidos[14].idPedidos = 30; //va de 2 en dos el contador por eso queda 2 , 4 ,6 etc
        listaPedidos[14].idCliente = 4;
        listaPedidos[14].kilosTotales = 33000;
        listaPedidos[14].kilosHdpe = 0;
        listaPedidos[14].kilosLdpe = 0;
        listaPedidos[14].kilosPp = 0;
        listaPedidos[14].kilosRestantes = 0;
        listaPedidos[14].isEmpty = 0;
        listaPedidos[14].estadoPedido = PENDIENTE;

        //----------------------------------------------------------

        //cliente 5

        listaPedidos[15].idPedidos = 32; //va de 2 en dos el contador por eso queda 2 , 4 ,6 etc
        listaPedidos[15].idCliente = 5;
        listaPedidos[15].kilosTotales = 841;
        listaPedidos[15].kilosHdpe = 0;
        listaPedidos[15].kilosLdpe = 0;
        listaPedidos[15].kilosPp = 0;
        listaPedidos[15].kilosRestantes = 0;
        listaPedidos[15].isEmpty = 0;
        listaPedidos[15].estadoPedido = PENDIENTE;

        listaPedidos[16].idPedidos = 34; //va de 2 en dos el contador por eso queda 2 , 4 ,6 etc
        listaPedidos[16].idCliente = 5;
        listaPedidos[16].kilosTotales = 49321;
        listaPedidos[16].kilosHdpe = 0;
        listaPedidos[16].kilosLdpe = 0;
        listaPedidos[16].kilosPp = 0;
        listaPedidos[16].kilosRestantes = 0;
        listaPedidos[16].isEmpty = 0;
        listaPedidos[16].estadoPedido = PENDIENTE;

        listaPedidos[17].idPedidos = 36; //va de 2 en dos el contador por eso queda 2 , 4 ,6 etc
        listaPedidos[17].idCliente = 5;
        listaPedidos[17].kilosTotales = 122000;
        listaPedidos[17].kilosHdpe = 0;
        listaPedidos[17].kilosLdpe = 0;
        listaPedidos[17].kilosPp = 0;
        listaPedidos[17].kilosRestantes = 0;
        listaPedidos[17].isEmpty = 0;
        listaPedidos[17].estadoPedido = PENDIENTE;

        listaPedidos[18].idPedidos = 38; //va de 2 en dos el contador por eso queda 2 , 4 ,6 etc
        listaPedidos[18].idCliente = 5;
        listaPedidos[18].kilosTotales = 1200;
        listaPedidos[18].kilosHdpe = 0;
        listaPedidos[18].kilosLdpe = 0;
        listaPedidos[18].kilosPp = 0;
        listaPedidos[18].kilosRestantes = 0;
        listaPedidos[18].isEmpty = 0;
        listaPedidos[18].estadoPedido = PENDIENTE;

        //----------------------------------------------------------

        //cliente 6

        listaPedidos[19].idPedidos = 40; //va de 2 en dos el contador por eso queda 2 , 4 ,6 etc
        listaPedidos[19].idCliente = 6;
        listaPedidos[19].kilosTotales = 84012;
        listaPedidos[19].kilosHdpe = 0;
        listaPedidos[19].kilosLdpe = 0;
        listaPedidos[19].kilosPp = 0;
        listaPedidos[19].kilosRestantes = 0;
        listaPedidos[19].isEmpty = 0;
        listaPedidos[19].estadoPedido = PENDIENTE;


        //Localidades

        listaLocalidades[0].idLocalidad = 1;
        strcpy(listaLocalidades[0].descripcion , "Lanus");
        listaLocalidades[0].isEmpty = 0;

        listaLocalidades[1].idLocalidad = 2;
        strcpy(listaLocalidades[1].descripcion , "Lomas De Zamora");
        listaLocalidades[1].isEmpty = 0;

        listaLocalidades[2].idLocalidad = 3;
        strcpy(listaLocalidades[2].descripcion , "Quilmes");
        listaLocalidades[2].isEmpty = 0;

        listaLocalidades[3].idLocalidad = 4;
        strcpy(listaLocalidades[3].descripcion , "Avellaneda");
        listaLocalidades[3].isEmpty = 0;

        listaLocalidades[4].idLocalidad = 5;
        strcpy(listaLocalidades[4].descripcion , "Recoleta");
        listaLocalidades[4].isEmpty = 0;

    }

    return ret;
}

//---------------------------------------------------------------------------------------------------------

void mostrarCliente(eCliente cliente)
{
    printf("\n%-10d  %-21s  %-21s    %-21s   \n ",cliente.id ,cliente.nombreEmpresa, cliente.direccion,
    						  cliente.cuit);
}


//---------------------------------------------------------------------------------------------------------

int mostrarClientes(eCliente lista[], int rango , eLocalidad listaLocalidades[] , int rangoLocalidades)
{
    int ret;
    int i;
    int idAux;

    ret = -1;

    if(lista != NULL && rango > 0 && listaLocalidades != NULL && rangoLocalidades > 0)
    {
        ret = 0;
        printf("---------------------------------------------------------------------------------------------------------|\n");
        printf(" ID         NOMBRE                 DIRECCION               LOCALIDAD                       CUIT          |\n");
        printf("---------------------------------------------------------------------------------------------------------|\n");
        for(i=0 ; i<rango ; i++)
        {
            if(lista[i].isEmpty == 0)
            {
                idAux = getIndexLocalidadIdRelacion(listaLocalidades , rangoLocalidades , lista[i].idRelacionLocalidad);

                if(idAux > -1)
                {
                    printf("\n%-10d  %-21s  %-21s   %-26s    %-21s   \n ",lista[i].id ,lista[i].nombreEmpresa, lista[i].direccion,
                                                                listaLocalidades[idAux].descripcion , lista[i].cuit);
                }                                               //lista[i].localidad
            }
        }
        printf("---------------------------------------------------------------------------------------------------------|\n\n");

    }
    return ret;
}

