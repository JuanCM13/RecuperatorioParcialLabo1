/*
 * input.h
 *
 *  Created on: 25 nov 2021
 *      Author: caand
 */

#ifndef INPUT_H_
#define INPUT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

//------------------------------------------------------------------------------------------------------------------------------

/**
 * @brief Devuelve un numero flotante entre un rango de valores
 * @param mensaje: Mensaje de pedido de datos
 * @param mensajeError: Mensaje de error del pedido de datos
 * @param minimo: Valor minimo que puede ser aceptado
 * @param maximo: Valor maximo que puede ser aceptado
 * @param numero: Direccion de memoria donde se almacena el flotante obtenido
 * @return Retorna -1 si hubo algun error en la carga del flotante o 0 si se cargo bien
 */
int Get_floatConLimites(char mensaje[] , char mensajeError[] , float minimo , float maximo , float* numero);
//-------------------------------------------------------------------------------------------------------------------------

/**
 * @brief Devuelve un numero entero entre un rango de valores
 * @param mensaje: Mensaje de pedido de datos
 * @param mensajeError: Mensaje de error del pedido de datos
 * @param minimo: Valor minimo que puede ser aceptado
 * @param maximo: Valor maximo que puede ser aceptado
 * @param numero: Direccion de memoria donde se almacena el numero obtenido
 * @return Retorna -1 si hubo algun error en la carga del numero o 0 si se cargo bien
 */
int Get_numeroConLimites(char mensaje[] , char mensajeError[] , int minimo , int maximo , int* numero);
//-------------------------------------------------------------------------------------------------------------------------

/**
 * @brief Valida si una cadena de caracteres es numero flotante
 * @param cadena: Cdena de caracteres a verificar
 * @param rango: Largo de la cadena a verificar
 * @return Retorna -1 si hubo algun error con los NULL , -2 si encuentra caracter no perteneciente a un flotante, 0 si la cadena es un flotante
 */
int esFloat(char lista[] , int rango);
//-------------------------------------------------------------------------------------------------------------------------

/**
 * @brief Valida si una cadena de caracteres es numero entero
 * @param cadena: Cadena de caracteres a verificar
 * @param rango: Largo de la cadena a verificar
 * @return Retorna -1 si hubo algun error con los NULL , -2 si encuentra caracter no perteneciente a un entero, 0 si la cadena es un flotante
 */
int esNumero(char cadena[] , int rango);
//-------------------------------------------------------------------------------------------------------------------------

/**
 * @brief Se utiliza con el fin de verificar a travez de un char si se desea continuar con un proceso
 * @param mensaje: Mensaje si se desea continuar con x proceso
 * @return Retorna -1 si hubo algun error con los NULL o si no desea continuar o 0 si se eligio la letra 's' (desea continuar)
 */
int QueresSeguir(char mensaje[]);
//-------------------------------------------------------------------------------------------------------------------------

/**
 * @brief Calcula el promedio
 * @param acumulado: Es el dividendo , la cantidad total de cosas que se desea calcular el promedio
 * @param divisor: Es por la cantidad que se quiere dividir (calcular)
 * @param promedio: Direccion de memoria donde se almacena el resultado
 * @return Retorna -1 si hubo algun error con los NULL o 0 si se calculo bien el promedio
 */
int get_promedio(float acumulado , int divisor , float* promedio);
//-------------------------------------------------------------------------------------------------------------------------

/**
 * @brief Pide una cadena de caracteres
 * @param mensaje: Mensaje de pedido de datos
 * @param mensajeError: Mensaje de error del pedido de datos
 * @param cadena: Donde se almacena la cadena de caracteres si es bien validada
 * @param rango: Largo de la cadena
 * @return Retorna -1 si algo fallo con los null, y 0 si se logro validar bien y se cargo en el array cadena
 */
int Get_cadena(char mensaje[] ,char mensajeError[] , char cadena[] , int rango);

//-------------------------------------------------------------------------------------------------------------------------


#endif /* INPUT_H_ */
