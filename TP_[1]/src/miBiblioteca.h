/*
 * miBiblioteca.h
 *
 *  Created on: 24 Sept 2021
 *      Author: irlid
 */

#ifndef MIBIBLIOTECA_H_
#define MIBIBLIOTECA_H_

/**
 * @fn int menu(int, int, int)
 * @brief despliega una lista de opciones seleccionables
 *
 * @param num1 primer número ingresado
 * @param num2 segundo número ingresado
 * @param flag no se flaco
 * @return opciones a seleccionar por el usuario
 */

int menu(int num1, int num2, int flagUno, int flagDos);

/**
 * @fn int sumar(int, int)
 * @brief suma dos numeros
 *
 * @param num1 primer número ingresado
 * @param num2 segundo número ingresado
 * @return resultado de la suma entre dos numeros
 */

int sumar(int num1, int num2);

/**
 * @fn int restar(int, int)
 * @brief resta dos numeros
 *
 * @param num1 primer número ingresado
 * @param num2 segundo número ingresado
 * @return resultado de la resta entre dos numeros
 */

int restar(int num1, int num2);

/**
 * @fn int multiplicar(int, int)
 * @brief multiplica dos numeros
 *
 * @param num1 primer número ingresado
 * @param num2 segundo número ingresado
 * @return resultado de la multiplicación entre dos numeros
 */

int multiplicar(int num1, int num2);

/**
 * @fn void dividir(int, int, float*)
 * @brief divide dos numeros
 *
 * @param num1 primer número ingresado
 * @param num2 segundo número ingresado
 * @param pResultado
 */

void dividir(int num1, int num2, float* pResultado);

/**
 * @fn void factorial(int, int*)
 * @brief realiza el factorial de
 *
 * @param x numero ingresado
 * @param pRespuesta
 */

void factorial (int x, int* pRespuesta);


#endif /* MIBIBLIOTECA_H_ */
