/*
 * miBiblioteca.c
 *
 *  Created on: 24 Sept 2021
 *      Author: irlid
 */


#include <stdio.h>
#include <stdlib.h>
#include "miBiblioteca.h"


int menu(int num1, int num2, int flagUno, int flagDos)
{
    int opciones;

    system("cls\n\n");

    if(flagUno == 0)
    {
        printf("1. Ingresar 1er operando( A )\n");
    }
    else
    {
    	printf("1. Ingresar 1er operando( %d )\n", num1);
    }

    if(flagDos == 0)
    {
    	printf("2. Ingresar 2do operando( B )\n");
    }
    else
    {
    	printf("2. Ingresar 2do operando( %d )\n", num2);
    }

		printf("3. Calcular todas las operaciones\n");
		printf("4. Informar resultados\n");
		printf("5. Salir\n");

    scanf("%d", &opciones);


    return opciones;
}

int sumar(int num1, int num2)
{
    int resultado;

    resultado = num1 + num2;


    return resultado;
}

int restar(int num1, int num2)
{
    int resultado;

    resultado = num1 - num2;


    return resultado;
}

int multiplicar(int num1, int num2)
{
    int resultado;

    resultado = num1 * num2;


    return resultado;
}

void dividir(int num1, int num2, float* pResultado)
{

    if(pResultado != NULL && num2 != 0)
    {
        *pResultado = (float) num1 / num2;
    }

}

void factorial (int num1, int* pRespuesta)
{
    int i;
    int auxiliar = 1;

    if(pRespuesta != NULL && num1 >= 0)
    {
        for(i = 1; i <= num1; i++)
        {
            auxiliar *= i;
        }

        *pRespuesta = auxiliar;

    }


}

