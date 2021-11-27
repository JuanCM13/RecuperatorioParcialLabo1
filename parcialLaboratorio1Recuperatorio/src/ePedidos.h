/*
 * ePedidos.h
 *
 *  Created on: 25 nov 2021
 *      Author: caand
 */

#ifndef EPEDIDOS_H_
#define EPEDIDOS_H_

#include "input.h"
#define FLT_MAX 250000

typedef struct
{
    int idPedidos;
    int idCliente;
    float kilosTotales;
    float kilosHdpe;
    float kilosLdpe;
    float kilosPp;
    float kilosRestantes;
    int isEmpty;
    int estadoPedido;

}ePedidos;

//-------------------------------------------------------------------------------

/**
 * @brief Inicializa un array de estructura eCliente modificando la variable isEmpty en 1 (indicando que estan vacios)
 * @param lista: Listado de pedidos
 * @param rango: Largo de la lista de pedidos
 * @return Retorna -1 si hubo algun error en la inicializacion , 0 si se inicializo bien
 */
int inicializarArrayPedidos(ePedidos lista[] , int rango);

//-------------------------------------------------------------------------------

/**
 * @brief Verifica que al menos haya un pedido cargado
 * @param lista: Listado de pedidos
 * @param rango: Largo de la lista de pedidos
 * @return Retorna -1 si hubo algun error en la inicializacion , 0 si verifico bien
 */
int isEmptyPedidos(ePedidos lista[] , int rango);

//-------------------------------------------------------------------------------

/**
 * @brief verifica si hay lugar vacio
 * @param lista: Listado de pedidos
 * @param rango: Largo de la lista de pedidos
 * @return Retorna -1 si hubo algun error en la inicializacion , 0 si verifico bien
 */
int hayAlgunPedidoCargado(ePedidos lista[] , int rango);

//-------------------------------------------------------------------------------

/**
 * @brief Retorna el indice de la lista de pedidos vacio proximo
 * @param lista: Listado de pedidos
 * @param rango: Largo de la lista de pedidos
 * @return Retorna -1 si hubo algun error en la inicializacion , -2 si no hay mas lugar, sino retorna el indice del espacio sin asignar
 */
int getIndexPedido(ePedidos lista[] , int rango);

//-------------------------------------------------------------------------------

/**
 * @brief Se encarga de pre cargar un pedido, busca espacio vacio, si encuentra inicializa los kilos deplasticos en 0 y
 *               modifica el estado del pedido en pendiente y la variable isEmpty en 0 (esta cargada)
 * @param lista: Listado de pedidos
 * @param rango: Largo de la lista de pedidos
 * @param *id: Referencia de contador de Id pedidos(la incrementa y asigna)
 * @param idClienteSeleccionado: Id del cliente seleccionado, se asigna este al id de relacion
 * @return Retorna -1 si hubo algun error en la inicializacion , -2 si no hay mas lugar, 0 si cargo bien
 */
int preCarga(ePedidos lista[] , int rango , int* id , int idClienteSeleccionado);

//-------------------------------------------------------------------------------

/**
 * @brief Da de baja un pedido , recibe el id y borra ese pedido
 * @param lista: Listado de pedidos
 * @param rango: Largo de la lista de pedidos
 * @return Retorna -1 si hubo algun error en la eliminacion ,  0 si elimino bien
 */
int darDeBajaPedido(ePedidos lista[], int rango , int idAborrar);

//-------------------------------------------------------------------------------

/**
 * @brief Recibe un idCliente a buscar, si lo encuentra devuelve el indice en la lista de ese pedido
 * @param lista: Listado de pedidos
 * @param rango: Largo de la lista de pedidos
 * @param idAencontrar: idCliente a encontrar
 * @return Retorna -1 si hubo algun error con los nulls ,  sino devuelve el indice
 */
int encontrarIdRelacion(ePedidos lista[], int rango , int idAencontrar);

//-------------------------------------------------------------------------------

/**
 * @brief Recibe un idPedidos a buscar, si lo encuentra devuelve el indice en la lista de ese id
 * @param lista: Listado de pedidos
 * @param rango: Largo de la lista de pedidos
 * @param idAencontrar: idPedidos a encontrar
 * @return Retorna -1 si hubo algun error con los nulls ,  sino devuelve el indice
 */
