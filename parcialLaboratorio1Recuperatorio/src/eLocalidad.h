/*
 * eLocalidad.h
 *
 *  Created on: 25 nov 2021
 *      Author: caand
 */

#ifndef ELOCALIDAD_H_
#define ELOCALIDAD_H_

#include "input.h"

typedef struct
{
    int idLocalidad;
    char descripcion[51];
    int isEmpty;

}eLocalidad;


//-------------------------------------------------------------------------------

/**
 * @brief Inicializa un array de estructura eCliente modificando la variable isEmpty en 1 (indicando que estan vacios)
 * @param lista: Listado de localidades
 * @param rango: Largo de la lista de localidades
 * @return Retorna -1 si hubo algun error en la inicializacion , 0 si se inicializo bien
 */
//int inicializarArrayLocalidades(eLocalidad lista[] , int rango);

//-------------------------------------------------------------------------------

/**
 * @brief Verifica que al menos haya un pedido cargado
 * @param lista: Listado de localidades
 * @param rango: Largo de la lista de localidades
 * @return Retorna -1 si hubo algun error en la inicializacion , 0 si verifico bien
 */
//int isEmptyLocalidades(eLocalidad lista[] , int rango);

//-------------------------------------------------------------------------------

/**
 * @brief verifica si hay lugar vacio
 * @param lista: Listado de localidades
 * @param rango: Largo de la lista de localidades
 * @return Retorna -1 si hubo algun error en la inicializacion o no encuentra lugar , 0 si encontro lugar libre
 */
//int hayLugarLocalidades(eLocalidad lista[] , int rango);

//-------------------------------------------------------------------------------

/**
 * @brief Retorna el indice de la lista de localidades vacio proximo
 * @param lista: Listado de localidades
 * @param rango: Largo de la lista de localidades
 * @return Retorna -1 si hubo algun error en la inicializacion , -2 si no hay mas lugar, sino retorna el indice del espacio sin asignar
 */
//int getIndexLocalidad(eLocalidad lista[] , int rango);

//-------------------------------------------------------------------------------

/**
 * @brief Retorna el indice de la localidad encontrada en base al id de relacion pasado por parametro (idRelacionLocalidad)
 * @param lista: Listado de localidades
 * @param rango: Largo de la lista de localidades
 * @return Retorna -1 si hubo algun error en la inicializacion , -2 si no hay mas lugar, sino retorna el indice del espacio sin asignar
 */
int getIndexLocalidadIdRelacion(eLocalidad lista[] , int rango , int idRelacion);




#endif /* ELOCALIDAD_H_ */
