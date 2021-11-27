/*
 * nombres.h
 *
 *  Created on: 25 nov 2021
 *      Author: caand
 */

#ifndef NOMBRES_H_
#define NOMBRES_H_

#include "input.h"

//-------------------------------------------------------------------------------------------------------------------------
/**
 * @brief Valida si todos los caracteres de una cadena son letras entre a y z (conbierte la cadena a minuscula y valida)
 * @param cadena: Recibe una cadena
 * @param rango: Recibe el tamanio de la lista
 * @return Retorna -1 si algo fallo con los null, -2 si emcontro un caracter que no este contemplado entre a y z -- y 0 si son todos los caracteres letras
 */
int sonLetras (char cadena[], int rango);
//-------------------------------------------------------------------------------------------------------------------------

/**
 * @brief Pide una cadena de letras
 * @param mensaje: Mensaje de pedido de datos
 * @param mensajeError: Mensaje de error del pedido de datos
 * @param cadena: Donde se almacena la cadena de caracteres si es bien validada
 * @param rango: Largo de la cadena
 * @return Retorna -1 si algo fallo con los null, y 0 si se logro validar bien y se cargo en el array cadena , -2 si el texto
 *                  que se quiere almacenar excede el espacio de cadena, -3 si se quieren ingresar numeros, solo se aceptan letras..
 */
int Get_string (char mensaje[], char mensajeError[], char cadena[],int rango);
//-------------------------------------------------------------------------------------------------------------------------

/**
 * @brief Consigue un nombre o apellido a travez de el llamado de distintas funciones
 * @param mensaje: Mensaje de pedido de datos
 * @param mensajeError: Mensaje de error del pedido de datos
 * @param cadena: Donde se almacena la cadena de caracteres si es bien validada
 * @param rango: Largo de la cadena
 * @return Retorna -1 si hubo algun error en la carga del nombre o apellido o 0 si se cargo bien
 */
int Get_NombreEmpresa (char mensaje[], char mensajeError[], char cadena[],int rango);
//-------------------------------------------------------------------------------------------------------------------------
/**
 * @brief Recibe una cadena en este caso un nombre o apellido y transforma la primer letra y la primer letra despues de un espacio a mayuscula
 *          y las demas letras a minuscula
 * @param lista: Recibe la cadena de caracteres
 * @param rango: Recibe el tamanio de la lista
 * @return Retorna -1 si algo fallo con los null, y 0 si ordeno el nombre
 */
int OrdenarNombre(char cadena[], int rango);
//-------------------------------------------------------------------------------------------------------------------------


#endif /* NOMBRES_H_ */