int encontrarIdPedido(ePedidos lista[], int rango , int idAencontrar);

//-------------------------------------------------------------------------------

/**
 * @brief Recibe un idPedidos a buscar, si lo encuentra y este esta con estado Pendiente devuelve el indice en la lista de ese id
 * @param lista: Listado de pedidos
 * @param rango: Largo de la lista de pedidos
 * @param idAencontrar: idPedidos a encontrar
 * @return Retorna -1 si hubo algun error con los nulls o si no lo encuentra o este ya fue procesado ,  sino devuelve el indice
 */
int encontrarIdPedidoPreCargado(ePedidos lista[], int rango , int idAencontrar);

//-------------------------------------------------------------------------------

/**
 * @brief Procesa un pedido, completa los pesos en kilos de los distintos plasticos, y corrobora que sea correcto lo ingresado.
 * @param lista: Listado de pedidos
 * @param rango: Largo de la lista de pedidos
 * @return Retorna -1 si hubo algun error con los nulls , 0 si procesa bien , -2 si el id ingresado no esta, -3 Si la suma da mas kilos que los totales
 *                                          -4 si no hay pedidos por completar
 */
int procesadoResiduos(ePedidos lista[] , int rango);

//-------------------------------------------------------------------------------

/**
 * @brief Pide los pesos en kilos de los distintos plasticos
 * @kilosHdpe : Referencia donde se almacenan los kilos de plastico hdpe pedidos
 * @kilosLdpe : Referencia donde se almacenan los kilos de plastico ldpe pedidos
 * @kilosPp : Referencia donde se almacenan los kilos de plastico pp pedidos
 * @return Retorna -1 si hubo algun error con los nulls , 0 si completa bien
 */
int completarResiduos(float* kilosHdpe , float* kilosLdpe , float* kilosPp);

//-------------------------------------------------------------------------------

/**
 * @brief Muestra pedidos pendientes
 * @param lista: Listado de pedidos
 * @param rango: Largo de la lista de pedidos
 * @return Retorna -1 si hubo algun error con los nulls , 0 si muestra bien
 */
int mostrarPedidosPendientes(ePedidos lista[], int rango);

//-------------------------------------------------------------------------------

/**
 * @brief Recibe un idCliente, lo busca y cuenta la cantidad de pedidos pendientes o procesados para ese cliente segun el orden dado, 1 (pendientes) 0 (procesados)
 * @param lista: Listado de pedidos
 * @param rango: Largo de la lista de pedidos
 * @param idAcontar: IdCliente a encontrar
 * @return Retorna -1 si hubo algun error con los nulls , o sino la cantidad de pedidos pendientes para ese cliente
 */
int contadorDePedidosPendientesOprocesadosPorCliente(ePedidos lista[] , int rango , int idAcontar , int orden);

//-------------------------------------------------------------------------------

/**
 * @brief Recibe un idCliente, lo busca y acumula la cantidad de kilos de PP en todos sus pedidos
 * @param lista: Listado de pedidos
 * @param rango: Largo de la lista de pedidos
 * @param idAcontar: IdCliente a encontrar
 * @param *acumulado: Referencia donde almacenara el acumulado
 * @return Retorna -1 si hubo algun error con los nulls , o sino la cantidad de kilos de PP de todos los pedidos del cliente
 */
int acumuladorPlasticosPorCliente(ePedidos lista[] , int rango , int idAencontrar , float* acumulado);

//-------------------------------------------------------------------------------

/**
 * @brief Recibe un idCliente, lo busca y cuenta la cantidad de pedidos de ese cliente (procesados o pendientes, suma ambos)
 * @param lista: Listado de pedidos
 * @param rango: Largo de la lista de pedidos
 * @param idAcontar: IdCliente a encontrar
 * @return Retorna -1 si hubo algun error con los nulls , o sino la cantidad de pedidos para ese cliente
 */
int contadorDePedidosPorCliente(ePedidos lista[] , int rango , int idAcontar);

//-------------------------------------------------------------------------------

#endif /* EPEDIDOS_H_ */
