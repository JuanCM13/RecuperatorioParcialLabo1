
	/******************************************************************************

	ULTIMA VERSION ACTUALIZADA 24/11/2021

	EXAMEN MENDEZ JUAN CRUZ DIV 1C , LABORATORIO
	40423224

	Una empresa de recolección y reciclado de plásticos requiere un sistema que les permita administrar
	sus clientes y pedidos de recolección. El programa contará con el siguiente menú:
	1) Alta de cliente: Se da de alta un cliente con nombre de la empresa, cuit dirección y localidad. Se generará
	un ID único para este cliente que se imprimirá por pantalla si el alta es correcta.
	2) Modificar datos de cliente: Se ingresa el ID de cliente y se permitirá cambiar la dirección y la localidad.
	3) Baja de cliente: Se ingresa el ID del cliente. Luego se preguntará si se quiere confirmar la eliminación.
	4) Crear pedido de recolección: Se imprimirán los clientes por pantalla y se pedirá que se ingrese el ID de un
	cliente existente y la cantidad de kilos totales que se recolectarán del cliente. Se generará un ID para el pedido y
	el mismo quedará en estado “Pendiente” hasta que se obtengan los residuos del cliente y se trasladen a la
	empresa.
	5) Procesar residuos: Se elegirá esta opción cuando los residuos que volvieron a la empresa se hayan
	procesado y separado en los diferentes tipos de plástico que la empresa puede reciclar. Se imprimirán los
	pedidos por pantalla y se pedirá seleccionar el ID de uno de ellos. Luego deberán ingresarse la cantidad de kilos
	de plástico de cada uno de los 3 tipos que la empresa puede procesar que se obtuvieron de los kilos totales que
	se recolectaron. Por último, se marcará al pedido como “Completado”.
	6) Imprimir Clientes: Se imprimirá una lista de clientes con todos sus datos junto con la cantidad de “pedidos
	de recolección” que posee en estado “Pendiente”.
	7) Imprimir Pedidos pendientes: Se imprimirá una lista de los pedidos que se encuentren en estado
	“Pendiente” con la información: Cuit del cliente, dirección del cliente, cantidad de kilos a recolectar.
	8) Imprimir Pedidos procesados: Se imprimirá una lista de los pedidos que se encuentren en estado
	“Completado” con la información: Cuit del cliente, dirección del cliente, cantidad de kilos reciclados de cada tipo
	de plástico.
	9) Ingresar una localidad e indicar la cantidad de pedidos pendientes para dicha localidad.
	10) Cantidad de kilos de polipropileno reciclado promedio por cliente. (kilos totales / cantidad de clientes)
	11) Cliente con más pedidos pendientes.
	12) Cliente con más pedidos completados.
	13) Cliente con más pedidos.

	//----AGREGADO SEGUNDA PARTE----

	1) Agregar la entidad Localidad.
	2) Refactorizar las funciones que considere necesarias para que utilicen la nueva entidad.
	3) Agregar los siguientes informes:
	a) Cliente con más pedidos pendientes.
	b) Cliente con más pedidos completados.
	c) Cliente con más pedidos.

	*******************************************************************************/

	#include "nexo.h"

	#define TAMCLIENTES 100
	#define TAMLOCALIDADES 5
	#define TAMPEDIDOS 1000

	int main()
	{
		setbuf(stdout, NULL);

	    //--creacion estructuras

	    eCliente listaClientes[TAMCLIENTES];
	    ePedidos listaPedidos[TAMPEDIDOS];
	    eLocalidad listaLocalidades[TAMLOCALIDADES];

	    //--contadores

	    int contadorId;
	    int contadorIdPedidos;

	    //--respuestas

	    int respuestaMenu;
	    int respuestaMod;
	    int respuestaBaja;
	    int respuestaPreCargaPedido;
	    int respuestaCompletarPedido;
	    int respuestaPedidosPorLocalidad;
	    int respuestaClienteMasPendientes;
	    int respuestaClienteMasProcesados;
	    int respuestaClienteMasPedidos;

	    contadorId = 6; //0 hardcodeo
	    contadorIdPedidos = 40; //0 hardcodeo

	    inicializarArrayClientes(listaClientes , TAMCLIENTES);

	    inicializarArrayPedidos(listaPedidos , TAMPEDIDOS);

	    //Funcion para hardcodear--
	    hardCodeo(listaClientes , listaPedidos , listaLocalidades);

	    do
	    {
	        if(desplegarMenu(&respuestaMenu) != 0)
	        {
	            printf("\n-- Algo fallo, reinicie..\n");
	        }

	        switch(respuestaMenu)
	        {
	            case 1:

	                if(hayLugar(listaClientes , TAMCLIENTES ) == 0)
	                {
	                    cargarCliente(listaClientes , TAMCLIENTES , &contadorId);
	                }
	                else
	                {
	                    printf("\n-- La lista de clientes se encuentra llena..\n");
	                }

	            break;

	            case 2:

	                if(isEmptyClientes(listaClientes , TAMCLIENTES ) == 0)
	                {
	                   respuestaMod = modificarCliente(listaClientes , TAMCLIENTES , "Para modificar la direccion ingrese 1, para modificar la localidad ingrese 2..",
	                                                                    "Error, Ingrese un valor entre los dados, 1 o 2..");
	                    switch(respuestaMod)
	                    {
	                        case -1:
	                            printf("\n-- Algo fallo con la modificacion, por favor reintente..\n");
	                        break;

	                        case -2:
	                            printf("\n-- Cancelo la operacion..\n");
	                        break;

	                        case -3:

	                        	printf("El id seleccionado no se encuentra en la lista..\n");

	                        break;

	                        case 0:
	                            printf("\n-- La direccion fue modificada con exito..\n");

	                        break;
	                        case 1:
	                            printf("\n-- La localidad fue modificada con exito..\n");
	                        break;
	                    }
	                }
	                else
	                {
	                    printf("\n-- Almenos debe haber 1 cliente cargado.. para entrar a esta area\n");
	                }

	            break;

	            case 3:

	                if(isEmptyClientes(listaClientes , TAMCLIENTES ) == 0)
	                {
	                    respuestaBaja = bajaCliente(listaPedidos , TAMPEDIDOS , listaClientes , TAMCLIENTES);

	                    switch(respuestaBaja)
	                    {
	                        case -3:

	                            printf("\n-- Cancelamos la operacion..\n");

	                        break;

	                        case -2:

	                            printf("\n-- El id ingresado no existe..\n");

	                        break;

	                        case -1:

	                            printf("\n-- Algo fallo.. reintente\n");

	                        break;

	                        case 0:

	                            printf("\n-- El cliente junto con su/s pedido/s fueron eliminados exitosamente..\n");

	                        break;

	                        case 1:

	                            printf("\n-- El cliente se dio de baja de manera correcta..\n");

	                        break;
	                    }
	                }
	                else
	                {
	                    printf("\n-- Debe al menos haber cargado un cliente para ingresar a esta opcion..\n");
	                }
	            break;

	            case 4:

	                if(isEmptyClientes(listaClientes , TAMCLIENTES ) == 0)
	                {
	                    respuestaPreCargaPedido = get_pedido(listaClientes , TAMCLIENTES , listaPedidos , TAMPEDIDOS , &contadorIdPedidos);

	                    switch(respuestaPreCargaPedido)
	                    {
	                        case 0:

	                            printf("\n-- El pedido fue pre cargado, esta en estado pendiente..\n");

	                        break;

	                        case -1:

	                            printf("\n-- Un error inesperado ha ocurrido, por favor reintente..\n");

	                        break;

	                        case -2:

	                            printf("\n-- Ese id no existe en la lista..\n");

	                        break;
	                    }
	                }
	                else
	                {
	                    printf("\n-- La lista debe tener al menos 1 cliente cargado para ingresar a este campo..\n");
	                }

	            break;

	            case 5:

	                if(isEmptyClientes(listaClientes , TAMCLIENTES ) == 0)
	                {
	                    respuestaCompletarPedido = procesadoResiduos(listaPedidos , TAMPEDIDOS);
	                    switch(respuestaCompletarPedido)
	                    {
	                        case -4:

	                            printf("\n-- No hay pedidos pendientes por completar..\n");

	                        break;
	                        case -3:

	                            printf("\n-- Error, el total de kilos no puede superar el kilo total del pedido declarado en la pre carga..\n");

	                        break;
	                        case -2:

	                            printf("\n-- Error ese id no se encontro en la lista..\n");

	                        break;
	                        case -1:

	                            printf("\n-- Error, algo fallo con la carga, reintente..\n");

	                        break;
	                        case -0:

	                            printf("\n-- El pedido fue procesado de manera correcta..\n");

	                        break;
	                    }
	                }
	                else
	                {
	                    printf("\n-- La lista debe tener al menos 1 cliente cargado para ingresar a este campo..\n");
	                }

	            break;

	            case 6:

	                if(isEmptyClientes(listaClientes , TAMCLIENTES ) == 0)
	                {
	                    if(imprimirClientesConPedidosPendientes(listaClientes , TAMCLIENTES , listaPedidos , TAMPEDIDOS , listaLocalidades , TAMLOCALIDADES) != 0)
	                    {
	                        printf("\n-- Algo fallo\n");
	                    }
	                }
	                else
	                {
	                    printf("\n-- La lista debe tener al menos 1 cliente cargado para ingresar a este campo..\n");
	                }

	            break;

	            case 7:

	                if(isEmptyClientes(listaClientes , TAMCLIENTES ) == 0)
	                {
	                    if(mostrarPedidosPendientesConClientes(listaPedidos , TAMPEDIDOS , listaClientes , TAMCLIENTES) == -2)
	                    {
	                        printf("\n-- Aun no hay pedidos pendientes!!\n");
	                    }
	                }
	                else
	                {
	                    printf("\n-- La lista debe tener al menos 1 cliente cargado para ingresar a este campo..\n");
	                }

	            break;

	            case 8:

	                if(isEmptyClientes(listaClientes , TAMCLIENTES ) == 0)
	                {
	                    if(mostrarPedidosProcesadosConClientes(listaPedidos , TAMPEDIDOS , listaClientes , TAMCLIENTES) == -2)
	                    {
	                        printf("\n-- Aun no hay pedidos procesados!!\n");
	                    }
	                }
	                else
	                {
	                    printf("\n-- La lista debe tener al menos 1 cliente cargado para ingresar a este campo..\n");
	                }


	            break;

	            case 9:

	                if(isEmptyClientes(listaClientes , TAMCLIENTES ) == 0)
	                {
	                    respuestaPedidosPorLocalidad = pedidosPendientesPorLocalidad(listaPedidos , TAMPEDIDOS , listaClientes , TAMCLIENTES , listaLocalidades , TAMLOCALIDADES);

	                    switch(respuestaPedidosPorLocalidad)
	                    {
	                        case -1:

	                            printf("\n-- Algo fallo..\n");

	                        break;

	                        case -2:

	                            printf("\n-- No se encontro esa ubicacion\n");

	                        break;

	                        case -3:

	                            printf("\n-- No hay pedidos pendientes para esa localidad\n");

	                        break;

	                        default:

	                            printf("\n-- La cantidad de pedidos pendientes para la localidad seleccionada son: %d\n",respuestaPedidosPorLocalidad);

	                        break;
	                    }
	                }
	                else
	                {
	                    printf("\n-- La lista debe tener al menos 1 cliente cargado para ingresar a este campo..\n");
	                }

	            break;

	            case 10:

	                if(isEmptyClientes(listaClientes , TAMCLIENTES ) == 0)
	                {
	                    if(mostrarTotalPpPorCliente(listaClientes , TAMCLIENTES , listaPedidos , TAMPEDIDOS) != 0)
	                    {
	                        printf("\n-- Debe almenos haber 1 pedido procesado para ingresar a este campo..\n");
	                    }
	                }
	                else
	                {
	                    printf("\n-- La lista debe tener al menos 1 cliente cargado para ingresar a este campo..\n");
	                }

	            break;

	            case 11:

	                if(isEmptyClientes(listaClientes , TAMCLIENTES ) == 0)
	                {
	                    respuestaClienteMasPendientes = BuscadorClienteConMasPedidosPendientes(listaClientes , TAMCLIENTES , listaPedidos , TAMPEDIDOS);
	                    switch(respuestaClienteMasPendientes)
	                    {
	                        case -1:

	                            printf("\n-- Algo fallo..\n");

	                        break;
	                        case -2:

	                            printf("\n-- No hay clientes con pedidos pendientes..\n");

	                        break;
	                    }
	                }
	                else
	                {
	                    printf("\n-- La lista debe tener al menos 1 cliente cargado para ingresar a este campo..\n");
	                }

	            break;

	            case 12:

	                if(isEmptyClientes(listaClientes , TAMCLIENTES ) == 0)
	                {
	                    respuestaClienteMasProcesados = BuscadorClienteConMasPedidosProcesados(listaClientes , TAMCLIENTES , listaPedidos , TAMPEDIDOS);
	                    switch(respuestaClienteMasProcesados)
	                    {
	                        case -1:

	                            printf("\n-- Algo fallo..\n");

	                        break;
	                        case -2:

	                            printf("\n-- No hay clientes con pedidos procesados..\n");

	                        break;
	                    }
	                }
	                else
	                {
	                    printf("\n-- La lista debe tener al menos 1 cliente cargado para ingresar a este campo..\n");
	                }

	            break;

	            case 13:

	                if(isEmptyClientes(listaClientes , TAMCLIENTES ) == 0)
	                {
	                    respuestaClienteMasPedidos = clienteConMasPedidos(listaClientes , TAMCLIENTES , listaPedidos , TAMPEDIDOS);
	                    switch(respuestaClienteMasPedidos)
	                    {
	                        case -1:

	                            printf("\n-- Algo fallo..\n");

	                        break;
	                        case -2:

	                            printf("\n-- Todavia no hay ningun pedido cargado en el programa..\n");

	                        break;
	                    }
	                }
	                else
	                {
	                    printf("\n-- La lista debe tener al menos 1 cliente cargado para ingresar a este campo..\n");
	                }

	            break;

	            case 0:

	                if(QueresSeguir("Seguro que desea salir? s/n") != 0)
	                {
	                    printf("\n\n--Operacion cancelada..\n");
	                    respuestaMenu = 14; //TOMA ESTE VALOR COMO AUXILIAR PARA REGRESAR AL MENU DE OPCIONES..
	                }

	            break;
	        }

	    }while(respuestaMenu != 0);


	    printf("\n\n--------------------------------------------------------------Finalizo el programa--------------------------------------------------------------\n");

	}

