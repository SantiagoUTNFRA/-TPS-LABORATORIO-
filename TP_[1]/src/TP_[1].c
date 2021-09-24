/*
 ============================================================================
 Name        : TP_[1].c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "miBiblioteca.h"

int main()
{
	setbuf(stdout, NULL);

    int num1;
    int num2;
    int resultadoSuma;
    int resultadoResta;
    int resultadoMultiplicacion;
    int pResultadoFactorialUno;
    int pResultadoFactorialDos;
    int flagOperandoUno = 0;
    int flagOperandoDos = 0;
    int flagResultados = 0;

    float pResultadoDividir;

    char seguir = 's';

    do
    {
        switch(menu(num1, num2, flagOperandoUno, flagOperandoDos))
        {
        case 1:
            printf("Ingrese un numero\n");
            scanf("%d", &num1);
            flagOperandoUno = 1;
            break;
        case 2:
            if(flagOperandoUno)
            {
                printf("Ingrese el segundo numero\n");
                scanf("%d", &num2);
                flagOperandoDos = 1;
            }
            else
            {
                printf("primero deberias ingresar el primer operando\n\n");
            }
            break;
        case 3:
            if(flagOperandoDos)
            {
                resultadoSuma = sumar(num1, num2);
                resultadoResta = restar(num1, num2);
                resultadoMultiplicacion = multiplicar(num1, num2);
                dividir(num1, num2, &pResultadoDividir);
                factorial(num1, &pResultadoFactorialUno);
                factorial(num2, &pResultadoFactorialDos);
                flagResultados = 1;
            }
            else
            {
                printf("primero deberias ingresar ingresar primer y segundo operando\n\n");
            }
            break;
        case 4:
            if(flagResultados)
            {
                printf("El resultado de %d + %d es: %d\n", num1, num2, resultadoSuma);
                printf("El resultado de %d - %d es: %d\n", num1, num2, resultadoResta);
                printf("El resultado de %d * %d es: %d\n", num1, num2, resultadoMultiplicacion);
                if(num2 == 0)
                {
                    printf("Math Error, no se puede dividir por 0 \n");
                }
                else
                {
                    printf("El resultado de %d/%d es: %.2f\n", num1, num2, pResultadoDividir);
                }
                if(num1 < 0)
                {
                    printf("No se pudo realizar su factorial de %d ya que es un numero negativo\n\n", num1);
                }
                else
                {
                    printf("El factorial de %d es: %d\n", num1, pResultadoFactorialUno);

                }
                if(num2 < 0)
                {
                    printf("No se pudo realizar su factorial de %d ya que es un numero negativo\n\n", num2);
                }
                else
                {
                    printf("El factorial de %d es: %d\n", num2, pResultadoFactorialDos);
                }
            }
            else
            {
                printf("primero deberias seguir los anteriores pasos\n\n");
            }
            break;
        case 5:
            seguir = 'n';
            break;
        default:
            printf("Su opcion no es reconocida, ingrese una opcion valida\n\n");
            break;
        }

        system("pause");

    }
    while(seguir == 's');

    return EXIT_SUCCESS;

}
